#include <iostream>

using namespace std;

class Unit
{
private:
	int _hp;
	int _defense;
	int _shield;
	int _damage;

public:
	void OnDamaged(int damage)
	{

	}

	void Heal()
	{
		this->_hp += 10;
	}
};

struct UnitData
{
public:
	int _hp;
	int _damage;

};

void main()
{
	//class ����
	//class == struct
	//���� ����.

	Unit unit;
	//unit._hp += 10;


	//private
	//  -> �ڱ��ڽŸ� ��� ���� (�ܺ� ���x)
	//public
	//  -> ������ ��� ���� (�ܺ� ���o)


	//private main������ ���Ұ���
	//public main������ ��밡��

	//private�� �����ϴ°� �����žƴѰ�?

	// Ŭ����
	//  ���İ�Ƽ �ڵ�
	//   --> AŬ�������� BŬ������ ȣ���ϴµ�
	//			BŬ�������� CŬ������ ȣ���ϰ�
	//			CŬ�������� AŬ������ ȣ���ؿ�

	//	A => B => C
	//	ȣ���ϴ� ������ �ѹ������θ� ȣ���ϴ°� �̻����� ����
	//  

	//������ ���İ�Ƽ �ڵ带 ���� ¥����.

	//���� (�ٸ��� ��������� class�� struct�� �ֱ⶧����)
	// Class�� ������ private �Լ��� public
	// struct�� Data�� �ǹ̸� ���� ���븸 struct��

	// class => Heap����  (�����Ҵ�)
	// struct => Stack����  (�����Ҵ�)
	// struct => ��ȹ�ڵ��� ����Ҹ��� ���������͸� ��� ��

}