#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    pid_t p1, p2, p3, p4, p5;
    p1 = fork();

    if (p1 == 0)
    {
        printf("P1 => Process ID: %d Parent ID: %d\n", getpid(), getppid());
        p2 = fork();
        if (p2 == 0)
        {
            printf("\nP2 => Process ID: %d Parent ID: %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        }
        else if (p2 > 0)
        {
            wait(NULL);
            p3 = fork();
            if (p3 == 0)
            {
                printf("\nP3 => Process ID: %d Parent ID: %d\n", getpid(), getppid());
                p5 = fork();
                //p4 = fork();
                if (p5 == 0)
                {
                    printf("\nP5 => Process ID: %d Parent ID: %d\n", getpid(), getppid());
                    exit(EXIT_SUCCESS);
                }
                if (p5 > 0)
                {
                    wait(NULL);
                    p4 = fork();
                    if (p4 == 0)
                    {
                        printf("\nP4 => Process ID: %d Parent ID: %d\n", getpid(), getppid());
                        exit(EXIT_SUCCESS);
                    }
                    if (p4 > 0)
                    {
                        wait(NULL);
                    }
                }
            }
            else if (p3 > 0)
            {
                wait(NULL);
            }
        }
        exit(EXIT_SUCCESS);
    }

    else if (p1 > 0)
    {
        wait(NULL);
    }

    return EXIT_SUCCESS;
}