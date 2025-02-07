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
		sleep(10);
		printf("\n\t End of Child Process......\n");

	}
	else
	{		
                printf("\n\tt This is parent process........\n");
                
                printf("\n\t Now Child Process is Orphan");
	}
	return 0;
	
}
