#include <bits/stdc++.h>
using namespace std;
class node
{
    int data;
    node *left = NULL;
    node *right = NULL;
public:
    int v[9];
    int i=0;
    node *createNode(int data)
    {
        node *ptr = (node *)new node();
        ptr->data = data;
        return ptr;
    }

    void connector(node *left = NULL, node *right = NULL)
    {
        this->right = right;
        this->left = left;
    }
    void inOrderTraversal(node *root)
    {

        if (root != NULL)
        {
            inOrderTraversal(root->left);
            v[i]=root->data;
            i++;
            cout<<root->data<<"\t";
            inOrderTraversal(root->right);
        }
    }

    void BSTcheck()
    {
        int flag = 0;
        for (int i = 0; i < 8; i++)
        {
            if (v[i] < v[i + 1])
            {
            }
            else
                flag = 1;
        }
        if (flag == 0)
        {
            cout << "\ngiven Tree is a BST" << endl;
        }
        else
        {
            cout << "\nGiven Tree is not a BST" << endl;
        }
    }
};
int main()
{
    node n;
    node *ptr1 = n.createNode(9);
    node *ptr2 = n.createNode(4);
    node *ptr3 = n.createNode(11);
    node *ptr4 = n.createNode(2);
    node *ptr5 = n.createNode(7);
    node *ptr6 = n.createNode(19);
    node *ptr7 = n.createNode(5);
    node *ptr8 = n.createNode(8);
    node *ptr9 = n.createNode(14);

    ptr1->connector(ptr2, ptr3);
    ptr2->connector(ptr4, ptr5);
    ptr3->connector(NULL, ptr6);
    ptr5->connector(ptr7, ptr8);
    ptr6->connector(ptr9, NULL);
    n.inOrderTraversal(ptr1);
    n.BSTcheck();
}

