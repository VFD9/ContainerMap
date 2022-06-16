// ContainerMap v0.1
#include <iostream>
#include <string>
#include <map>

using namespace std;

map<int, int> Numbers;

void AddData(int _Key, int _Value);

int main(void)
{
	Numbers[0] = 0;
	Numbers[1] = 10;
	Numbers[2] = 20;
	Numbers.insert(make_pair(3, 30));

	Numbers[1] = 100;

	Numbers.insert(make_pair(4, 40));

	map<int, int>::iterator iter = Numbers.find(2);

	//Numbers.insert(make_pair(2, 200)); 기존 데이터를 지켜주기에 make_pair를 써도 바뀌지 않음
	
	AddData(2, 200);

	for (map<int, int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
		cout << iter->second << endl;
	
	return 0;
}

void AddData(int _Key, int _Value)
{
	map<int, int>::iterator iter = Numbers.find(_Key);

	if (iter == Numbers.end())
		Numbers.insert(make_pair(_Key, _Value));
	else
		iter->second = _Value;
}

// 한 개의 키값과 한 개의 정보
// C는 데이터를 들고 올 방법이 많지 않아서 소켓을 사용해야한다