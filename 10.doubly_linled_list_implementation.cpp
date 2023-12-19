#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* prev;
    struct node* next;
};
void forward_traversal(struct node* p){
    struct  node*head=p;
// cout<<p->data<<"\t";
// p=p->next;
// while(p!=head){
//     cout<<p->data<<"\t";
//     p=p->next;
// }
// cout<<endl;
while(p->next!=NULL){
    cout<<p->data<<"\t";
    p=p->next;
}
    cout<<p->data<<"\t";
cout<<endl;
// reverse traversal
while(p->prev!=NULL){
    cout<<p->data<<"\t";
    p=p->prev;
}
cout<<p->data<<"\t";
}
int main(){
struct node *head=(struct node*)new (struct node)();
struct node *second=(struct node*)new (struct node)();
struct node *third=(struct node*)new (struct node)();
struct node *fourth=(struct node*)new (struct node)();
struct node *fifth=(struct node*)new (struct node)();
struct node *sixth=(struct node*)new (struct node)();

head->next=second;
second->next=third;
third->next=fourth;
fourth->next=fifth;
fifth->next=NULL;

head->prev=NULL;
second->prev=head;
third->prev=second;
fourth->prev=third;
fifth->prev=fourth;

head->data=1;
second->data=2;
third->data=3;
fourth->data=4;
fifth->data=5;

forward_traversal(head);
}