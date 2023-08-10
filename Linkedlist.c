#include <stdio.h>

struct employee
{
    char name[20];
    int id;
    float salary;
    struct employee *nextemp;
};

struct employee *emp;
struct employee *emptemp1;
struct employee *emptemp2;
struct employee *firstemp;
struct employee *lastemp;

int main()
{
    int choice, a=1;
    int empid;

    emp = NULL;
    firstemp = NULL;
    lastemp = NULL;

    while(a==1)
    {
        printf("MENU\n");
        printf("1. Enter Employee Details at end \n");
        printf("2. Enter Employee Details at start \n");
        printf("3. Enter Employee Details after \n");
        printf("4. Enter Employee Details before \n");
        printf("5. Search Employee by its id \n");
        printf("6. View Employee Details \n");
        printf("7. Delete Employee Details \n");
        printf("0. Exit \n");

        printf("Enter a choice : ");
        scanf("%d", &choice);

        system("cls");

        switch(choice)
        {
            case 1:
            enter_at_end();
            break;

            case 2:
            enter_at_start();
            break;

            case 3:
            printf("Enter the id after which you want to enter your details : ");
            scanf("%d", &empid);
            enter_after(empid);
            break;

            case 4:
            printf("Enter the id before which you want to enter your details : ");
            scanf("%d", &empid);
            enter_before(empid);
            break;

            case 5:
            printf("Enter the id you want to search : ");
            scanf("%d", &empid);
            search(empid);
            break;

            case 6:
            view_details();
            break;

            case 7:
            printf("Enter the id you want to delete : ");
            scanf("%d", &empid);
            delete_emp(empid);
            break;

            case 0:
            a=0;
            break;
        }
    }
}

void enter_at_end()
{
    emp = (struct employee*) malloc(sizeof(struct employee));

    printf("Enter name : ");
    scanf("%s", &emp->name);

    printf("Enter id : ");
    scanf("%d", &emp->id);

    printf("Enter salary : ");
    scanf("%f", &emp->salary);

    emp->nextemp = NULL;

    if (firstemp == NULL)
    {
        firstemp = emp;
        lastemp = emp;
    }
    else
    {
        lastemp->nextemp = emp;
        lastemp = emp;
    }
}

void enter_at_start()
{
    emp = (struct employee*) malloc(sizeof(struct employee));

    printf("Enter name : ");
    scanf("%s", &emp->name);

    printf("Enter id : ");
    scanf("%d", &emp->id);

    printf("Enter salary : ");
    scanf("%f", &emp->salary);

    emp->nextemp = firstemp;
    firstemp = emp;

}

void enter_after(int idemp)
{
    int temp = 1;
    emptemp1 = firstemp;

    if (emp == NULL)
    {
        printf("List empty \n");
        return;
    }

    while(temp == 1)
    {
        if(emptemp1->id == idemp)
        {
            emptemp2 = emptemp1->nextemp;
            emp = (struct employee*) malloc(sizeof(struct employee));

            printf("Enter name : ");
            scanf("%s", &emp->name);

            printf("Enter id : ");
            scanf("%d", &emp->id);

            printf("Enter salary : ");
            scanf("%f", &emp->salary);

            emptemp1->nextemp = emp;
            emp->nextemp = emptemp2;
            temp = 0;
        }
        else
        {
            emptemp1 = emptemp1->nextemp;
            if(emptemp1 == NULL){
                printf("No such element exists\n");
                return;
            }
        }
    }
}

void enter_before(int idemp)
{
    int temp = 1;
    emptemp1 = firstemp;
    emptemp2 = firstemp->nextemp;

    if (emp == NULL)
    {
        printf("List empty \n");
        return;
    }

    while(temp == 1)
    {
        if(emptemp2->id == idemp)
        {
            emp = (struct employee*) malloc(sizeof(struct employee));

            printf("Enter name : ");
            scanf("%s", &emp->name);

            printf("Enter id : ");
            scanf("%d", &emp->id);

            printf("Enter salary : ");
            scanf("%f", &emp->salary);

            emptemp1->nextemp = emp;
            emp->nextemp = emptemp2;

            temp = 0;
        }
        else
        {
            emptemp1 = emptemp2;
            emptemp2 = emptemp2->nextemp;
            if(emptemp2 == NULL){
                printf("No such element exists\n");
                return;
            }
        }
    }
}

void search(int idemp)
{
    int temp = 1;
    emp = firstemp;
    if (emp == NULL)
    {
        printf("List empty \n");
        return;
    }

    while(temp == 1)
    {
        if(emp->id == idemp)
        {
            printf("Name : %s\n", emp->name);
            printf("Id : %d\n", emp->id);
            printf("Salary: %f\n", emp->salary);
            temp = 0;
        }
        else
        {
            if(emp->nextemp == NULL)
            {
                printf("No such entry exist in the database \n");
                break;
            }
        }
    }
}

void view_details()
{
    if (firstemp == NULL)
    {
        printf("No Employee added to the list\n");
    }
    else
    {
        emp = firstemp;

        while(emp->nextemp != NULL)
        {
            printf("--------------------------------------------\n");
            printf("Name : %s\n", emp->name);
            printf("Id : %d\n", emp->id);
            printf("Salary: %f\n", emp->salary);

            emp = emp->nextemp;
        }
        printf("--------------------------------------------\n");
        printf("Name : %s\n", emp->name);
        printf("Id : %d\n", emp->id);
        printf("Salary: %f\n", emp->salary);
    }
    getchar();
    getchar();
}

void delete_emp(int idemp)
{
    int temp = 1;
    emp = firstemp;

    if (emp == NULL)
    {
        printf("List empty \n");
        return;
    }

    emptemp1 = firstemp;

    while(temp == 1)
    {
        if(emp->id == idemp)
        {
            if (emp == firstemp)
            {
                if (emp->nextemp == NULL)
                {
                    firstemp = NULL;
                    free(emp);
                    break;
                }
                else
                {
                    firstemp = emp->nextemp;
                    free(emp);
                    break;
                }
            }

            else if (emp == lastemp)
            {
                emptemp1->nextemp = NULL;
                free(emp);
                break;
            }

            else
            {
                emptemp1->nextemp = emp->nextemp;
                free(emp);
                break;
            }
        }
        else
        {
            emptemp1 = emp;
            if (emp->nextemp != NULL)
            {
                emp = emp->nextemp;
            }
            else
            {
                printf("No such entry exist in the database \n");
                break;
            }
        }
    }
}
