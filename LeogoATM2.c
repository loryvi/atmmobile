#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
void gotoxy(int x,int y);
void start();
int i,j;
int op;
int main_exit;
void menu();
void close();

struct date{
    int month,day,year;
};

struct whole{
    char first_name[100];
    char middle_name[100];
    char last_name[100];
};
struct {

    double mobilenumber;
    char password[100];
    char emailaddress[100];
    char nationality[100];
    char dateofbirth[100];
    char placeofbirth[100];
    char address[100];
    float amount;
    struct date mdy;
    struct whole name;

}add,upd,check,rem,transaction;

void fordelay(int j)
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}
void box(){
    int i, boxrow=26,boxcolumn=27;
    for(i=0; i<boxcolumn; i++){
      gotoxy(5,i+3);  printf("\xDD");
      gotoxy(30,i+3);  printf("\xDE");
    }

   for(i=0; i<boxrow; i++){
        gotoxy(i+5,3); printf("\xDC");
        gotoxy(i+5,29);printf("\xDF");
    }
}

void box2()
{
    int i, boxrow=50,boxcolumn=27;
    for(i=0; i<boxcolumn; i++){
      gotoxy(5,i+3);  printf("\xDD");
      gotoxy(54,i+3);  printf("\xDE");
    }
   for(i=0; i<boxrow; i++){
        gotoxy(i+5,3); printf("\xDC");
        gotoxy(i+5,29);printf("\xDF");
    }
}

void addaccount(){
    int choice;
    FILE *ptr;
    ptr=fopen("ATMdatabase.dat", "a+");

    num:
    system("cls");
    box();

    gotoxy(9,23);printf("PRESS 0 TO CANCEL");

    gotoxy(10,5);printf("WELCOME TO A-ToM");
    gotoxy(7,7);printf("\xAF \xAF \xAF REGISTER \xAE \xAE \xAE");
    gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");

    gotoxy(9,10);printf("MOBILE NUMBER:");
    gotoxy(9,11);scanf("%lf", &check.mobilenumber);

    gotoxy(9,13);printf("PASSWORD: ");
    gotoxy(9,14);scanf("%s", add.password);

             for(i=0;i<=8;i++){
            fordelay(10000000);
            gotoxy(13+i,16);printf("\xA7");
            }
     while(fscanf(ptr,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,&add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,&add.mdy.month,&add.mdy.day,&add.mdy.year,add.placeofbirth,&add.amount)!=EOF)
    {
        system("cls");
        if (check.mobilenumber==add.mobilenumber)
            {
             gotoxy(10,5);printf("A-ToM MOBILE BANK");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(11,12);printf("ACCOUNT EXIST!");

            for(i=0;i<=8;i++)
                    {
                        fordelay(10000000);
                        gotoxy(13+i,14);printf("\xDB");
                    }
            goto num;
            }
    }
    system("cls");
    box();
    add.mobilenumber=check.mobilenumber;
    gotoxy(8,4);printf("REGISTER YOUR NUMBER");
    gotoxy(7,5);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,6);printf("\xAF FIRST NAME");
    gotoxy(7,7);scanf("%s", add.name.first_name);
    gotoxy(7,8);printf("\xAF MIDDLE NAME");
    gotoxy(7,9);scanf("%s", add.name.middle_name);
    gotoxy(7,10);printf("\xAF LAST NAME");
    gotoxy(7,11);scanf("%s", add.name.last_name);
    gotoxy(7,12);printf("\xAF EMAIL ADDRESS");
    gotoxy(7,13);scanf("%s", add.emailaddress);
    gotoxy(7,14);printf("\xAF NATIONALITY");
    gotoxy(7,15);scanf("%s", add.nationality);
    gotoxy(7,16);printf("\xAF ADDRESS");
    gotoxy(7,17);scanf("%s",add.address);
    gotoxy(7,18);printf("\xAF BIRTHDAY(mm/dd/yyyy)");
    gotoxy(7,19);scanf("%d/%d/%d",&add.mdy.month, &add.mdy.day, &add.mdy.year);
    gotoxy(7,20);printf("\xAF BIRTH PLACE");
    gotoxy(7,21);scanf("%s",add.placeofbirth);
    gotoxy(7,22);printf("ENTER AMOUNT: ");
    gotoxy(7,23);scanf("%f", &add.amount);
    system("cls");

    fprintf(ptr,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);
    fclose(ptr);
    box();
    gotoxy(8,4);printf("REGISTER YOUR NUMBER");
    gotoxy(7,5);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
             for(i=0;i<=8;i++){
            fordelay(100000000);
            gotoxy(13+i,16);printf("\xDB");
            }

    system("cls");
    box();
    gotoxy(8,4);printf("REGISTER YOUR NUMBER");
    gotoxy(7,5);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(10,13);printf("SUCCESSFULLY");
    gotoxy(10,14);printf("REGISTERED");



    fordelay(1000000000);
    system("cls");


jumphere:
system("cls");
box();
    gotoxy(9,6);printf("A-ToM MOBILE BANK");
    gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(11,12); printf("[ 1 ] MAIN MENU");
    gotoxy(11,13); printf("[ 2 ] EXIT");
    gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(11,14); printf("ENTER: ");
    scanf("%d",&main_exit);

    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else
        {
            printf("\nInvalid!\a");
            goto jumphere;
        }

}

void viewlist()
{
    FILE *view;
    view=fopen("ATMdatabase.dat","r");
    int test=0;


    system("cls");
    box2();

    gotoxy(8,4);printf("A-ToM MOBILE BANK");
    gotoxy(8,5);printf(" [2] SEE LIST ");
    gotoxy(7,6);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,28);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(8,7);printf("MOBILE NUMBER");
    gotoxy(23,7);printf("NAME");
    gotoxy(42,7);printf("BIRTHDAY");


    while(fscanf(view,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,&add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,&add.mdy.month,&add.mdy.day,&add.mdy.year,add.placeofbirth,&add.amount)!=EOF)
       {

          gotoxy(6,test+9);printf("%d)",test+1);
          gotoxy(8,test+9);printf(" %.0lf", add.mobilenumber);
          gotoxy(22,test+9);printf("%s %s %s",add.name.first_name,add.name.middle_name,add.name.last_name);
          gotoxy(42,test+9);printf("%d/%d/%d", add.mdy.month,add.mdy.day,add.mdy.year);
            test++;
       }

    fclose(view);
    if (test==0)
        {   system("cls");
            box2();
            gotoxy(8,4);printf("A-ToM MOBILE BANK");
            gotoxy(8,5);printf(" [2] SEE LIST ");
            gotoxy(7,6);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,28);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(10,13);printf("RECORD");
            gotoxy(10,14);printf("NOT");
            gotoxy(10,15);printf("FOUND");
            fordelay(1000000000);
        }
   jumphere:
        gotoxy(30,4);printf("[1] MAIN MENU");
        gotoxy(30,5);printf("[0] EXIT    :");
        gotoxy(43,5);scanf("%d",&main_exit);

    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==0)
            close();
    else if(main_exit==2)
            viewlist();
    else
        {
            system("cls");
            box2();
            gotoxy(8,4);printf("A-ToM MOBILE BANK");
            gotoxy(8,5);printf("  [2] SEE LIST ");
            gotoxy(7,6);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,28);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");

            gotoxy(10,14);printf("Invalid!");
            goto jumphere;
        }
}

void edit(void)
{
    int choice,test=0;
    FILE *old,*newrec;

    old=fopen("ATMdatabase.dat","r");
    newrec=fopen("ATMnewdatabase.dat","w");

    box();
    gotoxy(10,5);printf("A-ToM MOBILE BANK");
    gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
    gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(9,10);printf("MOBILE NUMBER:");
    gotoxy(9,11);scanf("%lf",&upd.mobilenumber);


    while(fscanf(old,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,&add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,&add.mdy.month,&add.mdy.day,&add.mdy.year,add.placeofbirth,&add.amount)!=EOF)
    {
        if (add.mobilenumber==upd.mobilenumber)
        {   test=1;
            system("cls");
            box();
            gotoxy(10,5);printf("A-ToM MOBILE BANK");
            gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,9);printf("MOBILE NUMBER:");
            gotoxy(7,10);printf("%.0lf",add.mobilenumber);
            gotoxy(7,12);printf("[1] NAME");
            gotoxy(7,13);printf("[2] MOBILE NUMBER");
            gotoxy(7,14);printf("[3] PASSWORD");
            gotoxy(7,15);printf("[4] EMAIL ADDRESS");
            gotoxy(7,16);printf("[5] NATIONALITY");
            gotoxy(7,17);printf("[6] ADDRESS");
            gotoxy(7,18);printf("[7] BIRTHDAY");
            gotoxy(7,19);printf("[8] PLACE OF BIRTH");
            gotoxy(7,20);printf("[9] EXIT");
            gotoxy(7,22);printf("ENTER CHOICE:");
            scanf("%d",&choice);
            system("cls");

            if(choice==6)
            {   system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,10);printf("UPDATE ADDRESS:");
                gotoxy(7,11);scanf("%s",upd.address);
                fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, upd.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);
                gotoxy(7,13);printf("CHANGES SAVED!!");
                system("cls");
                }

            else if(choice==2)
                {
                system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,10);printf("UPDATE MOBILE NUMBER:");
                gotoxy(7,11);scanf("%lf",&upd.mobilenumber);
                            fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,upd.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);
                gotoxy(7,13);printf("CHANGES SAVED!!");
                system("cls");
                }
            else if(choice==3) //change password
            {   system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,10);printf("UPDATE PASSWORD:");
                gotoxy(7,11);scanf("%s",upd.password);

                        fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, upd.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);
              gotoxy(7,13);printf("CHANGES SAVED!!");
                system("cls");
            }
            else if(choice==4) //change email address
            {
                system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,10);printf("UPDATE EMAIL ADDRESS:");
                gotoxy(7,11);scanf("%s",upd.emailaddress);

                        fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, upd.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);
               gotoxy(7,13);printf("CHANGES SAVED!!");
               system("cls");
            }
            else if(choice==5) //change nationality
            {   system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,10);printf("UPDATE NATIONALITY:");
                gotoxy(7,11);scanf("%s",upd.nationality);

                        fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, upd.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);

                gotoxy(7,13);printf("CHANGES SAVED!!");
                    system("cls");
            }
            else if(choice==1) //change name
            {   system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,10);printf("UPDATE NAME");
                gotoxy(7,12);printf("\xAF FIRST NAME");
                gotoxy(7,13);scanf("%s",upd.name.first_name);
                gotoxy(7,14);printf("\xAF MIDDLE NAME:");
                gotoxy(7,15);scanf("%s",upd.name.middle_name);
                gotoxy(7,16);printf("\xAF LAST NAME:");
                gotoxy(7,17);scanf("%s",upd.name.last_name);

                        fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",upd.name.first_name,upd.name.middle_name,upd.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);
                gotoxy(7,19);printf("CHANGES SAVED!!");

                    system("cls");

            }
            else if(choice==7) //change birthday
            {
                system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,10);printf("UPDATE BIRTHDAY:");
                gotoxy(7,11);printf("(mm/dd/year)");
                gotoxy(7,12); scanf("%d/%d/%d",&upd.mdy.month, &upd.mdy.day, &upd.mdy.year);

                        fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,upd.mdy.month,upd.mdy.day,upd.mdy.year,add.placeofbirth,add.amount);
                gotoxy(7,14);printf("CHANGES SAVED!!");
                 system("cls");
            }
            else if(choice==8) //change place of birth
            {   system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,10);printf("UPDATE PLACE OF BIRTH:");
                gotoxy(7,11);scanf("%s",upd.placeofbirth);

                        fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,upd.placeofbirth,add.amount);
                gotoxy(7,13);printf("CHANGES SAVED!!");
                 system("cls");
            }
        }
        else
           fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);
    }

fclose(old);
fclose(newrec);
remove("ATMdatabase.dat");
rename("ATMnewdatabase.dat","ATMdatabase.dat");


if(test!=1)
        {   system("cls");
            box();
            gotoxy(10,5);printf("A-ToM MOBILE BANK");
            gotoxy(7,7);printf("\xAF \xAF \xAF \xAF       \xAE \xAE \xAE \xAE");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(10,13);printf("RECORD");
            gotoxy(10,14);printf("NOT");
            gotoxy(10,15);printf("FOUND");
            fordelay(1000000000);

            jumphere:
            system("cls");
            box();

                gotoxy(9,6);printf("A-ToM MOBILE BANK");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(11,12); printf("[ 1 ] MAIN MENU");
                gotoxy(11,13); printf("[ 2 ] EDIT");
                gotoxy(11,14); printf("[ 3 ] EXIT");

                gotoxy(11,15); printf("ENTER: ");scanf("%d",&main_exit);

              system("cls");
                 if (main_exit==1){
                    fclose(old);
                    fclose(newrec);
                    menu();
                 }
                else if (main_exit==2){
                    fclose(old);
                    fclose(newrec);
                    edit();
                }
                else if(main_exit==3){

                    fclose(old);
                    fclose(newrec);
                    remove("ATMdatabase.dat");
                    rename("ATMnewdatabase.dat","ATMdatabase.dat");

                    close();
                }
                else
                    {printf("\nInvalid!\a");
                    goto jumphere;}
        }
    else
        {       system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf("\xAF \xAF \xAF \xAF UPDATE \xAE \xAE \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");

                gotoxy(11,20); printf("[ 1 ] MAIN MENU");
                gotoxy(11,21); printf("[ 2 ] EDIT");
                gotoxy(11,22); printf("[ 3 ] EXIT");
                gotoxy(11,23); printf("ENTER: ");scanf("%d",&main_exit);

    system("cls");
    if (main_exit==1)
        menu();
    else if(main_exit==3){
            fclose(old);
            fclose(newrec);
            remove("ATMdatabase.dat");
            rename("ATMnewdatabase.dat","ATMdatabase.dat");
            close();
    }
    else if(main_exit==2){
        fclose(old);
        fclose(newrec);
        edit();
    }
    else
        {
            system("cls");
            box();
            gotoxy(9,6);printf("A-ToM MOBILE BANK");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(10,14);printf("INVALID.");
            fordelay(1000000000);

        }


fclose(old);
fclose(newrec);
remove("ATMdatabase.dat");
rename("ATMnewdatabase.dat","ATMdatabase.dat");
}
}
void transact(void)
{   int choice,test=0;
    FILE *old,*newrec;
    old=fopen("ATMdatabase.dat","r");
    newrec=fopen("ATMnewdatabase.dat","w");

        system("cls");
        box();
        gotoxy(10,5);printf("A-ToM MOBILE BANK");
        gotoxy(7,7);printf(" \xAF \xAF TRANSACTION \xAE \xAE");
        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(9,10);printf("MOBILE NUMBER:");
        gotoxy(9,11);scanf("%lf",&transaction.mobilenumber);

    while (fscanf(old,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,&add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,&add.mdy.month,&add.mdy.day,&add.mdy.year,add.placeofbirth,&add.amount)!=EOF)
    {

            if(add.mobilenumber==transaction.mobilenumber)
            { test=1;

                system("cls");
                box();
                gotoxy(10,5);printf("A-ToM MOBILE BANK");
                gotoxy(7,7);printf(" \xAF \xAF TRANSACTION \xAE \xAE");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(7,9);printf("MOBILE NUMBER:");
                gotoxy(7,10);printf("%.0lf",add.mobilenumber);
                gotoxy(7,12);printf("[1] DEPOSIT");
                gotoxy(7,13);printf("[2] WITHDRAW");
                gotoxy(7,15);printf("ENTER: ");scanf("%d",&choice);

                if(choice==1)
                {
                    system("cls");
                    box();
                    gotoxy(10,5);printf("A-ToM MOBILE BANK");
                    gotoxy(7,7);printf(" \xAF \xAF TRANSACTION \xAE \xAE");
                    gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                    gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                    gotoxy(7,12);printf("DEPOSIT: ");
                    gotoxy(7,13); scanf("%f",&transaction.amount);

                    add.amount+=transaction.amount;
                    fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);

                    for(i=0;i<=8;i++)
                    {
                        fordelay(10000000);
                        gotoxy(7+i,15);printf("\xDB");
                    }
                    gotoxy(7,16);printf("DEPOSITED");
                    gotoxy(7,17);printf("SUCCESSFULLY");

                    gotoxy(7,19);printf("\xAE BALANCE:");
                    gotoxy(10,20);printf("PHP %.2f",add.amount);

                }
                else
                {   system("cls");
                    box();
                    gotoxy(10,5);printf("A-ToM MOBILE BANK");
                    gotoxy(7,7);printf(" \xAF \xAF TRANSACTION \xAE \xAE");
                    gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                    gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                    gotoxy(7,12);printf("WITHDRAW: ");
                    gotoxy(7,13); scanf("%f",&transaction.amount);

                    add.amount-=transaction.amount;
                    fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);

                    for(i=0;i<=8;i++)
                    {
                        fordelay(10000000);
                        gotoxy(7+i,15);printf("\xDB");
                    }
                    gotoxy(7,16);printf("WITHDRAWED");
                    gotoxy(7,17);printf("SUCCESSFULLY");

                    gotoxy(7,19);printf("\xAE BALANCE:");
                    gotoxy(10,20);printf("PHP %.2f",add.amount);

                 }
            }
            else{
                    fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);
              }
    }
    fclose(old);
    fclose(newrec);
    remove("ATMdatabase.dat");
    rename("ATMnewdatabase.dat","ATMdatabase.dat");
    if(test!=1)
    {
        gotoxy(9,13);printf("RECORD NOT FOUND.");
        jumphere:
        gotoxy(10,16);printf("[0] TRY AGAIN");
        gotoxy(10,17);printf("[1] MAIN MENU");
        gotoxy(10,18);printf("[2] EXIT");
        gotoxy(10,19);printf("ENTER: ");scanf("%d",&main_exit);

        system("cls");
      if (main_exit==0){
        fclose(old);
        fclose(newrec);
        transact();
      }
    else if (main_exit==1){
        fclose(old);
        fclose(newrec);
        menu();
    }
    else if (main_exit==2)
        {
        fclose(old);
        fclose(newrec);
        remove("ATMdatabase.dat");
        rename("ATMnewdatabase.dat","ATMdatabase.dat");
        close();
        }
    else
    {
        system("cls");
            box();
            gotoxy(9,6);printf("A-ToM MOBILE BANK");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(10,14);printf("INVALID.");
            fordelay(1000000000);

        goto jumphere;
    }

   }
   else
   {
       gotoxy(7,22);printf(" [1] MAIN MENU");
       gotoxy(7,23);printf(" [2] EXIT");
       gotoxy(7,24);printf(" ENTER: ");scanf("%d",&main_exit);
        system("cls");
        if (main_exit==1)
        {
         fclose(old);
         fclose(newrec);
         menu();
        }
        else
        {   fclose(old);
            fclose(newrec);
            remove("ATMdatabase.dat");
            rename("ATMnewdatabase.dat","ATMdatabase.dat");
            close();
        }

}
  fclose(old);
   fclose(newrec);
   remove("ATMdatabase.dat");
   rename("ATMnewdatabase.dat","ATMdatabase.dat");
}
void removeaccount(void)
{
    FILE *old,*newrec;
    int test=0;

    old=fopen("ATMdatabase.dat","r");
    newrec=fopen("ATMnewdatabase.dat","w");
        system("cls");
        box();
        gotoxy(10,5);printf("A-ToM MOBILE BANK");
        gotoxy(7,7);printf("\xAF \xAF DELETE ACCOUNT \xAE \xAE");
        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(7,10);printf("ENTER MOBILE NUMBER: ");
        gotoxy(7,11);scanf("%lf",&rem.mobilenumber);


    while (fscanf(old,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,&add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,&add.mdy.month,&add.mdy.day,&add.mdy.year,add.placeofbirth,&add.amount)!=EOF)
   {
        if(add.mobilenumber!=rem.mobilenumber)
            fprintf(newrec,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,add.mdy.month,add.mdy.day,add.mdy.year,add.placeofbirth,add.amount);

        else{
            test++;
            box();
            gotoxy(10,5);printf("A-ToM MOBILE BANK");
            gotoxy(7,7);printf("\xAF \xAF DELETE ACCOUNT \xAE \xAE");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(10,13);printf("ACCOUNT");
            gotoxy(10,14);printf("DELETED");
            gotoxy(10,15);printf("SUCCESSFULLY");
            fordelay(1000000000);


            }
   }

   if(test==0)
        {
            system("cls");
            box();
            gotoxy(10,5);printf("A-ToM MOBILE BANK");
            gotoxy(7,7);printf("\xAF \xAF \xAF \xAF       \xAE \xAE \xAE \xAE");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(10,13);printf("RECORD");
            gotoxy(10,14);printf("NOT");
            gotoxy(10,15);printf("FOUND");
            fordelay(1000000000);

            erase_invalid:
                 system("cls");
                box();
                gotoxy(9,6);printf("A-ToM MOBILE BANK");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(11,12); printf("[ 0 ] TRY AGAIN");
                gotoxy(11,13); printf("[ 1 ] MAIN MENU");
                gotoxy(11,14); printf("[ 2 ] EXIT");
                gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(11,16); printf("ENTER: ");scanf("%d",&main_exit);

                 if (main_exit==1){
                    fclose(old);
                    fclose(newrec);
                    menu();
                 }
                else if (main_exit==2){
                    fclose(old);
                    fclose(newrec);
                    remove("ATMdatabase.dat");
                    rename("ATMnewdatabase.dat","ATMdatabase.dat");
                    close();
                }
                else if(main_exit==0)
                    removeaccount();
                else
                    {printf("\nInvalid!\a");
                    goto erase_invalid;}
        }
    else
        {
        system("cls");
        box();
        gotoxy(9,6);printf("A-ToM MOBILE BANK");
        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(11,12); printf("[ 1 ] MAIN MENU");
        gotoxy(11,13); printf("[ 2 ] EXIT");
        gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(11,14); printf("ENTER: ");scanf("%d",&main_exit);

        system("cls");
            if (main_exit==1){
            menu();
            }
            else{
                fclose(old);
                fclose(newrec);
                remove("ATMdatabase.dat");
                rename("ATMnewdatabase.dat","ATMdatabase.dat");
                close();
        }

}
    fclose(old);
   fclose(newrec);
   remove("ATMdatabase.dat");
   rename("ATMnewdatabase.dat","ATMdatabase.dat");
}
void see(void)
{
    FILE *ptr;
    int test=0;
    int choice;
    ptr=fopen("ATMdatabase.dat","r");

    system("cls");
        box();
        gotoxy(10,5);printf("A-ToM MOBILE BANK");
        gotoxy(7,7);printf(" \xAF \xAF VIEW DETAILS \xAE \xAE");
        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(7,10);printf(" [ 1 ] MOBILE NUMBER");
        gotoxy(7,11);printf(" [ 2 ] EMAIL ADDRESS");
        gotoxy(7,13);printf("ENTER: ");scanf("%d",&choice);

    if (choice==1)
        {
        system("cls");
        box();
        gotoxy(10,5);printf("A-ToM MOBILE BANK");
        gotoxy(7,7);printf(" \xAF \xAF VIEW DETAILS \xAE \xAE");
        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(7,10);printf(" ENTER MOBILE NUMBER:");
        gotoxy(7,11);scanf("%lf",&check.mobilenumber);

        while (fscanf(ptr,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,&add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,&add.mdy.month,&add.mdy.day,&add.mdy.year,add.placeofbirth,&add.amount)!=EOF)
        {
            if(add.mobilenumber==check.mobilenumber)
            {   system("cls");
                test=1;
            system("cls");
            box();
            gotoxy(10,5);printf("A-ToM MOBILE BANK");
            gotoxy(7,7);printf(" \xAF \xAF VIEW DETAILS \xAE \xAE");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,9);printf("ENTER MOBILE NUMBER:");
            gotoxy(7,10);printf("%.0lf",add.mobilenumber);

           gotoxy(7,12);printf("%s",add.name.first_name);
           gotoxy(7,13);printf("%s",add.name.middle_name);
           gotoxy(7,14);printf("%s",add.name.last_name);
           gotoxy(9,15);printf("BALANCE:");
           gotoxy(9,16);printf("PHP %.2f",add.amount);

           gotoxy(7,18);printf("%s", add.emailaddress);
           gotoxy(7,19);printf("%s", add.nationality);
           gotoxy(7,20);printf("%s", add.address);
           gotoxy(7,21);printf("%d/%d/%d", add.mdy.month,add.mdy.day,add.mdy.year);
           gotoxy(7,22);printf("%s", add.placeofbirth);
            int op;
            gotoxy(7,25);printf(" [ 1 ] MAIN MENU");
            scanf("%d",&op);
            if(op==1)
               menu();
            }

        }
        fclose(ptr);

    }
    else if (choice==2)
    {   gotoxy(7,15);printf("EMAIL ADDRESS: ");
        gotoxy(7,16);scanf("%s",check.emailaddress);
        while (fscanf(ptr,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,&add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,&add.mdy.month,&add.mdy.day,&add.mdy.year,add.placeofbirth,&add.amount)!=EOF)
       {
            if(strcmpi(add.emailaddress,check.emailaddress)==0)
            {   system("cls");
            test=1;
           system("cls");
            box();
            gotoxy(10,5);printf("A-ToM MOBILE BANK");
            gotoxy(7,7);printf(" \xAF \xAF VIEW DETAILS \xAE \xAE");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,9);printf("ENTER MOBILE NUMBER:");
            gotoxy(7,10);printf("%.0lf",add.mobilenumber);

           gotoxy(7,12);printf("%s",add.name.first_name);
           gotoxy(7,13);printf("%s",add.name.middle_name);
           gotoxy(7,14);printf("%s",add.name.last_name);
           gotoxy(9,15);printf("BALANCE:");
           gotoxy(9,16);printf("PHP %.2f",add.amount);

           gotoxy(7,18);printf("%s", add.emailaddress);
           gotoxy(7,19);printf("%s", add.nationality);
           gotoxy(7,20);printf("%s", add.address);
           gotoxy(7,21);printf("%d/%d/%d", add.mdy.month,add.mdy.day,add.mdy.year);
           gotoxy(7,22);printf("%s", add.placeofbirth);
           int op;
            gotoxy(7,25);printf(" [ 1 ] MAIN MENU");
            scanf("%d",&op);
            if(op==1)
               menu();

            }
        }
        fclose(ptr);
    }


     if(test!=1)
        {
            system("cls");
            box();
            gotoxy(10,5);printf("A-ToM MOBILE BANK");
            gotoxy(7,7);printf("\xAF \xAF \xAF \xAF       \xAE \xAE \xAE \xAE");
            gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
            gotoxy(10,13);printf("RECORD");
            gotoxy(10,14);printf("NOT");
            gotoxy(10,15);printf("FOUND");
            fordelay(1000000000);

            see_invalid:
                 system("cls");
                box();
                gotoxy(9,6);printf("A-ToM MOBILE BANK");
                gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(11,12); printf("[ 0 ] TRY AGAIN");
                gotoxy(11,13); printf("[ 1 ] MAIN MENU");
                gotoxy(11,14); printf("[ 2 ] EXIT");
                gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                gotoxy(11,16); printf("ENTER: ");scanf("%d",&main_exit);

              system("cls");
                 if (main_exit==1)
                    menu();
                else if (main_exit==2)
                    close();
                else if(main_exit==0)
                    see();
                else
                    {
                       system("cls");
                        box();
                        gotoxy(9,6);printf("A-ToM MOBILE BANK");
                        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                        gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                        gotoxy(10,14);printf("INVALID.");
                        fordelay(1000000000);
                        goto see_invalid;}
        }
    else
        {
        system("cls");
        box();
        gotoxy(9,6);printf("A-ToM MOBILE BANK");
        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(11,12); printf("[ 1 ] MAIN MENU");
        gotoxy(11,13); printf("[ 2 ] EXIT");
        gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(11,14); printf("ENTER: ");scanf("%d",&main_exit);

        if (main_exit==1)
        {
            system("cls");
            menu();
        }

        else
           {
            system("cls");
            close();
            }

}
}

void menu(void)
{   int op;
    system("cls");
    box();
    gotoxy(10,5);printf("A-ToM MOBILE BANK");
    gotoxy(7,7);printf("\xAF  \xAF  \xAFM E N U\xAE  \xAE  \xAE ");
    gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(7,12);printf("[1] CREATE NEW ACCOUNT");
    gotoxy(7,13);printf("[2] UPDATE INFORMATION");
    gotoxy(7,14);printf("[3] TRANSACTION");
    gotoxy(7,15);printf("[4] CHECK AN ACCOUNT");
    gotoxy(7,16);printf("[5] DELETE AN ACCOUNT");
    gotoxy(7,17);printf("[6] VIEW CUSTOMERS LIST");
    gotoxy(7,18);printf("[7] LOG OUT");
    gotoxy(7,19);printf("[8] EXIT");
    gotoxy(7,21);printf("ENTER CHOICE: ");scanf("%d",&op);

    system("cls");
    switch(op)
    {
        case 1:addaccount();
        break;
        case 2:edit();
        break;
        case 3:transact();
        break;
        case 4:see();
        break;
        case 5:removeaccount();
        break;
        case 6:viewlist();
        break;
        case 7:system("cls");
                box();
                gotoxy(11,13);printf("SIGNING OUT");
                for(i=0;i<=13;i++)
                    {
                        fordelay(100000000);
                        gotoxy(11+i,14);printf("\xDB");
                    }
            system("cls");
            start();
        break;
        case 8:close();
        break;

    }
}


void login(void)
{
int i;
FILE *ptr;
  ptr=fopen("ATMdatabase.dat","r");
        system("cls");
        box();
        gotoxy(10,5);printf("WELCOME TO A-ToM");
        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
        gotoxy(9,10);printf("MOBILE NUMBER:");
        gotoxy(9,11);scanf("%lf", &check.mobilenumber);
        gotoxy(9,13);printf("PASSWORD: ");
        gotoxy(9,14);scanf("%s", &check.password);


        while (fscanf(ptr,"\n %s %s %s \n %lf \n %s \n %s \n %s \n %s\n %d/%d/%d\n %s \n%f",add.name.first_name,add.name.middle_name,add.name.last_name,&add.mobilenumber, add.password, add.emailaddress, add.address, add.nationality,&add.mdy.month,&add.mdy.day,&add.mdy.year,add.placeofbirth,&add.amount)!=EOF)
        {
            if((check.mobilenumber==add.mobilenumber)&&strcmpi(add.password,check.password)==0)
            {
                system("cls");
                box();
                gotoxy(11,13);printf("LOADING");
                for(i=0;i<=13;i++)
                    {
                        fordelay(100000000);
                        gotoxy(11+i,14);printf("\xDB");
                    }
               system("cls");

                menu();
            }
        }
fclose(ptr);
system("cls");
box();
start();

}

void start(){
    box();

      gotoxy(10,5);printf("WELCOME TO A-ToM");
    gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(11,12); printf("[ 1 ] Register");
    gotoxy(11,13); printf("[ 2 ] Login");
    gotoxy(7,18); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
    gotoxy(11,14); printf("ENTER: ");scanf("%d", &op);

    switch(op){
    case 1: system("cls");
            box();
            gotoxy(11,13);printf("LOADING");
             for(i=0;i<=13;i++)
                    {
                        fordelay(100000000);
                        gotoxy(11+i,14);printf("\xDB");
                    }
            addaccount();
            break;

    case 2: login();
            break;
    default: system("cls");start();
    }
}

int main(){
    start();
}
void close(){
    system("cls");
                        box();
                        gotoxy(9,6);printf("A-ToM MOBILE BANK");
                        gotoxy(7,8);printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                        gotoxy(7,26); printf("\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD\xCD");
                        gotoxy(10,14);printf("THANK YOU");
                        gotoxy(10,15);printf("FOR");
                        gotoxy(10,16);printf("USING");
                        gotoxy(10,17);printf("A-Tom");
                        fordelay(100000000);
    system("cls");
                box();
                gotoxy(11,13);printf("SIGNING OUT");
                for(i=0;i<=13;i++)
                    {
                        fordelay(100000000);
                        gotoxy(11+i,14);printf("\xDB");
                    }

}
COORD coord={0,0};
void gotoxy(int x, int y)
{

    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


