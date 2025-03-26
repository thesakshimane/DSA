#include <iostream>

using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

class BST
{
    node *root;

public:
    BST()
    {
        root = NULL;
    }

    void create()
    {
        int n;
        cout << "Enter the number of nodes: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            node *nn = new node;
            cout << "Enter the data: ";
            cin >> nn->data;
            nn->left = NULL;
            nn->right = NULL;

            if (root == NULL)
            {
                root = nn;
            }
            else
            {
                node *temp = root;
                node *parent = NULL;
                while (temp != NULL)
                {
                    parent = temp;
                    if (nn->data > temp->data)
                    {
                        temp = temp->right;
                    }
                    else if (nn->data < temp->data)
                    {
                        temp = temp->left;
                    }
                }

                if (nn->data > parent->data)
                {
                    parent->right = nn;
                }
                else
                {
                    parent->left = nn;
                }
            }
        }
    }

    void preorder()
    {
    }

    void inorder(node *t)
    {
        if (t == NULL)
        {
            return;
        }
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    void display()
    {
        inorder(root);
    }

    void postorder()
    {
    }

    void insert(int x)
    {
        node *temp = root;
        node *nn = new node;
        nn->data = x;
        nn->right = NULL;
        nn->left = NULL;
        if (nn->data > temp->data)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }

    void delsp(int key)
    {
        node *temp = root;
        node *parent = NULL;
        while (temp != NULL && temp->data != key)
        {
            parent = temp;
            if (key < temp->data)
            {
                temp = temp->left;
            }
            else
            {
                temp = temp->right;
            }
        }
        cout << temp->data << "is found. " << endl;

        if (temp->left == NULL && temp->right == NULL)
        {
            delete temp;
            return;
        }
        else if (temp->left != NULL && temp->right == NULL)
        {
        }
        else if (temp->left == NULL && temp->right != NULL)
        {
        }
        else if (temp->left != NULL && temp->right != NULL)
        {
        }
    }
};

class Stack
{
    node *a[80];
    int top;

public:
    void push(node *t)
    {
        a[++top] = t;
    }

    node *pop()
    {
        return a[top--];
    }

    int empty()
    {
        return (top == -1) ? 1 : 0;
    }

    void preorder(node *t)
    {
        Stack S1;
        while (t != NULL)
        {
            cout << t->data << " ";
            S1.push(t);
            t = t->left;
        }
        while (!S1.empty())
        {
            t = S1.pop();
            t = t->right;
            while (t != NULL)
            {
                cout << t->data << " ";
                S1.push(t);
                t = t->left;
            }
        }
    }
};

int main()
{
    BST t1;
    t1.create();
    t1.display();
}