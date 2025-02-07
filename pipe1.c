/* Demonstration of ORPHAN Process  */



#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int pID;
void display_title()
{
	system("clean");
	printf("****DIMONSTRATION OF PIPE SYSTEM CALL   ******");
	printf("**********************************************");
}

int main()
{
	int pipe_fd[2];	
	display_title();
	
	pipe(pipe_fd);
	printf("\n\t\t File Descriptors for pipe are as follows :   \n");
	printf("\n\t\t Read File Descriptors is : %d \n", pipe_fd[0]);
	printf("\n\t\t write File Descriptors is : %d \n", pipe_fd[1]);

	return 0;
	
}
