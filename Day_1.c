#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;

} Node;

Node *creathead()
{
    Node *head=malloc(sizeof(Node));
    head->next=NULL;
    return head;
}

Node *creatnode(int data)
{
    Node *newnode=malloc(sizeof(Node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

Node *Insertnode(Node *head,Node *newnode)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;
}

void free_linklist(Node *head)
{
    Node *temp;
    while(head!=NULL)
    {
        temp=head;
        head=head->next;
        free(temp);
    }
}
   

int main()
{
    int n;
    
    Node *head = creathead();

    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        int data;
        printf("Enter the data for node %d: ", i + 1);
        scanf("%d", &data);
        Node *newnode = creatnode(data);
        head = Insertnode(head, newnode);
    }
    printf("The linked list is: ");
    Node *p = head->next;
    for (int j = 0; j < n; j++)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");

    free_linklist(head);

    return 0;
}