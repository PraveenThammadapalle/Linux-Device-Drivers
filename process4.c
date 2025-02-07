/* Demonstration of ORPHAN Process  */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

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
	}
	else
	{		
                printf("\n\t This is parent process........\n");
                sleep(10);
                printf("\n\t End of Parent Process...........");
	}
	return 0;
	
}
