#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *base;
struct node *head;
struct node *ptr;
struct node *temp;

int main(){

    int choice, a=1;

    ptr = NULL;
    head = NULL;
    base = NULL;

    while(a==1)
    {
        printf("MENU\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("0. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 0:
                a=0;
                break;

        }
    }

}

void enqueue()
{
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the number : ");
    scanf("%d", &ptr->data);

    if(head == NULL)
    {
        ptr->next = NULL;
        head = ptr;
        base = ptr;
        printf("%d enqueued\n", head->data);
    }
    else
    {
        ptr->next = NULL;
        base->next = ptr;
        base = ptr;
        printf("%d enqueued\n", base->data);
    }
}

void dequeue()
{
    if(base == NULL)
    {
        printf("no element to dequeue\n");
    }
    else if(head == base)
    {
        printf("%d dequeued\n", head->data);
        free(head);
        head = NULL;
        ptr = NULL;
        base = NULL;
    }
    else
    {
        printf("%d dequeued\n", head->data);
        ptr = head->next;
        free(head);
        head=ptr;
    }
}
