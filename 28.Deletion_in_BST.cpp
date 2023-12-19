#include <iostream>
using namespace std;
class node
{

public:
    int data;
    node *left = NULL;
    node *right = NULL;
    node *createNode(int data);
    void connectNode(node *, node *);
    node *search(node *, int);
    node* deletion(node *, int);
    void inOrder(node *);
    node* findMax(node *);
};

node * node::findMax(node * root){
    if(root->right!=NULL){
    findMax(root->right);
    // other frames will only return to the old call exept the base condition 
    }
    else{
        return root;
        // since other frames are not returning any value therfore the returned value of the base condtion is returned by the actual function call
    }
}

node *node::createNode(int data)
{
    node *ptr = (node *)new node();
    ptr->data = data;
    return ptr;
}

void node::connectNode(node *left = NULL, node *right = NULL)
{
    this->left = left;
    this->right = right;
}

node *node::search(node *root, int key)
{
    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return NULL;
}

node * node::deletion(node *root, int key)
{
    if (root == NULL)
    {
        cout << "node not exist in the tree" << endl;
        return NULL;
    }

    else if (key < root->data)
    {
        root->left=deletion(root->left,key);
    }
    else if (key > root->data)
    {
        root->right=deletion(root->right,key);
    }
    // case of equality
    else
    {
        if(root->left && root->right){  //both are not NULL
        root->data=findMax(root->left)->data;
        root->left=deletion(root->left,root->data);
        }

        else{
            node * temp=root;
            if(root->right==NULL){
                root=root->left;
            }
            if(root->left==NULL){
                root=root->right;
            }
            free(temp);
        }
    }
    return root;
}

void node::inOrder(node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        cout << (root->data) << "\t";
        inOrder(root->right);
    }
}

int main()
{
    node p;
    node *ptr1 = p.createNode(8);
    node *ptr2 = p.createNode(3);
    node *ptr3 = p.createNode(10);
    node *ptr4 = p.createNode(1);
    node *ptr5 = p.createNode(6);
    node *ptr6 = p.createNode(14);
    node *ptr7 = p.createNode(4);
    node *ptr8 = p.createNode(7);
    node *ptr9 = p.createNode(13);

    ptr1->connectNode(ptr2, ptr3);
    ptr2->connectNode(ptr4, ptr5);
    ptr3->connectNode(NULL, ptr6);
    ptr5->connectNode(ptr7, ptr8);
    ptr6->connectNode(ptr9, NULL);
    p.inOrder(ptr1);
    cout << endl;
    p.deletion(ptr1, 10);
    p.inOrder(ptr1);
}
// seekh: here in  line no 55
// seekh:if the base condtion returns any value and other stak frames are not returnning any value then in such case the value return by the actual function call will be the value returned by the base call 