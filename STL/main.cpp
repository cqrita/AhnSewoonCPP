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
	C++ 표준 라이브러리 벡터 클래스는 시퀀스 컨테이너에 대한 클래스 템플릿입니다.
	벡터는 지정된 형식의 요소를 선형 배열에 저장하고 모든 요소에 대한 빠른 임의 액세스를 허용합니다. 
	임의 액세스 성능이 프리미엄인 경우 벡터는 시퀀스에 대한 기본 컨테이너입니다.
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
	길이가 N인 Ty 형식의 요소 시퀀스를 제어하는 개체를 설명합니다. 
	시퀀스는 array<Ty, N> 개체에 포함된 Ty의 배열로 저장됩니다.
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
	각 요소가 데이터 값과 정렬 키를 갖고 있는 쌍인 컬렉션에서 데이터의 저장과 검색에 사용됩니다. 
	키 값은 고유하며 데이터를 자동으로 정렬하는 데 사용됩니다.
	map에 있는 요소의 값은 직접 변경할 수 있습니다. 키 값은 상수이며 변경할 수 없습니다. 
	대신, 이전 요소와 관련된 키 값은 삭제되어야 하며 새 요소에 대한 새 키 값이 삽입되어야 합니다.
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
	C++ 표준 라이브러리 multimap 클래스는 각 요소가 데이터 값과 정렬 키를 모두 포함하는 쌍인 컬렉션에서 데이터를 저장하고 검색하는 데 사용됩니다. 
	키 값은 고유할 필요가 없으며 데이터를 자동으로 정렬하는 데 사용됩니다. 
	multimap 요소의 값은 연관된 키 값을 제외하고 직접적으로 변경할 수 있습니다. 
	대신, 이전 요소와 관련된 키 값을 삭제하고 새 요소와 연결된 새 키 값을 삽입해야 합니다.
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
	C++ 표준 라이브러리 컨테이너 클래스 set 는 컬렉션에서 데이터를 저장하고 검색하는 데 사용됩니다. 
	요소의 set 값은 고유하며 데이터가 자동으로 정렬되는 키 값으로 사용됩니다. 
	요소의 set 값은 직접 변경되지 않을 수 있습니다. 대신, 이전 값을 삭제하고 새 값의 요소를 삽입해야 합니다.
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
	C++ 표준 라이브러리 multiset 클래스는 포함된 요소값이 고유할 필요가 없고 데이터가 자동 정렬되는 기준인 키 값으로 사용된 컬렉션의 데이터를 저장 및 검색하는 데 사용됩니다. 
	요소 multiset 의 키 값은 직접 변경되지 않을 수 있습니다. 
	대신, 이전 값을 삭제하고 새 값의 요소를 삽입해야 합니다.
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
	클래스 템플릿은 형식 std::pair<const Key, Ty>요소의 다양한 길이 시퀀스를 제어하는 개체를 설명합니다.
	시퀀스는 해시 함수로 약하게 정렬됩니다. 
	즉, 시퀀스를 버킷이라고 하는 하위 시퀀스의 정렬된 집합으로 분할합니다.
	각 버킷 내에서 비교 함수는 요소 쌍에 동일한 순서가 있는지 여부를 결정합니다.
	각 요소는 두 개체, 정렬 키와 값을 저장합니다.
	시퀀스는 적어도 모든 버킷의 길이가 거의 같은 경우 시퀀스의 요소 수(상수 시간)와 독립적일 수 있는 연산을 사용하여 임의 요소의 조회, 삽입 및 제거를 허용하는 방식으로 표시됩니다.
	모든 요소가 하나의 버킷에 있는 최악의 경우에는 작업 수가 시퀀스의 요소 수에 비례합니다(선형 시간).
	또한 요소를 삽입하면 반복기가 무효화되지 않고 요소를 제거하면 제거된 요소를 가리키는 반복기만 무효화됩니다.
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
	클래스 템플릿은 형식 std::pair<const Key, Ty>요소의 다양한 길이 시퀀스를 제어하는 개체를 설명합니다.
	시퀀스는 해시 함수로 약하게 정렬됩니다.
	즉, 시퀀스를 버킷이라고 하는 하위 시퀀스의 정렬된 집합으로 분할합니다.
	비교 함수는 각 버킷 내에서 요소 쌍이 동일하게 정렬되었는지 여부를 확인합니다.
	각 요소는 두 개체, 정렬 키와 값을 저장합니다.
	시퀀스는 최소한 모든 버킷이 대략 동일한 크기일 경우 시퀀스의 요소 수와 상관없이 작업 수를 사용하여 임의 요소를 조회, 삽입, 제거하는 방식으로 나타냅니다(일정 시간).
	모든 요소가 하나의 버킷에 있는 최악의 경우에는 작업 수가 시퀀스의 요소 수에 비례합니다(선형 시간).
	또한, 요소를 삽입할 경우 어떤 반복기도 무효화되지 않으며, 요소를 제거할 경우 제거된 요소를 가리키고 있는 반복기만 무효화됩니다.
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
	클래스 템플릿은 형식 const Key요소의 다양한 길이 시퀀스를 제어하는 개체를 설명합니다.
	시퀀스는 해시 함수로 약하게 정렬됩니다.
	즉, 시퀀스를 버킷이라고 하는 하위 시퀀스의 정렬된 집합으로 분할합니다.
	각 버킷 내에서 비교 함수는 요소 쌍에 동일한 순서가 있는지 여부를 결정합니다.
	각 요소는 정렬 키와 값으로 사용됩니다.
	시퀀스는 최소한 모든 버킷이 대략 동일한 크기일 경우 시퀀스의 요소 수와 상관없이 작업 수를 사용하여 임의 요소를 조회, 삽입, 제거하는 방식으로 나타냅니다(일정 시간).
	모든 요소가 하나의 버킷에 있는 최악의 경우에는 작업 수가 시퀀스의 요소 수에 비례합니다(선형 시간).
	요소를 삽입하면 반복기가 무효화되지 않고 요소를 제거하면 제거된 요소를 가리키는 반복기만 무효화됩니다.
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
	클래스 템플릿은 형식 const Key요소의 다양한 길이 시퀀스를 제어하는 개체를 설명합니다.
	시퀀스는 해시 함수로 약하게 정렬됩니다.
	즉, 시퀀스를 버킷이라고 하는 하위 시퀀스의 정렬된 집합으로 분할합니다.
	비교 함수는 각 버킷 내에서 요소 쌍이 동일하게 정렬되었는지 여부를 확인합니다.
	각 요소는 정렬 키와 값으로 사용됩니다.
	시퀀스는 최소한 모든 버킷이 대략 동일한 크기일 경우 시퀀스의 요소 수와 상관없이 작업 수를 사용하여 임의 요소를 조회, 삽입, 제거하는 방식으로 나타냅니다(일정 시간).
	모든 요소가 하나의 버킷에 있는 최악의 경우에는 작업 수가 시퀀스의 요소 수에 비례합니다(선형 시간).
	또한, 요소를 삽입할 경우 어떤 반복기도 무효화되지 않으며, 요소를 제거할 경우 제거된 요소를 가리키고 있는 반복기만 무효화됩니다.
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