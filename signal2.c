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


void sigint_handler(int signum){
	printf("\t\t Inside Signal Handler............................\n");
}

void sigalrm_handler(int signum)
{
	printf("\t\tInside Sigalrm Handler..............................\n");
	alarm(5);// comment this and see once and uncomment this and see once
}

int main()
{
	char nam[10];
	display_title();

	printf("\n\t\t Registration Signal Handler Function........................\n");
	signal(SIGINT, sigint_handler);
	signal(SIGALRM, sigalrm_handler);
	alarm(5);
	printf("\t\t Enter you name  :   \n");
	scanf("%s", nam);
	printf("\t\t You have entered :%s \n", nam);

	return 0;
}










