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

int main()
{
	int mid;	
	display_title();
	
	mid = msgget(20,IPC_CREAT);
	if(mid > 0)
	{
		printf("\n\t\t Successfully Created Message QUEUE with ID: %d  \n", mid);
		system("ipcs");
	}
	else
		printf("\n\t\t Unable to Create or Attach to Message Queue .....\n");
	return 0;
	
	
}

/* OUTPUT: Data Read From Pipe is : Pipe Data  */
