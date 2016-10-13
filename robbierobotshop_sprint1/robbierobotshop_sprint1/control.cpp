#include "control.h"
#include "parts.h"
#include "robotmodel.h"

const string types[5] = { "torso","head","arm","locomotor","battery" };
vector<model> models;
vector<robo*> repo;
void robotmodel()
{
	model forge;

	cout << "Select the parts you would like to create a model with. If no parts have been stored, you will be returned to the main menu.\n";
	if (repo.size() == 0)
	{
		cout << "No parts found!";
		return;
	}
	else
	{
		int flag = 0;
		cout << "A list of the name and part number of the parts stored will be displayed. Enter [y] once you see the one you need\n";
		for (unsigned int i = 0; i<repo.size(); i++)
		{
			char let;
			cout << repo[i]->name<<endl;
			cout << repo[i]->p_num<<endl;
			cout << "\n[y/n]\n";
			cin >> let;
			if (let == 'y')
			{
				forge.parts.push_back(repo[i]);
				flag++;
				break;
			}
			else
			{
				continue;
			}
		}
		if(flag==0){
			return;
		}
	cout << "Input the follolwing information of the robot model\n";
	
	cout << "Name: ";
	cin.ignore();
	cin.clear();
	getline(cin, forge.name);
	
	cout << "Model number: ";
	cin >> forge.modelNumber;
	
	cout << "Price: ";
	cin >> forge.price;
	
	models.push_back(forge);

	cout << "Robot Model Added Succesfully!\n";
	}

}
void createnewpart()
{
	cout << "Choose a part type (input a number only):\n(1.) Torso\n(2.) Head\n(3.) Arm\n(4.) Locomotor\n(5.) Battery\n(6.) Return to main menu\n";
	int choice;
	cin >> choice;

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
	else if (choice == 6)
	{
		return;
	}
}

void create()
{
	cout << "------------\n(1.) Create Robot Parts\n(2.) Robot Model\n(3.) Order\n(4.) Return to main menu\n ";
	int a;
	cin >> a;

		if (a == 1)
		{
			createnewpart();
		}
		else if (a == 2)
		{
			robotmodel();
		}

		else if (a == 4)
		{
			return;
		}
}

	void control()
	{
		int n;
		cin >> n;
		
		if (n == 1)
		{
			cout << "(1.) Order\n(2.) Customer\n(3.) Sales Associate\n(4.) Robot Model\n(5.) Robot Component\n(6.) Back\n";
			
				int inp;
				cin >> inp;
				
				if (inp == 5)
				{
					create();
				}
				else if (inp == 1)
				{
					return;
				}
				else if (inp == 2)
				{
					return;
				}
				else if (inp == 3)
				{
					return;
				}
				else if (inp == 4)
				{
					return;
				}
				else if (inp == 6)
				{
					return;
				}
		}
			else if (n == 3)
			{
				cout << "\n\nGoodbye!\n\n";
				exit(1);

			}
		
		
	}

	void menu()
	{
		cout << "Welcome to the Robbie Robot Shop!\n";
		cout << "What would you like to to do?\n";
		cout << "(1). Create\n(2). Report\n(3). Quit\n ";
		control();
	}