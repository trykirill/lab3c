#include <gtest/gtest.h>
#include <string>
#include <iostream>
#include "head.hpp"

using namespace std;

TEST(my_queue_lib, Tes_Item_000){
	Item item1(1.1, "string");
	ASSERT_EQ(item1.double_val, 1.1);
	ASSERT_EQ(item1.string_val, "string");

	Item item2;
	ASSERT_EQ(item2.double_val, 0);
	ASSERT_EQ(item2.string_val, "");
}

TEST(my_queue_lib, Test_Item_001){
	Item item;
	string str = "first_string";
	item << str;
	ASSERT_EQ(item.string_val, "first_string");

	item << "second_string";
	ASSERT_EQ(item.string_val, "second_string");
}

TEST(my_queue_lib, Test_Item_002){
	Item item;
	double val_double = 1.1;
	item << val_double;
	ASSERT_EQ(item.double_val, val_double);

	item << 2.2;
	ASSERT_EQ(item.double_val, 2.2);
}

TEST(my_queue_lib, Test_Item_003){
	Item item1(1.1, "first_string");
	Item item2(1.1, "first_string");
	Item item3(2.2, "second_string");
	
	ASSERT_TRUE(item1 == item2);
	ASSERT_FALSE(item1 == item3);
}

TEST(my_queue_lib, Test_Item_004){
	Item item1(1.1, "first_string");
	Item item2(2.2, "second_string");

	item1 = item2;

	ASSERT_TRUE(item1 == item2);
}

TEST(my_queue_lib, Test_Item_005){
	Item item(1.1, "string");
	double val_double;

	item >> val_double;

	ASSERT_EQ(val_double, item.double_val);
}

TEST(my_queue_lib, Test_Item_006){
	Item item(1.1, "string");
	string str;

	item >> str;

	ASSERT_EQ(str, item.string_val);
}

Item item1(1, "first");
Item item2(2, "second");
Item item3(3, "third");
Item item4(4, "fourth");
Item item5(5, "fifth");

TEST(my_queue_lib, Test_Queue_000){//insert
	Queue queue1(3);
	ASSERT_EQ(queue1 << item1, 0);
	ASSERT_EQ(queue1 << item2, 0);
	ASSERT_EQ(queue1 << item3, 0);
	ASSERT_EQ(queue1 << item4, 1);

	Item *arr1 = queue1.darr();
	ASSERT_TRUE(arr1[0] == item1);
	ASSERT_TRUE(arr1[1] == item2);
	ASSERT_TRUE(arr1[2] == item3);
	ASSERT_EQ(queue1.dnumber(), 3);

	Queue queue2(2);
	ASSERT_EQ(queue2 << item1, 0);
	ASSERT_EQ(queue2 << item3, 0);
	ASSERT_EQ(queue2 << item5, 1);

	Item *arr2 = queue2.darr();
	ASSERT_TRUE(arr2[0] == item1);
	ASSERT_TRUE(arr2[1] == item3);
	ASSERT_EQ(queue2.dnumber(), 2);


}

TEST(my_queue_lib, Test_Queue_001){
	Item item;
	Queue queue1(5);
	queue1 << item1;
	queue1 << item3;
	queue1 << item5;

	ASSERT_TRUE(!(queue1 >> item) and item == item1);
	ASSERT_TRUE(!(queue1 >> item) and item == item3);
	ASSERT_TRUE(!(queue1 >> item) and item == item5);
	ASSERT_TRUE(queue1 >> item);
	ASSERT_EQ(queue1.dnumber(), 0);

	Queue queue2(4);
	queue2 << item2;
	queue2 << item4;

	ASSERT_TRUE(!(queue2 >> item) and item == item2);
	ASSERT_TRUE(!(queue2 >> item) and item == item4);
	ASSERT_TRUE(queue2 >> item);

	ASSERT_EQ(queue2.dnumber(), 0);

}	
TEST(my_queue_lib, Test_Queue_002){//~
	Queue queue1(3);
	queue1 << item1;
	queue1 << item2;
	
	queue1.destroy();
	ASSERT_EQ(queue1.dnumber(), 0);
	ASSERT_EQ(queue1.dsize(), 0);
	ASSERT_EQ(queue1.dtail(), 0);
	ASSERT_EQ(queue1.dhead(), 0);
	ASSERT_EQ(queue1.darr(), nullptr);
}

TEST(my_queue_lib, Test_Queue_003){//конструктор перемещение
	Queue const_queue1(5);
	const_queue1 << item1;
	const_queue1 << item3;
	const_queue1 << item5;
	Queue queue1(move(const_queue1));
	
	ASSERT_EQ(queue1.dnumber(), 3);
	ASSERT_EQ(queue1.dsize(), 5);
	ASSERT_EQ(queue1.dtail(), 3);
	ASSERT_EQ(queue1.dhead(), 0);
	ASSERT_EQ((queue1.darr())[0].double_val, item1.double_val);
	ASSERT_EQ((queue1.darr())[0].string_val, item1.string_val);
	ASSERT_EQ((queue1.darr())[1].double_val, item3.double_val);
	ASSERT_EQ((queue1.darr())[1].string_val, item3.string_val);
	ASSERT_EQ((queue1.darr())[2].double_val, item5.double_val);
	ASSERT_EQ((queue1.darr())[2].string_val, item5.string_val);

	ASSERT_EQ(const_queue1.dnumber(), 0);
	ASSERT_EQ(const_queue1.dsize(), 0);
	ASSERT_EQ(const_queue1.dtail(), 0);
	ASSERT_EQ(const_queue1.dhead(), 0);
	ASSERT_EQ(const_queue1.darr(), nullptr);
	
	Queue const_queue2(4);
	const_queue2 << item2;
	const_queue2 << item4;
	Queue queue2(move(const_queue2));
	
	ASSERT_EQ(queue2.dnumber(), 2);
	ASSERT_EQ(queue2.dsize(), 4);
	ASSERT_EQ(queue2.dtail(), 2);
	ASSERT_EQ(queue2.dhead(), 0);
	ASSERT_EQ((queue2.darr())[0].double_val, item2.double_val);
	ASSERT_EQ((queue2.darr())[0].string_val, item2.string_val);
	ASSERT_EQ((queue2.darr())[1].double_val, item4.double_val);
	ASSERT_EQ((queue2.darr())[1].string_val, item4.string_val);	

	ASSERT_EQ(const_queue2.dnumber(), 0);
	ASSERT_EQ(const_queue2.dsize(), 0);
	ASSERT_EQ(const_queue2.dtail(), 0);
	ASSERT_EQ(const_queue2.dhead(), 0);
	ASSERT_EQ(const_queue2.darr(), nullptr);	
}

TEST(my_queue_lib, Test_Queue_004){//конструктор копирования
	Queue const_queue1(5);
	const_queue1 << item1;
	const_queue1 << item3;
	const_queue1 << item5;
	Queue queue1(const_queue1);
	
	ASSERT_EQ(queue1.dnumber(), 3);
	ASSERT_EQ(queue1.dsize(), 5);
	ASSERT_EQ(queue1.dtail(), 3);
	ASSERT_EQ(queue1.dhead(), 0);
	ASSERT_EQ((queue1.darr())[0].double_val, item1.double_val);
	ASSERT_EQ((queue1.darr())[0].string_val, item1.string_val);
	ASSERT_EQ((queue1.darr())[1].double_val, item3.double_val);
	ASSERT_EQ((queue1.darr())[1].string_val, item3.string_val);
	ASSERT_EQ((queue1.darr())[2].double_val, item5.double_val);
	ASSERT_EQ((queue1.darr())[2].string_val, item5.string_val);
	
	Queue const_queue2(4);
	const_queue2 << item2;
	const_queue2 << item4;
	Queue queue2(const_queue2);
	
	ASSERT_EQ(queue2.dnumber(), 2);
	ASSERT_EQ(queue2.dsize(), 4);
	ASSERT_EQ(queue2.dtail(), 2);
	ASSERT_EQ(queue2.dhead(), 0);
	ASSERT_EQ((queue2.darr())[0].double_val, item2.double_val);
	ASSERT_EQ((queue2.darr())[0].string_val, item2.string_val);
	ASSERT_EQ((queue2.darr())[1].double_val, item4.double_val);
	ASSERT_EQ((queue2.darr())[1].string_val, item4.string_val);
}

TEST(my_queue_lib, Test_Queue_005){//оператор копирование
	Queue const_queue1(5);
	const_queue1 << item1;
	const_queue1 << item3;
	const_queue1 << item5;
	Queue queue1;
	queue1 = const_queue1;
	
	ASSERT_EQ(queue1.dnumber(), 3);
	ASSERT_EQ(queue1.dsize(), 5);
	ASSERT_EQ(queue1.dtail(), 3);
	ASSERT_EQ(queue1.dhead(), 0);
	ASSERT_EQ((queue1.darr())[0].double_val, item1.double_val);
	ASSERT_EQ((queue1.darr())[0].string_val, item1.string_val);
	ASSERT_EQ((queue1.darr())[1].double_val, item3.double_val);
	ASSERT_EQ((queue1.darr())[1].string_val, item3.string_val);
	ASSERT_EQ((queue1.darr())[2].double_val, item5.double_val);
	ASSERT_EQ((queue1.darr())[2].string_val, item5.string_val);
	
	Queue const_queue2(4);
	const_queue2 << item2;
	const_queue2 << item4;
	Queue queue2(7);
	queue2 = const_queue2;
	
	ASSERT_EQ(queue2.dnumber(), 2);
	ASSERT_EQ(queue2.dsize(), 4);
	ASSERT_EQ(queue2.dtail(), 2);
	ASSERT_EQ(queue2.dhead(), 0);
	ASSERT_EQ((queue2.darr())[0].double_val, item2.double_val);
	ASSERT_EQ((queue2.darr())[0].string_val, item2.string_val);
	ASSERT_EQ((queue2.darr())[1].double_val, item4.double_val);
	ASSERT_EQ((queue2.darr())[1].string_val, item4.string_val);
}

TEST(my_queue_lib, Test_Queue_006){//оператор перемещение
	Queue const_queue1(5);
	const_queue1 << item1;
	const_queue1 << item3;
	const_queue1 << item5;
	Queue queue1;
	queue1 = move(const_queue1);
	
	ASSERT_EQ(queue1.dnumber(), 3);
	ASSERT_EQ(queue1.dsize(), 5);
	ASSERT_EQ(queue1.dtail(), 3);
	ASSERT_EQ(queue1.dhead(), 0);
	ASSERT_EQ((queue1.darr())[0].double_val, item1.double_val);
	ASSERT_EQ((queue1.darr())[0].string_val, item1.string_val);
	ASSERT_EQ((queue1.darr())[1].double_val, item3.double_val);
	ASSERT_EQ((queue1.darr())[1].string_val, item3.string_val);
	ASSERT_EQ((queue1.darr())[2].double_val, item5.double_val);
	ASSERT_EQ((queue1.darr())[2].string_val, item5.string_val);

	ASSERT_EQ(const_queue1.dnumber(), 0);
	ASSERT_EQ(const_queue1.dsize(), 0);
	ASSERT_EQ(const_queue1.dtail(), 0);
	ASSERT_EQ(const_queue1.dhead(), 0);
	ASSERT_EQ(const_queue1.darr(), nullptr);
	
	Queue const_queue2(4);
	const_queue2 << item2;
	const_queue2 << item4;
	Queue queue2(7);
	queue2 = move(const_queue2);
	
	ASSERT_EQ(queue2.dnumber(), 2);
	ASSERT_EQ(queue2.dsize(), 4);
	ASSERT_EQ(queue2.dtail(), 2);
	ASSERT_EQ(queue2.dhead(), 0);
	ASSERT_EQ((queue2.darr())[0].double_val, item2.double_val);
	ASSERT_EQ((queue2.darr())[0].string_val, item2.string_val);
	ASSERT_EQ((queue2.darr())[1].double_val, item4.double_val);
	ASSERT_EQ((queue2.darr())[1].string_val, item4.string_val);	

	ASSERT_EQ(const_queue2.dnumber(), 0);
	ASSERT_EQ(const_queue2.dsize(), 0);
	ASSERT_EQ(const_queue2.dtail(), 0);
	ASSERT_EQ(const_queue2.dhead(), 0);
	ASSERT_EQ(const_queue2.darr(), nullptr);	
}

