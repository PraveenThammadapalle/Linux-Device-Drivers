#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

int shmid;

void display_title()
{
	//system("clear");
	printf("************************************************************************\n");
	printf("*********** DEMONSTRATION OF SIGALARM SIGNAL     ***********************\n");
	printf("************************************************************************\n");

}


void signal_handler(int signum)
{
	if(signum == SIGINT)
		printf("\n\t\t Inside Sigint Handler..................\n");
	else if (signum == SIGALRM)
		printf("\n\t\t Inside Sigalrm Handler.................\n");
	printf("\t\t Commaon for all handler............................\n");
}


int main()
{
	char nam[10];
	display_title();

	printf("\n\t\t Registration Signal Handler Function........................\n");
	signal(SIGINT, signal_handler);
	signal(SIGALRM, signal_handler);
	alarm(5);
	printf("\t\t Enter you name  :   \n");
	scanf("%s", nam);
	printf("\t\t You have entered :%s \n", nam);

	return 0;
}










