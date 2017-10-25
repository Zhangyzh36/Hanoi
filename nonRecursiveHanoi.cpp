#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void move(int count);
inline int next(int);
inline int counterNext(int);


int main()
{
	int num;
	clock_t start, end;
	cout << "Please enter the number of disks: ";
	cin >> num;

	start = clock(); 
	move(num);
	end = clock();

	cout << "\ntime consuming: " << (end - start) << "ms" << endl << endl;;

	return 0;
}

void move(int count)
{
	vector<int> index;
	vector<int> position(count + 1, 1);
	for (int i = 1; i <= count; ++i)
	{
		int size = index.size();
		index.push_back(i);
		for (int j = 0; j < size; ++j)
			index.push_back(index[j]);

	}

	for (int i = 0; i < index.size(); ++i)
	{

		if ((index[i] + count) & 1)
		{
			cout << "Move disk " << index[i] << " from " << position[index[i]] << " to "
				 << next(position[index[i]]) << "." << endl;
			position[index[i]] = next(position[index[i]]);
		}
		else
		{
			cout << "Move disk " << index[i] << " from " << position[index[i]] << " to "
				 << counterNext(position[index[i]]) << "." << endl;
			position[index[i]] = counterNext(position[index[i]]);
		}

	}

}

int next(int cur)
{
	return (cur % 3) + 1; 
}

int counterNext(int cur) 
{
	return (cur + 1) % 3 + 1;
}
