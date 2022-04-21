#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
	pid_t pid1, pid2, pid3, pid4;
	printf("Parent P1 ID: %d", getpid());
	
	pid1 = fork();
	
	if(pid1 == 0)
		printf("\n\nChild P2 ID: %d\nParent of P2 ID: %d", getpid(), getppid());
	
	if(pid1 > 0) {
		pid2 = fork();
		if(pid2 == 0) {
			printf("\n\nChild P3 ID: %d\nParent of P2 ID: %d", getpid(), getppid());
			pid3 = fork();
			if(pid3 == 0) 
				printf("\n\nChild P4 ID: %d\nParent of P2 ID: %d", getpid(), getppid());
			pid4 = fork();
			if(pid4 == 0) 
				printf("\n\nChild P5 ID: %d\nParent of P2 ID: %d", getpid(), getppid());
		}
	}
	
	for(int i=0; i<3; i++)
		wait(NULL);

	return 0;
}
