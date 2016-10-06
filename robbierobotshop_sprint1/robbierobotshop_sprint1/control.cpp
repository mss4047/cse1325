#include "control.h"

void create()
{
	cout << "------------\n(1.) Create Robot Parts\n(2.) Robot Model\n(3.) Order\n(4.)Return to main menu\n ";
	int a;
	cin >> a;
	if (a == 4)
	{
		control();
	}
	if (a == 1)
	{

	}

}

void control()
{
	int n;
	cout << "Welcome to the Robbie Robot Shop!\n";
	cout << "What would you like to to do?\n";
	cout << "(1). Create\n(2). Report\n(3). Quit\n ";
	cin >> n;
	if (n == 1)
	{
		create();
	}
	if (n == 3)
	{
		cout << "\n\nGoodbye!\n\n";
		exit(1);
	}
}