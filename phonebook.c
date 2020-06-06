#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

struct person
{
	char name[30];
	char address[50];
	char mble_no[15];
	char mail[50];
};
void create();
void erase();
void search();
void edit();
void about();

void main()
{
	system("cls");
	system("color 3f");
	printf("\t\t\t\t*******Welcome to Phonebook*******\n");
	printf("\t\t\t\tMENU:-\n");
	printf("\t\t\t\t1.CREATE\t\t2.EDIT\n\t\t\t\t3.SEARCH\t\t4.DELETE\n\t\t\t\t5.EXIT\t\t\t6.ABOUT\n\n");
	printf("\t\t\tEnter the Choice:-");
	switch(getch())
	{
		case '1':create();
				 break;
		case '2':edit();
				 break;
		case '3':search();
				 break;
		case '4':erase();
				 break;
		case '5':getch();
				exit(0);
		case '6':about();
				 break;
		default:system("cls");
				printf("Enter from given choice only:-");
				getch();
	}
	main();
}

void about()
{
	system("cls");
	system("color 3f");
	printf("About phonebook:-\n\n\n");
	printf("App provide basic facility of phonebook like:\n1.Creating a contact\n2.Modifying a saved contact");
	printf("\n3.Searching a saved contact\n4.Deleting a saved contact\n\n");
	printf("\nIf there is more than one contact of same name\n");
	printf("then in order to perform above operation a person\n");
	printf("must know the number of the person\n");
	printf("\nEnter any key:- ");
	getch();
    system("cls");
	main();
}

void create()
{
	system("cls");
    FILE *f;
    struct person p;
    f=fopen("project.txt","a+");
	printf("\nEnter name: ");
    gets(p.name);
    printf("\nEnter the address: ");
    gets(p.address);
    printf("\nEnter phone no.:");
	gets(p.mble_no);
    printf("\nEnter e-mail:");
    gets(p.mail);
	fwrite(&p,sizeof(p),1,f);
    fflush(stdin);
    printf("\nrecord saved");
	fclose(f);
	printf("\nEnter any key");
	getch();
	system("cls");
    main();
}

void search()
{
	int t=0;
	struct person p;
	FILE *f;
	char name[100];
	f=fopen("project.txt","r");
	if(f==NULL)
	{
    	printf("\nerror in opening\a");
    	getch();
    	main();
	}
	system("cls");
	printf("enter name or phone number of person to search:- ");
	gets(name);
	while(fread(&p,sizeof(p),1,f)==1)
	{
   		if(strcmp(p.name,name)==0)
    	{
   			printf("\n\tDetail Information About %s",name);
       		printf("\nName:%s\nAddress:%s\nMobile no:%15s\nE-mail:%s\n",p.name,p.address,p.mble_no,p.mail);
   			t++;
		}
   		else if(strcmp(p.mble_no,name)==0)
   		{
     		printf("\n\tDetail Information About %s",name);
        	printf("\nName:%s\nAddress:%s\nMobile no:%15s\nE-mail:%s\n",p.name,p.address,p.mble_no,p.mail);
    		t++;
		}
	}
	if(t==0)
	{
		printf("\ncontact not found");
	}	
	fclose(f);
	printf("\n\nEnter any key:- ");
	getch();
    system("cls");
	main();
}

void erase()
{
	system("cls");
	struct person p;
    FILE *f,*ft;
    f=fopen("project.txt","r+");
	if(f==NULL)
	{
		printf("\nCONTACT'S DATA NOT ADDED YET.");
	}
	while(feof(f)==0)
	{
		while(fread(&p,sizeof(p),1,f)==1)
		{
			printf("\nName:%s\nAddress:%s\nMobile no:%15s\nE-mail:%s\n",p.name,p.address,p.mble_no,p.mail);
		}
	}
	fclose(f);
	int flag;
	char name[100];
	f=fopen("project.txt","r+");
	if(f==NULL)
	{
		printf("\nCONTACT'S DATA NOT ADDED YET.");
	}
	else
	{
		ft=fopen("temp.txt","w+");
		if(ft==NULL)
			printf("file opening error");
		else
        {
			printf("\nEnter CONTACT'S NUMBER:- ");
			gets(name);
			fflush(stdin);
			while(fread(&p,sizeof(p),1,f)==1)
			{
				if(strcmp(p.mble_no,name)!=0)
					fwrite(&p,sizeof(p),1,ft);
				else if(strcmp(p.mble_no,name)==0)
                	flag=1;
			}
			fclose(f);
			fclose(ft);
			if(flag!=1)
			{
				printf("\nNO CONACT'S RECORD TO DELETE.");
				remove("temp.txt");
			}
			else
			{
				remove("project.txt");
				rename("temp.txt","project.txt");
				printf("\nRECORD DELETED SUCCESSFULLY.");
			}
		}
	}
	printf("\nEnter any key:- ");
	getch();
    system("cls");
	main();
}

void edit()
{
	system("cls");
	struct person cont,s;
    int flag=0,status=0;
    char name[30];
    fflush(stdin);
    printf("\nEnter name/number for modify-");
    gets(name);
    FILE *fp;
    fp=fopen("project.txt","r+");
    while(fread(&cont,sizeof(cont),1,fp)==1)
    {
        if(strcmp(cont.name,name)==0)
        {
            flag=1;
            system("CLS");
        	printf("\nName:%s\nAddress:%s\nMobile no:%15s\nE-mail:%s\n",cont.name,cont.address,cont.mble_no,cont.mail); 
            char choice[10];
			printf("\n\n -Please select option which you want to update-\n");
            printf("\n1.Name\n2.Address\n3.Mobile number\n4.Email");
            fflush(stdin);
            printf("\nEnter option- ");
            gets(choice);
            do 
			{
            	if(strcmp(choice,"1")==0)
            	{
                	status=1;
                	fflush(stdin);
                	printf("\nEnter Name:- ");
                	gets(s.name);
                	strcpy(s.address,cont.address);
                	strcpy(s.mble_no,cont.mble_no);
                	strcpy(s.mail,cont.mail);
            	}
            	else if(strcmp(choice,"2")==0)
            	{
            	    status=1;
            	    fflush(stdin);
            	    printf("\nEnter Address:- ");
            	    gets(s.address);
            	    strcpy(s.mble_no,cont.mble_no);
            	    strcpy(s.mail,cont.mail);
            	    strcpy(s.name,cont.name);
            	}
            	else if(strcmp(choice,"4")==0)
            	{
            	    status=1;
            	    fflush(stdin);
            	    printf("\nEnter e-mail:- ");
            	    gets(s.mail);
            	    strcpy(s.mble_no,cont.mble_no);
            	    strcpy(s.name,cont.name);
            	    strcpy(s.address,cont.address);
            	}
            	else if(strcmp(choice,"3")==0)
            	{
            	    status=1;
            	    fflush(stdin);
            	    printf("\nEnter Phone number:- ");
            	    gets(s.mble_no);
            	    strcpy(s.name,cont.name);
            	    strcpy(s.address,cont.address);
            	    strcpy(s.mail,cont.mail);
            	}
            	else
            	{
            	    fflush(stdin);
                	printf("\nPlease enter valid choice..");
                	printf("\nEnter option-");
            		gets(choice);
	            }
            }while(status!=1);
            if(status==1)
            {
                fseek(fp,-sizeof(cont),SEEK_CUR);
                fwrite(&s,sizeof(s),1,fp);
                break;
            }
        }
        else if(strcmp(cont.mble_no,name)==0)
        {
            flag=1;
            system("CLS");
        	printf("\nName:%s\nAddress:%s\nMobile no:%15s\nE-mail:%s\n",cont.name,cont.address,cont.mble_no,cont.mail); 
            char choice[10];
			printf("\n\n -Please select option which you want to update-\n");
            printf("\n1.Name\n2.Address\n3.Mobile number\n4.Email");
            fflush(stdin);
            printf("\nEnter option- ");
            gets(choice);
            do 
			{
            	if(strcmp(choice,"1")==0)
            	{
                	status=1;
                	fflush(stdin);
                	printf("\nEnter Name:-");
                	gets(s.name);
                	strcpy(s.address,cont.address);
                	strcpy(s.mble_no,cont.mble_no);
                	strcpy(s.mail,cont.mail);
            	}
            	else if(strcmp(choice,"2")==0)
            	{
            	    status=1;
            	    fflush(stdin);
            	    printf("\nEnter Address:-");
            	    gets(s.address);
            	    strcpy(s.mble_no,cont.mble_no);
            	    strcpy(s.mail,cont.mail);
            	    strcpy(s.name,cont.name);
            	}
            	else if(strcmp(choice,"4")==0)
            	{
            	    status=1;
            	    fflush(stdin);
            	    printf("\nEnter e-mail:-");
            	    gets(s.mail);
            	    strcpy(s.mble_no,cont.mble_no);
            	    strcpy(s.name,cont.name);
            	    strcpy(s.address,cont.address);
            	}
            	else if(strcmp(choice,"3")==0)
            	{
            	    status=1;
            	    fflush(stdin);
            	    printf("\nEnter Phone number:-");
            	    gets(s.mble_no);
            	    strcpy(s.name,cont.name);
            	    strcpy(s.address,cont.address);
            	    strcpy(s.mail,cont.mail);
            	}
            	else
            	{
            	    fflush(stdin);
                	printf("\nPlease enter valid choice..");
                	printf("\nEnter option-");
            		gets(choice);
	            }
            }while(status!=1);
            if(status==1)
            {
                fseek(fp,-sizeof(cont),SEEK_CUR);
                fwrite(&s,sizeof(s),1,fp);
                break;
            }
        }
        fflush(stdin);
    }
    fclose(fp);
    if(flag==1)
    {
        printf("\nContact modified..");
    }
    else
	{
        printf("\nNo such contact..");
    }
    fflush(stdin);
	printf("\nEnter any key:- ");
	getch();
    system("cls");
	main();
}
