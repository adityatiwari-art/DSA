#include <iostream>
using namespace std;
class DEqueue
{
    int data;
    int size;
    int *arr = NULL;
    int f = -1, r = -1;

public:
    bool isEmpty();
    bool isFull();
    DEqueue(int s)
    {
        size = s;
        arr = (int *)new int[s];
    }
    int enquef(int data);
    int enqueR(int data); // basic
    int dequef();         // basic
    int dequeR();
    void DEqueueTraversal();
};



bool DEqueue::isEmpty()
{
    if (f == r)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool DEqueue::isFull()
{
    if (r == size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void DEqueue::DEqueueTraversal()
{
    if (isEmpty())
    {
        cout << -1 << endl;
        return;
    }
    for (int i = f + 1; i <= r; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int DEqueue::enqueR(int data)
{
    if (isFull())
    {
        cout << "queue overflow" << endl;
    }
    else
    {
        r++;
        arr[r] = data;
        return data;
    }
}

int DEqueue::dequef()
{
    if (isEmpty())
    {
        cout << "queue empty" << endl;
    }
    else
    {
        int data;
        data = arr[f + 1];
        f++;
        return data;
    }
}

int DEqueue::enquef(int data)
{
    if (isFull())
    {
        cout << "queue overflow" << endl;
    }

    else
    {
        arr[f]=data;
        f--;
        return data;
    }
}

int DEqueue::dequeR()
{
    if (isEmpty())
    {
        cout << "queue empty" << endl;
    }

    else
    {
        int data;
        data=arr[r];
        r--;
        return data;
    }
}

int main()
{
    DEqueue *q = (DEqueue *)new DEqueue(10);
    cout << "enqued at rear element is " << q->enqueR(8) << endl;
    cout << "enqued at rear element is " << q->enqueR(9) << endl;
    cout << "enqued at rear element is " << q->enqueR(10) << endl;
    cout << "enqued at rear element is " << q->enqueR(11) << endl;  //basic checked
    q->DEqueueTraversal();
    cout << "dequed at front element is " << q->dequef() << endl;  // basic checked
    cout << "dequed at rear element is " << q->dequeR() << endl;
    cout << "enqued at front element is " << q->enquef(12) << endl;
    cout << "dequed at front element is " << q->dequef()<< endl;
    q->DEqueueTraversal();
}