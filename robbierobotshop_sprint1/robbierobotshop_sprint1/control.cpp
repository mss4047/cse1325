#include "control.h"
#include "parts.h"

const string types[5] = { "torso","head","arm","locomotor","battery" };

void createnewpart()
{
	cout << "Choose a part type (input a number only):\n(1.) Torso\n(2.) Head\n(3.) Arm\n(4.) Locomotor\n(5.) Battery\n";
	int choice;
	cin >> choice;

	vector<robo*> repo;

	if (choice == 1)
	{
		Torso* newTorso = new Torso;
		newTorso->type = types[choice - 1];
		cout << "Input the name of the component: ";
		cin.clear();
		cin.ignore();
		getline(cin, newTorso->name);

		cout << "Input the part number: ";
		cin >> newTorso->p_num;


		cout << "Input the weight: ";
		cin >> newTorso->weight;

		cout << "Input the cost: ";
		cin >> newTorso->cost;

		cout << "Enter a brief description: ";
		cin.ignore();
		cin.clear();
		getline(cin, newTorso->desc);

		cout << "Enter number of battery compartment: ";
		cin >> newTorso->battery_compartment;

		repo.push_back(newTorso);

		cout << "Added\n";
	}
	else if (choice == 2)
	{
		Head* newHead = new Head;
		newHead->type = types[choice - 1];
		cout << "Input the name of the component: ";
		cin.clear();
		cin.ignore();
		getline(cin, newHead->name);

		cout << "Input the part number: ";
		cin >> newHead->p_num;


		cout << "Input the weight: ";
		cin >> newHead->weight;

		cout << "Input the cost: ";
		cin >> newHead->cost;

		cout << "Enter a brief description: ";
		cin.ignore();
		cin.clear();
		getline(cin, newHead->desc);

		repo.push_back(newHead);

		cout << "Added\n";
	}
	else if (choice == 3)
	{
		Arm* newArm = new Arm;
		newArm->type = types[choice - 1];
		cout << "Input the name of the component: ";
		cin.clear();
		cin.ignore();
		getline(cin, newArm->name);

		cout << "Input the part number: ";
		cin >> newArm->p_num;


		cout << "Input the weight: ";
		cin >> newArm->weight;

		cout << "Input the cost: ";
		cin >> newArm->cost;

		cout << "Enter a brief description: ";
		cin.ignore();
		cin.clear();
		getline(cin, newArm->desc);

		repo.push_back(newArm);

		cout << "Enter a power consumption: ";
		cin >> newArm->power_con;

		cout << "Added\n";
	}
	else if (choice == 4)
	{
		Locomotor* newLocomotor = new Locomotor;
		newLocomotor->type = types[choice - 1];
		cout << "Input the name of the component: ";
		cin.clear();
		cin.ignore();
		getline(cin, newLocomotor->name);

		cout << "Input the part number: ";
		cin >> newLocomotor->p_num;


		cout << "Input the weight: ";
		cin >> newLocomotor->weight;

		cout << "Input the cost: ";
		cin >> newLocomotor->cost;

		cout << "Enter a brief description: ";
		cin.ignore();
		cin.clear();
		getline(cin, newLocomotor->desc);

		repo.push_back(newLocomotor);

		cout << "Enter a power consumption: ";
		cin >> newLocomotor->power_conloco;

		cout << "Enter the max speed: ";
		cin >> newLocomotor->max_speed;

		cout << "Added\n";
	}
	else if (choice == 5)
	{
		Battery* newBattery = new Battery;
		newBattery->type = types[choice - 1];
		cout << "Input the name of the component: ";
		cin.clear();
		cin.ignore();
		getline(cin, newBattery->name);

		cout << "Input the part number: ";
		cin >> newBattery->p_num;


		cout << "Input the weight: ";
		cin >> newBattery->weight;

		cout << "Input the cost: ";
		cin >> newBattery->cost;

		cout << "Enter a brief description: ";
		cin.ignore();
		cin.clear();
		getline(cin, newBattery->desc);

		cout << "Input the energy: ";
		cin >> newBattery->energy;

		cout << "Input the maxPower: ";
		cin >> newBattery->maxPower;

		repo.push_back(newBattery);

		cout << "Added\n";
	}
}





void create()
{
	cout << "------------\n(1.) Create Robot Parts\n(2.) Robot Model\n(3.) Order\n(4.)Return to main menu\n ";
	int a;
	cin >> a;
	while (a != 4) {

	
	if (a == 1)
	{
		createnewpart();
	}

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