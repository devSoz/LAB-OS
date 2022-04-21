#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/wait.h>
//Producer-consumer problem - The problem occurs when concurrently Mr. X and Mr.
//Y tries to access the same account such a way that Mr. X deposit Rs.5000 and Mr.Y
//wants to withdraw Rs. 2000. Write a C Program to solve the problem with two
//  processes using semaphores.

int mutex = 1;
int full = 0;
int balance = 0;
int empty = 10, x = 0;

int waitx(int s)
{
    return (--s);
}

int signalx(int s)
{
    return (++s);
}

void deposit(int amount)
{
    mutex = waitx(mutex);
    full = signalx(full);
    empty = waitx(empty);
    balance += amount;
    x++;
    printf("Amount = %d", amount);

    printf("   Bank balance: %d\n", balance);
    mutex = signalx(mutex);
}

void withdraw(int amount)
{
    mutex = waitx(mutex);
    full = waitx(full);
    empty = signalx(empty);
    balance -= amount;
    printf("Amount = %d", amount);
    printf("    Bank balance: %d\n", balance);

    x--;
    mutex = signalx(mutex);
}

int main()
{
    int n, i, amount;
    printf("\n1-Deposit\n2-Withdraw\n3-Exit\n");

#pragma omp critical

    for (i = 1; i > 0; i++)
    {

        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if ((mutex == 1) && (empty != 0))
            {
                printf("\nEnter the deposit amount : ");
                scanf("%d", &amount);
                deposit(amount);
            }
            else
                printf("Buffer is full");

            break;

        case 2:
            if ((mutex == 1) && (full != 0))
            {
                printf("\nEnter the withdraw amount: ");
                scanf("%d", &amount);
                withdraw(amount);
            }

            else
                printf("Buffer is empty");

            break;

        case 3:
            exit(0);
            break;
        }
    }
}
