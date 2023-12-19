#include <iostream>
using namespace std;
struct stack
{
    int top;
    int size;
    char *arr;
};
int flag = 0;
int isEmpty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    else
        return 0;
}
void push(struct stack *s, char ch)
{
    if (isFull(s))
    {
        flag = 1;
        cout << "overflow" << endl;
    }
    else
    {
        s->top += 1;
        s->arr[s->top] = ch;
    }
}
char pop(struct stack *s)
{
    char popped;
    if (isEmpty(s))
    {
        flag = 1;
    }
    else
    {
        popped = s->arr[s->top];
        s->top -= 1;
    }
    return popped;
}
void para_balanced(struct stack *s1, string s)
{
    for (char i : s)
    {

        if (i == '(')
            push(s1, i);
        else if (i == ')')
        {
            char popped = pop(s1);
            if(popped!='('){
                flag= 1;
            }
        }
        if (i == '[')
            push(s1, i);
        else if (i == ']')
        {
            char popped = pop(s1);
             if(popped!='['){
                flag= 1;
            }
        }
        if (i == '{')
            push(s1, i);
        else if (i == '}')
        {
            char popped = pop(s1);
             if(popped!='{'){
                flag= 1;
            }
        }
    }
    if (!isEmpty(s1))
    {
        flag = 1;
    }
}

int main()
{
    struct stack *s = (struct stack *)new (struct stack)();
    s->size = 50;
    s->top = -1;
    s->arr = (char *)new (char)(s->size);
    string s2 = "x+y+z))+x+y+z)";
    para_balanced(s, s2);
    if (flag == 0)
        cout << "balanced" << endl;
    else
        cout << "not balanced" << endl;
}