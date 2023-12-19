#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *left = NULL;
    node *right = NULL;

    node *createNode(int data)
    {
        node *first = (node *)new (node)();
        first->data = data;
        return first;
    }

    void connector(node *l, node *r)
    {
        left = l;
        right = r;
    }

    void PreorderTraversal(node *root)
    {
        if (root != NULL)
        { // condition to break the recursion
            cout << root->data << "\t";
            PreorderTraversal(root->left); // root-> is very imp since we need to look for the left and the right of the root node and not the left and right of the object calling the function i.e ptr(real root)
            PreorderTraversal(root->right);
        }
    }
    void PostorderTraversal(node *root)
    {
        // left->right->root
        if (root != NULL)
        {
            PostorderTraversal(root->left);
            PostorderTraversal(root->right);
            cout << root->data << "\t";
        }
    }

    void inorderTraversal(node *root)
    {
        // left->root->right
        if (root != NULL)
        {
            inorderTraversal(root->left);
            cout << root->data << "\t";
            inorderTraversal(root->right);
        }
    }
};

int main()
{
    node n;
    node *ptr = n.createNode(4); // root node data passed as argument
    node *ptr2 = n.createNode(1);
    node *ptr3 = n.createNode(6);
    ptr->connector(ptr2, ptr3); // ptr is parent and passed nodes are left and right child resp.
    node *ptr4 = n.createNode(5);
    node *ptr5 = n.createNode(2);
    ptr2->connector(ptr4, ptr5);
    ptr->PreorderTraversal(ptr);
    cout << endl;
    ptr->PostorderTraversal(ptr);
    cout<<endl;
    ptr->inorderTraversal(ptr);
    //         4
    //       /   \
    //      1     6
    //     / \
    //    5   2
}