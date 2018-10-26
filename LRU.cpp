#include<iostream>
using namespace std;
#define size 3
int h = 0;
class lru
{
public:
    int start = 0;
    int end = 0;
    int lru_array[100];
    int ref[100];
    int current_ref = -1;
    int r;
    int a[size];
    int current = 0;
    int count = 0;

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
    void print_lru()
    {
        cout<<"\n Lru array is";
        for(int i=start;i<end;i++)
        {
            cout<<"\t"<<lru_array[i];
        }
    }
    void find()
    {
        for(int i=0; i<r; i++)
        {
            int x = ref[i];
            current_ref++;
            lru_array[end] = x;
            end++;

            int f = 1;
            for(int j=0; j<size; j++)
            {
                if(a[j]==x)
                {
                    cout<<"\nNo page fault occured";
                    f=0;
                    for(int k=start;k<end;k++)
                    {
                        if(lru_array[k]==x)
                        {
                            lru_array[k] = -1;
                        }
                    }
                    lru_array[end] = x;
                    end++;


                }
            }
            if(f)
            {
                cout<<"\nPage Fault Has Occured";
                if(count<size)
                {
                    count++;
                    a[current++] = x;

                }
                else
                {
                    int c = lru_array[start];
                    start++;
                    while(c==-1)
                    {
                        c = lru_array[start];
                        start++;
                    }

                    for(int k=0; k<size; k++)
                    {
                        if(c==a[k])
                        {
                            a[k] = x;
                        }
                    }


                }
            }
            print();
        }
    }
};
int main()
{
   lru l;
   l.input();
}
