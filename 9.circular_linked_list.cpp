#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *p)
{
    struct node *ptr = p;
    do
    {
        cout << p->data << "\t";
        p = p->next;
    } while (p != ptr);
    cout << endl;
}
struct node *insertion_atfirst(struct node *&p, struct node *ptr, int data)
{
    struct node *p2 = p; // both head
    ptr->next = p;
    do
    { // loop to access the last node
        p = p->next;
    } while (p->next != p2);
    p->next = ptr;
    ptr->data = data;
    return ptr;
}
void insertion_atlast(struct node *p, struct node *ptr, int data = 50)
{
    struct node *p2 = p;
    do
    { // loop to access the last node
        p = p->next;
    } while (p->next != p2);
    p->next = ptr;
    ptr->next = p2;
    ptr->data = data;
}
void insertion_inbetween(struct node *p, int pos, struct node *ptr, int data = 50)
{
    for (int i = 0; i < pos - 2; i++)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
}
void insertion_afternode(struct node *p,struct node *ptr, int data)
{
ptr->next=p->next;
p->next=ptr;
ptr->data=data;
}

int main()
{
    struct node *head = (struct node *)new (struct node *)();
    struct node *second = (struct node *)new (struct node *)();
    struct node *third = (struct node *)new (struct node *)();
    struct node *forth = (struct node *)new (struct node *)();
    struct node *fifth = (struct node *)new (struct node *)();
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = head;
    //   ^--------------------------------
    // head->second->third->forth->fifth |    //head is the address of second node
    head->data = 1;
    second->data = 2;
    third->data = 3;
    forth->data = 4;
    fifth->data = 5;
    traversal(head);

    struct node *p = (struct node *)new (struct node *)();
    head = insertion_atfirst(head, p, 40);
    traversal(head);

    struct node *p2 = (struct node *)new (struct node *)();
    insertion_atlast(head, p2);
    traversal(head);

    struct node *p3 = (struct node *)new (struct node *)();
    insertion_inbetween(head, 5, p3, 30);
    traversal(head);

    struct node *p4 = (struct node *)new (struct node *)();
    insertion_afternode(p3, p4, 40);
    traversal(head);

    return 0;
}