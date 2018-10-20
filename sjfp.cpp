#include<iostream>
using namespace std;
#define MAX 100
class process
{
    public:
    int arrival_time = 0;
    int burst_time = 0;
    int waiting_time = 0;
    int total_time =0;
    int response_time =0;
    int id =0;
    int it = 0;
};
class sjfp
{
    public:
    int total_time = 0;
    int current_time =0;
    int n;
    process p[MAX];
    process t[MAX];
    void input()
    {
        cout<<"\nEnter The Number Of Process";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"\nEnter The Arrival Time";
            cin>>p[i].arrival_time;
            cout<<"\nEnter The Burst Time";
            cin>>p[i].burst_time;
            t[i].burst_time = p[i].burst_time ;
            total_time += p[i].burst_time;
            p[i].id = i;

        }
    }
    void sort()
    {
        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n-i-1;j++)
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

    int next()
    {
        int s =-1 ;
      int  burst_time = 1000;
         cout<<"\nCurenrt time::"<<current_time;
        for(int i=0;i<n;i++)
        {


            if((p[i].burst_time > 0 )&& ( current_time >= p[i].arrival_time) && (p[i].burst_time < burst_time))
            {
                s = i;
                burst_time = p[i].burst_time;
            }
        }
        return s;

    }

    void cal()
    {
        sort();
        current_time = p[0].arrival_time;
        cout<<"\nFirst Arrival Time"<<current_time;
        while(total_time>0)
        {

            int c = next();

         //   cout<<"\nid is:"<<p[c].id;
            p[c].it++;
            if(p[c].it==1)
            {
                p[c].response_time = current_time - p[c].arrival_time;
            }
            p[c].burst_time--;
            current_time++;
            if(p[c].burst_time==0)
            {
                p[c].total_time = current_time - p[c].arrival_time;
            }
           // cout<<"\nburst time left is"<<p[c].burst_time;
            cout<<endl;

            total_time--;

        }

    }

    void print()
    {

     cout<<"\nid\tArrivalTime\tResponseTime\tTotalTime\tWaitTime\n";
        for(int i=0;i<n;i++)
        {
            cout<<p[i].id<<"\t";
            cout<<p[i].arrival_time<<"\t\t";;
            cout<<p[i].response_time<<"\t\t";;
            cout<<p[i].total_time<<"\t\t";;
            cout<<p[i].total_time - t[i].burst_time<<"\t";
            cout<<endl<<endl;
        }
        float arp = 0;
        float att = 0;
        float awt = 0;
        for(int i=0;i<n;i++)
        {
             arp += p[i].response_time;
             att += p[i].total_time;
             awt += (p[i].total_time - t[i].burst_time);
        }

        cout<<"\nAverage Total Turnaround Time"<<att/n;
        cout<<"\nAverage Response Time::"<<arp/n;
        cout<<"\nAverage Waiting Time::"<<awt/n;

    }

};
int main()
{
    sjfp p;
    p.input();
    p.cal();
    p.print();
}
