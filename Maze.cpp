#include <iostream>
#include "list.h"
#include "maze.h"
#include "mazeCell.h"
#include <string>
#include <fstream>

using namespace std;

void maze::Check(std::vector<short> & reference, int x)
{
	if (std::find(reference.begin(), reference.end(), x) != reference.end())
	{
		int random = (1 + rand() % (maze::size + 9));

		Check(reference, random);
	}
	else
	{
		reference.push_back(x);
	}
}


void maze::sides(int x)
{
	int i1(0);

	int i2(0);

	int randI(0);

	char walls = '1';

	char path = '0';

	while (i1 < x)
	{
		maze::currentcol.clear();

		maze::currentcol.push_back(walls);

		i2 = 0;

		while (i2 < x)
		{
			srand((int)maze::MakeSeeds.at(i1));

			int randg = (1 + rand() % 85);

			string SN = "0." + std::to_string(randg);

			std::random_device device;

			std::mt19937 gen(device());

			std::bernoulli_distribution rand(std::stod(SN));

			bool outcome = rand(gen);

			if (outcome == false)
			{
				path = '0';
			}
			else
			{
				path = '1';
			}

			maze::currentcol.push_back(path);

			i2++;
		}

		maze::currentcol.push_back(walls);

		maze::end.push_back(maze::currentcol);

		i1++;
	}

}
string maze::Makeupdown(int size)
{
	if (maze::updown == "")
	{
		int i = 0;

		int it = size + 2;

		char wall = '1';

		while (i < it)
		{
			maze::updown.push_back(wall);

			maze::updown.push_back(' ');

			i++;
		}
	}

	return maze::updown;
}


void maze::PrintMaze()
{
	cout << maze::Makeupdown(maze::end.size()) << endl;
	for (size_t r = 0; r < maze::end.size(); r++)
	{
		for (size_t c = 0; c < maze::end[r].size(); c++)
		{
			cout << maze::end[r][c] << " ";

			if (c != 0 && (maze::size / c) == 0)
			{
				cout << "\n";
			}
		}
	}
	cout << maze::Makeupdown(maze::end.size()) << endl;
}

void maze::MakeVectorSeeds(int x)
{
	srand(time_t(NULL));

	for (int i = 0; i < x; i++)
	{
		int randnum = (1 + rand() % 65);
		maze::Check(maze::MakeSeeds, randnum);
	}

	maze::sides(maze::size);
	return;
}

void maze::saveMaze()
{
	ofstream infile;

	string file;

	int count(0);

	cout << "Please input a file name: ";

	getline(cin, file);

	infile.open("Save_Maze");

	if (infile.fail())
	{
		do
		{
			cout << "Unable to open file." << endl;

			cout << "Please input a file name: ";

			getline(cin, file);

			infile.open("Save_Maze");

		} while (!infile.fail());
	}

	infile.close();

	return;
}
