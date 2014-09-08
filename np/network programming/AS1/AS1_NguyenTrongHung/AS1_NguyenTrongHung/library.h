
#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//struct nuoc choi
typedef struct
{
	char ten[20];	//Ten nguoi choi
	int Ma;			//Ma player : 1 or 2 	
	int position;
	char way;	
}Player;

int ChuoiSo(char recv_data[]);

void SoChuoi(char kitu[],int i);

void doichuoi(char user1[],char user2[]);
//in so do ban choi
void printMap(Player *P1,Player *P2,int *info);

//ghi so do ban choi vao log
void fprintMap(Player *P1,Player *P2,int *info, FILE *fp);

//lua chon nuoc choi
Player choice(Player *P,int *info);

//thuc hien nuoc di
int play(int *info,Player tmp);
//return so quan an duoc

void game(int state,int sockfd,char name1[], char name2[]);

void HD_sudung();

void InPlayer(Player p1, Player p2);

//kiem tra xem co an duoc o trong tiep theo ko
int checkContinue(int *info, Player tmp);

//ghi file log
//void log(FILE *fp, Player tmp, int *info);

//quit game va ghi vao file log
void quitGame(int *info, FILE *fp);

//check exit game
void checkExit(int *info, FILE *fp);
//kiem tr ket thuc game
int check_Gameover(int *info);
#endif // LIBRARY_H_INCLUDED