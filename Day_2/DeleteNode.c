#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}node;

node *DeleteNode(node *head,int data)
{
    node *prev=head;

    while(prev->next!=NULL&&prev->next->data!=data)//找到删除的节点
    {
        prev=prev->next;
    }
    
    if(prev->next!=NULL)//删除目标节点
    {
        node *target=prev->next;
        prev->next=target->next;
        free(target);
    }
    return head;
}

int main ()
{
    return 0;
}