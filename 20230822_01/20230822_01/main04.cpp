#include <iostream>
using namespace std;

struct  Unit
{
	float Hp;
	float Damage;
};

void main()
{
	// homework
	// computer rand 4 comb no duplicates
	// repeat
	// if same place strike same num ball
	// 4 strike end

	// struct
	// data structure
	// user defined
	
	// standard int, float, bool , char

	// user defined struct, enum, class

	float Hp;
	float Damage;
	Unit monster;

	monster.Hp = 100;
	monster.Damage = 23;

	Unit slime = {100,10};
	cout << "slime Hp : " << slime.Hp << endl;
	cout << "slime Damage : " << slime.Damage << endl;
	Unit hero = { 200,7 };
	cout << "hero Hp : " << hero.Hp << endl;
	cout << "hero Damage : " << hero.Damage << endl;

	while (hero.Hp > 0 && slime.Hp > 0)
	{
		hero.Hp=hero.Hp - slime.Damage;
		cout << "slime Hp : " << slime.Hp << endl;
		cout << "slime Damage : " << slime.Damage << endl;
		cout << "hero Hp : " << hero.Hp << endl;
		cout << "hero Damage : " << hero.Damage << endl;
		if (hero.Hp <= 0 || slime.Hp <= 0)
		{
			break;
		}
		slime.Hp=slime.Hp - hero.Damage;
		cout << "slime Hp : " << slime.Hp << endl;
		cout << "slime Damage : " << slime.Damage << endl;
		cout << "hero Hp : " << hero.Hp << endl;
		cout << "hero Damage : " << hero.Damage << endl;
	}

}