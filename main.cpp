#include"head.hpp"

int main(){
	int size;
	getInt(size, "enter size of queue -> ");
	Queue my_queue(size);
	processing(my_queue);
	return 0;
}

