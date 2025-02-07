/* Demonstration of CLONE SYSTEM CALL  */


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sched.h>

int pID;
void display_title()
{
	system("clean");
	printf("****DIMONSTRATION OF CLONE SYSTEM CALL ******");

}


int child_fun(void *arg)
{
	printf("\t\t Inside Child Process with ID : %d\n", getpid());
	printf("\t\t This is child process created using CLONE..........\n");
	printf("\t\t Argument received : %d \n", (int)arg);
	printf("\t\t End of child Process.........................\n");
	return 0;
}

void *stack_addr;

int main(){
	
	display_title();

	printf("\n\t Start of Parent Process.............");

	stack_addr = (void *) malloc(2000);
	pID = clone(child_fun,(stack_addr+2000),SIGCHLD,(void *)10);

	printf("\t Child Process ID was : %d \n", pID);
	printf("\t End of Parent Process.............");
	return 0;

}


