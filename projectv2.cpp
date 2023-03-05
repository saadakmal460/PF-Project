#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/*Constant variables*/
const int week = 7;
const int id = 5;
const int size1 = 100;
const int size2 = 10;
const int size3 = 3;

/*Arrays*/
string nameStudent[size1], cnic[size1], city[size1], pass[size1];
string rollno[size1];
string rollnumber[size1];
string day[week] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};
string dish[week] = {"biryani", "chicken", "sabzi", "daal", "pualo", "sabzi", "daal"};
string bills[id] = {"Electricity", "Gas", "Water", "Internet", "Mess"};
string challan[size1], stdAmount[size1];
string budgetHead[size3] = {"bills", "salaries", "maintainance"};
string budgets[size3] = {"600000", "450000", "350000"};
string nameEmploye[size2] = {"ahmad", "bilal", "hamza", "imran", "ali", "amir", "farhan", "hassan", "usman", "zain"};
string employeNumber[size2] = {"1638", "2379", "2580", "3495", "3904", "5397", "6051", "7342", "8126", "9586"};
string days[size1];
string expenseTopic[size1], expenseAmount[size1];
string revenueTopic[size1], RevenueAmount[size1];
string notices[size1];
string complaints[size1];
string reviews[size1];
string billAmonut[id];

/*Linera Variables*/
string name, cnic2, city2, password2;
string roll2;
string noticeBoard;
string removeStudent;
string att, opt, choice, weekDay;
string room;
string complaint = "No complaints yet";
string challanNumber, amountTaken, stdRoll;
string userName, userPass;
string feeName;
string review;
string topic1, amount1;
string topic2, amount2;
string line;
string attendenceDays;
int challanCount = 0;
int daysCount = 0;
int studnetCount = 0;
int revenueCount = 0;
int expenseCount = 0;
int Rcount = 0;
int Ecount = 0;
int userCount = 0;
int complaintCount = 0;
int reviewCount = 0;
int noticesCount = 0;
bool flagForFee;
int amounts;

/*Functions Prototypes*/

/*Basic Functions*/
void gotoxy(int x, int y);
void printHeader();
void setColor(int color);
void path(string name);
string menu();

/*Main Menus*/
string adminMenu();
string userMenu();
string accountsMenu();

/*Admin Functions*/
void addStudent();
void students();
void storeStudents();
void loadStudnets();
void viewStudent();
void updateStudent();
void updateInFile();
void MessMenu();
void updateMess();
void allotRoom();
void storeAttendence();
void loadAttendence();
void remove();
void removeFromFile(int deletedIndex);
void Addnotice();
void viewNotices();
void storeNotices();
void loadNotices();
void takeAttendence();
void viewAttendence();
string notice();
string mess();
string parsingAttendence(string line, int num);
string parsing(string line, int num);
string attendenceMenu();

/*User FUNCTIONS*/
string reviewMenu();
string validateAccount(string acc);
void info(string name);
void AddComplaint();
void viewComplaint(string userName);
void storeComplaints();
void loadComplaints();
void viewAttendeceStudent(string name);
void Addreview();
void storeReviews();
void loadReviews();
void viewReviews();
void payFess();
void checkBills();
bool checkId(string name, string password);

/*Accounts Functions*/
string billsMenu();
string generateChallan();
string validateChallanNumber(string challan);
string validateAmount(string amount);
string menuBudget();
string salariesMenu();
string financialReport();
string finacialReportMenu();
string parsingRevenue(string line, int num);
string parsingExpense(string line, int num);
void addBills();
int convertingInt();
void viewBills();
void calculateExpense();
void checkfee();
void viewBudget();
void updateBudget();
void employesList();
void transferSalaris();
int convert(string num);
void view();
void graph();
void addingRevenue();
void addingExpenses();
void graphicalCalculations();
void storingExpenses();
void storingRevenu();
void storeRevenueInFile();
void loadRevenue();
void storingExpensesInFile();
void loadExpense();

/*Validations*/
string validationName(string name);
string validateRollNumber(string roll);
string validatingCity(string cityCheck);
string validatingCnic(string checkCnic);
string validatingPassword(string checkPass);
string validateOption(string option);
string validateMenu(string option);
string validateSubMenu(string option);
string validateNotices(string noticeBoard);

main()
{
    
    string loginOption = "0";
    string loginAdmin = "0";
    string loginUser = "0";

    string messMenu = "0";
    string noticeOpt = "0";

    /*Loading data*/
    printHeader();
    loadStudnets();
    loadAttendence();
    loadRevenue();
    loadExpense();
    loadNotices();
    loadComplaints();
    loadReviews();

    while (loginOption != "4")
    {

        system("cls");

        printHeader();
        path("");
        setColor(2);
        loginOption = menu();

        /*ADMIN*/
        if (loginOption == "1")
        {
            
            system("cls");
            printHeader();
            path(" Admin");
            string name, password, role;
            setColor(2);
            cout << "\tEnter your username: ";
            cin >> name;

            cout << "\tEnter your password: ";
            cin >> password;

            if (name == "admin" && password == "123")
            {
                system("cls");
                printHeader();

                while (loginOption != "11")
                {
                    system("cls");
                    printHeader();
                    path(" Admin >");
                    setColor(2);
                    loginAdmin = adminMenu();
                    if (loginAdmin == "1")
                    {
                        system("cls");
                        printHeader();

                        string adminOpt = "1";

                        while (adminOpt == "1")
                        {
                           
                            system("cls");
                            printHeader();
                            path(" Admin > Add student ");
                            setColor(2);
                            students();
                            addStudent();
                            storeStudents();

                            cin >> adminOpt;
                        }
                    }

                    else if (loginAdmin == "2")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > Remove student ");
                        setColor(2);
                        remove();
                        getch();
                    }

                    else if (loginAdmin == "3")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > Update student ");
                        setColor(2);

                        string adminOpt = "1";

                        while (adminOpt == "1")
                        {

                            system("cls");
                            printHeader();
                            setColor(2);
                            updateStudent();
                            updateInFile();
                            cout << "Enter 1 to update student record" << endl;
                            cout << "Enter 2 to return to main menu" << endl;
                            cin >> adminOpt;
                        }
                    }

                    else if (loginAdmin == "4")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > View student ");
                        setColor(2);
                        viewStudent();
                        getch();
                    }

                    else if (loginAdmin == "5")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > Notice ");
                        setColor(2);
                        noticeOpt = notice();

                        if (noticeOpt == "1")
                        {

                            system("cls");
                            printHeader();
                            path(" Admin > Notice > Add notice ");
                            setColor(2);
                            Addnotice();
                            storeNotices();
                            getch();
                        }

                        else if (noticeOpt == "2")
                        {
                            system("cls");
                            printHeader();
                            path(" Admin > Notice > View notice ");
                            setColor(2);
                            viewNotices();
                            getch();
                        }
                    }

                    else if (loginAdmin == "6")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > Attendence");
                        setColor(2);
                        string attendence = attendenceMenu();
                        
                        if (attendence == "1")
                        {
                            system("cls");
                            printHeader();
                            path(" Admin > Attendence > Take Attendence ");
                            setColor(2);
                            takeAttendence();
                            storeAttendence();
                            getch();
                        }

                        else if (attendence == "2")
                        {
                            system("cls");
                            printHeader();
                            path(" Admin > Attendence > View Attendence ");
                            setColor(2);
                            viewAttendence();
                            getch();
                        }
                    }

                    else if (loginAdmin == "7")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > View compalint ");
                        setColor(2);
                        viewComplaint(userName);
                        getch();
                    }

                    else if (loginAdmin == "8")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > Mess ");
                        setColor(2);
                        messMenu = mess();

                        if (messMenu == "1")
                        {
                            system("cls");
                            printHeader();
                            path(" Admin > Mess > Mess Menu ");
                            setColor(2);
                            MessMenu();
                            getch();
                        }

                        else if (messMenu == "2")
                        {
                            system("cls");
                            printHeader();
                            path(" Admin > Mess > Update Mess ");
                            setColor(2);
                            string opt = "1";
                            while (opt == "1")
                            {
                                system("cls");
                                printHeader();
                                setColor(2);
                                updateMess();
                                cin >> opt;
                            }
                        }
                    }

                    else if (loginAdmin == "9")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > Financial Record ");
                        setColor(2);
                        string finance = financialReport();
                        if (finance == "1")
                        {
                            system("cls");
                            printHeader();
                            setColor(2);
                            view();
                            getch();
                        }

                        else if (finance == "2")
                        {
                            system("cls");
                            printHeader();
                            graphicalCalculations();
                            graph();
                            getch();
                        }
                        else if (finance == "3")
                        {
                            cout << "You have no acsess to this functionality" << endl;
                        }
                        getch();
                    }

                    else if (loginAdmin == "10")
                    {
                        system("cls");
                        printHeader();
                        path(" Admin > Allot rooms ");
                        setColor(2);
                        allotRoom();
                        getch();
                    }

                    else if (loginAdmin == "11")
                    {

                        break;
                    }
                }
            }

            else
            {
                setColor(2);
                cout << "Invalid info" << endl;
                cout << "Enter 1 to return" << endl;
                getch();
            }
        }

        /*USER*/

        else if (loginOption == "2")
        {
            system("cls");
            printHeader();
            path(" User Login ");
            setColor(2);
            cout << "\tEnter your userName: ";
            cin >> userName;

            cout << "\tEnter your userPass: ";
            cin >> userPass;

            bool check = checkId(userName, userPass);

            if (check == true)
            {
                system("cls");
                printHeader();

                while (loginUser != "11")
                {
                    system("cls");
                    printHeader();
                    path(" User Menu");
                    setColor(2);
                    string loginUser = userMenu();
                    if (loginUser == "1")
                    {
                        system("cls");
                        printHeader();
                        path(" User Menu > Info");
                        setColor(2);
                        info(userName);
                        getch();
                    }

                    else if (loginUser == "2")
                    {
                        system("cls");
                        printHeader();
                        path(" User Menu > Mess Menu");
                        setColor(2);
                        MessMenu();
                        getch();
                    }

                    else if (loginUser == "3")
                    {
                        system("cls");
                        printHeader();
                        path(" User Menu > Add complaint ");
                        setColor(2);
                        AddComplaint();
                        storeComplaints();
                        getch();
                    }

                    else if (loginUser == "4")
                    {
                        system("cls");
                        printHeader();
                        path(" User Menu > Notice board");
                        setColor(2);
                        viewNotices();
                        getch();
                    }

                    else if (loginUser == "5")
                    {
                        system("cls");
                        printHeader();
                        path(" User Menu > Pay fees");
                        setColor(2);
                        payFess();
                        getch();
                    }

                    else if (loginUser == "6")
                    {
                        system("cls");
                        printHeader();
                        path(" User Menu > Check bills");
                        setColor(2);
                        checkBills();
                        getch();
                    }

                    else if (loginUser == "7")
                    {
                        system("cls");
                        printHeader();
                        path(" User Menu > View attendence");
                        setColor(2);
                        viewAttendeceStudent(userName);
                        getch();
                    }

                    else if (loginUser == "8")
                    {
                        system("cls");
                        printHeader();
                        path(" User Menu > Remove");
                        setColor(2);
                        remove();
                        getch();
                        break;
                    }

                    else if (loginUser == "9")
                    {
                        string menu;
                        system("cls");
                        printHeader();
                        path(" User Menu > Review");
                        setColor(2);
                        menu = reviewMenu();

                        if (menu == "1")
                        {
                            system("cls");
                            printHeader();
                            path(" User Menu > Review > Add review");
                            setColor(2);
                            Addreview();
                            storeReviews();
                            getch();
                        }
                        else if (menu == "2")
                        {
                            system("cls");
                            printHeader();
                            path(" User Menu > View review");
                            setColor(2);
                            viewReviews();
                            getch();
                        }
                    }

                    else if (loginUser == "10")
                    {
                        break;
                    }
                }
            }

            else
            {
                setColor(2);
                cout << "Invalid info" << endl;
                cout << "Enter 1 to return" << endl;
                getch();
            }
        }

        /*Accounts Ofiice*/

        else if (loginOption == "3")
        {
            string accName, accPass;
            system("cls");
            printHeader();
            setColor(2);
            cout << "Enter you username: ";
            cin >> accName;

            cout << "Enter your password: ";
            cin >> accPass;

            if ((accName == "accounts") && (accPass == "123"))
            {
                string loginAcc = "0";
                while (loginAcc != "11")
                {
                    system("cls");
                    printHeader();
                    path(" Accounts");
                    setColor(2);
                    loginAcc = accountsMenu();

                    if (loginAcc == "1")
                    {

                        system("cls");
                        printHeader();
                        path(" Accounts > Bills Menu");
                        setColor(2);
                        string bills = billsMenu();

                        if (bills == "1")
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > Add Bills");
                            setColor(2);
                            addBills();
                            getch();
                        }

                        else if (bills == "2")
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > View Bills");
                            setColor(2);
                            viewBills();
                            getch();
                        }
                    }

                    else if (loginAcc == "2")
                    {
                        system("cls");
                        printHeader();
                        path(" Accounts > Calculate expenses");
                        setColor(2);
                        calculateExpense();
                        getch();
                    }

                    else if (loginAcc == "3")
                    {
                        system("cls");
                        printHeader();
                        setColor(2);

                        while (generateChallan() == "1")
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > Generate Challans");
                            setColor(2);
                            generateChallan();
                            getch();
                        }
                    }

                    else if (loginAcc == "4")
                    {
                        system("cls");
                        printHeader();
                        setColor(2);
                        string mBudget = menuBudget();
                        if (mBudget  == "1")
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > View budget");
                            setColor(2);
                            viewBudget();
                            getch();
                        }

                        else if (mBudget == "2")
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > Update Budget");
                            setColor(2);
                            updateBudget();
                            getch();
                        }
                    }

                    else if (loginAcc == "5")
                    {
                        system("cls");
                        printHeader();
                        path(" Accounts > View bills");
                        setColor(2);
                        viewBills();
                        getch();
                    }

                    else if (loginAcc == "6")
                    {
                        system("cls");
                        printHeader();
                        path(" Accounts > Check Fee");
                        setColor(2);
                        checkfee();
                        getch();
                    }

                    else if (loginAcc == "7")
                    {
                        system("cls");
                        printHeader();
                        path(" Accounts > Financial Report");
                        setColor(2);
                        string finance = financialReport();
                        if (finance == "1")
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > View Financial Report");
                            setColor(2);
                            view();
                            getch();
                        }

                        else if (finance == "2")
                        {
                            system("cls");
                            printHeader();
                            graphicalCalculations();
                            graph();
                            getch();
                        }

                        else if (finance == "3")
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > Adding report");
                            setColor(2);
                            string opt = "1";
                            string opt2 = "1";
                            string financeMenu = finacialReportMenu();
                            if (financeMenu == "1")
                            {
                                while (opt == "1")
                                {
                                    system("cls");
                                    printHeader();
                                    path(" Accounts > Adding report > Adding revenue");
                                    setColor(2);
                                    addingRevenue();
                                    storingRevenu();
                                    storeRevenueInFile();
                                    cin >> opt;
                                }
                            }
                            if (financeMenu == "2")
                            {
                                while (opt2 == "1")
                                {
                                    system("cls");
                                    printHeader();
                                    path(" Accounts > Adding report > Adding expenses");
                                    setColor(2);
                                    addingExpenses();
                                    storingExpenses();
                                    storingExpensesInFile();
                                    cin >> opt2;
                                }
                            }
                        }
                    }

                    else if (loginAcc == "8")
                    {
                        system("cls");
                        printHeader();
                        path(" Accounts > Adding report > Transfer Salaries");
                        setColor(2);
                        if (salariesMenu() == "1")
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > Employe list");
                            setColor(2);
                            employesList();
                            getch();
                        }

                        else
                        {
                            system("cls");
                            printHeader();
                            path(" Accounts > Adding report > Transfer Salaries");
                            setColor(2);
                            transferSalaris();
                            getch();
                        }
                    }

                    else if (loginAcc == "9")
                    {
                        system("cls");
                        printHeader();
                        path(" Accounts > View notices");
                        setColor(2);
                        viewNotices();
                        getch();
                    }

                    else if (loginAcc == "10")
                    {
                        break;
                    }
                }
            }

            else
            {
                setColor(2);
                cout << "INVALID!!";
                cout << "press 1 to return";
            }
        }
    }
    setColor(7);
}

/*FUNCTIONS*/

void graph()
{
    char box = 219;
    cout << "GRAPHICAL Respresentation" << endl;
    cout << endl;

    cout << "    |                         " << endl;
    cout << "    |                         " << endl;
    cout << "    |                         " << endl;
    cout << "  1M|                         " << endl;
    cout << "    |                         " << endl;
    cout << "100k|                         " << endl;
    cout << "    |                         " << endl;
    cout << " 10k|                         " << endl;
    cout << "    |                         " << endl;
    cout << "  1k|                         " << endl;
    cout << "    |                         " << endl;
    cout << "    |                         " << endl;
    cout << "    |___________________________________" << endl;

    for (int i = 0; i < Rcount; i++)
    {
        setColor(2);
        gotoxy(10, 33 - i);
        cout << box << endl;
        setColor(7);
    }
    for (int i = 0; i < Ecount; i++)
    {
        setColor(4);
        gotoxy(17, 33 - i);
        cout << box << endl;
        setColor(7);
    }
    if (Rcount > Ecount)
    {
        gotoxy(45 , 25);
        cout << "Revenue is greater than expenses"<<endl;
    }
    else
    {
        gotoxy(45 , 25);
        cout << "Expenses are rising beaware"<<endl;
    }
    
    gotoxy(42, 30);
    setColor(2);
    cout << box << " Revenue" << endl;
    setColor(7);
    gotoxy(42, 33);
    setColor(4);
    cout << box << " Expense" << endl;
    setColor(7);

    Rcount = 0;
    Ecount = 0;
}

void graphicalCalculations()
{
    int amount = 0;
    int amount2 = 0;
    int num;
    int num2;

    for (int i = 0; i < revenueCount; i++)
    {
        stringstream ss(RevenueAmount[i]);
        if (ss >> num)
        {
            amount = amount + num;
        }
    }

    while (amount != 0)
    {
        amount = amount / 10;
        Rcount++;
    }

    for (int i = 0; i < expenseCount; i++)
    {
        stringstream ss(expenseAmount[i]);
        if (ss >> num2)
        {
            amount2 = amount2 + num2;
        }
    }

    while (amount2 != 0)
    {
        amount2 = amount2 / 10;
        Ecount++;
    }
}

void view()
{

    cout << "Revenue" << endl;
    cout << "_______________________________________" << endl;
    for (int i = 0; i < revenueCount; i++)
    {
        cout << revenueTopic[i] << "\t\t\t\t" << RevenueAmount[i] << endl;
    }
    cout << "_______________________________________" << endl
         << endl;
    cout << "Expenses" << endl;
    cout << "_______________________________________" << endl;
    for (int i = 0; i < expenseCount; i++)
    {
        cout << expenseTopic[i] << "\t\t\t\t" << expenseAmount[i] << endl;
    }
}

string financialReport()
{
    string opt;

    cout << "1.View financial report" << endl;
    cout << "2.View graphical analysis" << endl;
    cout << "3.Add financial report" << endl;
    cout << "Enter your option" << endl;

    cin >> opt;

    return opt;
}

string finacialReportMenu()
{
    string option;
    cout << "\t1.Enter revenue" << endl;
    cout << "\t2.Enter expenses" << endl;
    cout << "Enter your option" << endl;
    cin >> option;

    return option;
}

void addingRevenue()
{

    cout << "Enter revenue source: ";
    cin.ignore();
    getline(cin, topic1);

    cout << "Enter revenue amount: ";
    cin >> amount1;
    amount1 = validateAmount(amount1);

    cout << "Enter 1 to enter another menu" << endl;
    cout << "Enter 2 to exit" << endl;
}

void storingRevenu()
{
    revenueTopic[revenueCount] = topic1;
    RevenueAmount[revenueCount] = amount1;
    revenueCount++;
}

void loadRevenue()
{
    string line;
    fstream file;
    file.open("revenu.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        revenueTopic[revenueCount] = parsingRevenue(line, 1);
        RevenueAmount[revenueCount] = parsingRevenue(line, 2);
        revenueCount++;
    }
    file.close();
}

string parsingRevenue(string line, int num)
{
    int count = 1;
    string temp;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            count = count + 1;
        }
        else if (count == num)
        {
            temp = temp + line[i];
        }
    }
    return temp;
}

void storeRevenueInFile()
{
    fstream file;
    char comma = ',';
    file.open("revenu.txt", ios ::app);

    file << topic1 << comma;
    file << amount1 << endl;
    file.close();
}

void addingExpenses()
{
    cout << "Enter expense source: ";
    cin.ignore();
    getline(cin, topic2);

    cout << "Enter expense amount: ";
    cin >> amount2;

    amount2 = validateAmount(amount2);

    cout << "Enter 1 to enter another menu" << endl;
    cout << "Enter 2 to exit" << endl;
}

void storingExpenses()
{
    expenseTopic[expenseCount] = topic2;
    expenseAmount[expenseCount] = amount2;
    expenseCount++;
}

void loadExpense()
{
    string line;
    fstream file;
    file.open("expense.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        expenseTopic[expenseCount] = parsingRevenue(line, 1);
        expenseAmount[expenseCount] = parsingRevenue(line, 2);
        expenseCount++;
    }
    file.close();
}

string parsingExpense(string line, int num)
{
    int count = 1;
    string temp;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            count = count + 1;
        }
        else if (count == num)
        {
            temp = temp + line[i];
        }
    }
    return temp;
}

void storingExpensesInFile()
{
    fstream file;
    char comma = ',';
    file.open("expense.txt", ios ::app);

    file << topic2 << comma;
    file << amount2 << endl;
    file.close();
}

void transferSalaris()
{
    string name, number , amountR;
    int total ,sum = 0, budget = 450000;
    bool flagb = true;

    cout << "Enter name of employe: ";
    cin >> name;

    cout << "Enter employe number: ";
    cin >> number;

    for (int i = 0; i < 10; i++)
    {
        if ((name == nameEmploye[i]) && (number == employeNumber[i]))
        {
            cout << "Enter amount: ";
            cin >> amountR;
            amountR = validateAmount(amountR);
            total = convert(amountR);
            sum = sum + total;
            if (sum < budget)
            {
                cout << "Remainning budget = " << budget - sum << endl;
                cout << "Salary transfered succesfully" << endl;
            }
            else
            {
                cout << "Not enough budget!!" << endl;
            }
        }

        else
        {
            flagb = false;
        }
    }

    cout << "Press any key to continue" << endl;
}

int convert(string num)
{
    int num2;
    stringstream ss(num);
    ss >> num2;
    return num2;

}

void employesList()
{
    cout << "\t\tName\t\t\tEmploye Number" << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "\t\t" << nameEmploye[i] << "\t\t\t" << employeNumber[i] << endl;
    }
}

string salariesMenu()
{
    string opt;
    cout << "\t1.View list of employes" << endl;
    cout << "\t2.Tranfer salaraies" << endl;

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
            budgets[i] = validateAmount(budgets[i]);
        }
    }

    cout << "Record updated sucessfully" << endl;
    cout << "Press any key to continue" << endl;
}

void viewBudget()
{
    cout << "\tBudget for Bills\t\tBudget for salaries\t\tBudget for maintainance" << endl;
    for (int i = 0; i < 4; i++)
    {

        cout << "\t" << budgets[i] << "\t\t\t";
    }
    cout << endl;
    cout << "Press any key to continue" << endl;
}

string menuBudget()
{
    string opt;
    cout << "\t1.View current budget" << endl;
    cout << "\t2.Update budget" << endl;
    cout << "Enter your option: ";
    cin >> opt;

    return opt;
}

void checkfee()
{
    string student;
    bool check = false;
    bool check2;

    cout << "Enter roll number of student" << endl;
    cin >> student;

    for (int i = 0; i < userCount; i++)
    {
        if ((student == rollno[i]) && (flagForFee == true))
        {
            check = true;
        }
        else if (student != rollno[i])
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
        cout << "Fee was paid" << endl;
    }
    else if (check2 == false)
    {
        cout << "Record not found" << endl;
    }
    else
    {
        cout << "Fee not paid" << endl;
    }

    cout << "Pree any key to continue" << endl;
}

string generateChallan()
{

    string opt, check;

    check = "Not Found";
    cout << "Enter roll number of student: ";
    cin >> stdRoll;

    for (int i = 0; i < userCount; i++)
    {
        if (stdRoll == rollno[i])
        {
            check = "Found";
            cout << "Enter challan number: ";
            cin >> challanNumber;
            challanNumber = validateChallanNumber(challanNumber);
            challan[i] = challanNumber;

            cout << "Enter amount of fees: ";
            cin >> amountTaken;
            amountTaken = validateAmount(amountTaken);
            stdAmount[i] = amountTaken;
            

            break;
        }
    }

    if (check == "Not Found")
    {
        cout << "NO record of student found" << endl;
    }

    cout << "Press 1 to generate another challan" << endl;
    cout << "Press 2 to return" << endl;

    cin >> opt;

    return opt;
}

string validateChallanNumber(string challan)
{
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < challan.length(); i++)
        {
            if (challan[i] < 48 || challan[i] > 57)
            {
                flag = false;
                break;
            }
        }
        if (challan.length() < 5 || !flag)
        {
            cout << "INVALID!!!"<<endl;
            cin >> challan;
        }
        else
        {
            return challan;
        }
        
        
    }
    
}

string validateAmount(string amount)
{
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < amount.length(); i++)
        {
            if (amount[i] < 48 || amount[i] > 57)
            {
                flag = false;
                break;
            }
        }
        if (amount.length() < 1 || !flag)
        {
            cout << "INVALID!!!"<<endl;
            cin >> amount;
        }
        else
        {
            return amount;
        }
        
        
    }

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
        amounts = convertingInt();
        sum = sum + amounts;
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
        billAmonut[i] = validateAmount(billAmonut[i]);
       
    }

    cout << "Press any key to exit" << endl;
}


int convertingInt()
{
    for (int i = 0; i < id; i++)
    {
       stringstream ss(billAmonut[i]);
        ss >> amounts;
    }
   return amounts; 

}

string billsMenu()
{
    string option;
    cout << "\t 1.Add this month bills" << endl;
    cout << "\t 2.View this month bills" << endl;

    cin >> option;
    option = validateSubMenu(option);

    return option;
}

void Addreview()
{

    cout << "Enter your review about hostel: " << endl;
    cin.ignore();
    getline(cin, review);
    review = validateNotices(review);
    reviews[reviewCount] = review;
    reviewCount++;
    cout << "\tPRESS any KEY to continue";
}

void storeReviews()
{
    fstream file;
    char comma = ',';
    file.open("reviews.txt", ios::app);
    file << review << endl;
    file.close();
}
void loadReviews()
{
    fstream file;
    file.open("reviews.txt", ios::in);

    while (!file.eof())
    {
        getline(file, reviews[reviewCount]);
        reviewCount++;
    }
    file.close();
}

void viewReviews()
{
    for (int i = 0; i < reviewCount; i++)
    {
        cout << "\t\t" << reviews[i] << endl;
    }
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
    cout << "\tMess\t\t\tLaundaray\t\t\tSecurity fees\t\t\tOthers" << endl;
    cout << "\t10000\t\t\t3000\t\t\t\t250670\t\t\t10000" << endl;
}

void payFess()
{
    int i = 0;
    string bank, account, challanNo, amonut;
    bool flag1, flag2, flag3 = false;

    cout << "\tEnter name of bank: ";
    cin >> bank;
    bank = validateNotices(bank);

    cout << "\tEnter bank account number: ";
    cin >> account;
    account = validateAccount(account);

    
    cout << "\tEnter challan number: ";
    cin >> challanNo;

    for (i = 0; i < userCount; i++)
    {
        if (challanNo == challan[i])
        {
            flag3 = true;
            break;
        }
    }

    while (flag3 == false)
    {
        cout << "INVALID Challan number" << endl;
        cin >> challanNo;

        for (i = 0; i < userCount; i++)
        {
            if (challanNo == challan[i])
            {
                flag3 = true;
                break;
            }
        }
    }

    cout << "Enter amount: ";
    cin >> amonut;

    while (amonut != stdAmount[i])
    {
        cout << "INVALID !! Enter proper amonut" << endl;
        cin >> amonut;
    }
    flagForFee = true;

    cout << "\tFEE paid sucessfully" << endl;
}

string validateAccount(string acc)
{
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < acc.length(); i++)
        {
            if (acc[i] < 48 || acc[i] > 57)
            {
                flag = false;
                break;
            }
        }
        if (acc.length() < 16 || !flag)
        {
            cout << "INVALID ACCOUNT number"<<endl;
            cout << "Enter again: ";
            cin >> acc;
        }
        else
        {
            return acc;
        }
        
    }
}

void viewAttendeceStudent(string name)
{
    for (int i = 0; i < userCount; i++)
    {
        if (name == nameStudent[i])
        {
            cout << nameStudent[i] << "\t\t"
                 << " present for " << days[i] << " days" << endl;
        }
    }

    cout << "Press any key to continue" << endl;
}

void AddComplaint()
{

    cout << "Enter your complaint: " << endl;
    cin.ignore();
    getline(cin, complaint);
    complaint = validateNotices(complaint);
    complaints[complaintCount] = complaint;
    complaintCount++;

    cout << "\tPRESS any KEY to continue";
}

void storeComplaints()
{
    fstream file;
    char comma = ',';
    file.open("complaints.txt", ios::app);
    file << complaint << endl;
    file.close();
}

void loadComplaints()
{
    fstream file;
    file.open("complaints.txt", ios::in);

    while (!file.eof())
    {
        getline(file, complaints[complaintCount]);
        complaintCount++;
    }
    file.close();
}

void viewComplaint(string name)
{
    cout << "\t COMPLAINT BOX" << endl;

    for (int i = 0; i <= complaintCount; i++)
    {

        cout << "\t\t\t" << complaints[i] << endl;
    }
}

void info(string name)
{
    for (int i = 0; i <= userCount; i++)
    {
        if ((name == nameStudent[i]))
        {
            cout << "\t\tName"
                 << "\t\tCNIC/B Form"
                 << "\t\tRoll Number"
                 << "\t\tCity" << endl;
            cout << "\t\t" << nameStudent[i] << "\t\t" << cnic[i] << "\t\t" << rollno[i] << "\t\t\t" << city[i] << "\t\t\t" << challan[i] << endl;
        }
    }
    cout << "PRESS ANY key to continue" << endl;
}

bool checkId(string name, string password)
{

    bool flag = false;

    for (int i = 0; i < userCount; i++)
    {
        if (name == nameStudent[i] && password == pass[i])
        {
            flag = true;
            break;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}

void remove()
{

    cout << "Enter name of student: ";
    cin >> removeStudent;

    int j = 0;

    for (int i = 0; i < userCount; i++)
    {
        if ((removeStudent == nameStudent[i]))
        {
            continue;
        }

        nameStudent[j] = nameStudent[i];
        cnic[j] = cnic[i];
        rollno[j] = rollno[i];
        city[j] = city[i];
        pass[j] = pass[i];
        j++;
        removeFromFile(i);
    }

    userCount = j;

    cout << "Reocrd deleted Sucessfully" << endl;
}

void removeFromFile(int deletedIndex)
{
    fstream file;
    char comma = ',';
    file.open("studentRecords.txt", ios::out);
    for (int i = 0; i < userCount - 1; i++)
    {
        if (i != deletedIndex)
        {
            file << nameStudent[i] << comma;
            file << cnic[i] << comma;
            file << rollno[i] << comma;
            file << city[i] << comma;
            file << pass[i] << endl;
        }
    }
    file.close();

    for (int i = deletedIndex; i < userCount - 1; i++)
    {
        nameStudent[i] = nameStudent[i + 1];
        cnic[i] = cnic[i + 1];
        rollno[i] = rollno[i + 1];
        city[i] = city[i + 1];
        pass[i] = pass[i + 1];
    }

    userCount--;
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
            flag = true;
            break;
        }
        else
        {
            continue;
        }
    }

    if (flag == false)
    {
        cout << "Record not found";
    }
    else if (flag == true)
    {
        cout << "Enter room number: ";
        cin >> room;
        room = validateMenu(room);
        cout << "\t" << roomName << "  Room number"
             << "\t" << room;
    }
}

void viewAttendence()
{

    cout << "\t\t\t\tAttendence" << endl;

    for (int i = 0; i < userCount; i++)
    {
        cout << nameStudent[i] << " present for " << days[i] << " days" << endl;
    }

    cout << endl;
    cout << "\tPRESS any KEY to continue";
}

void takeAttendence()
{
    cout << "Enter name of student: ";
    cin >> att;

    for (int i = 0; i < userCount; i++)
    {
        if ((att == nameStudent[i]))
        {
            cout << "Days he was present: ";
            cin >> attendenceDays;
            attendenceDays = validateMenu(attendenceDays);
            days[i] = attendenceDays;
        }
    }
    

    //daysCount++;
}

void loadAttendence()
{
    string line;
    fstream file;
    file.open("attendence.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        nameStudent[userCount] = parsingAttendence(line, 1);
        days[daysCount] = parsingRevenue(line, 2);
        daysCount++;
    }
    file.close();
}

string parsingAttendence(string line, int num)
{
    int count = 1;
    string temp;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            count = count + 1;
        }
        else if (count == num)
        {
            temp = temp + line[i];
        }
    }
    return temp;
}

void storeAttendence()
{
    fstream file;
    char comma = ',';
    file.open("attendence.txt", ios ::app);

    file << att << comma;
    file << attendenceDays << endl;
    file.close();
}

string attendenceMenu()
{
    string attOption;
    cout << "\t1.TAKE ATTENDECE" << endl;
    cout << "\t2.Check attendence" << endl;

    cout << "Enter your option: ";
    cin >> attOption;

    attOption = validateSubMenu(attOption);

    return attOption;
}

void updateStudent()
{
    string student, stdRoll, stdCnic, stdCity;
    bool flag = false;

    cout << "Enter name of student: " << endl;
    cin >> student;

    for (int i = 0; i <= userCount; i++)
    {
        if (student == nameStudent[i])
        {
            flag = true;
            cout << "Enter roll no: ";
            cin >> stdRoll;
            stdRoll =validateAmount(stdRoll);

            cout << "Enter cnic: ";
            cin >> stdCnic;
            stdCnic =validatingCnic(stdCnic);

            cout << "Enter city: ";
            cin >> stdCity;
            stdCity =validatingCity(stdCity);

            rollno[i] = stdRoll;
            cnic[i] = stdCnic;
            city[i] = stdCity;

            break;
        }

        else
        {
            continue;
        }

        if (flag == false)
        {
            cout << "No record found" << endl;
        }
    }
}

void updateInFile()
{
    fstream file;
    char comma = ',';
    file.open("studentRecords.txt", ios ::out);
    for (int i = 0; i < userCount; i++)
    {
        file << nameStudent[i] << comma;
        file << cnic[i] << comma;
        file << rollno[i] << comma;
        file << city[i] << comma;
        file << pass[i] << endl;
    }
    file.close();
}

void Addnotice()
{

    cout << "Enter your notice: " << endl;
    cin.ignore();
    getline(cin, noticeBoard);
    noticeBoard = validateNotices(noticeBoard);
    notices[noticesCount] = noticeBoard;
    noticesCount++;

    cout << "\tPRESS any KEY to continue";
}

string validateNotices(string noticeBoard)
{
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < noticeBoard.length(); i++)
        {
            if (noticeBoard[i] > 33 && noticeBoard[i] < 47)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            cout << "INVALID!!" << endl;
            cout << "Enter again: ";
            cin >> noticeBoard;
        }
        else
        {
            return noticeBoard;
        }
    }
}

void viewNotices()
{
    cout << "NOTICE BOARD" << endl;
    for (int i = 0; i < noticesCount; i++)
    {
        cout << "\t\t\t" << notices[i] << endl;
    }
}

void storeNotices()
{
    fstream file;
    char comma = ',';
    file.open("notices.txt", ios::app);
    file << noticeBoard << endl;
    file.close();
}

void loadNotices()
{
    fstream file;
    file.open("notices.txt", ios::in);

    while (!file.eof())
    {
        getline(file, notices[noticesCount]);
        noticesCount++;
    }
    file.close();
}

string notice()
{
    string noticeOption;
    cout << "\t1.Add a notice" << endl;
    cout << "\t2.View notice board" << endl;

    cout << "Enter your option: ";
    cin >> noticeOption;
    noticeOption = validateSubMenu(noticeOption);

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
            dish[i] = validatingCity(dish[i]);
        }
    }

    cout << "Enter 1 to update menu" << endl;
    cout << "Enter 2 to return to main menu" << endl;
}

void MessMenu()
{
    cout << "\tDay"
         << "\t\t\t\tDish" << endl;

    for (int i = 0; i < week; i++)
    {
        cout << "\t" << day[i] << "\t\t\t\t" << dish[i] << endl;
    }
    cout << endl;
    cout << "\tPRESS any KEY to continue";
}

string mess()
{
    string messOption;
    cout << "\t1.View this month Mess" << endl;
    cout << "\t2.Update mess" << endl;

    cout << "Enter your option: ";
    cin >> messOption;
    messOption = validateSubMenu(messOption);

    return messOption;
}

void viewStudent()
{
    string tempRollno;
    string tempName, tempCnic, tempCity, tempPass;
    cout << "\t\tName"
         << "\t\tCNIC/B Form"
         << "\t\tRoll Number"
         << "\t\tCity"
         << "\t\t\tPassword" << endl;

    for (int i = 0; i < userCount; i++)
    {
        for (int j = 0; j < userCount - i - 1; j++)
        {
            if (rollno[j] > rollno[j + 1])
            {
                tempRollno = rollno[j];
                rollno[j] = rollno[j + 1];
                rollno[j + 1] = tempRollno;

                /*Changing name*/
                tempName = nameStudent[j];
                nameStudent[j] = nameStudent[j + 1];
                nameStudent[j + 1] = tempName;

                /*Chnaging cnic*/
                tempCnic = cnic[j];
                cnic[j] = cnic[j + 1];
                cnic[j + 1] = tempCnic;

                /*Chnaging city */
                tempCity = city[j];
                city[j] = city[j + 1];
                city[j + 1] = tempCity;

                /*Chnaging pass*/
                tempPass = pass[j];
                pass[j] = pass[j + 1];
                pass[j + 1] = tempPass;
            }
        }
    }

    for (int i = 0; i < userCount; i++)
    {
        cout << "\t\t" << nameStudent[i] << "\t\t" << cnic[i] << "\t\t" << rollno[i] << "\t\t\t" << city[i] << "\t\t\t" << pass[i] << endl;
    }
}

void addStudent()
{

    nameStudent[userCount] = name;

    rollno[userCount] = roll2;

    cnic[userCount] = cnic2;

    city[userCount] = city2;

    pass[userCount] = password2;

    userCount++;

    cout << "Enter 1 to enter student" << endl;
    cout << "Enter 2 to return to main menu" << endl;
}

void loadStudnets()
{
    string line;
    fstream file;
    file.open("studentRecords.txt", ios::in);
    while (!file.eof())
    {
        getline(file, line);
        nameStudent[userCount] = parsing(line, 1);
        cnic[userCount] = parsing(line, 2);
        rollno[userCount] = parsing(line, 3);
        city[userCount] = parsing(line, 4);
        pass[userCount] = parsing(line, 5);
        userCount++;
    }
    file.close();
}

string parsing(string line, int num)
{
    int count = 1;
    string temp;
    for (int i = 0; i < line.length(); i++)
    {
        if (line[i] == ',')
        {
            count = count + 1;
        }
        else if (count == num)
        {
            temp = temp + line[i];
        }
    }
    return temp;
}

void storeStudents()
{
    fstream file;
    char comma = ',';
    file.open("studentRecords.txt", ios ::app);

    file << name << comma;
    file << cnic2 << comma;
    file << roll2 << comma;
    file << city2 << comma;
    file << password2 << endl;
    file.close();
}

string accountsMenu()
{
    string option;

    cout << "\t 1.Check bills" << endl;
    cout << "\t 2.Calculate expenses" << endl;
    cout << "\t 3.Generate challans" << endl;
    cout << "\t 4.Update budget" << endl;
    cout << "\t 5.View monthly expenses" << endl;
    cout << "\t 6.Check student fees" << endl;
    cout << "\t 7.View financial report" << endl;
    cout << "\t 8.Transfer salaries" << endl;
    cout << "\t 9.See notices" << endl;
    cout << "\t 10.EXIT" << endl;

    cout << endl;
    cout << "\tEnter your option: ";
    cin >> option;
    option = validateMenu(option);

    return option;
}

string userMenu()
{
    string option;
    cout << "\t 1.View your information" << endl; 
    cout << "\t 2.View mess menu" << endl;        
    cout << "\t 3.Add a complaint" << endl;       
    cout << "\t 4.See notices" << endl;           
    cout << "\t 5.Pay fees" << endl;
    cout << "\t 6.Check bills" << endl;         
    cout << "\t 7.View Attendence" << endl;     
    cout << "\t 8.Remove registration" << endl; 
    cout << "\t 9.Review" << endl;              
    cout << "\t 10.EXIT" << endl;

    cout << endl;
    cout << "\tEnter your option: ";
    cin >> option;
    option = validateMenu(option);

    return option;
}

string adminMenu()
{
    string option;
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
    option = validateMenu(option);

    return option;
}

string menu()
{

    string option;
    cout << "\t \t Log In as: " << endl;
    cout << "\t1. Admin" << endl;
    cout << "\t2. User" << endl;
    cout << "\t3. Accounts" << endl;
    cout << "\t4. EXIT" << endl;
    cout << endl;
    cout << endl;

    cout << "Enter your option: ";
    cin >> option;
    option = validateOption(option);
    setColor(7);
    return option;
}

void printHeader()
{
    cout << endl;
    cout << endl;
    setColor(3);
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
    setColor(7);
    cout << endl;
    cout << endl;
}

void students()
{
    cout << "Enter name of student: ";
    cin >> name;
    name = validationName(name);

    cout << "Enter roll no: ";
    cin >> roll2;
    roll2 = validateRollNumber(roll2);

    cout << "Enter cnic: ";
    cin >> cnic2;
    cnic2 = validatingCnic(cnic2);

    cout << "Enter city: ";
    cin >> city2;
    city2 = validatingCity(city2);

    cout << "Enter the password for student: ";
    cin >> password2;
    password2 = validatingPassword(password2);
}

string validateSubMenu(string option)
{
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < option.length(); i++)
        {
            if (option[i] < 49 || option[i] > 50)
            {

                flag = false;
                break;
            }
        }

        if (option.length() > 3 || !flag)
        {
            cout << "Error" << endl;
            cin >> option;
        }
        else
        {
            return option;
        }
    }
}

string validateMenu(string option)
{
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < option.length(); i++)
        {
            if (option[i] < 48 || option[i] > 57)
            {

                flag = false;
                break;
            }
        }

        if (option.length() > 3 || !flag)
        {
            cout << "Error" << endl;
            cin >> option;
        }
        else
        {
            return option;
        }
    }
}

string validatingPassword(string checkPass)
{

    int check3 = checkPass.length();
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < userCount; i++)
        {
            if (checkPass == pass[i])
            {
                flag = false;
                break;
            }
        }

        if (check3 <= 2 || !flag)
        {
            cout << "INVALID!!" << endl;
            cout << "Enter again: ";
            cin >> checkPass;
            break;
        }
        else
        {
            return checkPass;
        }
    }
}

string validationName(string name)
{
    int check = name.length();

    while (true)
    {
        bool isvalid = true;

        for (int i = 0; i < userCount; i++)
        {
            if (name == nameStudent[i])
            {
                isvalid = false;
                cout << "This name already exist" << endl;
                break;
            }
        }

        for (int i = 0; i < check; i++)
        {
            if (name[i] < 65 || (name[i] > 90 && name[i] < 97) || name[i] > 122)
            {
                isvalid = false;
                break;
            }
        }

        if (check <= 2 || check > 10 || !isvalid)
        {
            cout << "Invalid name!!" << endl;
            cout << "Enter a valid name: ";
            cin >> name;
            check = name.length();
        }
        else
        {
            return name;
        }
    }
}

string validateRollNumber(string roll)
{
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < roll.length(); i++)
        {
            if (roll[i] < 48 || roll[i] > 57 || roll == rollno[i])
            {
                flag = false;
                break;
            }
        }
        if (roll.length() != 3 || !flag)
        {
            cout << "Invalid!!" << endl;
            cout << "Enter roll number again" << endl;
            cin >> roll;
        }
        else
        {
            return roll;
        }
    }
}

string validatingCity(string cityCheck)
{
    int check2 = cityCheck.length();

    while (true)
    {
        bool flag = true;

        for (int i = 0; i < check2; i++)
        {
            if (cityCheck[i] < 65 || cityCheck[i] > 122)
            {
                flag = false;
                break;
            }
        }

        if (check2 <= 2 || check2 > 10 || !flag)
        {
            cout << "INVALID" << endl;
            cout << "Enter again: ";
            cin >> cityCheck;
            check2 = cityCheck.length();
        }

        else
        {
            return cityCheck;
        }
    }
}

string validatingCnic(string checkCnic)
{
    int check = checkCnic.length();
    while (true)
    {
        bool flag = true;
        for (int i = 0; i < userCount; i++)
        {
            if (checkCnic == cnic[i])
            {
                flag = false;
                break;
            }
        }
        for (int i = 0; i < checkCnic.length(); i++)
        {
            if (checkCnic[i] < 48 || checkCnic[i] > 57)
            {
                flag = false;
                break;
            }
        }
        if (checkCnic.length() != 13 || !flag)
        {
            cout << "INVALID!!" << endl;
            cout << "Enter again: ";
            cin >> checkCnic;
            check = checkCnic.length();
        }
        else
        {
            return checkCnic;
        }
    }
}

string validateOption(string option)
{
    while (true)
    {
        bool flag = true;

        for (int i = 0; i < option.length(); i++)
        {
            if (option[i] < 49 || option[i] > 52)
            {
                flag = false;
                cout << "Error" << endl;
                break;
            }
        }

        if (flag)
        {
            return option;
        }
        cin >> option;
    }
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

void path(string name)
{
    string path = "Login >";
    setColor(4);
    cout << "\t\t" << path + name << endl
         << endl;
    setColor(7);
}

void setColor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}