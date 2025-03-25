#include <iostream>
using namespace std;

struct node
{
    int data;
    node *link;
};

class SSL
{
    node *head;

public:
    SSL() { head = NULL; }
    void create()
    {
        int n;
        cout << "Enter the size of the linked list: ";
        cin >> n;

        while (head != NULL)
        {
            node *temp = head;
            head = head->link;
            delete temp;
        }

        node *temp;
        for (int i = 0; i < n; i++)
        {
            node *nn = new node;
            cout << "Enter the data: ";
            cin >> nn->data;
            nn->link = NULL;
            if (i == 0)
            {
                head = nn;
                temp = nn;
                continue;
            }
            else
            {
                temp->link = nn;
                temp = nn;
            }
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

    void occurence(int x)
    {
        int count;
        node *prev;
        node *temp = head;
        while (temp->link != NULL)
        {
            if (temp->data = x)
            {
                count++;
            }
            if (count > 1)
            {
                prev->link = temp->link;
                node *delnode = temp;
                temp = temp->link;
                delete delnode;
            }
            prev = temp;
            temp = temp->link;
        }
    }
};

int main()
{
    SSL lst;
    lst.create();
    lst.display();
    lst.occurence(2);
    lst.display();
    return 0;
}