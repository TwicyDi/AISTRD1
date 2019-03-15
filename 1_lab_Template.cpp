#include "stdafx.h"
#include <iostream>
#include "LinkedList.h"
#include "LinkedList.cpp"
#include <cstdlib>
#include <Windows.h>
using namespace std;

void text()
{
	cout << "Laboratory work 1 \"List template class\"\nShchebet Diana gr.7302 var. 2\n";
	cout << "\n1. Add the element into the end of the list\n";
	cout << "2. Add the element into the beginning of the list\n";
	cout << "3. Remove the last list element \n";
	cout << "4. Remove the first list element\n";
	cout << "5. Add the element by index\n";
	cout << "6. Get the element by index\n";
	cout << "7. Remove the element by index\n";
	cout << "8. Get the list size\n";
	cout << "9. Print list elements\n";
	cout << "10. Clear the list\n";
	cout << "11. Replace the element by index\n";
	cout << "12. Is the list empty?\n";

	cout << "\nAdditional function:\n-1. Close the programm\n-2. Clear extra text\n";
}

int main()
{
	LinkedList<double> lst;
	int option;
	text();

	do {
		double element;
		int index;
		int index1;
		cout << "\nEnter option: "; cin >> option;
		switch (option)
		{
		case -2: system("cls"); text(); break;
		case -1: break;
		case 1: cout << "Enter the element: "; cin >> element; lst.push_back(element); break;
		case 2: cout << "Enter the element: "; cin >> element; lst.push_front(element); break;
		case 3: lst.pop_back(); break;
		case 4: lst.pop_front(); break;
		case 5: cout << "Enter the element: "; cin >> element; cout << "Enter the index: "; cin >> index; lst.insert(index, element); break;
		case 6: cout << "Enter the index: "; cin >> index; 
			try { lst.at(index); }
			catch (const out_of_range& error) {
				if (lst.size == 0) { cout << "List is empty. Add some elements to use this function" << endl; break; }
				else if (index < 0) { cout << "You entered a negative number, the index will be reduced to zero\n" << lst.at(0); break; }
				else if (index >= lst.size) { cout << "You entered a number outside the list, it will be equal to the index of the last element of the list\n" << lst.at(lst.size - 1); break; }
			}
			cout << lst.at(index) << endl; break;
		case 7: cout << "Enter the index: "; cin >> index; lst.remove(index); break;
		case 8: cout << "List size is " << lst.get_size() << endl; break;
		case 9: lst.Print_List(); break;
		case 10: lst.clear(); break;
		case 11: cout << "\nEnter the element: "; cin >> element; cout << "Enter the index: "; cin >> index; lst.set(index, element); break;
		case 12: (lst.isEmpty() == 0) ? cout << "No" : cout << "Yes"; cout << endl; break;
		}
	} while (option != -1);
	system("cls");


	return 0;
}
