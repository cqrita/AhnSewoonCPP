#include<iostream>
#include <vector>
using namespace std;
//inheritance
//polymorphism

class Unit
{
protected:
	int _hp;
	float _x, _y;
public:
	virtual void Init() abstract;
};
class Inventory
{

};
class Archer :public Unit
{
private:
	float _attackRange;
	int _damage;
	Inventory* inventory;
public:
	void Init() override {}
};
class Supporter :public Unit
{
private:
	float _attackRange;
	Inventory* inventory;
public:
	void Init() override {}
};
void main()
{
	Archer* archer = new Archer();
	Unit* archer1 = new Archer();
	Unit* supporter = new Supporter();
	vector<Unit*> units;
	units.push_back(archer1);
	units.push_back(supporter);
	for (int i = 0; i < units.size(); i++)
	{
		units[i]->Init();
	}

}