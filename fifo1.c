/* Demonstration of FIFO  */



#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
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
	int fd;
	char buffer[10];	
	display_title();
	
	mkfifo("myfifo1",0666);
	if(fork() == 0)
	{
		printf("\n\t\t Child Process is reading data From FIFO \n");
		fd = open ("./myfifo1", O_RDONLY, 0777);
		read(fd, buffer,4);
		printf("\n\t\t Read Data From FIFO is : %s \n ", buffer);
		close(fd);
	}

	else
	{
		printf("n\\t\t Parent Process is writing Data to FIFO  \n");
		fd = open ("./myfifo1", O_WRONLY, 0777);
		write(fd,"ISM", 4);
		close(fd);

	}
	printf("\n\t\t End of Process..............\n");
	
	return 0;
	
}

/* OUTPUT: Data Read From Pipe is : Pipe Data  */
