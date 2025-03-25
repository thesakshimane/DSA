#include <iostream>

using namespace std;

struct node
{
    int data;
    node *link;
};

class SSL
{
    int n = 0;
    node *head;

public:
    SSL() { head = NULL; }
    void create()
    {
        int n;
        cout << "Enter the decimal number: ";
        cin >> n;

        while (head != NULL)
        {
            node *temp = head;
            head = head->link;
            delete temp;
        }

        node *temp = head;

        for (int i = n; i > 0; i = i / 2)
        {
            node *nn = new node;
            nn->data = i % 2;
            nn->link = head;
            head = nn;
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "->";
            temp = temp->link;
        }
        cout << "NULL" << endl;
    }

    void rotation(int x)
    {
        while (x > 0)
        {
            node *temp = head;
            node *tail = head->link;

            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = head;
            head->link = NULL;
            head = tail;
            x--;
        }
    }

    void get_decimal()
    {
    }
};

int main()
{
    SSL lst;
    lst.create();
    lst.display();
    lst.rotation(1);
    lst.display();
}