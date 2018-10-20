#include<iostream>
#include<map>
#include<iterator>
#include<math.h>
using namespace std;
 int ram[1024];
int ram_size;
int page_size;
int frame_size;
int no_of_frames;

class process
{
    public:
        int pid;
        int process_size = 0;
        int reqired_frames;
        int page_table[1024];

        int start = 0;
    void entry(int i)
    {
        page_table[start++] = i;
    }
    void print()
    {
        cout<<"\nPage table is";
        cout<<"\nPageNo\tFrameNo";
        for(int i=0;i<start;i++)
        {
            cout<<endl<<i<<"\t"<<page_table[i];
        }
    }



};


class comp
{
    public:

        process p[100];
        int count = -1;


    void input()
    {
        cout<<"\nEnter the size of ram";
        cin>>ram_size;
        cout<<"\nEnter the page size";
        cin>>page_size;
        frame_size = page_size;
        no_of_frames = (ram_size/page_size);
        cout<<"\nNumber of frames is"<<no_of_frames;
        for(int i=0;i<ram_size;i++)
        {
            ram[i] = -1;
        }

    }

    void create()
    {
        count++;
         p[count];
        cout<<"\nEnter the id of process";
        cin>>p[count].pid;
        cout<<"\nEnter the memory requirement for process";
        cin>>p[count].process_size;
        int reqired_frames = ceil((float)p[count].process_size/page_size);
        p[count].reqired_frames = reqired_frames;
        cout<<"\nRequired frames is"<<reqired_frames;

        for(int i=0;reqired_frames!=0;i+=frame_size)
        {
            if(ram[i]==-1)
            {
                ram[i] = p[count].pid;
                reqired_frames--;
                p[count].entry(i/frame_size);
            }
        }
        if(reqired_frames!=0)
        {
            cout<<"\nConnot allocate memory";
        }
        p[count].print();


    }

    void deallocate()
    {
        cout<<"\nEnter the id to be dellocated";
        int id;
        cin>>id;


                for(int i=0;i<ram_size;i++)
                {
                    if(id==ram[i])
                    {
                        ram[i] =-1;
                    }
                }


        }



    void print_frame_table()
    {
        cout<<"\nPrinting Frame Table";
        cout<<"\nFrame Number\tProcessId";
        for(int i=0;i<ram_size;i+=frame_size)
        {
            if(ram[i]!=-1)
            {
                cout<<endl<<(i/frame_size)<<"\t"<<ram[i];
            }
        }
    }




};


int main()
{
    comp c;
    c.input();

    while(true)
    {
        cout<<"\n1.Create a process";
        cout<<"\n2.Deallocate a process";
        cout<<"\n3.Print Frame table";
        cout<<"\nEnter your choice::";

        int ch;
        cin>>ch;
        if(ch==1)
        {
            c.create();
        }
        else if(ch==2)
        {
            c.deallocate();
        }
        else if(ch==3)
        {
            c.print_frame_table();
        }
        else
        {
            break;
        }
    }

}

