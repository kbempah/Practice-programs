/*This is a program that simulates the operation of a drink vending machine*/

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cstdlib>
using namespace std;

/*
The Beverage structure defines member variables to hold drink information: drink name, drink cost, drink ID, and drink quantity
*/
struct Beverage
{
	string Name;
	double Cost;
	int Code;
	int Quantity;
};

/*
The Sales structure defines member variables to hold individual quantities sold and total quantities sold
*/
struct Sales
{
	int totalSold, cokeSold, rootSold, lemonSold, grapeSold, creamSold;
};

//Function prototypes
void getDrinkChoice(int &);
void validatePayment(double&);

int main()
{
	const int SIZE = 5;		
	Beverage soft[SIZE] {
						 	{"Cola", 1.50, 101, 20}, 
						 	{"Root Beer", 1.50, 201, 20}, 
						 	{"Lemon-Lime", 1.50, 301, 20}, 
						 	{"Grape Soda", 2.25, 401, 20}, 
						 	{"Cream Soda", 2.25, 501, 20}
						};
	
	Sales unit {0}; 			//Initialize all Sale members to 0
						
	double amount = 0.0;		//To hold payment amount
	double revenue = 0.0;		//To hold machine revenue
		   
	int drinkChoice;			//To hold drink choice
	char buyAgain;				//To hold decision to use machine again
	
	do
	{
		//Display drink offerings
		cout << "\t\tFunny Vending Services\nHere are our drink offerings:\n"
		 << "Cola" << setw(14) << right << "101\n" 
		 << "Root Beer" << setw(9) << right <<"201\n" 
		 << "Lemon-lime" << setw(8) << right <<"301\n"
		 << "Grape Soda" << setw(8) << right <<"401\n"
		 << "Cream Soda" << setw(8) << right <<"501\n";
		
		//Get drink choice
		getDrinkChoice(drinkChoice);
		
		if(drinkChoice != -1)
		{
			//Get payment
			cout << "Insert payment. No card, cash payment only! Accepts $2 and $5: ";
			cin >> setw(3) >> amount;
			validatePayment(amount);
			
			//Program branch for Cola
			if(drinkChoice == soft[0].Code)
			{
				if(soft[0].Quantity == 0)
					cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= soft[0].Cost))
					{
						cout << "Insufficient amount...Insert payment: $";
						cin >> amount;
						validatePayment(amount);
					}
					if(amount >= soft[0].Cost)
					{
						cout << "Vending " << soft[0].Name << "...\n"
						 	 << "Dispensing $"<< setprecision(2) << fixed << (amount-1.50) <<" in change...\n" 
						 	 << "Ending transaction..." << endl;
						revenue += 1.50;
						soft[0].Quantity -= 1;
						unit.cokeSold += 1;
						unit.totalSold += 1;
					}		
				}	
			}
			
			//Program branch for Root Beer
			else if(drinkChoice == soft[1].Code)
			{
				if(soft[1].Quantity == 0)
					cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= soft[1].Cost))
					{
						cout << "Insufficient amount...Insert payment: $";
						cin >> amount;
						validatePayment(amount);
					}
					if(amount >= soft[1].Cost)
					{
						cout << "Vending " << soft[1].Name << "...\n"
							 << "Dispensing $"<< setprecision(2) << fixed << (amount-1.50) <<" in change...\n"
							 << "Ending transaction..." << endl;
						revenue += 1.50;
						soft[1].Quantity -= 1;
						unit.rootSold += 1;
						unit.totalSold += 1;
					}
				}	
			}
			
			//Program branch for Lemon-Lime
			else if(drinkChoice == soft[2].Code)
			{
				if(soft[2].Quantity == 0)
					cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= soft[2].Cost))
					{
						cout << "Insufficient amount...Insert payment: $";
						cin >> amount;
						validatePayment(amount);
					}
					if(amount >= soft[2].Cost)
					{
						cout << "Vending " << soft[2].Name << "...\n"
					 	 	 << "Dispensing $"<< setprecision(2) << fixed << (amount-1.50) <<" in change...\n"
					 	 	 << "Ending transaction..." << endl;
						revenue += 1.50;
						soft[2].Quantity -= 1;
						unit.lemonSold += 1;
						unit.totalSold += 1;
					}
				}
				
			}
			
			//Program branch for Grape soda
			else if(drinkChoice == soft[3].Code)
			{
				if(soft[3].Quantity == 0)
					cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= soft[3].Cost))
					{
						cout << "Insufficient amount...Insert payment: $";
						cin >> amount;
						validatePayment(amount);
					}
					if(amount >= soft[3].Cost)
					{
						cout << "Vending " << soft[3].Name << "...\n"
						 	 << "Dispensing $"<< setprecision(2) << fixed << (amount-2.25) <<" in change...\n"
						 	 << "Ending transaction..." << endl;
						revenue += 2.25;
						soft[3].Quantity -= 1;
						unit.grapeSold += 1;
						unit.totalSold += 1;
					}
				}
			}
			
			//Program branch for Cream Soda
			else if(drinkChoice == soft[4].Code)
			{
				if(soft[4].Quantity == 0)
					cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= soft[4].Cost))
					{
						cout << "Insufficient amount...Insert payment: $";
						cin >> amount;
						validatePayment(amount);
					}
					if(amount >= soft[4].Cost)
					{
						cout << "Vending " << soft[4].Name << "...\n"
						 	 << "Dispensing $"<< setprecision(2) << fixed << (amount-2.25) <<" in change...\n"
						 	 << "Ending transaction..." << endl;
						revenue += 2.25;
						soft[4].Quantity -= 1;
						unit.creamSold += 1;
						unit.totalSold += 1;
					}
					
				}
			}
			
		}
		else
		{
			//Display total sales and revenue made
			cout << "The machine earned a total of $" << fixed << setprecision(2) << revenue << " and sold a total of " << unit.totalSold << " unit(s).\n"
				 << soft[0].Name << " sold " << unit.cokeSold << " unit(s).\n"
				 << soft[1].Name << " sold " << unit.rootSold << " unit(s).\n"
				 << soft[2].Name << " sold " << unit.lemonSold << " unit(s).\n"
				 << soft[3].Name << " sold " << unit.grapeSold << " unit(s).\n"
				 << soft[4].Name << " sold " << unit.creamSold << " unit(s).\n";
				 
			return 0;
		}
		
		//Allows user to make multiple purchases
		cout << "\nWould you like to buy another drink(Y/N): ";
		cin >> setw(1) >> buyAgain;
		while(toupper(buyAgain) != 'Y' && toupper(buyAgain) != 'N')
		{
			cout << "Please enter Y or N: ";
			cin >> setw(1) >> buyAgain;
		}
		buyAgain = toupper(buyAgain);
		cin.ignore();
	} while(buyAgain == 'Y'); cout << endl; 
	
	//Display total sales and revenue if user quits at selection selection menu 
	switch(buyAgain)
		case 'N': cout << "The machine earned a total of $" << fixed << setprecision(2) << revenue << " and sold a total of " << unit.totalSold << " unit(s).\n"
					   << soft[0].Name << " sold " << unit.cokeSold << " unit(s).\n"
					   << soft[1].Name << " sold " << unit.rootSold << " unit(s).\n"
					   << soft[2].Name << " sold " << unit.lemonSold << " unit(s).\n"
					   << soft[3].Name << " sold " << unit.grapeSold << " unit(s).\n"
					   << soft[4].Name << " sold " << unit.creamSold << " unit(s).\n";
			
	return 0;
}

/**********************************************************************************************************
Function Definitions
**********************************************************************************************************/

/*
getDrinkChoice gets a selection from the user and validates user selection
*/
void getDrinkChoice(int& drink)
{
	cout << "Enter a drink code from the list or -1 to quit: ";
	cin >> drink;
	
	while(drink != 101 && drink != 201 && drink != 301 && drink != 401 && drink != 501 && drink != -1)
	{
		cout << "Please enter a drink code on the list or -1 to quit: ";
		cin.clear();
		cin.ignore();
		cin >> drink;
	}
}

/*
validatePayment accepts the user's payment amount and validates the amount
*/
void validatePayment(double& a)
{
	while(cin.fail()||a != 2.00 && a != 5.00)
	{
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Insert $2 or $5: $";
		cin >> setw(3) >> a;
	}
}

