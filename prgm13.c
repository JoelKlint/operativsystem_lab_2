#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int proceed = 1;


void firstHandler(int sig)
{
	printf("Alarm Signal invoked\n");
	
	// Ignore SIGNAL USR1
	proceed=0;
	return;
}


int main(void)
{
	setvbuf (stdout, NULL, _IONBF, 0);
	printf("Starting Alarm signal\n");
	int iterations = 0;
	struct sigaction act;
	act.sa_handler = &firstHandler;
	alarm (10);
	sigaction(SIGALRM, &act, NULL);

	while(proceed)
		iterations += 1;
	printf("Iterations equal: %d\n", iterations); 
	return 0;
	
}
