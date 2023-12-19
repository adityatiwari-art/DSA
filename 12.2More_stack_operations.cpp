#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void traversal(struct node *tp){
    while(tp!=NULL){
        cout<<tp->data<<"\t";
        tp=tp->next;
    }
    cout<<endl;
}
int isEmpty(struct node *tp)
{
    if (tp == NULL)
        return 1;
    else
        return 0;
}
int isFull(struct node *tp)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        return 1;
    else
        return 0;
}
void push(struct node *tp,int data)
{
    if (isFull(top))
        cout << "stack overflow" << endl;
    else
    {
        struct node *n = (struct node *)new (struct node)();
        n->next = tp;
        n->data=data;
        top = n;
    }
}
int pop(struct node *tp)
{
    if (isEmpty(top))
        cout << "stack underflow" << endl;
    else
    {
        struct node *n = tp;
        top = tp->next;
        int x = tp->data;
        free(n);
        return x;
    }
}
int peek(struct node*tp,int pos){
    if(isEmpty(tp))
        cout<<"empty stack peek operation not possible"<<endl;
    else{
        for(int i=0;i<pos;i++){
            if(i==pos-1){
                return tp->data;
            }
            tp=tp->next;
        }
    }
}
int main()
{
    push(top,4);
    push(top,5);
    push(top,6);
    push(top,7);
    push(top,8);
    traversal(top);
    cout<<peek(top,4)<<endl;
    cout<<pop(top)<<endl;
    traversal(top);
}