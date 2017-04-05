#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>


int main(void)
{

	sigset_t mask, orig_mask, pending_set;
	sigfillset(&mask);

	sigprocmask(SIG_BLOCK, &mask, &orig_mask);

	time_t start_t, end_t;
	time(&start_t);

	puts("Will enter loop");
	while(difftime(time(&end_t), start_t) < 15.0) {
		//puts("Hello");	
		//sleep(1);
	}
	puts("Exited from loop");

	// Handle potential error
	sigpending(&pending_set);
	int sig;
	for(sig = 1; sig < NSIG; sig++) {
		if(sigismember(&pending_set, sig)) {
			printf("%d has been blocked\n", sig);
		}
	}	

	return 0;
	
}
