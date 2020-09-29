#pragma once
#include<iostream> //including <iostream> header file to perform I/O operations
#include<string> //including <string> header file to perform string class operations
#include<fstream> //including <fstream> to perform file handling operations
#include"Phone.h" //including user defined "Phone.h" header File
#include"Database.h" //Including User defined "Database.h" header File
using namespace std;
//class handles all Sales management operations
class SalesManagement
{
private:
	fstream file;
public:
	//function to aloow user to buy Phone:
	void buyPhone(MobileDatabase& mD);
	//function makes invoice When User Buys Phone:
	void createInvoice(string name, string userId, Phone ph, string date);
	//Function To read invlice from File and Print it on the screen:
	void printInvoice(string userId);
	//Function to make a report and Print it on the Screen:
	void makeReport();
	//Function removes comma from data when read from file:
	void removeComma(string& str);
};