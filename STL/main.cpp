#include <vector>
#include <array>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

int main()
{
	using namespace std;
	/*
	vector
	C++ ǥ�� ���̺귯�� ���� Ŭ������ ������ �����̳ʿ� ���� Ŭ���� ���ø��Դϴ�.
	���ʹ� ������ ������ ��Ҹ� ���� �迭�� �����ϰ� ��� ��ҿ� ���� ���� ���� �׼����� ����մϴ�. 
	���� �׼��� ������ �����̾��� ��� ���ʹ� �������� ���� �⺻ �����̳��Դϴ�.
	*/
	vector<int> vec;
	int a = 1;
	vec.push_back(a);
	vec.emplace_back(2);
	vector<int> vec1 = {1,2,3,4};
	for (int i : vec1)
	{
		cout << i << endl;
	}
	vec1.erase(vec1.begin());
	cout << endl;
	for (int i : vec1)
	{
		cout << i << endl;
	}
	cout << endl;
	/*
	array
	���̰� N�� Ty ������ ��� �������� �����ϴ� ��ü�� �����մϴ�. 
	�������� array<Ty, N> ��ü�� ���Ե� Ty�� �迭�� ����˴ϴ�.
	*/
	array<int, 4> arr;
	cout << arr.size() << endl;
	cout << endl;
	for (size_t i=0;i<arr.size();i++)
	{
		arr[i] = i;
	}
	for (int i : arr)
	{
		cout << i << endl;
	}
	cout << endl;
	array<int, 4> arr1 = {1,2,3,4};
	for (int i : arr1)
	{
		cout << i << endl;
	}
	cout << endl;
	/*
	map
	�� ��Ұ� ������ ���� ���� Ű�� ���� �ִ� ���� �÷��ǿ��� �������� ����� �˻��� ���˴ϴ�. 
	Ű ���� �����ϸ� �����͸� �ڵ����� �����ϴ� �� ���˴ϴ�.
	map�� �ִ� ����� ���� ���� ������ �� �ֽ��ϴ�. Ű ���� ����̸� ������ �� �����ϴ�. 
	���, ���� ��ҿ� ���õ� Ű ���� �����Ǿ�� �ϸ� �� ��ҿ� ���� �� Ű ���� ���ԵǾ�� �մϴ�.
	*/
	map<char, int> myMap;
	myMap['a'] = 2;
	myMap.insert(make_pair('b', 1));
	cout << myMap['a'] << endl;
	cout << myMap['b'] << endl;
	for (pair<char, int> p : myMap)
	{
		cout << p.first <<' '<<p.second<< endl;
	}
	myMap.erase(myMap.find('a'));
	cout << endl;
	for (pair<char, int> p : myMap)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	cout << endl;
	/*
	multimap
	C++ ǥ�� ���̺귯�� multimap Ŭ������ �� ��Ұ� ������ ���� ���� Ű�� ��� �����ϴ� ���� �÷��ǿ��� �����͸� �����ϰ� �˻��ϴ� �� ���˴ϴ�. 
	Ű ���� ������ �ʿ䰡 ������ �����͸� �ڵ����� �����ϴ� �� ���˴ϴ�. 
	multimap ����� ���� ������ Ű ���� �����ϰ� ���������� ������ �� �ֽ��ϴ�. 
	���, ���� ��ҿ� ���õ� Ű ���� �����ϰ� �� ��ҿ� ����� �� Ű ���� �����ؾ� �մϴ�.
	*/
	multimap<char, int> myMultiMap;
	myMultiMap.insert(make_pair('a', 4));

	myMultiMap.insert(make_pair('a', 2));
	myMultiMap.insert(make_pair('a', 3));
	myMultiMap.insert(make_pair('b', 1));
	for (multimap<char, int>::iterator iter = myMultiMap.lower_bound('a'); iter != myMultiMap.upper_bound('a'); iter++)
	{
		cout << iter->second << endl;
	}
	cout << endl;
	for (pair<char, int> p : myMultiMap)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	cout << endl;
	myMultiMap.erase(myMultiMap.lower_bound('a'));
	for (pair<char, int> p : myMultiMap)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	cout << endl;
	/*
	set
	C++ ǥ�� ���̺귯�� �����̳� Ŭ���� set �� �÷��ǿ��� �����͸� �����ϰ� �˻��ϴ� �� ���˴ϴ�. 
	����� set ���� �����ϸ� �����Ͱ� �ڵ����� ���ĵǴ� Ű ������ ���˴ϴ�. 
	����� set ���� ���� ������� ���� �� �ֽ��ϴ�. ���, ���� ���� �����ϰ� �� ���� ��Ҹ� �����ؾ� �մϴ�.
	*/
	set<int> mySet;
	mySet.insert(1);
	set<int> mySet1 = { 0,1,2,3,4 };
	set<int>::iterator iter= mySet1.find(2);
	cout << *iter<<endl;
	cout << endl;
	for (iter = mySet1.begin(); iter != mySet1.end(); iter++)
	{
		cout << *iter << endl;
	}
	mySet1.erase(mySet1.find(3));
	cout << endl;
	for (iter = mySet1.begin(); iter != mySet1.end(); iter++)
	{
		cout << *iter << endl;
	}
	/*
	multiset
	C++ ǥ�� ���̺귯�� multiset Ŭ������ ���Ե� ��Ұ��� ������ �ʿ䰡 ���� �����Ͱ� �ڵ� ���ĵǴ� ������ Ű ������ ���� �÷����� �����͸� ���� �� �˻��ϴ� �� ���˴ϴ�. 
	��� multiset �� Ű ���� ���� ������� ���� �� �ֽ��ϴ�. 
	���, ���� ���� �����ϰ� �� ���� ��Ҹ� �����ؾ� �մϴ�.
	*/
	multiset<int> myMultiSet;
	myMultiSet.insert(1);
	multiset<int> myMultiSet1 = { 0,1,1,2,3,4 };
	multiset<int>::iterator iter1 = myMultiSet1.find(2);
	cout << *iter1 << endl;
	cout << endl;
	for (iter1 = myMultiSet1.begin(); iter1 != myMultiSet1.end(); iter1++)
	{
		cout << *iter1 << endl;
	}
	cout << endl;
	for (iter1 = myMultiSet1.lower_bound(1); iter1 != myMultiSet1.upper_bound(1); iter1++)
	{
		cout << *iter1 << endl;
	}
	myMultiSet1.erase(myMultiSet1.find(3));
	cout << endl;
	for (iter1 = myMultiSet1.begin(); iter1 != myMultiSet1.end(); iter1++)
	{
		cout << *iter1 << endl;
	}
	cout << endl;
	/*
	unordered_map
	Ŭ���� ���ø��� ���� std::pair<const Key, Ty>����� �پ��� ���� �������� �����ϴ� ��ü�� �����մϴ�.
	�������� �ؽ� �Լ��� ���ϰ� ���ĵ˴ϴ�. 
	��, �������� ��Ŷ�̶�� �ϴ� ���� �������� ���ĵ� �������� �����մϴ�.
	�� ��Ŷ ������ �� �Լ��� ��� �ֿ� ������ ������ �ִ��� ���θ� �����մϴ�.
	�� ��Ҵ� �� ��ü, ���� Ű�� ���� �����մϴ�.
	�������� ��� ��� ��Ŷ�� ���̰� ���� ���� ��� �������� ��� ��(��� �ð�)�� �������� �� �ִ� ������ ����Ͽ� ���� ����� ��ȸ, ���� �� ���Ÿ� ����ϴ� ������� ǥ�õ˴ϴ�.
	��� ��Ұ� �ϳ��� ��Ŷ�� �ִ� �־��� ��쿡�� �۾� ���� �������� ��� ���� ����մϴ�(���� �ð�).
	���� ��Ҹ� �����ϸ� �ݺ��Ⱑ ��ȿȭ���� �ʰ� ��Ҹ� �����ϸ� ���ŵ� ��Ҹ� ����Ű�� �ݺ��⸸ ��ȿȭ�˴ϴ�.
	*/
	unordered_map<char, int> myUnMap;
	myUnMap['a'] = 2;
	myUnMap.insert(make_pair('b', 1));
	cout << myUnMap['a'] << endl;
	cout << myUnMap['b'] << endl;
	for (pair<char, int> p : myUnMap)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	myUnMap.erase(myUnMap.find('a'));
	cout << endl;
	for (pair<char, int> p : myUnMap)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	cout << endl;
	/*
	unordered_multimap
	Ŭ���� ���ø��� ���� std::pair<const Key, Ty>����� �پ��� ���� �������� �����ϴ� ��ü�� �����մϴ�.
	�������� �ؽ� �Լ��� ���ϰ� ���ĵ˴ϴ�.
	��, �������� ��Ŷ�̶�� �ϴ� ���� �������� ���ĵ� �������� �����մϴ�.
	�� �Լ��� �� ��Ŷ ������ ��� ���� �����ϰ� ���ĵǾ����� ���θ� Ȯ���մϴ�.
	�� ��Ҵ� �� ��ü, ���� Ű�� ���� �����մϴ�.
	�������� �ּ��� ��� ��Ŷ�� �뷫 ������ ũ���� ��� �������� ��� ���� ������� �۾� ���� ����Ͽ� ���� ��Ҹ� ��ȸ, ����, �����ϴ� ������� ��Ÿ���ϴ�(���� �ð�).
	��� ��Ұ� �ϳ��� ��Ŷ�� �ִ� �־��� ��쿡�� �۾� ���� �������� ��� ���� ����մϴ�(���� �ð�).
	����, ��Ҹ� ������ ��� � �ݺ��⵵ ��ȿȭ���� ������, ��Ҹ� ������ ��� ���ŵ� ��Ҹ� ����Ű�� �ִ� �ݺ��⸸ ��ȿȭ�˴ϴ�.
	*/
	unordered_multimap<char, int> myUnMultiMap;
	myUnMultiMap.insert(make_pair('a', 4));

	myUnMultiMap.insert(make_pair('a', 2));
	myUnMultiMap.insert(make_pair('a', 3));
	myUnMultiMap.insert(make_pair('b', 1));
	auto finder = myUnMultiMap.equal_range('a');
	for (unordered_multimap<char, int>::iterator iter = finder.first; iter != finder.second; iter++)
	{
		cout << iter->first << ' ' << iter->second << endl;
	}
	cout << endl;
	for (pair<char, int> p : myUnMultiMap)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	cout << endl;
	myUnMultiMap.erase(myUnMultiMap.find('a'));
	for (pair<char, int> p : myUnMultiMap)
	{
		cout << p.first << ' ' << p.second << endl;
	}
	cout << endl;
	/*
	unordered_set
	Ŭ���� ���ø��� ���� const Key����� �پ��� ���� �������� �����ϴ� ��ü�� �����մϴ�.
	�������� �ؽ� �Լ��� ���ϰ� ���ĵ˴ϴ�.
	��, �������� ��Ŷ�̶�� �ϴ� ���� �������� ���ĵ� �������� �����մϴ�.
	�� ��Ŷ ������ �� �Լ��� ��� �ֿ� ������ ������ �ִ��� ���θ� �����մϴ�.
	�� ��Ҵ� ���� Ű�� ������ ���˴ϴ�.
	�������� �ּ��� ��� ��Ŷ�� �뷫 ������ ũ���� ��� �������� ��� ���� ������� �۾� ���� ����Ͽ� ���� ��Ҹ� ��ȸ, ����, �����ϴ� ������� ��Ÿ���ϴ�(���� �ð�).
	��� ��Ұ� �ϳ��� ��Ŷ�� �ִ� �־��� ��쿡�� �۾� ���� �������� ��� ���� ����մϴ�(���� �ð�).
	��Ҹ� �����ϸ� �ݺ��Ⱑ ��ȿȭ���� �ʰ� ��Ҹ� �����ϸ� ���ŵ� ��Ҹ� ����Ű�� �ݺ��⸸ ��ȿȭ�˴ϴ�.
	*/
	unordered_set<int> myUnSet;
	myUnSet.insert(1);
	unordered_set<int> myUnSet1 = { 0,1,2,3,4 };
	unordered_set<int>::iterator unIter = myUnSet1.find(2);
	cout << *unIter << endl;
	cout << endl;
	for (unIter = myUnSet1.begin(); unIter != myUnSet1.end(); unIter++)
	{
		cout << *unIter << endl;
	}
	myUnSet1.erase(myUnSet1.find(3));
	cout << endl;
	for (unIter = myUnSet1.begin(); unIter != myUnSet1.end(); unIter++)
	{
		cout << *unIter << endl;
	}
	/*
	unordered_multiset
	Ŭ���� ���ø��� ���� const Key����� �پ��� ���� �������� �����ϴ� ��ü�� �����մϴ�.
	�������� �ؽ� �Լ��� ���ϰ� ���ĵ˴ϴ�.
	��, �������� ��Ŷ�̶�� �ϴ� ���� �������� ���ĵ� �������� �����մϴ�.
	�� �Լ��� �� ��Ŷ ������ ��� ���� �����ϰ� ���ĵǾ����� ���θ� Ȯ���մϴ�.
	�� ��Ҵ� ���� Ű�� ������ ���˴ϴ�.
	�������� �ּ��� ��� ��Ŷ�� �뷫 ������ ũ���� ��� �������� ��� ���� ������� �۾� ���� ����Ͽ� ���� ��Ҹ� ��ȸ, ����, �����ϴ� ������� ��Ÿ���ϴ�(���� �ð�).
	��� ��Ұ� �ϳ��� ��Ŷ�� �ִ� �־��� ��쿡�� �۾� ���� �������� ��� ���� ����մϴ�(���� �ð�).
	����, ��Ҹ� ������ ��� � �ݺ��⵵ ��ȿȭ���� ������, ��Ҹ� ������ ��� ���ŵ� ��Ҹ� ����Ű�� �ִ� �ݺ��⸸ ��ȿȭ�˴ϴ�.
	*/
	unordered_multiset<int> myUnMultiSet;
	myUnMultiSet.insert(1);
	unordered_multiset<int> myUnMultiSet1 = { 0,1,1,2,3,4 };
	unordered_multiset<int>::iterator unIter1 = myUnMultiSet1.find(2);
	cout << *unIter1 << endl;
	cout << endl;
	for (unIter1 = myUnMultiSet1.begin(); unIter1 != myUnMultiSet1.end(); unIter1++)
	{
		cout << *unIter1 << endl;
	}
	cout << endl;
	auto setFinder = myUnMultiSet1.equal_range(1);
	for (unIter1 = setFinder.first; unIter1 != setFinder.second; unIter1++)
	{
		cout << *unIter1 << endl;
	}
	myUnMultiSet1.erase(myUnMultiSet1.find(3));
	cout << endl;
	for (unIter1 = myUnMultiSet1.begin(); unIter1 != myUnMultiSet1.end(); unIter1++)
	{
		cout << *unIter1 << endl;
	}
	cout << endl;
}