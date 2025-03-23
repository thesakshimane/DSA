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

        if (n < 0)
        {
            cout << "Invalid size! List size cannot be negative." << endl;
            return;
        }

        // Free the existing list
        while (head != NULL)
        {
            node *temp = head;
            head = head->link;
            delete temp;
        }

        node *temp = NULL; // Proper initialization
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
        if (head == NULL)
        {
            cout << "The list is empty. " << endl;
        }
        else
        {
            node *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << "->";
                temp = temp->link;
            }
            cout << "NULL" << endl;
        }
    }

    void insert_front(int x)
    {
        node *nn = new node;
        nn->data = x;
        nn->link = head;
        head = nn;
    }

    void insert_end(int x)
    {
        node *nn = new node;
        nn->data = x;
        nn->link = NULL;

        if (head == NULL)
        {
            head = nn;
            return;
        }

        node *temp = head;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = nn;
    }

    void delete_front()
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        head = head->link;
        delete temp;
    }

    void delete_end()
    {
        if (head == NULL) // Empty list
        {
            return;
        }
        if (head->link == NULL) // Only one node
        {
            delete head;
            head = NULL;
            return;
        }

        node *temp = head;
        node *prev = NULL;

        while (temp->link != NULL)
        {
            prev = temp;
            temp = temp->link;
        }

        if (prev != NULL) // Check before using prev->link
            prev->link = NULL;

        delete temp;
    }

    void insert_pos(int x, int p)
    {
        if (p <= 0)
        {
            cout << "Invalid position! Position should be >= 1." << endl;
            return;
        }

        node *nn = new node;
        nn->data = x;
        nn->link = NULL;

        if (p == 1) // Insert at the beginning
        {
            nn->link = head;
            head = nn;
            return;
        }

        node *temp = head;
        for (int i = 1; i < p - 1 && temp != NULL; i++)
        {
            temp = temp->link;
        }

        if (temp == NULL) // If position is out of bounds
        {
            cout << "Invalid position! List has fewer elements." << endl;
            delete nn;
            return;
        }

        nn->link = temp->link;
        temp->link = nn;
    }

    void delete_pos(int p)
    {
        if (head == NULL)
        {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (p <= 0)
        {
            cout << "Invalid position! Position should be >= 1." << endl;
            return;
        }

        if (p == 1) // Delete first node
        {
            node *temp = head;
            head = head->link;
            delete temp;
            return;
        }

        node *temp = head;
        node *prev = NULL;

        for (int i = 1; i < p - 1 && temp != NULL; i++)
        {
            temp = temp->link;
        }

        if (temp == NULL || temp->link == NULL) // If position is out of bounds
        {
            cout << "Invalid position! No node exists at position " << p << "." << endl;
            return;
        }

        node *delNode = temp->link;
        temp->link = delNode->link;
        delete delNode;
    }

    void search(int x)
    {
        if (head == NULL)
        {
            cout << x << " not found. The list is empty." << endl;
            return;
        }

        node *temp = head;
        int count = 1;
        bool found = false;

        while (temp != NULL)
        {
            if (temp->data == x)
            {
                cout << x << " is found at position " << count << "." << endl;
                found = true;
            }
            temp = temp->link;
            count++;
        }

        if (!found)
        {
            cout << x << " not found in the list." << endl;
        }
    }
};

int main()
{
    SSL lst;
    lst.create();
    lst.display();
    lst.insert_pos(3, 1);
    lst.display();
}