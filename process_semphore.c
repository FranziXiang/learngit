/*************************************************************************
	> File Name: process_semphore.c
	> Author: 
	> Mail: 
	> Created Time: 2018年03月20日 星期二 22时29分38秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<error.h>
#include<sys/sem.h>

#define key (key_t)1024

int main()
{
    pid_t pid;
    pid = fork();
    int sem_int;
    struct sembuf * opsptr;
    sem_int = semget(key,1,IPC_CREAT);
    while(1)
    {
        if(pid < 0)
        {
            fprintf(stderr,"error fork()");
        }
        else if(pid > 0)
        {
            opsptr->sem_op=-1;
            semop(sem_int,opsptr,1);
            printf("i am parent process\n");
            sleep(1);
            opsptr->sem_op=1;
            semop(sem_int,opsptr,1);
        }
        else
        {
            sleep(20);
            while(1)
            {
                opsptr->sem_op=-1;
                semop(sem_int,opsptr,1);
                printf("i am child process\n");
                opsptr->sem_op=1;
                semop(sem_int,opsptr,1);
            }
        }
    }
}

