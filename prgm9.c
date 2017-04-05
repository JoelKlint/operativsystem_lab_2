#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigHandler(int sig)
{
	printf("SIGINT DETECTED\n");
}


int main(void)
{

	signal(SIGINT, sigHandler);

//	if (signal(SIGINT, sigHandler) == SIG_ERR)
//	printf("\ncan't catch SIGINT\n");

	while(1)
		sleep(1);
	return 0;
	
}
