;
;        ÜÁ·®äÁ­èsÌvO
;        2003.11.19 
;         Y.ANDO
;
;|[gÌèÄ;
;
;      RB0`RB2iZTüÍj
;      RB3`RB5iLEDoÍj
;      RB6`RB7i¢gpj
;      RA0`RA1i[^oÍj
;      RA2`RA3i¢gpj
;      RA4     iXCb`üÍj
;
;gpvZbTCt@CÌwè
;
        LIST    p=pic16F84a        ;gpvZbTÍ PIC16F84A
        INCLUDE <p16F84a.inc>   ;gpt@C
;
;Áê@\Ýè
;
        __CONFIG _CP_OFF & _WDT_OFF & _PWRTE_OFF & _HS_OSC
                                ;R[hveNgµÈ¢
                                ;EHb`hbO^C}ð®ì³¹È¢
                                ;p[Abv^C}[ðN®³¹È¢
                                ;IbV[^[hÍ HS
;
;ÄpWX^ÌèÄ
;
        CBLOCK 0Ch              ;0CHÔn©çèÄé
        W_COUNT                 ;100Êsecp^C}JE^
        WM_COUNT                ;  10msecp^C}JE^
        WS_COUNT                ;10msec*np^C}JE^
        ENDC                    ;èÄI¹
;
;vOJn
;
        ORG     0               ;vOX^[gÔn
        GOTO    MAIN            ;C[`Ö
        ORG     4
        GOTO    INT             ;èÝòÑæ
        ORG     8
;
MAIN:   BCF     INTCON,GIE      ;èÝSÄÖ~
        CLRF    PORTA           ;A|[gÌb`NA
        CLRF    PORTB           ;B|[gÌb`NA
;
        BSF     STATUS,RP0      ;Bank¨1
;
        MOVLW   B'11111100'     ;A|[g,RA0ÆRA1ÍoÍA¼SÄüÍ
        MOVWF   TRISA
        MOVLW   B'00000111'     ;B|[g,RB0,RB1,RB2ÍüÍA¼SÄoÍ
        MOVWF   TRISB
;
        BCF     STATUS,RP0      ;Bank¨0
;
;;;;;;;;;;;;;;;;;;;;;;;[^ì®Jn;;;;;;;;;;;;;;;;;;;;;;;;;
MT_TST: MOVLW   B'00000011'     ;E[^ONC¶[^ON
        MOVWF   PORTA
        MOVLW   D'3'           ;ñ0.03sec^C}
        MOVWF   WS_COUNT
        CALL    WAIT_s
;
        MOVLW   B'00000000'     ;¼[^OFF
        MOVWF   PORTA
        MOVLW   D'8'           ;ñ0.08sec^C}
        MOVWF   WS_COUNT
        CALL    WAIT_s
;
	GOTO	MT_TST          ;MT_TSTÉßé
;
;^C}Tu[`
;
;100Êsec^C}
;                               ;TCN (CALL WAITÅ 2)
WAIT:   MOVLW   D'165'          ;1
        MOVWF   W_COUNT         ;1
        DECFSZ  W_COUNT,F       ;1*164+2
        GOTO    $-1             ;2*164
        RETURN                  ;2
                                ;v@500TCN*0.2Êsec=100Êsec
                                ;±êðTu[`ÆµÄgp·éÆ«Í
                                ;MOVLW  D'164' Æ·éÆë·ª­È¢
;
;10msec^C}
WAIT_m: MOVLW   D'100'          ;JèÔµñ100
        MOVWF   WM_COUNT
        CALL    WAIT            ;100Êsec^C}
        DECFSZ  WM_COUNT,F      ;WM_COUNT-1ªOÈçQsºÖ
        GOTO    $-2             ;QsãÌ½ßÉòÔ
        RETURN
;
;10msec*nÌ^C}ì¬(1<n<255)
;WS_COUNTÉnÌlðüêÄ^Cð²®
WAIT_s: CALL    WAIT_m
        DECFSZ  WS_COUNT,F
        GOTO    WAIT_s
        RETURN
;èÝÍ¢gp
INT:    RETFIE
        END
