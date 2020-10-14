#include<stdio.h>                               // Adding Libraries.
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define ll long long int

int password()
{
    char pass[15]={0};                          // For taking i/p (password) from User for verification Purpose.
    char check[15]={0};                         // For fetching Original Password From the Binary File Store in the Disk.
    char ch;
    
    printf("PLEASE! ENTER THE PASSWORD\n");
    printf("ONLY 3 CHANCES WILL BE GIVEN\n");
    
    for(int i=0;i<=2;i++)                       // Loop Run 3 Times(Maximum).
    {
        int j=0;
        printf("\n\n\nEnter the Password->");
        
        pass[0]=getch();                        // Main purpose is to Check, There is no Carriage Return (Enter) will be given by the user.
        while(pass[j]!='\r')                    // Checking Carriage Return.
        {
            if(pass[j]=='\b')                   // -->> Removes the Problem of removal of (*) from Screen while Typing the Password and enter backspace, then now with that the (*) all removed.
            {
                j--;
                printf("\b");                   // Backspace(For moving one Step Back).
                printf(" ");                    // Replace the * with Blank Space.
                printf("\b");                   // Then again, move One Step Back, & now we can move further (PROBLEM SOLVED).
                pass[j]=getch();                // Most Impotant Concept -->> To take cursor one step back and ready to take continious Input.
            }
            else
            {
                printf("*");                    // Shows like that we Enter Password on the Screen in the HIDDEN i.e (*) Format.
                j++;
                pass[j]=getch();                // Storing Pasword from User Side For Comparision Purpose.
            }
        }
        pass[j]='\0';                           // Adding NULL at the Last helps to Check Termination point of the Array Input i.e. (String).
        
        FILE *fp;                          // file pointer to the password file.
        fp = fopen("password","r");
        if(fp==NULL)
        {
            printf("[FILE MISSING]");
            getch();
            return 1;
        }
        else
        {
            j=0;
            while(1)
            {
                ch=fgetc(fp);
                if(ch==EOF)
                {
                    check[i]='\0';         // Make Null character at the last to convert into string
                    break;
                }
                check[j]=ch-5;
                j++;
            }
            if(strcmp(pass,check)==0)
            {
                printf("ACCESS GRANTED \n");
                return 0;
            }
            else
            {
                printf("WRONG PASSWORD \n");
            }
        }
        fclose(fp);
    }
    printf("YOU ARE NOT ALLOWED TO ENTER");
    getch();
    return 1;
}

























void edit_password()
{
    system("cls");                                                 // Clear the Screen.
    
    char pass[15]={0}, check[15]={0};
    int match;
    
    printf("\n\n");    
    FILE *fp;                                                       // File Pointer to password file
    fp=fopen("password","rb");                                      // Read Binary Mode
    if(fp==NULL)
    {
        fp=fopen("password","wb"); 
        if(fp==NULL)                                                // Write Binary Mode
        {
            printf("SYSTEM ISSUE -_-");
            getch();
            return ;
        }
        fclose(fp);
        printf("\nYOUR PASSWORD IS 'ENTER'\n PRESS ENTER TO CHANGE PASSWORD\n\n");   
        getch();
    }
    fclose(fp);
    match=password();
    if(match==1)
    {
        return;
    }
    do
    {
        if(match==0)
        {
            printf("Enter the NEW password -> ");
            fflush(stdin);
        }
    }
}



































int main()
{
    int option;
    printf("\n\n\t\t\t#############################################################");                                                                      // For Design Purpose Only.
    printf("\n\t\t\t#\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t#\n\t\t\t# \t\t\t   PASSWORD PROTECTED PERSONAL DIARY\t\t\t#");
    printf("\n\t\t\t#\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t#\n\t\t\t# \t\t\t\t       (ALEX_SALONI_SUNNY) \t\t\t\t\t#\n\t\t\t#\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t#\n");
    printf("\t\t\t#############################################################");
    
    
    while(1)
    {
        printf("\n\n\n\t\t\t{ MAIN MENU }\t { OPTION }");
        printf("\n\n\t\t\tADD RECORD\t\t\t[1]");
        printf("\n\t\t\tVIEW RECORD\t\t\t[2]");
        printf("\n\t\t\tDELETE RECORD\t\t[3]");
        printf("\n\t\t\tEDIT PASSWORD\t\t[4]");
        printf("\n\t\t\tEXIT\t\t\t\t[5]");
        printf("\n\n\t\t\tPlease! Enter the Option :");
        scanf("%d",&option);
        
        switch(option)
        {
            case 1:
                add_record();
                break; 
            case 2:
                view_record();
                break;
            case 3:
                delete_record();
                break;
            case 4:
                edit_password();
                break;
            case 5:
                printf("THANK YOU");
                getch();
                break;
        }
        system("cls");
    }
    return 0;
}
