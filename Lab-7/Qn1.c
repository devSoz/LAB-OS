#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
//Create 2 processes (parent and child process). Child process read N characters and
//Parent process reads and finds total no of vowels. Use shared memory for
//communication.
int main()
{
    int processId = fork(); //creating a child

    if (processId == 0)
    {
        key_t key = ftok("shmfile", 65);
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT); //creating a shared memory and assigning the id
        char *str = (char *)shmat(shmid, (void *)0, 0);

        printf("Enter the character string: ");
        //fgets(str, 1024, stdin);
        scanf("%s", str);
        cin >> str;

        shmdt(str);
    }

    //procesID>0 - Parent
    else
    {

        wait(NULL);

        key_t key = ftok("shmfile", 65);                 //A unique key is generated
        int shmid = shmget(key, 1024, 0666 | IPC_CREAT); //shared memory segment is generated
        char *str = (char *)shmat(shmid, (void *)0, 0);  //shared mempory is attached

        printf("\nData read from memory: %s", str);

        int i = 0, vowelCount = 0;

        for (int i = 0; (str[i] != '\0' && i < 1024); i++)
        {
            char temp = tolower(str[i]);
            if (temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u')
                vowelCount++;
        }
        i++;
        printf("\nNumber of vowels in the string: %d", vowelCount);

        shmdt(str); //shared memory is detached

        shmctl(shmid, IPC_RMID, NULL); //shared memory is destroyed
    }

    return 0;
}
