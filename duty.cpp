#include <iostream>
#include <string>
using namespace std;

int main()
{

	//initial setup
	string cheesetype, cheeseimporter;
	double cheese_value, import1, import2, import3, sum;
	const double FIRST_ROUND = 0.011;
	const double SECOND_ROUND = 0.02;
	const double SECOND_EX = 0.014;
	const double FINAL_ROUND = 0.029;

	cout << "Cheese type: ";
	getline(cin, cheesetype);

	cout << "Value: ";
	cin >> cheese_value;
	cin.ignore(10000, '\n');

	cout << "Importer : ";
	getline(cin, cheeseimporter);

	cout << "---" << endl;

	//calculation for duty amount

	if (cheese_value <= 1000)
	{
		import1 = cheese_value * FIRST_ROUND;
		import2 = 0;
		import3 = 0;
		cout.setf(ios::fixed);
		cout.precision(2);
		sum = import1 + import2 + import3;
	}

	else if (cheese_value > 1000 && cheese_value <= 13000)
	{
		import1 = 1000 * FIRST_ROUND;

		if (cheesetype == "cheshire" || cheesetype == "stilton")
			import2 = (cheese_value - 1000) * SECOND_EX;
		else
			import2 = (cheese_value - 1000) * SECOND_ROUND;

		import3 = 0;
		cout.setf(ios::fixed);
		cout.precision(2);
		sum = import1 + import2 + import3;
	}

	else if (cheese_value > 13000)
	{
		import1 = 1000 * FIRST_ROUND;

		if (cheesetype == "cheshire" || cheesetype == "stilton")
			import2 = 12000 * SECOND_EX;
		else
			import2 = 12000 * SECOND_ROUND;

		import3 = (cheese_value - 13000) * FINAL_ROUND;
		cout.setf(ios::fixed);
		cout.precision(2);
		sum = import1 + import2 + import3;
	}

	//types of error message
	if (cheesetype == "")
		cout << "You must enter a cheese type";
	else if (cheese_value < 0)
		cout << "The value must be positive";
	else if (cheeseimporter == "")
		cout << "You must enter an importer";
	else
		cout << "The import duty for " << cheeseimporter << " is $" << sum << endl;
	return 0;
	

}