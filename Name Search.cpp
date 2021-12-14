// File Name: Name Search
// Written by: Kwadwo A Bempah
// Description: This program tells whether a boy name or girl name entered 
//				by a user is popular or not
// Challenges:
// Time Spent: 2 days
// Given Input:              	Expected Output: 
// --------------------      	-------------------------
// 1)Jaden; Sarah				Jaden is popular, Sarah is popular
// 2)Aidan; Emilia				Aidan is popular, Emilia is not popular
// 3)Bounce; Marielys           Bounce is not popular, Marielys is not popular
// 4)Kwadwo; Natasha			Kwadwo is not popular, Natasha is not popular
// 5) n; n						No name entered for boy, no name enetered for girl

// 6) Where files do not open, error message is displayed and program ends

// Revision History
// Date:        Revised By:     Action:
// ------------------------------------------------------------------
// mm/dd/yy    (your initials)  (what you did to the code)
// 12/03/21			KAB			Changed search algorithm to reduce its time complexity

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

//Function prototype
int SequentialSearch(vector<string>&, string);

int main()
{
	bool condition1, condition2;		//To control program if file open fails
	
	string boy, 		//To hold boy name
		   girl, 		//To hold girl name
		   name;		//To hold names read from files
		     
	char	again;		//To hold Y/N option for program rerun
		   
	ifstream inputFile;		//File operator
	
	vector<string> boyNames;		//BoyNames vector
	vector<string> girlNames;		//GirlNames vector
	
	//Open file containing boy names
	inputFile.open("BoyNames.txt");
	
	//Check for file open error, display error message if fail	 
	if (inputFile)
	{
		condition1 = false;		//Set condition to false if file open
		
		//Read names from file into name, increase boyNames by name
		while (inputFile >> name)
			boyNames.push_back(name);
			
		//CLose file
		inputFile.close();
	}
	else
	{
		condition1 = true;		//File open fails
		cout << "Error opening file 'BoyNames.txt'\n";
	}
		
	//Open file containing girl names
	inputFile.open("GirlNames.txt");
	
	//Check for file open error, display error message if fail
	if (inputFile)
	{
		condition2 = false;
		
		//Read names from file into value, increase girlNames by
		while (inputFile >> name)
			girlNames.push_back(name);
		
		//Close file
		inputFile.close();
	}
	else
	{
		condition2 = true;
		cout << "Error opening file 'GirlNames.txt'\n";
	}
	
	if (condition1 || condition2)
		return 0;		//End program when file open fails
	else
	{
		do
		{
			cout << "Enter the name of a boy or a girl as a proper noun (first letter capitalized)\n" 
		 		 << "and I will tell you if it is popular or not.\n";
		 		 
			//Get boy name to search for
			cout << "Enter the name of a boy or N if you do not wish to: ";
			getline(cin, boy);
			cout << toupper(boy[0]) ; //<<" "<< static_cast<int> (boy[1]) << endl
	
			//Get girl name to search for
			cout << "Enter the name of a girl or N if you do not wish to: ";
			getline(cin, girl);
			
			if (boy != "N" && boy != "n")
			{	
				//Call  to function popularDisplay with boyNames, boy as arguments
				if (SequentialSearch(boyNames, boy) != -1)
					cout << boy <<" is one of the most popular boy's names.\n";
				else
					cout << boy <<" is not one of the most popular boy's names.\n";
			}
			else 
				cout << "No name was entered for boy.\n";
	
			if (girl != "N" && girl != "n")
			{
				//Call to function popularDisplay wtih girlNames and girl as arguments
				if (SequentialSearch(girlNames, girl) != -1)
					cout << girl <<" is one of the most popular girl's names.\n";
				else
					cout << girl <<" is not one of the most popular girl's names.\n";
			}
			else 
				cout << "No name was entered for girl.\n";
		
			//Ask user if they want to rerun program
			cout << "\nDo you want to check the popularity of another set of names? (Y/N): ";
			cin >> again;
			again = toupper(again);
			cin.ignore();
		
			//Check user input for propram rerun
			while (again != 'Y' && again != 'N')
			{
				cout << "Please enter Y or N: ";
				cin >> again;
				again = toupper(again);
				cin.ignore();
			}
		} while (again == 'Y');
	}
	return 0;
}

// **********************************************************************************
// Definition of function popularDisplay                                            *
// The size of name is stored into count. Count is then used to step through        *
// a loop to compare the names in name to the user input stored in person.          *
// It assigns true to isFound if a match is found and returns the value of isFound. *
// **********************************************************************************

/*bool popularDisplay(vector<string>& name, string person)
{
	bool isFound = false;
	
	for (int index = 0; index < name.size(); index++)
	{
		if (name[index] == person)
			isFound = true;
	}
	
	return isFound;
}*/

int SequentialSearch(vector<string>& name, string k)
 {
    string last = name[name.size()-1];
    name[name.size()-1] = k;
    int i = 0;
	while (name[i]!= k)
        	i++;
    name[name.size()-1] = last;
    if(i < name.size()-1 || name[name.size()-1] == k)
        return i;
    return -1;
}

