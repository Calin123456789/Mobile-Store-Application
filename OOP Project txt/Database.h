#pragma once
#include<iostream> //including <iostream> header file to perform I/O operations
#include<string> //including <string> header file to perform string class operations
#include<fstream> //including <fstream> to perform file handling operations
#include<vector> //including <vector> to use vectors and vertor operations
#include"Phone.h" //including user defined "Phone.h" header File
using namespace std;
//container class of Phone Class
class MobileDatabase
{
private:
	//object of Phone Class
	vector<Phone> ph;
	fstream file;
public:
	//Constructor initializes the data of the vector datamember using file,
	MobileDatabase();
	//function to edit the record of a Phone:
	void editRecord();
	//function to add a record of a Phone:
	void addRecord();
	//function to delete the record of a Phone:
	void deleteRecord();
	//Outputs Data to randon file:
	void ranFileOutput();
	friend ostream& operator<<(ostream& os, MobileDatabase& mD);
	//function write the data back to file in the correct format:
	void writeToFile();
	//function to search based on type of Phone:
	void searchType(string type, string userId);
	//function to search based on Operating System of Phone:
	void searchOs(string OS, string userId);
	//function to search based on Name of Phone:
	void searchName(string name, string userId);
	//function to search based on Brand of Phone:
	void searchBrand(string brand, string userId);
	//function to search based on RAM of Phone:
	void searchRam(int ram, string userId);
	//function to search based on ROM of Phone:
	void searchRom(int rom, string userId);
	//function to search based on Price Range of Phone:
	void searchPrice(int startPrice, int endPrice, string userId);
	//function to search based on Multiple Parameters of Phone:
	void search(string brand, string os, int startPrice, int endPrice, int camQuality, int ram, string userId);
	//function to search based on Camera Quality of Phone:
	void searchCamQuality(int camQuality, string userId);
	//function to Show Previous search result of user:
	void showSearch(string userId);
	
	friend class SalesManagement;
};
