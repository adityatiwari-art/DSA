#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL; //  top is a pointer and not a node as in case of a LL
void traverse(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}
int isEmpty(struct node *top)
{
    if (top == NULL)
        return 1;
    else
        return 0;
}
int isFull(struct node *top)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        return 1;
    else
        return 0;
}
struct node *push(struct node *top, int data)
{
    if (isFull(top))
        cout << "stack overflow " << endl;
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->next = top;
        n->data = data;
        top = n;
        return top;
    }
}
int pop(struct node *tp)
{
    if (isEmpty(top))
        cout << "stack underflow" << endl;
    else
    {
        struct node *n = top;
        top = tp->next;
        int x = n->data;
        free(n);
        return x;
    }
}
int main()
{
    cout << "push operation in process..." << endl;
    top = push(top, 4);
    top = push(top, 8);
    top = push(top, 9);
    top = push(top, 10);
    traverse(top);
    cout << "pop operation in process..." << endl;
    cout << pop(top) << endl;
    cout << pop(top) << endl;
    traverse(top);
    // struct node *top=(struct node*)malloc (sizeof(struct node *));
}