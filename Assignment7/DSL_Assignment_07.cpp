/*
The ticket booking system of Cinemax theater haa to be implemented using c++.there are 10 rows and 7 seats in each row. Doubly circulated  created linked list has to be maintained to keep track of free seats at rows.Assume some random to start with.use array to store  pointer to each row.on demand
a)the list of avalabile seats is to be  displayed 
b)the seats are to be booked
c)the booking can be canceled                                                                            
*/

//Doubly circulated linked list Has Been used!
//Pointer Reqiured Reqiured are next and prev.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    class node *next;
    class node *prev;

    node() //Default Consructor,of class node is called when obj is created!
    {
        data = 0; //data vaule is intialize with zero!
        next = NULL;
        prev = NULL;
    }
    friend class Ticket;

} * (head[10]), *(last[10]);
class Ticket
{

    // class node ,;    //creating array pointer object with ,head and last as variable!
public:
    //Doubly circular link-list
    Ticket()
    {
        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 8; j++)
            {
                head[i] = last[i] = NULL; //Empty list->head and last are poiting towards NULL
            }
        }
        for (int i = 1; i < 11; i++)
        {
            for (int j = 1; j < 8; j++)
            {
                class node *ptr = new node(); //Allocating New memory for new node
                //Initailization For Link-list
                if (head[i] == NULL)
                {
                    //head[i]==NULL then head and last both are poitiong towards ptr
                    head[i] = last[i] = ptr;
                    head[i]->next = head[i];
                    last[i]->next = last[i];
                    head[i]->prev = head[i];
                    last[i]->prev = last[i];
                }
                else
                {
                    //temp pointer is poiting towards head[i] for traversing
                    class node *temp = head[i];
                    do
                    {
                        temp = temp->next; //Incrementing temp
                    } while (temp->next != head[i]);
                    temp->next = ptr;
                    ptr->prev = temp;
                    ptr->next = head[i];
                    ptr = last[i];           //now our ptr is last node and
                    head[i]->prev = last[i]; //head->prev is poiting towards last[i]
                }
            }
        }
    }
    void avalabile_seats()
    {

        cout << "ROW/COL";
        for (int i = 1; i < 8; i++)
            cout << setw(8) << i;
        cout << endl;
        for (int i = 1; i < 11; i++)
        {
            class node *ptr = head[i];
            cout << "ROW-" << setw(3) << i;
            while (ptr->next != head[i])
            {
                if (ptr->data == 0)
                {
                    cout << setw(8) << "0"; //E->Empty!
                }
                else
                {
                    cout << setw(8) << "1"; //E->Booked!
                }
                ptr = ptr->next; //Incrementing ptr
            }
            if (ptr->data == 0)
                cout << setw(10) << "0";
            else
                cout << setw(10) << "1";
            cout << endl;
        }
    }
    void book_seat()
    {
        int row, col;
        cout << "Enter The Row:";
        cin >> row;
        cout << "Enter The Col:";
        cin >> col;
        if (row > 10 || col > 7)
        {
            cout << "Invalid Choice!" << endl;
            return;
        }
        class node *ptr = head[row];
        for (int j = 1; j < col; j++) //for getting the correct coloum
        {
            ptr = ptr->next; //incrementing the ptr till we get correct coloum entered by user!
        }
        if (ptr->data == 1)
        {
            cout << "\nTicket Is Already Booked!" << endl
                 << endl;
        }
        else
        {
            ptr->data = 1;
            cout << "\n\nTicket Booked SuccessFully!\n"
                 << endl;
        }
    }
    void cancel_booking()
    {
        int row, col;
        cout << "Enter The Row:";
        cin >> row;
        cout << "Enter The Col:";
        cin >> col;
        if (row > 10 || col > 7)
        {
            cout << "Invalid Choice!" << endl;
            return;
        }
        class node *ptr = head[row];
        for (int j = 1; j < col; j++)
        {
            ptr = ptr->next;
        }
        if (ptr->data == 0)
        {
            cout << "\n\nTicket Is Not Booked Yet!" << endl;
        }
        else
        {
            ptr->data = 0;
            cout << "\n\nTicket Canclelation Successfully!\n"
                 << endl;
        }
    }
};
int main()
{
    Ticket t;
    int choice;
    system("color 0B"); //Color Changes
    do
    {
        cout << "\n\n----  MAIN MENU  ----" << endl
             << endl;
        cout << "1.AVAILABLE SEAT -" << endl;
        cout << "2.BOOK SEAT -" << endl;
        cout << "3.CANCEL TICKET -" << endl;
        cout << "4.EXIT." << endl
             << endl;
        cout << "Enter Choice-";
        cin >> choice;
        cout << "\n";

        switch (choice)
        {
        case 1:
            t.avalabile_seats();
            break;
        case 2:
            t.book_seat();
            break;
        case 3:
            t.cancel_booking();
            break;
        case 4:
            break;
        }
    } while (choice != 4);

    return 0;
}