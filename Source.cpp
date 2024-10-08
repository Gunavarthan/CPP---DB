#include<iostream>
#include <sstream>
#include<fstream>
#include<string>
#include<vector>
#include<cstdlib> 
using namespace std;

class date
{
	char slash = '/';
private:
	int day;
	int month;
	int year;

	bool validDate(int d, int m, int y) {
		if (m < 1 || m > 12)
			return false;
		if (d < 1 || d > 31)
			return false;
		if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30)
			return false;
		if (m == 2) {
			if (is_leap_year(y))
				return d <= 29;
			else
				return d <= 28;
		}
		return true;
	}

	bool is_leap_year(int y)
	{
		return (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0));
	}
public:
	void get_date()
	{
		string input;
		cout << "Enter the date (dd/mm/yyyy):";
		cin >> input;
		stringstream ss(input);
		try
		{
			ss >> day >> slash >> month >> slash >> year;
			if (ss.fail() || slash != '/' || !validDate(day, month, year))
			{
				throw invalid_argument("\nINVALID INPUT: Invalid date Format or value");
			}
		}
		catch (invalid_argument& e)
		{
			cout << e.what() << endl;
			get_date();
		}

	}
	void disp_date()
	{
		cout << day << '/' << month << '/' << year;
	}
	string tostr()
	{
		string ss;
		ss = '\n' + to_string(day) + '/' + to_string(month) + '/' + to_string(year);
		return ss;
	}
};
class device
{
protected:
	int Device;
	string name;
	date d;
	string CPU;
	string GPU;
	string Memory;
	int ram;
	int storage;
	int mspeed;
public:
	virtual void get(int a)
	{
		d.get_date();
		cin.ignore();
		cout << "Enter the Device Name:"; getline(cin, name);
		cout << "Enter the Computing Unit:"; getline(cin,CPU);
		cout << "Enter the Graphic Unit:"; getline(cin,GPU);
		cout << "Enter the Memory Module:"; getline(cin,Memory);
	}
	virtual string toCSV()
	{
		string ss;
		ss = d.tostr() + ',' + name + ',' + CPU + ',' + GPU + ',' + Memory;
		return ss;
	}
};
class Mobile :public device
{
private:
	int geekbench;
	int DMark;
	int battery;
public:
	void get(int a)
	{
		device::get(0);
		Device = a;
		cout << "Enter the GeekBench Score:"; cin >> geekbench;
		cout << "Enter the 3D Mark Score:"; cin >> DMark;
		cout << "Enter the Speed of RAM(MHz):"; cin >> mspeed;
		cout << "Enter the Baterry Capacity(mAh):"; cin >> battery;
		cout << "Enter the RAM Capacity(Gb):"; cin >> ram;
		cout << "Enter the Storage Capacity(Gb):"; cin >> storage;
	}

	string toCSV()
	{
		string ss;
		ss = device::toCSV() + ',' + to_string(geekbench) + ',' + to_string(DMark) + ',' + "NA" + ',' + "NA" + ',' + to_string(device::mspeed) + ',' + to_string(battery) + ',' + to_string(device::storage) + ',' + to_string(device::ram);
		return ss;
	}
};

class PC :public device
{
protected:
	int cenebench;
	int DMark;
	int crystalDiscMark;
public:
	void get(int a)
	{
		device::get(a);
		cout << "Enter the CeneBench Score:"; cin >> cenebench;
		cout << "Enter the 3D Mark Score:"; cin >> DMark;
		cout << "Enter the Crystal disc Mark score:"; cin >> crystalDiscMark;
		cout << "Enter the Speed of RAM(MHz):"; cin >> mspeed;
		cout << "Enter the RAM Capacity(Gb):"; cin >> ram;
		cout << "Enter the Storage Capacity(Gb):"; cin >> storage;
	}

	string toCSV()
	{
		string ss;
		ss = device::toCSV() + ',' + "NA" + ',' + to_string(DMark) + ',' + to_string(cenebench) + ',' + to_string(crystalDiscMark) + ',' + to_string(device::mspeed) + ',' + "NA" + ',' + to_string(device::storage) + ',' + to_string(device::ram);
		return ss;
	}
};

class LAPTOP : public PC {
private:
	int battery;
public:
	void get(int a) override {
		PC::get(a);
		cout << "Enter the Battery Capacity:(Wh)"; cin >> battery;
	}

	string toCSV() override {
		return device::toCSV() + ',' + "NA" + ',' + to_string(DMark) + ',' + to_string(cenebench) + ',' + to_string(crystalDiscMark) + ',' + to_string(mspeed) + ',' + to_string(battery) + ',' + to_string(storage) + ',' + to_string(ram);
	}
};
vector<string> splitString(const string& str, char delimiter)
{
	vector<string> data;
	int start = 0, end = 0;
	while ((end = str.find(delimiter, start)) != string::npos)
	{
		data.push_back(str.substr(start, end - start));
		start = end + 1;
	}
	data.push_back(str.substr(start));
	return data;
}
void display(string a)
{
	// day name CPU GPU MEMORY geekbench DMark cenebench crystalDiskMark mspeed battery storage RAM
	vector<string> data = splitString(a, ',');
	if (data.size() >= 13)
	{
		cout << "DAY:" << data[0] << endl;
		cout << "NAME:" << data[1] << endl;
		cout << "CPU:" << data[2] << endl;
		cout << "GPU:" << data[3] << endl;
		cout << "MEMORY:" << data[4] << endl;
		cout << "GEEKBENCH:" << data[5] << endl;
		cout << "3DMARK:" << data[6] << endl;
		cout << "CENEBENCH:" << data[7] << endl;
		cout << "CRYSTAL DISC MARK:" << data[8] << endl;
		cout << "MEMORY SPEED:" << data[9] << endl;
		cout << "BATTERY:" << data[10] << endl;
		cout << "STORAGE:" << data[11] << endl;
		cout << "RAM:" << data[12] << endl;
	}
}

void clearScreen() {
	// Clear the console screen
	system("cls");
}

void printMenu() {
	cout << "\nOPERATIONS AVAILABLE\n====================\n";
	cout << "1. Enter new Record\n";
	cout << "2. Search record\n";
	cout << "3. Number of records\n";
	cout << "4. Display whole table\n";
	cout << "5. EXIT\n";
	cout << "CHOOSE OPERATION:";
}

void wHeader(ofstream& file)
{
	file.seekp(0, ios::end);
	if (file.tellp() == 0)
	{
		file << "Date,Name,CPU,GPU,MemoryModule,GeekBench,3DMark,CineBench,CrystalDiskMark,MemorySpeed(MHz),Battery(Wh/mAh),Storage(GiB),RAM(Gb)\n";
	}
}

int main() {
	device* s1;
	char loop = 'y';
	int choice1;

	while (loop == 'y') {
		clearScreen();
		printMenu();
		cin >> choice1;

		switch (choice1) {
		case 1: {
			clearScreen();
			int choice;
			cout << "\nCHOOSE DEVICE\n=========\n";
			cout << "1. MOBILE\n";
			cout << "2. PC\n";
			cout << "3. LAPTOP\n";
			cout << "CHOOSE OPERATION:";
			cin >> choice;

			switch (choice) {
			case 1: {
				s1 = new Mobile;
				break;
			}
			case 2: {
				s1 = new PC;
				break;
			}
			case 3: {
				s1 = new LAPTOP;
				break;
			}
			default: {
				cout << "INVALID INPUT!!!";
				exit(0);
			}
			}

			ofstream fcin("data.csv", ios::app);
			if (!fcin) {
				cout << "FILE ERROR: File Might be OPEN";
				exit(0);
			}

			wHeader(fcin);
			s1->get(choice);
			fcin << s1->toCSV();
			fcin.close();
			break;
		}
		case 2: {
			clearScreen();
			ifstream fcout("data.csv");
			string record;
			string name;
			cout << "Enter the name to be Searched:";
			cin >> name;
			int flag = 0;
			while (getline(fcout, record)) {
				if (record.find(name) != string::npos) {
					display(record);
					flag = 1;
				}
			}
			if (flag == 0) {
				cout << "RECORD NOT FOUND !!!!";
			}
			fcout.close();
			break;
		}
		case 3: {
			clearScreen();
			ifstream fcout("data.csv");
			int count = -1; // start from -1 to exclude header line
			string t;
			while (getline(fcout, t)) {
				if (!t.empty()) {
					count++;
				}
			}
			cout << "TOTAL NUMBER OF RECORDS:" << count << endl;
			fcout.close();
			break;
		}
		case 4: {
			clearScreen();
			ifstream fcout("data.csv");
			string t;
			while (getline(fcout, t)) {
				display(t);
				cout << "\n\n";
			}
			fcout.close();
			break;
		}
		case 5: {
			loop = 'n';
			cout << "THANKS FOR USING THE PROGRAM \n\n\nCHECK THE FILE FOR EXTRA DETAILS";
			break;
		}
		default: {
			cout << "INVALID CHOICE!";
			break;
		}
		}
		cout << "\n\nPress any key to continue...";
		cin.ignore();
		cin.get(); // Wait for user to press Enter
	}

	return 0;
}
/* -> Guna*/