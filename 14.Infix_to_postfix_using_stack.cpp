#include <iostream>
using namespace std;
struct stack
{
    int size;
    int top;
    char *arr = NULL;
};

int isEmpty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}
int isFull(struct stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    return 0;
}
void push(struct stack *s, char ch)
{
    if (isFull(s))
    {
        cout << "stack overflow" << endl;
    }
    else
    {
        s->top++; // first incrrement then store value
        s->arr[s->top] = ch;
    }
}

char pop(struct stack *s)
{
    if (isEmpty(s))
    {
        cout << "stack underflow" << endl;
    }
    else
    {
        char data = s->arr[s->top];
        s->top -= 1;
        return data;
    }
}

char stackTop(struct stack *s)
{
    return s->arr[s->top];
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int precedence(char ch)
{
    if (ch == '/' || ch == '*')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 1;
}
char * infixToPostfix(string infix)
{
    struct stack *s1 = (struct stack *)new (struct stack)();
    s1->arr = (char *)new (char)();
    s1->top = -1;
    s1->size = 100;
    char *postfix = (char *)new char();
    int j = 0;
    for (char i : infix)
    {
        if (!isOperator(i))
        {
            postfix[j] = i;
            j++;
        }
        else
        {
            if (precedence(i) > precedence(stackTop(s1)))
                push(s1, i);
            else{
                while(precedence(i) <= precedence(stackTop(s1)) && !isEmpty(s1)){
                postfix[j]=pop(s1);
                j++;
                }
                push(s1,i);
            }
        }
        }
    while(!isEmpty(s1)){
        postfix[j]=pop(s1);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
    string infix="x-y/z-k*d";
    cout<<infixToPostfix(infix);
}

// infix--->given string
// postfix---->output string
// arr-->stack for operation