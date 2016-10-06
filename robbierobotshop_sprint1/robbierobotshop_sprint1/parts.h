#ifndef PARTS_H
#define PARTS_H
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class robo
{
public:
	string name;
	int p_num;
	string type;
	double weight;
	double cost;
	string desc;
	robo();
	void setter(string name, int p_num, string type, double weight, double cost, string desc);
	//virtual void setVal() = 0;

};

class Locomotor : public robo
{
	Locomotor();
	int max_speed;
};

class Arm : public robo
{
	Arm();
	void setArm(int Power_Con);
	int power_con;
};

class Battery : public robo
{
	Battery();
	void setBattery(double Energy, double power);
	double energy;
	double maxPower;
};

class Head : public robo
{
	Head();
};

class Torso : public robo
{
	Torso();
	int battery;
	vector<Arm> arms;
	vector<Battery> bat;
};
#endif

