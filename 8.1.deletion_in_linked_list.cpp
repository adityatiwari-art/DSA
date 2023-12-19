// same as in insertion we have 4 cases  for deletion also this is the program for the case 1 :deleting the  first element 
#include <iostream>
using namespace std;
struct node {
    int data;
    struct node* next;
};
void traversal(struct node * p){
    while(p!=NULL){
        cout<<p->data<<"\t";
        p=p->next;
    }
    cout<<endl;
}
struct node * deletion(struct node* p){
    struct  node *ptr=p;
    p=p->next;   //imp since freeing ptr will free p if p=p->next is not assigned
    free(ptr);
    return p;
}
int main(){
struct node * head=(struct node *) new struct node*();
struct node * second=(struct node *) new struct node*();
struct node * third=(struct node *) new struct node*();
struct node * forth=(struct node *) new struct node*();

head->next=second;
second->next=third;
third->next=forth;
forth->next=NULL;

head->data=1;
second->data=2;
third->data=3;
forth->data=4;

traversal(head);
head=deletion(head);
traversal(head);

// see how to free since you  have used the same pointer head

}