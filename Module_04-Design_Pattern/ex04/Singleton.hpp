#pragma once
#include <iostream>
#include <vector>

template <typename T>
class Singleton
{
protected:
	Singleton(){};
	static Singleton *_instance;
	static std::vector<T> _list;

public:
	Singleton(Singleton &other) = delete;
	void operator=(const Singleton &) = delete;

	static Singleton *getInstance()
	{
		if (_instance == nullptr)
			_instance = new Singleton();
		return _instance;
	}

	 T add(T item)
	{
		_list.push_back(item);
		return item;
	};

	 T remove(T item)
	{
		_list.erase(std::remove(_list.begin(), _list.end(), item), _list.end());
		return item;
	};

	 std::vector<T> getList()
	{
		return _list;
	};

	T operator[](int index)
	{
		if (index < 0 || index >= _list.size())
			throw std::out_of_range("Index out of range");
		return _list[index];
	};
};

template <typename T>
Singleton<T> *Singleton<T>::_instance = nullptr;

template <typename T>
std::vector<T> Singleton<T>::_list = std::vector<T>();
