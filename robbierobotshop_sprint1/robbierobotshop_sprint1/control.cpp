//includes
#include "control.h"
#include "parts.h"
#include "robotmodel.h"

//using namespace std;

//globals

const string types[5] = { "torso","head","arm","locomotor","battery" };

vector<model> models;
vector<model> orders;
vector<Torso*> torsos;
vector<Head*> heads;
vector<Battery*> batteries;
vector <Arm*> arms;
vector<Locomotor*> locomotors;

void SAVE()
{
	ofstream tempfile;
	tempfile.open("store.txt");
	for (int i = 0; i < models.size(); i++)
	{
		model newtemp = models[i];
		if (newtemp.parts[newtemp.parts.size()-1]->type == "torso")
		{
				tempfile << newtemp.name << ",";
				tempfile << newtemp.modelNumber << ",";
				tempfile << newtemp.price << ",";
				tempfile << newtemp.quantity << ",";
				tempfile << newtemp.parts[0]->name << ",";
				tempfile << newtemp.parts[0]->p_num << ",";
				tempfile << newtemp.parts[0]->type << ",";
				tempfile << newtemp.parts[0]->weight << ",";
				tempfile << newtemp.parts[0]->cost << ",";
				tempfile << newtemp.parts[0]->desc << ",";
				tempfile << repo[i]->battery_compartment;
		}
	}
	
	tempfile.close();
}
void placeorder()
{
	for (unsigned int i = 0; i < models.size(); i++)
	{
		cout << "(" << i + 1 << "). ";
		cout << "Name: " << models[i].name << " Model number: " << models[i].modelNumber << " Price: " << models[i].price<<endl;
	}

	int n;
	cout << "Enter the number of the model you wish to order: ";
	cin >> n;
	n -= 1;
	model temp = models [n];
	cout << "How many do you want to order? ";
	int a;
	cin >> a;
	temp.quantity = a;
	orders.push_back(temp);
	int order_price = (models[n].price)*temp.quantity;
	cout << "Name: " << temp.name<<endl << "Model number: " <<temp.modelNumber<<endl<< "Price: " << temp.price<<endl<<"Quantity: "<<temp.quantity<<endl;
	cout << "Total price: "<<order_price<<endl;
	cout << "Order placed!\n";
}
void catalog()
{
	for (int i = 0; i < models.size(); i++)
	{
		cout <<"("<<i+1<<"). ";
		cout << "Name: " << models[i].name<<"Model number: "<<models[i].modelNumber<<"Price: "<<models[i].price<<endl;
	}

	int n;
	cout << "Enter the number of the model who's parts you wish to see: ";
	cin >> n;
	n -= 1;
	models[n];
	if (models[n].Headsm.size() != 0)
	{
		for (int j = 0; j < models[n].Headsm.size(); j++)
		{
			cout << models[n].Headsm[j]->name<<endl;
			cout << models[n].Headsm[j]->p_num << endl;
			cout << models[n].Headsm[j]->type << endl;
			cout << models[n].Headsm[j]->weight << endl;
			cout << models[n].Headsm[j]->cost << endl;
			cout << models[n].Headsm[j]->desc << endl;
		}
	}

	if (models[n].Armsm.size() != 0)
	{
		for (int j = 0; j < models[n].Armsm.size(); j++)
		{
			cout << models[n].Armsm[j]->name << endl;
			cout << models[n].Armsm[j]->p_num << endl;
			cout << models[n].Armsm[j]->type << endl;
			cout << models[n].Armsm[j]->weight << endl;
			cout << models[n].Armsm[j]->cost << endl;
			cout << models[n].Armsm[j]->desc << endl;
			cout << models[n].Armsm[j]->power_con << endl;
		}
	}

	if (models[n].Batteriesm.size() != 0)
	{
		for (int j = 0; j < models[n].Batteriesm.size(); j++)
		{
			cout << models[n].Batteriesm[j]->name << endl;
			cout << models[n].Batteriesm[j]->p_num << endl;
			cout << models[n].Batteriesm[j]->type << endl;
			cout << models[n].Batteriesm[j]->weight << endl;
			cout << models[n].Batteriesm[j]->cost << endl;
			cout << models[n].Batteriesm[j]->desc << endl;
			cout << models[n].Batteriesm[j]->energy << endl;
			cout << models[n].Batteriesm[j]->maxPower << endl;
		}
	}

	if (models[n].Locomotorsm.size() != 0)
	{
		for (int j = 0; j < models[n].Locomotorsm.size(); j++)
		{
			cout << models[n].Locomotorsm[j]->name << endl;
			cout << models[n].Locomotorsm[j]->p_num << endl;
			cout << models[n].Locomotorsm[j]->type << endl;
			cout << models[n].Locomotorsm[j]->weight << endl;
			cout << models[n].Locomotorsm[j]->cost << endl;
			cout << models[n].Locomotorsm[j]->desc << endl;
			cout << models[n].Locomotorsm[j]->max_speed << endl;
			cout << models[n].Locomotorsm[j]->power_conloco << endl;
		}
	}
	
	if (models[n].Torsosm.size() != 0)
	{
		for (int j = 0; j < models[n].Headsm.size(); j++)
		{
			cout << models[n].Torsosm[j]->name << endl;
			cout << models[n].Torsosm[j]->p_num << endl;
			cout << models[n].Torsosm[j]->type << endl;
			cout << models[n].Torsosm[j]->weight << endl;
			cout << models[n].Torsosm[j]->cost << endl;
			cout << models[n].Torsosm[j]->desc << endl;
			cout << models[n].Torsosm[j]->bat << endl;
			cout << models[n].Torsosm[j]->battery_compartment << endl;
			cout << models[n].Torsosm[j]->arms << endl;
		}
	}

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

	cout << "Select the parts you would like to create a model with. If no parts have been stored, you will be returned to the main menu.\n";
	if (heads.size() == 0 && batteries.size() == 0 && arms.size() == 0 && locomotors.size() == 0 && torsos.size() == 0)
	{
		cout << "\nNo parts found!\n";
		return;
	}
	else
	{
		cout << "\nA list of the name and part number of the parts stored will be displayed. Enter [y] once you see the one you need or [n] to view the next part\n";
		
		int flag = 0;
		
		if (torsos.size() != 0)
		{
			for (unsigned int i = 0; i<torsos.size(); i++)
			{
				char let;
				cout << torsos[i]->name << endl;
				cout << torsos[i]->p_num << endl;
				cout << "\n[y/n]\n";
				cin >> let;
				if (let == 'y')
				{
					forge.Torsosm.push_back(torsos[i]);
					flag++;
					break;
				}
				else
				{
					continue;
				}
			}
		}

		if (heads.size() != 0)
		{
			for (unsigned int i = 0; i<heads.size(); i++)
			{
				char let;
				cout << heads[i]->name << endl;
				cout << heads[i]->p_num << endl;
				cout << "\n[y/n]\n";
				cin >> let;
				if (let == 'y')
				{ 
					forge.Headsm.push_back(heads[i]);
					flag++;
					break;
				}
				else
				{
					continue;
				}
			}
		}

		if (batteries.size() != 0)
		{
			for (unsigned int i = 0; i<batteries.size(); i++)
			{
				char let;
				cout << batteries[i]->name << endl;
				cout << batteries[i]->p_num << endl;
				cout << "\n[y/n]\n";
				cin >> let;
				if (let == 'y')
				{
					forge.Batteriesm.push_back(batteries[i]);
					flag++;
					break;
				}
				else
				{
					continue;
				}
			}
		}

		if (arms.size() != 0)
		{
			for (unsigned int i = 0; i<arms.size(); i++)
			{
				char let;
				cout << arms[i]->name << endl;
				cout << arms[i]->p_num << endl;
				cout << "\n[y/n]\n";
				cin >> let;
				if (let == 'y')
				{
					forge.Armsm.push_back(arms[i]);
					flag++;
					break;
				}
				else
				{
					continue;
				}
			}
		}

		if (locomotors.size() != 0)
		{
			for (unsigned int i = 0; i<locomotors.size(); i++)
			{
				char let;
				cout << locomotors[i]->name << endl;
				cout << locomotors[i]->p_num << endl;
				cout << "\n[y/n]\n";
				cin >> let;
				if (let == 'y')
				{
					forge.Locomotorsm.push_back(locomotors[i]);
					flag++;
					break;
				}
				else
				{
					continue;
				}
			}
		}

		if(flag==0)
		{
			cout << "\nNo more parts to display! You will now be returned to the previous menu...\n";
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

		cout << "Enter number of arms: ";
		cin >> newTorso->arms;

		cout << "Enter number of batteries: ";
		cin >> newTorso->bat;

		torsos.push_back(newTorso);

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

		heads.push_back(newHead);

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

		cout << "Enter the power consumption: ";
		cin >> newArm->power_con;
		
		arms.push_back(newArm);
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

		cout << "Enter the power consumption: ";
		cin >> newLocomotor->power_conloco;

		cout << "Enter the max speed: ";
		cin >> newLocomotor->max_speed;
		locomotors.push_back(newLocomotor);
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

		batteries.push_back(newBattery);

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
			cout << "(1.) Order\n(2.) Customer*\n(3.) Sales Associate*\n(4.) Create robot model or component\n(5.) Back\n";
			
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
			cout << "\n\nSaving...\n\n";
			SAVE();
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