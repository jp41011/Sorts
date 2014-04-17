// Juan P - C++
/* Will implement several different sorting algorithms.
Will also compare runtime of the different sorting algorithms
*/
#include <iostream>
#include <vector>
#include <stdlib.h> // rand - random numbers
#include <time.h>
using std::cout;
using std::endl;
using std::cin;
using std::vector;

std::ostream& operator << (std::ostream& out, const vector<int>& vec)
{
	unsigned int size = vec.size();
	for(unsigned int i=0; i < size; i++)
		out << vec[i] << " ";
	out << endl;
}

int main()
{
	unsigned int num;
	vector<int> vec; // vector to store elements
	cout << "Testing out algorithms" << endl;
	cout << "How many random elements: ";
	cin >> num;

	srand(time(NULL)); // initialize random seed

	for(unsigned int i=0; i < num; i++)
		vec.push_back((rand()%2000 - 1000)); // random values. range: -1000 to 1000

	cout << vec;

	//conclusion
	char redo;
	cout << "Redo: r\tExit: e\t? ";
	cin >> redo;
	if(redo == 'r')
		main();

	return 0;
}