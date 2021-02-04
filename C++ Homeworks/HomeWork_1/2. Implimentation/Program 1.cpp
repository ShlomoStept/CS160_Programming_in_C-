//  Name:  	Shlomo Stept
//	Class:	CIS 160 M01 CSI
//  Professor: A Atshan
//	Date:	October 9, 2020
//	Project name: Project 1 - Computerized Billing System
//	Description: The program Calculates and Prints a Carpet bill for a customer based on the cost of carpet, labor, taxes and their discount

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>


using namespace std;



// constants
const float LABOR_COST_PER_SQFT = 5.95;
const float TAX_RATE = .06825;



int main()
{
// Global definitions and declarations
    string Customer_Name;
    float Room_Length, Room_Width;
    int Carpet_Size;
    float Carpet_Cost, Carpet_Price_Per_Sqft, Customer_Discount;
    float Total_Labor_Cost, Installed_Price, Discount, SubTotal, Taxes, Total_Cost;

// Input section
    cout << "\n\t:: Enter in the Following information :: " <<endl;
    cout<< "Customer Name: "; getline(cin, Customer_Name); // used getline() in order to solve the space between words problem using - cin >> Customer_name - gives me
    cout<< "Room Length (Ft): "; cin >> Room_Length;
    cout<< "Room Width  (Ft): "; cin >> Room_Width;
    cout<< "Carpet Price / Sq Ft: "; cin >> Carpet_Price_Per_Sqft;
    cout<< "Customer Discount: "; cin >> Customer_Discount;


// Processing section
    Carpet_Size = ceil(Room_Length * Room_Width); // used ceil to round up to the nearest foot
    Carpet_Cost = Carpet_Size * Carpet_Price_Per_Sqft;
    Total_Labor_Cost = Carpet_Size * LABOR_COST_PER_SQFT;
    Installed_Price = Carpet_Cost + Total_Labor_Cost;
    Discount = Installed_Price * (Customer_Discount/100);
    SubTotal = Installed_Price - Discount;
    Taxes = TAX_RATE * SubTotal;
    Total_Cost = SubTotal + Taxes;

// Output section
    cout << fixed << showpoint << setprecision(2); // formating output to two decimals places, decimal not e-notation, and fixed point
    cout << "\n\nWelcome to Passaic County Carpeting Company" << endl;
    cout << "\nCustomer Information:  " << endl;
    cout << "\tCustomer Name:   " << Customer_Name << endl;
    cout << "\tCarpet Size:     " << Carpet_Size<< " Square Feet" << endl;

    cout << "\nCharges:" << endl;
    cout << /*setw(15)<<*/ "\tCarpet Cost: @ $" <</* setw(5) <<*/ Carpet_Price_Per_Sqft <</* setw(6)<< */" Sq Ft" << setw(10) << "\t$" << Carpet_Cost << endl;
    cout << "\tLabor Cost: @ $" << LABOR_COST_PER_SQFT << " Sq Ft" << "\t\t$" << Total_Labor_Cost << endl; // used \t and \n to allign the output
    cout << "\n\tInstalled Price:" <<"\t\t\t$" << Installed_Price << endl;
    cout << "\tDiscount:" <<"\t\t\t\t$" << Discount << endl;
    cout << "\t\t\t\t\t\t___________ " <<endl;
    cout << "\tSubTotal:" << "\t\t\t\t$" << SubTotal << endl;
    cout << "\n\tTaxes:" << "\t\t\t\t\t$" << Taxes << endl;
    cout << "\n\tTotal Cost: " <<"\t\t\t\t$" << Total_Cost << endl;
    cout << "\n" << Customer_Name << ", Thank You for Using PCCC Carpeting";

    return 0;
}




