// case 2:insertion in between
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
struct node *insertion_case2(int node_num, struct node *p)
{
    int i = 1;
    while (i < node_num - 1)
    {
        // node_num-1 reson is given in copy for node_num=5 beacause it will go till i=4 an then will assign p=4->next i.e fift address but we need 4th address to insert at fifth
        p = p->next;
        i++;
    }
    return p;
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *forth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));
    struct node *sixth = (struct node *)malloc(sizeof(struct node));
    struct node *seventh = (struct node *)malloc(sizeof(struct node));
    struct node *eight = (struct node *)malloc(sizeof(struct node));
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = NULL;
    head->data = 1;
    second->data = 2;
    third->data = 3;
    forth->data = 4;
    fifth->data = 5;
    sixth->data = 6;
    seventh->data = 7;
    eight->data = 8;
    traversal(head);
    // node to be inserted
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *previous_node = insertion_case2(5, head); // the first argument is the position where new node is to be inserted
    p->next = previous_node->next;
    previous_node->next = p;
    p->data = 20;
    traversal(head);
}