/* Demonstration of Msgqueue  */



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <string.h>

int pID;
void display_title()
{
	system("clean");
	printf("****DIMONSTRATION OF MESSAGE QUEUE   *********");
	printf("**********************************************");
}

struct message
{
	long int mtype;
	char mdata[30];
};

int msgsnd(int msqid, const void *msg_ptr, size_t msg_sz,int msgflag);

int main()
{
	int mid;	
	display_title();
	
	struct message send_msg;

	printf("Creating Message Queue \n");

	mid = msgget(30, IPC_CREAT);
	send_msg.mtype = 1;
	strcpy(send_msg.mdata,"Hello");
	printf("\t********************************************************\n");
	msgsnd(mid, (int)&send_msg, sizeof(send_msg),0);
	system("ipcs");
	msgsnd(mid, (void*)send_msg, size_of(send_msg),0);
	system("ipcs");
			sleep(5);

	

	
	return 0;
	
}	


/* OUTPUT: Data Read From Pipe is : Pipe Data  */
