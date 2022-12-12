#ifndef HEAD_HPP
#define HEAD_HPP

#include <iostream>
#include <string>

void getDouble(double &val, const char *txt);
void getInt(int &val, const char *txt);

struct Item{
	double double_val;
	std::string string_val;

	Item();
	Item(double val_double, std::string val_string) : double_val(val_double), string_val(val_string) {};
		
	int operator == (Item &item);

	struct Item operator >> (double &val);
	struct Item operator >> (std::string &val);

	struct Item operator << (double val);
	struct Item operator << (std::string val);

	friend std::ostream &operator << (std::ostream &ostream, const Item &item);
	friend std::istream &operator >> (std::istream &isteam, Item &item);
};

class Queue{

private:
	int number = 0;
	int size = 0;
	int head = 0 ;
	int tail = 0;
	Item *arr = nullptr;
public:
	Queue(Item *queue, int num, int len);
	Queue(const Queue &queue);
	Queue(Queue &queue);
	Queue(int len);
	Queue();

	int operator !();
	int operator >> (Item &item);
	int operator << (Item &item);
	friend std::ostream &operator << (std::ostream &ostream, const Queue &queue);
	Queue & operator = (const Queue &queue);

	~Queue();
};

int processing(Queue &my_queue);

#endif
