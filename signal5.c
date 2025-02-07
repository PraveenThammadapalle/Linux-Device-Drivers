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
	printf("*********** DEMONSTRATION OF RAISE SYSTEM CALL     ***********************\n");
	printf("************************************************************************\n");

}


void sigusr1_handler(int signum)
{
	printf("\t\t Inside SIGUSR1 signal Handler............................\n");
	printf("\t\t Outof  SIGUSR1 Signal Handler............................\n");
}

void sigusr2_handler(int signum)
{
	printf("\t\tInside SIGUSR2 Signal Handler..............................\n");
	printf("\t\tOutof  SIGUSR2 Signal handler..............................\n");
}

int main()
{
	char nam[10];
	display_title();

	printf("\n\t\t Registration Signal Handler Function........................\n");
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGUSR2, sigusr2_handler);
	printf("\t\t Enter you name  :   \n");
	scanf("%s", nam);

	if(strlen(nam)<5)
		raise(SIGUSR1);
	else if(strlen(nam)<8)
		raise(SIGUSR2);
	else  
	printf("\t\t You have entered :%s \n", nam);
	
	return 0;
}










