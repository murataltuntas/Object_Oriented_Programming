/*
*        Murat ALTUNTAS
*          111044043
*       HW08_111044043
*          Container
*
* HW08_111044043_Test.cpp
*/
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

#ifndef SET_CONTAINER_H
#include "HW08_111044043_SetContainer.h"
#include "HW08_111044043_SetContainer.cpp"
#endif
#ifndef SORTED_CONTAINER_H
#include "HW08_111044043_SortedContainer.h"
#include "HW08_111044043_SortedContainer.cpp"
#endif
#ifndef SORTED_SET_CONTAINER_H
#include "HW08_111044043_SortedSetContainer.h"
#include "HW08_111044043_SortedSetContainer.cpp"
#endif

using namespace std;
using namespace Altuntas;

int main()
{
	try {
		try{
		/************************************************/
		/***************** SetContainer *****************/
		/************************************************/
		cout << "************** char **************\n";
		SetContainer<char> mySetContainer;

		/* eleman ekleme */
		mySetContainer.add('g');
		mySetContainer.add('e');
		mySetContainer.add('a');
		mySetContainer.add('c');
		mySetContainer.add('d');
		mySetContainer.add('b');
		mySetContainer.add('d');
		mySetContainer.add('a');
		mySetContainer.add('h');
		mySetContainer.add('f');

		/* eleman silme */
		mySetContainer.remove('f');

		cout << "mySetContainer contains:";
		mySetContainer.print();

		/* eleman arama */
		cout << "'b' is " << mySetContainer.search('b') << ". elements in container.\n\n";

		/************************************************/
		/************** SortedSetContainer **************/
		/************************************************/
		SortedSetContainer<char> mySortedSetContainer;

		/* eleman ekleme */
		mySortedSetContainer.add('g');
		mySortedSetContainer.add('e');
		mySortedSetContainer.add('a');
		mySortedSetContainer.add('c');
		mySortedSetContainer.add('d');
		mySortedSetContainer.add('b');
		mySortedSetContainer.add('d');
		mySortedSetContainer.add('a');
		mySortedSetContainer.add('h');
		mySortedSetContainer.add('f');

		/* eleman silme */
		mySortedSetContainer.remove('f');

		cout << "mySortedSetContainer contains:";
		mySortedSetContainer.print();

		/* eleman arama */
		cout << "'b' is " << mySortedSetContainer.search('b') << ". elements in container.\n\n";

		/************************************************/
		/**************** SortedContainer ***************/
		/************************************************/
		SortedContainer<char> mySortedContainer;

		/* eleman ekleme */
		mySortedContainer.add('g');
		mySortedContainer.add('e');
		mySortedContainer.add('a');
		mySortedContainer.add('c');
		mySortedContainer.add('j');
		mySortedContainer.add('d');
		mySortedContainer.add('b');
		mySortedContainer.add('d');
		mySortedContainer.add('a');
		mySortedContainer.add('h');
		mySortedContainer.add('f');

		/* eleman silme */
		mySortedContainer.remove('f');

		cout << "mySortedContainer contains:";
		mySortedContainer.print();

		/* eleman arama */
		cout << "'b' is " << mySortedContainer.search('b') << ". elements in container.\n\n";

		/* global fonksiyon testi */
		cout << "Number of SortedSetContainer Object Elements: " << numOfSortCont(mySortedSetContainer) << endl;
		cout << "Number of SortedContainer Object Elements: " << numOfSortCont(mySortedContainer) << endl;
		cout << "\n";

		/* firs() ve next() fonksiyonlarinin testi */
		cout << "Sorted Set Container first element: " << mySortedSetContainer.first() << endl;
		cout << "Sorted Set Container next element: " << mySortedSetContainer.next() << endl;
		cout << "Sorted Set Container next element: " << mySortedSetContainer.next() << endl;

		/* iki container i birlestirme */
		cout << "\nmySetContainer.addAll(mySortedContainer): ";
		mySetContainer.addAll(mySortedContainer);
		mySetContainer.print();

		cout << "mySortedContainer.addAll(mySetContainer):";
		mySortedContainer.addAll(mySetContainer);
		mySortedContainer.print();

		/* toVector() testi */
		cout << "mySortedSetContainer.toVector():";
		mySortedSetContainer.toVector();
		mySortedSetContainer.print();

		/* containerdaki butun elemanlari silme */
		cout << "mySortedSetContainer.removeAll():";
		mySortedSetContainer.removeAll();
		mySortedSetContainer.print();
		
		} 
		catch (exception const& ex) { 
			cerr << "Exception: " << ex.what() <<endl; 
		}
	}
	catch (bad_alloc& ba) {
		cerr << "bad_alloc caught: " << ba.what() << endl;
	}

    try{
    	try{
		/************************************************/
		/***************** SetContainer *****************/
		/************************************************/
		cout << "\n************** int **************\n";
		SetContainer<int> mySetContainer2;

		/* eleman ekleme */
		mySetContainer2.add(6);
		mySetContainer2.add(7);
		mySetContainer2.add(9);
		mySetContainer2.add(8);
		mySetContainer2.add(2);
		mySetContainer2.add(1);
		mySetContainer2.add(4);
		mySetContainer2.add(2);
		mySetContainer2.add(5);
		mySetContainer2.add(24);
		mySetContainer2.add(4);

		cout << "mySetContainer contains:";
		mySetContainer2.print();

		/* eleman arama */
		cout << "'2' is " << mySetContainer2.search(2) << ". elements in container.\n\n";

		/************************************************/
		/************** SortedSetContainer **************/
		/************************************************/
		SortedSetContainer<int> mySortedSetContainer2;

		/* eleman ekleme */
		mySortedSetContainer2.add(6);
		mySortedSetContainer2.add(7);
		mySortedSetContainer2.add(9);
		mySortedSetContainer2.add(8);
		mySortedSetContainer2.add(2);
		mySortedSetContainer2.add(11);
		mySortedSetContainer2.add(4);
		mySortedSetContainer2.add(2);
		mySortedSetContainer2.add(15);
		mySortedSetContainer2.add(4);
		mySortedSetContainer2.add(8);
		mySortedSetContainer2.add(2);
		mySortedSetContainer2.add(1);
		mySortedSetContainer2.add(4);

		cout << "mySortedSetContainer contains:";
		mySortedSetContainer2.print();

		/* eleman arama */
		cout << "'2' is " << mySortedSetContainer2.search(2) << ". elements in container.\n\n";

		/************************************************/
		/**************** SortedContainer ***************/
		/************************************************/
		SortedContainer<int> mySortedContainer2;

		/* eleman ekleme */
		mySortedContainer2.add(6);
		mySortedContainer2.add(7);
		mySortedContainer2.add(9);
		mySortedContainer2.add(8);
		mySortedContainer2.add(12);
		mySortedContainer2.add(1);
		mySortedContainer2.add(4);
		mySortedContainer2.add(2);
		mySortedContainer2.add(5);
		mySortedContainer2.add(4);
		mySortedContainer2.add(19);
		mySortedContainer2.add(8);
		mySortedContainer2.add(2);
		mySortedContainer2.add(1);

		cout << "mySortedContainer contains:";
		mySortedContainer2.print();

		/* eleman arama */
		cout << "'2' is " << mySortedContainer2.search(22) << ". elements in container.\n\n";

		} 
		catch (exception const& ex) { 
			cerr << "Exception: " << ex.what() <<endl; 
		}
	}
    catch (bad_alloc& ba)
	{
		cerr << "bad_alloc caught: " << ba.what() << endl;
	}
	return 0;
}