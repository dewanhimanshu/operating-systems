#include<stdio.h>
#define BUFFER_SIZE 10
typedef struct
{
    int x;
}item;
int in=0;
int out=0;
item buffer[BUFFER_SIZE];
void producer()
{
    item nextProduced;
    if(((in+1)%BUFFER_SIZE)==out)
    {
        printf("Buffer is full\n");
    }
    else{

    printf("Enter the data you eant to enter");
    scanf("%d",&nextProduced.x);
    buffer[in] = nextProduced;
    in = (in+1)%BUFFER_SIZE;
    }
}
void consumer()
{
    item nextConsumed;
    if(out==in)
    {
        printf("buffer empty\n");
    }
    else
    {
        nextConsumed = buffer[out];
        printf("\nConsumed item is %u",nextConsumed.x);
        out = (out+1)%BUFFER_SIZE;
    }
}

int main()
{

    printf("Menu Driven Program\n");
    while(1)
    {
        printf("\n1.produce data\n");
        printf("2.consume data\n");
         printf("3.exit\n");
        int ch;
        printf("Enter your choice ");
        scanf("%d",&ch);
        if(ch==1)
        {
             producer();
        }
        else if(ch==2)
        {

            consumer();
        }
        else
        {
            return 0;
        }
    }

    return 0;
}
