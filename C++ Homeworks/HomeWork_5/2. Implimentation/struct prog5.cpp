// 	Name:  	Shlomo Stept
//	Class:	CIS 160 M01 CSI
//  Professor: A Atshan
//	Date:	December 19, 2020
//	Project name: Project 5
//	Description: A program that exposes me to Structures, utilizing an employee pay calculator 

#include <iostream> // a stream that inherits/adopts the operators; i for input and; 0 for output
#include <string>
#include <iomanip>


using namespace std;

//structure definition
struct Report
{
    string name;
    float hours_worked;
    float hourly_rate;
};

// function prototypes
void setData(Report &);
void print(Report);
float gross_pay(Report);

// Main
int main()
{
    Report Report1;

// input section
    setData(Report1);

// output section
    print(Report1);

    return 0;
}


/*--------------------------------------------------------------------------------------------------------------------
                 :::::Functions::::
 --------------------------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------------------------
 * Function 1: setData Specifications:
 *          -> setData is a void function that accepts the object of type Report
 *             (1) gets the name, number of hours, and hourly rate and passe them back to the Instance of Class reports
 *                  member variables, name, hours_worked and hourly_rate
 *
 *          -> The object of type Report is passed by reference, nothing is returned.
 */

void setData(Report &rept1)
{
    cout << " Enter in an Employee Name: " << endl;
    getline(cin, rept1.name);

    cout << " Enter the Numbers of Hours " << rept1.name << " Worked: " << endl;
    cin >> rept1.hours_worked;

    cout << " Enter in the Hourly pay rate for " << rept1.name << ": " << endl;
    cin>>rept1.hourly_rate;
}




/*--------------------------------------------------------------------------------------------------------------------
 * Function 2: print Specifications:
 *          -> print is a void function that accepts the object of type Report
 *             (1) calls the function gross_pay to calculate the gross pay
 *             (2) prints out an Employee report with the employees name, hours worked, hourly rate, and total wages
 *
 *          -> The nothing is passed by reference, nothing is returned.
 */

void print(Report rept1)
{
    float grosspay;
    grosspay = gross_pay(rept1);

    cout<< fixed << setprecision(2) << showpoint;
    cout<< "----------------------------------------------";
    cout<< "\n\t::Employee Salary Report::" << endl;
    cout<< "----------------------------------------------";
    cout<< "\n Employee Name: \t\t"<<rept1.name << endl;
    cout<< "\n Hours Worked: \t\t\t"<<rept1.hours_worked << endl;
    cout<< " Hourly Rate: \t\t\t$"<<rept1.hourly_rate << endl;
    cout<< "----------------------------------------------";
    cout<< "\n Wages: \t\t\t$"<< grosspay ;
    cout<< "\n----------------------------------------------";
}




/*--------------------------------------------------------------------------------------------------------------------
 * Function 3: gross_pay Specifications
 *          -> gross_pay is a  float function that accepts the object of type Report
 *              calculates the gross pay by multiplying the hours worked by the hourly rate, and returns it
 *
 *          -> The nothing is passed by reference, the float value of the gross pay is returned.
 */

float gross_pay(Report rept1)
{
    return rept1.hours_worked * rept1.hourly_rate;

}



