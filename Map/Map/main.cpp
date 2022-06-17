// ContainerMap v0.2
#include <iostream>
#include <string>
#include <map>
#include <list>

using namespace std;

struct Vector3
{
	float x, y, z;

	Vector3() : x(0.0f), y(0.0f), z(0.0f) {};
	Vector3(const float _x, const float _y) : x(_x), y(_y), z(0.0f) {};
	Vector3(const float _x, const float _y, const float _z) : x(_x), y(_y), z(_z) {};
};

struct Transform
{
	Vector3 Position;
	Vector3 Rotation;
	Vector3 Scale;
};

struct Object
{
	Transform Info;

	Object() {};
	Object(const Transform& _Info) : Info(_Info) {};
};

struct Player : public Object
{
	Player() {};
	Player(const Transform& _Info) : Object(_Info) {};
};

map<string, list<Object*>> Objects;

void Initialize();
void AddObject(string _Key, Object* _Object);

int main(void)
{
	//Initialize();
	Transform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	AddObject("Player", new Player(Info));

	for (map<string, list<Object*>>::iterator iter = Objects.begin(); iter != Objects.end(); ++iter)
		cout << &(iter->second) << endl;

	return 0;
}

void Initialize()
{
	Transform Info;

	Info.Position.x = 10;
	Info.Position.y = 20;
	Info.Position.z = 30;

	//Objects["Player"] = new Player(Info);
}

void AddObject(string _Key, Object* _Object)
{
	map<string, list<Object*>>::iterator iter = Objects.find(_Key);

	if (iter == Objects.end())
	{
		list<Object*> Temp;
		Temp.push_back(_Object);
		Objects.insert(make_pair(_Key, Temp));
	}
	else
		iter->second.push_back(_Object);
}

// 한 개의 키값과 한 개의 정보
// C는 데이터를 들고 올 방법이 많지 않아서 소켓을 사용해야한다