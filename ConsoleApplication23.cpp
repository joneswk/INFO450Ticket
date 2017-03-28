// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

// ConsoleApplication18Ticket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "string"
#include <iomanip>
using namespace std;

class Ticket
{
	static int IDGenerator;
	string issueStatus;
	string input;
	int ID;
	char issueType;
	string issuePriority;
	string callerName;
	string description;
	int usersImpacted;

public:
	Ticket();
	int getID();
	void CaptureTicket();
	void ShowTicket();
	void CloseTicket();

};

int Ticket::IDGenerator = 1;

Ticket::Ticket()
{
	issueStatus = "OPEN";
	ID = IDGenerator;
	IDGenerator++;
}

int Ticket::getID()
{
	return ID;
}

void Ticket::CaptureTicket()
{
	cin.ignore();
	cout << "What is the name of the caller" << endl;
	getline(cin, callerName);
	cout << "Which category does your issue belong to? Type the letter (s) for Server, the letter (a) for Application and (c) for a(C)cess." << endl;
	cin >> issueType;
	switch (issueType)
	{
	case 's':
	case 'S':
		input = "Server";
		break;
	case 'a':
	case 'A':
		input = "Application";
		break;
	case 'c':
	case 'C':
		input = "Access";
		break;

	default:
		cout << "Invalid Entry, Please type the letter (s) for Server, the letter (a) for Application and (c) for a(C)cess";
	}
	cin.clear();
	cin.ignore();
	cout << "Describe the following issue please" << endl;
	getline(cin, description);
	cout << "How many users was affected?" << endl;
	cin >> usersImpacted;
	cin.clear();
	cin.ignore();

	if (usersImpacted < 10)
	{
		issuePriority = "Low!";
	}
	if (usersImpacted >= 10 && usersImpacted < 50)
	{
		issuePriority = "Medium!!";
	}
	else if (usersImpacted >= 50)
	{
		issuePriority = "High!!!";
	}

	cout << "Your TicketID is:" << ID << endl;
}

void Ticket::ShowTicket()
{
	cout << "\n*****************************\n";
	std::cout << "Ticket Summary\n";
	std::cout << "\n*****************************\n";
	std::cout << "TicketID:" << setw(2) << ID << endl;
	std::cout << "Type:" << setw(20) << input << endl;
	std::cout << "Status:" << setw(16) << issueStatus << endl;
	std::cout << "Caller's Name:" << setw(8) << callerName << endl;
	std::cout << "Users Impacted:" << setw(6) << usersImpacted << endl;
	std::cout << "Priority:" << setw(18) << issuePriority << endl;
	std::cout << "\n*****************************\n";
}


void Ticket::CloseTicket()
{
	issueStatus = "CLOSED";
	cout << "Ticket # " << ID << " is closed " << issueStatus << endl;
}

int main()
{

	int newTicket = 0;
	char input;
	Ticket Ticketsys[100];

	cout << "Would you like to open a ticket ? Type the letter (Y)es to Continue or Type the letter (N)o to discontinue" << endl;
	cin >> input;

	while (input == 'Y' || input == 'y')
	{
		Ticketsys[newTicket].CaptureTicket();
		newTicket++;
		cout << "Would you like to open a ticket ? Type the letter (Y)es to Continue or Type the letter (N)o to discontinue" << endl;
		cin >> input;
	}

	for (int i = 0; i < newTicket; i++)
	{
		Ticketsys[i].ShowTicket();
	}

	Ticketsys[0].CloseTicket();
	cin >> input;
	return 0;
}
