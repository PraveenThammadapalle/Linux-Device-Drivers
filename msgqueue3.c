/* Demonstration of Msgqueue  */



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/msg.h>

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
}MY_MSG[3] = {{1,"ISM1"},{2,"ISM2"},{3,"ISM3"}};

int main()
{
	int mid;	
	display_title();
	
	mid = msgget(20,IPC_CREAT);
	if(mid > 0)
	{ 	
		long int i;
		for(i=0;i<4;i++)
		{
			display_title();
			printf("\n\n");
			printf("\t********************************************************\n");
			printf("\n \t\t Reading Message Queue with MTYPE = %ld\n",i);
			printf("\t********************************************************\n");
			msgrcv(mid, &MY_MSG[i], sizeof(MY_MSG[i]),i,0);
			printf("Message Read has MTYPE = %ld and MDATA = %s \n", MY_MSG->mtype, MY_MSG->mdata);
			printf("\t********************************************************\n");
		
			system("ipcs");
			sleep(5);
		}
	}
	else
		printf("\n\t\t Unable to Create or Attach to Message Queue .....\n");
	return 0;
	
	
}

/* OUTPUT: Data Read From Pipe is : Pipe Data  */
