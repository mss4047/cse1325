#ifndef ROBOTMODEL_H
#define ROBOT MODEL_H

#include <string>
#include <iostream>
#include <vector>
#include "parts.h"

using namespace std;

class model
{
public:

	string name;
	int modelNumber;
	double price;
	vector<robo*> parts;
};

#endif
