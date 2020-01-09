// Name: Karim Ahmed
// Semester Project Part A
// CIS 253
//_______________________________________
#pragma once
#include <vector>
using namespace std;
class ServerGroup
{
private:
	// declaring servers vector of type int
	vector <int> Servers;
	// spServer as int
	int spServer;
	// freeServer as int
	int freeServer;

public:

	// ServerGroup, a constructor that will excute after the class header
	ServerGroup(int pSize);
	// spServerFree function that returns a boolean value
	bool spServerFree()
	{
		// if spServer is 0
		if (spServer == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	// server Free function that will be executed outside of the class header
	bool serverFree();
	// void function called useServer that takes avTransTime as parameter
	void useServer(int avTransTime)
	{
		// set the value of Servers in index of freeServer to avTransTime's value
		Servers[freeServer] = avTransTime;
	}
	// void function that takes an int parameter avTransTime
	void usespServer(int avTransTime)
	{
		// setting spServer to be equal to avTransTime
		spServer = avTransTime;
	}
	// void function decServers that will excute outside of the class heading
	void decServers();
	// function print servers
	void printServers()
	{
		cout << "servers: ";
		// for loop that goes over every int in Servers array(vector)
		for (int server : Servers)
		{
			cout << server << " ";
		}
		cout << endl << "special purpose Server: " << spServer << endl;
	}





};
//constructor
ServerGroup::ServerGroup(int pSize)
{
	// resizes the server array to be equal to the passed parameter
	Servers.resize(pSize);
	// for loop that goes through every element in servers
	for (int& element : Servers)
	{
		// sets every element to 0
		Servers[element] = 0;
	}
	// sets spServer to 0
	spServer = 0;


}
//boolean serverFree function
bool ServerGroup::serverFree()
{
	//int i declared
	int i;
	//for loop that goes through every element in Servers
	for (i = 0; i < Servers.size(); i++)
	{
		// if the element is 0
		if (Servers[i] == 0)
		{
			// set freserver to be equal to the index
			freeServer = i;
			//return true
			return true;
		}

	}
	// return false if not
	return false;
}
//decserver function
void ServerGroup::decServers()
{
	// if spserver is greater than 0
	if (spServer > 0)
	{
		// decrement spserver by 1
		spServer -= 1;
	}
	//int i declared
	int i;
	// for loop that goes through every element in servers
	for (i = 0; i < Servers.size(); i++)
	{
		//if element is not equal to 0
		if (Servers[i] != 0)
		{
			// deecrement the element by 1
			Servers[i] -= 1;
		}
	}
}
