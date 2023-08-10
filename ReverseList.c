#include <stdio.h>

struct node
{
    int data;
    struct node *next;
};

struct node *ptr1;
struct node *head;
struct node *last;
struct node *tmp1;
struct node *tmp2;

int main()
{
    ptr1 = NULL;
    head = NULL;
    last = NULL;

    int a=1, choice;

    while(1)
    {
        printf("Enter 1 to enter data and 0 to end \n");
        scanf("%d", &choice);
        if(choice == 1)
        {

            ptr1 = (struct node*)malloc(sizeof(struct node));
            printf("Enter data : ");
            scanf("%d", &ptr1->data);

            ptr1->next=NULL;

            if(head == NULL)
            {
                head = ptr1;
                last = ptr1;
            }
            else
            {
                last->next = ptr1;
                last = ptr1;
            }
        }
        else
        {
            break;
        }
    }

    printf("Linked List : \n");

    if(head == NULL)
    {
        printf("No data is found\n");
    }
    else{
        ptr1 = head;

        while(ptr1 != NULL){
            printf("%d\n", ptr1->data);
            ptr1 = ptr1->next;
        }
    }

    printf("Reversed Linked List : \n");

    ptr1 = head;
    tmp1 = head->next;
    tmp2 = head->next->next;

    head->next = NULL;

    while(tmp2 != last)
    {
        tmp1->next = ptr1;
        ptr1 = tmp1;
        tmp1 = tmp2;
        tmp2 = tmp2->next;
    }
    tmp1->next = ptr1;
    tmp2->next = tmp1;

    ptr1 = last;
    while(ptr1 != NULL)
    {
        printf("%d\n", ptr1->data);
        ptr1 = ptr1->next;
    }
}


