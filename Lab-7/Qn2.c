#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>

int main()
{
    int processId = fork(); //Child process is created

    if (processId == 0)
    {

        int n;
        printf("Enter the value of n: ");
        scanf("%d", &n);

        key_t key = ftok("fileshm", 65);
        int shmid = shmget(key, sizeof(int) * (n + 1), 0666 | IPC_CREAT);
        int *array = (int *)shmat(shmid, (void *)0, 0);

        array[0] = n;

        printf("Enter the elements: ");
        for (int i = 0; i < n; ++i)
            scanf("%d", &array[i + 1]);

        shmdt(array);
    }

    //processId > 0 - Parent
    else
    {

        wait(NULL);

        key_t key = ftok("fileshm", 65);
        int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
        int *array = (int *)shmat(shmid, (void *)0, 0);

        int sum = 0, n = array[0];

        for (int i = 0; i < n; ++i)
        {
            sum += array[i + 1];
        }

        printf("\nSum of the numbers: %d", sum);

        shmdt(array);
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}
