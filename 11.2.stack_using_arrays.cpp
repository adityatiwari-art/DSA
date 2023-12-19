#include <iostream>
using namespace std;
struct stack
{
    int *arr;
    int top;
    int size;
};
int isFull(struct stack *s);
int isEmpty(struct stack *s);
int push(int data, struct stack *s)
{
    if (isFull(s) == 1)
    {
        cout << "stack overflow condition";
        return 0;
    }
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}
int pop(struct stack *s)
{
    if (isEmpty(s) == 1)
    {
        cout << "stack underflow condition";
        return 0;
    }
    else
    {
        return s->arr[s->top--];
    }
}
int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int peek(struct stack *s, int pos)
{
    if (pos < 0)
    {
        cout << "invalid position" << endl;
        return 0;
    }
    else
    {
        return s->arr[(s->size) - pos];
    }
}
int stack_top(struct stack *s){
    return s->arr[s->top];
}
int stack_bottom(struct stack *s){
    return s->arr[0];
}
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 5;
    s->arr = (int *)new (int)(s->size); // for contiguoes memeory using new we reguire parenthesis and not subscript
    push(5, s);
    push(6, s);

    push(7, s);

    push(8, s);

    push(9, s);
    cout<<stack_top(s)<<"\t";
    cout<<stack_bottom(s)<<"\t";
    // push(9,s);
    for (int i = 1; i <= s->top + 1; i++)
    {
        cout << peek(s, i) << endl;
    }
    pop(s);
    pop(s);
    pop(s);
    pop(s);
    pop(s);

    // pop(s);
}