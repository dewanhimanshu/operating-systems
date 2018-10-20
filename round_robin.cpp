#include<iostream>
using namespace  std;
#define MAX 100
class process
{
public:
    int total_time = 0;
    int wait_time = 0 ;
    int response_time = 0;
    int arrival_time = 0 ;
    int burst_time =0;
    int c = 0;
    int id;

};
class round
{
    int slice_time =0;
    int total_time = 0;
    int current_time = 0;
    int n;
    int q_count = 0;
    int q[MAX];
    int front = -1;
    int rear = -1;
    process p[MAX];
public:
    void enqueue(int x)
    {
        if(front==-1)
        {
            front=rear =0;
            q[0] = x;
            return;
        }
        q[++rear] = x;

    }
    int dequeue()
    {

        int x = q[front];
        front++;
        return x;
    }

    void input()
    {
        cout<<"\Enter the time slice";
        cin>>slice_time;
        cout<<"\nEnter The Number Of Process";
        cin>>n;

        for(int i=0; i<n; i++)
        {
            cout<<"\nEnter The Arrival Time";
            cin>>p[i].arrival_time;
            cout<<"\nEnter The Burst Time";
            cin>>p[i].burst_time;
            total_time += p[i].burst_time;
            p[i].id = i;

        }
    }
    void sort()
    {
        for(int i=0; i<n-1; i++)
        {
            for(int j=0; j<n-i-1; j++)
            {
                if(p[j].arrival_time>p[j+1].arrival_time)
                {
                    process temp = p[j];
                    p[j] = p[j+1];
                    p[j+1] = temp;
                }
            }
        }
    }
    void update()
    {
        for(int i=0;i<n;i++)
        {
            if(p[i].burst_time>0 && p[i].arrival_time==current_time)
            {
                enqueue(i);
                q_count++;
            }
        }
    }
    void run()
    {
        sort();

        current_time = p[0].arrival_time;
        enqueue(0);
        q_count = 1;
        int flag =0 ;
        int count = 0;
        int r;
        while(current_time<=total_time)
        {
            if(q_count!=0||flag==1)
            {

                    if(q_count!=0&&flag==0)
                    {
                        r = dequeue();
                        q_count--;
                        count = 0;
                        flag = 1;
                        continue;
                    }
                    if(count!=slice_time)
                    {
                        p[r].burst_time--;
                        count++;
                        update();
                        current_time++;
                        cout<<endl<<r;
                        continue;
                    }
                    if(count==slice_time)
                    {
                        if(p[r].burst_time==0)
                        {
                            cout<<endl<<r;
                        }
                        else
                        {
                            cout<<endl<<r;
                            //update();
                            enqueue(r);
                            q_count++;


                        }
                        count=0;
                        flag = 0;

                    }

            }
            else
            {
                update();
                current_time++;

            }

        }



    }

};


int main()
{
round r;
r.input();
r.run();
//r.test();
}
