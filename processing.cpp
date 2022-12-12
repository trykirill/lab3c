#include <iostream>
#include <string>
#include "head.hpp"

int processing(Queue &my_queue){
	Item val;
	int mode;
	do{
	std::cout << "[0] вставить в очередь\n"
		<< "[1]  удалить из очереди\n"
		<< "[2]  вывести очередь\n"
		<< "[3] переобозначить очередь\n";
	getInt(mode, "enter mode -> ");
	if(mode == 0){
		std::cin >> val;
		my_queue << val;
	}
	else if(mode == 1){
		if(!(my_queue >> val)){
			std::cout << val;
		}
	}
	else if(mode == 2){
		std::cout << my_queue;
	}
	else if(mode == 3){
		int len, number;
		getInt(len, "enter size of queue");
		Item *queue = new Item[len];
		getInt(number, "enter number of items -> ");
		std::cin >> number;
		Item item;
		for(int pos = 0; pos < number; ++pos){
			std::cout << "item " << pos << ":\n";
			std::cin >> item;
			queue[pos] = item;
		}
		my_queue(queue, number, len);
	}
	}while(mode != -1);
	return 0;
}

void getDouble(double &val, const char *txt){
	int flag = 1;
	const char * err = "";
	do{
		std::cout << err;
		std::cout << txt;
		std::cin >> val;
		if(std::cin.good()){
			flag = 0;
		}
		else{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		err = "wronge data!\n";
	} while(flag);
}

void getInt(int &val, const char *txt){
	int flag = 1;
	const char * err = "";
	do{
		std::cout << err;
		std::cout << txt;
		std::cin >> val;
		if(std::cin.eof()){
			val =  -1;
			return;
		}
		if(std::cin.good()){
			flag = 0;
		}
		else{
			std::cin.clear();
			std::cin.ignore(1000, '\n');
		}
		err = "wronge data!\n";
	} while(flag);
}

