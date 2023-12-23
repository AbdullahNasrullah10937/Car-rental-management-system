#include<iostream>
#include<conio.h>
#include<windows.h>
#include<string>
#include<cctype>
#include<limits>
#include<fstream>
#include<stdlib.h>
using namespace std;

int convertDatetodays(string date); //get date's input
bool check_number(string check, int length);
bool empty(string check);
bool check_int(string check);
bool check_repeatition(string input, string arr[], int index); // it checks repeatition of in[put]
void for_string_int();         // To show error when iput is other than integer
void for_string_repeatition(); // To show that Input is being repeated
void for_empty_string();       // to show that Input is empty
void invalid_option();                               // To show error when options are other than preffered
bool charactermCheck(string characterCheck);
string sign_in();
string main_menu();
void sign_up();
int admincount=0;
int index=-1;
string owner_menu();
string company[1000];

string type[1000];
string registration[1000];
string nameofcar[1000];
string carselection[1000];
string price_of_car[1000];
string dateofborrow[1000];
string dateofreturn[1000];
int carcount=0;
void gotoxy(int x, int y); // to specifiy location of output
int x=3; int y=3;
void list_of_customer();
void add_cars();
void view_list();
void available_cars();
void rented_cars();
void select_car();
void rent_details();
void return_car();
void feed_back();
string getField(string record, int field);
string customer_menu();
string feedback[1000];
int feedbackcount=0;
int carisselected[1000];
int sales=0;
string username[1000];
string password[1000];
string role[1000];
int usercount=0;
//functions of file handling
void storesignup();
void readsignup();
void storecarinformation();
void readcarinformation();
void storefeedback();
void readfeedback();
void storesale();
void readsale();
void storedate();
void readdate();
void storeselection();
void readselection();









HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
main()
{

    for(int i=0; i<1000; i++) 
    {
    carisselected[i]=-1;
    }
    for(int i=0; i<1000; i++) 
    {
    carselection[i]="Not Selected";
    }
        readsignup();
       
        readcarinformation();
        readfeedback();
        readsale();
        readdate();
        readselection();





    while(true)
    {
        string menu=main_menu();
        if(menu=="1")
        {
            sign_up();
        }
        else if(menu=="2")
        {
            string return1=sign_in();
            if(return1=="Admin")
            {
                while(true)
                {
                string owner=owner_menu();
                if(owner=="1")
                {
                    add_cars();
                }
                else if(owner=="2")
                {
                    view_list();
                }
                else if(owner=="3")
                {
                    list_of_customer();
                }
                else if(owner=="4")
                {
                    sign_up();
                }
                else if(owner=="5")
                {
                    available_cars();
                }
                else if(owner=="6")
                {
                    cout<<"Total Profit Earned is: "<<sales;
                    getch();
                }
                else if(owner=="7")
                {
                    rented_cars();
                }
                else if(owner=="8")
                {
                    break;
                }
                else
                {
                    invalid_option();
                }
                }
                
            }
            else if(return1=="User")
            {
                while(true)
                {
                string customer=customer_menu();
                if(customer=="1")
                {
                    available_cars();
                }
                else if(customer=="2")
                {
                    select_car();
                }
                else if(customer=="3")
                {
                    return_car();    
                }
                else if(customer=="4")
                {
                    rent_details();
                }
                else if(customer=="5")
                {
                    feed_back();
                }
                else if(customer=="6")
                {
                    break;
                }
                else 
                {
                    invalid_option();
                }
                }
            }
            else
            {
                cout<<"Invalid Credentials"<<endl;
                getch();
            }
        }
        else if(menu=="3")
        {
            break;
        }
        else 
        {
            invalid_option();
        }
    }
}
string main_menu()
{
    system("cls");
    string option;
   SetConsoleTextAttribute(h,6);
    cout<<"1. Sign up"<<endl;
    cout<<"2. Sign in"<<endl;
    cout<<"3. Exit"<<endl;
      SetConsoleTextAttribute(h,7);
    cout<<"Enter your preferred choice: ";
      SetConsoleTextAttribute(h,6);
    getline(cin, option); 
      SetConsoleTextAttribute(h,7);
    return option;
}
void sign_up()
{
    system("cls");
    while(true)
    {
      SetConsoleTextAttribute(h,6);cout<<"Enter your username: ";
     SetConsoleTextAttribute(h,10);getline(cin, username[usercount]);
    if(empty(username[usercount]))
    {
        for_empty_string();
    }
    else if(check_repeatition(username[usercount], username, usercount))
    {
        for_string_repeatition();
    }   
    else 
    {
        break;
    }
    }
    while(true)
    {
         SetConsoleTextAttribute(h,6);
    cout<<"Enter your password: ";
    SetConsoleTextAttribute(h,10); getline(cin, password[usercount]);
    if(empty(username[usercount]))
    {
        for_empty_string();
    }   
    else 
    {
        break;
    }
    }
    while(true)
    { SetConsoleTextAttribute(h,6);
    cout<<"Enter your Role(Admin, User): ";
     SetConsoleTextAttribute(h,10);getline(cin, role[usercount]);
    if(empty(username[usercount]))
    {
        for_empty_string();
    }
    else if(role[usercount]!="Admin" && role[usercount]!="User") 
    {
        invalid_option();
    }  
    else if(role[usercount]=="Admin" && admincount==1)
    {
        SetConsoleTextAttribute(h,4); cout<<"There cannot be more than one admin."<<endl;
        getch();
    }
    else 
    {
        break;
    }
    }
    if(role[usercount]=="Admin")
    {
        admincount++;
    }
    usercount++;
    storesignup();


}
string sign_in()
{
    system("cls");
    int a=-1;
    string name; string passworduser;
    string rolereturn="";
    SetConsoleTextAttribute(h,6); cout<<"Enter username: ";
    SetConsoleTextAttribute(h,10); getline(cin, name);
    SetConsoleTextAttribute(h,6); cout<<"Enter password: ";
    SetConsoleTextAttribute(h,10); getline(cin, passworduser);
    for(int i=0; i<usercount; i++)
    {
        if(name==username[i] && passworduser==password[i])
        {
            a=i;
            index=i;
            break;
        }
    }
    rolereturn=role[a];
    return rolereturn;
}
string owner_menu()
{
    system("cls");
    string option;
    SetConsoleTextAttribute(h,6); cout<<"1. Add Cars."<<endl;
    SetConsoleTextAttribute(h,6); cout<<"2. View Cars."<<endl;
    SetConsoleTextAttribute(h,6); cout<<"3. List of Customer."<<endl;
    SetConsoleTextAttribute(h,6); cout<<"4. Add customers."<<endl;
    SetConsoleTextAttribute(h,6); cout<<"5. Available cars."<<endl;
    SetConsoleTextAttribute(h,6); cout<<"6. Profit"<<endl;
    SetConsoleTextAttribute(h,6); cout<<"7. Rented cars."<<endl;
    SetConsoleTextAttribute(h,6); cout<<"8. Exit"<<endl;
    SetConsoleTextAttribute(h,6); cout<<"Enter your preffered choice.";
    SetConsoleTextAttribute(h,10); getline(cin, option);
    return option;
}
void available_cars()
{
    system("cls");
    gotoxy(x, y);
    SetConsoleTextAttribute(h,6); cout<<"Company";
    gotoxy(x+15, y);
     SetConsoleTextAttribute(h,6);cout<<"Type";
    gotoxy(x+30, y);
   // SetConsoleTextAttribute(h,6); cout<<"Registration Number";
   // gotoxy(x+60, y);
    SetConsoleTextAttribute(h,6); cout<<"Name of car";
    gotoxy(x+78, y);
    SetConsoleTextAttribute(h,6); cout<<"Price(per hour)";
    gotoxy(x+92, y);
    SetConsoleTextAttribute(h,6); cout<<"Car Selection";
    
    for(int i=0; i<carcount; i++)
    {
        if(carselection[i]!="Not Selected")
        {
            continue;
        }
        gotoxy(x, y+i+2);
         SetConsoleTextAttribute(h,10);cout<<company[i];
        gotoxy(x+15, y+i+2);
        
        SetConsoleTextAttribute(h,10); cout<<type[i];
        gotoxy(x+60, y+i+2);
        //SetConsoleTextAttribute(h,10); cout<<registration[i];
       // gotoxy(x+30, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<nameofcar[i];
        gotoxy(x+78, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<price_of_car[i];
        gotoxy(x+92, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<carselection[i];
        
    }
    getch();
}
void rented_cars()
{
    system("cls");
    gotoxy(x, y);
    SetConsoleTextAttribute(h,6); cout<<"Company";
    gotoxy(x+15, y);
   SetConsoleTextAttribute(h,6);  cout<<"Type";
    gotoxy(x+30, y);
   // SetConsoleTextAttribute(h,6); cout<<"Registration Number";
    //gotoxy(x+60, y);
    SetConsoleTextAttribute(h,6); cout<<"Name of car";
    gotoxy(x+78, y);
    SetConsoleTextAttribute(h,6); cout<<"Car Selection";
    for(int i=0; i<carcount; i++)
    {
        if(carselection[i]=="Not Selected")
        {
            continue;
        }
        gotoxy(x, y+i+2);
         SetConsoleTextAttribute(h,10);cout<<company[i];
        gotoxy(x+15, y+i+2);
       // SetConsoleTextAttribute(h,10); cout<<registration[i];
       // gotoxy(x+30, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<type[i];
        gotoxy(x+60, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<nameofcar[i];
        gotoxy(x+78, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<carselection[i];
    }
    getch();
}
void add_cars()
{
    system("cls");
     SetConsoleTextAttribute(h,6);cout<<"Enter these details of car: "<<endl;
    while(true)
    {
    SetConsoleTextAttribute(h,6); cout<<"Company of car: ";
    SetConsoleTextAttribute(h,10); getline(cin, company[carcount]);
    if(empty(company[carcount]))
    {
        for_empty_string();
    }  
    else
    {
        break;
    }
    }
    while(true)
    {
    SetConsoleTextAttribute(h,6); cout<<"Type of car: ";
    SetConsoleTextAttribute(h,10); getline(cin, type[carcount]);
    if(empty(type[carcount]))
    {
        for_empty_string();
    }
    else
    {
        break;
    }
    }
   // while(true)
   // {
   // SetConsoleTextAttribute(h,6); cout<<"Registration number: ";
    // SetConsoleTextAttribute(h,10);getline(cin, registration[carcount]);
    /*if(empty(registration[carcount]))
    {
        for_empty_string();
    }
   
    else if(check_repeatition(registration[carcount], registration, usercount)==1)
    {
        for_string_repeatition();
    }
    else 
    {
        break;
    }*/
   // }
    while(true)
    {
     SetConsoleTextAttribute(h,6);cout<<"Name of car: ";
    SetConsoleTextAttribute(h,10); getline(cin, nameofcar[carcount]);
    if(empty(nameofcar[carcount]))
    {
        for_empty_string();
    }
    else
    {
        break;
    }
    }
    while(true)
    {
     SetConsoleTextAttribute(h,6);cout<<"Price of car(per hour): ";
     SetConsoleTextAttribute(h,10);getline(cin, price_of_car[carcount]);
    if(empty(price_of_car[carcount]))
    {
        for_empty_string();
    }
    else if(check_int(price_of_car[carcount]))
    {
        for_string_int();
    }
    else
    {
        break;
    }
    }
    carcount++;
    storecarinformation();

}
void view_list()
{
    system("cls");
    gotoxy(x, y);
     SetConsoleTextAttribute(h,6);cout<<"Company";
    gotoxy(x+15, y);
    SetConsoleTextAttribute(h,6); cout<<"Type";
    gotoxy(x+30, y);
   // SetConsoleTextAttribute(h,6); cout<<"Registration Number";
   // gotoxy(x+60, y);
    SetConsoleTextAttribute(h,6); cout<<"Name of car";
    gotoxy(x+78, y);
    SetConsoleTextAttribute(h,6); cout<<"Price(per hour)";
    for(int i=0; i<carcount; i++)
    {
        gotoxy(x, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<company[i];
        gotoxy(x+15, y+i+2);
       // SetConsoleTextAttribute(h,10); cout<<registration[i];
       // gotoxy(x+30, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<type[i];
        gotoxy(x+60, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<nameofcar[i];
        gotoxy(x+78, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<price_of_car[i];
    }
    getch();
}
void list_of_customer() 
{
    system("cls");
    gotoxy(x, y);
    SetConsoleTextAttribute(h,6); cout<<"Name";
    for(int i=0; i<usercount; i++)
    {
        if(role[i]=="Admin")
        {
            continue;
        }
        gotoxy(x, y+i+2);
        SetConsoleTextAttribute(h,10); cout<<username[i];

    }
    getch();
}
string customer_menu()
{
    string option;
    system("cls");
    SetConsoleTextAttribute(h,6); cout<<"1. View Available Cars"<<endl;
    SetConsoleTextAttribute(h,6); cout<<"2. Select Car for rent"<<endl;
    SetConsoleTextAttribute(h,6); cout<<"3. Return the Car"<<endl;
    SetConsoleTextAttribute(h,6); cout<<"4. View Details of rent"<<endl;
    SetConsoleTextAttribute(h,6); cout<<"5. Feedback"<<endl;
    SetConsoleTextAttribute(h,6); cout<<"6. Exit."<<endl;
    SetConsoleTextAttribute(h,6); cout<<"Enter Your Preffered choice";
    SetConsoleTextAttribute(h,10); getline(cin, option);
    return option;
}
void select_car()
{
    if(carisselected[index]!=-1)
    {
       SetConsoleTextAttribute(h,4);  cout<<"You have not returned the previous car."<<endl;
        SetConsoleTextAttribute(h,4); cout<<"First, return the previous car then comeback.";
        getch();
    }
    if(carisselected[index]==-1)
    {
     SetConsoleTextAttribute(h,10);cout<<price_of_car[0]<<" "<<price_of_car[1]<<endl;getch();
    string car;
    int a=1;
     SetConsoleTextAttribute(h,6);cout<<"Enter the name of car you want for rent: ";
    SetConsoleTextAttribute(h,10); getline(cin, car);
    for(int i=0; i<carcount; i++)
    {
        if(car==nameofcar[i])
        {
            
            a=i;
            break;
        }
    }
    if(a==-1)
    {
        SetConsoleTextAttribute(h,4); cout<<"This car is not available.";
        getch();
    }
    else if(carselection[a]=="Not Selected")
    {
        while(true)
        {
       SetConsoleTextAttribute(h,6);  cout<<"Time of obtaining(DD/MM/YYYY): ";
       SetConsoleTextAttribute(h,10);  getline(cin, dateofborrow[index]);
        string c=dateofborrow[index];
        if(empty(c)==1)
        {
            for_empty_string();
        }
        else if((charactermCheck(dateofborrow[index])==0 && c[2]!='/' && c[5]!='/') || c.size()!=10)
        {
          SetConsoleTextAttribute(h,4);   cout<<"Invalid fORMAT";
            getch();
        }
        else
        {
            break;
        }
        }
        while(true)
        {
       SetConsoleTextAttribute(h,6);  cout<<"Time of return(DD/MM/YYYY): ";
       SetConsoleTextAttribute(h,10);  getline(cin, dateofreturn[index]);
        string cd=dateofreturn[index];
        if(empty(cd)==1)
        {
            for_empty_string();
        }
        else if((charactermCheck(dateofreturn[index])==0 && cd[2]!='/' && cd[5]!='/') || cd.size ()!=10)
        {
         SetConsoleTextAttribute(h,4);    cout<<"Invalid fORMAT";
            getch();
        }
        else
        {
            break;
        }
        }
       SetConsoleTextAttribute(h,2);  cout<<"You have successfully rented a car"<<endl;
        carselection[a]="Rented";
        carisselected[index]=a;
        int ab=convertDatetodays(dateofborrow[index]);
        int b=convertDatetodays(dateofreturn[index]);
        int c=(b*24)-(ab*24);
        string convert=price_of_car[a];
        int d=c*stoi(convert);
        sales=sales+d;
        storedate();
        storeselection();

        




    }
    else if(carselection[a]!="Not Selected")
    {
        SetConsoleTextAttribute(h,4); cout<<"This car is already on rent.";
    }
    storecarinformation();
    storesale();
    }

}
void feed_back()
{
    while(true)
    {
    SetConsoleTextAttribute(h,6); cout<<"Enter your feedback below:";
    SetConsoleTextAttribute(h,10); getline(cin, feedback[feedbackcount]);
    if(empty(feedback[feedbackcount]))
    {
        for_empty_string();
    }
    else
    {
        break;
    }
    }
    feedbackcount++;
    storefeedback();

}
void return_car()
{
    string option;
    SetConsoleTextAttribute(h,6); cout<<"Enter YES to return and any other to not: ";
    SetConsoleTextAttribute(h,10); getline(cin, option);
    if(option=="YES" || option=="yes")
    {
        carselection[carisselected[index]]=="Not Selected";
    }
}
void rent_details()
{
    if(carisselected[index]!=-1)
    {
       SetConsoleTextAttribute(h,4);  cout<<"You have not rented a car."<<endl;
        getch();
    }
    if(carisselected[index]!=-1)
    {
       
        SetConsoleTextAttribute(h,6); cout<<"Company Name: "<<company[carisselected[index]];
        SetConsoleTextAttribute(h,6); cout<<"Type: "<<type[carisselected[index]];
       // SetConsoleTextAttribute(h,6); cout<<"Registration number: "<<registration[carisselected[index]];
         SetConsoleTextAttribute(h,6); cout<<"Name of car: "<<nameofcar[carisselected[index]];
        SetConsoleTextAttribute(h,6); cout<<"Price: "<<price_of_car[carisselected[index]];
        getch();
    }
}
int convertDatetodays(string date) 
{
    string dateDays="0";
    string dateMonths="0";
    string dateYears="0";
    dateDays = { date[0], date[1], '\0' };
    dateMonths = { date[3], date[4], '\0' };
    dateYears = { date[6], date[7], date[8], date[9], '\0' };
    return stoi(dateDays) + stoi(dateMonths) * 30 + (stoi(dateYears) - 2000) * 365;
}
bool charactermCheck(string characterCheck)
{
  //this is used to check the digits if the user input character then return false
  for (int i = 0; i < characterCheck.length(); i++)
  {
    char c = characterCheck[i];
    if (isdigit(c))
    {
      continue;
    }
    else
    {
      return false;
    }
  }
  return true;
}
void gotoxy(int x, int y) // to specifiy location of output
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
bool check_number(string check, int length) // it checks the length of input
{

    if (check.size() != length)
    {
        return 1;
    }
    return 0;
}
bool check_int(string check) // it checks whether the input ids iinteger or not
{
    for (int q = 0; check[q] != '\0'; q++)
    {

        int b = check[q];
        if (b != 48 && b != 49 && b != 50 && b != 51 && b != 52 && b != 53 && b != 54 && b != 55 && b != 56 && b != 57)
        {

            return 1;
        }
    }
    return 0;
}
bool check_repeatition(string input, string arr[], int index) // it checks repeatition of in[put]
{

    for (int c = 0; c < index; c++)
    {

        if (input == arr[c])
        {
            return 1;
        }
    }
    return 0;
}
bool empty(string check) // it checks whether the inpuyt is empty or not
{
    if (check == "")
    {
        return 1;
    }
    return 0;
}
void for_empty_string() // it shows validation in sentences for empty string
{

    SetConsoleTextAttribute(h,4); cout << "Input must not be empty. Try again."<<endl;
    SetConsoleTextAttribute(h,6); cout << "To continue, press any key....."<<endl;
    getch();
}
void for_string_repeatition() // it shows validation in sentences if input is bieng repeated
{

    SetConsoleTextAttribute(h,4); cout << "Sorry, but that input has already been claimed." << endl;
    SetConsoleTextAttribute(h,6); cout << "To continue, kindly press any key....."<<endl;
    getch();

}
void for_string_length() ////it shows validation in sentences for incorrect length of input
{

    SetConsoleTextAttribute(h,4); cout << "The specified length is not accurate. Please try again.                            " << endl;
    SetConsoleTextAttribute(h,6); cout << "To continue, kindly press any key....."<<endl;
    getch();
}
void for_string_int() // it shows validation in sentences if user put other inputs than integers
{

     SetConsoleTextAttribute(h,4);cout << "Input must be in integers."<<endl;
     SetConsoleTextAttribute(h,6);cout << "To continue, press any key to continue..."<<endl;
    getch();
}
void invalid_option() // it shows validation in sentences invalid options
{

    SetConsoleTextAttribute(h,4); cout << "The chosen option is not valid.Select a valid option." << endl;
    SetConsoleTextAttribute(h,6); cout << "To continue, kindly press any key....."<<endl;
    getch();
}
string getField(string record, int field)
{
  int commaCount = 1;
  string item;
  for (int x = 0; x < record.length(); x++)
  {
    if (record[x] == ',')
  {
    commaCount = commaCount + 1;
  }
  else if (commaCount == field)
  {
    item = item + record[x];
  }
  }
  return item;
}

//file handling functions start from here...

void storesignup()
{
    fstream line;
    line.open("Signup.txt", ios::out);
    {
        for(int i=0; i<usercount; i++)
        {
        line<<username[i]<<","<<password[i]<<","<<role[i]<<endl;
        }
    }
  
    line.close();
}
void readsignup()
{
    usercount=0;
    string record;
    fstream line;
    line.open("Signup.txt", ios::in);
    while(!(line.eof()))
    {
        getline(line, record);
        if(record=="")
        {
            break;
        }
        username[usercount]=getField(record, 1);
        password[usercount]=getField(record, 2);
        role[usercount]=getField(record, 3);
        if(role[usercount]=="Admin")
        {
            admincount=1;
        }
            usercount++;

    }
  
    line.close();
}
void storecarinformation()
{

    fstream line;
    line.open("Carinformation.txt", ios::out);
    {
        for(int i=0; i<carcount; i++)
        {
        line<<company[i]<<","<<type[i]<<","<<nameofcar[i]<<","<<carselection[i]<<","<<price_of_car[i]<<endl;
        }
    }
    line.close();
}
void readcarinformation()
{
    usercount=0;
    string record;
    fstream line;
    line.open("Carinformation.txt", ios::in);
    while(!(line.eof()))
    {
        getline(line, record);
        if(record=="")
        {
            break;
        }
        company[carcount]=getField(record, 1);
        type[carcount]=getField(record, 2);
       // registration[carcount]=getField(record, 3);
        nameofcar[carcount]=getField(record, 4);
        carselection[carcount]=getField(record, 5);
        price_of_car[carcount]=getField(record, 6);


    }
    line.close();
}
void storefeedback()
{
    fstream line;
    line.open("Feedback.txt", ios::out);
    for(int i=0; i<feedbackcount; i++)
    {
        line<<feedback[i]<<","<<feedbackcount<<endl;
    }
    line.close();
}
void readfeedback()
{
    feedbackcount=0;
    fstream line;
    string record;
    line.open("Feedback.txt", ios::in);
    while(!(line.eof()))
    {
        getline(line, record);
        if(record=="")
        {
            break;
        }
        feedback[feedbackcount]=getField(record, 1);
        feedbackcount++;
    }
}
void storesale()
{
    fstream line;
    line.open("Sales.txt", ios::out);
    line<<sales;
    line.close();
}
void readsale()
{
    string record;
    fstream line;
    line.open("Sales.txt", ios::out);
    getline(line, record);
    if(record=="")
    {
        record="0";
    }
    sales=stoi(record);
    line.close();
}
void storedate()
{
    fstream line;
    line.open("Storedate.txt", ios::out);
    for(int i=0; i<usercount; i++)
    {
        line<<dateofborrow[i]<<","<<dateofreturn[i]<<endl;
    }
    line.close();
}
void readdate()
{
    int i=0;
    fstream line;
    string record;
    line.open("Storedate.txt", ios::out);
    while(!(line.eof()))
    {
        getline(line, record);
        dateofborrow[i]=getField(record,1);
        dateofreturn[i]=getField(record,2);
        i++;
    }
    line.close();
}
void storeselection()
{
    fstream line;
    line.open("StoreSelection.txt", ios::out);
    for(int i=0; i<usercount; i++)
    {
        line<<carisselected[i]<<endl;
    }
    line.close();
}
void readselection()
{
    int i=0;
    string record;
    fstream line;
    line.open("StoreSelection.txt", ios::in);
    while(!(line.eof()))
    {
        getline(line, record);
        string b=getField(record, 1);
        if(b=="")
        {
            b="0";
        }
        carisselected[i]=stoi(b);
        i++;
    }
    line.close();
}
