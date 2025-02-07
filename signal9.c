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

void sigint_handler(int signum)
{
	printf("\t\tInside Signal Handler..............................\n");
}

int main()
{
	
	char nam[10];
	display_title();
	int pid;

	printf("\n\t\t Registration Signal Handler Function........................\n");
	
	signal(SIGINT, sigint_handler);
	pid = fork();
	if (pid == 0)
	{
		printf("\t\t\t Child Process is waiting for signal.......\n");
		pause();
		printf("\t\t\t End of Child Process................\n");
	}
	else
	{
		sleep(1);
		printf("\t\t Sending Signal Child Process.......................................\n");
		kill(pid, SIGINT);
	      	sleep(2);
		printf("\t\t End of Parent Process.................................. \n");
	}









}
