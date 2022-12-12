#include <iostream>
#include <string>
#include "head.hpp"

Item::Item(){
	double_val = 0;
	string_val = "";
}

Queue::Queue(Item *&queue, int &num, int &len) : size(len), number(num), tail(num),  arr(queue){};

Queue::Queue(const Queue & queue):size(queue.size), number(queue.number), head(queue.head), tail(queue.tail), arr(nullptr)
{
	if(number){
		arr = new Item[size];
		for(int pos = head; pos < tail; pos++){
			arr[pos] = queue.arr[pos];
		}
	}
}

Queue::Queue(Queue &queue){
}

Queue::Queue(int len) : size(len)
{
	if(size){
		arr = new Item[size];
	}
}

Queue::~Queue(){
	size = 0;
	number = 0;
	head = 0;
	tail = 0;
	if(size){
		delete [] arr;
		arr = nullptr;
	}
}

int Item::operator == (Item &item){
	if(double_val == item.double_val and string_val == item.string_val){
		return 1;
	}
	return 0;
}

Item Item::operator >> (double &val){
	val = double_val;
	return *this;
}

Item Item::operator >> (std::string &val){
	val = string_val;
	return *this;
}

Item Item::operator << (double val){
	double_val = val;
	return *this;
}

Item Item::operator << (std::string val){
	string_val = val;
	return *this;
}

std::istream &operator >> (std::istream &istream,  Item &item){
	std::cout << "enter double val -> ";
	istream >> item.double_val;	
	std::cout << "enter string val -> ";
	istream >> item.string_val;
	return istream;
}

std::ostream &operator << (std::ostream &ostream, const Item &item){
	ostream << "{" << item.double_val << ", " << item.string_val<< "}\n";
	return ostream;
}


Queue &Queue::operator = (const Queue  &queue){
	if(this != &queue){
		size = queue.size;
		number = queue.number;
		head = queue.head;
		tail = queue.tail;
		delete [] arr;
		if(number){
			for(int pos = head; pos % size < tail; ++pos){
				arr[pos] = queue.arr[pos];
			}
		}
	}
	return *this;
}	


int Queue::operator >> (Item &item){
	if(number == 0){
		std::cout << "queue is empty\n";
		return 1;
	}
	item.double_val = arr[head].double_val;
	item.string_val = arr[head].string_val;
	head = (head + 1) %size;
	--number;
	return 0;
}

int Queue::operator << (Item &item){
	if(number == size){
		std::cout << "queue is full\n";
		return 1;
	}
	arr[tail] << item.string_val;
	arr[tail] << item.double_val;
	tail = (tail + 1) % size;
	++number;
	return 0;
}

std::ostream &operator << (std::ostream &ostream, const Queue &queue){
	int tmp_head = queue.head;
	for(int num = 0; num < queue.number; num++){
		ostream << queue.arr[tmp_head];
		tmp_head = (tmp_head + 1) % queue.size;
	}
	return ostream;
}

int Queue::operator ! (){
	if(number == size){
		return 2;
	}
	if(number == 0){
		return 1;
	}
	return 0;
}
