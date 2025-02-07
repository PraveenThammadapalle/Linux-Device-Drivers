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
	int mtype;
	char mdata[30];
}MY_MSG[3] = {{1,"ISM1"},{2,"ISM2"},{3,"ISM3"}};

int main()
{
	int mid;	
	display_title();
	
	mid = msgget(10,IPC_CREAT);
	if(mid > 0)
	{ 	
		long int i;
		for(i=0;i<3;i++)
		{
			display_title();
			printf("\n\n");
			printf("\t********************************************************\n");
			printf("\n \t\t Writing Message with MTYPE = %ld and  MDATA = %s\n", MY_MSG[i].mtype,MY_MSG[i].mdata);
			printf("\t********************************************************\n");
			msgsnd(mid,(void*)&MY_MSG[i], sizeof(MY_MSG[i]),0);
		
			system("ipcs");
			sleep(5);
		}
	}
	else
		printf("\n\t\t Unable to Create or Attach to Message Queue .....\n");
	return 0;
	
	
}

/* OUTPUT: Data Read From Pipe is : Pipe Data  */
