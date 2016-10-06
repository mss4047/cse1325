#include "parts.h"

void Torso::mysetter(string newname, int p_num, string type, double weight, double cost, string desc)
{}
//void robo::setter(string Name, int P_num, string Type, double Weight, double Cost, string Desc) {
	//name = Name; p_num = P_num; type = Type; weight = Weight; cost = Cost; desc = Desc;
//}

void Battery::mysetter(string name, int p_num, string type, double weight, double cost, string desc)
{
}

void Battery::setBattery(double Energy, double power)
{
	energy = Energy; maxPower = power;
}

void Arm::mysetter(string name, int p_num, string type, double weight, double cost, string desc)
{
}

void Arm::setArm(int Power_Con) { power_con = Power_Con; }

/*Head::Head() { type = "Head"; };
Torso::Torso() { type = "Torso"; };
Arm::Arm() { type = "Arm"; };
Locomotor::Locomotor() { type = "Locomotor"; };
Battery::Battery() { type = "Battery"; };*/

void Head::mysetter(string name, int p_num, string type, double weight, double cost, string desc)
{
}

void Locomotor::mysetter(string name, int p_num, string type, double weight, double cost, string desc)
{
}
