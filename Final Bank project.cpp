#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <math.h>

void checkbalance(char *);
void transfermoney(void);
void display(char *);
void person(char *);
void login(void);
void loginsu(void);
void account(void);
void accountcreated(void);
void afterlogin(void);
void logout(void);

int date, month, year;
long long int adharnumber, pnumber;
char fname[20], lname[20], fathname[20], mothname[20], address[50], typeaccount[20], username[50], password[50], userameto[50], userpersonfrom[50];
long int money1=10000;

void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int main()
{
    int i, a, b, choice;
    int passwordlength;

    gotoxy(20, 3);
    printf("WELCOME TO BANK ACCOUNT SYSTEM\n\n");
    gotoxy(18, 5);

    printf("**********************************");
    gotoxy(25, 7);

    printf("DEVELOPER-SAGNIK PAL");

    gotoxy(20, 10);
    printf("1.... CREATE A BANK ACCOUNT");

    gotoxy(20, 12);
    printf("2.... ALREADY A USER? SIGN IN");
    gotoxy(20, 14);
    printf("3.... EXIT\n\n");

    printf("\n\nENTER YOUR CHOICE..");

    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        system("cls");
        printf("\n\n USERNAME 50 CHARACTERS MAX!!");
        printf("\n\n PASSWORD 50 CHARACTERS MAX!!");
        account();
        break;

    case 2:
        login();
        break;

    case 3:
        exit(0);
        break;

        getch();
    }
}

void account(void)
{
    // int date, month, year, pnumber, adharnumber;
    int count;
    long long int i, adharNum, phoneNum;
    char ch;
    system("cls");
    printf("\n\n!!!!!!!!CREATE ACCOUNT!!!!!!!");
	
	
    printf("\n\nFIRST NAME..");
    scanf("%s", &fname);
    fflush(stdin);

    printf("\n\nLAST NAME..");
    scanf("%s", &lname);
    fflush(stdin);

    printf("\n\nFATHER'S NAME..");
    scanf("%s", &fathname);
    fflush(stdin);

    printf("\n\nMOTHER's NAME..");
    scanf("%s", &mothname);
    fflush(stdin);

    printf("\n\nADDRESS..");
    scanf("%s", &address);
    fflush(stdin);

    // Account Type
    while (1)
    {
        printf("\n\nACCOUNT TYPE (Savings or Current)..");
        scanf("%s", &typeaccount);
        fflush(stdin);
        if ((strcmp(typeaccount, "Savings") == 0) || (strcmp(typeaccount, "Current") == 0))
        {
            printf("\n");
            break;
        }
        else
        {
            printf("Wrong Account type Entered!!!\n");
            printf("Re Enter the Correct account type!!\n");
            continue;
        }
    }

    // DOB
    while (1)
    {
        printf("\n\nDATE OF BIRTH..");
        printf("\nDATE-");
        scanf("%d", &date);
        fflush(stdin);
        printf("\nMONTH-");
        scanf("%d", &month);
        fflush(stdin);
        printf("\nYEAR-");
        scanf("%d", &year);
        fflush(stdin);

        if ((date >= 1 && date <= 31) && (month >= 1 && month <= 12) && (year >= 1770 && year <= 2023))
        {
            printf("\n");
            break;
        }
        else
        {
            printf("Wrong Date of Birth Entered!!!\n");
            printf("Re Enter the Date of Birth!!\n");
            continue;
        }
    }

    // Aadhar Number
    while (1)
    {
        printf("\n\nADHAR NUMBER..");
        scanf("%lld", &adharNum);
        i = adharNum;
        count = 0;
        while (i > 0)
        {
            count++;
            i /= 10;
        }
        // check digits
        if (count == 12)
        {
            printf("\n");
            adharnumber = adharNum;
            break;
        }
        else
        {
            printf("Please Enter Correct Aadhar Number.\n");
            printf("Re Enter the Aadhar Number!!\n");
            continue;
        }
    }

    // Phone Number
    while (1)
    {
        printf("\n\nPHONE NUMBER..");
        scanf("%lld", &phoneNum);
        i = phoneNum;
        count = 0;
        while (i > 0)
        {
            count++;
            i /= 10;
        }
        if (count == 10)
        {
            printf("\n");
            pnumber = phoneNum;
            break;
        }
        else
        {
            printf("Please Enter Correct Phone Number.\n");
            printf("Re Enter the Phone Number!!\n");
            continue;
        }
    }
	
    printf("\n\nUSERNAME.. ");
    scanf("%s", &username);
    fflush(stdin);

    printf("\n\nPASSWORD..");
    for (i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            password[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else if (ch == 8)
        {
            password[i - 1] = '\0';
            i -= 2;
        }
        else
            break;
    }
    fflush(stdin);

    accountcreated();
}

void accountcreated(void)
{
    int i;
    char ch;
    system("cls");
    printf(
        "PLEASE WAIT....\n\nYOUR DATA IS PROCESSING....");
    for (i = 0; i < 200000000; i++)
    {
        i++;
        i--;
    }

    gotoxy(30, 10);

    printf("ACCOUNT CREATED SUCCESSFULLY....");
    gotoxy(0, 20);

    printf("Press enter to login");

    getch();
    login();
}

void login(void)
{
    system("cls");

    char username2[50];
    char password2[50];
    int i;
    char ch;

    gotoxy(34, 2);
    printf(" ACCOUNT LOGIN ");
    gotoxy(7, 5);
    printf("***********************************************"
           "********************************");

    gotoxy(35, 10);
    printf("==== LOG IN ====");

    gotoxy(35, 12);
    printf("USERNAME.. ");
    scanf("%s", &username2);
    fflush(stdin);

    gotoxy(35, 14);
    printf("PASSWORD..");
    for (i = 0; i < 50; i++)
    {
        ch = getch();
        if (ch != 13 && ch != 8)
        {
            password2[i] = ch;
            ch = '*';
            printf("%c", ch);
        }
        else if (ch == 8)
        {
            password2[i - 1] = '\0';
            i -= 2;
        }
        else
            break;
    }
    if ((strcmp(username, username2)==0) && (strcmp(password, password2)==0))
    {
        loginsu();
        display(username2);
        return;
    }
    else
    {
        printf("\n\nWrong username and password.");
        printf("\nPlease try again.......");
        login();
    }
}

void loginsu(void)
{
    int i;
    system("cls");
    printf("Fetching account details.....\n");
    for (i = 0; i < 20000; i++)
    {
        i++;
        i--;
    }

    gotoxy(30, 10);
    printf("LOGIN SUCCESSFUL....");
    gotoxy(0, 20);
    printf("Press enter to continue");

    getch();
}

void display(char username1[])
{
    system("cls");
    int choice, i;

    gotoxy(30, 1);
    printf("WELCOME, %s %s", fname, lname);
    gotoxy(28, 2);
    printf("..........................");
    gotoxy(55, 6);
    printf("==== YOUR ACCOUNT INFO ====");
    gotoxy(55, 8);
    printf("***************************");
    gotoxy(55, 10);
    printf("NAME..%s %s", fname, lname);

    gotoxy(55, 12);
    printf("FATHER's NAME..%s %s", fathname, lname);

    gotoxy(55, 14);
    printf("MOTHER's NAME..%s %s", mothname,lname);

    gotoxy(55, 16);
    printf("ADHAR CARD NUMBER..%lld", adharnumber);

    gotoxy(55, 18);
    printf("MOBILE NUMBER..%lld", pnumber);

    gotoxy(55, 20);
    printf("DATE OF BIRTH.. %d-%d-%d", date, month, year);

    gotoxy(55, 22);
    printf("ADDRESS..%s", address);

    gotoxy(55, 24);
    printf("ACCOUNT TYPE..%s", typeaccount);

    gotoxy(0, 6);
    printf(" HOME ");
    gotoxy(0, 7);
    printf("******");
    gotoxy(0, 9);
    printf(" 1....CHECK BALANCE");
    gotoxy(0, 11);
    printf(" 2....TRANSFER MONEY");
    gotoxy(0, 13);
    printf(" 3....LOG OUT\n\n");
    gotoxy(0, 15);
    printf(" 4....EXIT\n\n");

    printf(" ENTER YOUR CHOICES..");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        checkbalance(username1);
        break;

    case 2:
        transfermoney();
        break;

    case 3:
        logout();
        login();
        break;

    case 4:
        exit(0);
        break;
    }
}

void checkbalance(char username3[])
{
    system("cls");
    char ch;
    int i = 1, summoney = 10000;

    int k = 5, l = 10;
    int m = 30, n = 10;
    int u = 60, v = 10;

    gotoxy(30, 2);
    printf("==== BALANCE DASHBOARD ====");
    gotoxy(30, 3);
    printf("***************************");
    gotoxy(k, l);
    printf("S no.");
    gotoxy(m, n);
    printf("TRANSACTION ID");
    gotoxy(u, v);
    printf("AMOUNT");

    gotoxy(k, ++l);
    printf("%d", i);
    i++;
    gotoxy(m, ++n);
    printf("%s", userpersonfrom);

    gotoxy(u, ++v);
    printf("%d", money1);
    summoney = summoney + money1;

    gotoxy(80, 10);
    printf("TOTAL AMOUNT");

    gotoxy(80, 12);
    printf("%d", summoney);

    getch();

    display(username3);
}
void transfermoney(void)
{
    int i, j;
    char usernamet[20];
    char usernamep[20];
    system("cls");

    gotoxy(33, 4);
    printf("---- TRANSFER MONEY ----");
    gotoxy(33, 5);
    printf("========================");

    gotoxy(33, 11);
    printf("FROM (your username).. ");
    scanf("%s", &usernamet);
    fflush(stdin);

    gotoxy(33, 13);
    printf(" TO (username of person)..");
    scanf("%s", &usernamep);
    fflush(stdin);

    strcpy(userameto, username);
    strcpy(userpersonfrom, usernamet);

    gotoxy(33, 16);

    printf("ENTER THE AMOUNT TO BE TRANSFERRED..");
    scanf("%d", &money1);
    fflush(stdin);

    gotoxy(0, 26);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    gotoxy(0, 28);
    printf(
        "--------------------------------------------------"
        "--------------------------------------------");

    gotoxy(0, 29);
    printf("transferring amount, Please wait..");

    gotoxy(10, 27);
    for (i = 0; i < 70; i++)
    {
        for (j = 0; j < 1200000; j++)
        {
            j++;
            j--;
        }
        printf("*");
    }

    gotoxy(33, 40);
    printf("AMOUNT SUCCESSFULLY TRANSFERRED....");
    getch();

    display(usernamet);
}

void logout(void)
{
    int i, j;
    system("cls");
    printf("please wait, logging out");

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 25000000; j++)
        {
            i++;
            i--;
        }
        printf(".");
    }

    gotoxy(30, 10);
    printf("Sign out successfully..\n");

    gotoxy(0, 20);
    printf("press any key to continue..");

    getch();
}
