#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/socket.h> 
#include <sys/select.h>
#include <unistd.h>
#include "data.h"
#include "protos.h"
#include "message.h"


#include <sys/timeb.h>
BOOL ftime_ok = FALSE;  /* does ftime return milliseconds? */
int get_ms()
{
	struct timeb timebuffer;
	ftime(&timebuffer);
	if (timebuffer.millitm != 0)
		ftime_ok = TRUE;
	return (timebuffer.time * 1000) + timebuffer.millitm;
}

#define MAXLENGTH 100

/* mainConsoleChess() is basically an infinite loop that either calls
   think() when it's the enermy's turn to move or prompts
   the user for a command (and deciphers it). */

int my_print_result(int sockfd)
{
	int i;

	/* is there a legal move? */
	for (i = 0; i < first_move[1]; ++i)
		if (makemove(gen_dat[i].m.b)) {
			takeback();
			break;
		}
	if (i == first_move[1]) {
		if (in_check(side)) {
			if (side == LIGHT) {
				printf("0-1 {Black mates}\n");
				if (send(sockfd, message_toString(message_construct(RESULT, "0", "1", "0", "0")), MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
	     		 printf("send() sent a different number of bytes than expected\n");
	    		}
	    	return 1;
			}
			else {
				printf("1-0 {White mates}\n");
				if (send(sockfd, message_toString(message_construct(RESULT, "1", "0", "0", "0")), MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
	     		 printf("send() sent a different number of bytes than expected\n");
	    		}
	    	return 1;
			}
		}
		else {
			printf("1/2-1/2 {Stalemate}\n");
				if (send(sockfd, message_toString(message_construct(RESULT, "1/2", "1/2", "0", "0")), MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
	     		 printf("send() sent a different number of bytes than expected\n");
	    		}
	    	return 1;
		}
	}
	else if (reps() == 3) {
		printf("1/2-1/2 {Draw by repetition}\n");
		if (send(sockfd, message_toString(message_construct(RESULT, "1/2", "1/2", "0", "0")), MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
    		 printf("send() sent a different number of bytes than expected\n");
		}
		return 1;
	}
	else if (fifty >= 100) {
		printf("1/2-1/2 {Draw by fifty move rule}\n");
		if (send(sockfd, message_toString(message_construct(RESULT, "1/2", "1/2", "0", "0")), MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
     		 printf("send() sent a different number of bytes than expected\n");
   		}
		return 1;
	}
	return 0;
}

int mainConsoleChess(int pick_side, int sockfd)
{
	int enermy_side;
	char s[1024];
	int m;
	char recvline[MAXLENGTH];
	message_t newMesg;

	printf("\n");
	printf("Phung Nhat Huy and Pham Duy Hung's Console Chess\n");
	printf("\n");
	printf("Type \"help\" to displays a list of commands.\n");
	printf("\n");
	init_hash();
	init_board();
	gen();
	enermy_side = pick_side ^ 1;

	max_time = 1 << 25;
	max_depth = 4;
	
	for (;;) {
		if (side == enermy_side) {  /* enermy's turn */
		printf("Your opposite's turn now. Please wait...\n");
		if (recv(sockfd, recvline, MESSAGE_MAXLEN, 0) < 0) {
	      printf("Server terminated prematurely\n");
	      exit(1);
	    }
	    recvline[strlen(recvline)] = '\0';
	    newMesg = message_parse(recvline);
	    strcpy(s, newMesg->arg);
	    if(newMesg->cmd != MOVE) {
	    	if (send(sockfd, message_toString(message_construct(RESULT, "1/2", "1/2", "0", "0")), MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
	     	 printf("send() sent a different number of bytes than expected\n");
	    	}
	    	goto DONE_GAME;
	    }

		printf("Your enermy's move: %s\n", s);
				
		m = parse_move(s);
		if (m == -1 || !makemove(gen_dat[m].m.b))
			printf("Illegal move.\n");
		else {
			ply = 0;
			gen();
			print_board();
			if(my_print_result(sockfd) == 1) {
				goto DONE_GAME;
			}
		}

		continue;
		}

		printf("ConsoleChess > Your turn now.\n");
		printf("ConsoleChess > ");
		/* get user input */
			if (scanf("%s", s) == EOF)
				return 0;
			if (!strcmp(s, "d")) {
				print_board();
				continue;
			}
			if (!strcmp(s, "bye")) {
				printf("Thanks for playing. Enjoy!\n");
				while(getchar() != '\n');
				if (send(sockfd, message_toString(message_construct(RESULT, "1/2", "1/2", "0", "0")), MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
		     	 printf("send() sent a different number of bytes than expected\n");
		    	}
				goto DONE_GAME;
				break;
			}
			if (!strcmp(s, "help")) {
				printf("d - display the board\n");
				printf("bye - exit the program\n");
				printf("Enter moves in coordinate notation, e.g., e2e4, e7e8Q (for promote moving)\n");
				continue;
			}

			/* maybe the user entered a move? */
			m = parse_move(s);
			if (m == -1 || !makemove(gen_dat[m].m.b))
				printf("Illegal move.\n");
			else {
				ply = 0;
				gen();
				if (send(sockfd, message_toString(message_construct(MOVE, s, "0", "0", "0")), MESSAGE_MAXLEN, 0) != MESSAGE_MAXLEN ) {
		     	 printf("send() sent a different number of bytes than expected\n");
		    	}
		    	print_board();
				if(my_print_result(sockfd) == 1) {
				goto DONE_GAME;
			}
			
		}
	}

	DONE_GAME:
	if (recv(sockfd, recvline, MESSAGE_MAXLEN, 0) < 0) {
	    printf("Server terminated prematurely\n");
	    exit(1);
	}
	recvline[strlen(recvline)] = '\0';
	newMesg = message_parse(recvline);
	if(newMesg->cmd == SIGNOUT) {
		printf("Game over!\n");
	}
	return 0;
}


/* parse the move s (in coordinate notation) and return the move's
   index in gen_dat, or -1 if the move is illegal */

int parse_move(char *s)
{
	int from, to, i;

	/* make sure the string looks like a move */
	if (s[0] < 'a' || s[0] > 'h' ||
			s[1] < '0' || s[1] > '9' ||
			s[2] < 'a' || s[2] > 'h' ||
			s[3] < '0' || s[3] > '9')
		return -1;

	from = s[0] - 'a';
	from += 8 * (8 - (s[1] - '0'));
	to = s[2] - 'a';
	to += 8 * (8 - (s[3] - '0'));

	for (i = 0; i < first_move[1]; ++i)
		if (gen_dat[i].m.b.from == from && gen_dat[i].m.b.to == to) {

			/* if the move is a promotion, handle the promotion piece;
			   assume that the promotion moves occur consecutively in
			   gen_dat. */
			if (gen_dat[i].m.b.bits & 32)
				switch (s[4]) {
					case 'N':
						return i;
					case 'B':
						return i + 1;
					case 'R':
						return i + 2;
					default:  /* assume it's a queen */
						return i + 3;
				}
			return i;
		}

	/* didn't find the move */
	return -1;
}


/* move_str returns a string with move m in coordinate notation */

char *move_str(move_bytes m)
{
	static char str[6];

	char c;

	if (m.bits & 32) {
		switch (m.promote) {
			case KNIGHT:
				c = 'n';
				break;
			case BISHOP:
				c = 'b';
				break;
			case ROOK:
				c = 'r';
				break;
			default:
				c = 'q';
				break;
		}
		sprintf(str, "%c%d%c%d%c",
				COL(m.from) + 'a',
				8 - ROW(m.from),
				COL(m.to) + 'a',
				8 - ROW(m.to),
				c);
	}
	else
		sprintf(str, "%c%d%c%d",
				COL(m.from) + 'a',
				8 - ROW(m.from),
				COL(m.to) + 'a',
				8 - ROW(m.to));
	return str;
}


/* print_board() prints the board */

void print_board()
{
	int i;
	
	printf("\n8 ");
	for (i = 0; i < 64; ++i) {
		switch (color[i]) {
			case EMPTY:
				printf(" .");
				break;
			case LIGHT:
				printf(" %c", piece_char[piece[i]]);
				break;
			case DARK:
				printf(" %c", piece_char[piece[i]] + ('a' - 'A'));
				break;
		}
		if ((i + 1) % 8 == 0 && i != 63)
			printf("\n%d ", 7 - ROW(i));
	}
	printf("\n\n   a b c d e f g h\n\n");
}



/* print_result() checks to see if the game is over, and if so,
   prints the result. */

void print_result(int sockfd)
{
	int i;

	/* is there a legal move? */
	for (i = 0; i < first_move[1]; ++i)
		if (makemove(gen_dat[i].m.b)) {
			takeback();
			break;
		}
	if (i == first_move[1]) {
		if (in_check(side)) {
			if (side == LIGHT) {
				printf("0-1 {Black mates}\n");
			}
			else {
				printf("1-0 {White mates}\n");
			}
		}
		else {
			printf("1/2-1/2 {Stalemate}\n");
		}
	}
	else if (reps() == 3) {
		printf("1/2-1/2 {Draw by repetition}\n");
	}
	else if (fifty >= 100) {
		printf("1/2-1/2 {Draw by fifty move rule}\n");
	}
}