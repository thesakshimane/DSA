#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next, *prev;
};

class DLL
{
    node *head;

public:
    DLL() { head == NULL; }

    void create()
    {
        int n;
        cout << "Enter the size of the list: ";
        cin >> n;
        node *temp = NULL;

        for (int i = 0; i < n; i++)
        {
            node *nn = new node;
            cout << "Enter the data: ";
            cin >> nn->data;
            nn->prev = NULL;
            nn->next = NULL;

            if (i == 0)
            {
                head = nn;
                nn->prev = NULL;
                nn->next = NULL;
                temp = nn;
            }
            else
            {
                temp->next = nn;
                nn->prev = temp;
                temp = nn;
            }
        }
    }

    void display()
    {
        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << "<->";
            temp = temp->next;
        }
        cout << "X" << endl;
    }
};

int main()
{
    DLL lst;
    lst.create();
    lst.display();
    return 0;
}