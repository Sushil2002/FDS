/*In any language program mostly syntax error occurs due to unbalancing the delimiter such as (),{},[].write c++ program using stack to check  whether given expression is well paraentheesized or not.*/

#include <iostream>
#define max 100
using namespace std;
class stack{
    int top;
    char array[max];
    public:
    stack()
    {
        top=-1;
    }
    int top1()
    {
        return array[top];
    }
    int  isfull()
    {
        if(top==max-1)
        {
            return 1;
            cout<<"Stack OverrFlow!"<<endl;
        }
        else
        {
            return 0;
        }
    }
    int isEmpty()
    {
        if(top==-1)
        {
            return 1;
            cout<<"Stack underFlow!"<<endl;
        }
        else
        {
            return 0;
        }
    }
    void push(char x)
    {
        if(isfull())
        {
            cout<<"Stack OverrFlow!"<<endl;
        }
        else
        {
            top++;
            array[top]=x;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"Stack OverrFlow!"<<endl;
        }
        else
        {
            top--;
        }
    }
    friend class parenthesis;
};
class parenthesis{
    stack sp;
    string exp;
    public:
    void setdata()
    {
        cout<<"\n\nEnter the Expression:";
        cin>>exp;
    }
    void check()
    {
        for(int i=0;i<exp.length();i++)
        {
            if(exp[i]=='(' || exp[i]=='{' ||  exp[i]=='[')
            {
                sp.push(exp[i]);
            }
            else if(exp[i]==')'  &&  sp.top1()=='(')
            {
                sp.pop();
            }
            else if(exp[i]==']'  &&  sp.top1()=='[')
            {
                sp.pop();
            }
            else if(exp[i]=='}'  &&  sp.top1()=='{')
            {
                sp.pop();
            }
            
            else if(  (exp[i]==']'  || exp[i]=='}' || exp[i]==')') && sp.isEmpty())
            {
                sp.push(exp[i]);
                cout<<"\nEXPRESSION IS NOT BALANCED!\n"<<endl;
            }
            else if(!sp.isEmpty())
            {
                cout<<"\nEXPRESSION IS NOT BALANCED!\n"<<endl;
            }
        }
        
        if(sp.isEmpty())
        {
            cout<<"\nEXPRESSION IS BALANCED!\n"<<endl;
        }
        else{
            cout<<"\nEXPRESSION IS NOT BALANCED!***\n"<<endl;
        }
    }
};
int main(){
    parenthesis p;
    p.setdata();
    p.check();
    return 0;
}