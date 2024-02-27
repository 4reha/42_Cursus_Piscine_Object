#pragma once
#include <list>

enum Event
{
	RingBell
};

class Person;

class BellEvent
{
	std::list<Person *> list_observer_;
	Event _event;
	void bell();
	void notify();
public:
	BellEvent(){};
	~BellEvent(){};
	void attach(Person *observer);
	void detach(Person *observer);

	friend class Headmaster;
};
