#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
    int data;
    struct node *next;
};
void inserting_element_in_linked_list(struct node *p)
{
    cout << "enter linked list elements:";
    while (p != NULL)
    {
        cin >> p->data;
        p = p->next;
    }
}
void printing_element_of_linked_list(struct node *p)
{
    cout << "the elements of liked list are:";
    while (p != NULL)
    {
        cout << p->data << "\t";
        p = p->next;
    }
    cout << endl;
}
// cases of insertion
// 1.insertion at starting
// 2.insertion at the end
// 3.insertion in between
// 4.insertion after a node
// void insertion_case1(struct node **head, struct node *ptr_new)
// {
//     ptr_new->next = *head;
//     *head = ptr_new;
//     ptr_new->data = 20;
// }
// problem1: encountered
// void insertion_case1(struct node *head, struct node *ptr_new)
// {
//     ptr_new->next = head;
//     head= ptr_new;
//      //local head is assigned new value it stopped pointing to the old address but the head in main is still pointing to the first node that was iniitially given
//     ptr_new->data = 20;
//     cout<<head->data<<endl;  //local head pointing to  ptr_new or that passed address
//     //but if yoou are printing  ptr_new->data in main after this function executiion you will get 20 this means that the node is successfully created but the head is not  assigned the new value //local head pointing to  ptr_new or that passed address
// }

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *forth = (struct node *)malloc(sizeof(struct node));
    // to be inserted
    struct node *ptr_new = (struct node *)malloc(sizeof(struct node));
    head->next = second;
    second->next = third;
    third->next = forth;
    forth->next = NULL;
    // printf("value of ptr_new pointer in main is i.e added value %d\n",ptr_new);
    inserting_element_in_linked_list(head);
    printing_element_of_linked_list(head);
    cout << "LL after insertion:" << endl;
    printing_element_of_linked_list(head);
    
}
// solution to problem1:preffered first 
// 1.by retuning the value of local head 
// struct node* insertion_case1(struct node *head, struct node *ptr_new)
// {
//     ptr_new->next = head;
//     head= ptr_new;
//      //local head is assigned new value it stopped pointing to the old address but the head in main is still pointing to the first node that was iniitially given
//     ptr_new->data = 20;
//     cout<<head->data<<endl;  //local head pointing to  ptr_new or that passed address
//     //but if yoou are printing  ptr_new->data in main after this function executiion you will get 20 this means that the node is successfully created but the head is not  assigned the new value //local head pointing to  ptr_new or that passed address
//     return head;
// }
    // head=insertion_case1(head, ptr_new);

// 2.by using a pointer to the pointer so that the change is refelected as done in this program