#include<iostream>
using namespace std;
#define size 3
class fifo
{
    int a[size];
    int front = -1;
    int rear = -1;
    int count = 0;
    public:

        void enqueue(int x)
        {

            for(int i=0;i<size;i++)
            {
                if(a[i]==x)
                {
                    cout<<"\nNo Page Fault";
                    return;
                }
            }
            cout<<"\nPage Fault Occured";
            if(rear==-1)
            {
                front=rear=0;
                a[rear] = x;
                count++;
                return ;
            }
            rear = (rear+1)%size;
            count++;
            a[rear] = x;
        }

        void print()
        {
            cout<<"\nContent of Page Table";
            if(count<=3)
            {
                for(int i=0;i<count;i++)
                {
                    cout<<"\t"<<a[i];
                }
            return;
            }

            for(int i=0;i<size;i++)
            {
                cout<<"\t"<<a[i];
            }
        }
};

int main()
{
    fifo f;
    cout<<"\nEnter the length of reference string";
    int n;
    cin>>n;
    int a[n];
    cout<<"\nEnter the string";
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        f.enqueue(a[i]);
        f.print();
    }
}
