#ifndef HEAD_HPP
#define HEAD_HPP

#include <iostream>
#include <string>

void getDouble(double &val, const char *txt);
void getInt(int &val, const char *txt);

struct Item{
	double double_val;
	std::string string_val;

	Item();//инициализирующий конструктор
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
	Queue(const Item *queue, const int &num, const int &len);
	Queue(const Queue &queue);//конструктор присваивания
	Queue(Queue &&queue);//конструктор перемищения
	Queue(int len);
	Queue(){}

	int operator !();
	int operator >> (Item &item);
	int operator << (Item &item);
	friend std::ostream &operator << (std::ostream &ostream, const Queue &queue);
	Queue & operator = (const Queue &queue);//операор присваивания
	Queue & operator = (Queue && queue);//оператор перемещения
	
	//деструкторы
	void destroy();
	~Queue();
	int dsize(){return size;}
	int dnumber(){return number;}
	int dtail(){return tail;}
	int dhead(){return head;}
	Item *darr(){return arr;}
	int operator == (const Queue &queue);

};

int processing(Queue &my_queue);

#endif
