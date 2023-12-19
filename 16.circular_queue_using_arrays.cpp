// problem with linear Queue is that once it becomes empty after becoming full means once rear =size-1 and front =rear no element can be furthur inserted in the Queue and hence this is disadvantage of linear Queue because memory wastage occurs 
#include <iostream>
using namespace std;
class circularQueue
{
    int *arr = NULL;
    int size;
    int frontInd=0;
    int backInd=0;

public:
    circularQueue(int *ptr, int s)
    {
        arr = ptr;
        size = s;
    }
    int enque(int);
    int deque();
    int isEmpty();
    int isFull();
    void circularQueueTraversal();
};
int circularQueue::enque(int data)
{
    if (isFull())
        cout << "circularQueue is full(overflow)" << endl;
    else
    {
        backInd=(backInd+1)%size;
        arr[backInd] = data;
        return data;
    }
}
int circularQueue::deque()
{
    if (isEmpty())
        cout << "empty circularQueue(underflow)" << endl;
    else
    {
        int data = arr[(frontInd + 1)%size];  //you need to return the data of circular increment of the frontInd not the linear increment 
        frontInd=(frontInd+1)%size;
        return data;
    }
}

int circularQueue::isEmpty()
{
    if (frontInd == backInd)
        return 1;
    return 0;
}

int circularQueue::isFull()
{
    if ((backInd+1)%size==frontInd)
        return 1;
    return 0;
}

// void circularQueue::circularQueueTraversal()
// {
//     if(isEmpty()){
//         cout<<-1;
//     }
//     else{
//     for (int i = frontInd + 1; i <= backInd; i=(i+1)%size)
//     {
//         cout << arr[i] << "\t";
//     }
//     }
//     cout << endl;
// }
int main()
{
    int s = 3;
    int *ptr = (int *)new int[s]; // if used int *ptr = (int *)new int(); then undefined behavior
    circularQueue *q1 = (circularQueue *)new circularQueue(ptr, s);
    cout<<"enqued value is "<<q1->enque(5)<<endl;
    cout<<"enqued value is "<<q1->enque(6)<<endl;
    cout<<"dequed value is "<<q1->deque()<<endl;
    cout<<"dequed value is "<<q1->deque()<<endl;
    cout<<"enqued value is "<<q1->enque(6)<<endl;
    cout<<"enqued value is "<<q1->enque(6)<<endl;
    cout<<"dequed value is "<<q1->deque()<<endl;
    cout<<"dequed value is "<<q1->deque()<<endl;
    cout<<"enqued value is "<<q1->enque(6)<<endl;




    // q1->circularQueueTraversal();
}