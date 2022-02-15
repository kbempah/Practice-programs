// Program Name: Name Search
// Written by: Kwadwo A Bempah
// Description: This program tells whether a boy name or girl name entered 
//				by a user is popular or not
// Test Input:              	Expected Output: 
// --------------------      	-------------------------
// 1)Jaden; Sarah				Jaden is popular, Sarah is popular
// 2)Aidan; Emilia				Aidan is popular, Emilia is not popular
// 3)Bounce; Marielys           Bounce is not popular, Marielys is not popular
// 4)Kwadwo; Natasha			Kwadwo is not popular, Natasha is not popular
// 5) n; n						No name entered for boy, no name enetered for girl

// 6) Where name files do not open, error message is displayed and program ends

// Revision History
// Date:        Revised By:     Action:
// ------------------------------------------------------------------
// mm/dd/yy    (your initials)  (what you did to the code)

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<cstdlib>
#include<algorithm>

void formatName(std::string&);

int main()
{
	bool condition1, condition2;		//To control program if file open fails
	
	std::string boy, 		//To hold boy name
		   girl, 		//To hold girl name
		   name;		//To hold names read from files
	
	char	again;		//To hold Y/N option for program rerun
		   
	std::ifstream file;		//File operator
	
	std::vector<std::string> boyNames;		//BoyNames vector
	std::vector<std::string> girlNames;		//GirlNames vector
	
	//Open file containing boy names
	file.open("D:\\KB Personal Stuff\\Programming I\\BoyNames.txt");
	
	//Check for file open error, display error message if fail	 
	if (file)
	{
		condition1 = false;		//Set condition to false if file open
		
		//Read names from file into name, increase boyNames by name
		while (file >> name)
			boyNames.push_back(name);
		
		//Sort boyNames for binary search
		std::sort(boyNames.begin(),boyNames.end());
			
		//CLose file
		file.close();
	}
	else
	{
		condition1 = true;		//File open fails
		std::cout << "Error opening file 'BoyNames.txt'\n";
	}
		
	//Open file containing girl names
	file.open("D:\\KB Personal Stuff\\Programming I\\GirlNames.txt");
	
	//Check for file open error, display error message if fail
	if (file)
	{
		condition2 = false;
		
		//Read names from file into value, increase girlNames by
		while (file >> name)
			girlNames.push_back(name);
		
		//Sort girlNames
		std::sort(girlNames.begin(),girlNames.end());
		
		//Close file
		file.close();
	}
	else
	{
		condition2 = true;
		std::cout << "Error opening file 'GirlNames.txt'\n";
	}
	
	if (condition1 || condition2)
		return 0;		//End program when file open fails
	else
	{
		do
		{
			system("CLS");
			std::cout << "Enter the name of a boy or a girl " 
		 		 "to check if it is popular or not.\n";
		 		 
			//Get boy name to search for
			std::cout << "Enter the first name of a boy or N if you do not wish to: ";
			getline(std::cin, boy);
			char *temp1 = new char[sizeof(boy)+1];
			strcpy(temp1, boy.c_str());
			formatName(boy);
			
	
			//Get girl name to search for
			std::cout << "Enter the first name of a girl or N if you do not wish to: ";
			getline(std::cin, girl);
			char *temp2 = new char[sizeof(girl)+1];
			strcpy(temp2, girl.c_str());
			formatName(girl);
			
			if (boy != "N")
			{	
				//Call to function binary_search with boyNames, boy as arguments
				if (std::binary_search(boyNames.begin(), boyNames.end(), boy))
					std::cout << temp1 <<" is among the most popular boy's names.\n";
				else
					std::cout << temp1 <<" is not among the most popular boy's names.\n";
			}
			else 
				std::cout << "No name was entered for boy.\n";
	
			if (girl != "N")
			{
				//Call to function binary_search wtih girlNames and girl as arguments
				if (std::binary_search(girlNames.begin(), girlNames.end(), girl))
					std::cout << temp2 <<" is among the most popular girl's names.\n";
				else
					std::cout << temp2 <<" is not among of the most popular girl's names.\n";
			}
			else 
				std::cout << "No name was entered for girl.\n";
		
			//Ask user if they want to rerun program
			std::cout << "Do you want to check the popularity of another set of names? (Y/N): ";
			std::cin >> again;
			std::cin.ignore();	//Ignore input buffer
		
			//Check user input for propram rerun
			while (toupper(again) != 'Y' && toupper(again) != 'N')
			{
				std::cin.clear();
				std::cin.ignore(CHAR_MAX,'\n');
				std::cout << "Please enter Y or N: ";
				std::cin >> again;
			}
			
			delete[]temp1; 
			delete[]temp2;
	
		} while (toupper(again) == 'Y');
	}
	
	return 0;
}

void formatName(std::string& name)
{
	name[0] = char(toupper(name[0])) ; 
	for(int i=1;i<name.length();i++)
		name[i] = char(tolower(name[i]));
}

