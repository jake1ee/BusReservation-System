#include<iostream>
#include<string>
using namespace std;
int a = 0;

class info {

	char seatA[8][8][4]{};
	int seat[8][8][4]{}, busn[8]{};
	float depart[8]{}, arrival[8]{};
	string driver_name[8],from[8],to[8];
	
public:

	void install();

	void check();

	void show();
	
	void reservation();

	int checkResult(int num);

	int checkAvailable(int num2);
	
	int* checkAvailableSeat(int num3, int num4);
}
;

void printLine(char symbols)
{
	for (int c = 0;c < 80;c++)
	{
		cout << symbols;
	}
}

int* info::checkAvailableSeat(int num,int bus)
{
	int place[2] = {-1,-1};
	for (int i = 0;i < 8;i++)
	{
		for (int j = 0;j < 4;j++) 
		{
			if (seat[bus][i][j] == num) {
				place[0] = i;
				place[1] = j;
				break;
			}
		}
	}
	return place;
}


void info::install() 
{
	cout << "Enter bus number: ";
		cin >> busn[a];
	cout << "Enter Driver name: ";
		cin >> driver_name[a];
	cout << "Enter Depart Time: ";
		cin >> depart[a];
	cout << "Enter Arrive Time: ";
		cin >> arrival[a];
	cout << "From: ";
		cin >> from[a];
	cout << "To: ";
		cin >> to[a];
	int p = 1;

	for (int c = 0;c < 8;c++) 
	{
		for (int i = 0;i < 4;i++) {
			
			seat[a][c][i] = p;
			p++;
			
		}
	}

	for (int c = 0;c < 8;c++)
	{
		for (int i = 0;i < 4;i++) {

			seatA[a][c][i] ='A';
			
		}
	}
	
	a++;
}

int info::checkResult(int num) 
{
	int result=-1;
	for (int c = 0;c < 8;c++) 
	{
		if (num==busn[c])
			result = c;
	}
	return result;
}

int info::checkAvailable(int num2)
{
	int c = 0;
	for (int i = 0;i < 8;i++) 
	{
		for (int k = 0;k < 4;k++) 
		{
			if (seatA[num2][i][k] == 'A')
				c++;

		}
	}
	return c;
}

void info::check() 
{
	int number;
	int result;
	cout << "Pls enter bus number: ";
	cin >> number;
	result = checkResult(number);
		if (result >= 0)
		{
			cout << "From: " << from[result] << endl;
			cout << "To  : " << to[result] << endl;
			cout << "There is " << checkAvailable(result) << " sits still available for reservation" << endl;
		}
		else if (result == -1)
		{
			cout << "You have enter an invalid bus number pls try again." << endl;
		}
}

void info::show() 
{
	int number;
	int c = 1;
	cout << "Please enter bus number: ";
	cin >> number;
	int result = checkResult(number);
		if (result >= 0)
		{
			printLine('-');
			cout << "\nBus number: " << busn[result] << endl;
			cout << "Bus Driver: " << driver_name[result] << endl;
			cout << "From: " << from[result] << "\t\tTo: " << to[result] << endl;
			cout << "Depart time: " << depart[result] << endl;
			cout << "Arrive time: " << arrival[result] << endl;
			printLine('-');
			cout << "\n | 1 A |                | 2 R | " << endl;
			cout << "   ^ ^                    ^ ^   " << endl;
			cout << "   | |                    | |   " << endl;
			cout << "   | Available            |  Reserved   " << endl;
			cout << "   Seat number            Seat number   " << endl;
			cout << "A---available for reservation \t\t\tR-reseved\n" << endl;
			for (int i = 0;i < 8;i++)
			{
				cout << endl;
				for (int j = 0; j < 4;j++)
				{
					cout << " | " << c << " " << seatA[result][i][j] << " | ";
						c++;
				}
			}
			cout << "\n";
			printLine('-');
			cout << "\n";
		}
		else if (result == -1)
		{
			cout << "You have enter an invalid bus number pls try again." << endl;
		}
	
}

void info::reservation() 
{
	int number;
	int result;
	int reserved = -1;
	cout << "Pls enter bus number: ";
	cin >> number;
	result = checkResult(number);
	if (result >= 0)
	{
		printLine('-');
		cout << "\n | 1 A |                | 2 R | " << endl;
		cout << "   ^ ^                    ^ ^   " << endl;
		cout << "   | |                    | |   " << endl;
		cout << "   | Available            |  Reserved   " << endl;
		cout << "   Seat number            Seat number   " << endl;
		cout << "A---available for reservation \t\t\tR-reseved" << endl;
		for (int i = 0;i < 8;i++)
		{
			cout << endl;
			for (int j = 0; j < 4;j++)
			{
				cout << " | " << seat[result][i][j] << " " << seatA[result][i][j] << " | ";
			}
		}
		cout << "\n";
		printLine('-');
		cout << "\n";
		
		while (reserved > 32 || reserved < 0) {
			cout << "Enter the Seat number: ";
			cin >> reserved;
			if (reserved > 32 || reserved < 0)
			{
				cout << "You have enter invalid seat number";

			}
		}

		int* seatPlace = checkAvailableSeat(reserved, result);
		bool Checking=false;
		if (seatA[result][seatPlace[0]][seatPlace[1]] = 'A')
		{
			Checking = true;
			seatA[result][seatPlace[0]][seatPlace[1]] = 'R';
		
		}
		else if(seatA[result][seatPlace[0]][seatPlace[1]] == 'R') {
			Checking = false;
		}
		
		if (Checking) {
			cout << "You have sucessful reserved the seat" << endl;
		}
		else
		{
			cout << "The Seat is Reserved" << endl;
		}
			
	}
	else if (result == -1)
	{
		cout << "You have enter an invalid bus number pls try again." << endl;
	}

}

int main() {
	
	int choice;
	info infoObject;
		cout << "	WELCOME TO LEE'S BUS RESERVATION APPLICATION" << endl;
		cout << "--------------------------------------------------------" << endl;
		cout << "0.Exit \n" << endl;
		cout << "1.Install\n" << endl;
		cout << "2.Check\n" << endl;
		cout << "3.Show\n" << endl;
		cout << "4.Reservation\n" << endl;
		cout << "Enter your choice: ";
		cin  >> choice;
		cout << "" << endl;
	while (choice != 0) {

		switch (choice)

		{
		case 1: infoObject.install();
			system("cls");
			break;

		case 2: infoObject.check();

			break;

		case 3: infoObject.show();

			break;

		case 4: infoObject.reservation();

			break;

		case 5: exit(0);

			break;
		}
			
		cout << "\n";
		cout << "0.Exit \n" << endl;
		cout << "1.Install\n" << endl;
		cout << "2.Check\n" << endl;
		cout << "3.Show\n" << endl;
		cout << "4.Reservation\n" << endl;
		cout << "Enter your choice: " ;
			cin >> choice;
		cout << "" << endl;
		system("cls");
		
	}
	system("pause>0");
}


void check()
{
}

void show()
{
}

void reservation()
{
}

int checkResult(int num)
{
	return 0;
}

int checkAvailable(int num2)
{
	return 0;
}

int checkAvailableSeat(int num3, int num4)
{
	return 0;
}
