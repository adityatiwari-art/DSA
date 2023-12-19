// case2:deletion from between
#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *p)
{
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }

    cout << endl;
}
void deletion_case2(struct node *p, int pos)
{
    int i = 1;
    while (i < pos - 1)
    {
        p=p->next;
        i++;
    }
    struct node*ptr;
    ptr=p->next;
    p->next =(p->next)->next;
    free(ptr);
    
}
int main()
{
    struct node *head = (struct node *)new struct node *();
    struct node *second = (struct node *)new struct node *();
    struct node *third = (struct node *)new struct node *();
    struct node *forth = (struct node *)new struct node *();
    struct node *fifth = (struct node *)new struct node *();
    struct node *sixth = (struct node *)new struct node *();
    struct node *seventh = (struct node *)new struct node *();

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next =sixth;
    sixth->next = seventh;
    seventh->next = NULL;

    head->data = 1;
    second->data = 2;
    third->data = 3;
    forth->data = 4;
    fifth->data = 5;
    sixth->data = 6;
    seventh->data = 7;

    traversal(head);
    deletion_case2(head, 5);
    traversal(head);
}