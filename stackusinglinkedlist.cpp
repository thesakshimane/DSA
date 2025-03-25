#include <iostream>

using namespace std;

struct node
{
    int data;
    node *link;
};

class Stack
{
    node *head;

public:
    Stack() { head = NULL; }
    void push(int x)
    {
        node *nn = new node;

        if (nn == NULL)
        {
            cout << "Stack full" << endl;
            exit(0);
        }
        nn->data = x;
        nn->link = head;
        head = nn;
    }

    int pop()
    {
        if (is_empty())
        {
            cout << "Stack empty. " << endl;
            exit(0);
        }
        node *temp = head;
        int x = head->data;
        head = head->link;
        delete temp;
        return x;
    }

    void display()
    {
        
    }

    int is_empty()
    {
        if (head == NULL)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
};

int main()
{
    Stack S1;
    S1.push(5);
    S1.pop();
}