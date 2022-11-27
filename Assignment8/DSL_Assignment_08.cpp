/*Second year Computer Engineering class,Set A of student like vanilla ice-cream and set B of student like butterscotch ice-cream.Write C++ program to strore two set using Linked-list.Compute and Display 
1.Set of student who like both vanilla and butterscotch 
2.set of student who like either vanilla or butterscotch or not both 
3.Number of student who like neither vanilla nor butterscotch*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Set;
class Node
{
    int data;
    Node *next;

public:
    Node()
    {
        next = NULL;
    }
    friend class Set;
};
class Set
{
public:
    void add_stu(Node **head, int roll_no)
    {
        Node *last;
        Node *ptr = new Node();
        ptr->data = roll_no;
        ptr->next = NULL;
        if (*head == NULL)
        {
            *head = ptr;
        }
        else
        {
            last = *head;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = ptr;
        }
    }
    void display(Node *temp)
    {
        Node *temp1 = temp;
        while (temp1 != NULL)
        {
            cout << temp1->data << "  ";
            temp1 = temp1->next;
        }
        cout << endl;
    }
    Node *intersection(Node *head1, Node *head2)
    {
        Node *newhead = new Node();
        newhead->data = -1;
        Node *newtemp = newhead;
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        while (ptr1 != NULL)
        {
            while (ptr2 != NULL)
            {
                if (ptr2->data == ptr1->data)
                {
                    Node *newnode = new Node();
                    newnode->data = ptr2->data;
                    newtemp->next = newnode;
                    newtemp = newtemp->next;
                    break;
                }
                else
                {
                    ptr2 = ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
        return newhead->next;
    }
    bool ispresent(Node *ptr, int data)
    {
        Node *temp = ptr;
        while (temp != NULL)
        {
            if (temp->data == data)
            {
                return 1;
            }
            temp = temp->next;
        }
        return 0;
    }
    void Union(Node *head4, Node *head1, Node *head2)
    {
        Node *result = NULL;
        Node *ptr1 = head1;
        Node *ptr2 = head2;
        Node *ptr3 = head4;
        while (ptr1 != NULL)
        {
            add_stu(&result, ptr1->data);
            ptr1 = ptr1->next;
        }
        while (ptr2 != NULL)
        {
            if (!ispresent(result, ptr2->data))
            {
                add_stu(&result, ptr2->data);
            }
            ptr2 = ptr2->next;
        }

        while (ptr3 != NULL)
        {
            if (!ispresent(result, ptr3->data))
            {
                cout << ptr3->data << " ";
            }
            ptr3 = ptr3->next;
        }
    }
    void either(Node *head1, Node *head2)
    {
        Node *temp1 = head1;
        Node *temp2 = head2;
        bool check = false;
        while (temp1 != NULL)
        {

            if (!ispresent(temp2, temp1->data))
            {
                cout << temp1->data << " ";
            }
            temp1 = temp1->next;
        }
    }
};
int main()
{
    Set s1;
    Node *uni = NULL;
    Node *total = NULL;
    Node *SetA = NULL;
    Node *SetB = NULL;
    int num, roll_no, o;
    cout << "Enter Total Number of Student In SE-";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        cout << "Enter Roll Number:";
        cin >> roll_no;
        s1.add_stu(&total, roll_no);
    }
    cout << "\nEnter Roll No Are -";
    s1.display(total);

    int vanila, butter, v_roll, b_roll;
    cout << "\nEnter The Total Number Of Student For Vanilla-";
    cin >> vanila;
    for (int i = 0; i < vanila; i++)
    {
        cout << "Enter Roll No.:";
        cin >> v_roll;
        s1.add_stu(&SetA, v_roll);
    }
    cout << "\nStudent Who Like Vanilla Are - ";
    s1.display(SetA);

    cout << "\nEnter The Total Number Of Student For ButterScotch-";
    cin >> butter;
    for (int i = 0; i < butter; i++)
    {
        cout << "Enter Roll No.:";
        cin >> b_roll;
        s1.add_stu(&SetB, b_roll);
    }
    cout << "\nStudent Who Like Buttersotch Are - ";

    s1.display(SetB);

    cout << "\n1.student who like both vanilla and butterscotch are.." << endl; //->1.
    cout << "";
    Node *aj = s1.intersection(SetA, SetB);
    s1.display(aj);

    cout << "\n2.set of student who like either vanilla or butterscotch or not both " << endl;
    cout << "[";
    s1.either(total, aj);
    cout << "]\n";

    cout << "\n3.Number of student who like neither vanilla nor butterscotch" << endl; //->3.
    cout << "[";
    s1.Union(total, SetA, SetB);
    cout << "]\n";
    return 0;
}