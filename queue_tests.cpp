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

TEST(my_queue_lib, Test_Queue_000){
	Queue queue;

	ASSERT_FALSE(queue << item1);
	ASSERT_FALSE(queue << item2);
	ASSERT_FALSE(queue << item3);
	ASSERT_FALSE(queue << item4);
	ASSERT_TRUE(queue << item5);
}

TEST(my_queue_lib, Test_Queue_001){
	Queue queue(item1, item2, item3, item4);
	Item item;

	ASSERT_TRUE(!(queue >> item) and item == item1);
	ASSERT_TRUE(!(queue >> item) and item == item2);
	ASSERT_TRUE(!(queue >> item) and item == item3);
	ASSERT_TRUE(!(queue >> item) and item == item4);
	ASSERT_TRUE(queue >> item);
}

TEST(my_queue_lib, Test_Queue_002){
	Queue queue1;
	Queue queue2(item1);
	Queue queue3(item1, item2, item3, item4);

	ASSERT_EQ(!queue1, 1);
	ASSERT_EQ(!queue2, 0);
	ASSERT_EQ(!queue3, 2);
}





