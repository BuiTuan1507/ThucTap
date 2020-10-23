// ThucTap.cpp : Defines the entry point for the console application.
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
	virtual void getId(BaseObject Base) {
		printf("%d   ", Base.id);
	}
	virtual void getName(BaseObject car) {
		printf("%s  \n", car.name.c_str());
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
	virtual void move(StaticObject &staticObject) {
		staticObject.positionX += 0;
		staticObject.positionY += 0;

	}
	virtual void printAfterMovePosition(StaticObject staticObject) {
		printf("  Vi tri sau cua vat the: (%d, %d )  \n", staticObject.positionX, staticObject.positionY);
	}
	virtual void printPosition(StaticObject staticObject) {
		printf("  Vi tri cua vat the: (%d, %d )  \n", staticObject.positionX, staticObject.positionY);
	}


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

public:
	virtual void move(DynamicObject &dynamicObject) {
		dynamicObject.positionX += 2;
		dynamicObject.positionY += 1;

	}
	virtual void printAfterMovePosition(DynamicObject dynamicObject) {
		printf("  Vi tri sau cua vat the: (%d, %d )  \n", dynamicObject.positionX, dynamicObject.positionY);
	}
	virtual void printPosition(DynamicObject dynamicObject) {
		printf("  Vi tri cua vat the: (%d, %d )  \n", dynamicObject.positionX, dynamicObject.positionY);
	}

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

public:
	Tree(int x, string y, int z, int t) {
		this->id = x;
		this->name = y;
		this->positionX = z;
		this->positionY = t;
	};
	void getId(Tree tree) {

	}

	void getName(Tree tree) {

	}
	//Position inner_object;
	void move(Tree &tree) {

	}
	void printAfterMovePosition(Tree tree) {

	}
	void printPosition(Tree tree) {

	}

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
public:
	House(int x, string y, int z, int t) {
		this->id = x;
		this->name = y;
		this->positionX = z;
		this->positionY = t;
	};
	void getId(Tree tree) {

	}

	void getName(Tree tree) {

	}
	//Position inner_object;
	void move(Tree &tree) {

	}
	void printAfterMovePosition(Tree tree) {

	}
	void printPosition(Tree tree) {

	}

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
	void getId(Motorbike moto) {
		//printf("%d   ", car.id);
	}
	void getName(Motorbike moto) {
		//printf("%s  \n", car.name.c_str());
	}
	void move(Motorbike &moto) {

	}
	void printAfterMovePosition(Motorbike moto) {

	}
	void printPosition(Motorbike moto) {

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
		this->positionX = z;
		this->positionY = t;
	};
	void getId(Car car) {

	}

	void getName(Car car) {

	}
	//Position inner_object;
	void move(Car &car) {

	}
	void printAfterMovePosition(Car car) {

	}
	void printPosition(Car car) {

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
	DynamicObject *car1 = new Car(1, "Xe Mercedes", 3, 0);
	DynamicObject *car2 = new Car(2, "Xe Yamaha", 4, 0);
	DynamicObject *car3 = new Car(3, "Xe heo99999", 1, 0);
	DynamicObject *listCar[3] = { car1,car2,car3 };

	DynamicObject *moto1 = new Motorbike(1, "Xe lead", 3, 0);
	DynamicObject *moto2 = new Motorbike(2, "Xe dream", 2, 0);
	DynamicObject *moto3 = new Motorbike(3, "Xe SH", 2, 0);
	DynamicObject *listMoto[3] = { moto1,moto2,moto3 };

	StaticObject *tree1 = new Tree(1, "Cam", 8, 0);
	StaticObject *tree2 = new Tree(2, "Oi", 7, 0);
	StaticObject *tree3 = new Tree(3, "Nho", 5, 0);
	StaticObject *listTree[3] = { tree1,tree2,tree3 };

	StaticObject *house1 = new House(1, "Market", 5, 0);
	StaticObject *house2 = new House(2, "Pizza", 4, 0);
	StaticObject *house3 = new House(3, "KFC", 3, 0);
	StaticObject *listHouse[3] = { house1,house2,house3 };
	printf("Car: \n");
	for (auto obj : listCar) {
		obj->getId(*obj);
		obj->getName(*obj);
		obj->printPosition(*obj);
		obj->move(*obj);
		obj->printAfterMovePosition(*obj);

	}
	printf("Motobike: \n");
	for (auto obj : listMoto) {
		obj->getId(*obj);
		obj->getName(*obj);
		obj->printPosition(*obj);
		obj->move(*obj);
		obj->printAfterMovePosition(*obj);

	}
	printf("Tree: \n");
	for (auto obj : listTree) {
		obj->getId(*obj);
		obj->getName(*obj);
		obj->printPosition(*obj);
		obj->move(*obj);
		obj->printAfterMovePosition(*obj);

	}
	printf("House : \n");
	for (auto obj : listHouse) {
		obj->getId(*obj);
		obj->getName(*obj);
		obj->printPosition(*obj);
		obj->move(*obj);
		obj->printAfterMovePosition(*obj);

	}
	for (int i = 0; i < 3; i++) {
		delete listCar[i];
		delete listHouse[i];
		delete listMoto[i];
		delete listTree[i];
	}
	delete[] listCar;
	delete[] listHouse;
	delete[] listMoto;
	delete[] listTree;



	system("pause");
	return 0;
}

