#include <iostream>
using namespace std;

class queue
{

public:
    int f = -1, r = -1;
    int size = 100;
    int *arr = NULL;
    queue(int *ptr)
    {
        arr = ptr;
    }
    int isEmpty(queue *q)
    {
        if (q->f == q->r)
            return 1;
        else
            return 0;
    }
    int isFull(queue *q)
    {
        if (q->r == q->size - 1)
            return 1;
        else
            return 0;
    }

    int enque(queue *q, int data)
    {
        if (isFull(q))
        {
            cout << "queue is full enque not possible" << endl;
        }
        else
        {
            q->r++;
            // cout<<r;
            q->arr[q->r] = data;
        }
        return q->arr[q->r];
    }
    int deque(queue *q)
    {
        if (isEmpty(q))
        {
            cout << "queue is empty deletion not possible" << endl;
        }
        else
        {
            int data = q->arr[q->f + 1];
            q->f++;
            return data;
        }
    }
    void queueTraversal(queue *q)
    {
        if (isEmpty(q))
        {
            cout << -1 << endl;
        }
        else
        {
            for (int i = q->f + 1; i <= q->r; i++)
            {
                cout << q->arr[i] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    int visited[7] = {0, 0, 0, 0, 0, 0, 0}; // visited nodes will set to 1
    int i = 4;                              // node to start with
    int a[7][7] = {
        // adjacency matrix
        {0, 1, 1, 1, 0, 0, 0}, // 0 node
        {1, 1, 0, 0, 0, 0, 0}, // 1 node
        {1, 1, 0, 1, 1, 0, 0}, // 2 node
        {1, 0, 1, 0, 0, 0, 0}, // 3 node
        {0, 0, 1, 1, 0, 1, 1}, // 4 node
        {0, 0, 0, 0, 1, 0, 0}, // 5 node
        {0, 0, 0, 0, 1, 0, 0}  // 6 node
    };
    int s = 100;
    int *arr = (int *)new int[s];
    queue *q = (queue *)new queue(arr);
    visited[i] = 1;
    q->enque(q, i);
    cout << i << "\t";
    // q->queueTraversal(q);
    while (!(q->isEmpty(q)))
    {
        int exp = q->deque(q);
        for (int j = 0; j < 7; j++)
        {
            if (a[exp][j] == 1 && visited[j] == 0)
            {
                visited[j] = 1;
                cout << j << "\t";
                q->enque(q, j);
            }
        }
    }
}