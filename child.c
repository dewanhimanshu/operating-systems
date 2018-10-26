#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>

int main()
{
    pid_t pid;
    pid = fork();
    if(pid<0)
    {
        fprintf(stderr,"Fork Failed");
        return 1;
    }

    if(pid == 0)
    {
        printf("Child Process Executing\n");
    }
    else
    {
        wait(NULL);
        printf("Parent Process Executing");
    }
    return 0;
}
