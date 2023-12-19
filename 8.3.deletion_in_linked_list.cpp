// case 3:deletion from end
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
void deletion_case3(struct node *p)
{
    while (p != NULL)
    {
        if (((p->next)->next) != NULL)
            p = p->next;
        
        else
            break; // if no else then loopwill not terrminate since p will never be equal to NULL beacause it cant encounter if block one node
    }
    if ((((p->next)->next) != NULL))
    {
        struct node *ptr=p->next;
        free(ptr);

    }
    p->next = NULL;
   
}
int main()
{
    struct node *head = (struct node *)new struct node *();
    struct node *second = (struct node *)new struct node *();
    struct node *third = (struct node *)new struct node *();
    struct node *forth = (struct node *)new struct node *();
    struct node *fifth = (struct node *)new struct node *();
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = NULL;

    head->data = 1;
    second->data = 2;
    third->data = 3;
    forth->data = 4;
    fifth->data = 5;

    traversal(head);
    deletion_case3(head);
    traversal(head);
}