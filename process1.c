/* Demonstration of fork() system call  */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


void display_title()
{
	//system("clean");
	printf("**********");

}

int main(){
	
	display_title();
	printf("\n\tCalling fork().............");

	pid_t pID = fork();

	printf("\n\tThis is common for both parent and child process........");
	if(pID == 0)
		printf("\n\ttThis is executed by child process........\n");
	else 
		printf("\n\tThis is executed by Parent process........\n");

	printf("\n\tThis is again executed by both parent and child process....\n");
	return 0;
	
}
