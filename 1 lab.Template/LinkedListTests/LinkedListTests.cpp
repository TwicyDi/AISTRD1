#include "stdafx.h"
#include "CppUnitTest.h"
#include "..//1 lab.Template/LinkedList.h"
#include "..//1 lab.Template/LinkedList.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(add_last_element_int)
		{
			LinkedList<int> lst;
			lst.push_back(1);
			lst.push_back(2);
			Assert::IsTrue(lst.at(1) == 2 && lst.at(0)==1 && lst.get_size()==2);
		}
		TEST_METHOD(add_first_element_int)
		{
			LinkedList<int> lst;
			lst.push_front(1);
			lst.push_front(2);
			Assert::IsTrue(lst.at(0) == 2 && lst.at(1)==1 &&  lst.get_size() == 2);
		}
		TEST_METHOD(delete_last_element_int)
		{
			LinkedList<int> lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.pop_back();
			Assert::IsTrue(lst.get_size() == 1 && lst.at(0)==1);
		}
		TEST_METHOD(delete_first_element_int)
		{
			LinkedList<int> lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.pop_front();
			Assert::IsTrue(lst.get_size() == 1 && lst.at(0)==2);
		}
		
		TEST_METHOD(empty_list_int)
		{
			LinkedList<int> lst;
			Assert::IsTrue(lst.isEmpty());
		}

		TEST_METHOD(empty_list_size_int)
		{
			LinkedList<int> lst;
			Assert::IsTrue(lst.get_size() == 0);
		}

		TEST_METHOD(list_size_int)
		{
			LinkedList<int> lst;
			lst.push_front(5);
			lst.push_front(5);
			lst.push_front(5);
			Assert::IsTrue(lst.get_size() == 3);
		}

		TEST_METHOD(not_empty_list_int)
		{
			LinkedList<int> lst;
			lst.push_front(5);
			Assert::IsFalse(lst.isEmpty());
		}
		TEST_METHOD(clear_list_int)
		{
			LinkedList<int> lst;
			lst.push_front(5);
			lst.push_front(5);
			lst.push_front(5);
			lst.clear();
			Assert::IsTrue(lst.isEmpty());
		}
		TEST_METHOD(clear_empty_list_int)
		{
			LinkedList<int> lst;
			lst.clear();
			Assert::IsTrue(lst.isEmpty());
		}
		TEST_METHOD(at_list_number_int) 
		{
			LinkedList<int> lst;
			lst.push_front(1);
			Assert::IsTrue(lst.at(0) == 1);
		}
		TEST_METHOD(at_list_out_of_range_int)
		{
			LinkedList<int> lst;
			lst.push_front(1);
			lst.push_front(1);
			lst.push_front(1);
			try {
				lst.at(3);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Index is out of range", error.what());
			}
		}
		TEST_METHOD(add_last_element_char)
		{
			LinkedList<char> lst;
			lst.push_back('a');
			lst.push_back('b');
			lst.push_back('c');
			Assert::IsTrue(lst.at(2) == 'c' && lst.at(1)=='b' && lst.at(0)=='a' && lst.get_size()==3);
		}
		TEST_METHOD(add_first_element_char)
		{
			LinkedList<char> lst;
			lst.push_front('a');
			lst.push_front('b');
			lst.push_front('c');
			Assert::IsTrue(lst.at(0) == 'c' && lst.at(1)=='b' && lst.at(2)=='a');
		}
		TEST_METHOD(add_last_element_double)
		{
			LinkedList<double> lst;
			lst.push_back(1.123);
			lst.push_back(2.123);
			lst.push_back(3.123);
			Assert::IsTrue(lst.at(2) == 3.123 && lst.at(1)==2.123 && lst.at(0)==1.123 && lst.get_size()==3);
		}
		TEST_METHOD(add_first_element_double)
		{
			LinkedList<double> lst;
			lst.push_front(1.234);
			lst.push_front(2.234);
			lst.push_front(3.234);
			Assert::IsTrue(lst.at(0) == 3.234 && lst.at(1)==2.234 && lst.at(2)==1.234 && lst.get_size()==3);
		}

		TEST_METHOD(add_element_insert_int_with_push_front)
		{
			LinkedList<int> lst;
			lst.push_front(3);
			lst.push_front(2);
			lst.push_front(1);
			lst.insert(0, 5);
			Assert::IsTrue(lst.at(0) == 5 && lst.at(1) == 1 && lst.at(2) == 2 && lst.at(3) == 3 && lst.get_size() == 4);
		}

		TEST_METHOD(add_element_insert_int_with_push_back)
		{
			LinkedList<int> lst;
			lst.push_back(1);
			lst.push_back(2);
			lst.push_back(3);
			lst.insert(0, 5);
			Assert::IsTrue(lst.at(0) == 5 && lst.at(1) == 1 && lst.at(2) == 2 && lst.at(3) == 3 && lst.get_size() == 4);
		}
				
		TEST_METHOD(add_element_insert_char_with_push_back)
		{
			LinkedList<char> lst;
			lst.push_back('a');
			lst.push_back('b');
			lst.push_back('c');
			lst.insert(1, 'd');
			Assert::IsTrue(lst.at(1) == 'd'&& lst.at(0)=='a' && lst.at(2)=='b' && lst.at(3)=='c' && lst.get_size()==4);
		}
		TEST_METHOD(add_element_insert_char_with_push_front)
		{
			LinkedList<char> lst;
			lst.push_front('a');
			lst.push_front('b');
			lst.push_front('c');
			lst.insert(1, 'd');
			Assert::IsTrue(lst.at(1) == 'd' && lst.at(0)=='c' && lst.at(2)=='b' && lst.at(3)=='a' && lst.get_size()==4);
		}
		TEST_METHOD(add_element_insert_double_with_push_back)
		{
			LinkedList<double> lst;
			lst.push_back(1.123);
			lst.push_back(2.123);
			lst.push_back(3.123);
			lst.insert(2, 10.11);
			Assert::IsTrue(lst.at(2) == 10.11 && lst.at(0)==1.123 && lst.at(1)==2.123 && lst.at(3)==3.123 && lst.get_size()==4);
		}
		TEST_METHOD(add_element_insert_double_with_push_front)
		{
			LinkedList<double> lst;
			lst.push_front(1.234);
			lst.push_front(2.234);
			lst.push_front(3.234);
			lst.insert(2, 10.11);
			Assert::IsTrue(lst.at(2) == 10.11 && lst.at(0)==3.234 && lst.at(1)==2.234 && lst.at(3)==1.234 && lst.get_size()==4);
		}
		TEST_METHOD(add_element_insert_over_int)
		{
			LinkedList<int> lst;
			lst.push_front(1);
			lst.push_front(2);
			lst.push_front(3);
			lst.push_front(4);
			try {
				lst.insert(10, 5);
			}
			catch(const out_of_range& error){
				Assert::AreEqual("Index is out of range", error.what());
			}
		}
		TEST_METHOD(delete_first_element_empty_list_char)
		{
			LinkedList<char> lst;
			lst.pop_front();
			Assert::IsTrue(lst.isEmpty());
		}
		TEST_METHOD(delete_first_element_char)
		{
			LinkedList<char> lst;
			lst.push_front('a');
			lst.push_front('b');
			lst.push_front('c');
			lst.pop_front();
			Assert::IsTrue(lst.at(0) == 'b' && lst.at(1)=='a' && lst.get_size()==2);
		}
		TEST_METHOD(delete_last_element_empty_list_char)
		{
			LinkedList<char> lst;
			lst.pop_back();
			Assert::IsTrue(lst.isEmpty());
		}
		TEST_METHOD(delete_last_element_char)
		{
			LinkedList<char> lst;
			lst.push_back('a');
			lst.push_back('b');
			lst.push_back('c');
			lst.pop_back();
			Assert::IsTrue(lst.get_size()==2 && lst.at(0)=='a' && lst.at(1)=='b');
		}
		TEST_METHOD(delete_first_element_empty_list_double)
		{
			LinkedList<double> lst;
			lst.pop_front();
			Assert::IsTrue(lst.isEmpty());
		}
		TEST_METHOD(delete_first_element_double)
		{
			LinkedList<double> lst;
			lst.push_front(1.234);
			lst.push_front(2.234);
			lst.push_front(3.234);
			lst.pop_front();
			Assert::IsTrue(lst.at(0)==2.234 && lst.at(1)==1.234 && lst.get_size()==2);
		}
		TEST_METHOD(delete_last_element_empty_list_double)
		{
			LinkedList<double> lst;
			lst.pop_back();
			Assert::IsTrue(lst.isEmpty());
		}
		TEST_METHOD(delete_last_element_double)
		{
			LinkedList<double> lst;
			lst.push_back(1.123);
			lst.push_back(2.123);
			lst.push_back(3.123);
			lst.pop_back();
			Assert::IsTrue(lst.get_size()==2 && lst.at(0)==1.123 && lst.at(1)==2.123);
		}
		TEST_METHOD(set_element_int)
		{
			LinkedList<int> lst;
			lst.push_front(1);
			lst.set(0, 5);
			Assert::IsTrue(lst.at(0) == 5 && lst.get_size() == 1);
		}
		TEST_METHOD(set_element_int_over_of_range)
		{
			LinkedList<int> lst;
			lst.push_front(1);
			lst.push_front(2);
			lst.push_front(3);
			try
			{
				lst.set(5, 5);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Index is out of range", error.what());
			}
		}
		TEST_METHOD(set_element_int_empty_list)
		{
			LinkedList<int> lst;
			try
			{
				lst.set(0, 5);
			}
			catch (const std::out_of_range& error) {
				Assert::AreEqual("Index is out of range", error.what());
			}
		}

		TEST_METHOD(set_element_char)
		{
			LinkedList<char> lst;
			lst.push_front('a');
			lst.set(0, 'b');
			Assert::IsTrue(lst.at(0) == 'b' && lst.get_size() == 1);
		}

		TEST_METHOD(set_element_double)
		{
			LinkedList<double> lst;
			lst.push_front(1.23);
			lst.set(0, 12.12);
			Assert::IsTrue(lst.at(0) == 12.12 && lst.get_size() == 1);
		}
		
		TEST_METHOD(remove_element_int)
		{
			LinkedList<int> lst;
			lst.push_front(1);
			lst.push_front(2);
			lst.push_front(3);
			lst.remove(1);
			Assert::IsTrue(lst.at(0) == 3 && lst.at(1) == 1 && lst.get_size() == 2);
		}
		
		TEST_METHOD(remove_first_element_int)
		{
			LinkedList<int> lst;
			lst.push_front(1);
			lst.push_front(2);
			lst.push_front(3);
			lst.remove(0);
			Assert::IsTrue(lst.at(0) == 2 && lst.at(1) == 1 && lst.get_size() == 2);
		}
		TEST_METHOD(remove_last_element_int)
		{
			LinkedList<int> lst;
			lst.push_front(1);
			lst.push_front(2);
			lst.push_front(3);
			lst.remove(2);
			Assert::IsTrue(lst.at(0) == 3 && lst.at(1) == 2 && lst.get_size() == 2);
		}


		TEST_METHOD(remove_element_int_empty_list)
		{
			LinkedList<int> lst;
			try {
				lst.remove(1);
			}
			catch (const out_of_range& error) {
				Assert::AreEqual("Index is out of range", error.what());
			}
		}

		TEST_METHOD(remove_element_char)
		{
			LinkedList<int> lst;
			lst.push_front('c');
			lst.push_front('b');
			lst.push_front('a');
			lst.remove(1);
			Assert::IsTrue(lst.at(0) == 'a' && lst.at(1) == 'c' && lst.get_size() == 2);
		}
		TEST_METHOD(remove_element_double)
		{
			LinkedList<double> lst;
			lst.push_front(1.23);
			lst.push_front(2.23);
			lst.push_front(3.23);
			lst.remove(1);
			Assert::IsTrue(lst.at(0) == 3.23 && lst.at(1) == 1.23 && lst.get_size() == 2);
		}

	};
}