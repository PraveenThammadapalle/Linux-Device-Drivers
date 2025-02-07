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
	printf("****DIMONSTRATION OF ORPHAN PROCESS ******");

}

int main(){
	
	display_title();
	printf("\n\tCalling fork().............");

	pID = fork();

	
	if(pID == 0)
	{
		printf("\n\t This is child process........\n");
		
		printf("\n\t End of Child Process......\n");
		printf("Now Child Process is in ZOMBIE STATE");
	return 0;
	}
	else
	{	
		int id, status;
		printf("Parent Process...............  \n");
		sleep(5);
		printf("Using wait to free resource of child Process......\n");
		id = wait(&status);
		printf("Child Process with ID = %d has exited with status : %d\n", id, status);

                sleep(5);
                printf("\n\t End of Parent Process...........");
	}
	return 0;
	
}
