/* Demonstration of ORPHAN Process  */

/*   execv wants to execute this program, befor we execute the runprg.c programs and run by using// cc runprg.c -o runprg// command after that execute the process6 program */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int pID;
void display_title()
{
	system("clean");
	printf("****DIMONSTRATION OF EXEC SYSTEM CALL   ******");

}

int main(){
	
	display_title();
	printf("\n\tCalling fork().............");

	pID = fork();

	
	if(pID == 0)
	{
		printf("\n\t This is child process........................\n");
		execv("./runprg", NULL);
		
		printf("This will not get printed.......................\n");
	
	}
	else
	{	
	
		printf("This is Parent Process............................ \n");
	
	}
	return 0;
	
}
