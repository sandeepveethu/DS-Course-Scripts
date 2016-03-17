/*
This program initialises a tree data structre such that left child's data is smaller
than parent's data and right child's data is larger  than parent's data.
This program checks for data duplicacy and recard duplicate entries.
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct tree_node
{
    struct tree_node * lchild ;
    struct tree_node * rchild ;
    int data ;
}node;

node *root=NULL;
void insert( node * ,  node *);
void display( node *);
void buildtree1by1();
void buildtreebyarray();
void main()
{
    buildtreebyarray();
    //buildtree1by1();
    display(root);
    printf("\n");
    printf("\n");
}

void buildtree1by1()
{
    int i;
    do
    {
         node * new_node ;
        new_node = ( node *)malloc(sizeof( node));
        printf("Add the value : ");
        scanf("%d",&(new_node->data));
        if(root==NULL)
        {
            root = new_node ;
            root->lchild = NULL;
            root->rchild = NULL;
        }
        else
        {
            insert(new_node,root);
        }
        printf("want to add more [1/0] ");
        scanf("%d",&i);
    }while(i);
}

void buildtreebyarray()
{
    int i;
    int a[] = {14,15,4,9,7,18,3,5,16,4,20,17,9,14,5,1,0,21};
    printf("The input is:\n");
    for(i=0;i<18;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<18;i++)
    {
         node * new_node ;
        new_node = ( node *)malloc(sizeof( node));
        new_node->data = a[i];
        if(root==NULL)
        {
            root = new_node ;
            root->lchild = NULL;
            root->rchild = NULL;
            printf("%d is the root data\n",root->data);
        }
        else
        {
            insert(new_node,root);
        }
    }
}
void insert( node * new_node, node *current)
{
    //checks if the current node is the lead node.
    if(new_node->data > current->data && current->rchild!=NULL)
    {
        insert(new_node , current->rchild );
        return ;
    }
    else if(new_node->data < current->data && current->lchild!=NULL)
    {
        insert(new_node , current->lchild );
        return ;
    }

    //current node is the leaf node who is the correct parent for the new node.

    //checks if the new node should be the left child of the current node.
    if(new_node->data > current->data)
    {
        printf("%d is right child of %d\n",new_node->data,current->data);
        current->rchild = new_node ;
        return;
    }
    //or is it the right child.
    else if(new_node->data < current->data)
    {
        printf("%d is the left child of %d\n",new_node->data,current->data);
        current->lchild = new_node ;
        return ;
    }
    //so, this is a duplicate entry!
    else
    {
        printf("%d is duplicate entry\n",new_node->data);
        return ;
    }

}

//a preorder traversal
void display( node * current)
{
    if(current==NULL)
    {
        return;
    }
    else
    {
        printf("%d ",current->data);
        display(current->lchild);
        display(current->rchild);
    }
}


/*sample  input 14 15 4 9 7 18 3 5 16 4 20 17 9 14 5 */
