
// Hashtable Project

#include <iostream>
#include <exception>
#include <string>
#include <cstdio>
#include "hashtable.h"
#include "Student.h"
using namespace std;

int main()
{


	try
	{
                Hashtable h(10);

		while(true)
		{
                        cout << "Enter 'Set' to set a key/value pair to a hash table \n 'Get' to retrieve a value in the table, \n 'Delete' to delete a value from the table \n 'Load' to retrieve the load factor. \n and 'exit' to exit the program"
			string str;
			cin >> str;
			if(cin.eof())
			{
				break;
			}
			if(str.compare("exit") == 0)
			{
				break;
			}
                        else if(str.compare("Set") == 0)
			{
				int key;
				string name;
				double gpa;
				cin >> key >> name >> gpa;
				Student tmp(name, gpa);
				h.insert(key, tmp);
			}
			else if(str.compare("lookup") == 0)
			{
				int key;
				cin >> key;
				h.lookup(key);
			}
			else if(str.compare("delete") == 0)
			{
				int key;
				cin >> key;
				h.remove(key);
			}
			else if(str.compare("print") == 0)
			{
				h.print();
			}
			else
			{
				cin.clear();
				cout << "Inputed string format was incorrect" << endl;
			}
		}
	}
	catch(exception& ex)
	{
		cerr << ex.what() << endl;
	}

	return 0;
}
