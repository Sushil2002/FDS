//Queue are frequently used in computer programming and a typical example is the creation of a job Queue by an operating sysytem.If the operating system does not use priorities,then jobs are processed in the order they enter the system.Write c++ program for simulating job Queue.Write Function  to add job and delete job from Queue.

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class node{
    string data;
    node *next;
    public:
    node() //default constructor
    {
        data="";
        next=NULL;
    }
    friend class Queue;
};
class Queue{
    node *front; //pointing towards front part
    node *rear;  //pointing towards rear part
    public:
    Queue()  //default constructor
    {
        front=NULL;
        rear=NULL;
    }
    void Enqueue(string name)
    {
        
        node *temp=new node();  //allocating memory for new node
        temp->data=name;  //taking data for new node
        if(front==NULL && rear==NULL)
        {
            front=rear=temp;
        }
        else{
            //In Queue Fronts reamins the Same
            rear->next=temp;
            rear=temp; //now our rear becones the temp
            temp->next=NULL;  
        }
    }
    void display()
    {
        node *ptr=front;
        while(ptr!=NULL)  //will move one step after the last node and will stop
        {
            cout<<ptr->data<<endl;   //will print the data
            ptr=ptr->next;     //incrementing the ptr
        }
    }
    void Dequeue()
    {
        node *ptr=front;//another pointer poiting towards front
        if(front==NULL && rear==NULL) 
        {
            cout<<"Empty Queue!"<<endl;
        }
        else{
            front=front->next; //incrementing front
            //we cannot delete front because if we do that our front lets lost.
            delete ptr;
        }
    }
};
int main(){
    Queue q1;
    string name;
    int ch;
    do
    {
        cout<<"---------------------------"<<endl;
        cout<<"  MAIN MENU  "<<endl;
        cout<<" 1.Enqueue -"<<endl;
        cout<<" 2.Dequeue -"<<endl;
        cout<<" 3.Display -"<<endl;
        cout<<" 4.Exit -"<<endl;
        cout<<"\nEnter Choice:";
        cin>>ch;
        cout<<"---------------------------"<<endl;
        switch(ch)
        {
            case 1:
                cout<<"Enter the Name:";
                cin.ignore();
                getline(cin,name);
                q1.Enqueue(name);
                cout<<"Name Added In the Queue!"<<endl;
                break;
            case 2:
                q1.Dequeue();
                cout<<"Dequeue Successfully!"<<endl;
                break;
            case 3:
                q1.display();
                break;
        }
    } while (ch!=4);
    
    return 0;
}