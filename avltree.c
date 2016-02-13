/*
A program to implement AVL tree
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct node
{
    struct node * parent ; //works fine
    struct node * lchild ;
    struct node * rchild ;
    int lheight ;
    int rheight ;
    int data ;
}*root=NULL;

void insert(struct node * , struct node *);
void display(struct node *);
void buildtreebyarray();
int max(int,int);

void main()
{
    buildtreebyarray();
    display(root);
    printf("\n");
    printf("\n");
}


void buildtreebyarray()
{
    int i;

    //sample inputs , change limit value in for loop accordingly
    int a[] = {14,15,4,9,7,18,3,5,16,20,17};
    /*int a[] = {1,2,3,4,5,6,7};*/
    printf("The input is:\n");
    for(i=0;i<11;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<11;i++)
    {
        struct node * new_node ;
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = a[i];
        new_node->lheight = 0;
        new_node->rheight = 0;
        if(root==NULL)
        {
            root = new_node ;
            root->parent = NULL;
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
void insert(struct node * new_node,struct node *current)
{
    //checks if the current node is the leaf node.
    if(new_node->data > current->data && current->rchild!=NULL)
    {
        //current->rheight++;
        insert(new_node , current->rchild );
        current->rheight = max(current->rchild->lheight,current->rchild->rheight);
        current->rheight++; //it worked , YAY!
        /*if(current->lchild!=NULL && current->rchild!=NULL)
            current->rheight--;*/
        return ;
    }
    else if(new_node->data < current->data && current->lchild!=NULL)
    {
        //current->lheight++;
        insert(new_node , current->lchild );
        current->lheight = max(current->lchild->lheight,current->lchild->rheight);
        current->lheight++; //it worked , YAY!
        /*if(current->lchild!=NULL && current->rchild!=NULL)
            current->lheight--;*/
        return ;
    }

    //current node is the leaf node who is the correct parent for the new node.

    //checks if the new node should be the left child of the current node.
    if(new_node->data > current->data)
    {
        current->rchild = new_node ;
        new_node->parent = current ;
        current->rheight++;
        printf("%d is right child of %d\n",new_node->data,new_node->parent->data);
        return;
    }
    //or is it the right child.
    else if(new_node->data < current->data)
    {
        current->lchild = new_node ;
        new_node->parent = current ;
        current->lheight++;
        printf("%d is the left child of %d\n",new_node->data,new_node->parent->data);
        return ;
    }
    //so, this is a duplicate entry!
    else
    {
        printf("%d is duplicate entry\n",new_node->data);
        return ;
    }

}

void display(struct node * current)
{
    if(current==NULL)
    {
        return;
    }
    else
    {
        printf("\n***%d node left height is %d and right height is %d***\n",current->data,current->lheight,current->rheight);
        display(current->lchild);
        display(current->rchild);
    }
}

int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

/*sample input 1,2,3,4,5,6,7 */
