#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>
using namespace std;

struct Unit
{
	int Hp;
	int Damage;
};

void main()
{
	srand(time(NULL));
	Unit player;
	cout << "set Player hp" << endl;
	cin >> player.Hp;
	cout << "set Player damage" << endl;
	cin >> player.Damage;
	cout << "set Monster hp" << endl;
	int MonsterHp;
	cin >> MonsterHp;
	cout << "set Monster damage" << endl;
	int MonsterDamage;
	cin >> MonsterDamage;

	vector<Unit> monsterManager;
	for (int i = 0; i < 100; i++)
	{
		Unit monster;
		monster.Hp = rand() % 10 + 10;
		monster.Damage = rand() % 10 + 1; 
		monsterManager.push_back(monster);
	}

	//while(monsterhp>0 playerhp>0)
	//monsterhp-=playerdamage
	//playerhp-=monsterdamage
	//monsterhp<0
	//break
	//playerhp<0
	//break
	
	int killCount = 0;
	for (int i = 0;;i++)
	{
		bool isBattleEnd = false;
		if (player.Hp > 0)
		{
			while (false == isBattleEnd)
			{
				cout << "player hits monster" << endl;
				monsterManager[i].Hp -= player.Damage;

				cout << "monster hits player" << endl;
				player.Hp -= monsterManager[i].Damage;

				if (monsterManager[i].Hp <= 0)
				{
					cout << "player win" << endl;
					isBattleEnd = true;
					killCount++;
				}
				if (player.Hp <= 0)
				{
					cout << "monster win" << endl;
					isBattleEnd = true;
				}
			}
		}
		cout << "player kill count" << killCount << endl;

	}
}