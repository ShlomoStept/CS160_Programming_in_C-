// 	Name:  	Shlomo Stept
//	Class:	CIS 160 M01 CSI
//  Professor: A Atshan
//	Date:	December 12th
//	Project name:   Project 4: loops
//	Description:	a program uses loops to calculate the profit/loss of a contracting company, (and calculates the cost in each expense domain);
//                 	by accepting in the revenue brought in per job and all the costs for subcontractors, materials and workers, for each job.

#include <iostream> // a stream that inherits/adopts the operators; i for input and; 0 for output
#include <string>
#include <iomanip>
#include <fstream>


using namespace std;

//Prototypes -> Begin ->

void program_begin( float & contract_incoming_revenue, ofstream & output_tofile,
                   float & total_cost_of_electrician, float & total_cost_of_plumber, float & total_cost_of_roofer, float & total_cost_for_extra_workers,
                   float & total_cost_of_wood, float & total_cost_of_concrete, float & total_cost_of_windows, float & total_cost_of_doors,
                   float & total_cost_of_contract,float & net_profit_from_contract, double & total_paid_for_all_electrical_work,
                   float & total_paid_for_all_plumbing_work, float & total_paid_for_all_roofing_work, float & total_paid_for_all_materials,
                   float & total_paid_for_all_contracts_extra_workers, float & grand_total_for_all_incoming_revenue, float & grand_total_for_all_contracts_costs,
                   float & grand_total_net_profit_for_all_contracts);

void get_contract_data(int contract_num, float & contract_incoming_revenue, float & total_cost_of_electrician, float & total_cost_of_plumber,
                       float & total_cost_of_roofer, float & total_cost_for_extra_workers, float & total_cost_of_wood, float & total_cost_of_concrete,
                       float & total_cost_of_windows, float & total_cost_of_doors);

void process_contract_data(float contract_incoming_revenue, float total_cost_of_electrician, float total_cost_of_plumber,
                           float total_cost_of_roofer, float total_cost_for_extra_workers, float total_cost_of_wood, float total_cost_of_concrete,
                           float total_cost_of_windows, float total_cost_of_doors, float & total_cost_of_contract,float & net_profit_from_contract,
                            double & total_paid_for_all_electrical_work,float & total_paid_for_all_plumbing_work, float & total_paid_for_all_roofing_work,
                           float & total_paid_for_all_materials,float & total_paid_for_all_contracts_extra_workers, float & grand_total_for_all_incoming_revenue,
                           float & grand_total_for_all_contracts_costs,float & grand_total_net_profit_for_all_contracts);

void output_contract_data_toFile(int contract_num, ofstream & output_tofile, float  contract_incoming_revenue,
                                 float  total_cost_of_contract,float  net_profit_from_contract);

void output_all_projects_totals_toFile(ofstream & output_tofile,  double total_paid_for_all_electrical_work,float total_paid_for_all_plumbing_work, float total_paid_for_all_roofing_work,
                                       float total_paid_for_all_materials,float total_paid_for_all_contracts_extra_workers, float grand_total_for_all_incoming_revenue,
                                       float grand_total_for_all_contracts_costs, float grand_total_net_profit_for_all_contracts);

//Prototypes <- End <-


int main()
{
    float contract_incoming_revenue;

    ofstream output_tofile("Results.txt");
    float total_cost_of_electrician;
    float total_cost_of_plumber;
    float total_cost_of_roofer;

    float total_cost_for_extra_workers;  //min of 5
    float total_cost_of_wood;
    float total_cost_of_concrete;
    float total_cost_of_windows;
    float total_cost_of_doors;
    float total_cost_of_contract;
    float net_profit_from_contract;
    double total_paid_for_all_electrical_work;
    float total_paid_for_all_plumbing_work;
    float total_paid_for_all_roofing_work;
    float total_paid_for_all_materials;
    float total_paid_for_all_contracts_extra_workers;
    float grand_total_for_all_incoming_revenue;
    float grand_total_for_all_contracts_costs;
    float grand_total_net_profit_for_all_contracts;

    program_begin(contract_incoming_revenue,output_tofile, total_cost_of_electrician,
                  total_cost_of_plumber, total_cost_of_roofer, total_cost_for_extra_workers,total_cost_of_wood,
                  total_cost_of_concrete, total_cost_of_windows, total_cost_of_doors,total_cost_of_contract, net_profit_from_contract,
                  total_paid_for_all_electrical_work,total_paid_for_all_plumbing_work, total_paid_for_all_roofing_work, total_paid_for_all_materials,
                   total_paid_for_all_contracts_extra_workers, grand_total_for_all_incoming_revenue, grand_total_for_all_contracts_costs,
                    grand_total_net_profit_for_all_contracts);



    return 0;
}



//____________________________________________________________________________________________________________________________________________________________________________________________________________
//        ::FUNCTIONS::
//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
Function 1: program_begin -> specification:

           program_begin is void function that receives:
           the float contract_incoming_revenue, the ofstream output_tofile, the float total_cost_of_electrician, the float total_cost_of_plumber,
           the float total_cost_of_roofer, the float total_cost_for_extra_workers, the float total_cost_of_wood , the float total_cost_of_concrete,
           the float total_cost_of_windows, the float total_cost_of_doors, the float total_cost_of_contract, the float net_profit_from_contract,
           the double total_paid_for_all_electrical_work, the float  total_paid_for_all_plumbing_work, the float total_paid_for_all_roofing_work,
           the float total_paid_for_all_materials, the float total_paid_for_all_contracts_extra_workers, the float grand_total_for_all_incoming_revenue,
           the float grand_total_for_all_contracts_costs, the float grand_total_net_profit_for_all_contracts

        -- the function program_begin runs the entire program by:
            (1) receiving the number of contracts, and then using a loop (dependant of the number of contacts) to call the functions
                a -> get_contract_data, to receive the data of each function independently
                b -> process_contract_data, to calculate the costs for each domain, and the running total of incoming revenue, costs and net profit
                c -> output_contract_data_toFile, to output each contract's incoming revenue, costs and net profit
            and
            (2)    output_all_projects_totals_toFile, that outputs the total costs for each domain, and the running total of incoming revenue, costs and net profit

    --All the values in program_begin are referenced back to the calling function. Nothing is returned.
 */

void program_begin(float & contract_incoming_revenue, ofstream & output_tofile,float & total_cost_of_electrician, float & total_cost_of_plumber,
                   float & total_cost_of_roofer, float & total_cost_for_extra_workers, float & total_cost_of_wood, float & total_cost_of_concrete,
                   float & total_cost_of_windows, float & total_cost_of_doors, float & total_cost_of_contract,float & net_profit_from_contract,
                   double & total_paid_for_all_electrical_work, float & total_paid_for_all_plumbing_work, float & total_paid_for_all_roofing_work,
                   float & total_paid_for_all_materials, float & total_paid_for_all_contracts_extra_workers, float & grand_total_for_all_incoming_revenue,
                   float & grand_total_for_all_contracts_costs, float & grand_total_net_profit_for_all_contracts)
{

    int number_of_projects , contract_num = 0;

    cout << "Enter the Total Number of Contracts PCCC Won: " << endl;
    cin >>number_of_projects;

    while(number_of_projects)
    {
        // Input section:
        contract_num += 1 ;
        get_contract_data(contract_num, contract_incoming_revenue, total_cost_of_electrician, total_cost_of_plumber,total_cost_of_roofer,
                          total_cost_for_extra_workers, total_cost_of_wood,  total_cost_of_concrete, total_cost_of_windows,  total_cost_of_doors);

        // Processing section:
        process_contract_data(contract_incoming_revenue, total_cost_of_electrician, total_cost_of_plumber,
                                   total_cost_of_roofer, total_cost_for_extra_workers, total_cost_of_wood,  total_cost_of_concrete,
                                   total_cost_of_windows,  total_cost_of_doors, total_cost_of_contract, net_profit_from_contract,
                                   total_paid_for_all_electrical_work, total_paid_for_all_plumbing_work, total_paid_for_all_roofing_work,
                                   total_paid_for_all_materials, total_paid_for_all_contracts_extra_workers,  grand_total_for_all_incoming_revenue,
                                   grand_total_for_all_contracts_costs, grand_total_net_profit_for_all_contracts);

        // Output section 1:
        output_contract_data_toFile( contract_num, output_tofile, contract_incoming_revenue, total_cost_of_contract, net_profit_from_contract);

        number_of_projects -= 1;
    }

    // Output section 2:
    output_all_projects_totals_toFile(output_tofile, total_paid_for_all_electrical_work, total_paid_for_all_plumbing_work, total_paid_for_all_roofing_work,
                                            total_paid_for_all_materials, total_paid_for_all_contracts_extra_workers, grand_total_for_all_incoming_revenue,
                                           grand_total_for_all_contracts_costs, grand_total_net_profit_for_all_contracts);



}




//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
Function 2: get_contract_data -> specification:

            get_contract_data is a void function that receives the integer value of contract_num, the float value of contract_incoming_revenue, the float value of total_cost_of_electrician,
            the float value of total_cost_of_plumber, the float value of total_cost_of_roofer, the float value of total_cost_for_extra_workers,
            the float value of total_cost_of_wood, the float value of total_cost_of_concrete, the float value of total_cost_of_windows, and the float value of total_cost_of_doors)

            Using these values The Function:
            (1) Receives the total incoming revenue, and total subcontractor, material, and a minimum of 5 workers, costs incurred for the contracts

    --> all values are referenced back to the calling function; except contract_num. nothing is returned.
*/

void get_contract_data(int contract_num, float & contract_incoming_revenue, float & total_cost_of_electrician, float & total_cost_of_plumber,
                       float & total_cost_of_roofer, float & total_cost_for_extra_workers, float & total_cost_of_wood, float & total_cost_of_concrete,
                       float & total_cost_of_windows, float & total_cost_of_doors)
{
    //system("cls");
    cout << "\n::Enter In the Total PCCC is being Paid for Contract #"<< contract_num <<" : "<<endl;
    cin >> contract_incoming_revenue;
    cout << "::Costs:: \nEnter in Total Paid to Electrician: "<< endl; cin >> total_cost_of_electrician;
    cout << "Enter in Total Paid to Plumber: " << endl; cin >> total_cost_of_plumber;
    cout << "Enter in Total Paid to Roofer: " << endl;  cin >> total_cost_of_roofer;



    int x=0;
    float salary_for_worker;
    total_cost_for_extra_workers=0;

    // You Must have a minimum of 5 workers
    while(x<5)
        {
            x++;
            cout << "Enter in Worker #"<<x<<"'s Salary for the Contract: "<<endl;
            cin >> salary_for_worker;
            while(salary_for_worker==0)
            {
                cout<< "\n::ERROR 1::  You Must Enter a Salary for Worker #" << x << "\nReEnter Worker #" << x<< "'s Salary for the Contract: "<<endl;
                cin>>salary_for_worker;
            }
            total_cost_for_extra_workers+=salary_for_worker;
        }

    while( salary_for_worker != 0 )
    {
        x+=1;
        cout << "Enter in Worker #"<<x<<"'s Salary for the Contract: "<<endl;
        cin >> salary_for_worker;
        total_cost_for_extra_workers+=salary_for_worker;

    }

    cout << "Enter in Cost of Wood: "<< endl; cin >> total_cost_of_wood;
    cout << "Enter in Cost of Concrete: "<< endl; cin >> total_cost_of_concrete;
    cout << "Enter in Cost of Windows: "<< endl; cin >> total_cost_of_windows;
    cout << "Enter in Cost of Doors: "<< endl; cin >> total_cost_of_doors;


}





//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
function 3: process_contract_data -> specification:

            get_contract_data is a void function that receives the float value of contract_incoming_revenue, the float value of total_cost_of_electrician,
            the float value of total_cost_of_plumber, the float value of total_cost_of_roofer, the float value of total_cost_for_extra_workers, the float value of total_cost_of_wood,
            the float value of total_cost_of_concrete, the float value of total_cost_of_windows, float total_cost_of_doors, the float value of total_cost_of_contract,
            the float value of net_profit_from_contract, the double value of total_paid_for_all_electrical_work,the float value of total_paid_for_all_plumbing_work,
            the float value of total_paid_for_all_roofing_work, the float value of total_paid_for_all_materials,the float value of total_paid_for_all_contracts_extra_workers,
            the float value of grand_total_for_all_incoming_revenue, the float value of grand_total_for_all_contracts_costs,the float value of grand_total_net_profit_for_all_contracts

            Using these values The Function:
            (1) the function calculates the costs for each catagory of costs, and the incoming revenue, costs and net profit for each individual contract run(loop),
                and also keeps a running total of the incoming revenue, costs and net profit for all contracts

    --> the float values of: total_cost_of_contract, net_profit_from_contract, total_paid_for_all_electrical_work, total_paid_for_all_plumbing_work, total_paid_for_all_roofing_work,
         total_paid_for_all_materials, total_paid_for_all_contracts_extra_workers, grand_total_for_all_incoming_revenue, grand_total_for_all_contracts_costs,grand_total_net_profit_for_all_contracts
         are referenced back to the calling function. Nothing is returned.
*/

void process_contract_data(float contract_incoming_revenue, float total_cost_of_electrician, float total_cost_of_plumber,
                           float total_cost_of_roofer, float total_cost_for_extra_workers, float total_cost_of_wood, float total_cost_of_concrete,
                           float total_cost_of_windows, float total_cost_of_doors, float & total_cost_of_contract,float & net_profit_from_contract,
                           double & total_paid_for_all_electrical_work,float & total_paid_for_all_plumbing_work, float & total_paid_for_all_roofing_work,
                           float & total_paid_for_all_materials,float & total_paid_for_all_contracts_extra_workers, float & grand_total_for_all_incoming_revenue,
                           float & grand_total_for_all_contracts_costs,float & grand_total_net_profit_for_all_contracts)
{


    total_cost_of_contract = (  total_cost_of_electrician + total_cost_of_plumber + total_cost_of_roofer + total_cost_for_extra_workers
                                + total_cost_of_wood + total_cost_of_concrete + total_cost_of_windows + total_cost_of_doors );
    net_profit_from_contract = contract_incoming_revenue - total_cost_of_contract;

    //running total of $ paid for all jobs,  subcontractors, materials, and extra workers
    total_paid_for_all_electrical_work += total_cost_of_electrician;
    total_paid_for_all_plumbing_work += total_cost_of_plumber;
    total_paid_for_all_roofing_work += total_cost_of_roofer;
    total_paid_for_all_materials += ( total_cost_of_wood + total_cost_of_concrete + total_cost_of_windows + total_cost_of_doors );
    total_paid_for_all_contracts_extra_workers += total_cost_for_extra_workers;

    // running grand total of revenue, costs, and net profit/loss
    grand_total_for_all_incoming_revenue += contract_incoming_revenue;
    grand_total_for_all_contracts_costs += total_cost_of_contract;
    grand_total_net_profit_for_all_contracts += net_profit_from_contract;

    
}





//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
//function 4: output_contract_data_toFile -> specification:

	        Output_contract_data_toFile is a void function that receives the integer contract number, the ofstream output_to_file, the float contract incoming revenue
	        the float total cost of contract, and the float value of  net profit from contract.

            Using these values The Function:
            (1) for the first contract it outputs to the file a header
            (2) and then for all contracts the incoming revenue, the cots and the total net profit loss

    --> the ofstream output_to_file is referenced back to the calling function. Nothing is returned

*/

void output_contract_data_toFile(int contract_num, ofstream & output_tofile, float  contract_incoming_revenue,
                                 float  total_cost_of_contract,float  net_profit_from_contract)
{

    output_tofile << fixed << setprecision(2) << showpoint;
    if(contract_num == 1)
    {
        output_tofile <<"\n\t/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/"<<endl;
        output_tofile << "\t\t  Passaic County Contracting Company: Net Profit Breakdown"<<endl;
        output_tofile <<"\t/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/"<<endl;
    }
    else
        output_tofile<<"\n"<<endl;
    output_tofile <<"\n\t---------------------------------------------------------------------------------"<<endl;
    output_tofile << "\t\t\t\t\t Contract #"<<contract_num << endl;
    output_tofile <<"\t---------------------------------------------------------------------------------"<<endl;
    output_tofile << "\n\tTotal Incoming revenue from Contract #" << contract_num << ":\t\t\t" << right << contract_incoming_revenue << endl;
    output_tofile << "\tTotal Spent on Completing Contract #" << contract_num << ":\t\t\t\t" << right << total_cost_of_contract << endl;
    output_tofile <<"\t---------------------------------------------------------"<<"\t-------------"<<endl;
    if (net_profit_from_contract>0)
        output_tofile  << "\tTotal Profit from Contract #" << contract_num << ":  \t\t\t\t" << right << net_profit_from_contract<<"\n"<< endl;
    else
        output_tofile  << "\tTotal Loss from Contract #" << contract_num << ":\t\t\t\t\t" << right << net_profit_from_contract<<"\n"<< endl;


}





//____________________________________________________________________________________________________________________________________________________________________________________________________________
/*
//function 5: output_all_projects_totals_toFile -> specification:

	        output_all_projects_totals_toFile is a void function that takes the ofstream output_to_file, the double total_paid_for_all_electrical_work,the float total_paid_for_all_plumbing_work,
            the float total_paid_for_all_roofing_work, the float total_paid_for_all_materials, the float total_paid_for_all_contracts_extra_workers,
            the float  grand_total_for_all_incoming_revenue, the float grand_total_for_all_contracts_costs, and the float grand_total_net_profit_for_all_contracts)                                                          Using these values The Function:

            Using these values The Function:
            (1) outputs to the file a breakdown of total costs of each catagory of workers/materials/subcontractors for all the contracts
            (2) outputs the Running total incoming revenue, costs and net profit/loss for all the contracts
            (3) and then closes the file

    --the ofstream output_tofile is referenced back to the calling function (** although this is not technically necessary for this specific program).
    Nothing is returned.
*/

void output_all_projects_totals_toFile(ofstream & output_tofile, double total_paid_for_all_electrical_work,float total_paid_for_all_plumbing_work, float total_paid_for_all_roofing_work,
                                       float total_paid_for_all_materials,float total_paid_for_all_contracts_extra_workers, float grand_total_for_all_incoming_revenue,
                                       float grand_total_for_all_contracts_costs, float grand_total_net_profit_for_all_contracts)
{

    output_tofile <<"\n\n\t---------------------------------------------------------------------------------"<<endl;
    output_tofile << "\t\t\t  Breakdown of Costs Incurred for all Contracts"<<endl;
    output_tofile <<"\t---------------------------------------------------------------------------------"<<endl;

    output_tofile << "\n\tA. Salaries, Subcontractors and Materials:"<<endl;
    output_tofile << "\t------------------------------------------"<<endl;
    output_tofile << "\tTotal Cost of all Electrical Work (for all Contracts) : \t" << right << total_paid_for_all_electrical_work << endl;
    output_tofile << "\tTotal Cost of all Plumbing Work (for all Contracts) : \t\t" << right << total_paid_for_all_plumbing_work << endl;
    output_tofile << "\tTotal Cost of all Roofing Work (for all Contracts) : \t\t" << right << total_paid_for_all_roofing_work << endl;
    output_tofile << "\tTotal Cost of all Materials (for all Contracts): \t\t" << right << total_paid_for_all_materials << endl;
    output_tofile << "\tTotal Salaries paid, for all Contracts : \t\t\t" << right << total_paid_for_all_contracts_extra_workers << endl;
    output_tofile <<"\n\t---------------------------------------------------------"<<"\t-------------"<<endl;

    output_tofile << "\n\tB. Net Profit:"<<endl;
    output_tofile << "\t--------------"<<endl;
    output_tofile << "\tTotal Incoming revenue from All Contracts: \t\t\t" << right <<  grand_total_for_all_incoming_revenue << endl;
    output_tofile << "\tTotal Spent On/(to complete) All Contracts: \t\t\t" << right << grand_total_for_all_contracts_costs << endl;
    if (grand_total_net_profit_for_all_contracts>0)
        output_tofile  << "\tTotal Net Profit from all Contracts:   \t\t\t\t" << right << grand_total_net_profit_for_all_contracts<< endl;
    else
        output_tofile  << "\tTotal Net loss from all Contracts:   \t\t\t\t"  << right << grand_total_net_profit_for_all_contracts<< endl;

    output_tofile <<"\n\n\t---------------------------------------------------------------------------------"<<endl;
    output_tofile <<"\t/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/-/"<<endl;

    //close the file
    output_tofile.close();

}


