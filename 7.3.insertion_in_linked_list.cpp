#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void traversal(struct node *p){
while(p!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
}
cout<<endl;
}
struct node * insertion_case3(struct node *p, int data,struct node **ptr)
{
    while (p != NULL)
    {
        p = p->next;
    }
    (*ptr)->data=data;
    (*ptr)->next=NULL;
    return *ptr;


}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *forth = (struct node *)malloc(sizeof(struct node));

    head->data = 1;
    second->data = 2;
    third->data = 3;
    forth->data = 4;

    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;
    traversal(head);

    struct node *p = (struct node *)malloc(sizeof(struct node));
    forth->next=insertion_case3(head, 6,&p);
    traversal(head);

}