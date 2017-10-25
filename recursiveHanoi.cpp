#include <iostream>
#include <ctime>
using namespace std;


void move(int count, int start, int finish, int temp);

int main()
{
	int num;
	clock_t start, end;
	cout << "Please enter the number of disks: ";
	cin >> num;

	start = clock();
	move(num, 1, 3, 2);
	end = clock();

	cout << "\ntime consuming: " << (end - start) << "ms" << endl << endl;
	return 0;
}

void move(int count, int start, int finish, int temp)
{
	if ( count <= 0 )
		return;

	move(count - 1, start, temp, finish);
	cout << "Move disk " << count << " from " << start
		 << " to " << finish << "." << endl;
	move(count - 1, temp, finish, start);
}