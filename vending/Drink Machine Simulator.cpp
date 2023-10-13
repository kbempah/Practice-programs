// Program Name: Vending Simulator
// Written by: Kwadwo A Bempah
// Description: This is a program that simulates the operation of a vending machine

#include <iostream>
#include <iomanip>
#include <cctype>
#include <string>
#include <cstdlib>

#define SIZE 5	//drink array size macro

/*
The Beverage structure defines member variables to hold drink information: drink name, drink cost, drink ID, and drink quantity
*/
struct Beverage
{
	std::string Name;
	double Price;
	int Code;
	int Quantity;
};

/*
The Sales structure defines member variables to hold individual quantities sold and total quantities sold
*/
struct Sales
{
	int totalSold, 
		cokeSold, 
		rootSold, 
		lemonSold, 
		grapeSold, 
		creamSold;
};

//Function prototypes
void getDrinkChoice(int &);
void validatePayment(double&);
void vendingNow(Beverage[], int, double&);


int main()
{		
	Beverage drink[SIZE] {
						 	{"Cola", 1.50, 101, 20}, 
						 	{"Root Beer", 1.50, 201, 20}, 
						 	{"Lemon-Lime", 1.50, 301, 20}, 
						 	{"Grape Soda", 2.25, 401, 20}, 
						 	{"Cream Soda", 2.25, 501, 20}
						};
	
	Sales unit {0}; 			//Initialize all Sale members to 0
						
	double amount = 0.0;		//To hold payment
	double revenue = 0.0;		//To hold machine revenue	   
	int drinkChoice;			//To hold drink choice
	char buyAgain;				//To hold decision to use machine again
	
	do
	{
		system("CLS");
		
		//Display drink offerings
		std::cout << "\t\tFunny Vending Services\nHere are our drink offerings:\n"
			<< "Drink" << std::setw(12) << "Code" << std::setw(10) << "Price\n"
			<< "---------------------------\n"
		 	<< "Cola" << std::setw(12) << std::right << "101" << std::setw(11) << std::right << "$1.50\n" 
		 	<< "Root Beer" << std::setw(7) << std::right <<"201" << std::setw(11) << std::right << "$1.50\n"
		 	<< "Lemon-lime" << std::setw(6) << std::right <<"301" << std::setw(11) << std::right << "$1.50\n"
		 	<< "Grape Soda" << std::setw(6) << std::right <<"401" << std::setw(11) << std::right << "$2.25\n"
		 	<< "Cream Soda" << std::setw(6) << std::right <<"501" << std::setw(11) << std::right << "$2.25\n";
		
		//Get drink choice
		getDrinkChoice(drinkChoice);
		
		if(drinkChoice != -1)
		{
			//Get payment
			std::cout << "Insert payment. No card, cash payment only! Accepts $2 and $5: $";
			std::cin >> std::setw(3) >> amount;
			validatePayment(amount);
			
			//Program branch for Cola
			if(drinkChoice == drink[0].Code)
			{
				if(drink[0].Quantity == 0)
					std::cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= drink[0].Price))
					{
						std::cout << "Insufficient amount...Insert payment: $";
						std::cin >> amount;
						validatePayment(amount);
					}
					if(amount >= drink[0].Price)
					{
						vendingNow(drink, 0, amount);	 
						revenue += 1.50;
						drink[0].Quantity -= 1;
						unit.cokeSold += 1;
						unit.totalSold += 1;
					}		
				}	
			}
			
			//Program branch for Root Beer
			else if(drinkChoice == drink[1].Code)
			{
				if(drink[1].Quantity == 0)
					std::cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= drink[1].Price))
					{
						std::cout << "Insufficient amount...Insert payment: $";
						std::cin >> amount;
						validatePayment(amount);
					}
					if(amount >= drink[1].Price)
					{
						vendingNow(drink, 1, amount);
						revenue += 1.50;
						drink[1].Quantity -= 1;
						unit.rootSold += 1;
						unit.totalSold += 1;
					}
				}	
			}
			
			//Program branch for Lemon-Lime
			else if(drinkChoice == drink[2].Code)
			{
				if(drink[2].Quantity == 0)
					std::cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= drink[2].Price))
					{
						std::cout << "Insufficient amount...Insert payment: $";
						std::cin >> amount;
						validatePayment(amount);
					}
					if(amount >= drink[2].Price)
					{
						vendingNow(drink, 2, amount);
						revenue += 1.50;
						drink[2].Quantity -= 1;
						unit.lemonSold += 1;
						unit.totalSold += 1;
					}
				}
				
			}
			
			//Program branch for Grape soda
			else if(drinkChoice == drink[3].Code)
			{
				if(drink[3].Quantity == 0)
					std::cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= drink[3].Price))
					{
						std::cout << "Insufficient amount...Insert payment: $";
						std::cin >> amount;
						validatePayment(amount);
					}
					if(amount >= drink[3].Price)
					{
						vendingNow(drink, 3, amount);
						revenue += 2.25;
						drink[3].Quantity -= 1;
						unit.grapeSold += 1;
						unit.totalSold += 1;
					}
				}
			}
			
			//Program branch for Cream Soda
			else if(drinkChoice == drink[4].Code)
			{
				if(drink[4].Quantity == 0)
					std::cout << "Drink is sold out.\n";
				else
				{
					while(!(amount >= drink[4].Price))
					{
						std::cout << "Insufficient amount...Insert payment: $";
						std::cin >> amount;
						validatePayment(amount);
					}
					if(amount >= drink[4].Price)
					{
						vendingNow(drink, 4, amount);
						revenue += 2.25;
						drink[4].Quantity -= 1;
						unit.creamSold += 1;
						unit.totalSold += 1;
					}
					
				}
			}
			
		}
		else
		{
			//Display total sales and revenue made
			std::cout << "At " << __TIME__ << ", " << __DATE__ << " ,the machine total earned is $" << std::fixed << std::setprecision(2) << revenue << " and has sold a total of " << unit.totalSold << " unit(s).\n"
				 << drink[0].Name << " sold " << unit.cokeSold << " unit(s).\n"
				 << drink[1].Name << " sold " << unit.rootSold << " unit(s).\n"
				 << drink[2].Name << " sold " << unit.lemonSold << " unit(s).\n"
				 << drink[3].Name << " sold " << unit.grapeSold << " unit(s).\n"
				 << drink[4].Name << " sold " << unit.creamSold << " unit(s).\n";
				 
			return 0;
		}
		
		//Allow users to make multiple purchases
		std::cout << "\nWould you like to buy another drink(Y/N): ";
		std::cin >> std::setw(1) >> buyAgain;
		while(toupper(buyAgain) != 'Y' && toupper(buyAgain) != 'N')
		{
			std::cout << "Please enter Y or N: ";
			std::cin >> std::setw(1) >> buyAgain;
		}
		buyAgain = toupper(buyAgain);
		std::cin.ignore();
	} while(buyAgain == 'Y'); std::cout << std::endl; 
	
	//Display total sales and revenue if user quits at selection menu 
	switch(buyAgain)
		case 'N': std::cout << "At " << __TIME__ << ", " << __DATE__ << " ,the machine total earned is $" << std::fixed << std::setprecision(2) << revenue << " and has sold a total of " << unit.totalSold << " unit(s).\n"
					   << drink[0].Name << " sold " << unit.cokeSold << " unit(s).\n"
					   << drink[1].Name << " sold " << unit.rootSold << " unit(s).\n"
					   << drink[2].Name << " sold " << unit.lemonSold << " unit(s).\n"
					   << drink[3].Name << " sold " << unit.grapeSold << " unit(s).\n"
					   << drink[4].Name << " sold " << unit.creamSold << " unit(s).\n";
			
	return 0;
}

/**********************************************************************************************************
Function Definitions
**********************************************************************************************************/

/*
getDrinkChoice gets a selection from the user and validates user selection
*/
void getDrinkChoice(int& selection)
{
	std::cout << "Enter a drink code from the list or -1 to quit: ";
	std::cin >> selection;
	
	while(selection != 101 && selection != 201 && selection != 301 && selection != 401 && selection != 501 && selection != -1)
	{
		std::cout << "Please enter a drink code on the list or -1 to quit: ";
		std::cin.clear();
		std::cin.ignore(INT_MAX,'\n');
		std::cin >> selection;
	}
}

/*
validatePayment accepts the user's payment amount and validates the amount
*/
void validatePayment(double& payment)
{
	while(std::cin.fail()||payment != 2.00 && payment != 5.00)
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "Insert $2 or $5: $";
		std::cin >> std::setw(3) >> payment;
	}
}

/*
vendingNow displays information about drink that is being vended
*/
void vendingNow(struct Beverage item[], int index, double& value)
{
	std::cout << "Vending " << item[index].Name << "...\n"
		 << "Dispensing $"<< std::setprecision(2) << std::fixed << (value-item[index].Price) <<" in change...\n"
		 << "Ending transaction..." << std::endl;
}
