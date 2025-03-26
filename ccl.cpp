#include <iostream>

using namespace std;

struct node
{
    int data;
    node *link;
};

class CCL
{
    node *last;

public:
    CCL()
    {
        last = NULL;
    }

    void create_end()
    {
        int n;
        cout << "Enter the size of the list: ";
        cin >> n;

        node *temp = NULL;

        for (int i = 0; i < n; i++)
        {
            node *nn = new node;
            if (nn == NULL)
            {
                cout << "Memory allocation failed. ";
            }
            cout << "Enter the data: ";
            cin >> nn->data;
            nn->link = NULL;

            if (i == 0)
            {
                last = nn;
                last->link = last;
            }
            else
            {
                nn->link = last->link;
                last->link = nn;
                last = nn;
            }
        }
    }

    void create_front()
    {
        int n;
        cout << "Enter the size of the list: ";
        cin >> n;

        node *temp = NULL;

        for (int i = 0; i < n; i++)
        {
            node *nn = new node;
            if (nn == NULL)
            {
                cout << "Memory allocation failed. ";
            }
            cout << "Enter the data: ";
            cin >> nn->data;
            nn->link = NULL;

            if (i == 0)
            {
                last = nn;
                last->link = last;
            }
            else
            {
                nn->link = last->link;
                last->link = nn;
            }
        }
    }

    void display()
    {
        node *t = last;
        do
        {
            cout << t->data << " ";
            t = t->link;
        } while (t != last);
    }
};

int main()
{
    CCL lst;
    lst.create_front();
    lst.display();

    lst.create_end();
    lst.display();
    return 0;
}