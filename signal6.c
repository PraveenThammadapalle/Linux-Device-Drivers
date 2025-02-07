#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <string.h>

int shmid;

void display_title()
{
	//system("clear");
	printf("************************************************************************\n");
	printf("*********** DEMONSTRATION OF SIGBLOCK SYSTEM CALL     ***********************\n");
	printf("************************************************************************\n");

}


void sigint_handler(int signum)
{
	printf("\t\t Inside SIGINT signal Handler............................\n");
}

int main()
{
	char nam[10];
	display_title();

	printf("\n\t\t Registration Signal Handler Function........................\n");
	signal(SIGINT, sigint_handler);
	
	raise(SIGINT);
	printf("\t\t Blocking SIGINT Signal..........................\n");
	sigblock(0xFFFFFFFB);
	raise(SIGINT);

	printf("\t\t Enter you name : \n");
	scanf("%s", nam);
	printf("\t\t You have Entered : %s \n",nam);
		
	return 0;
}










