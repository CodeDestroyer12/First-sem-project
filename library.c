#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

//defining the properties of the fields used in the program


#define IN 1
#define OUT 0

int time();
void lay2();
void rectangle(int x,int y,int l,int b);
int login();

void lay2();
int menu();

void adddel();
void adddelmem();
void search();
void bookret();
void Exit();


void Addbook();
void modifyb();
void delbook();

void Searchbook();
void Displaybook();
void Author();
void Titlelist();
void memname();


void Issue();

void Addmembr();
void delmembr();
void modmembr();


char info[500];



void gotoxy(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }




struct bookrec
{
  int bid;
  char bname[25] ;
  char author[25];
  int nooftitles;
  char titles[100];
  int status;
};
struct memrec
{
  int mid;
  char mname[25] ;
  char department[25];
  int availibcard;
  int phno;

};


//initializing the files used in the program


FILE *temp1;
FILE *temp2;

int main(){
    login();
    
    return 0;
}

void lay2(){
    int i;

    system("clear");
    
system("COLOR 1B");

gotoxy(0,0);
// for horizontal line right at the uppermost part of the screen
for(i=0;i<168;i++){
    printf("%c",205);
}
gotoxy(0,0);// for vertical line just from the beginning.
for(i=0;i<80;i++){
    printf("%c",186);
    printf("\n");
}
gotoxy(1,1);
printf("Logged in As :Library Staff");
time();
rectangle(60,0,120,6);
gotoxy(74,1);
printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n");

gotoxy(0,2);//line after the printing of library management system
for(i=0;i<168;i++){
    printf("%c",205);
}
gotoxy(73,1);
    printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n");
    gotoxy(75,3);
    printf("Madan Bhandari Memorial College");
    gotoxy(81,5);
    printf("Anamnagar,Kathmandu");
     //Top line
    for(i=25;i<125;i++){
        gotoxy(i,9);
        printf("%c",178);
    }
    
    
    gotoxy(45,11);
    printf("Menu");
    

    //2nd Top line
    for(i=25;i<125;i++){
        gotoxy(i,12);
        printf("%c",178);
    }
    
    //right line
    for(i=8;i<38;i++){
        gotoxy(124,1+i);
        printf("%c\n",178);
    }
    
    //Left line
    for(i=8;i<38 ;i++){
    gotoxy(25,1+i);
    printf("%c",178);
    }
        //upper Bottom line
    for(i=25;i<125;i++){
        gotoxy(i,35);
        printf("%c",178);
    }
    
    //bottom line
    for(i=25;i<125;i++){
        gotoxy(i,38);
        printf("%c",178);
    }   

        //middle line
    for(i=11;i<35;i++){
    gotoxy(60,1+i);
    printf("%c",178);
    }
}

int login(){
    system("cls");
    

int i=0;
char name[20];
char ch;
char password[10];
//horizontial line of top
system("cls");
system("COLOR 1B");

gotoxy(0,0);
// for horizontal line right at the uppermost part of the screen
for(i=0;i<168;i++){
    printf("%c",205);
}
gotoxy(0,0);// for vertical line just from the beginning.
for(i=0;i<80;i++){
    printf("%c",186);
    printf("\n");
}

//time();
rectangle(60,0,120,6);
gotoxy(74,1);
printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n");

gotoxy(0,2);//line after the printing of library management system
for(i=0;i<168;i++){
    printf("%c",205);
}
rectangle(60,10,120,24);
gotoxy(73,1);
    printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n\n");
    gotoxy(75,3);
    printf("Madan Bhandari Memorial College");
    gotoxy(81,5);
    printf("Anamnagar,Kathmandu");
gotoxy(80,15);
printf("SYSTEM LOGIN\n\n");
gotoxy(65,14);// line before printing of system login
for(i=0;i<50;i++){
    printf("%c",205);
}


gotoxy(65,16);// line after printing of system login
for(i=0;i<50;i++){
    printf("%c",205);
}

gotoxy(80,19);
printf("Username: ");
gets(name);
gotoxy(80,20);
printf("Password: ");
while(1){
    ch=getch();

    if(ch==13){
        password[i]='\0';
        break;
        }

    else if(ch==8){
        if(i>0){
            i--;
            printf("\b \b");
            }
    }

    else if(ch==9 || ch==32){
        continue ;
    }

    else{
        password[i]=ch;
        i++;
        printf("*");
    }
}
gets(password);
if (strcmp(name,"admin") == 0 || strcmp(password,"admin") == 0){
    printf("Access granted \n");
    system("cls");
    gotoxy(1,1);
    printf("Logged in As :Library Staff");
    char sname[20];
    for(i=0;i<168;i++){
        printf("%c",205);
    }

    gotoxy(0,2);
    for(i=0;i<168;i++){
        printf("%c",205);
    }

    gotoxy(75,1);
    printf("LIBRARY MANAGEMENT SYSTEM\n\n");
    gotoxy(0,2);//line after the printing of library management system
    for(i=0;i<168;i++){
        printf("%c",205);
    }
    //gotoxy(75,19);
    menu();
    
    }
else{
 gotoxy(80,30);
 printf("Access denied\n");
 gotoxy(80,31);
 printf("Do you want to try again (Y/N) ?");
 gotoxy(80,32);
    char typee = getch();
    //printf("%c\n", typee);
    if(typee=='Y'){
        system("cls");
        login();
    }
    else{
        if(typee=='N'){
        gotoxy(80,33);
        printf("Enter a Right Choice Or press e to exit \n");
        char qq = getch();
        if(qq=='e'){
            system("cls");
            exit(0);
        }
    }
        //main();
    }
 //login();
 
}

return 0;
}



void rectangle(int x,int y,int l,int b)
{
    int i,m;
    gotoxy(x,y); printf("%c",201);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,y);
        printf("%c",205);
    }
    gotoxy(i,y); printf("%c",187);

    for (m=y+1;m<b;m++)
    {
        gotoxy(x,m);
        for(i=x;i<l;i++)
        {
            if(i==x||i==l-1)
            {
                gotoxy(i,m); printf("%c",186);
            }

        }

    }

    gotoxy(x,m); printf("%c",200);
    for(i=x+1;i<l-1;i++)
    {
        gotoxy(i,m);
        printf("%c",205);
    }
    gotoxy(i,m);
     printf("%c",188);
}


int menu()
{       
    int choice=0;

    
    system("cls");
    lay2();
    do{
    gotoxy(1,1);
    printf("Logged in As :Library Staff");
    gotoxy(26,14);       
    printf("1>Add A New Book/delete book");
    gotoxy(26,17);
    printf("2>Add member/delete member");
    gotoxy(26,20);
    printf("3>Search");
    gotoxy(26,23);
    printf("4>Return a book");
    gotoxy(26,26);
    printf("5>Book issue");
    gotoxy(26,29);
    printf("6>Exit");
    gotoxy(26,37);
    printf("Enter Your Choice:");
    
    scanf("%d",&choice);

      
    switch (choice)
    {   
        case 1:
            adddel();
            break;
        case 2:
            adddelmem();
            break;
        case 3:
            search();
            break;
        case 4:
            bookret();
            break;
        case 5:
            Issue();
            break;
        case 6:
            Exit();    
        default:
        gotoxy(26,36);
            printf(" ! Invalid Input...\n");
    }
}while(choice!=6);
 return 0;
}



void adddel()
{
    int z;
    system("cls");
    lay2();
    do{
    gotoxy(26,14);
    printf("1>Add Books");
    gotoxy(26,18);
    printf("2>Delete Books");
    gotoxy(26,22);
    printf("3>Modify Records");
    gotoxy(26,26);
    printf("4>Back");
    gotoxy(26,37);
    printf("Enter Your Choice:");
    scanf("%d",&z);
    switch(z){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
        case 1:
        Addbook();
        break;

        case 2:
        delbook();
        break;

        case 3:
        modifyb();
        break;

        case 4:
        menu();
        break;
        
        default:
        gotoxy(26,36);
        printf("Invalid selection!!");
    }
    }while(z!=4);

    
}



void adddelmem(){
    int z;
    system("cls");
    lay2();
    do{
    gotoxy(26,14);
    printf("1>Add Member");
    gotoxy(26,18);
    printf("2>Delete Member");
    gotoxy(26,22);
    printf("3>Modify Member");
    gotoxy(26,26);
    printf("4>Back");
    gotoxy(26,37);
    printf("Enter Your Choice:");
    scanf("%d",&z);
    switch(z){
        case 1:
        Addmembr();
        break;

        case 2:
        delmembr();
        break;

        case 3:
        modmembr();
        break;

        case 4:
        menu();
        break;

        default:
        gotoxy(26,36);
        printf("Invalid input!!");
    }
    }while(z!=4);
    

}



void search(){
    int y;
    system("cls");
    lay2();
    do{
    gotoxy(26,14);
    printf("1>Display all Records");
    gotoxy(26,17);
    printf("2>Search book");
    gotoxy(26,20);
    printf("3>Category");
    gotoxy(26,23);
    printf("4>Auther");
    gotoxy(26,26);
    printf("5>Search Member");
    gotoxy(26,29);
    printf("6>Back");
    gotoxy(26,37);
    printf("Enter Your Choice:");
    scanf("%d",&y);
    switch(y){
        case 1:
            Displaybook();
            break;
        case 2:
            Searchbook();
            break;
        case 3:
            Titlelist();
            break;
        case 4:
            Author();
            break;
        case 5:
            memname();
            break;

        case 6:
            menu();
            break;
        default:
           gotoxy(26,36);
            printf("Invalid input!!");

            }

        }while(y!=6);
    
}



void Addbook()
{
    int i;
    int a;
    struct bookrec book;
    book.status=IN;
    FILE *librecord;
    
    system("cls");

            //opening the librecord file
            librecord = fopen("librecord.txt","ab");
    lay2();
    gotoxy(61,13);
    printf("Enter The uniqueid of The Book :(Integer) ");
        scanf("%d",&a);
         book.bid = a;
    gotoxy(61,15);
    printf("Enter The Category of The Book :");
        scanf("%s",book.bname);
    gotoxy(61,17);
    printf("Enter The Name of Author :");
        scanf("%s",book.author);
    gotoxy(61,19);  
    printf("Enter The Number of Books:(Integer)");
        scanf("%d",&book.nooftitles);
    gotoxy(61,21);
    printf("Enter the title of book:");
        scanf("%s",book.titles);
 
     
    fwrite(&book,sizeof(book),1,librecord);
   
   
    fclose(librecord);
    gotoxy(26,36);
    printf("A New Book has been Added Successfully...\n");


}



void delbook(){
 int r, s;
 FILE *librecord;
 FILE *fp3;
 struct bookrec book;
 system("cls");
 lay2();
 gotoxy(61,13);
 printf("Enter the book id you want to delete :");
 scanf("%d", &r);
 
 
  librecord = fopen("librecord.txt", "rb");
  fp3 = fopen("TempFile", "wb");
  while (fread(&book, sizeof(book), 1, librecord))
  {
   s = book.bid;
   if (s != r){
    fwrite(&book, sizeof(book), 1, fp3);}
  }
  fclose(librecord);
  fclose(fp3);
  librecord = fopen("librecord.txt", "wb");
  fp3 = fopen("TempFile", "rb");
  while (fread(&book, sizeof(book), 1, fp3)){
   fwrite(&book, sizeof(book), 1, librecord);}
  gotoxy(26,36);
  printf("RECORD DELETED");
  fclose(librecord);
  fclose(fp3);
}



void modifyb(){
    FILE *librecord;
    FILE *fp3;
    struct bookrec book;
 int avl;
 int s, r, ch;
 system("cls");
 lay2();
 gotoxy(61,13);
 printf("Enter book id to update:");
 scanf("%d", &r);
 

  librecord = fopen("librecord.txt", "rb");
  fp3 = fopen("TempFile", "w");
  while (fread(&book, sizeof(book), 1, librecord))
  {
   s = book.bid;
   if (s != r)
    fwrite(&book, sizeof(book), 1, fp3);
   else
   {
    gotoxy(26,14);
    printf("1>ID" );
    gotoxy(26,17);
    printf("2>Name" );
    gotoxy(26,21);
    printf("3>Auther" );
    gotoxy(26,24);
    printf("4>No fo titles:");
    gotoxy(26,27);
    printf("5>Back");
    gotoxy(26,37);
    printf("Enter your choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     gotoxy(61,13);
     printf("Enter New ID:");
     scanf("%d", &book.bid);
     break;
    case 2:
     gotoxy(61,13);
     printf("Enter New Name : ");
     scanf("%s", book.bname);
     break;
    case 3:
     gotoxy(61,13);
     printf("Enter New Auther: ");
     scanf("%s", book.author);
     break;
    case 4:
    gotoxy(61,13);
     printf("Enter New no.: ");
     scanf("%d", &book.nooftitles);
     break;
     case 5:
     modifyb();
     break;
    default:
    gotoxy(26,36);
     printf("Invalid Selection");
     break;
    }
    fwrite(&book, sizeof(book), 1, fp3);
   }
  }
  fclose(librecord);
  fclose(fp3);
  librecord = fopen("Record", "wb");
  fp3 = fopen("TempFile", "rb");
  while (fread(&book, sizeof(book), 1, fp3))
  {
   fwrite(&book, sizeof(book), 1, librecord);
  }
  fclose(librecord);
  fclose(fp3);
  gotoxy(26,36);
  printf("RECORD UPDATED");
 }






void Displaybook()
{
    int i=14,j;
    FILE *librecord;
    FILE *membrrecord;
    struct bookrec book;
    struct memrec membr;
    system("cls");
    lay2();
    librecord = fopen("librecord.txt","rb");
    gotoxy(61,13);
    printf("Bookid\tCategory\tAuthor\tStatus\tNo.\tTitles");
    
    while(fread(&book,sizeof(book),1,librecord)){   
    gotoxy(61,i);
    printf("%d\t\t%s\t\t%s\t%d\t%d\t%s",book.bid,book.bname,book.author,book.status,book.nooftitles,book.titles);
    i++;
}

    fclose(librecord);
    j=i+3;
    membrrecord = fopen("membrrecord.txt","rb");
    gotoxy(61,i+2);
    printf("Mid\tName\tDept\tPh.no\t\tAvailablecards");
   /*do
    {
        fgets(info,500,membrrecord);
        printf("%s\n",info);
    }while(!feof(membrrecord));*/
    while(fread(&membr,sizeof(membr),1,membrrecord)){
        gotoxy(61,j);
        printf("%d\t%s\t%s\t%d\t\t%d",membr.mid,membr.mname,membr.department,membr.phno,membr.availibcard);
        j++;
    }    
    fclose(membrrecord);

}


void Searchbook()
{
    int i;
    char Target[25],stats[3];
    int Found=0;
    FILE *librecord;
    struct bookrec book;
    system("cls");
    lay2();
    
    if((librecord=fopen("librecord.txt","rb"))==NULL)
        printf(" ! The File is Empty...\n\n");
    else
    {
        gotoxy(61,13);
        printf("Enter The Titles Of Book : ");
            scanf("%s",Target);
            rewind(librecord);
        while(!feof(librecord))
        {
        fread(&book,sizeof(book),1,librecord);
            if(strcmp(Target,book.titles)==0)
                Found=1;
                break;
           
        }
        if(Found)
        {
            if(book.status==IN)
                strcpy(stats,"IN");
            else
                strcpy(stats,"OUT");
            gotoxy(61,14);
            printf("The Unique ID of The Book:  %d",book.bid);
            gotoxy(61,15);
            printf("The Name of Book is:  %s",book.titles);
            gotoxy(61,16);
            printf("The Author is:  %s",book.author);
            gotoxy(61,17);
            printf("The Book Status:%s",stats);
            }
        else(!Found);
            gotoxy(26,36);
            printf("! There is no such Entry...\n");
            
        fclose(librecord);
    }

}



void Author()
{
    int i,j=16;   
    char Target[500];
    int Found=0;
    FILE *librecord;
    struct bookrec book;
    system("cls");
    lay2();
    if((librecord=fopen("librecord.txt","rb"))==NULL)
    printf(" ! The file is empty... \n\n");
    else
    {
        gotoxy(61,13);
        printf("Enter The Name Of Author : ");
            scanf("%s",Target);
        gotoxy(61,15);  
        printf("Books:");
        while(!feof(librecord))
        {
            fread(&book,sizeof(book),1,librecord);
            if(strcmp(Target,book.author)==0)
            {
                Found++;
                gotoxy(61,j);
                printf("%s",book.titles);
                j++;
            }
        
        }
        if(Found==0){
            gotoxy(26,36);
            printf(" ! There is no such Entry...\n");
        }
        fclose(librecord);
    }

}




void Titlelist()
{
    int i=0,j=16;
    FILE *librecord;
    char Target[500];
    int Found=0;
    struct bookrec book;
    system("cls");
    lay2();
    if((librecord=fopen("librecord.txt","rb"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        gotoxy(61,13);
        printf("Enter The Category of Book :");
        scanf("%s",Target);
        while(!feof(librecord))
        {
            fread(&book,sizeof(book),1,librecord);
            Found=0;
            if(strcmp(Target,book.bname)==0)
                {
                    Found=1;
                }
             if(Found){
                gotoxy(61,j);
                printf("%d.%s",i+1,book.titles);
                i++;
                j++;    
             }   
            
        }
        /*if(Found)
        {
            //printf("The Name of book is:               %s\n",book.bname);
            gotoxy(61,15);
            printf("The Titles:");
            for(i=0;i<book.nooftitles;i++)
            {
                
                fscanf(librecord,"%s",book.titles);
                gotoxy(61,j);
                printf("%d.%s......\n",i+1,book.titles);
                j++;
            }
        }*/

        if(!Found);
            gotoxy(26,36);
            printf(" ! There is no such Entry...\n");
        fclose(librecord);
    }

}

void memname(){ 
    int i;
    char Target[25];
    int Found=0;
    FILE *membrrecord;
    struct memrec membr;
    system("cls");
    if((membrrecord=fopen("membrrecord.txt","rb"))==NULL)
        printf(" ! The File is Empty...\n\n");
    else 
    {
        gotoxy(61,13);
        printf("Enter The Name Of member : ");
            scanf("%s",Target);
        while(!feof(membrrecord) && Found==0)
        {
        
        fread(&membr,sizeof(membr),1,membrrecord);
            if(strcmp(Target,membr.mname)==0)
                Found=1;
     
        }
        if(Found)
        {
           
                       gotoxy(61,14);
            printf("The Name of Member is:  %d",membr.mid);
            gotoxy(61,15);
            printf("The Name of Member is:  %s",membr.mname);
            gotoxy(61,16);
            printf("The Department is:  %s",membr.department);
            gotoxy(61,17);
            printf("The Phone Number: %d",membr.phno);
            gotoxy(61,18);
            printf("The Available card: %d",membr.availibcard);
            }
        else if(!Found){
            gotoxy(26,36);
            printf("! There is no such Entry...\n");}
        fclose(membrrecord);
    }

}





void Addmembr()
{
    int i;
    system("cls");    
    FILE *membrrecord;   
    struct memrec membr;
    membrrecord = fopen("membrrecord.txt","a+b");
    gotoxy(61,13);
    printf("Enter The userid of the Member(Integer) :");
        scanf("%d",&membr.mid);
    gotoxy(61,14);    
    printf("Enter The Name of the Member :");
        scanf("%s",membr.mname);
    gotoxy(61,15);    
    printf("Enter The Department");
        scanf("%s",membr.department);
    gotoxy(61,16);
    printf("Enter The phone number of the member:");
        scanf("%d",&membr.phno);
    membr.availibcard=2;
    fwrite(&membr,sizeof(membr),1,membrrecord);
    fclose(membrrecord);
    gotoxy(26,36);
    printf("(' ') Added  A New member Successfully...");
   
   
}



void delmembr()
{
 int r, s;
 FILE *membrrecord;
 FILE *fp3;
 struct memrec membr;
 system("cls");
 lay2();
 gotoxy(61,13);
 printf("Enter the member id you want to delete :");
 scanf("%d", &r);

  membrrecord = fopen("membrrecord.txt", "rb");
  fp3 = fopen("TempFile", "wb");
  while (fread(&membr, sizeof(membr), 1, membrrecord))
  {
   s = membr.mid;
   if (s != r)
    fwrite(&membr, sizeof(membr), 1, fp3);
  }
  fclose(membrrecord);
  fclose(fp3);
  membrrecord = fopen("membrrecord.txt", "wb");
  fp3 = fopen("TempFile", "r");
  while (fread(&membr, sizeof(membr), 1, fp3))
   fwrite(&membr, sizeof(membr), 1,membrrecord);
gotoxy(26,36);
  printf("RECORD DELETED");
  fclose(membrrecord);
  fclose(fp3);


}

void modmembr(){
 int s, r,ch;
 FILE *membrrecord;
 FILE *fp3;
 struct memrec membr;
 system("cls");
 lay2();
 gotoxy(61,13);
 printf("Enter member id to update:");
 scanf("%d", &r);

  membrrecord = fopen("membrrecord.txt", "rb");
  fp3 = fopen("TempFile", "w+b");
  while (fread(&membr, sizeof(membr), 1, membrrecord))
  {
   s = membr.mid;
   if (s != r)
    fwrite(&membr, sizeof(membr), 1, fp3);
   else
   {
     gotoxy(26,14);
    printf("1>ID" );
    gotoxy(26,17);
    printf("2>Name" );
    gotoxy(26,21);
    printf("3>Department" );
    gotoxy(26,24);
    printf("4>Phone Number");
    gotoxy(26,27);
    printf("5>Back");
    gotoxy(26,37);
    printf("Enter your choice");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
     gotoxy(61,15);
     printf("Enter New ID:");
     scanf("%d", &membr.mid);
     break;

    case 2:
    gotoxy(61,16);
     printf("Enter New Name : ");
     scanf("%s", membr.mname);
     break;

    case 3:
    gotoxy(61,17);
    printf("Enter New Department: ");
     scanf("%s", membr.department);
     break;

     case 4:
     printf("Enter New Phone No.: ");
     scanf("%d", &membr.phno);
     break;

     case 5:

     adddelmem();
     break;

    default:
    gotoxy(26,36);
     printf("Invalid Selection");
     break;
    }
    fwrite(&membr, sizeof(membr), 1, fp3);
   }
  }
  fclose(membrrecord);
  fclose(fp3);
  membrrecord = fopen("membrrecord.txt", "wb");
  fp3 = fopen("TempFile", "rb");
  while (fread(&membr, sizeof(membr), 1, fp3))
  {
   fwrite(&membr, sizeof(membr), 1, membrrecord);
  }
  fclose(membrrecord);
  fclose(fp3);
  gotoxy(26,36);
  printf("RECORD UPDATED");
 }


void Issue()
{
    int mid,i,Found1=0,Found2=0;
    char issubookname[20];
    FILE *membrrecord;
    FILE *librecord;
    FILE *fp1;
    FILE *fp2;
    FILE *temp1;
    FILE *temp2;
    struct bookrec book;
    struct memrec membr;
    system("cls");
    gotoxy(61,13);
    printf("Enter The userid of the Member : ");
        scanf("%d",&mid);
    if((membrrecord=fopen("membrrecord.txt","rb"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        while(!feof(membrrecord))
        {
            fread(&membr,sizeof(membr),1,membrrecord);
            if(mid==membr.mid)
            {
                Found1=1;
                break;
            }
        }
        if(Found1)
        {
            if(membr.availibcard<1)
            {
                gotoxy(26,36);
                printf(" ! Library card not available...");
            }
            else

            {   
             gotoxy(61,14);   
             printf("Enter The Name of book :");
                scanf("%s",issubookname);
                if((librecord=fopen("librecord.txt","rb"))==NULL)
                    printf(" ! The file is empty...\n\n");
                else
                {
                    while(!feof(librecord))
                    {
                        fread(&book,sizeof(book),1,librecord);
                        if(strcmp(issubookname,book.titles)==0)
                            Found2=1;
                        
                    }
                    if(Found2)
                    {
                        if(book.nooftitles<1){
                             gotoxy(26,36);
                             printf(" ! Book already issued...\n");
                        }
        
                           
                        
                        else
                        {   
                           
                            fp2=fopen("fp2.txt","w");
                            if((temp2=fopen("membrrecord.txt","rb"))==NULL)
                                printf(" ! The file is empty...\n\n");
                            else
                            {
                                while(!feof(temp2))
                                {
                                    fread(&membr,sizeof(membr),1,temp2);
                                      if(feof(temp2))
                                        break;
                           
                                   
                                    if(mid==membr.mid)
                                    {
                                        membr.availibcard--;
                                        fwrite(&membr,sizeof(membr),1,fp2);

                                    }
                                    else{
                                       fwrite(&membr,sizeof(membr),1,fp2);
                                   }
                                  
                                }
                            }
                            fclose(temp2);
                            fclose(fp2);
                           

                            fp1=fopen("fp1.txt","wb");
                            if((temp1=fopen("librecord.txt","rb"))==NULL)
                                printf(" ! The file is empty...\n\n");
                            else
                            {
                                while(!feof(temp1))
                                {
                                      fread(&book,sizeof(book),1,temp1);
                                    if(feof(temp1))
                                        break;
                                    if(strcmp(issubookname,book.titles)==0)
                                    {
                                      book.nooftitles--;  
                                      fwrite(&book,sizeof(book),1,fp1);
                                    }
                                    else
                                    {
                                        fwrite(&book,sizeof(book),1,fp1);
                                    }
                                //    for(i=0;i<book.nooftitles;i++)
                                 //   {
                                     //   fscanf(temp1,"%s",book.titles);
                                   //     fprintf(fp1,"%s\t",book.titles);
                                   // }
                                }
                            }
                            fclose(temp1);
                            fclose(fp1);
                            fclose(librecord);
                            fclose(membrrecord);
                            remove("librecord.txt");
                            rename("fp1.txt","librecord.txt");
                            remove("membrrecord.txt");
                            rename("fp2.txt","membrrecord.txt");
                            gotoxy(26,36);
                            printf(" (' ') Book Successfully issued...\n");
                        }               
                    }
                    else if(!Found2)
                        gotoxy(26,36);
                        printf(" ! There is no such Book...\n");
               
                }
            }
        }

        else if(!Found1)
            gotoxy(26,36);
            printf(" ! Invalid User id...\n");
       

    }
   
}




void bookret()
{
int mid,i,Found1=0,Found2=0,flag=0;
char retbookname[20];
FILE *librecord;
FILE *membrrecord;
FILE *fp1;
FILE *fp2;
FILE *temp1;
FILE *temp2;
struct bookrec book;
struct memrec membr;
system("cls");
lay2();
    temp1=librecord;temp2=membrrecord;
    gotoxy(61,13);
    printf("Enter The userid of the Member :");
        scanf("%d",&mid);
    if((membrrecord=fopen("membrrecord.txt","rb"))==NULL)
        printf(" ! The file is empty...\n\n");
    else
    {
        while(!feof(membrrecord))
        {
            fread(&membr,sizeof(membr),1,membrrecord);
            if(mid==membr.mid)
            {
                Found1=1;
            }
        }
        if(Found1)
        {
            if(membr.availibcard<=2)
            {
                gotoxy(26,36);
                printf(" ! Error...\n");
            }
            else
            {    printf("Enter The Name of book :");
                scanf("%s",retbookname);
                if((librecord=fopen("librecord.txt","rb"))==NULL)
                    printf(" ! The file is empty\n\n");
                else
                {
                    while(!feof(librecord))
                    {
                        fread(&book,sizeof(book),1,librecord);
                        if(strcmp(retbookname,book.titles)==0)
                        Found2=1;
                        
                    }
                    if(Found2)
                    {
                        if(book.status==1)
                        {
                            gotoxy(26,36);
                            printf(" ! Error:Book already in stock...");
                        }
                        else
                        {   
                           
                            fp2=fopen("fp2.txt","w");
                            if((temp2=fopen("membrrecord.txt","a+b"))==NULL)
                                printf(" ! The file is empty...\n\n");
                            else
                            {
                                while(!feof(temp2))
                                {
                                    fread(&membr,sizeof(membr),1,temp2);
                                    
                                    if(feof(temp2))
                                        break;
                                   
                                    if(mid==membr.mid)
                                    {
                                        membr.availibcard++;
                                        fwrite(&membr,sizeof(membr),1,fp2);
                                    }
                                    else
                                    {
                                        fwrite(&membr,sizeof(membr),1,fp2);
                                    }
                                    
                                }
                            }
                            fclose(temp2);
                            fclose(fp2);
                           

                            fp1=fopen("fp1.txt","wb");
                            if((temp1=fopen("librecord.txt","rb"))==NULL)
                                printf(" ! The file is empty...\n\n");
                            else
                            {
                                while(!feof(temp1))
                                {
                                    fread(&book,sizeof(book),1,temp1);
                                      
                                    if(feof(temp1))
                                        break;
                                    if(strcmp(retbookname,book.bname)==0)
                                    {
                                        book.nooftitles++;
                                        fwrite(&book,sizeof(book),1,fp1);
                                    }
                                    else
                                    {
                                        fwrite(&book,sizeof(book),1,fp1);
                                    }
                                    
                                }
                            }
                            fclose(temp1);
                            fclose(fp1);
                            fclose(librecord);
                            fclose(membrrecord);
                            gotoxy(26,36);
                            printf("('') Book Successfully Returned...\n");
                            remove("librecord.txt");
                            rename("fp1.txt","librecord.txt");
                            remove("membrrecord.txt");
                            rename("fp2.txt","membrrecord.txt");

                        }               
                    }
                    else if(!Found2)
                        gotoxy(26,36);
                        printf("! There is no such Book...\n");
               
                }
            }
        }
        else if(!Found1)
            gotoxy(26,36);
            printf("! Invalid User id...\n");
       

    }
   
}



 //gotoxy(40,1);
/*int time()
{
time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char s[64];
    strftime(s, sizeof(s), "%c", tm);
    gotoxy(40,1);
    printf("%s\n", s);
}*/
int time(){
    gotoxy(35,1);
   printf("%s", __DATE__ );
   gotoxy(50,1);
   printf("%s", __TIME__ );
}


void Exit()
{
  exit(0);
}