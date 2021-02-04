//  Name:  	Shlomo Stept
//	Class:	CIS 160 M01 CSI
//  Professor: A Atshan
//	Date:	November, 2, 2020
//	Project name: Project 2 - Computerized Catering Billing System using functions
//	Description: The program uses functions to Input, Calculate and then Print an itemized catering bill for a customer
//	             based on the number of Adults & Children, the cost of Each meal for An Adult & Child, the cost of desert,
//               the Tax & tip rate - and Room fees if applicable.


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;


// Global constants
const float CHILD_MEAL_RATE = .60;
const float DESERT_COST = 4.50;
const float TAX_RATE = .07;
const float TIP_RATE = .15;


// Prototypes
void setdata( string &cust_name, int &num_adults, int &num_child, int &num_deserts, float &mealCost_adult, float &room_fee, float &deposit_amt);

void CateringCostCalculations(int Number_of_Adults, int Number_of_Children, int Number_of_Deserts, float Cost_of_Meal_Adult, float & adult_total_cost,
 							  float & child_total_cost, float & desert_total_cost, float & food_total, float & mealCost_child );
 							  
void TaxTipsandTotalBallance( float Total_Food_Cost, float Room_Fee, float Already_Paid_by_Deposit, float & tax_total , float & tip_total , float & bill_total ,
							  float & bill_final);
							  
void OutputToFile( string  Customer_Name, int Number_of_Adults, int Number_of_Children, float Cost_of_Meal_Adult, float Cost_of_Meal_Child, float Total_Cost_Adult_Meals, 
					float Total_Cost_Child_Meals, float Total_Cost_for_Desert, float Total_Food_Cost, float Total_Tax, float Total_Tip, float Room_Fee, float Total_Bill,
					float Already_Paid_by_Deposit,float Final_Balance);



int main()
{

    // Local Variables
    string Customer_Name;
    int Number_of_Adults;
    int Number_of_Children;
    int Number_of_Deserts;

    float Cost_of_Meal_Adult;
    float Cost_of_Meal_Child;
    float Room_Fee;
    float Total_Cost_Adult_Meals;
    float Total_Cost_Child_Meals;
    float Total_Cost_for_Desert;
    float Total_Food_Cost;
    float Total_Tax;
    float Total_Tip;
    float Total_Bill;
    float Already_Paid_by_Deposit;
    float Final_Balance;

    // Input section
    setdata(Customer_Name, Number_of_Adults, Number_of_Children, Number_of_Deserts, Cost_of_Meal_Adult, Room_Fee, Already_Paid_by_Deposit);

    // Processing section
    CateringCostCalculations( Number_of_Adults, Number_of_Children,  Number_of_Deserts,  Cost_of_Meal_Adult, Total_Cost_Adult_Meals, Total_Cost_Child_Meals, 
								Total_Cost_for_Desert, Total_Food_Cost, Cost_of_Meal_Child );

    TaxTipsandTotalBallance(Total_Food_Cost, Room_Fee, Already_Paid_by_Deposit, Total_Tax, Total_Tip, Total_Bill, Final_Balance);

    // Output section
    OutputToFile( Customer_Name,  Number_of_Adults,  Number_of_Children,  Cost_of_Meal_Adult,  Cost_of_Meal_Child, Total_Cost_Adult_Meals, Total_Cost_Child_Meals,
                      Total_Cost_for_Desert, Total_Food_Cost, Total_Tax, Total_Tip, Room_Fee, Total_Bill, Already_Paid_by_Deposit, Final_Balance);

    return 0;
}




// Functions 


/*
Function 1: setdata specification:
	setdata is a void function that reads the string customer name, integer number of adults, integer number of children,
    integer number of deserts, cost of an adult meal, the room fee, and the deposit paid at the time of reservations, from the customer. And then sends back the values 
		to variables in main.
    --All the values are referenced back to the calling function. Nothing is returned.
*/
void setdata( string &cust_name, int &num_adults, int &num_child, int &num_deserts, float &mealCost_adult , float &room_fee, float &deposit_amt)
{
    cout << "Enter Customer name: "<< endl; getline(cin,cust_name) ; // MUST use getline by any string with a whitespace so it does not skip over the cins that follow
    cout << "Enter Number of Adults: " << endl; cin >> num_adults;
    cout << "Enter Number of children: " << endl; cin >> num_child;
    cout << "Enter Number of Deserts: " << endl; cin >> num_deserts;
    cout << "Enter Cost of Adult Meal: " << endl; cin>> mealCost_adult;
    cout << "Enter the Room/Hall Fee:  " << endl; cin >> room_fee;
    cout << "Enter Deposit Paid at time of Reservation: " << endl; cin >> deposit_amt;
}



//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
Function 2: CateringCostCalculations specification:
	CateringCostCalculations is a void function that takes 9 arguments.  The Integer- number of adults, the Integer- number of children, the Integer- number of deserts,
	the Float- cost of an adult meal, the float- total cost for adult meals, the float- total cost for child meals, the float- total cost of desert, 
	the float- total cost of food, and The float- child meal rate.
    The Function (1) first calculates the meal cost for a single child.
    (2)Then the function calculates the total cost of adult meals, the total cost of children's meals, the total cost of deserts.
    --the values of  adult_total_cost,  child_total_cost, desert_total_cost ,  food_total,  mealCost_child are referenced back to the calling function. Nothing is returned.
*/

void CateringCostCalculations(int Number_of_Adults, int Number_of_Children, int Number_of_Deserts, float Cost_of_Meal_Adult, float & adult_total_cost,
							   float & child_total_cost, float & desert_total_cost, float & food_total, float & mealCost_child )
{
    mealCost_child = CHILD_MEAL_RATE * Cost_of_Meal_Adult;
    adult_total_cost = Number_of_Adults * Cost_of_Meal_Adult;
    child_total_cost = Number_of_Children * mealCost_child;
    desert_total_cost = Number_of_Deserts * DESERT_COST;
    food_total = adult_total_cost + child_total_cost + desert_total_cost;

}



//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
Function 3: TaxTipsandTotalBallance specification:
	TaxTipsandTotalBallance is a void function that takes 7 arguments, the float- Total_Food_Cost, the float- Room_Fee, the float- Already_Paid_by_Deposit, 
	the float- total tax , the float- total tip and the flaot - bill total before accounting for the deposit , and the float- final bill after accounting for the deposit.
    (1) The function then calculates the total taxes, total tips, total bill before accounting for the deposit, and the final bill after accounting for the deposit
        All these values are referenced back to the calling function. Nothing is returned.
*/

void TaxTipsandTotalBallance( float Total_Food_Cost, float Room_Fee, float Already_Paid_by_Deposit, float & tax_total , float & tip_total , float & bill_total ,
							   float & bill_final)
{
  tax_total = Total_Food_Cost * TAX_RATE;
  tip_total = Total_Food_Cost * TIP_RATE;
  bill_total =  Total_Food_Cost + tax_total + tip_total + Room_Fee;
  bill_final = bill_total - Already_Paid_by_Deposit;

}



//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
Function 4: OutputToFile specification:
	OutputToFile is a void function that takes 15 arguments. The string- customer name, the integer- number of adults,
    the integer- number of children, the float- cost pf a meal per child, the float- cost of a meal per adult, the float- cost per desert,
    the float- total cost for adults, the float- total cost for children, the float- total food cost,
    the float- total taxes, the float- total tips, the float- room fee, the float- total bill before accounting for the deposit, the float- amount already deposited
    and the float- final bill after accounting for the deposit. ( and uses the constant float- total cost of desert without taking it as an argument)
    (1) Using these values, the function outputs - to a file - an itemized bill sheet outlying each specific cost that lead up
    to the final bill. Nothing is returned.
    Note:  1. that no values are referenced back. 2. the output is sent to a file and formatted using standard specifications
*/
void OutputToFile( string  Customer_Name, int Number_of_Adults, int Number_of_Children, float Cost_of_Meal_Adult, float Cost_of_Meal_Child, float Total_Cost_Adult_Meals, 
				   float Total_Cost_Child_Meals,  float Total_Cost_for_Desert, float Total_Food_Cost, float Total_Tax, float Total_Tip, float Room_Fee, float Total_Bill, 
				   float Already_Paid_by_Deposit,float Final_Balance)
                   {
    ofstream output_file("final_bill_file.txt");
    output_file << fixed << setprecision(2) << showpoint;
    output_file << "\n\t\tPassaic County Catering & Convention Services\t Final Bill" << endl;
    output_file << "\n\tCustomer: \t\t" << Customer_Name << endl;
    output_file << "\tNumber of Adults: \t" << Number_of_Adults << endl;
    output_file << "\tNumber of Children: \t" << Number_of_Children << endl;
    output_file << "\n\tCost of Meal Per Adult: \t\t" << Cost_of_Meal_Adult << endl;
    output_file << "\tCost of Child’s Meal Per Child: \t" << Cost_of_Meal_Child << endl;
    output_file << "\tCost per Desert: \t\t\t" << DESERT_COST << endl;
    output_file << "\n\tTotal Cost for Adult Meals: \t\t" << Total_Cost_Adult_Meals << endl;
    output_file << "\tTotal Cost for Child Meals: \t\t" << Total_Cost_Child_Meals << endl;
    output_file << "\tTotal Cost for Desert: \t\t\t" << Total_Cost_for_Desert << endl;
    output_file << "\tTotal Food Cost: \t\t\t" << Total_Food_Cost << endl;
    output_file << "\n\tPlus 7% Tax: \t\t\t\t" << Total_Tax << endl;
    output_file << "\tPlus 15% Tips: \t\t\t\t" << Total_Tip << endl;
    output_file << "\tPlus Room Fee : \t\t\t" << Room_Fee << endl;
    output_file << "\n\tTotal Bill: \t\t\t\t" << Total_Bill << endl;
    output_file << "\tLess Deposit : \t\t\t\t" << Already_Paid_by_Deposit << endl;
    output_file << "\tBalance Due : \t\t\t\t" << Final_Balance << endl;
    output_file << "\n\t\tThank You for Using Passaic County Catering Services"<<endl;
}



