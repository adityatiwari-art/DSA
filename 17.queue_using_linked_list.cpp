#include <iostream>
using namespace std;
class node
{
    int data;
    int size;
    node *next = NULL;
    node *f = NULL;
    node *r = NULL;

public:
    node()
    {
    }
    bool isEmpty();
    bool isFull();
    int enque(int data);
    int deque();
    void queueTraversal();
};

bool node::isEmpty()
{
    if (f == NULL)
        return 1;
    else
        return 0;
}

bool node::isFull()
{
    node *ptr = (node *)new node();
    if (ptr == NULL)
        return 1;
    else
        return 0;
}

int node::enque(int data)
{
    if (isFull())
        cout << "queue overflow" << endl;
    else
    {
        // data is entered in the queue always at the rear end that is at the last node but if the queue is already empty then the  data is entered  in the first node
        node *ptr = (node *)new node();
        if (f == NULL)
        {
            ptr->data = data;
            f = ptr;
            r = ptr;
        }
        else
        {
            r->next = ptr;
            ptr->next = NULL;
            ptr->data = data;
            r=ptr;
        }
    }
    return data;
}

int node::deque()
{
    int data = -1;
    if (isEmpty())
        cout << "queue underflow" << endl;
    else
    {
        // data is dequed in the queue always at the front end that is at the first node
        node *ptr = (node *)new node();
        ptr = f;
        data = ptr->data;
        f = f->next;
        free(ptr);
    }
    return data;
}

void node::queueTraversal()
{
    node *ptr = f;
    while (ptr != NULL)
    {
        cout << ptr->data << "\t";
        ptr = ptr->next;
    }
    cout << endl;
}
int main()
{
    node *n = (node *)new node();
    cout << "enqued data is " << n->enque(6) << endl;
    cout << "enqued data is " << n->enque(7) << endl;
    cout << "enqued data is " << n->enque(8) << endl;
    cout << "enqued data is " << n->enque(9) << endl;
    cout << "enqued data is " << n->enque(10) << endl;
    n->queueTraversal();
    cout << "dequed data is " << n->deque() << endl;
    cout << "dequed data is " << n->deque() << endl;
    cout << "dequed data is " << n->deque() << endl;
    n->queueTraversal();
}