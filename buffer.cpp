#include<iostream>
#define BUFFER_SIZE 10
using namespace std;
class item
{
public:
    int info;
};
item buffer[BUFFER_SIZE];
int in = 0;
int out = 0;

void producer()
{

    if((in+1)%BUFFER_SIZE==out)
    {
        cout<<"\nBuffer Full";
        return;
    }
    cout<<"\nEnter the information";
    int x;
    cin>>x;
    item t;
    t.info = x;
    buffer[in] = t;
    in = (in+1)%BUFFER_SIZE;
    return;

}
void consume()
{
    if(in==out)
    {
        cout<<"\nNothing to consume";
        return;

    }
    item  t = buffer[out];
    cout<<"\nValue of consumed item"<<t.info;
    out = (out+1)%BUFFER_SIZE;
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
            producer();
        }
        else if(ch==2)
        {
            consume();
        }
        else{
            break;
        }
    }
}
