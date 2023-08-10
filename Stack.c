#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;
struct node *ptr;

int main(){

    int choice, a=1;

    ptr = NULL;
    head = NULL;

    while(a==1)
    {
        printf("MENU\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("0. Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 0:
                a=0;
                break;

        }
    }

}

void push()
{
    ptr = (struct node*)malloc(sizeof(struct node));

    printf("Enter the number : ");
    scanf("%d", &ptr->data);

    if(head == NULL)
    {
        head = ptr;
        head->next = NULL;
        printf("%d pushed\n", head->data);
    }
    else
    {
        ptr->next = head;
        head = ptr;
        printf("%d pushed\n", head->data);
    }
}

void pop()
{
    if(head == NULL)
    {
        printf("No element to pop\n");
        ptr = NULL;
    }
    else if(head->next == NULL)
    {
        printf("%d popped \n", head->data);
        free(head);
        head = NULL;
        ptr = NULL;
    }
    else
    {
        printf("%d popped \n", head->data);
        ptr = head->next;
        free(head);
        head = ptr;
    }
}
