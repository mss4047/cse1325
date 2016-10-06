#include "parts.h"

robo::robo() {}

void robo::setter(string Name, int P_num, string Type, double Weight, double Cost, string Desc) {
	name = Name; p_num = P_num; type = Type; weight = Weight; cost = Cost; desc = Desc;
}

void Battery::setBattery(double Energy, double power)
{
	energy = Energy; maxPower = power;
}

void Arm::setArm(int Power_Con) { power_con = Power_Con; }

Head::Head() { type = "Head"; };
Torso::Torso() { type = "Torso"; };
Arm::Arm() { type = "Arm"; };
Locomotor::Locomotor() { type = "Locomotor"; };
Battery::Battery() { type = "Battery"; };