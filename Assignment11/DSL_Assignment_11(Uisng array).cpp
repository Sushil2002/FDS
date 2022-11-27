//Queue are frequently used in computer programming and a typical example is the creation of a job Queue by an operating sysytem.If the operating system does not use priorities,then jobs are processed in the order they enter the system.Write c++ program for simulating job Queue.Write Function  to add job and delete job ffrom Queue.
#include <iostream>
#define max 100
using namespace std;
class Queue{
    public:
    char array[max];
    int front;
    int rear;
    Queue()
    {
        front=-1;
        rear=-1;
    }
    void Enqueue(char x)
    {
        if((rear==max-1 && front==0) || front==rear+1) 
        {
            cout<<"Queue OverFlow!"<<endl;
        }
        else if(front==-1 && rear==-1)
        {
            rear=0;
            front=0;
            array[rear]=x;
            cout<<"\nAdded In the Queue!"<<endl;
        }
        else{
            rear++;//or rear=rear+1
            array[rear]=x;
            cout<<"Added In the Queue!"<<endl;
        }
    }
    void Dequeue()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"Queue Empty!"<<endl;
        }
        else if(rear==front)
        {
            rear=front=-1;
        }
        else if(front==max-1)
        {
            front=0;
            cout<<"Dequed From the Queue!(Successfully)"<<endl;
        }
        else{
            front++;
            cout<<"Dequed From the Queue!(Successfully)"<<endl;
        }
    }
    void display()
    {
        if(front==-1 && rear==-1)
        {
            cout<<"Empty Queue!"<<endl;
        }
        else{
            for(char i=front;i<=rear;i++)
            {
                cout<<array[i]<<endl;
            }
        }
    }
};
int main(){
    Queue q1;
    
    int ch;
    do
    {
        // int ch;
        cout<<"\n1.Queue EnQueue"<<endl;
        cout<<"2.Queue DeQueue"<<endl;
        cout<<"3.Display"<<endl;
        cout<<"4.Exit"<<endl<<endl;
        cout<<"Enter Chioce:";
        cin>>ch;
        switch(ch)
        {
            case 1:
                char a;
                cout<<"\nEnter the Job Title:";
                cin>>a;
                cout<<endl;
                q1.Enqueue(a);
                break;
            case 2:
                q1.Dequeue();
                break;
            case 3:
                q1.display(); 
                break;
                
        }
    } while (ch!=4);
    
    return 0;
}