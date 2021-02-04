//  Name:  	Shlomo Stept
//	Class:	CIS 160 M01 CSI
//  Professor: A Atshan
//	Date:	November, 26, 2020
//	Project name: Project 3 - Computerized Catering Billing System using conditons (if else..) and menues
//	Description: The program uses functions conditional evaluations (if/else) switch-break, and menu's to Input, Calculate and then Print an itemized catering bill for a customer
//	             based on the number of Adults & Children, the selected adult meal (duluxe or standard) the cost of Each meal for An Adult & Child, the hall fee (menu driven)
//               the Tax & gratuity rate - and weekend fees if applicable.


#include <iostream>
#include <string>
#include <iomanip>


using namespace std;


// Prototypes
float type_of_adult_meal();
string hall_choice(float &);
void setdata(int &NumAdults, int & NumChild, float & CostMeal_Ad, float &Hall_Cost, string & Hall_Num, string & Weekend, string & Speedy_Dis);

void CateringCostCalculations( float & Cost_of_Meal_Child, float Cost_of_Meal_Adult, float & Total_Cost_Child_Meals,int Number_of_Children, float & Total_Cost_Adult_Meals, int Number_of_Adults,
                                float & Total_Food_Cost,float & Total_Tax, float& Total_Gratuity,float & gratuity_rate, string Weekend,float & Weekend_Charge, float & subtotal,
                                float Hall_Charge, float &Less_Speedy_payment, string Speedy_Dis,float & Final_Balance);

void Output(int Number_of_Adults, int Number_of_Children, float gratuity_rate, string Weekend, float Cost_of_Meal_Adult,float Cost_of_Meal_Child,
            float Total_Cost_Adult_Meals, float Total_Cost_Child_Meals,float Total_Food_Cost, float Total_Gratuity, string Hall_Number, float Hall_Charge, float Weekend_Charge, float Total_Tax,
            float Subtotal, float Less_Speedy_payment, float Final_Balance);


int main()
{

    // Local Variables
    string Customer_Name;
    string Weekend;
    string Speedy_Discount;
    string Hall_Number;

    int Number_of_Adults;
    int Number_of_Children;


    float Cost_of_Meal_Adult;
    float Cost_of_Meal_Child;
    float Total_Cost_Adult_Meals;
    float Total_Cost_Child_Meals;
    float Total_Food_Cost;
    float gratuity_rate;
    float Total_Gratuity;
    float Hall_Charge;
    float Weekend_Charge;
    float Total_Tax;
    float Subtotal;
    float Less_Speedy_payment;
    float Final_Balance;

    // Input section
    setdata(Number_of_Adults, Number_of_Children, Cost_of_Meal_Adult,Hall_Charge, Hall_Number, Weekend, Speedy_Discount);

    // Processing section
    CateringCostCalculations(Cost_of_Meal_Child,  Cost_of_Meal_Adult, Total_Cost_Child_Meals,Number_of_Children,  Total_Cost_Adult_Meals,
                             Number_of_Adults, Total_Food_Cost, Total_Tax, Total_Gratuity, gratuity_rate,  Weekend, Weekend_Charge,  Subtotal,
                             Hall_Charge, Less_Speedy_payment,  Speedy_Discount,Final_Balance);


    // Output section
    Output( Number_of_Adults, Number_of_Children, gratuity_rate, Weekend, Cost_of_Meal_Adult, Cost_of_Meal_Child,
                Total_Cost_Adult_Meals, Total_Cost_Child_Meals, Total_Food_Cost, Total_Gratuity, Hall_Number, Hall_Charge,
                Weekend_Charge, Total_Tax, Subtotal, Less_Speedy_payment,Final_Balance);

    return 0;
}




//____________________________________________________________________________________________________________________________________________________________________________________________________________
//        ::FUNCTIONS::
//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
Function 1: setdata specification:
            setdata is a void function that get from user input- the values for, integer number of adults, integer number of children,
            float cost of an adult meal, float cost of hall, string hall number, the string weekend (if the catering is done on weekend),
            and the string speedy discount.
            And then sends back the values to variables in main.

        -- the function setdata calls two functions:
            (1) type_of_adult_meal: --  to get the (returned value for) cost of an adult meal- based on the user selection from two choices (standard and Deluxe)
            (2) all_choice: -- to get the hall number(returned value) and the cost of that hall(passback reference)

    --All the values in setdata are referenced back to the calling function. Nothing is returned.
 */

void setdata(int &NumAdults, int & NumChild, float & CostMeal_Ad, float & Hall_Cost, string & Hall_Num, string & Weekend, string & Speedy_Dis)
{
    cout << " Enter The Number of Adults Attending: "; cin >> NumAdults;
    cout << " Enter The Number of Children Attending: "; cin >> NumChild;

    CostMeal_Ad = type_of_adult_meal();

    Hall_Num = hall_choice(Hall_Cost);

    cout<< " Is/Was the Catering on a Weekend? (Y/N) : " << endl;
    getline(cin, Weekend); Weekend= toupper(Weekend[0]);

    cout<< " Does the Customer Qualify for the Speedy Payment discount? (Y/N) :  " <<endl;
    getline(cin, Speedy_Dis); Speedy_Dis= toupper(Speedy_Dis[0]);




}


//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
function 2: type_of_adult_meal specification:
            type_of_adult_meal is a float function that receives the string value for Type of Adult meat to be served from user input
            based on the user input the function:
            1. first checks to see if the value entered by the user is valid ( 1, 2, s, S, d , or D),  the input prompt is repeated until a valid entry is received
            2. then the function uses an if statement to decide which, constant float value for meal price to return, based on the type of meal selected

    --no values are referenced back to the calling function. the meal price is returned.
*/

float type_of_adult_meal()
{
    const float DELUXE_MEAL_RATE = 25.95;
    const float STANDARD_MEAL_RATE = 21.75;
    string choice, line;
    line.assign(60,  '-');

    cout << "\n Select the Type of Adult Meal to be served from the following Menu: "<< endl;
    cout << line << endl;
    cin.ignore();
    cout<< " \t 1- Deluxe Meal at $" << DELUXE_MEAL_RATE << " Per Adult"<< endl;
    cout<< " \t 2- Standard Meal at $"<< STANDARD_MEAL_RATE<< " Per Adult"<< endl;
    getline(cin, (choice));

    // While Loop used to -- Evaluate if entry was valid, and allow user to ReEnter if invalid
    while (choice[0] != '1' && toupper(choice[0]) != 'D' && choice[0] != '2' && toupper(choice[0]) != 'S')
        {
            cout<<"You entered an Invalid Choice," <<endl;
            cout<<"Reenter Choice: " <<endl;
            getline(cin, (choice));
        }

    // Used an "If" statement Here-- because it was more Efficient than a switch
    if( choice[0] == '1' || toupper(choice[0]) == 'D')
        {
            return DELUXE_MEAL_RATE;
        }
        else if( choice[0] == '2' || toupper(choice[0]) == 'S')
            {
                return STANDARD_MEAL_RATE;
            }
            else
                cout<< "Something Went Wrong" <<endl;



}


//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
function 3: hall_choice specification:
            hall_choice is a float function  that receives the string value of hall choice and uses it to calculate the float value for hall price
            and based on the user input the function:
            1. first checks to see if the value entered by the user is valid ( A, B, C, D, or H),  the input prompt is repeated until a valid entry is received
            2. then the function uses an switch-break statement to decide which hall price to assign to- the float hall price

    --the float value of hall price is are referenced back to the calling function. the hall choice is returned.
 */

string hall_choice(float &Hall_price)
{
    string choice, line;
    const float HALL_A = 100.00;
    const float HALL_B = 85.00;
    const float HALL_C = 75.00;
    const float HALL_D = 65.00;
    const float HALL_H = 0.00;

    cout << "\n Choose a Hall to use from the following Menu: (A-H) "<< endl;
    line.assign(40,  '-');
    cout << line << endl;
    cout << "\tHall - A\t$100.00"<<endl;
    cout << "\tHall - B\t$85.00"<<endl;
    cout << "\tHall - C\t$75.00"<<endl;
    cout << "\tHall - D\t$65.00"<<endl;
    cout << "\tHall - H\tis Home"<<endl;
    getline(cin, choice); choice = toupper(choice[0]);

    // While Loop used to -- Evaluate if entry was valid, and allow user to ReEnter if invalid
    while (choice[0] != 'A'  && choice[0] != 'B' && choice[0] != 'C' && choice[0] != 'D' && choice[0] != 'H')
    {
        cout<<"You Entered an Invalid Choice" <<endl;
        cout<<"Reenter Choice (A-H) :  " <<endl;
        getline(cin, (choice)); choice= toupper(choice[0]);
    }

    switch(choice[0])
    {
        case 'A': Hall_price = HALL_A;
            break;
        case 'B': Hall_price = HALL_B;
            break;
        case 'C': Hall_price = HALL_C;
            break;
        case 'D': Hall_price = HALL_D;
            break;
        case 'H': Hall_price = HALL_H;
            break;
        default:
            cout<< "You Entered an Invalid Choice"<<endl;
    }

    return choice;



}


//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
//function 4: Function 2: CateringCostCalculations specification:
	        CateringCostCalculations is a void function that takes 16 arguments.
	        the float - Cost_of_Meal_Child, the float- Cost_of_Meal_Adult, the float - Total_Cost_Child_Meals, the integer -  Number_of_Children,
	        the float - Total_Cost_Adult_Meals, the integer - Number_of_Adults, the float - Total_Food_Cost, the float - Total_Tax, the float - Total_Gratuity,
	        the float - gratuity_rate, the - string Weekend, the float - Weekend_Charge, ans the float - subtotal,

            Using these values The Function:
            (1) first calculates the meal cost for a single child.
            (2) Then the function calculates the total cost of children's meals, the total cost of adult meals, the total food cost, the total cost of taxes,
                the total cost of gratuity (only applied the ttoal food cost),
            (3) next using an if statement the function determines whether to add a 10% weekend charge
            (4) the function then calcualtes the subtotal
            (5) next using a nested if -else if set of statements to determine what total dsicount; which is determined based on discount tier associated with the subtotal cost

    --the values of  Cost_of_Meal_Child, Total_Cost_Child_Meals, Total_Cost_Adult_Meals, Total_Food_Cost, Total_Tax,  Total_Gratuity, gratuity_rate,  Weekend_Charge, subtotal,
                 Less_Speedy_payment,and  Final_Balance are referenced back to the calling function. Nothing is returned.
//*/

void CateringCostCalculations(float & Cost_of_Meal_Child, float Cost_of_Meal_Adult, float & Total_Cost_Child_Meals,int Number_of_Children, float & Total_Cost_Adult_Meals, int Number_of_Adults,
                float & Total_Food_Cost,float & Total_Tax, float& Total_Gratuity,float & gratuity_rate, string Weekend,float & Weekend_Charge, float & subtotal,
                float Hall_Charge, float &Less_Speedy_payment, string Speedy_Dis,float & Final_Balance)
{
    float sales_tax_rate=.07;
    float child_meal_rate =0.6;
    gratuity_rate=0.20;

    const float DISCOUNT_LEVEL_1 =0.01;
    const float DISCOUNT_LEVEL_2 =0.02;
    const float DISCOUNT_LEVEL_3 =0.04;
    const float DISCOUNT_LEVEL_4 =0.05;
    const float DISCOUNT_LEVEL_5 =0.07;

    Cost_of_Meal_Child = Cost_of_Meal_Adult * child_meal_rate;
    Total_Cost_Child_Meals =  Cost_of_Meal_Child * Number_of_Children;
    Total_Cost_Adult_Meals = Cost_of_Meal_Adult * Number_of_Adults;
    Total_Food_Cost = Total_Cost_Adult_Meals +Total_Cost_Child_Meals;
    Total_Tax = Total_Food_Cost * sales_tax_rate;
    Total_Gratuity = gratuity_rate * Total_Food_Cost;

    if (Weekend[0] == 'Y')
        Weekend_Charge = (Total_Food_Cost + Total_Gratuity + Hall_Charge) * .1;
        else
            Weekend_Charge = 0.00;

    subtotal = Total_Food_Cost + Total_Gratuity + Weekend_Charge + Hall_Charge + Total_Tax;

    // CALCULATION OF SPEEDY PAYMENT DISCOUNT - IF APPLICABLE.
    Less_Speedy_payment=0.00;
    if (Speedy_Dis == "Y")
        {
            if (subtotal < 500)
                Less_Speedy_payment = subtotal * DISCOUNT_LEVEL_1;
                else if (subtotal >= 500 && subtotal < 1000.00)
                    Less_Speedy_payment = subtotal * DISCOUNT_LEVEL_2;
                    else if (subtotal >= 1000 && subtotal < 5000.00)
                        Less_Speedy_payment = subtotal * DISCOUNT_LEVEL_3;
                        else if (subtotal >= 5000 && subtotal < 10000.00)
                            Less_Speedy_payment = subtotal * DISCOUNT_LEVEL_4;
                        else if (subtotal > 10000.00)
                            Less_Speedy_payment = subtotal * DISCOUNT_LEVEL_5;
                            else
                                cout<< "something else has gone wrong"<<endl;
         }


    Final_Balance = subtotal- Less_Speedy_payment;




}


//____________________________________________________________________________________________________________________________________________________________________________________________________________
//Function 5
/* Specifications:
 */
/*
Function 5: Output specification:
	        Output is a void function that takes 17 arguments. the integer - Number_of_Adults, the integer - Number_of_Children, the float - gratuity_rate, the string -  Weekend, the float - Cost_of_Meal_Adult,
            the float - Cost_of_Meal_Child, the float - Total_Cost_Adult_Meals, the float - Total_Cost_Child_Meals, the float - Total_Food_Cost, the float - Total_Gratuity, the string - Hall_Number,
            the float - Hall_Charge, the float - Weekend_Charge, the float - Total_Tax, the float - Subtotal, the  float - Less_Speedy_payment, the float -  Final_Balance,

    (1) Using these values, the function outputs - an itemized bill sheet outlying each specific cost that lead up to the final bill. Nothing is returned.
    (2) based on the string value of weekend (Y/N) a new value is assigned to weekend(Yes/No) to be used in the output.
    Note:  1. that no values are referenced back. 2. the output is  formatted using standard specifications
*/
void Output(int Number_of_Adults, int Number_of_Children, float gratuity_rate, string Weekend, float Cost_of_Meal_Adult,float Cost_of_Meal_Child, float Total_Cost_Adult_Meals,
            float Total_Cost_Child_Meals,float Total_Food_Cost, float Total_Gratuity,string Hall_Number, float Hall_Charge, float Weekend_Charge, float Total_Tax,
            float Subtotal, float Less_Speedy_payment, float Final_Balance)
{

    cout << fixed << setprecision(2) << showpoint;
    cout <<"\n\t/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/"<<endl;
    cout << "\t\t\tCaswell Catering & Convention Services\n\t\t\t\t\t Final Bill" << endl;
    cout <<"\t/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/"<<endl;
    cout  << "\tNumber of Adults: \t" << Number_of_Adults << endl;
    cout  << "\tNumber of Children: \t" << Number_of_Children << endl;
    cout  << "\tGratuity:  \t\t" << (int(gratuity_rate*100))<<"%" << endl;
    //-------------------------------------------------------
    if (Weekend=="Y")
        Weekend="Yes";
        else if (Weekend=="N")
            Weekend="No";
    //-------------------------------------------------------
    cout  << "\tWeekend: \t\t" << Weekend<< endl;
    cout  << "\n\tCost of standard Meal for Adult: \t" << Cost_of_Meal_Adult << endl;
    cout  << "\tCost of standard Meal for Child: \t" << Cost_of_Meal_Child << endl;
    cout  << "\t---------------------------------------------------------------------\n";
    cout  << "\tTotal Cost for Adult Meals: \t\t" << Total_Cost_Adult_Meals << endl;
    cout  << "\tTotal Cost for Child Meals: \t\t" << Total_Cost_Child_Meals << endl;
    cout  << "\n\tTotal Food Cost: \t\t\t" << Total_Food_Cost << endl;
    cout  << "\t---------------------------------------------------------------------\n";
    cout  << "\tGratuity: \t\t\t\t" << Total_Gratuity << endl;
    cout  << "\tHall "<<Hall_Number<<" - Room Fee:\t\t\t" << Hall_Charge<< endl;
    cout  << "\tWeekend Charge : \t\t\t" << Weekend_Charge << endl;
    cout  << "\tTaxes: \t\t\t\t\t" << Total_Tax << endl;
    cout  << "\t---------------------------------------------------------------------\n";
    cout  << "\tSubtotal : \t\t\t\t" << Subtotal << endl;
    cout  << "\n\tLess Speedy Payment : \t\t\t" << Less_Speedy_payment << endl;
    cout  << "\n\tBalance Due : \t\t\t\t" << Final_Balance << endl;
    cout <<"\n\t/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/"<<endl;

}




























