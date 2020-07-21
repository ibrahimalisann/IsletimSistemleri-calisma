#include <stdio.h>
#include < sys/types.h>
#include <sys/msg.h>

#include <string.h>

#define MAXSIZE 128  
struct my_mesaj
{

long mytype;
char mtext[MAXSIZE];

}mesaj;
int main(){

int msg_id=msgget(2040, | 0666); 		//keyfekeder sayi verdik(haberleşmesini isteyen sayi
 
mesaj.mtype= 1;

//strcpy(mesaj.mtext,"merhaba\n");

//msgsnd(msg_id, &mesaj,MAXSIZE, IPC_NOWAIT); 


msgrcv(msg_id,&mesaj,MAXSIZE,0,0);

printf("alinan mesaj: %s\n ",mesaj.mtext);
return 0; 	//derleme gcc msg-rcv.c -o msg-rcv
}