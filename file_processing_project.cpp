#include <iostream>
// input output library (hidden file)
#include <fstream>
// file library (hidden file)
#include <cstring>
// string library (hidden file)
#include <stdio.h> // C standard input output library (hidden file)

#include <cstdlib>
using namespace std;
struct data
{
	int id;
	char courses[10], name[10];
};
// using the namespace std (standard) at every line
class file
{ // define a class with a name (file)

private:
	// class data1
	string filename, filename2; /* filename for creating file with a name (input), 
	                                 data of the file to enter and
									 filename2 for searching and (output) the data of a file*/
								/*object as datatype of the file not the class
	                                myfile for input and output a file*/
								//   for inputting the file and reading the file
	int status;
	char filef[20]; //for searching the string filename

	data d1;

public:
	void addfile()
	{ // member function to add a file
		data d1;
		ofstream myfile("myfile3.txt", ios::out | ios::app); /*open a file and the user
	                              enters their name*/

		if (!myfile.is_open())		 //condition to check that the file wasn't being opened
			cout << "file error!\n"; // if it wasn't opened print that

		else
		{ // if the file was opened do that
			cout << "Enter the id of the student: ";
			cin >> d1.id;
			cout << "Enter your name of the student: ";
			cin >> d1.name; //output the data to the file

			cout << "Enter the course name: ";
			cin >> d1.courses;
			myfile.write((char *)&d1, sizeof(d1));

			myfile.close(); //close the file
		}
	}

	void showdata()
	{ //member function to show the data of a file
		data d1;
		ifstream load("myfile3.txt"); //open the file the user typed its name

		if (!load.is_open()) //condition to check the file wasn't opened
			cout << "cannot find the file!\n";

		else
		{ //condition if the file was opened
			cout << "The data in the file is: ";
			cout << "\n"
				 << "ID\t\tStudent name\t\tCourse name" << endl;
			/*while (load>>d1.id){
				cout << d1.id << "\t\t";
			}
			while (load>>d1.name)
			{							 //read the data of the file
				cout << d1.name <<"\t\t"; //print the data in the file to the screen
			}
			while (load>>d1.courses)
			{							 
				cout << d1.courses << endl; 
			}*/
			load.read((char *)&d1, sizeof(d1));
			while (!load.eof())
			{
				cout << d1.id << "\t\t" << d1.name << "\t\t\t" << d1.courses << endl;
				load.read((char *)&d1, sizeof(d1));
			}
			load.close(); //close the file
		}
	}
	void search()
	{
		data d1;
		ifstream load("myfile3.txt"); //open the file the user typed its name
		char k[10];
		cout << "Enter a name to search for: ";
		cin >> k;
		bool Gotit = false;
		if (!load.is_open()) //condition to check the file wasn't opened
			cout << "cannot find the file!\n";

		else
		{
			load.read((char *)&d1, sizeof(d1));
			while (!load.eof())
			{
				if (strcmp(k, d1.name) == 0)
				{
					Gotit = true;
					cout << "\n"
						 << "ID\t\tStudent name\t\t\tCourse name" << endl;
					cout << d1.id << "\t\t" << d1.name << "\t\t" << d1.courses << endl;
					break;
				}

				load.read((char *)&d1, sizeof(d1));
				load.close();
			}
			if (!Gotit)
			{
				cout << "Not found\n";
				;
			}
		}
	}
	void Update()
	{
		data d1;
		fstream load("myfile3.txt", ios::in | ios::out); //open the file the user typed its name
		int k;
		cout << "Enter id to update its record: ";
		cin >> k;
		bool Gotit = false;
		if (!load.is_open()) //condition to check the file wasn't opened
			cout << "cannot find the file!\n";

		else
		{
			load.read((char *)&d1, sizeof(d1));
			while (!load.eof())
			{
				if (k == d1.id)
				{
					cout << "Enter the new name: ";
					cin >> d1.name;
					int cursor = load.tellg();
					int dsize = sizeof(d1);
					load.seekp(cursor - dsize, ios::beg);
					load.write((char *)&d1, sizeof(d1));
					Gotit = true;
					load.seekg(cursor - dsize, ios::beg);
					load.read((char *)&d1, sizeof(d1));
					cout << "\n"
						 << "ID\t\tStudent name\t\t\tCourse name" << endl;
					cout << d1.id << "\t\t" << d1.name << "\t\t\t" << d1.courses << endl;
					break;
				}

				load.read((char *)&d1, sizeof(d1));
				load.close();
			}
			if (!Gotit)
			{
				cout << "Not found\n";
				;
			}
		}
	}
	void Delete()
	{ //member function to delete a file
		cout << "Enter the name of the file: ";
		cin >> filef; //user enter the filename
		cout << endl;

		if (status = remove(filef) == 0)
		{ /*delete a file with (remove function)
		                                    condition to check if the file was deleted*/
			cout << "File deleted succesfully\n";
		}
		else //condition to check if the file wasn't deleted
			cout << "unable to delete file!\n";
	}
	void Deleterecord()
	{
		ifstream load("myfile3.txt");
		ofstream saved("temp.txt");
		char k[10];
		cout << "Enter a name to delete its record: ";
		cin >> k;
		bool Gotit = false;
		if (!load.is_open()) //condition to check the file wasn't opened
			cout << "cannot find the file!\n";

		else
		{
			load.read((char *)&d1, sizeof(d1));
			while (!load.eof())
			{
				if (strcmp(k, d1.name) != 0)
				{
					saved.write((char *)&d1, sizeof(d1));
				}

				load.read((char *)&d1, sizeof(d1));
			}
			load.close();
			saved.close();
			remove("myfile3.txt");
			rename("temp.txt", "myfile3.txt");
		}
	}


};
int main()
{ //main function (program is starting)
jump:
	data d1; // goto here
	file f;	 //define (f) of the file (datatype)
	fstream myfile;
	int choose;
	char other;
	//print the menu instructions
	cout << " \t\t\t\t\t\t      MENU\n \t\t\t\t\t\t 1) Add record\n \t\t\t\t\t\t 2) Show records\n";
	cout << " \t\t\t\t\t\t 3) delete file\n \t\t\t\t\t\t 4) Search\n \t\t\t\t\t\t 5) update\n \t\t\t\t\t\t 6)"; 
	cout<<" delete record\n \t\t\t\t\t\t 7) Exit\n\n";
	cout << "(Enter a number from 1 to 7), your choice: ";
	cin >> choose; //user enters the number of the thing that want to do

	switch (choose)
	{

	case 1:
		//if they enter 1
		f.addfile(); //call the member function addfile
		cout << "press 'y' or 'Y' if you want to add another record: ";
		cin >> other;
		if (other == 'y' || other == 'Y')
		{ //condition if they want to add another file
			f.addfile();
		}
		goto jump;

	case 2:			  //if they enter 2
		f.showdata(); //call the member function showdata
		cout << "\n\n";
		goto jump; //goto statement jump (menu)
		break;
	case 3:			//if they enter 3
		f.Delete(); //call the member function delete
		goto jump;	//goto statement jump (menu)
		break;
	case 4:
		f.search();
		goto jump; //goto statement jump (menu)
		break;
	case 5:
		f.Update();
		goto jump; //goto statement jump (menu)
		break;
	case 6:
		f.Deleterecord();
		goto jump;
		break;
	case 7:				//if they enter 4
		myfile.close(); //close the file
		cout << "Good bye!";
		return 0; //close the program and return 0 to the main function
		break;
	default: //wrong input will close the program
		cout << "Enter a correct choice(number)\n";
		return 0; //close the program and return 0 to the main function
	}
	return 0; //close the program and return 0 to the main function
}
