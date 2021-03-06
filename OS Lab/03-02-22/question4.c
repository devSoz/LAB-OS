#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int fd[2];
	int n;
	char str[100];
	pid_t p;
	
	if(pipe(fd) == -1) {
		printf("Error: Pipe failed");
		exit(0);
	}
	
	p = fork();
	
	if(p < 0) {
		printf("Error: Fork failed");
		exit(0);
	}
	
	else if(p > 0) {
		wait(NULL);
		close(0);
		close(fd[1]);
		dup(fd[0]);
		read(fd[0], str, sizeof(str));
		int ans = 0;
		for(int i=0; i<strlen(str); i++) {
			if(isupper(str[i]))
				tolower(str[i]);
			if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
				ans++;
		}
		printf("Number of vowels = %d\n", ans);
	}	
	
	else {
		close(fd[0]);
		close(1);
		dup(fd[1]);
		scanf("%d", &n);
		fgets(str, sizeof(str), stdin);
		write(fd[1], str, strlen(str)+1);
		close(fd[1]);
	}

	return 0;
}
