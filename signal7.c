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
	printf("*********** DEMONSTRATION OF SIGPROCMASK SYSTEM CALL     ***********************\n");
	printf("************************************************************************\n");

}


void sigusr1_handler(int signum)
{
	printf("\t\t Inside SIGUSR1 signal Handler............................\n");
	raise(SIGINT);
	printf("\t\t End of SIGUSR1 Signal Handler............................\n");
}

void sigint_handler(int signum)
{
	printf("\t\tInside SIGINT Signal Handler..............................\n");
}

int main()
{
	sigset_t set1;
	char nam[10];
	display_title();

	printf("\n\t\t Registration Signal Handler Function........................\n");
	signal(SIGUSR1, sigusr1_handler);
	signal(SIGINT, sigint_handler);

	printf("\t\t Blocking SIGINT Signal.......................................\n");
	sigemptyset(&set1);
	sigaddset(&set1,SIGINT);
	sigprocmask(SIG_SETMASK, &set1, NULL);
	raise(SIGINT);
	
	printf("\t\t Enter you name  :   \n");
	scanf("%s", nam);

	if(strlen(nam)<5)
		raise(SIGUSR1);
	else  
	printf("\t\t You have entered :%s \n", nam);
	
	return 0;
}










