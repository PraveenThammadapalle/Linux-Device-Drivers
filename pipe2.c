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
	char buffer[10];	
	display_title();
	
	pipe(pipe_fd);
	write(pipe_fd[1],"Pipe Data",10);
	read(pipe_fd[0],buffer,10);
	printf("\n\t\t Data Read from Pipe is : %s  \n", buffer);
	

	return 0;
	
}

/* OUTPUT: Data Read From Pipe is : Pipe Data  */
