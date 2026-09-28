#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

void display_int(int num)
{
	cout << num << ", ";
}


int main()
{
	cout << "The Number Cruncher Program\n\n";

	vector<int> numbers;
	numbers.reserve(11);

	srand(time(nullptr));

	for (int i = 0; i < numbers.capacity(); i++)
	{
		int number = rand() % 30;
		numbers.push_back(number);
	}

	cout << numbers.size() << " RANDOM NUMBERS: ";
	for_each(numbers.begin(), numbers.end(), display_int);
	cout << endl;

	// sort in ascending order
	sort(numbers.begin(), numbers.end());
	cout << numbers.size() << " SORTED NUMBERS: ";
        for_each(numbers.begin(), numbers.end(), display_int);
        cout << endl;

        //calc sum of the numbers
        int sum = accumulate(numbers.begin(), numbers.end(), 0);
        cout << "Sum: " << sum << " | ";

        int avg = sum / numbers.size();
        cout << "Average: " << avg << " | ";

        auto maxIter = max_element(numbers.begin(), numbers.end());
        cout << "Max Number: " << *maxIter << " | ";

        auto minIter = min_element(numbers.begin(), numbers.end());
        cout << "Max Number: " << *minIter << "\n";

        int num = 10;
        bool numExists = binary_search(numbers.begin(), numbers.end(), num);

        if (numExists)
        {
		int c = count(numbers.begin(), numbers.end(), num);
		cout << "The number " << num << " occurs " << c << " time(s)\n";
        }
        else
        {
		cout << "These numbers do NOT include " << num << "!\n\n";
        }


}
