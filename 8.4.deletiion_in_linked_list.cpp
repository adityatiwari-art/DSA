// case4 :deletion after any node
#include <iostream>
using namespace std;
struct node {
    int data;
    struct node * next;
};
void traversal(struct node *p){
    while (p!=NULL)
    {
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<endl;
}
void deletion_case4(struct node *p,struct node*ptr){
struct  node *p2=ptr->next;
ptr->next=(ptr->next)->next;
free(p2);
}
int main(){
struct node *head=(struct node*)malloc(sizeof(struct node));
struct node *second=(struct node*)malloc(sizeof(struct node));
struct node *third=(struct node*)malloc(sizeof(struct node));
struct node *forth=(struct node*)malloc(sizeof(struct node));
struct node *fifth=(struct node*)malloc(sizeof(struct node));

head->next=second;
second->next=third;
third->next=forth;
forth->next=fifth;
fifth->next=NULL;

head->data=1;
second->data=2;
third->data=3;
forth->data=4;
fifth->data=5;

traversal(head);
deletion_case4(head,third);
traversal(head);

}