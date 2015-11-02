#include <iostream>
#include <fstream>
using namespace std;

int main()
{
	int temp;
	ifstream infile("data.txt");
	ofstream outfile("out.txt");
	while(!feof(infile))
	{
		infile >> temp;
		outfile << temp <<" ";
	}
	return 0;
}