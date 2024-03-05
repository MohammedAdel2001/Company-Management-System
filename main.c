#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char day[3];
    char month[3];
    char year[5];
} date;

typedef struct
{
    char id[10];
    char last[20];
    char first[20];
    char salary[10];
    date birthdate;
    char phone[12];
    char address[50];
    char email[50];

} Employee;
Employee emp[100];
char id[10],ln[20],fn[20],s[10],day[3],mo[3],year[5],p[12],a[50],email[50];
int end;

void printemp(Employee e)
{
    printf("\nThe id of employee is %s\n",e.id);
    printf("The last name of employee is %s\n",e.last);
    printf("The first name of employee is %s\n",e.first);
    printf("The salary of employee is %s\n",e.salary);
    printf("The birthdate of employee is %s/%s/%s\n",e.birthdate.day,e.birthdate.month,e.birthdate.year);
    printf("The phone of employee is %s\n",e.phone);
    printf("The address of employee is %s\n",e.address);
    printf("The email of employee is %s\n",e.email);
}

void loadfile()
{
    int n=0,i;
    FILE* cmpny;
    cmpny = fopen("Company.txt","r");
    if (cmpny!=NULL)
    {
        char employee[200], *check;
        i = 0;
        while(!feof(cmpny))
        {
            check = fgets(employee,200,cmpny);
            if(!check)
                break;

            n++;
            strcpy(emp[i].id, strtok(employee,",-"));
            strcpy(emp[i].last, strtok(NULL,",-"));
            strcpy(emp[i].first, strtok(NULL,",-"));
            strcpy(emp[i].salary, strtok(NULL,",-"));
            strcpy(emp[i].birthdate.day, strtok(NULL,",-"));
            strcpy(emp[i].birthdate.month, strtok(NULL,",-"));
            strcpy(emp[i].birthdate.year, strtok(NULL,",-"));
            strcpy(emp[i].address, strtok(NULL,",-"));
            strcpy(emp[i].phone, strtok(NULL,",-"));
            strcpy(emp[i].email, strtok(NULL,",-"));
            printemp(emp[i]);
            i++;
        }

    }
    else
    {
        printf("FILE NOT FOUND");
        exit(-1);
    }
    fclose(cmpny);
    end=n;
}

void search ()
{
    char str[20];
    int i,temp=0;
    printf("enter last name of the employee you want to search for:  ");
    scanf("%s",str);
    for(i=0; i<end; i++)
    {
        if(strcasecmp(emp[i].last,str)==0)
        {
            temp=1;
            printemp(emp[i]);

        }
    }
    if(temp==0)
        printf("Employee doesn't exist!");
}

int validateID(char *id)
{
    int i,n;
    n=strlen(id);
    for(i=0;i<n;i++)
    {
        if((id[i]>='A'&& id[i]<='Z') || (id[i]>='a'&& id[i]<='z'))
        {
            printf("ENTER A VALID ID: ");
            return 0;
        }
    }
    return 1;
}
int validatePHN(char *phone)
{
    int i,n;
    n=strlen(phone);
    for(i=0;i<n;i++)
    {
        if((phone[i]>='A'&& phone[i]<='Z') || (phone[i]>='a'&& phone[i]<='z'))
        {
            printf("ENTER A VALID PHONE NUMBER: ");
            return 0;
        }
    }
    return 1;
}

int validateEMAIL (char *email)
{
    int i,a,point=0,n,cnt=0;
    a=1;
    n=strlen(email);
    for(i=0;i<n;i++)
    {
        if(email[i]=='@')
            {a=i; cnt++;}
        if(strstr(email,".com"))
            point=1;
    }
    if(cnt>1 || point!=1 || a==1 )
        {
            printf("ENTER A VALID EMAIL: ");
            return 0;
        }

}
void add()
{

    int i=end;
    printf("the id of employee is: ");
    do
    {
        scanf("%s",emp[i].id);
    }
    while(!validateID(emp[i].id));
    printf("the last name of employee is: ");
    scanf("%s",emp[i].last);
    printf("the first name of employee is: ");
    scanf("%s",emp[i].first);
    printf("the salary of employee is: ");
    scanf("%s",emp[i].salary);
    printf("the birth day of employee is: ");
    scanf("%s",emp[i].birthdate.day);
    printf("the birth month of employee is: ");
    scanf("%s",emp[i].birthdate.month);
    printf("the birth year of employee is: ");
    scanf("%s",emp[i].birthdate.year);
    printf("the phone of employee is: ");
    do
    {
        scanf("%s",emp[i].phone);
    }
    while(!validatePHN(emp[i].phone));
    printf("the address of employee is: ");
    getchar();
    gets(emp[i].address);
    printf("the email of employee is: ");
    do
        {
             scanf("%s",emp[i].email);
        }
    while(!validateEMAIL(emp[i].email));
    printf("\nTHE EMPLOYEE WAS SUCCESSFULLY ADDED\n");
    end++;
    printf("\nTHE LIST OF EMPLOYEES\n");
        for(i=0; i<end; i++)
        {
        printemp(emp[i]);

        }

}
void deleteemp()
{
    int i,temp=0,k;
    char last[20],first[20];
    printf("Enter last name of employee to be deleted: ");
    scanf("%s",last);
    printf("Enter first name of employee to be deleted: ");
    scanf("%s",first);
    for(i=0;i<end;i++)
    {
        if(strcasecmp(emp[i].last,last)==0 && strcasecmp(emp[i].first,first)==0)
        {
            for(k=i;k<end;k++)
            {
                temp=1;
                emp[k]=emp[k+1];
                end--;
            }
        }
    }
    if(temp==0)
        printf("Employee doesn't exist");

    printf("THE LIST OF EMPLOYEES\n");
        for(i=0; i<end; i++)
        {
        printemp(emp[i]);

        }


}
void modemp(Employee e)
{
    printf("the modified id of employee is: ");
    do
    {
        scanf("%s",id);
    }
    while(!validateID(id));
    strcpy(e.id,id);
    printf("the modified last name of employee is: ");
    scanf("%s",ln);
    strcpy(e.last,ln);
    printf("the modified first name of employee is: ");
    scanf("%s",fn);
    strcpy(e.first,fn);
    printf("the modified salary of employee is: ");
    scanf("%s",s);
    strcpy(e.salary,s);
    printf("the modified birth day of employee is: ");
    scanf("%s",day);
    strcpy(e.birthdate.day,day);
    printf("the modified birth month of employee is: ");
    scanf("%s",mo);
    strcpy(e.birthdate.month,mo);
    printf("the modified birth year of employee is: ");
    scanf("%s",year);
    strcpy(e.birthdate.year,year);
    printf("the modified phone of employee is: ");
    do
    {
        scanf("%s",p);
    }
    while(!validatePHN(p));
    strcpy(e.phone,p);
    printf("the modified address of employee is: ");
    getchar();
    gets(a);
    strcpy(e.address,a);
    printf("the modified email of employee is: ");
    do
    {
        scanf("%s",email);
    }
    while(!validateEMAIL(email));
    strcpy(e.email,email);
}
void mod()
{
    int i,flag=0;
    char arr[10];
    printf("Enter the id to modify: ");
    scanf("%s",arr);
    for(i=0;i<end;i++)
    {
        if(strcmp(emp[i].id,arr)==0)
        {flag=1; break;}

    }

    if(flag==0)
        printf("Employee doesn't exist");
    else
    {
        printf("employee found enter the modified information:\n");
        modemp(emp[i]);
    }
    printf("THE LIST OF EMPLOYEES\n");
        for(i=0; i<end; i++)
        {
        printemp(emp[i]);

        }
}
void sortbyln(int n)
{
    Employee e1[100];
    int i,pass,sorted=0;
    for(pass=1; pass<n && !sorted; pass++)
    {
        sorted=1;
        for(i=0; i<(n-pass); i++)
        {
            if(strcmp(emp[i].last,emp[i+1].last)==1)
            {
                *e1=emp[i];
                emp[i]=emp[i+1];
                emp[i+1]=*e1;
                sorted=0;
            }
        }
    }
    printf("THE LIST OF EMPLOYEES AFTER SORTING: \n");
        for(i=0; i<end; i++)
        {
        printemp(emp[i]);

        }
}
void sortbysalary(int n)
{
    printf("EMPLOYEES' SALARY IN ASCENDING ORDER: \n");
    Employee e1[100];
    long s[100];
    long swap;
    int i,pass,sorted=0;
    for(i=0; i<n; i++)
    {
        s[i]=atoi(emp[i].salary);

    }

    for(pass=1; pass<n-1 && !sorted; pass++)
    {
        sorted=1;
        for(i=0; i<n-pass; i++)
        {
            if(s[i]>s[i+1])
            {
                swap=s[i];
                s[i]=s[i+1];
                s[i+1]=swap;
                *e1=emp[i];
                emp[i]=emp[i+1];
                emp[i+1]=*e1;
                sorted=0;
            }
        }
    }
    printf("THE LIST OF EMPLOYEES AFTER SORTING: \n");
        for(i=0; i<end; i++)
        {
        printemp(emp[i]);

        }
}

void sortbydate(int n)
{
    Employee e1[100];
    int y[100];
    int m[100];
    int d[100];
    int swap;
    int i,pass,sorted=0;
    for(i=0; i<n; i++)
    {
        y[i]=atoi(emp[i].birthdate.year);
        m[i]=atoi(emp[i].birthdate.month);
        d[i]=atoi(emp[i].birthdate.day);
    }


    for(pass=1; pass<n && !sorted; pass++)
    {
        sorted=1;
        for(i=0; i<n-pass; i++)
        {
            if(y[i]>y[i+1])
            {
                swap=y[i];
                y[i]=y[i+1];
                y[i+1]=swap;
                *e1=emp[i];
                emp[i]=emp[i+1];
                emp[i+1]=*e1;
                sorted=0;
            }
            if (y[i]==y[i+1])
            {
                if(m[i]>m[i+1])
                {
                    swap=m[i];
                    m[i]=m[i+1];
                    m[i+1]=swap;
                    *e1=emp[i];
                    emp[i]=emp[i+1];
                    emp[i+1]=*e1;
                    sorted=0;
                }
                if(m[i]==m[i+1])
                {
                    if(d[i]>d[i+1])
                    {
                        swap=d[i];
                        d[i]=d[i+1];
                        d[i+1]=swap;
                        *e1=emp[i];
                        emp[i]=emp[i+1];
                        emp[i+1]=*e1;
                        sorted=0;
                    }
                }
            }
        }
    }
   printf("THE LIST OF EMPLOYEES AFTER SORTING: \n");
        for(i=0; i<end; i++)
        {
        printemp(emp[i]);

        }
}
void sort()
{
    int n=end;
    int x;
    printf("\nchoose\n1)Sort by last name\n2)Sort by date of birth\n3)Sort by salary\n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
            sortbyln(n);
            break;
        case 2:
            sortbydate(n);
            break;
        case 3:
            sortbysalary(n);
            break;

    }

}
void savefile()
{
    int n,i;
    FILE* cmpny;
    cmpny = fopen("Company.txt","w");
    if (cmpny!=NULL)
    {

        char format[200];
        for(i=0;i<end;i++)
        {
            sprintf(format, "%s,%s,%s,%s,%s-%s-%s,%s,%s,%s", emp[i].id,emp[i].last,emp[i].first,emp[i].salary,
                    emp[i].birthdate.day,emp[i].birthdate.month,emp[i].birthdate.year,emp[i].address,emp[i].phone,emp[i].email);

            if(format[strlen(format) - 1] == '\n') {
                format[strlen(format) - 1] = '\0';
            }

            fprintf(cmpny, "%s\n", format);
        }


    }
    else
    {
        printf("FILE NOT FOUND");
        exit(-1);
    }
    fclose(cmpny);
    printf("DATA SAVED TO THE FILE SUCCESSFULLY!!");
}

void quit()
{
    int x;
    printf("Do you want to save before quitting?\n Enter 1)YES 2)NO");
    scanf("%d",&x);
    if(x==2)
    {
        printf("WARNING! NEW DATA MIGHT NOT BE SAVED!!");
        exit(0);
    }
    else
    {
        savefile();
        exit(0);
    }
}


int main()
{
    printf("LOADING ALL EMPLOYEES: \n");
    loadfile();
    int x,i;
    printf("Choose the command:\n");
    for(i=0; i<100; i++)
    {
        printf("\n1)SEARCH\n2)ADD\n3)DELETE\n4)MODIFY\n5)SORT\n6)SAVE\n7)QUIT\n");
        scanf("%d",&x);
        switch(x)
        {
            case 1:
                search();
                break;
            case 2:
                add();
                break;
            case 3:
                deleteemp();
                break;
            case 4:
                mod();
                break;
            case 5:
                sort();
                break;
            case 6:
                savefile();
                break;
            case 7:
                quit();
                break;

        }
    }

    return 0;
}
