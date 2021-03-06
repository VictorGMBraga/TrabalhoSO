#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string>
#include <string.h>

using namespace std;

struct msgtype{
	long mtype;
	struct process{
		char path[100];
		int offset;
		int times;
	} proc;
};

int main(int argc, char *argv[]){

	// Vezes que o programa ira executar
	int times = atoi(argv[2]);

	// Calcula o offset em minutos
	int hours 			= atoi(strtok(argv[1], ":"));
	int minutes 		= atoi(strtok(NULL, ":"));
	int total_minutes	= (hours*60 + minutes) % 1440;

	// Definições da mensagem a ser enviada
	key_t msgkey 	= 0x10012648;
	int msgflag 	= 0666;
	int msgsize 	= sizeof(struct msgtype) - sizeof(long);

	// Monta a mensagem
	struct msgtype msg = { 4, { " ", total_minutes, times } };
	strcpy(msg.proc.path, argv[3]);

	// Se conecta a fila de mensagens
	int msgqid;
	if((msgqid = msgget(msgkey, msgflag)) < 0){
        perror("msgget");
        exit(1);
    }

    // Envia a mensagem
    if(msgsnd(msgqid, &msg, msgsize, 0) < 0){
    	perror("msgsnd");
    }

	return 0;
}