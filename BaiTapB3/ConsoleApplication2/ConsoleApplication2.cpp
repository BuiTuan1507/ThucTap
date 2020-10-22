// ConsoleApplication2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <string>
using namespace std;
struct Position
{
	int x;
	int y;
};
class BaseObject
{
public:
	BaseObject();
	~BaseObject();

public:
	int id;
	string name;
	int positionX;
	int positionY;
	virtual void getId(BaseObject &Base) {
		printf("%d   ", Base.id);
	}
	virtual void getName(BaseObject &car) {
		printf("%s  \n", car.name.c_str());
	}
	virtual void move(BaseObject &car) {
		car.positionX += 2;
		car.positionY += 0;
		printf("%d", car.positionX);
	}
	virtual void printAfterMovePosition(BaseObject &car) {
		printf("  Vi tri sau cua vat the: (%d, %d )  \n", car.positionX, car.positionY);
	}
	virtual void printPosition(BaseObject &car) {
		printf("  Vi tri cua vat the: (%d, %d )  \n", car.positionX, car.positionY);
	}

	


};

BaseObject::BaseObject()
{
}
BaseObject::~BaseObject()
{
}
class StaticObject : public BaseObject
{
public:
	StaticObject();
	~StaticObject();

public: 
	

};

StaticObject::StaticObject()
{
}

StaticObject::~StaticObject()
{
}
class DynamicObject : public BaseObject
{
public:
	DynamicObject();
	~DynamicObject();

private:

};

DynamicObject::DynamicObject()
{
}

DynamicObject::~DynamicObject()
{
}
class Tree : public StaticObject
{
public:
	Tree();
	~Tree();

private:

};

Tree::Tree()
{
}

Tree::~Tree()
{
}
class House : public StaticObject
{
public:
	House();
	~House();

private:

};

House::House()
{
}

House::~House()
{
}
class Motorbike : public DynamicObject
{
public:
	Motorbike();
	~Motorbike();

public:
	Motorbike(int x, string y, int z, int t) {
		this->id = x;
		this->name = y;
		this->positionX = z;
		this->positionY = t;
	};
	void getId(Motorbike &moto) {
		//printf("%d   ", car.id);
	}
	void getName(Motorbike &car) {
		//printf("%s  \n", car.name.c_str());
	}

};

Motorbike::Motorbike()
{
}

Motorbike::~Motorbike()
{
}
class Car : public DynamicObject 
{
public:
	Car();
	~Car();

public:
	
	
	Car(int x, string y, int z, int t) {
		this->id = x;
		this->name = y;
		this-> positionX = z;
		this ->positionY = t;
	};
	void getId(Car &car) {
		//printf("%d   ", car.id);
	}

	void getName(Car &car) {
		//printf("%s  \n", car.name.c_str());
	}
	//Position inner_object;
	void move(Car &car) {
	//	car.positionX += 2;
	//	car.positionY += 0;
	//	printf("%d",car.positionX);
	}
	void printAfterMovePosition(Car &car) {
		//printf("  Vi tri sau cua vat the: (%d, %d )  \n", car.positionX,car.positionY);
	}
	void printPosition(Car &car) {
		//printf("  Vi tri cua vat the: (%d, %d )  \n", car.positionX, car.positionY);
	}


};
Car::Car()
{
}

Car::~Car()
{
}


int main()
{	
	BaseObject car1 =  Car(1, "Xe Mercedes", 3, 0);
	BaseObject car2 =  Car(2,"Xe Yamaha",4,0);
	BaseObject car3 =  Car(3,"Xe heo",1,0);
	BaseObject listCar[3] = { car1,car2,car3 };
	BaseObject moto1 = Motorbike(10000, "sf", 1, 0);
	for (auto obj : listCar) {
		obj.getId(obj);
		obj.getName(obj);
		obj.printPosition(obj);
		obj.move(obj);
		obj.printAfterMovePosition(obj);
		
	}
	moto1.getId(moto1);

	
	
	system("pause");
   return 0;
}

