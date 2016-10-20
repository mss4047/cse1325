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
vector<Orders> ord;
/*void SAVE()
{
	ofstream tempfile;
	tempfile.open("store.txt");
	for (int i = 0; i < torsos.size(); i++)
	{
		tempfile << torsos[i]->name<<",";
		tempfile << torsos[i]->p_num << ",";
		tempfile << torsos[i]->type << ",";
		tempfile << torsos[i]->weight << ",";
		tempfile << torsos[i]->cost << ",";
		tempfile << torsos[i]->desc << ",";
		tempfile << torsos[i]->battery_compartment << ",";	
		tempfile << torsos[i]->arms << ",";
		tempfile << torsos[i]->bat << ",";
	}

	tempfile << endl;

	for (int i = 0; i < heads.size(); i++)
	{
		tempfile << heads[i]->name << ",";
		tempfile << heads[i]->p_num << ",";
		tempfile << heads[i]->type << ",";
		tempfile << heads[i]->weight << ",";
		tempfile << heads[i]->cost << ",";
		tempfile << heads[i]->desc << ",";
	}

	tempfile << endl;

	for (int i = 0; i < batteries.size(); i++)
	{
		tempfile << batteries[i]->name << ",";
		tempfile << batteries[i]->p_num << ",";
		tempfile << batteries[i]->type << ",";
		tempfile << batteries[i]->weight << ",";
		tempfile << batteries[i]->cost << ",";
		tempfile << batteries[i]->desc << ",";
		tempfile << batteries[i]->energy << ",";
		tempfile << batteries[i]->maxPower << ",";
	}

	tempfile << endl;

	for (int i = 0; i < arms.size(); i++)
	{
		tempfile << arms[i]->name << ",";
		tempfile << arms[i]->p_num << ",";
		tempfile << arms[i]->type << ",";
		tempfile << arms[i]->weight << ",";
		tempfile << arms[i]->cost << ",";
		tempfile << arms[i]->desc << ",";
		tempfile << arms[i]->power_con << ",";
	}

	tempfile << endl;

	for (int i = 0; i < locomotors.size(); i++)
	{
		tempfile << locomotors[i]->name << ",";
		tempfile << locomotors[i]->p_num << ",";
		tempfile << locomotors[i]->type << ",";
		tempfile << locomotors[i]->weight << ",";
		tempfile << locomotors[i]->cost << ",";
		tempfile << locomotors[i]->desc << ",";
		tempfile << locomotors[i]->max_speed << ",";
		tempfile << locomotors[i]->power_conloco << ",";
	}

	tempfile << endl;

	for (int i = 0; i < models.size(); i++)
	{
		tempfile << models[i].name;
		tempfile << models[i].modelNumber;
		tempfile << models[i].price;
		if (models[i].Torsosm.size() != 0)
		{

		}
	}


	tempfile.close();
}
*/
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
	Orders temp;
	temp.mod= models[n];
	cout << "Enter the order number: ";
	cin >> temp.orderNumber;

	cout << "Enter the order date(in the format of mm/dd/yyyy: ";
	cin.clear();
	cin.ignore();
	getline(cin, temp.date);

	cout << "Enter the customer name: ";
	getline(cin, temp.customer);

	cout << "Enter the sales associate name: ";
	getline(cin, temp.salesAss);

	cout << "Enter the status: ";
	getline(cin,temp.status);

	ord.push_back(temp);
	cout << "\nOrder placed!\nSubtotal: "<<temp.mod.price<<"\n";

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
			cout <<"Name: "<< models[n].Headsm[j]->name<<endl;
			cout <<"Part number: "<< models[n].Headsm[j]->p_num << endl;
			cout <<"Type: "<< models[n].Headsm[j]->type << endl;
			cout <<"Weight: "<< models[n].Headsm[j]->weight << endl;
			cout <<"Cost: "<< models[n].Headsm[j]->cost << endl;
			cout <<"Description: "<< models[n].Headsm[j]->desc << endl;
		}
	}

	if (models[n].Armsm.size() != 0)
	{
		for (int j = 0; j < models[n].Armsm.size(); j++)
		{
			cout <<"Name: "<< models[n].Armsm[j]->name << endl;
			cout << "Part number: " << models[n].Armsm[j]->p_num << endl;
			cout << "Type: " << models[n].Armsm[j]->type << endl;
			cout << "Weight: " << models[n].Armsm[j]->weight << endl;
			cout << "Cost: " << models[n].Armsm[j]->cost << endl;
			cout << "Description: " << models[n].Armsm[j]->desc << endl;
			cout << "Power consumption: " << models[n].Armsm[j]->power_con << endl;
		}
	}

	if (models[n].Batteriesm.size() != 0)
	{
		for (int j = 0; j < models[n].Batteriesm.size(); j++)
		{
			cout << "Name: " << models[n].Batteriesm[j]->name << endl;
			cout << "Part number: " << models[n].Batteriesm[j]->p_num << endl;
			cout << "Type: " << models[n].Batteriesm[j]->type << endl;
			cout << "Weight: " << models[n].Batteriesm[j]->weight << endl;
			cout << "Cost: " << models[n].Batteriesm[j]->cost << endl;
			cout << "Desc: " << models[n].Batteriesm[j]->desc << endl;
			cout << "Energy: " << models[n].Batteriesm[j]->energy << endl;
			cout << "Maximum power: " << models[n].Batteriesm[j]->maxPower << endl;
		}
	}

	if (models[n].Locomotorsm.size() != 0)
	{
		for (int j = 0; j < models[n].Locomotorsm.size(); j++)
		{
			cout << "Name: " << models[n].Locomotorsm[j]->name << endl;
			cout << "Part number: " << models[n].Locomotorsm[j]->p_num << endl;
			cout << "Type: " << models[n].Locomotorsm[j]->type << endl;
			cout << "Weight: " << models[n].Locomotorsm[j]->weight << endl;
			cout << "Cost: " << models[n].Locomotorsm[j]->cost << endl;
			cout << "Description: " << models[n].Locomotorsm[j]->desc << endl;
			cout << "Maximum speed: " << models[n].Locomotorsm[j]->max_speed << endl;
			cout << "Power consumption: " << models[n].Locomotorsm[j]->power_conloco << endl;
		}
	}
	
	if (models[n].Torsosm.size() != 0)
	{
		for (int j = 0; j < models[n].Headsm.size(); j++)
		{
			cout << "Name: " << models[n].Torsosm[j]->name << endl;
			cout << "Part number: " << models[n].Torsosm[j]->p_num << endl;
			cout << "Type: " << models[n].Torsosm[j]->type << endl;
			cout << "Weight:" << models[n].Torsosm[j]->weight << endl;
			cout << "Cost: " << models[n].Torsosm[j]->cost << endl;
			cout << "Description: " << models[n].Torsosm[j]->desc << endl;
			cout << "Number of battery compartments: " << models[n].Torsosm[j]->battery_compartments << endl;
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
		cout << "How many parts do you want to add?\n";
		int q;
		cin >> q;
		cout << "\nA list of the name and part number of the parts stored will be displayed. Enter [y] once you see the one you need or [n] to view the next part\n";
		
		int flag = 0;
		for (int j = 0; j < q; j++)
		{
			if (torsos.size() != 0)
			{
				for (unsigned int i = 0; i < torsos.size(); i++)
				{
					char let;
					cout << torsos[i]->name << endl;
					cout << torsos[i]->p_num << endl;
					cout << "\n[y/n]\n";
					cin >> let;
					if (let == 'y')
					{
						forge.Torsosm.push_back(torsos[i]);
						cout << "\nPart Added!\n";
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
				for (unsigned int i = 0; i < heads.size(); i++)
				{
					char let;
					cout << heads[i]->name << endl;
					cout << heads[i]->p_num << endl;
					cout << "\n[y/n]\n";
					cin >> let;
					if (let == 'y')
					{
						forge.Headsm.push_back(heads[i]);
						cout << "\nPart Added!\n";
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
				for (unsigned int i = 0; i < batteries.size(); i++)
				{
					char let;
					cout << batteries[i]->name << endl;
					cout << batteries[i]->p_num << endl;
					cout << "\n[y/n]\n";
					cin >> let;
					if (let == 'y')
					{
						forge.Batteriesm.push_back(batteries[i]);
						cout << "\nPart Added!\n";
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
				for (unsigned int i = 0; i < arms.size(); i++)
				{
					char let;
					cout << arms[i]->name << endl;
					cout << arms[i]->p_num << endl;
					cout << "\n[y/n]\n";
					cin >> let;
					if (let == 'y')
					{
						forge.Armsm.push_back(arms[i]);
						cout << "\nPart Added!\n";
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
				for (unsigned int i = 0; i < locomotors.size(); i++)
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
						cout << "\nPart Added!\n";
						break;
					}
					else
					{
						continue;
					}
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

		if(heads.size()==0 || arms.size()==0||locomotors.size()==0||batteries.size()==0)
		{
			cout << "\nError! Not enough parts stored. Please enter one or more of the following parts if you haven't already:\nHead\n\nArm\nLocomotor\nBattery\n";
			return;
		}
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
		cin >> newTorso->battery_compartments;

		cout << "How many arms do wish to add?\n";
		int a;
		cin >> a;
		for (int j = 0; j < a; j++)
		{
			cout << "\nChoose an arm: "<<endl;
			for (int i = 0; i < arms.size(); i++)
			{
				cout << "--------"<<endl;
				cout << "\t" << i<<endl;
				cout << "--------"<<endl;
				cout << "Name: " << arms[i]->name << endl;
				cout << "Part Number: " << arms[i]->p_num << endl;
				cout << "Type: " << arms[i]->type << endl;
				cout << "Weight: " << arms[i]->weight << endl;
				cout << "Cost: " << arms[i]->cost << endl;
				cout << "Description: " << arms[i]->desc << endl;
				cout << "Power Consumption: " << arms[i]->power_con << endl;
			}
			cout << "\nEnter the number of the arm you want to add\n";
			int c;
			cin >> c;
			newTorso->tArm[j].name = arms[c]->name;
			newTorso->tArm[j].p_num = arms[c]->p_num;
			newTorso->tArm[j].type = arms[c]->type;
			newTorso->tArm[j].weight = arms[c]->weight;
			newTorso->tArm[j].cost = arms[c]->cost;
			newTorso->tArm[j].desc = arms[c]->desc;
			newTorso->tArm[j].power_con = arms[c]->power_con;
		}

		cout << "How many batteries do you wish to add (cannot add more than 3 AND cannot add more than number of battery compartments)?";
		int b;
		cin >> b;
		if (b > newTorso->battery_compartments||b>3)
		{
			cout << "\nError! Cannot add that many batteries";
			return;
		}
		else
		{
			for (int j = 0; j < b; j++)
			{
				cout << "\nChoose a battery\n"<<endl;

				for (int i = 0; i < batteries.size(); i++)
				{
					cout << "--------\n";
					cout << "\t" << i<<endl;
					cout << "--------"<<endl;
					cout << "Name: " << batteries[i]->name << endl;
					cout << "Part number: " << batteries[i]->p_num << endl;
					cout << "Type: " << batteries[i]->type << endl;
					cout << "Weight: " << batteries[i]->weight << endl;
					cout << "Cost: " << batteries[i]->cost << endl;
					cout << "Descricption: " << batteries[i]->desc<< endl;
					cout << "Energy: " << batteries[i]->energy << endl;
					cout << "Maximum power: " << batteries[i]->maxPower<< endl;
				}
				cout << "\nEnter the number of the battery you want to add\n";
				int c;
				cin >> c;
				newTorso->tArm[j].name = batteries[c]->name;
				newTorso->tBattery[j].p_num = batteries[c]->p_num;
				newTorso->tBattery[j].type = batteries[c]->type;
				newTorso->tBattery[j].weight = batteries[c]->weight;
				newTorso->tBattery[j].cost = batteries[c]->cost;
				newTorso->tBattery[j].desc = batteries[c]->desc;
				newTorso->tBattery[j].desc = batteries[c]->desc;
				newTorso->tBattery[j].desc = batteries[c]->desc;
				newTorso->tBattery[j].energy= batteries[c]->energy;
				newTorso->tBattery[j].maxPower = batteries[c]->maxPower;
			}
		}

		cout << "\nChoose the head you want to add\n";
		for (int i = 0; i < heads.size(); i++)
		{
			cout << "-------" << endl;
			cout << "---" << i << "---" << endl;
			cout << "-------";
			cout << "Name: " << heads[i]->name << endl;
			cout << "Part number: " << heads[i]->p_num << endl;
			cout << "Type: " << heads[i]->type << endl;
			cout << "Weight: " << heads[i]->weight << endl;
			cout << "Cost: " << heads[i]->cost << endl;
			cout << "Descricption: " << heads[i]->desc << endl<<endl;
		}

		cout << "\nEnter the number of the head you want to add: ";
		int z;
		cin >> z;
		newTorso->tHead.name = heads[z]->name;
		newTorso->tHead.p_num= heads[z]->p_num;
		newTorso->tHead.type = heads[z]->type;
		newTorso->tHead.weight = heads[z]->weight;
		newTorso->tHead.cost = heads[z]->cost;
		newTorso->tHead.desc = heads[z]->desc;

		cout << "\nChoose the locomotor you wish to add\n";
		for (int i = 0; i < locomotors.size(); i++)
		{
			cout << "-------" << endl;
			cout << "---" << i << "---" << endl;
			cout << "-------";
			cout << "Name: " << locomotors[i]->name << endl;
			cout << "Part number: " << locomotors[i]->p_num << endl;
			cout << "Type: " << locomotors[i]->type << endl;
			cout << "Weight: " << locomotors[i]->weight << endl;
			cout << "Cost: " << locomotors[i]->cost << endl;
			cout << "Descricption: " << locomotors[i]->desc << endl << endl;
			cout << "Maximum speed: " << locomotors[i]->max_speed << endl << endl;
			cout << "Power consumption: " << locomotors[i]->power_conloco << endl << endl;
		}

		cout << "\nEnter the number of the locomotor you want to add: ";
		cin >> z;
		newTorso->tLoco.name = locomotors[z]->name;
		newTorso->tLoco.p_num = locomotors[z]->p_num;
		newTorso->tLoco.type = locomotors[z]->type;
		newTorso->tLoco.weight = locomotors[z]->weight;
		newTorso->tLoco.cost = locomotors[z]->cost;
		newTorso->tLoco.desc = locomotors[z]->desc;
		newTorso->tLoco.power_conloco = locomotors[z]->power_conloco;
		newTorso->tLoco.max_speed = locomotors[z]->max_speed;

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
			//SAVE();
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