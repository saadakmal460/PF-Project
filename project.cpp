#include <iostream>
#include <conio.h>
using namespace std;

int userCount = 0;
const int week = 7;
const int id = 5;
int size = 10;
int count[10];
string nameStudent[10] , cnic[10], city[10], pass[10], option;
int rollno[10];
string day[week] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
string dish[week] = {"biryani", "chicken", "sabzi", "daal", "pualo", "sabzi", "daal"};
string noticeBoard;
string att, opt ,choice, weekDay;
string room;
string complaint;
string userName, userPass;
string feeName;
string review;
string bills[id] = {"Electricity", "Gas", "Water", "Internet", "Mess"};
int billAmonut[id];
string challan[10], stdAmount[10];
int challanCount = 0;
bool flagForFee;
string budgetHead[3] = {"bills" , "salaries" , "maintainance"};
string budgets[3] = {"600000" , "450000" , "350000"};
string nameEmploye[10] = {"ahmad" , "bilal" , "hamza" , "imran" , "ali" , "amir" , "farhan" , "hassan" , "usman" , "zain"};
string employeNumber[10] = {"1638" , "2379" , "2580" , "3495" , "3904" , "5397" , "6051","7342" , "8126" , "9586"};
string days[10]; 



void printHeader();
void clearScreen();
int menu(); 
int adminMenu();
int userMenu();
int accountsMenu();
void addStudent();
string remove();
void viewStudent();
void updateStudent();
int notice();
string Addnotice();
int attendenceMenu();
string takeAttendence();
string viewAttendence();
int mess();
void MessMenu();
void updateMess();
void allotRoom();
bool checkId(string name, string password);
string info(string name);
string AddComplaint();
string viewComplaint(string userName);
void payFess();
void checkBills();
string reviewMenu();
string Addreview();
string billsMenu();
void addBills();
void viewBills();
void calculateExpense();
string generateChallan();
void checkfee();
string menuBudget();
void viewBudget();
void updateBudget();
string salariesMenu();
void employesList();
void transferSalaris();
string financialReport();
void view();
void graph();
void financialRecord();
string viewAttendeceStudent(string name);


main()
{
    int loginOption = 0;
    int loginAdmin = 0;
    int loginUser = 0;
    int loginAcc = 0;
    int messMenu = 0;
    int noticeOpt = 0;

    printHeader();
    

    while (loginOption != 4)
    {
        system("cls");
        printHeader(); // main heading
        

        loginOption = menu();

        /*ADMIN*/
        if (loginOption == 1)
        {

            system("cls");
            printHeader(); // main heading
            

            string name, password, role;

            cout << "\tEnter your username: ";
            cin >> name;

            cout << "\tEnter your password: ";
            cin >> password;

            if (name == "admin" && password == "123")
            {
                system("cls");
                printHeader(); // main heading
                
                while (loginOption != 11)
                {
                    system("cls");
                    printHeader(); // main heading
                    
                    loginAdmin = adminMenu();
                    if (loginAdmin == 1)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        string adminOpt = "1";

                        while (adminOpt == "1")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            addStudent();
                            cin >> adminOpt;
                        }
                    }

                    else if (loginAdmin == 2)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        remove();
                        getch();
                    }

                    else if (loginAdmin == 3)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        string adminOpt  = "1";

                        while(adminOpt == "1")
                        {

                            system("cls");
                            printHeader(); // main heading
                            
                            updateStudent();
                            cin >> adminOpt;
                        }
                    }

                    else if (loginAdmin == 4)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        viewStudent();
                        getch();
                    }

                    else if (loginAdmin == 5)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        noticeOpt = notice();

                        if (noticeOpt == 1)
                        {

                            system("cls");
                            printHeader(); // main heading
                            
                            Addnotice();
                            getch();
                        }

                        else if (noticeOpt == 2)
                        {
                            system("cls");
                            printHeader(); // main heading
                            

                            cout << "NOTICE BOARD" << endl<< endl;
                            cout << "\t\t\t" << noticeBoard;
                            getch();
                        }
                    }

                    else if (loginAdmin == 6)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        int attendence = attendenceMenu();
                        if (attendence == 1)
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            takeAttendence();
                            getch();
                        }

                        else if (attendence == 2)
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            viewAttendence();
                            getch();
                        }
                    }

                    else if (loginAdmin == 7)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        viewComplaint(userName);
                        getch();
                    }

                    else if (loginAdmin == 8)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        messMenu = mess();

                        if (messMenu == 1)
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            MessMenu();
                            getch();
                        }

                        else if (messMenu == 2)
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            string opt = "1";
                            while(opt == "1")
                            {
                                system("cls");
                                printHeader(); // main heading
                                
                                updateMess();
                                getch();
                            }
                        }
                    }

                    else if (loginAdmin == 9)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        financialRecord();
                        getch();
                    }

                    else if (loginAdmin == 10)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        allotRoom();
                        getch();
                    }

                    else if (loginAdmin == 11)
                    {
                        break;
                    }
                }
            }

            else
            {
                cout << "Invalid info" << endl;
                cout << "Enter 1 to return" << endl;
                getch();
            }
        }

        /*USER*/

        else if (loginOption == 2)
        {
            system("cls");
            printHeader(); // main heading
            

            cout << "\tEnter your userName: ";
            cin >> userName;

            cout << "\tEnter your userPass: ";
            cin >> userPass;

            bool check = checkId(userName, userPass);

            if (check == true)
            {
                system("cls");
                printHeader(); // main heading
                

                while (loginUser != 11)
                {
                    system("cls");
                    printHeader(); // main heading
                    
                    loginUser = userMenu();

                    if (loginUser == 1)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        info(userName);
                        getch();
                    }

                    else if (loginUser == 2)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        MessMenu();
                        getch();
                    }

                    else if (loginUser == 3)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        AddComplaint();
                        getch();
                    }

                    else if (loginUser == 4)
                    {
                        system("cls");
                        printHeader(); // main heading
                        

                        cout << "NOTICE BOARD" << endl<< endl;
                        cout << "\t\t\t" << noticeBoard;
                        getch();
                    }

                    else if (loginUser == 5)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        payFess();
                        getch();
                    }

                    else if (loginUser == 6)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        checkBills();
                        getch();
                
                    }

                    else if (loginUser == 7)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        viewAttendeceStudent(userName);
                        getch();
                    }
                    

                    else if (loginUser == 9)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        remove();
                        getch();
                        break;
                    }

                    else if (loginUser == 10)
                    {
                        string menu;
                        system("cls");
                        printHeader(); // main heading
                        
                        menu = reviewMenu();

                        if (menu == "1")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            Addreview();
                            getch();
                        }
                        else if (menu == "2")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            cout << "\t\tREVIEW PANEL" << endl<< endl;
                            cout << "\t\t" << review;
                        }
                    }

                    else if (loginUser == 11)
                    {
                        break;
                    }
                }
            }

            else
            {

                cout << "Invalid info" << endl;
                cout << "Enter 1 to return" << endl;
                getch();
            }
        }

        /*Accounts Ofiice*/

        else if (loginOption == 3)
        {
            string accName, accPass;
            system("cls");
            printHeader(); // main heading
            

            cout << "Enter you username: ";
            cin >> accName;

            cout << "Enter your password: ";
            cin >> accPass;

            if ((accName == "accounts") && (accPass == "123"))
            {
                while (loginAcc != 11)
                {
                    system("cls");
                    printHeader(); // main heading
                    
                    loginAcc = accountsMenu();

                    if (loginAcc == 1)
                    {

                        system("cls");
                        printHeader(); // main heading
                        

                        if (billsMenu() == "1")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            addBills();
                            getch();
                        }

                        else if (billsMenu() == "2")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            viewBills();
                            getch();
                        }
                    }

                    else if (loginAcc == 2)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        calculateExpense();
                        getch();
                    }

                    else if (loginAcc == 3)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        while(generateChallan() == "1")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            generateChallan();
                            getch();

                        }
                        
                    }

                    else if (loginAcc == 4)
                    {
                        system("cls");
                        printHeader(); // main heading
                        

                        if(menuBudget() == "1")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            viewBudget();
                            getch();

                        }

                        else if (menuBudget() == "2")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            updateBudget();
                            getch();
                            
                        }
                        

                    }
                    

                    else if (loginAcc == 5)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        viewBills();
                        getch();
                        
                    }


                    else if (loginAcc == 6)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        checkfee();
                        getch();
                        
                    }

                    else if (loginAcc == 7)
                    {
                        system("cls");
                        printHeader(); // main heading
                        

                        if(financialReport() == "1")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            view();
                            getch();

                        }

                        else
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            graph();
                            getch();

                        }
                    
                    }
                    

                    else if (loginAcc == 8)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        
                        if (salariesMenu() == "1")
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            employesList();
                            getch();
                        }

                        else
                        {
                            system("cls");
                            printHeader(); // main heading
                            
                            transferSalaris();
                            getch();
                            
                        }
                        
                        
                        
                    }
                    

                    else if (loginAcc == 9)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        cout << "NOTICE BOARD" << endl<< endl;
                        cout << "\t\t\t" << noticeBoard;
                        getch();
                        
                    }

                    else if (loginAcc == 10)
                    {
                        system("cls");
                        printHeader(); // main heading
                        
                        financialRecord();
                        getch();
                    }
                    

                    else if (loginAcc == 11)
                    {
                        break;
                    }
                    
                    
                    
                    
                }
            }

            else
            {
                cout << "INVALID!!";
                cout << "press 1 to return";
            }
        }
    }
}

/*FUNCTIONS*/

void financialRecord()
{
    cout << "Month\t\t\t Januaray"<<endl;
    cout << "Purchases and expenses"<<endl;
    cout<<"_______________________________________"<<endl;
    cout << "\tDate\t\t\t\tDeatils\t\t\t\tAmount"<<endl;
    cout << "\t02-01-2023\t\t\tMess and others\t\t\t\t100000"<<endl;
    cout << "\t05-01-2023\t\t\tSlaraies to staff\t\t\t150000"<<endl;
    cout << "\t10-01-2023\t\t\tPayment of bills\t\t\t100000"<<endl;
    cout << "\t17-01-2023\t\t\tMeeting with GM\t\t\t\t10000"<<endl;
    cout << "\t23-01-2023\t\t\tRepairing and maintainanace\t\t20000"<<endl;

    cout << "Presss any key to continue"<<endl;
}

void graph()
{
    cout << "GRAPHICAL Resprestntation"<<endl;
    cout <<endl;

    cout << "    |                  "<<endl;
    cout << "    |                      "<<endl;
    cout << "    |     Revenue          "<<endl;
    cout << "450k|      ****     "<<endl;
    cout << "    |      ****  **** Expense     "<<endl;
    cout << "350k|      ****  ****  "<<endl;
    cout << "    |      ****  ****  " <<endl;
    cout << "250k|      ****  ****  " <<endl;
    cout << "    |      ****  ****  "<<endl;
    cout << "150k|      ****  ****  "<<endl;
    cout << "    |      ****  ****  "<<endl;
    cout << " 50k|      ****  ****  "<<endl;
    cout << "    |___________________________________"<<endl;
    cout << "\t\t\t\t\tJANUARY";

}


void view()
{

    cout << "Revenue"<<endl;
    cout<<"_______________________________________"<<endl;
    cout << "Students Fess\t\t\t\t 100000Pkr"<<endl;
    cout << "Voluntary contribution\t\t\t 200000Pkr"<<endl;
    cout << "Revenue producing activities\t\t 100000Pkr"<<endl;
    cout << "Other revenue\t\t\t\t 50000Pkr"<<endl;

    cout << "Total revenue:\t\t\t45000"<<endl;
    cout<<"_______________________________________"<<endl;

    cout << "Expenses"<<endl;
    cout<<"_______________________________________"<<endl;
    cout << "Staff salaries\t\t\t\t 150000Pkr"<<endl;
    cout << "Supplies consumable and others\t\t 100000Pkr"<<endl;
    cout << "General operating expense\t\t 100000Pkr"<<endl;
    cout << "Meetings\t\t\t\t 50000Pkr"<<endl;

    cout << "Total Expenses:\t\t\t400000"<<endl;
    cout<<"_______________________________________"<<endl;


    cout << "Operating surplus = 50000"<<endl; 
    

}



string financialReport()
{
    string opt;
    
    cout << "1.View financial report"<<endl;
    cout << "2.View graphical analysis"<<endl;
    cout << "Enter your option"<<endl;

    cin >> opt;

    return opt;


}






void transferSalaris()
{
    string name , number ;
    int amount , sum = 0 , budget = 450000;
    bool flagb = true;

    cout << "Enter name of employe: ";
    cin >> name;

    cout << "Enter employe number: ";
    cin >> number;

    for (int i = 0; i <10; i++)
    {
        if ((name == nameEmploye[i]) && (number == employeNumber[i]))
        {
            cout << "Enter amount: ";
            cin >> amount;
            sum = sum + amount;
            if (sum < budget)
            {
                cout << "Remainning budget = " << budget - sum <<endl; 
                cout << "Salary transfered succesfully"<<endl;
            }
            else
            {
                cout << "Not enough budget!!"<<endl; 
            }
            

        }

        else
        {
            flagb = false;
        }  
    
    }
        
    cout << "Press any key to continue"<<endl;
    
}

void employesList()
{
    cout << "\t\tName\t\t\tEmploye Number"<<endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "\t\t" <<nameEmploye[i] << "\t\t\t"<<employeNumber[i]<<endl;
    }
    
}


string salariesMenu()
{
    string opt;
    cout << "\t1.View list of employes"<<endl;
    cout << "\t2.Tranfer salaraies"<<endl;

    cout << "Enter your option: ";

    cin >> opt;
    return opt;

}

void updateBudget()
{
    string budget;
  
    cout << "What you want to update in budget: ";
    cin >> budget;
     
    for (int i = 0; i < 4; i++)
    {
        if (budget == budgetHead[i])
        {
            cin >> budgets[i];
        }        
    
    }

    
    cout << "Record updated sucessfully"<<endl;
    cout << "Press any key to continue"<<endl;
    

}


void viewBudget()
{
    cout << "\tBudget for Bills\t\tBudget for salaries\t\tBudget for maintainance"<<endl;
    for (int i = 0; i < 4; i++)
    {
        
        cout <<"\t"<< budgets[i] <<"\t\t\t";
    }
    cout << endl;
    cout << "Press any key to continue"<<endl;
    
}

string menuBudget()
{
    string opt;
    cout << "\t1.View current budget"<<endl;
    cout << "\t2.Update budget"<<endl;
    cout << "Enter your option: ";
    cin >> opt;

    return opt;
}

void checkfee()
{
    string student;
    bool check = false;
    bool check2;

    cout << "Enter name of student"<<endl;
    cin >> student;

    for (int i = 0; i < userCount; i++)
    {
        if ((student == nameStudent[i]) && (flagForFee == true))
        {
            check = true;
        }
        else if(student != nameStudent[i])
        {
            check2 = false;

        }
        else
        {
            check = false;
        }
        
    }

    if (check == true)
    {
        cout << "Fee was paid" <<endl;
    }
    else if(check2 == false)
    {
        cout << "Record not found"<<endl;
    }
    else
    {
        cout << "Fee not paid"<<endl;
    }
    
    cout << "Pree any key to continue"<<endl;
    

}






string generateChallan()
{
    int stdRoll;
    string opt;
    bool flag = false;
    cout << "Enter roll number of student: ";
    cin >> stdRoll;

    for (int i = 0; i < userCount; i++)
    {
        if (stdRoll == rollno[i])
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }

    if (flag == false)
    {
        cout << "NO record of student found" << endl;
    }

    else
    {
        cout << "Enter challan number: ";
        cin >> challan[challanCount];

        cout << "Enter amount of fees: ";
        cin >> stdAmount[challanCount];

        cout << "Challan generated sucessfully";

        challanCount++;
    }

    cout << "Press 1 to generate another challan" << endl;
    cout << "Press 2 to return" << endl;

    cin >> opt;

    return opt;
}






void calculateExpense()
{
    string opt;
    int sum = 0;
    for (int i = 0; i < id; i++)
    {
        cout << "\t" << bills[i] << "\t\t\t" << billAmonut[i] << endl;
    }

    for (int i = 0; i < id; i++)
    {
        sum = sum + billAmonut[i];
    }
    cout << "Total month expenses are " << sum << endl;
}

void viewBills()
{
    for (int i = 0; i < id; i++)
    {
        cout << "\t" << bills[i] << "\t\t\t" << billAmonut[i] << endl;
    }

    cout << "Press any key to exit" << endl;
}


void addBills()
{
    for (int i = 0; i < id; i++)
    {
        cout << bills[i] << endl;
        cin >> billAmonut[i];
    }

    cout << "Press any key to exit" << endl;
}

string billsMenu()
{
    string option;
    cout << "Press 1 to add this month bills" << endl;
    cout << "Press 2 to view this month bills" << endl;

    cin >> option;

    return option;
}

string Addreview()
{

    cout << "Enter your review about hostel: " << endl;
    cin.ignore();
    getline(cin, review);

    cout << "\tPRESS any KEY to continue";
}

string reviewMenu()
{
    string reviewOption;
    cout << "\t1.Give your review" << endl;
    cout << "\t2.View your review" << endl;

    cout << "Enter your option: ";
    cin >> reviewOption;

    return reviewOption;
}

void checkBills()
{
    cout << "\tMess\t\t\tLaundaray\t\t\tSecurity fees\t\t\tOthers" <<endl;
    cout << "\t10000\t\t\t3000\t\t\t\t250670\t\t\t10000"<<endl;
}

void payFess()
{
    int i=0;
    string bank, account, challanNo, amonut;
    bool flag1 , flag2;

    cout << "\tEnter name of bank: ";
    cin >> bank;

    cout << "\tEnter bank account number: ";
    cin >> account;

    while (account.length() != 16)
    {
        cout << "\tBank account number must be of 16 digits" << endl;
        cin >> account;
    }

    cout << "\tEnter challan number: ";
    cin >> challanNo;

    while (challanNo != challan[i])
    {
        cout << "INVALID!! Enter again";
        cin >> challanNo;
    
    }
    

    cout << "Enter amonut: ";
    cin >> amonut;

    while (amonut != stdAmount[i])
    {
        cout << "INVALID !! Enter proper amonut";
        cin >> amonut;
    
    }
    flagForFee = true;



    cout << "\tFEE paid sucessfully" << endl;
}

string viewAttendeceStudent(string name)
{
   for (int i = 0; i < userCount; i++)
   {
     if (name == nameStudent[i])
    {
        cout << nameStudent[i] <<"\t\t"<<" present for "<<days[i]<<" days" << endl;
    }
   
   }

   cout << "Press any key to continue" <<endl;
   
    

}

string AddComplaint()
{

    cout << "Enter your complaint: " << endl;
    cin.ignore();
    getline(cin, complaint);

    cout << "\tPRESS any KEY to continue";
}

string viewComplaint(string name)
{
    cout << "\t COMPLAINT BOX" << endl;

    for (int i = 0; i <= userCount; i++)
    {
        if ((name == nameStudent[i]))
        {
            cout << "\t\tName" << nameStudent[i] << endl;
            cout << "\t\t\t" << complaint << endl;
        }

    }

}

string info(string name)
{
    for (int i = 0; i <= userCount; i++)
    {
        if ((name == nameStudent[i]))
        {
            cout << "\t\tName"
                 << "\t\tCNIC/B Form"
                 << "\t\tRoll Number"
                 << "\t\tCity" << endl;
            cout << "\t\t" << nameStudent[i] << "\t\t" << cnic[i] << "\t\t" << rollno[i] << "\t\t\t" << city[i] << endl;
        }
    }
    cout << "PRESS ANY key to continue" << endl;
}

bool checkId(string name, string password)
{

    for (int i = 0; i < userCount; i++)
    {
        if ((name == nameStudent[i]) && (password == pass[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

string remove()
{

    cout << "Enter name of student: ";
    cin >> att;

    int j = 0;

    for (int i = 0; i < userCount; i++)
    {
        if ((att == nameStudent[i]))
        {
            continue;
        }

        nameStudent[j] = nameStudent[i];
        cnic[j] = cnic[i];
        rollno[j] = rollno[i];
        city[j] = city[i];
        j++;
    }

    userCount = j;

    cout << "Reocrd deleted Sucessfully" << endl;
}

void allotRoom()
{
    string roomName;
    bool flag = false;
    cout << "Enter name of student: ";
    cin >> roomName;

    for (int i = 0; i < userCount; i++)
    {
        if ((roomName == nameStudent[i]))
        {
            cout << "Enter room number: ";
            cin >> room;
            flag = true;
        }
        else
        {
            flag = false;
        }
    }

    if (flag == false)
    {
        cout << "Record not found";
    }
    else if (flag == true)
    {
        cout << "\t" << roomName << "  Room number"
             << "\t" << room;
    }
}

string viewAttendence()
{

    cout << "\t\t\t\tAttendence" << endl;

    for (int i = 0; i < userCount; i++)
    {
        cout << nameStudent[i] <<" present for "<<days[i]<<" days" << endl;

       
    }

    cout << endl;
    cout << "\tPRESS any KEY to continue";
}

string takeAttendence()
{
    
    cout << "Enter name of student: ";
    cin >> att;


    for (int i = 0; i < userCount; i++)
    {
        if ((att == nameStudent[i]))
        {
            cout << "Days he was present: ";
            cin >> days[i];          
        }
    }

}

int attendenceMenu()
{
    int attOption;
    cout << "\t1.TAKE ATTENDECE" << endl;
    cout << "\t2.Check attendence" << endl;

    cout << "Enter your option: ";
    cin >> attOption;

    return attOption;
}

void updateStudent()
{
    string student;

    cout << "Enter name of student: " << endl;
    cin >> student;

    for (int i = 0; i <= userCount; i++)
    {
        if (student == nameStudent[i])
        {
            cout << "Enter roll no: ";
            cin >> rollno[i];

            cout << "Enter cnic: ";
            cin >> cnic[i];
            while (cnic[i].length() != 13)
            {
                cout << "INVALID!!" << endl;
                cout << "Enter again: ";
                cin >> cnic[i];
            }

            cout << "Enter city: ";
            cin >> city[i];
        }

        else
        {
            cout << "Record not found!!" << endl<< endl;
        }

        cout << "Enter 1 to update student record" << endl;
        cout << "Enter 2 to return to main menu" << endl;


    }
}

string Addnotice()
{

    cout << "Enter your notice: " << endl;
    cin.ignore();
    getline(cin, noticeBoard);

    cout << "\tPRESS any KEY to continue";
}

int notice()
{
    int noticeOption;
    cout << "\t1.Add a notice" << endl;
    cout << "\t2.View notice board" << endl;

    cout << "Enter your option: ";
    cin >> noticeOption;

    return noticeOption;
}

void updateMess()
{
    string updateDay;

    cout << "Enter day to update dish: ";
    cin >> updateDay;

    for (int i = 0; i < week; i++)
    {
        if (day[i] == updateDay)
        {
            cout << "Enter name of dish:";
            cin >> dish[i];
        }
    }

    cout << "Enter 1 to update meny" << endl;
    cout << "Enter 2 to return to main menu" << endl;
    

   
}

void MessMenu()
{
    cout << "\tDay"
         << "\t\t\t\tDish" << endl;

    for (int i = 0; i < week; i++)
    {
        cout << "\t" << day[i] << "\t\t\t\t" << dish[i] << endl;
        ;
    }
    cout << endl;
    cout << "\tPRESS any KEY to continue";
}

int mess()
{
    int messOption;
    cout << "\t1.View this month Mess" << endl;
    cout << "\t2.Update mess" << endl;

    cout << "Enter your option: ";
    cin >> messOption;

    return messOption;
}

void viewStudent()
{
    cout << "\t\tName"<< "\t\tCNIC/B Form"<< "\t\tRoll Number"<< "\t\tCity" << endl;
   
    for (int i = 0; i < userCount; i++)
    {
        cout << "\t\t" << nameStudent[i] << "\t\t" << cnic[i] << "\t\t" << rollno[i] << "\t\t\t" << city[i] << endl;
    }
}

void addStudent()
{

    cout << "Enter name of student: ";
    cin >> nameStudent[userCount];

    cout << "Enter roll no: ";
    cin >> rollno[userCount];

    cout << "Enter cnic: ";
    cin >> cnic[userCount];
    while (cnic[userCount].length() != 13)
    {
        cout << "INVALID!!" << endl;
        cout << "Enter again: ";
        cin >> cnic[userCount];
    }

    cout << "Enter city: ";
    cin >> city[userCount];

    cout << "Enter the password for student: ";
    cin >> pass[userCount];

    userCount++;

    cout << "Enter 1 to enter student" << endl;
    cout << "Enter 2 to return to main menu" << endl;
    

   
}

int accountsMenu()
{
    int option;

    cout << "\t 1.Check bills" << endl;
    cout << "\t 2.Calculate expenses" << endl;
    cout << "\t 3.Generate challans" << endl;
    cout << "\t 4.Update budget" << endl;
    cout << "\t 5.View monthly expenses" << endl;
    cout << "\t 6.Check student fees" << endl;
    cout << "\t 7.View financial report" << endl;
    cout << "\t 8.Transfer salaries" << endl;
    cout << "\t 9.See notices" << endl;
    cout << "\t 10.View financial records" << endl;
    cout << "\t 11.EXIT" << endl;

    cout << endl;
    cout << "\tEnter your option: ";
    cin >> option;
    cout << endl;

    return option;
}

int userMenu()
{
    int option;

    cout << "\t 1.View your information" << endl;
    cout << "\t 2.View mess menu" << endl;
    cout << "\t 3.Add a complaint" << endl;
    cout << "\t 4.See notices" << endl;
    cout << "\t 5.Pay fees" << endl;
    cout << "\t 6.Check bills" << endl;
    cout << "\t 7.View Attendence" << endl;
    cout << "\t 8.Register online" << endl;
    cout << "\t 9.Remove registration" << endl;
    cout << "\t 10.Review" << endl;
    cout << "\t 11.EXIT" << endl;

    cout << endl;
    cout << "\tEnter your option: ";
    cin >> option;
    cout << endl;

    return option;
}

int adminMenu()
{
    int option;
    cout << "\t 1.Add an hostelite" << endl;
    cout << "\t 2.Remove an hostelite" << endl;
    cout << "\t 3.Update record" << endl;
    cout << "\t 4.View hostelites" << endl;
    cout << "\t 5.Add a notice" << endl;
    cout << "\t 6.Attendence record" << endl;
    cout << "\t 7.View Complaints" << endl;
    cout << "\t 8.Mess information" << endl;
    cout << "\t 9.Payment records" << endl;
    cout << "\t 10.Allot rooms" << endl;
    cout << "\t 11.EXIT" << endl;

    cout << endl;
    cout << "\tEnter your option: ";
    cin >> option;
    cout << endl;

    return option;
}


int menu()
{
    int option;
    cout << "\t \t Log In as: " << endl;
    cout << "\t1. Admin" << endl;
    cout << "\t2. User" << endl;
    cout << "\t3. Accounts" << endl;
    cout << endl;
    cout << endl;

    cout << "Enter your option: ";
    cin >> option;

    return option;
}

void clearScreen()
{
    cout << "Press Any Key to Continue.." << endl;
    getch();
    system("cls");
}

void printHeader()
{
    cout << endl;
    cout << endl;

    cout << "\t \t \t ##     ##  ####     ####    ######       " << endl;
    cout << "\t \t \t ##     ##  ##  ## ##  ##  ##             " << endl;
    cout << "\t \t \t #########  ##    #    ##    ##           " << endl;
    cout << "\t \t \t ##     ##  ##         ##      ##         " << endl;
    cout << "\t \t \t ##     ##  ##         ##  ######         " << endl;

    cout << "\t \t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << "\t \t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << "\t \t. .                                                         . ." << endl;
    cout << "\t \t. .                                                         . ." << endl;
    cout << "\t \t. .                                                         . ." << endl;
    cout << "\t \t. .           WELCOME TO HOSTEL MANAGMENT SYSTEM            . ." << endl;
    cout << "\t \t. .                                                         . ." << endl;
    cout << "\t \t. .                                                         . ." << endl;
    cout << "\t \t. .                                                         . ." << endl;
    cout << "\t \t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;
    cout << "\t \t. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . ." << endl;

    cout << endl;
    cout << endl;
}





void setColor(int color) 
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}