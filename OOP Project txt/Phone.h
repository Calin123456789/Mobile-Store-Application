#pragma once
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
class Phone
{
private:
	int stock;
	string type;
	string brand;
	string name;
	int price;
	int ram;
	int rom;
	string operatingSystem;
	float screenSize;
	int camQuality;
	int battery;
public:
	//constructor of Phone Class:
	Phone();
	//Parameterized Constructor of Phone Class
	Phone(string type, int stock, string brand, string name, int price, int ram, int rom, string operatingSystem, float screenSize, int camQuality, int battery);
	//function removes commas from reading from file
	void removeComma(string& str);
	//function adds commas when writing back to file to insure correct file formatting
	string addComma(string str);
	//function to read data from the file
	int fileInput(int pos);
	void setStock(int stock);
	string getBrand();
	int getPrice();
	int getStock();
	string getName();
	string getType();
	int getRam();
	int getRom();
	string getOs();
	int getCamQuality();
	int getBattery();
	//funtion writes data back to file
	void fileOutput(string fileName);
	//overloaded >> operator gets data from user
	friend istream& operator >> (istream& in, Phone& sp);
	//overloaded << operator prints class data to screen
	friend ostream& operator<<(ostream& os, Phone sp);
};