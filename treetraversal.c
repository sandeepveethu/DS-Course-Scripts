/*
This program contains algorithms for 3 types of tree traversals
namely, inorder traversal, preorder traversal, postorder traversal
During tree building, duplicate values are not ignored
*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node * lchild ;
    struct node * rchild ;
    int data ;
}*root=NULL;

void buildtreebyarray();
void inordertraversal(struct node *);
void preordertraversal(struct node *);
void postordertraversal(struct node *);
void insert(struct node * , struct node *);
void main()
{
    buildtreebyarray();
    printf("Inorder Traversal:\n");
    inordertraversal(root);
    printf("\nPreorder Traversal:\n");
    preordertraversal(root);
    printf("\nPostorder Traversal:\n");
    postordertraversal(root);
    printf("\n");
}

void buildtreebyarray()
{
    int i;
    //Enter the tree input array here
    int a[] = {14,15,4,9,7,18,3,5,16,4,20,17,9,14,5};
    printf("The input is:\n");
    for(i=0;i<15;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<15;i++)
    {
        struct node * new_node ;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = a[i];
        if(root==NULL)
        {
            root = new_node ;
            root->lchild = NULL;
            root->rchild = NULL;
            //printf("%d is the root data\n",root->data);
        }
        else
        {
            insert(new_node,root);
        }
    }
}

void insert(struct node * new_node,struct node *current)
{
    //checks if the current node is the lead node.
    if(new_node->data > current->data && current->rchild!=NULL)
    {
        insert(new_node , current->rchild );
        return ;
    }
    else if(new_node->data <= current->data && current->lchild!=NULL)
    {
        insert(new_node , current->lchild );
        return ;
    }

    //current node is the leaf node who is the correct parent for the new node.

    //checks if the new node should be the left child of the current node.
    if(new_node->data > current->data)
    {
        //printf("%d is right child of %d\n",new_node->data,current->data);
        current->rchild = new_node ;
        return;
    }
    //or is it the right child.
    else if(new_node->data <= current->data)
    {
        //printf("%d is the left child of%d\n",new_node->data,current->data);
        current->lchild = new_node ;
        return ;
    }
}

void inordertraversal(struct node* current)
{
    if(current==NULL)
    {
        return;
    }
    else
    {
        inordertraversal(current->lchild);
        printf("%d ",current->data);
        inordertraversal(current->rchild);
    }
}

void preordertraversal(struct node * current)
{
    if(current==NULL)
        return;
    else
    {
        printf("%d ",current->data);
        preordertraversal(current->lchild);
        preordertraversal(current->rchild);
    }
}

void postordertraversal(struct node * current)
{
    if(current==NULL)
        return;
    else
    {
        preordertraversal(current->lchild);
        preordertraversal(current->rchild);
        printf("%d ",current->data);
    }
}
