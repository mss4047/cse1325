#include "control.h"
#include "parts.h"
#include "robotmodel.h"

using namespace std;
const string types[5] = { "torso","head","arm","locomotor","battery" };

vector<model> models;
vector<robo*> repo;
vector<model> orders;

void placeorder()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		cout << "(" << i + 1 << "). ";
		cout << "Name: " << models[i].name << "Model number: " << models[i].modelNumber << "Price: " << models[i].price;
	}

	int n;
	cout << "Enter the number of the model you wish to order: ";
	cin >> n;
	model temp = models [n];
	cout << "How many do you want to order? ";
	int a;
	cin >> a;
	temp.quantity = a;
	orders.push_back(temp);
	int order_price = (models[n].price)*temp.quantity;
	cout << "Name: " << temp.name<<endl << "Model number: " <<temp.modelNumber<<endl<< "Price: " << temp.price<<endl<<"Quantity: "<<temp.quantity<<endl;
	cout << "Total price: "<<order_price<<endl;
}
void catalog()
{
	for (int i = 0; i < models.size(); i++)
	{
		cout <<"("<<i+1<<"). ";
		cout << "Name: " << models[i].name<<"Model number: "<<models[i].modelNumber<<"Price: "<<models[i].price;
	}

	int n;
	cout << "Enter the number of the model who's parts you wish to see: ";
	vector<robo*> newvec;
	cin >> n;
	for (int i = 0; i < repo.size(); i++)
	{
		newvec.push_back(repo[i]);
	}
		cout << "Parts:\n";
		cout << "Name: " << newvec[n-1]->name;
		cout << "\nPart number: " << newvec[n-1]->p_num;
		cout << "\nType: " << newvec[n-1]->type;
		cout << "\nWeight: " << newvec[n-1]->weight;
		cout << "\nCost: " << newvec[n-1]->cost;
		cout << "\nDesciption: " << newvec[n-1]->desc;
	}
void order()
{
	cout << "What would you like to do?\n(1.) View catalog\n(2.) Place an order\n(3.) Return to previous menu\n";
	int n;
	cin>> n;
	if (n == 3)
	{
		return;
	}
	else if (n == 1)
	{
		catalog();
	}
	else if (n == 2)
	{
		placeorder();
	}

}
//function for printing to file under construction!!!
/*void printtofile()
{
	std::ofstream output_file("./store.txt");
	ostream_iterator<string> output_iterator(output_file, "\n");
	copy(repo.begin(), repo.end(), output_iterator);
}*/
void robotmodel()
{
	model forge;

	std::cout << "Select the parts you would like to create a model with. If no parts have been stored, you will be returned to the main menu.\n";
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
	cout << "------------\n(1.) Create Robot Parts\n(2.) Create Robot Model\n(3.) Return to main menu\n ";
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
		else if (a == 3)
		{
			return;
		}
}
void control()
	{
		int n;
		cin >> n;
		
		if(n == 1)
		{
			cout << "(1.) Order\n(2.) Customer*\n(3.) Sales Associate*\n(4.) Robot Component\n(5.) Back\n";
			
				int inp;
				cin >> inp;
				
				if (inp == 4)
				{
					create();
					return;
				}
				else if (inp == 1)
				{
					order();
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
				else if (inp == 5)
				{
					return;
				}
				else if(inp == 6)
				{
					//printtofile();
					return;
				}
		}
		else if (n == 4)
		{
			cout << "Name: Muhammad Sohaib Siddiqui\n";
			cout << "Student ID: 1001194047\n";
			cout << "Class: CSE 1325-003\n";
			cout << "Professor: George Rice\n";
			cout << "Homework 5\n";
			return;
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
		cout << "What would you like to to do? (an * means the option is not available)\n";
		cout << "(1). Create\n(2). Report*\n(3). Quit\n(4.) View student information\n";
		control();
	}