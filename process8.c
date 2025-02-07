/* Demonstration of ORPHAN Process  */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

int pID;
int var = 10;
void display_title()
{
	system("clean");
	printf("****DIMONSTRATION OF ORPHAN PROCESS ******");

}

int main(){
	
	display_title();
	printf("\n\tCalling fork().............");

	pID = vfork();

	
	if(pID == 0)
	{
		printf("\n\t This is Child process var = %d \n",var);
		
		printf("\n\t Child Process changing var = 40 \n");
		var = 40;
		printf("Now Child is delayed for 5 seconds..........\n");
		sleep(5);
		printf("\t\t Child Process var = %d \n", var);
		_exit(0);
	}
	else
	{
		printf("\t Parent Process var = %d \n",var);
	}
	
	return 0;
}
