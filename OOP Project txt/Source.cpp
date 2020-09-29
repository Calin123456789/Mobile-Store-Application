#include<iostream> //including <iostream> header file to perform I/O operations
#include<string> //including <string> header file to perform string class operations
#include<fstream> //including <fstream> to perform file handling operations
#include<vector> //including <vector> to use vectors and vertor operations
#include"Phone.h" //including user defined "Phone.h" header File
#include"Database.h" //Including User defined "Database.h" header File
#include"SalesManagement.h" //Including user defined "SalesManagement.h" header File

//constructor of Phone class
/*Initailizes default values for Phone Class Data Members*/
Phone::Phone() :
	stock(0), type(""), brand(""), name(""), price(0), ram(0), rom(0), operatingSystem(""), screenSize(0), camQuality(0), battery(0)
{}
//Parameterized constructor of Phone class
/*Initailizes values for Phone Class Data Members*/
Phone::Phone(string type, int stock, string brand, string name, int price, int ram, int rom, string operatingSystem, float screenSize, int camQuality, int battery) :
	stock(stock), type(type), brand(brand), name(name), price(price), ram(ram), rom(rom), operatingSystem(operatingSystem), screenSize(screenSize), camQuality(camQuality), battery(battery)
{}

//function removes commas from reading from file
//so correct data gets written to object
void Phone::removeComma(string& str)
{
	unsigned int i = 0;
	while (i < str.length())
	{
		if (str[i] == ',')
		{
			str[i] = ' ';
		}
		i++;
	}
}
//function adds commas when writing back to file
//so correct formatting is done whne writting back to file
string Phone::addComma(string str)
{
	unsigned int i = 0;
	while (i < str.length())
	{
		if (str[i] == ' ')
		{
			str[i] = ',';
		}
		i++;
	}
	return str;
}

//function reads data from file.
//takes postion as parameter so reading happens from correct position
//and returns last postion data is read from
int Phone::fileInput(int pos)
{
	int p;
	fstream file;
	file.open("Phone Database.txt", ios::in);
	file.seekg(pos);
	file >> stock;
	file >> type;
	file >> brand;
	file >> name;
	removeComma(name);
	file >> price;
	file >> ram;
	file >> rom;
	file >> operatingSystem;
	removeComma(operatingSystem);
	file >> screenSize;
	file >> camQuality;
	file >> battery;
	p = file.tellg();
	file.close();
	return p;
}

void Phone::setStock(int stock)
{
	this->stock = stock;
}
string Phone::getBrand()
{
	return brand;
}
int Phone::getPrice()
{
	return price;
}
int Phone::getStock()
{
	return stock;
}
string Phone::getName()
{
	return name;
}
string Phone::getType()
{
	return type;
}
int Phone::getRam()
{
	return rom;
}
int Phone::getRom()
{
	return rom;
}
string Phone::getOs()
{
	return operatingSystem;
}
int Phone::getCamQuality()
{
	return camQuality;
}
int Phone::getBattery()
{
	return battery;
}

//funtion writes data back to file with correct formatting of data
void Phone::fileOutput(string fileName)
{
	fstream file;
	file.open(fileName + ".txt", ios::out | ios::app);
	file << stock << " ";
	file << type << " ";
	file << brand << " ";
	file << addComma(name) << " ";
	file << price << " ";
	file << ram << " ";
	file << rom << " ";
	file << addComma(operatingSystem) << " ";
	file << screenSize << " ";
	file << camQuality << " ";
	file << battery << " ";
	file << endl;
	file.close();
}


//overloaded >> operator gets data from user
istream& operator >> (istream& in, Phone& sp)
{
	cout << "Enter the total Stock of the phone:";
	in >> sp.stock;
	cout << "type:";
	in >> sp.type;
	cout << "Enter the Brand of phone:";
	in.ignore();
	getline(in, sp.brand);
	cout << "Enter the Name of phone:";
	getline(in, sp.name);
	cout << "Enter Price of phone:";
	in >> sp.price;
	cout << "Enter the RAM of phone:";
	in >> sp.ram;
	cout << "Enter the ROM of the phone:";
	in >> sp.rom;
	cout << "Enter Operating System of the phone:";
	in.ignore();
	getline(in, sp.operatingSystem);
	cout << "Enter Screen Size in inches:";
	in >> sp.screenSize;
	cout << "Enter the Camera quality in MP of the phone:";
	in >> sp.camQuality;
	cout << "Enter the Battery Capacity in mAH of the phone:";
	in >> sp.battery;
	return in;
}

//overloaded <<operator prints data on the screen
ostream& operator<<(ostream& os, Phone sp)
{
	os << setiosflags(ios::right) << setw(10) << sp.brand << setw(15) << sp.type << setw(20)
		<< sp.name << setw(10) << sp.price << " Rs" << setw(18) << sp.operatingSystem
		<< setw(7) << sp.ram << " GB" << setw(7) << sp.rom << " GB"
		<< setw(8) << sp.screenSize << "inches" << setw(14) << sp.camQuality << " MP"
		<< setw(10) << sp.battery << " mAH" << endl;
	return os;
}

//Constructor of MobileDatabase Class:
/*Constructor intailizes the data of Phone Class
from file and adds the data to vector*/
MobileDatabase::MobileDatabase()
{
	int totalPhones;
	Phone p;
	int pos;
	int rPos;
	file.open("Phone Database.txt", ios::in);
	if (file.is_open())
	{
		file >> totalPhones;
		for (int i = 0; i < totalPhones; i++)
		{
			pos = file.tellg();
			rPos=p.fileInput(pos);
			file.seekg(rPos);
			ph.push_back(p);
		}
		file.close();
	}
	else
	{
		cerr << "File not found" << endl;
		exit(1);
	}
}

void MobileDatabase::writeToFile()
{
	file.open("Phone Database.txt", ios::out);
	file << ph.size() << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		ph[i].fileOutput("Phone Database");
	}
	file.close();
}

void MobileDatabase::ranFileOutput()
{
	fstream file;
	file.open("MobData.dat", ios::out);
	for (int i = 0; i < ph.size(); i++)
	{
		file.write((char*)&ph[i], sizeof(Phone));
	}
	file.close();
}

//overloaded << operator prints all Phone data on the Screen 
ostream& operator<<(ostream& os, MobileDatabase& mD)
{
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < mD.ph.size(); i++)
	{
		cout << setw(3) << count++ << "  ";
		cout << mD.ph[i];
	}
	count = 0;
	return os;
}
//function to edit Phone Record
void MobileDatabase::editRecord()
{
	string comp;
	bool found = false;
	unsigned int count = 0;
	cout << "Enter the name of the Phone you want to edit the data of:";
	getline(cin, comp);
	while (count<ph.size())
	{
		if (ph[count].getName() == comp)
		{
			found = true;
			cin >> ph[count];
			break;
		}
		count++;
	}
	if (!found)
	{
		cout << "The Phone was not found!" << endl;
	}
	else
	{
		cout << "Data has been edited" << endl;
	}
	system("pause");
}
//function add new Phone data
void MobileDatabase::addRecord()
{
	Phone tempRec;
	cin >> tempRec;
	ph.push_back(tempRec);
}
//function to delete a Phones record
void MobileDatabase::deleteRecord()
{
	string deletePhone;
	bool found=false;
	cout << "Enter the name of the phone whose data you want to delete:";
	getline(cin, deletePhone);	
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getName() == deletePhone)
		{
			found = true;
			ph.erase(ph.begin() + i);
		}
	}
	if (!found)
	{
		cout << "Record of Phone not Found!";
	}

}

//Only shows Phone type matching user Preference
void MobileDatabase::searchType(string type, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getType() == type)
		{
			cout << setw(3) << count << "  ";
			cout << ph[i];
			file << ph[i];
			found = true;
			count++;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//Only shows Phone having Operating System matching users choice
void MobileDatabase::searchOs(string OS, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getOs() == OS)
		{
			cout << setw(3) << count << "  ";
			cout << ph[i];
			file << ph[i];
			found = true;
			count++;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//Only shows Phone having Name matching users choice
void MobileDatabase::searchName(string name, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getName() == name)
		{
			cout << setw(3) << count << "  ";
			cout << ph[i];
			file << ph[i];
			count++;
			found = true;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//Only shows Phone having Brand matching users choice
void MobileDatabase::searchBrand(string brand, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getBrand() == brand)
		{
			cout << setw(3) << count<<"  ";
			cout << ph[i];
			file << ph[i];
			found = true;
			count++;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//shows all Phone having more Ram then users Preference
void MobileDatabase::searchRam(int ram, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getRam() >= ram)
		{
			cout << ph[i];
			file << ph[i];
			found = true;
			count++;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//only Shows phones Having more rom then users Preference
void MobileDatabase::searchRom(int rom, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getRom() >= rom)
		{
			cout << setw(3) << count << "  ";
			cout << ph[i];
			file << ph[i];
			found = true;
			count++;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//shows Phones within a Certain Price Range
void MobileDatabase::searchPrice(int startPrice, int endPrice, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getPrice() >= startPrice || ph[i].getPrice() <= endPrice)
		{
			cout << setw(3) << count << "  ";
			cout << ph[i];
			file << ph[i];
			found = true;
			count++;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//allows user to search based on multiple parameters
//and shows search result
void MobileDatabase::search(string brand, string os, int startPrice, int endPrice, int camQuality, int ram, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getBrand() == brand && ph[i].getOs() == os
			&& ph[i].getPrice() >= startPrice && ph[i].getPrice() <= endPrice
			&&ph[i].getCamQuality() >= camQuality && ph[i].getRam() >= ram)
		{
			cout << setw(3) << count << "  ";
			cout << ph[i];
			file << ph[i];
			found = true;
			count++;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//allows user to search Phone based on Camera Quality
//Only shows Phones Having more Camera Quality then User Preference
void MobileDatabase::searchCamQuality(int camQuality, string userId)
{
	bool found = false;
	cout << "Search result:" << endl;
	file.open(userId + ".txt", ios::out);
	int count = 1;
	cout << setiosflags(ios::right) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	for (unsigned int i = 0; i < ph.size(); i++)
	{
		if (ph[i].getCamQuality() >= camQuality)
		{
			cout << setw(3) << count << "  ";
			cout << ph[i];
			file << ph[i];
			found = true;
			count++;
		}
	}
	file.close();
	if (!found)
	{
		cout << "No Phone Matches Criteria";
	}
}

//shows previous seache result of the user:
void MobileDatabase::showSearch(string userId)
{
	string searchData;
	int count = 1;
	cout << setiosflags(ios::left) << setw(15) << "Brand" << setw(15) << "Type" << setw(20)
		<< "Name" << setw(13) << "Price" << setw(18) << "Operating System" << setw(10) << "RAM"
		<< setw(10) << "ROM" << setw(14) << "Screen Size" << setw(17) << "Camera Quality"
		<< setw(14) << "Battery" << endl;
	file.open(userId + ".txt", ios::in);
	if (file.is_open())
	{
		while (getline(file, searchData))
		{
			cout << setw(5) << count++;
			cout << searchData << endl;
		}
		file.close();
	}
	else
	{
		cerr << "File not found" << endl;
		exit(1);
	}
}






//function allows user to buy a Phone
//Also creates and prints Invoice
void SalesManagement::buyPhone(MobileDatabase& mD)
{
	int date;
	int month;
	int year;
	string name;
	string userId;
	string phoneName;
	char found = false;
	char confirm;
	cout << "Enter your Name:";
	getline(cin, name);
	cout << "Enter your User ID:";
	getline(cin, userId);
	cout << "Enter the name of the Phone you want to buy:";
	getline(cin, phoneName);
	for (unsigned int i = 0; i < mD.ph.size() ; i++)
	{
		if (mD.ph[i].getName() == phoneName)
		{
			found = true;
			cout << mD.ph[i].getName() << " costs " << mD.ph[i].getPrice() << endl;
			cout << "Are you sure you want to buy this Phone?" << endl;
			cout << "Enter 'Y' for 'yes' or 'N' for 'No'" << endl;
			cout << ">>";
			cin >> confirm;
			if (confirm == 'y' || confirm == 'Y')
			{
				mD.ph[i].setStock(mD.ph[i].getStock() - 1);
				cout << "Enter the date (Format:dd-mm-yyyy):";
				setw(2); cin >> date; cin.ignore();
				setw(2); cin >> month; cin.ignore();
				setw(4); cin >> year;
				string strDate = to_string(date) + "-" + to_string(month) + "-" + to_string(year);
				createInvoice(name, userId, mD.ph[i], strDate);
				printInvoice(userId);
				file.open(strDate + ".txt", ios::out | ios::app);
				file << userId << " ";
				mD.ph[i].addComma(name);
				file << name << " ";
				mD.ph[i].addComma(phoneName);
				file << phoneName << " ";
				file << mD.ph[i].getPrice() << endl;
				file.close();

				break;
			}
		}
	}
	if (!found)
	{
		cout << "The Phone was not found";
		system("pause");
	}
}

//creates invoice of the Phone User has Bought
void SalesManagement::createInvoice(string name, string userId, Phone ph, string date)
{
	file.open("Invoice-" + userId + ".txt", ios::out);
	file << "------------------------------------------------------------------" << endl;
	file << "                          Invoice" << endl;
	file << "------------------------------------------------------------------" << endl;
	file << date << endl;
	file << "User Id:" << userId << endl;
	file << "User Name:" << name << endl;
	file << "Product Bought:" << endl;
	file << ph.getBrand() << " " << ph.getName() << "   Price:" << ph.getPrice();
	file.close();
}

//reads Invoice from file and prints data on the screen
void SalesManagement::printInvoice(string userId)
{
	string invoice;
	file.open("Invoice-" + userId + ".txt", ios::in);
	while (getline(file, invoice))
		cout << invoice << endl;
	file.close();
}

//funtion makes report of all Phone Bought during a certain period of time.
void SalesManagement::makeReport()
{
	int startDate;
	int startMon;
	int startYear;
	int endDate;
	int endMon;
	int endYear;
	int totalPrice = 0;
	bool found = false;
	cout << "Enter the Start Date (Format:dd-mm-yyyy)";
	setw(2); cin >> startDate; cin.ignore();
	setw(2); cin >> startMon; cin.ignore();
	setw(4); cin >> startYear;
	string strStartDate = to_string(startDate) + "-" + to_string(startMon) + "-" + to_string(startYear);
	cout << "Enter the end Date (Format:dd-mm-yyyy)";
	setw(2); cin >> endDate; cin.ignore();
	setw(2); cin >> endMon; cin.ignore();
	setw(4); cin >> endYear;
	string strEndDate = to_string(endDate) + "-" + to_string(endMon) + "-" + to_string(endYear);
	if (startDate <= endDate)
	{
		while (startDate <= endDate)
		{
			string strDate = to_string(startDate) + "-" + to_string(startMon) + "-" + to_string(startYear);
			file.open(strDate + ".txt", ios::in);
			if (file.is_open())
			{
				string userId;
				string name;
				string phoneName;
				int price;
				found = true;
				cout << strDate << ":" << endl;
				while (file >> userId)
				{
					file >> name;
					removeComma(name);
					file >> phoneName;
					removeComma(phoneName);
					file >> price;
					cout << userId << " " << name << " " << phoneName << " " << price << endl;
					totalPrice += price;
				}
				file.close();
			}
			startDate++;
			strStartDate = to_string(startDate) + "-" + to_string(startMon) + "-" + to_string(startYear);
		}
		if (found)
		{
			cout << "total Sales amount=" << totalPrice << endl;
		}
		else
		{
			cout << "No records Found in the specified Dates" << endl;
		}
	}
	else
	{
		cout << "The start date must be less then to equal to End Date" << endl;
	}
}

//function removes commas from data being read
//for correct data storage
void SalesManagement::removeComma(string& str)
{
	unsigned int i = 0;
	while (i < str.length())
	{
		if (str[i] == ',')
		{
			str[i] = ' ';
		}
		i++;
	}
}