#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>
#include<string.h>

void signupform();
void loginform();
void toss();
void about();
void newscoresheet();
void viewscoresheet();
void controllerFunction();
void addbatting();
void addbowling();
void addcurrent();
void battingteam();
void bowlingteam();
void currentmatchinfo();
void totalruns();
void viewlast();
void currentmatch();

int main()
{
    system("COLOR 2F");
    system("cls");
    printf("\n\t\t\t\t\t***CRICKET SCORE MANAGEMENT SYSTEM***\n");
    printf("\n\t\t\t\t\t======================================\n");
    printf("\n\t\t\t\t\tDeveloped By\n\t\t\t\t\tSumon Sheikh (Dept. of SWE at DIU)\n\t\t\t\t\tID: 172-35-2136\n\t\t\t\t\tDevelop Date: 04-04-2018\n");
    printf("\n\t\t\t\t\t======================================\n");
    printf("\n\t\t\t\t\t1.Signup\n");
    printf("\n\t\t\t\t\t2.Login\n");
    printf("\n\t\t\t\t\t3.About\n");
    printf("\n\t\t\t\t\t4.Log Out\n");

    int si=0;
    printf("\n\t\t\t\t\tChoose your option: ");
    scanf("%d",&si);

    switch(si)
    {
        case 1:
            signupform();
            break;
        case 2:
            loginform();
            break;
        case 3:
            about();
            break;
        case 4:
            exit(0);
            break;
            default:
                printf("\n\t\t\t\t\tYour choice is wrong\n");
                break;
     }
     return 0;
}

void signupform()
{
    system("CLS");
    printf("\n\t\t\t\t\t***THIS IS SIGNUP FORM***\n");

    FILE *signup;
    signup = fopen("Signup.txt", "a+");
    if(signup == NULL)
      {
          exit(1);
      }

    char usern[30];
    printf("\n\t\t\t\t\tUser name: ");
    scanf("%s",&usern);
    char password[10],ch;
    printf("\n\t\t\t\t\tPassword <By 6 characters>: ");
    scanf("%s",&password);
    /*for(int i=0;i<6;i++)
        {
            ch = getch();
            password[i] = ch;
            ch = '*' ;
            printf("%c",ch);
        }*/
    fprintf(signup,"Username %s Password %s\n",usern,password);
    fclose(signup);

    printf("\n\t\t\t\t\tPress 0 To Return Main Menu 1 Save\n");

    int su=0;
    printf("\n\t\t\t\t\tChoose your option: ");
    scanf("%d",&su);
    switch(su)
    {
        case 0:
            main();
            break;
        case 1:
            printf("\n\t\t\t\t\tSuccessfully Saved\n");
            printf("\n\t\t\t\t\tPress Enter For Back To Main Menu.....");
            getch();
            main();
            break;
            default:
                printf("\n\t\t\t\t\tYour Choice Is Wrong");
                printf("\n\t\t\t\t\tPress Enter For Back");
                getch();
                main();
                break;
     }

}

void loginform()
{
    system("CLS");

    char usname[30];
    char password[30];
    printf("\n\t\t\t\t\t***THIS IS LOGIN FORM***\n");
    printf("\n\t\t\t\t\tUsername: ");
    scanf("%s",&usname);
    printf("\n\t\t\t\t\tPassword <By 6 characters>: ");
    scanf("%s",&password);

    FILE *login;
    login = fopen("Signup.txt", "r+");

    char name[30];
    char pass[30];
    int i=0;

    while(fscanf(login,"%s %s %s %s",name,name,pass,pass)!=EOF)
    {
      int username = strcmp(usname,name);
      int upass = strcmp(password,pass);
      if(username==0 && upass==0)
        {
            printf("\n\t\t\t\t\tSuccessfully Logged In\n");
            printf("\n\t\t\t\t\tPress Enter To Continue......");
            getch();
            system("CLS");
            printf("\n\n\n\n\n\t\t\t\t\t==========================================");
            printf("\n\n\n\t\t\t\t\t\WELCOME TO CRICKET SCORE MANAGEMENT SYSTEM");
            printf("\n\n\n\t\t\t\t\t==========================================");
            printf("\n\n\t\t\t\t\tPress Enter To Continue....");
            getch();
            i=1;
            break;
        }
    }
    if(i==0)
       {
           printf("\n\t\t\t\t\tLogin Unsuccessful!!\n");
           printf("\n\t\t\t\t\tPlease Input Correct Username & Password\n");
           printf("\n\t\t\t\t\tPress Enter For Back To Main Menu....");
           getch();
           main();
       }
    else
       controllerFunction();
}

void about()
{
    system("CLS");
    printf("\n\t\t\t\t\t***ABOUT CRICKET SCORE MANAGEMENT SYSTEM***\n");
    printf("\n\t\t\t\t\t===========================================\n");
    printf("\n\t\t\t\t\tThis Software is developed by Sumon Sheikh\n\t\t\t\t\tVersion 1.0\n\t\t\t\t\tIf you face any bug, please send bug reports\n\t\t\t\t\tto Sumon35-2136@diu.edu.bd\n");
    printf("\n\t\t\t\t\t===========================================\n\n\n");

    printf("\n\t\t\t\t\tPress Enter For Back To Main Menu....");
    getch();
    main();
}

void controllerFunction()
{
    printf("\n\t\t\t\t\tLogin Successful\n");
    system("cls");
    printf("\n\t\t\t\t\t***CRCKET SCORE MANAGEMENT SYSTEM***\n");
    printf("\n\t\t\t\t\t1. Add Player's Profile of Both Team\n");
    printf("\n\t\t\t\t\t2. View Current Match Info\n");
    printf("\n\t\t\t\t\t3. Log Out\n");
    int su;
    printf("\n\t\t\t\t\tChoose your option: ");
    scanf("%d",&su);

    switch(su)
    {
     case 1:
         newscoresheet();
         break;
     case 2:
         currentmatch();
         break;
     case 3:
         exit(0);
         default:
             break;
     }

}

void newscoresheet()
{
  system("CLS");
  printf("\n\t\t\t\t\t***ADD NEW SCORESHEET***\n");
  printf("\n\t\t\t\t\t1. Add First Team Player's List\n");
  printf("\n\t\t\t\t\t2. Add Second Team Player's List\n");
  printf("\n\t\t\t\t\t3. Add Current Match Info\n");
  printf("\n\t\t\t\t\t4. Back To Previous Menu\n");
      int su;
    printf("\n\t\t\t\t\tChoose your option: ");
    scanf("%d",&su);

    switch(su)
    {
     case 1:
         addbatting();
         break;
     case 2:
         addbowling();
         break;
     case 3:
         toss();
         break;
     case 4:
         controllerFunction();
         break;
    }
}
void currentmatchinfo()
{
   system("COLOR 2F");
   system("CLS");

    printf("\n\t\t\t\t\t***CRCKET SCORE MANAGEMENT SYSTEM***\n");
    printf("\n\t\t\t\t\t1. Add Current Over\n");
    printf("\n\t\t\t\t\t2. Add Total Runs Of This Match\n");
    printf("\n\t\t\t\t\t3. Score After Current Over\n");
    printf("\n\t\t\t\t\t4. View Score Sheet\n");
    printf("\n\t\t\t\t\t5. Previous Menu\n");
    printf("\n\t\t\t\t\t6. Log Out\n");

    int su;
    printf("\n\t\t\t\t\tChoose your option: ");
    scanf("%d",&su);

    switch(su)
    {
     case 1:
         addcurrent();
         break;
     case 2:
         totalruns();
         break;
     case 3:
         viewlast();
         break;
     case 4:
         currentmatch();
         break;
     case 5:
         viewscoresheet();
         break;
     case 6:
         exit(0);
         default:
             break;
     }
}
void addbatting()
{
    system("COLOR 2F");
    system("CLS");

    FILE *Battingteam;
    Battingteam = fopen("Battingteam.txt", "a+");
    if(Battingteam == NULL)
        {
            exit(1);
        }
    printf("\n\t\t\t\t\tADD FIRST TEAM PLAYER'S PROFILE\n");

    struct battingteam
    {
        char name[50];
        int age;
        int matches;
        int runs;
        int wickets;
    }bat[11];

    for(int i=0;i<11;i++)
        {
            printf("\n\t\t\t\t\t%d.Name: ",i+1);
            scanf("%s",bat[i].name);
            printf("\n\t\t\t\t\tAge: ");
            scanf("%d",&bat[i].age);
            printf("\n\t\t\t\t\tMatches: ");
            scanf("%d",&bat[i].matches);
            printf("\n\t\t\t\t\tRuns: ");
            scanf("%d",&bat[i].runs);
            printf("\n\t\t\t\t\tWickets: ");
            scanf("%d",&bat[i].wickets);

            fprintf(Battingteam,"%d. %s \t%d \t%d \t%d \t%d\n",i+1,bat[i].name,bat[i].age,bat[i].matches,bat[i].runs,bat[i].wickets);
         }

    fclose(Battingteam);
    getch();
    newscoresheet();
}
void totalruns()
{
    FILE *Totalrun;
    Totalrun = fopen("Totalrun.txt", "a+");
    if(Totalrun == NULL)
        {
            exit(1);
        }
    system("CLS");
    printf("\n\t\t\t\t\t***ENTER TODAY'S MATCH INFO***\n");
    char total[20];
    printf("\n\t\t\t\t\tEnter Total Runs Of Bangladesh Team:");
    scanf("%s",total);
    fprintf(Totalrun,"%s",total);

    FILE *Totalrunsba;
    Totalrunsba = fopen("Totalrunsba.txt", "a+");
    if(Totalrunsba == NULL)
        {
            exit(1);
        }

    int n;
    struct nowbatting1
    {
        char id[20];
        char name[20];
        int runs;
        int balls;

    }ba[11];

    printf("\n\t\t\t\t\tEnter How Many Batting Are Bat Today:");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\n\t\t\t\t\tOrder: ");
        scanf("%s",&ba[i].id);
        printf("\n\t\t\t\t\tName: ");
        scanf("%s",&ba[i].name);
        printf("\n\t\t\t\t\tRuns: ");
        scanf("%d",&ba[i].runs);
        printf("\n\t\t\t\t\tBalls: ");
        scanf("%d",&ba[i].balls);

        fprintf(Totalrunsba,"%s \t%s \t%d \t%d\n",ba[i].id,ba[i].name,ba[i].runs,ba[i].balls);
    }

    FILE *Totalrunsbo;
    Totalrunsbo = fopen("Totalrunsbo.txt", "a+");
    if(Totalrunsbo == NULL)
        {
            exit(1);
        }

    struct nowbowling1
    {
        char id[20];
        char name[20];
        int runs;
        int wiecket;
        int over;

    }bo[11];

        printf("\n\t\t\t\t\tEnter How Many Bowling Are Bowled Today: ");
        scanf("%d",&n);

        for(int i=0;i<n;i++)
            {
                printf("\n\t\t\t\t\tOrder: ");
                scanf("%s",&bo[i].id);
                printf("\n\t\t\t\t\tName: ");
                scanf("%s",&bo[i].name);
                printf("\n\t\t\t\t\tRuns: ");
                scanf("%d",&bo[i].runs);
                printf("\n\t\t\t\t\tWiecket: ");
                scanf("%d",&bo[i].wiecket);
                printf("\n\t\t\t\t\tOver: ");
                scanf("%d",&bo[i].over);

               fprintf(Totalrunsbo,"%s \t%s \t%d \t%d \t%d\n",bo[i].id,bo[i].name,bo[i].runs,bo[i].wiecket,bo[i].over);
            }

        fclose(Totalrun);
        fclose(Totalrunsba);
        fclose(Totalrunsbo);
        getch();
        currentmatchinfo();
}
void addbowling()
{
    system("COLOR 2F");
    system("CLS");

    FILE *Bowlingteam;
    Bowlingteam = fopen("Bowlingteam.txt", "a+");
    if(Bowlingteam == NULL)
    {
        exit(1);
    }

    printf("\n\t\t\t\t\tADD SECOND TEAM PLAYER'S PROFILE\n");

    struct bowlingteam
    {
        char name[50];
        int age;
        int matches;
        int runs;
        int wickets;
     }ball[11];

    for(int i=0;i<11;i++)
        {
            printf("\n\t\t\t\t\t%d.Name: ",i+1);
            scanf("%s",ball[i].name);
            printf("\n\t\t\t\t\tAge: ");
            scanf("%d",&ball[i].age);
            printf("\n\t\t\t\t\tMatches: ");
            scanf("%d",&ball[i].matches);
            printf("\n\t\t\t\t\tRuns: ");
            scanf("%d",&ball[i].runs);
            printf("\n\t\t\t\t\tWickets: ");
            scanf("%d",&ball[i].wickets);
            fprintf(Bowlingteam,"%d %s \t%d \t%d \t%d \t%d\n",i+1,ball[i].name,ball[i].age,ball[i].matches,ball[i].runs,ball[i].wickets);
        }
    fclose(Bowlingteam);

    getch();
    newscoresheet();
}

void toss()
{
    system("CLS");
    system("COLOR 2F");
    FILE *Currentmatch;
    Currentmatch = fopen("Currentmatch.txt", "a+");
    if(Currentmatch == NULL)
    {
        exit(1);
    }
    printf("\n\t\t\t\t\tADD CURRENT MATCH INFO\n");
    char toss[20],elect[20];
    printf("\n\t\t\t\t\tToss won by: ");
    scanf("%s",&toss);
    printf("\n\t\t\t\t\tElected to: ");
    scanf("%s",&elect);
    fprintf(Currentmatch,"Toss Won By %s Team & Elected To %s\n",toss,elect);

    fclose(Currentmatch);
    printf("\n\t\t\t\t\tPress Enter To Continue....");
    getch();
    viewscoresheet();
}

void viewscoresheet()
{
    system("CLS");
    printf("\n\t\t\t\t\t***VIEW PLAYER PROFILE OF BOTH TEAM & TODAY'S MATCH INFO***\n");
    printf("\n\t\t\t\t\t1. For Batting Team Player's Profile\n");
    printf("\n\t\t\t\t\t2. For Bowling Team Player's Profile\n");
    printf("\n\t\t\t\t\t3. For Add Current Match Info\n");
    printf("\n\t\t\t\t\t4. For Back To Previous Menu\n");

    int su;
    printf("\n\t\t\t\t\tChoose your option: ");
    scanf("%d",&su);

   switch(su)
   {
       case 1:
           battingteam();
           break;
       case 2:
           bowlingteam();
           break;
       case 3:
           currentmatchinfo();
             break;
       case 4:
           controllerFunction();
             break;
    }
}
void addcurrent()
{
    system("CLS");
    system("COLOR 5F");
    printf("\n\t\t\t\t\t***ADD CURRENT MATCH INFO***\n");
    printf("\n\t\t\t\t\tEnter Strike & Non-Strike Batting Name\n");

    FILE *Nowbatting;
    Nowbatting = fopen("Nowbatting.txt", "a+");
    if(Nowbatting == NULL)
        {
            exit(1);
        }
    struct nowbatting1
    {
        char id[20];
        char name[20];
        int runs;
        int balls;

    }ba1;

    printf("\n\t\t\t\t\tOrder: ");
    scanf("%s",&ba1.id);
    printf("\n\t\t\t\t\tName: ");
    scanf("%s",&ba1.name);
    printf("\n\t\t\t\t\tRuns: ");
    scanf("%d",&ba1.runs);
    printf("\n\t\t\t\t\tBalls: ");
    scanf("%d",&ba1.balls);

    struct nowbatting2
    {
        char id[20];
        char name[20];
        int runs;
        int balls;

    }ba2 ;

    printf("\n\t\t\t\t\tOrder: ");
    scanf("%s",&ba2.id);
    printf("\n\t\t\t\t\tName: ");
    scanf("%s",&ba2.name);
    printf("\n\t\t\t\t\tRuns: ");
    scanf("%d",&ba2.runs);
    printf("\n\t\t\t\t\tBalls: ");
    scanf("%d",&ba2.balls);

    FILE *Nowbowling;
    Nowbowling = fopen("Nowbowling.txt", "a+");
    if(Nowbowling == NULL)
        {
            exit(1);
        }

    struct nowbowling1
    {
        char id[20];
        char name[20];
        int runs;
        int over;
    }bo1;

        printf("\n\t\t\t\t\tAdd Striker Bowling\n");
        printf("\n\t\t\t\t\tOrder: ");
        scanf("%s",bo1.id);
        printf("\n\t\t\t\t\tName: ");
        scanf("%s",&bo1.name);
        printf("\n\t\t\t\t\tRuns: ");
        scanf("%d",&bo1.runs);
        printf("\n\t\t\t\t\tOver: ");
        scanf("%d",&bo1.over);

    system("CLS");
    printf("\n\t\t\t\t\t***CURRENT OVER***\n");
    printf("\n\t\t\t\t\tRun Will Be Made By | 0 | 1 | 2 | 3 | 4 | 5 | 6 |\n");
    int first;
    int second;
    int third;
    int four;
    int five;
    int six;
    int sum=0;
    int sumb=0;
    int sums=0;

    printf("\n\t\t\t\t\tEnter 1st Ball Runs:\n\t\t\t\t\t");
    scanf("%d",&first);
    if(first==0)
    {
       ba1.runs=ba1.runs;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs;
    }
    else if(first==1)
    {
       ba1.runs=ba1.runs+1;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+1;
    }
    else if(first==2)
    {
       ba1.runs=ba1.runs+2;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+2;
    }
    else if(first==3)
    {
       ba1.runs=ba1.runs+3;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+3;
    }
    else if(first==4)
    {
       ba1.runs=ba1.runs+4;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+4;
    }
    else if(first==5)
    {
       ba1.runs=ba1.runs+5;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+5;
    }
    else if(first==6)
    {
       ba1.runs=ba1.runs+6;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+6;
    }

    printf("\n\t\t\t\t\tEnter 2nd Ball Runs:\n\t\t\t\t\t");
    scanf("%d",&second);
    if(second==0)
    {
       ba1.runs=ba1.runs;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs;
    }
    else if(second==1)
    {
       ba2.runs=ba2.runs+1;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+1;
    }
    else if(second==2)
    {
       ba1.runs=ba1.runs+2;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+2;

    }
    else if(second==3)
    {
       ba2.runs=ba2.runs+3;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+3;
    }
    else if(second==4)
    {
       ba1.runs=ba1.runs+4;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+4;
    }
    else if(second==5)
    {
       ba2.runs=ba2.runs+5;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+5;
    }
    else if(second==6)
    {
       ba1.runs=ba1.runs+6;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+6;
    }

    printf("\n\t\t\t\t\tEnter 3rd Ball Runs:\n\t\t\t\t\t");
    scanf("%d",&third);
    if(third==0)
    {
       ba1.runs=ba1.runs;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs;
    }
    else if(third==1)
    {
       ba2.runs=ba2.runs+1;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+1;
    }
    else if(third==2)
    {
       ba1.runs=ba1.runs+2;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+2;
    }
    else if(third==3)
    {
       ba2.runs=ba2.runs+3;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+3;
    }
    else if(third==4)
    {
       ba1.runs=ba1.runs+4;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+4;
    }
    else if(third==5)
    {
       ba2.runs=ba2.runs+5;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+5;
    }
    else if(third==6)
    {
       ba1.runs=ba1.runs+6;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+6;
    }

    printf("\n\t\t\t\t\tEnter 4th Ball Runs:\n\t\t\t\t\t");
    scanf("%d",&four);
    if(four==0)
    {
       ba1.runs=ba1.runs;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs;
    }
    else if(four==1)
    {
       ba2.runs=ba2.runs+1;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+1;
    }
    else if(four==2)
    {
       ba1.runs=ba1.runs+2;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+2;
    }
    else if(four==3)
    {
       ba2.runs=ba2.runs+3;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+3;
    }
    else if(four==4)
    {
       ba1.runs=ba1.runs+4;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+4;
    }
    else if(four==5)
    {
       ba2.runs=ba2.runs+5;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+5;
    }

    printf("\n\t\t\t\t\tEnter 5th Ball Runs:\n\t\t\t\t\t");
    scanf("%d",&five);

    if(five==0)
    {
       ba1.runs=ba1.runs;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs;
    }
    else if(five==1)
    {
       ba2.runs=ba2.runs+1;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+1;
    }
    else if(five==2)
    {
       ba1.runs=ba1.runs+2;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+2;
    }
    else if(five==3)
    {
       ba2.runs=ba2.runs+3;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+3;
    }
    else if(five==4)
    {
       ba1.runs=ba1.runs+4;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+4;
    }
    else if(five==5)
    {
       ba2.runs=ba2.runs+5;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+5;
    }
    else if(five==6)
    {
       ba1.runs=ba1.runs+6;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+6;
    }

    printf("\n\t\t\t\t\tEnter 6th Ball Runs:\n\t\t\t\t\t");
    scanf("%d",&six);

    if(six==0)
    {
       ba1.runs=ba1.runs;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs;
    }
    else if(six==1)
    {
       ba2.runs=ba2.runs+1;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+1;
    }
    else if(six==2)
    {
       ba1.runs=ba1.runs+2;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+2;
    }
    else if(six==3)
    {
       ba2.runs=ba2.runs+3;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+3;
    }
    else if(six==4)
    {
       ba1.runs=ba1.runs+4;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+4;
    }
    else if(six==5)
    {
       ba2.runs=ba2.runs+5;
       ba2.balls=ba2.balls+1;
       bo1.runs=bo1.runs+5;
    }
    else if(six==6)
    {
       ba1.runs=ba1.runs+6;
       ba1.balls=ba1.balls+1;
       bo1.runs=bo1.runs+6;
    }

    bo1.over=bo1.over+1;
    sum=sum+ba1.runs;
    sumb=sumb+ba2.runs;
    sums=sums+bo1.runs;

    fprintf(Nowbatting,"%s \t%s \t%d \t%d\n",ba1.id,ba1.name,sum,ba1.balls);
    fprintf(Nowbatting,"%s \t%s \t%d \t%d\n",ba2.id,ba2.name,sumb,ba2.balls);
    fprintf(Nowbowling,"%s \t%s \t%d \t%d \t%d\n",bo1.id,bo1.name,sums,bo1.over);

}
void viewlast()
{
    FILE *Nowbatting;
    char num[20];
    char name[20];
    char runs[20];
    char balls[20];

    system("CLS");
    Nowbatting = fopen("Nowbatting.txt", "r+");
    printf("\n\t\t\t\t\t***BANGLADESH***\n");
    printf("\nORDER:\tNAME:\t\tRUNS:\tBalls:");
    while(fscanf(Nowbatting,"%s %s %s %s\n",num,name,runs,balls)!=EOF)
      {
        printf("\n%s\t%s\t\t%s\t%s\t",num,name,runs,balls);
      }

      getch();

     system("CLS");
     FILE *Nowbowling;
     char order[20];
     char boname[20];
     char boruns[20];
     char over[20];

     Nowbowling = fopen("Nowbowling.txt", "r+");
     printf("\n\t\t\t\t\t***AUSTRALIA***\n");
     printf("\nORDER:\tNAME:\t\tRUNS:\tOVER:");
     while(fscanf(Nowbowling,"%s %s %s %s %s\n",order,boname,boruns,over)!=EOF)
       {
          printf("\n%s\t%s\t\t%s\t%s",order,boname,boruns,over);
       }

      getch();
      currentmatchinfo();
}
void battingteam()
{
    system("CLS");
    system("COLOR 2F");
    printf("\n\t\t\t\t\t***BANGLADESH TEAM PLAYER'S LIST & PROFILE***\n");

    FILE *Battingteam;
    char num[20];
    char name[20];
    char matches[20];
    char age[20];
    char runs[20];
    char wickets[20];
    Battingteam = fopen("Battingteam.txt", "r+");
    printf("\nORDER:\tNAME:\t\tAGE:\tMATCHES:\tRUNS:\tWICKETS:");
    while(fscanf(Battingteam,"%s %s %s %s %s %s\n",num,name,matches,age,runs,wickets)!=EOF)
      {
        printf("\n%s\t%s\t\t%s\t%s\t\t%s\t%s",num,name,matches,age,runs,wickets);
      }

      getch();
      viewscoresheet();
}

void bowlingteam()
{
    system("COLOR 2F");
    system("CLS");
    printf("\n\t\t\t\t\t***AUSTRALIA TEAM PLAYER'S LIST & PROFILE***\n");

    FILE *Bowlingteam;
    char num[20];
    char name[20];
    char matches[20];
    char age[20];
    char runs[20];
    char wickets[20];
    Bowlingteam = fopen("Bowlingteam.txt", "r+");
    printf("\nORDER:\tNAME:\tMATCHES:\tRUNS:\tWICKETS:");
    while(fscanf(Bowlingteam,"%s %s %s %s %s %s\n",num,name,matches,age,runs,wickets)!=EOF)
       {
       printf("\n%s\t%s\t%s\t%s\t%s\t%s",num,name,matches,age,runs,wickets);
       }

       getch();
       viewscoresheet();
}

void currentmatch()
{
    system("CLS");
    system("COLOR 2F");
    printf("\n\t\t\t\t\t***VIEW TODAY'S MATCH SCORESHEET***\n");
    printf("\n\t\t\t\t\t***BANGLADESH TEAM***\n");

    FILE *Totalrun;
    char total[20];
    Totalrun = fopen("Totalrun.txt", "r+");
    while(fscanf(Totalrun,"%s\n",total)!=EOF)
      {
        printf("\nBangladesh: %s\n",total);
      }

      getch();

    FILE *Totalrunsba;
    char num[20];
    char name[20];
    char runs[20];
    char balls[20];

    Totalrunsba = fopen("Totalrunsba.txt", "r+");
    printf("\nORDER\tNAME\t\tRUNS\tBALLS");
    while(fscanf(Totalrunsba,"%s %s %s %s\n",num,name,runs,balls)!=EOF)
      {
        printf("\n%s\t%s\t\t%s\t%s\t",num,name,runs,balls);
      }

      getch();

     FILE *Totalrunsbo;
     char order[20];
     char boname[20];
     char boruns[20];
     char wiecket[20];
     char over[20];

     Totalrunsbo = fopen("Totalrunsbo.txt", "r+");
     printf("\n\t\t\t\t\t***AUSTRALIA***\n");
     printf("\nORDER\tNAME\t\tRUNS\tWICKET\tOVER");
     while(fscanf(Totalrunsbo,"%s %s %s %s %s\n",order,boname,boruns,wiecket,over)!=EOF)
       {
          printf("\n%s\t%s\t\t%s\t%s\t%s",order,boname,boruns,wiecket,over);
       }

      getch();
      controllerFunction();
}
