#include<iostream>
using namespace std;
#define size 3
int h = 0;
class optimal
{
    public:
    int ref[100];
    int r;
    int current_ref = 0;
    int a[size];
    int count = 0;
    int current = -1;
    void input()
    {
        cout<<"\nEnter the size of reference string";
        cin>>r;
        cout<<"\nEnter the reference string";
        for(int i=0; i<r; i++)
        {
            cin>>ref[i];
        }
        find();
    }
    int least_used()
    {
        int max = -1;
        int n = -1;
        h = 0;
        for(int i=0; i<size; i++)
        {
            int x = a[i];
            for(int j=current_ref; j<r; j++)
            {
                if(x==ref[j])
                {
                     h++;
                    if(max<j)
                    {

                        max = j;
                        n = x;

                    }
                }
            }
        }

        return n;
    }
    void print()
    {
        cout<<"\nContent of Page Table";
        if(count<=3)
        {
            for(int i=0; i<count; i++)
            {
                cout<<"\t"<<a[i];
            }
            return;
        }

        for(int i=0; i<size; i++)
        {
            cout<<"\t"<<a[i];
        }
    }
    void find()
    {
        for(int i=0; i<r; i++)
        {
            int x = ref[i];
            cout<<"\nSearching for number"<<x;
            current_ref++;
            //Searching for the page
            int f = 1;
            for(int j=0; j<size; j++)
            {
                if(a[j]==x)
                {
                    cout<<"\nNo Page Fault Occured";
                    print();
                    f = 0;

                }
            }
            if(f)
            {
            //Page Replacement
            cout<<"\nPage Fault Ocuured";
            if(count<size)
            {
                a[++current] = x;
                count++;


            }
            else
            {
                int n =  least_used();
                cout<<"\nValue of n"<<n;
                cout<<"\nValue of h"<<h;
               if(h == 1)
                {
                    for(int k=0; k<size; k++)
                    {
                        if(a[k]!=n)
                        {
                            a[k] = x;
                            break;
                        }
                    }
                    h = 0;
                }
               else  if(n==-1)
                {
                    current = (current+1)%size;
                    a[current] = x;
                }
                else
                {
                    for(int k=0; k<size; k++)
                    {
                        if(n==a[k])
                        {
                            a[k] = x;
                        }
                    }
                }

            }

             print();

        }
        }
    }
};
int main()
{
    optimal o;
    o.input();
}
