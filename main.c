/*Name: Lam Vo Ngoc Dung
 *ID: CE140405
 *Class: PRF192 - IA1401
 *Program: that allows user:
Adding a new employee
Find data about employees using a name inputted.
Remove an employee based on a code inputted
Print the list in descending order based on salary + allowance.
 *Date: 16/8/2019
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxN 50
void menu(char names[][21], char codes[][9], double salaries[], double allowances[])
{
    char name[maxN];
    char code[maxN];
    int n=0;
    int num = 1;
    do
    {
        int opt;
        printf("\nChoose one option below:\n");
        printf("1. Adding a new employee\n2. Find data about employees using name inputted\n3. Remove an employee based on a code inputted\n4. Print the list in descending order based on salary + allowance\n5. Other option\n");
        printf("Enter option: ");
        scanf("%d",&opt);

        switch(opt)
        {
        case 1:
            add(names,codes,salaries,allowances,&n);
            break;

        case 2:
            printf("\nInput a name you want to find: ");
            fflush(stdin);
            scanf("%30[^\n]",name);
            printBasedName(name,codes,names,salaries,allowances,n);
            break;

        case 3:
            printf("\nInput a code you want to delete: ");
            fflush(stdin);
            scanf("%30[^\n]",code);
            removePos(code,codes,names,salaries,allowances,&n);
            break;

        case 4:
            sortprint(names,codes,salaries,allowances,n);
            break;

        case 5:
            printf("Do you want to continue?\n");
            printf("1. YES\t\t2. NO\n");
            scanf("%d",&num);

        }
    }
    while(num==1);

}

void add(char names[][21], char codes[][9], double salaries[], double allowances[], int *pn)
{


    printf("\nName of employee: ");
    getchar();
    scanf("%30[^\n]",names[*pn]);


    printf("Code of employee: ");
    getchar();
    scanf("%30[^\n]",codes[*pn]);

    printf("Salary of employee: ");
    scanf("%lf",&salaries[*pn]);

    printf("Allowance of employee: ");
    scanf("%lf",&allowances[*pn]);

    *pn=*pn+1;
}

void printBasedName(char name[], char codes[][9],char names[][21], double salaries[], double allowances[], int n)
{
    int data=0;
    int count=0;
    for(int i=0; i<n; i++)
    {
        if(strcmp(name,names[i])!=0)
        {
            count=count+1;
            if(count==n)
            {
                printf("NO NAME FOUND! PLEASE TRY AGAIN!");
            }
        }
        else
        {
            if(data==0)
            {
                printf("\nName: %s\t\tCode: %s\t\tSalaries: %.3lf\t\tAllowances: %.3lf\n", names[i], codes[i], salaries[i], allowances[i]);
                data=1;
            }
        }
    }
}

void removePos(char code[], char codes[][9],char names[][21], double salaries[], double allowances[], int *pn)
{
    int data=0;
    int count=0;
    for(int i=0; i<(*pn); i++)
    {
        if(strcmp(code,codes[i])!=0)
        {
            count=count+1;
            if(count==(*pn)){
                printf("INVALID CODE! PLEASE TRY AGAIN!");
            }
        }
        else
        {
            if(data==0){
            strcpy(codes[i],codes[i+1]);
            codes[i+1][0]='\0';
            strcpy(names[i],names[i+1]);
            names[i+1][0]='\0';
            salaries[i]=salaries[i+1];
            salaries[i+1]='\0';
            allowances[i]=allowances[i+1];
            allowances[i+1]='\0';
            *pn=*pn-1;
            printf("Deleted! Please choose the print option to see the list after deleting!\n");
            data=1;
            }
        }
    }
}


void sortprint(char names[][21], char codes[][9], double salaries[], double allowances[], int n)
{
    int max_sal=0;
    int max_all=0;
    char max_names[maxN][21];
    char max_codes[maxN][9];
    printf("\nList of employee:\n");
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if((salaries[i]+allowances[i])<(salaries[j]+allowances[j]))
            {
                max_sal=salaries[i];
                salaries[i]=salaries[j];
                salaries[j]=max_sal;
                max_all=allowances[i];
                allowances[i]=allowances[j];
                allowances[j]=max_all;
                strcpy(max_names[i],names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],max_names[i]);
                strcpy(max_codes[i],codes[i]);
                strcpy(codes[i],codes[j]);
                strcpy(codes[j],max_codes[i]);
            }
        }
        printf("\nName: %s\t\tCode: %s\t\tSalaries: %.3lf\t\tAllowances: %.3lf\n", names[i], codes[i], salaries[i], allowances[i]);
    }
}

int main()
{
    printf("Welcome to employee management program!\n");
    char names[maxN][21];
    char codes[maxN][9];
    double salaries[maxN];
    double allowances[maxN];
    char name[21];
    char code[9];

    menu(names,codes,salaries,allowances);

    return 0;
}
