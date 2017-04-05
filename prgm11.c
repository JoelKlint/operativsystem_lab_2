#include <stdio.h>
#include <signal.h>
#include <unistd.h>


void secondHandler(int sig)
{
	//printf("SECOND SIG HANDLER INVOKED\n");
	printf("USR2 DETECTED\n");
}

void firstHandler(int sig)
{
	printf("FIRST SIG HANDLER INVOKED\n");
	
	// Ignore SIGNAL USR1
	struct sigaction act;
	act.sa_handler = SIG_IGN;
	sigaction(SIGUSR1, &act, NULL);

	struct sigaction act2;
	act2.sa_handler = &secondHandler;
	sigaction(SIGUSR2, &act2, NULL);

	while(1)
		sleep(1);
	return;
}


int main(void)
{

	struct sigaction act;
	act.sa_handler = &firstHandler;

	sigaction(SIGINT, &act, NULL);

	while(1)
		sleep(1);
	return 0;
	
}
