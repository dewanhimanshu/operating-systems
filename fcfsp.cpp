#include<iostream>
using namespace std;
#define MAX 100
class process
{
    public:
        int arrival_time = 0;
        int total_time = 0;
        int wait_time = 0;
        int response_time =0;
        int burst_time = 0;
        int priority = 0;
    void set()
    {
        cout<<"\nenter your arrival time";
        cin>>arrival_time;
        cout<<"\nenter your burst time";
        cin>>burst_time;
        cout<<"\nenter your priority";
        cin>>priority;


    }
};
class fcfs
{

    process a[MAX];
    int n;
    int current_time;
    public :

        fcfs()
        {
            current_time =0;
        }
        void set()
        {
            cout<<"enter the number of process";
            cin>>n;
            for(int i =0 ;i<n;i++)
            {
                a[i].set();
            }
        }
        void sort()
        {
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n-i-1;j++)
                {
                    if (a[j].priority < a[j+1].priority){
                        process temp = a[j];
                        a[j] = a[j+1];
                        a[j+1] = temp;
                    }
                }
            }
        }
        void table()
        {
            sort();
            current_time = a[0].arrival_time;
            for(int i =0 ;i<n;i++)
            {
                a[i].wait_time = current_time-a[i].arrival_time;
                a[i].response_time = current_time-a[i].arrival_time;
                current_time += a[i].burst_time;
                a[i].total_time = current_time-a[i].arrival_time;
                cout<<"\n*******************";
                cout<<"\nArrival time"<<a[i].arrival_time;
                cout<<"\nTotal turn Aroun time"<<a[i].total_time;
                cout<<"\nWait time"<<a[i].wait_time;
                cout<<"\nRespone Time"<<a[i].response_time;
            }
        }
        void efficency()
        {
            float total_time = 0;
            float wait_time = 0;
            float response_time = 0;
            for(int i=0 ;i<n;i++)
            {
                total_time += a[i].total_time;
                wait_time += a[i].wait_time;
                response_time += a[i].response_time;

            }
            total_time /= n;
            wait_time /= n;
            response_time /= n;

            cout<<"\n*******************";

            cout<<"\nTotal turn Aroun time"<<total_time;
            cout<<"\nWait time"<<wait_time;
            cout<<"\nRespone Time"<<response_time;


            cout<<"\n***********************";
             cout<<"\nArrival Time \t total_time \t wait time \t response time\n";
             for(int i =0 ;i<n;i++)
             {
                cout<<i<<"\t"<<a[i].arrival_time<<"\t"<<a[i].total_time<<"\t\t"<<a[i].wait_time<<"\t"<<a[i].response_time<<endl;

             }
             cout<<"\t       "<<total_time<<"\t \t"<<wait_time<<"\t\t"<<response_time;



        }




};

int main()
{
    fcfs cpu;
    cpu.set();
    cpu.table();
    cpu.efficency();


}
