#include <iostream>
#include <stdlib.h>
using namespace std;
void linked_list_traversal(struct node *ptr);
struct node
{
    int data;
    struct node *next; // this is a self referencing structure and  each node of a linked list is  astructure thhat has a pointer that points to the next structure
};

void linked_list_traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << "data is " << ptr->data << endl;
        ptr = ptr->next;
        // ptr is thee address of node and initially it is head so head->next i.eptr=  &second node ,then ptr=second node->next as same way
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *forth = (struct node *)malloc(sizeof(struct node));
    head->data = 2;
    head->next = second; // second is a pointer container address of structure of second node allocated dynamically

    second->data = 4;
    second->next = third;

    third->data = 8;
    third->next = forth;

    forth->data = 5;
    forth->next = NULL;

    linked_list_traversal(head);
}
