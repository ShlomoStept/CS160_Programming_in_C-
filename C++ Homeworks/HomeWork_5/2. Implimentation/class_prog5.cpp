// 	Name:  	Shlomo Stept
//	Class:	CIS 160 M01 CSI
//  Professor: A Atshan
//	Date:	December 19, 2020
//	Project name: Project 5
//	Description: A program that exposes me to classes, utilizing an employee pay calculator 

#include <iostream> // a stream that inherits/adopts the operators; i for input and; 0 for output
#include <string>
#include <iomanip>

using namespace std;


/*--------------------------------------------------------------------------------------------------------------------
        ::::: Class Definition ::::
--------------------------------------------------------------------------------------------------------------------*/
class Report
{
private:
    string name;
    float hours_worked;
    float hourly_pay;
    // private member function
    float gross_pay();

public:
    Report();
    void setData();
    void print();
    ~Report();
};

/*--------------------------------------------------------------------------------------------------------------------
    ::::: Member Function Declarations ::::
--------------------------------------------------------------------------------------------------------------------*/

// Function 1: Null Constructor
Report :: Report()
{
}

// Function 2: setdata, is a void function that receives the employees name, hours worked and hourly pay and uses these to set the associated member variables
void Report :: setData()
{
    cout << "\n Enter in an Employee Name: " << endl;
    getline(cin, name);

    cout << " Enter the Numbers of Hours " << name << " Worked: " << endl;
    cin >> hours_worked;

    cout << " Enter in the Hourly pay rate for " << name << ": " << endl;
    cin>> hourly_pay;
}

// Function 3: print, is a void function that outputs the  employees name, hours worked,  hourly rate, calls a function to calculate the gross pay and outputs that as well
void Report :: print()
{
    cout<< fixed << setprecision(2) << showpoint;
    cout<< "\n----------------------------------------------";
    cout<< "\n\t::Employee Salary Report::" << endl;
    cout<< "----------------------------------------------";
    cout<< "\n Employee Name: \t\t" << name << endl;
    cout<< "\n Hours Worked: \t\t\t" << hours_worked << endl;
    cout<< " Hourly Rate: \t\t\t$" << hourly_pay << endl;
    cout<< "----------------------------------------------";
    cout<< "\n Wages: \t\t\t$" << gross_pay() << endl;
    cout<< "----------------------------------------------";
}

// Function 4: gross_pay, is a float function that returns the calculated gross pay.
float Report :: gross_pay()
{
    return hours_worked * hourly_pay;
}

// Function 5: Destructor
Report :: ~Report()
{
}
//--------------------------------------------------------------------------------------------------------------------*/



/*--------------------------------------------------------------------------------------------------------------------
    ::::: Main ::::
--------------------------------------------------------------------------------------------------------------------*/

int main()
{
    Report WorkerReport;

    // input section
    WorkerReport.setData();

    // output section
    WorkerReport.print();

    return 0;
}


