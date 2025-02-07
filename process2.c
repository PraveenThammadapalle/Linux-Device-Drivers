/* Demonstration of getpid and getppid system call  */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int pID;
void display_title()
{
	system("clean");
	printf("**********");

}

int main(){
	
	display_title();
	printf("\n\tCalling fork().............");

	pID = fork();

	
	if(pID == 0)
	{
		printf("\n\ttThis is child process........\n");
		printf("\n\t Child Process ID    : %d\n", getpid());
		printf("\n\t Child's Parent Process ID : %d\n", getppid());
	}
	else
	{		
                printf("\n\tt This is parent process........\n");
                printf("\n\t parent Process ID    : %d\n", getpid());
                printf("\n\t parent's  Parent Process ID : %d\n", getppid());
	}
	return 0;
	
}
