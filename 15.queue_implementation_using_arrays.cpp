#include <iostream>
using namespace std;
class queue
{
    int *arr = NULL;
    int size;
    int frontInd=-1;
    int backInd=-1;

public:
    queue(int *ptr, int s)
    {
        arr = ptr;
        size = s;
    }
    void enque(int);
    int deque();
    int isEmpty();
    int isFull();
    void queueTraversal();
};
void queue::enque(int data)
{
    if (isFull())
        cout << "queue is full(overflow)" << endl;
    else
    {
        arr[++backInd] = data;
    }
}
int queue::deque()
{
    if (isEmpty())
        cout << "empty queue(underflow)" << endl;
    else
    {
        int data = arr[frontInd + 1];
        frontInd++;
        return data;
    }
}

int queue::isEmpty()
{
    if (frontInd == backInd)
        return 1;
    return 0;
}

int queue::isFull()
{
    if (backInd == size - 1)
        return 1;
    return 0;
}

void queue::queueTraversal()
{
    if(isEmpty()){
        cout<<-1;
    }
    else{
    for (int i = frontInd + 1; i <= backInd; i++)
    {
        cout << arr[i] << "\t";
    }
    }
    cout << endl;
}
int main()
{
    int s = 5;
    int *ptr = (int *)new int[s]; // if used int *ptr = (int *)new int(); then undefined behavior
    queue *q1 = (queue *)new queue(ptr, s);
    q1->enque(4);
    q1->enque(5);
    q1->enque(6);
    q1->enque(7);
    q1->enque(8);
    q1->enque(8);
    q1->queueTraversal();
    q1->deque();
    q1->deque();
    q1->deque();
    q1->deque();
    q1->deque();
    q1->enque(8);
    q1->queueTraversal();
}