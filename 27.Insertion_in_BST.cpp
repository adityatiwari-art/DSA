#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node *searchRecursively(node *, int);
    node *searchIteratibly(node *,int);

    node *createNode(int data)
    {
        node *ptr = (node *)new node();
        ptr->data = data;
    }

    void connectNode(node *left, node *right)
    {
        this->left = left;
        this->right = right;
    }
    int insertion(node *root,node * NFI); //NFI=Node For Insertion

    void inOrder(node * root){
        if(root!=NULL){
            inOrder(root->left);
            cout<<root->data<<"\t";
            inOrder(root->right);
        }
    }
};

int node::insertion(node *root,node * NFI){
    while(root!=NULL){
        if(root->data==NFI->data)
            return 0;
        if(NFI->data>root->data && root->right!=NULL){
            root=root->right;
        }
        else if( NFI->data<root->data && root->left!=NULL){
            root=root->left;
        }

        else{
            break;
        }
    }
    if(NFI->data>root->data && root->right==NULL){
        root->right=NFI;
    }
    else{
        if(root->left==NULL)
            root->left=NFI;
    }
    return 1;

}

node *node::searchRecursively(node *root, int key)
{
    if (root == NULL)
        return NULL;

    else if (root->data == key)
        return root;

    else if (key > root->data)
        return searchRecursively(root->right, key);

    else
        return searchRecursively(root->left, key);
}
node *node::searchIteratibly(node * root,int key){
    while(root!=NULL){
        if(root->data==key)
            return root;
        else if(root->data>key)
            root=root->left;
        else
            root=root->right;
    }
}

int main()
{
    node p;
    node *ptr1 = p.createNode(9);
    node *ptr2 = p.createNode(4);
    node *ptr3 = p.createNode(11);
    node *ptr4 = p.createNode(2);
    node *ptr5 = p.createNode(7);
    node *ptr6 = p.createNode(19);
    node *ptr7 = p.createNode(5);
    node *ptr8 = p.createNode(8);
    node *ptr9 = p.createNode(14);

    ptr1->connectNode(ptr2, ptr3);
    ptr2->connectNode(ptr4, ptr5);
    ptr3->connectNode(NULL, ptr6);
    ptr5->connectNode(ptr7, ptr8);
    ptr6->connectNode(ptr9, NULL);

    // node to be inserted
    int key=10;
    node * ptrNew=p.createNode(key);

    if(p.searchRecursively(ptr1,key)==NULL){
        cout<<"element not found"<<endl
        ;
    }
    else{
        cout<<"Found: "<<key<<endl;
    }

    p.inOrder(ptr1);
    cout<<"Insertion Successful"<<endl;
    if (p.insertion(ptr1,ptrNew)==0){
        cout<<"NO duplicate node possible"<<endl;
    }
    else{
    cout<<endl;
     if(p.searchRecursively(ptr1,key)==NULL){
        cout<<"\nelement not found"<<endl;
    }
    else{
        cout<<"Found: "<<key<<endl;
    }
    p.inOrder(ptr1);
    }




}