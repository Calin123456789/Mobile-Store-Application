#include<iostream> //including <iostream> header file to perform I/O operations
#include<string> //including <string> header file to perform string class operations
#include"Phone.h" //including user defined "Phone.h" header File
#include"Database.h" //Including User defined "Database.h" header File
#include"SalesManagement.h" //Including user defined "SalesManagement.h" header File
using namespace std;
int main()
{
	//intantiating MoblileDatabase Class obj;
	MobileDatabase mD;
	char choice1;
	char choice2;
	//Printing Menu For User:
	cout << "Welcome to the Phone Management Program" << endl;
	cout << "This program handles Mobile Phone Database and sales Management." << endl;
	cout << "Made by Muhammad Wajahat Enrollment:01-134192-102"<<endl;
	cout << "Class BSCS-2B"<<endl;
	system("pause");
	cout << "Using this program you can perform the following tasks:" << endl;
	cout << "1)You can View all available Phones" << endl;
	cout << "2)You can add Phones to Database" << endl;
	cout << "3)You can delete Phones from the Database" << endl;
	cout << "4)You can search Phones based on user preference" << endl;
	
	system("pause");
	system("cls");
	while (1)
	{
		//Showing user Operation Choice:
		cout << "Enter 1 to Perform Database Operations." << endl;
		cout << "Enter 2 to Perform sales Operations.";
		cout << "Enter 'q' or 'Q' to exit" << endl;
		cout << ">>";
		cin >> choice1;
		switch (choice1)
		{
		//case containg DataBase operations;
		case '1':
		{
			//Showing DataBase Operations Choice to user:
			cout << "Choose the Operation you want to perform:" << endl;
			cout << "Enter 1 to Print veiw all Phones" << endl;
			cout << "Enter 2 to edit a Phone Data" << endl;
			cout << "Enter 3 to Add new phone record" << endl;
			cout << "Enter 4 to delete a phone's record" << endl;
			cout << "Enter 5 to print perform searching operaations" << endl;
			cout << ">>";
			cin >> choice2;
			cin.ignore();
			switch (choice2)
			{
			//case to Print Data of all Phones on the Screen:
			case '1':
			{
				cout << mD;
				break;
			}
			//Case to add New Phone record:
			case '2':
			{
				mD.editRecord();
				mD.writeToFile();
				break;
			}
			//Case to add New Phone record:
			case '3':
			{
				mD.addRecord();
				mD.writeToFile();
				break;
			}
			//case to Delete Phone record:
			case '4':
			{
				mD.deleteRecord();
				mD.writeToFile();
				break;
			}
			//case containing searching Operations:
			case '5':
			{
				string userID;
				cout << "Enter your user ID:";
				getline(cin, userID);
				int searchChoice;
				//showing user the search operations they can perform:
				cout << "Choose the Criteria to search:"<<endl;
				cout << "enter 1 to search based on \"brand\"." << endl;
				cout << "enter 2 to search based on \"Type\"."<<endl;
				cout << "enter 3 to search based on \"Operating System\"."<<endl;
				cout << "enter 4 to search based on \"RAM\"."<<endl;
				cout << "enter 5 to search based on \"ROM\"."<<endl;
				cout << "enter 6 to search based on \"Price Range\"."<<endl;
				cout << "enter 7 to search based on \"Camera Quality\"."<<endl;
				cout << "enter 8 to search based on \"Name\"."<<endl;
				cout << "enter 9 to search on \"multiple Parameters\"."<<endl;
				cout << "enter 10 to see user's Previous search Result."<<endl;
				cout << ">>";
				cin >> searchChoice;
				cin.ignore();
				switch (searchChoice)
				{
					//case to search based on Brand of Phone:
					case 1:
					{
						string brand;
						cout << "Enter the brand you want to search:" << endl;
						getline(cin, brand);
						mD.searchBrand(brand, userID);
						break;
					}
					//case to search based on Type of Phone:

					case 2:
					{
						string type;
						cout << "Enter the type of Phone you want to search:" << endl;
						getline(cin, type);
						mD.searchType(type, userID);
						break;
					}
					//case to search based on Operating System of Phone:

					case 3:
					{
						string os;
						cout << "Enter the Operating System you want to search:" << endl;
						getline(cin, os);
						mD.searchOs(os, userID);
						break;
					}
					//case to search based on RAM of Phone:
					case 4:
					{
						int ram;
						cout << "Enter the minimum RAM you want in the Phone:" << endl;
						cin >>ram;
						mD.searchRam(ram, userID);
						break;
					}
					//case to search based on ROM of Phone:
					case 5:
					{
						int rom;
						cout << "Enter the minimum ROM you want in the Phone:" << endl;
						cin >> rom;
						mD.searchRom(rom, userID);
						break;
					}
					//case to search Price Range:
					case 6:
					{
						int minPrice;
						int maxPrice;
						cout << "Enter the Minimum Price:";
						cin >> minPrice;
						cout << "Enter the Maximum Price:";
						cin >> maxPrice;
						mD.searchPrice(minPrice, maxPrice, userID);
						break;
					}
					//case to search based on Camera Quality:
					case 7:
					{
						int camQuality;
						cout << "Enter the Minimum Camera Quality you want:" << endl;
						cin >> camQuality;
						mD.searchCamQuality(camQuality, userID);
						break;
					}
					//case to search based on name of Phone:
					case 8:
					{
						string name;
						cout << "Enter the Name of the Phone you want to search:" << endl;
						getline(cin, name);
						mD.searchName(name, userID);
						break;
					}
					//case to search based multiple user choices
					case 9:
					{
						string brand;
						int minPrice;
						int maxPrice;
						string type;
						string os;
						int ram;
						int camQuality;
						cout << "Enter the brand you want to search" << endl;
						getline(cin, brand);
						cout << "Enter the type of Phone you want to search:" << endl;
						getline(cin, type);
						cout << "Enter the Operating System you want to search:" << endl;
						getline(cin, os);
						cout << "Enter the minimum RAM you want in the Phone:" << endl;
						cin >> ram;
						cout << "Enter the Minimum Price:";
						cin >> minPrice;
						cout << "Enter the Maximum Price:";
						cin >> maxPrice;
						cout << "Enter the Minimum Camera Quality you want:" << endl;
						cin >> camQuality;
						mD.search(brand, os, minPrice, maxPrice, camQuality, ram, userID);
						break;
					}
					//case to Show previous search result made by user:
					case 10:
					{
						cout << "Your Previous Search Result:" << endl;			
						mD.showSearch(userID);
						break;
					}
					//Default in case of incorrect Choice by user:
					default:
					{
						cout << "Invalid Entry!!" << endl;
						break;
					}
				}
				break;
			}
			//Default in case of incorrect Choice by user:
			default:
			{
				cout << "Invalid Entry!!" << endl;
				break;
			}
			}
			break;
		}
		//case Containing the Sales operations:
		case '2':
		{
			//intantiating SaleManagement class obj;
			SalesManagement sale;
			char salesChoice;
			//showing user the sales Operations user can perform:
			cout << "Choose the Operation you want to perform:" << endl;
			cout << "Enter 1 to buy Phone" << endl;
			cout << "Enter 2 to Print the invoice of a previous transaction" << endl;
			cout << "Enter 3 to see report of phones bought during a certain Period" << endl;
			cin >> salesChoice;
			cin.ignore();
			switch (salesChoice)
			{
				//case containg function to buy new Phone:
				case '1':
				{
					sale.buyPhone(mD);
					break;
				}
				//case containg function to print invoice of a previously bought phone:
				//using user id:
				case '2':
				{
					string userID;
					cout << "Enter the user ID of the invoice you want to View:";
					getline(cin, userID);
					sale.printInvoice(userID);
					break;
				}
				//case containing function to make report of Phones Bought during certain period:
				case '3':
				{
					sale.makeReport();
					break;
				}
				default:
				{
					cout << "Invalid Entry!!" << endl;
					break;
				}
			}
			break;
		}
		//case to exit the program:
		case 'q':
		case 'Q':
		{
			cout << "you have exitted the program" << endl;
			system("pause");
			mD.writeToFile();
			mD.ranFileOutput();
			exit(0);
		}
		//default case to check invald user choice:
		default:
		{
			cout << "Invalid Entry!!";
			cout << "Returning to Menu" << endl;
			break;
		}
	}
	//pausing screen after an operation is performed:
	system("pause");
	//clearing screen after a operation is performed:
	system("cls");
}
return 0;
}