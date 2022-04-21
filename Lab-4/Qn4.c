#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <ctype.h>

int main(void)
{
    int n;
    char str[100];
    FILE *inputFile;
    inputFile = fopen("inputFile4.txt", "r");
    printf("Number of characters: ");
    scanf("%d", &n);

    int fd[2], i = 0;
    pipe(fd);
    pid_t pid = fork();

    if (pid > 0)
    {
        wait(NULL);
        close(0);
        close(fd[1]);
        dup(fd[0]);
        char str[100];
        int count = 0;
        int size = read(fd[0], str, sizeof(str));
        for (i = 0; i < size; i++)
        {
            str[i] = tolower(str[i]);
            if ((str[i] == 'a') || (str[i] == 'e') || (str[i] == 'i') || (str[i] == 'o') || (str[i] == 'u'))
                count++;
        }
        printf("Number of vowels: %d", count);
    }
    else if (pid == 0)
    {
        printf("Enter string: ");
        scanf("%s", str);
        close(fd[0]);
        close(1);
        dup(fd[1]);
        write(1, str, n);
    }
}
