// StateDoors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include <cstdio>
using namespace std;

 //#define STATE_1
#define STATE_2
#ifdef STATE_1
emum stateEnum{
	STATE_OPENED,
	STATE_CLOSED,
	STATE_LOCKED
}
int m_nCurrentState
#endif // STATE_1
#ifdef STATE_2
class StateBase
{
public:
	StateBase();
	~StateBase();

public:
	bool state = true;
	virtual StateBase* GetNextState(bool state) = 0;
	virtual    char* ToString() = 0;
	void set_state(bool state);
};
void StateBase::set_state(bool state) {
	this->state = state;
}
StateBase::StateBase()
{
}

StateBase::~StateBase()
{
}
//State Opened
class Opened : public StateBase
{
public:
	Opened();
	~Opened();

public:
	
	virtual StateBase* GetNextState(bool state);
	virtual    char* ToString() {
		return "Class Opened";
	}
	

};

Opened::Opened()
{
}

Opened::~Opened()
{
}
//State Closed
class Closed : public StateBase
{
public:
	Closed();
	~Closed();

public:
	virtual StateBase* GetNextState(bool state);
	virtual    char* ToString() {
		return "Class Closed";
	}

};

Closed::Closed()
{
}

Closed::~Closed()
{
}
//State Locked
class Locked : public StateBase
{
public:
	Locked();
	~Locked();

public:
	virtual StateBase* GetNextState(bool state);
	virtual    char* ToString() {
		return "Class Locked ";
	}
};

Locked::Locked()
{
}

Locked::~Locked()
{
}
StateBase* Closed::GetNextState(bool state) {
	if (state == true) {
		return new Locked();
	}

	else{
		
		return new Opened();
	}

}

StateBase* Opened::GetNextState(bool state) {
	
	Closed* open = new Closed();
	open->set_state(true);
	return open;
}

StateBase* Locked::GetNextState(bool state) {
	
	Closed* close = new Closed();
	close->set_state(false);
	return close;
}
class Door
{
public:
	Door() {};
	Door(StateBase* pContext) {
		m_pState = pContext;
	}
	~Door() {
		delete m_pState;
	};
	
	
public:
	void StateChanged() {
		if (m_pState) {
			StateBase* pState = m_pState->GetNextState(m_pState->state);
			delete m_pState;
			m_pState = pState;
		}
	}
	char* GetStateName() {
		return m_pState->ToString();
	}
protected:
	StateBase* m_pState;


};


#endif // STATE_2 



int main()
{
#ifdef STATE_1

	m_nCurrentState = STATE_EVENING;
	switch (m_nCurrentState)
	{
	case STATE_MORNING:
		m_nCurrentState = STATE_EVENING;
		break;
	case STATE_EVENING:
		m_nCurrentState = STATE_NIGHT;
		break;
	case STATE_NIGHT:
		m_nCurrentState = STATE_EVENING;
		break;
		//..........
		//..........
		//..........
	default:
		break;
	}

#endif

#ifdef STATE_2
	
	Door objSun(new Opened);
	printf("Door is %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());

	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());
	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());
	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());
	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());
	objSun.StateChanged();
	printf("Door is %s !!!\n\n", objSun.GetStateName());


#endif

	system("pause");
    return 0;
}

