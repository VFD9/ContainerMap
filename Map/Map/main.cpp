// ContainerMap v0.1
#include <iostream>
#include <string>
#include <map>

using namespace std;

struct object
{

};

int main(void)
{
	/*
	map<int, int> Numbers;

	// Key, Value

	Numbers[0] = 1;
	Numbers[1] = 2;
	Numbers[2] = 3;
	Numbers[3] = 4;
	Numbers[4] = 5;
	*/

	/*
	map<string, int> Numbers;

	// Key, Value

	Numbers["A"] = 1;
	Numbers["B"] = 2;
	Numbers["C"] = 3;
	Numbers["D"] = 4;
	Numbers["E"] = 5;

	for (map<string, int>::iterator iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		cout << iter->first << endl;
		cout << iter->second << endl << endl;
	}

	for (auto iter = Numbers.begin(); iter != Numbers.end(); ++iter)
	{
		cout << iter->first << endl;
		cout << iter->second << endl << endl;
	}
	*/

	// 배열은 정수이면서 상수여야 한다
	/*enum Key { AAA, BBB, CCC, DDD, EEE };

	const int Max = 10;

	Key _State = AAA;
	int Array[EEE];

	cout << Array[_State] << endl;
	*/

	// 심볼릭 상수를 활용한 2차원 배열
	enum Key 
	{ 
		Player,
		Enemy,
		Bullet,
		Max,
	};

	const int MaxObject = 128;

	int Array[Max][MaxObject];

	for (int i = 0; i < Max; ++i)
	{
		for (int j = 0; j < MaxObject; ++j)
		{
			Array[i][j] = j;
		}
	}

	for (int i = 0; i < MaxObject; ++i)
		cout << Array[Enemy][i] << endl;
	
	return 0;
}

// 한 개의 키값과 한 개의 정보
// C는 데이터를 들고 올 방법이 많지 않아서 소켓을 사용해야한다