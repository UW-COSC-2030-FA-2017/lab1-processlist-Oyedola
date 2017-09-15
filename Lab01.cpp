//Oyedola Ajao
//COSC 2030 FALL 2017
//Lab1
//09-15-2017

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

int main()
{
	ifstream infile;
	string file;
	int count(0);
	double x = 0;
	double y = 0;
	double z = 0;
	double d = 0;

	cout << "Please input a file name: ";

	getline(cin, file);

	infile.open(file);
	//if the file fails to open then the program loops, asking the user to re-enter the file name.
	if (infile.fail())
	{
		do 
		{
			cout << "Unable to open file." << endl;
			cout << "Please input a file name: ";
			getline(cin, file);
			infile.open(file);
		} while ((!infile.fail()));
	}
	
	while (!infile.eof())
	{

		if (count == 0)
		{
			infile >> x;

			y = x;
		}
		else if (count == 1)
		{
			infile >> x;

			z = d;

			d = y;
		}
		else if (count > 1)
		{
			z = d;

			infile >> d;
		}

		count++;
	}
	cout << "Count: " << count << endl;

	cout << "First Two Numbers: " << y << " " << x << endl;
	
	cout << "Last Two Numbers: " << z << " " << d << endl;

	cout << "Thank you for using the program. Have a wonderful day!" << endl;

	infile.close();

	return 0;
}