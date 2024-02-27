#include "Event.hpp"
#include "Person.hpp"

void BellEvent::attach(Person *observer)
{
	if (std::find(list_observer_.begin(), list_observer_.end(), observer) == list_observer_.end())
		list_observer_.push_back(observer);
}

void BellEvent::detach(Person *observer)
{
	list_observer_.remove(observer);
}

void BellEvent::notify()
{
	std::list<Person *>::iterator it = list_observer_.begin();
	for (; it != list_observer_.end(); ++it)
	{
		(*it)->update(this->_event);
	}
}

void BellEvent::bell()
{
	this->_event = RingBell;
	notify();
}
