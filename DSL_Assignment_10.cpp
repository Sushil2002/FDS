/*Implement c++ program for expression conversion as infix to postfix and its evaluation using Stack based on given condition:
1.Operands and operator ,both must be single character
2.Inputs Postfix Expression must be in a desired format.
3.only '+','-','*' and '/' operators are expected.*/

#include <iostream>
#include <stack>
#define max 100
using namespace std;
class Stack  //class
{
    public:
    int top;
    char array[max];
    Stack()           //defalut Contructor
    {
        top = -1;
    }
    char top1()       //it points toward the top of the Stack
    {
        return array[top];
    }
    int isFull()  //check whether the Stack is full !
    {
        if(top==max-1)  
        {
            cout<<"Stack Overflow"<<endl;
            return 1;
        }
        else{
            return 0;  
        }
    }
    int isEmpty()    //check whether the Stack is Empty !
    {
        if(top==-1)
        {
            return 1;
        }
        else
            return 0;
    }
    void push(char x)
    {
        if(isFull())
        {
            cout<<"Stack Overflow!";
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
            cout<<"Stack UnderFlow"<<endl;
        }
        else
        {
            char x=array[top];
            top--;
        }
    }
    friend class Expression;
    
};
class Expression{
    public:
    Stack sp;
    string infix;
    string postfix; 
    void SetData()
    {
        cout<<"\n\nEnter Expression:";
        cin>>infix;
    }
    int pre(char c)
    {
        if(c=='*' || c=='/')
        {
            return 2;
        }
        else if(c=='+' || c=='-')
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
    void convert()
    {
        for(int i=0;i<infix.length();i++)
        {
            if(isalpha(infix[i]))
            {
                postfix=postfix+infix[i];
            }
            else if(infix[i]=='(')
            {
                sp.push(infix[i]);
            }
            else if(infix[i]==')')
            {
                while(sp.top1()!='(')
                {
                    postfix=postfix+sp.top1();
                    sp.pop();
                }
                sp.pop();
            }
            else
            {
                while(!sp.isEmpty() && (pre(infix[i])<=pre(sp.top1())))
                {
                    postfix=postfix+sp.top1();
                    sp.pop();
                }
                sp.push(infix[i]);
            }
        }
        while(!sp.isEmpty())
        {
            postfix=postfix+sp.top1();
            sp.pop();
        }
        cout<<postfix;
    }
    void value()
    {
        stack <int> st; 
        for(int i=0;i<postfix.length();i++)
        {
            if(isalpha(postfix[i]))
            {
              cout<<"\n\nEnter Vaule for "<<postfix[i]<<": ";
              int a;
              cin>>a;
              st.push(a);
            }
            else{
              int op1=st.top();
              st.pop();
              int op2=st.top();
              st.pop();
              switch(postfix[i])
              {
                case '*':
                    st.push(op2*op1);
                    break;
                case '/':
                    st.push(op2/op1);
                    break;
                  case '+':
                    st.push(op2+op1);
                    break;
                  case '-':
                    st.push(op2-op1);
                    break;
              }
            }

        }
        cout<<"Value is  "<<st.top();


    }

};
    
int main()
{
    Expression exp;
    exp.SetData();
    exp.convert();
    exp.value();
    return 0;
}