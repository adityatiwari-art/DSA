// case4:insertion after a node 
#include <iostream>
using namespace std;
struct node{
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
void insertion_case4(struct node *p,struct node* prev_node,struct node* new_node,int data)
{
new_node->next=prev_node->next;
prev_node->next=new_node;
new_node->data=data;
}
int main()
{
struct node *head=(struct node *)malloc(sizeof(struct node));
struct node *second=(struct node *)malloc(sizeof(struct node));
struct node *third=(struct node *)malloc(sizeof(struct node));
struct node *forth=(struct node *)malloc(sizeof(struct node));
head->next=second;
second->next=third;
third->next=forth;
forth->next=NULL;

head->data=1;
second->data=2;
third->data=3;
forth->data=4;

struct node *p=(struct node *)malloc(sizeof(struct node));
traversal(head);

insertion_case4(head,second,p,9);
traversal(head);

}