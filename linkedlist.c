
#include <stdio.h>
#include <stdlib.h>
void create();
void printlist();
struct node
{
    struct node * next ;
    int data ;
}*start=NULL;

void main()
{
    create();
    printlist();
}

void create()
{
    int ch ;
    do
    {
        struct node *new_node , *current ;
        new_node = (struct node *)malloc(sizeof(struct node));
        printf("enter the number : ");
        scanf("%d",&(new_node->data));
        if(start==NULL)
        {
            start = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
        printf("want to add more [1/0]");
        scanf("%d",&ch);
    }while(ch!=0);
}

void printlist()
{
    struct node * new_node ;
    new_node = start ;
    do
    {
        printf("%d-->",new_node->data);
        new_node = new_node->next;
    }while(new_node!=NULL);
    printf("NULL\n");
}
