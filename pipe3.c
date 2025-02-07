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
	if(fork() == 0)
	{
		close(pipe_fd[1]);
		sleep(1);
		printf("\n\t\t Child Process is Reading Pipe \n");
		read(pipe_fd[0],buffer,10);
		printf("\n\t\t Data Read from Pipe is : %s  \n", buffer);
	}
	else
	{
		close(pipe_fd[0]);
		printf("\n\t\t Parent Process is Writing into Pipe \n");
		write(pipe_fd[1], "pipe Data", 10);
	}


	return 0;
	
}

/* OUTPUT: Data Read From Pipe is : Pipe Data  */
