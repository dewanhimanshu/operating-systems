#include<iostream>
using namespace std;
int read = 1;
int write = 1;
int queue[100];
int queue_length = 0;
int rear = -1;
int front = -1;
int info = -1;
int count = 0;
int g = 10;

void enqueue(int x)
{
    if(front==-1)
    {
        front = rear = 0;
        queue[front] = x;
        return;
    }
    queue[++rear] = x;
    return ;
}

int dequeue()
{
    if(front==-1)
    {
        cout<<"\nQueue is empty";
        return -1;
    }
    int x = queue[front];
    front++;
    return x;
}
void print ()
{
    for(int i=front;i<=rear;i++)
    {
        cout<<queue[i]<<"->";
    }
}


void signal(int &s)
{
    s++;
}
void wait(int &s,int &f)
{
    if(s<=0)
    {
        f = 0;
        return;
    }
    s--;
}

void produce()
{
    int f = 1;
    wait(write,f);
    cout<<"\nEnter the info to be produced";
    int i;
    cin>>i;
    enqueue(i);
    count++;
    if(f==0)
    {
        cout<<"\nproduced producer put in the queue";
        print();
        return;
    }


}

void  consumer()
{
    if(count==0)
    {
        cout<<"\nNothing to consume";
        return ;
    }
    info = dequeue();
    signal(write);
    count--;
    cout<<"\nConsumed info is"<<info;

}



int main()
{
    while(true)
    {
        cout<<"\n1.Produce";
        cout<<"\n2.consume";
        cout<<"\nEnter your choice";
        int ch;
        cin>>ch;
        if(ch==1)
        {
            produce();
        }
        else if(ch==2)
        {
            consumer();
        }
        else
        {
            break;
        }

    }
}
