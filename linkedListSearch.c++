#include <iostream>
using namespace std;

struct node
{
    int num;
    node *nextptr;
} *stnode; // node defined

void makeList(int n);
void display();
void searchList(int item);

int main()
{
    int n, item;

    cout << "Enter the number of nodes: ";
    cin >> n;
    makeList(n);
    cout << "\nLinked list data: \n";
    display();
    cout << "\nEnter element you want to search: ";
    cin >> item;
    searchList(item);

    return 0;
}

void makeList(int n)
{
    struct node *frntNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));
    if (stnode == NULL)
    {
        cout << "Memory can not be allocated";
    }
    else
    {
        cout << "Enter the data for node 1: ";
        cin >> num;
        stnode->num = num;
        stnode->nextptr = NULL;
        tmp = stnode;

        for (i = 2; i <= n; i++)
        {
            frntNode = (struct node *)malloc(sizeof(struct node));

            if (frntNode == NULL)
            {
                cout << "Memory can not be allocated";
                break;
            }
            else
            {
                cout << "Enter the data for node " << i << ": ";
                cin >> num;
                frntNode->num = num;
                frntNode->nextptr = NULL;
                tmp->nextptr = frntNode;
                tmp = tmp->nextptr;
            }
        }
    }
}

void display()
{
    struct node *tmp;
    if (stnode == NULL)
    {
        cout << "No data found in the list";
    }
    else
    {
        tmp = stnode;
        cout << "Linked List: ";
        while (tmp != NULL)
        {
            cout << "\t" << tmp->num;
            tmp = tmp->nextptr;
        }
        cout << endl;
    }
}

void searchList(int item)
{
    struct node *tmp;
    int i = -1;
    tmp = stnode;
    bool found = false;

    if (stnode == NULL)
    {
        cout << "Empty List\n";
    }
    else
    {
        while (tmp != NULL)
        {
            i++;
            if (tmp->num == item)
            {
                cout << "Item found at location: " << i << endl;
                found = true;
            }
            tmp = tmp->nextptr;
        }
        if (!found)
        {
            cout << "Item not found" << endl;
        }
    }
}
