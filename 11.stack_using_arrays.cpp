#include <iostream>
using namespace std;
struct stack
{
    int top;
    int *arr;
    int size;
};
// if & is not mentioned then it will work on the copy of the structure and not on the exact structure
void push(struct stack *s, int data)
{
    *(s->arr + s->top + 1) = data;
    s->top += 1;
    cout << s->arr[s->top] << endl;
}

int pop(struct stack *s)
{
    return s->arr[s->top--];
}
int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int main()
{
    struct stack s;
    // or struct stack *s only no dma and hence no need to pass the addresses
    s.size = 10;
    s.top = -1;
    s.arr = (int *)malloc(sizeof(int) * s.size);
    cout << "top is" << s.top << endl;
    if (isEmpty(&s) == 0)
    {
        cout << "the status of stack:not empty" << endl;
    }
    else
    {
        cout << "the status of stack is: empty" << endl;
    }
    push(&s, 7);
    cout << "top is" << s.top << endl;
    push(&s, 9);
    cout << "top is" << s.top << endl;
 if (isEmpty(&s) == 0)
    {
        cout << "the status of stack:not empty" << endl;
    }
    else
    {
        cout << "the status of stack is: empty" << endl;
    }
    // manually pushing element to the stack
    // s.arr[s.top+1]=5;
    // s.top=s.top+1;
    // cout<<s.arr[s.top];
    cout << "poped item is" << pop(&s) << endl;
    cout << "top is" << s.top << endl;
}
// situations when you dont need to pass the adress since the name is itself the address or call by reference ios default:
// arrays,string