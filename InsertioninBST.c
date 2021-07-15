#include <stdio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // Setting the data
    n->left = NULL;                                 // Setting the left and right children to NULL
    n->right = NULL;                                // Setting the left and right children to NULL
    return n;                                       // Finally returning the created node
}
void inorder(struct node*root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

struct node*insert(struct node*root,int key){
    if (root==NULL)
    {
        return createNode(key);
    }
    if(key<root->data){
        root->left=insert(root->left,key);
    }
    else if (key>root->data){
        root->right=insert(root->right,key);
    }
    return root;
    
}

int main()
{

    // Constructing the root node - Using Function (Recommended)
    struct node *p = NULL;
    p = insert(p,50);
    insert(p,30);
    insert(p,20);
    insert(p,40);
    insert(p,70);
    insert(p,90);
    insert(p,80);

    inorder(p);

   
   
    return 0;
}