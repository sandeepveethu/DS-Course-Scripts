/*
A program to implement AVL trees
Note-It ignores duplicate input entries
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
void r2l_rotation(struct node *);
void l2r_rotation(struct node *);
void make_it_avl(struct node *);
//void simpleshifting(struct node *);

void main()
{
    buildtreebyarray();
    display(root);
    //printf("root %d it's lchild %d it's rchild %d",root->data,root->lchild->data,root->rchild->data);
    //printf("%d lchild is %d and rchild is %d",root->rchild->data,root->rchild->lchild->data,root->rchild->rchild->data);
    printf("\n");
    printf("\n");
}


void buildtreebyarray()
{
    int i;

    //sample inputs , change limit value in for loop accordingly
    //int a[] = {14,15,4,9,7,18,3,5,16,20,17};
    //int a[] = {1,2,3,4,5,6,7};
    int a[] = {1,2,3,4,5,6,7};
    printf("The input is:\n");
    for(i=0;i<7;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    for(i=0;i<7;i++)
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
    //checks if the current node is the leaf node.
    if(new_node->data > current->data && current->rchild!=NULL)
    {
        insert(new_node , current->rchild );
        current->rheight = max(current->rchild->lheight,current->rchild->rheight);
        current->rheight++;//it worked , YAY!
        if((current->rheight - current->lheight)>1)
        {
            printf("\nit occured for %d and left height is %d and right height is %d\n",current->data,current->lheight,current->rheight);
            make_it_avl(current); //keeping it clean here
        }
        return ;
    }
    else if(new_node->data < current->data && current->lchild!=NULL)
    {
        insert(new_node , current->lchild );
        current->lheight = max(current->lchild->lheight,current->lchild->rheight);
        current->lheight++; //it worked , YAY!
        if((current->rheight - current->lheight)>1 || (current->lheight - current->rheight)>1 )
        {
            r2l_rotation(current);
        }
        return ;
    }

    //current node is the leaf node who is the correct parent for the new node.

    //checks if the new node should be the left child of the current node.
    if(new_node->data > current->data)
    {
        current->rchild = new_node ;
        new_node->parent = current ;
        current->rheight++;
        //printf("%d is right child of %d\n",new_node->data,new_node->parent->data);
        return;
    }
    //or is it the right child.
    else if(new_node->data < current->data)
    {
        current->lchild = new_node ;
        new_node->parent = current ;
        current->lheight++;
        //printf("%d is the left child of %d\n",new_node->data,new_node->parent->data);
        return ;
    }
    //so, this is a duplicate entry!
    else
    {
        //printf("%d is duplicate entry\n",new_node->data);
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
        printf("\n***%d node lheight is %d and rheight is %d parent is ",current->data,current->lheight,current->rheight);
        if(current->parent!=NULL)
            printf("%d***\n",current->parent->data);
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


//it should be noted that rotation always occurs between root and its child.
void make_it_avl(struct node * k)
{
    if(k->rheight > k->lheight)
    {
        if(k==root)
        {
            r2l_rotation(k->rchild);
            return;
        }
        //XXX:check if k->rchild->lchild==NULL is required or not
        else if(k!=root && k->lchild==NULL)
        {
            simpleshifting(k);
            return;
        }
        else
        {
            r2l_rotation(k);
            return;
        }
    }
    else
    {
        if(k==root)
            l2r_rotation(k->lchild);
        return;
    }
}


void r2l_rotation(struct node * k2)
{
    struct node * k1 = root ;
    //int temp1 = max(k1->lheight,k2->lheight);

    //because subtree B is iniitially lchild of k2 and finally becomes
    //rchild of k1
    k1->rheight = k2->lheight;

    k1->rchild = k2->lchild ;
    k1->parent = k2 ;
    root = k2 ;

    //because finally lheight of k2 is node k1 + the max depth of subtree A or B
    k2->lheight = max(k1->lheight,k2->lheight)+1 ;

    k2->lchild = k1 ;
    k2->parent = NULL ;

}

void l2r_rotation(struct node * k1)
{
    return;
}

void simpleshifting(struct node * k)
{
    printf("here\n");
    //giving different pointer to the address of rchild of k , as it will now
    //become parent of k.
    struct node *k2 = k->rchild ;
    //storing address of parent of k , because it will now become parent of k2
    struct node *k3 = k->parent ;

    //making k leaf node whose parent is now it's earlier rchild
    k->lchild = NULL;
    k->rchild = NULL ;
    k->lheight = 0;
    k->rheight = 0;
    k->parent = k2 ;

    k2->lheight = 1;
    k2->parent = k3;
    k3->rchild = k2;
    k2->lchild = k ;
    printf("k is %d k2 is %d",k->data,k2->data);
    printf("k2 parent is %d rchild is %d",k2->parent->data,k2->rchild->data);

}
