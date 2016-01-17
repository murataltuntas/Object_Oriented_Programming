/*
*        Murat ALTUNTAS
*          111044043
*       HW08_111044043
*          Container
*
* HW08_111044043_Container.h
*/
#ifndef HW08_CONTAINER_H
#define HW08_CONTAINER_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
using namespace std;

namespace Altuntas {
	template<class T>
	class Container
	{
	public:
	//	Container();
		/* container a eleman ekleme fonksiyonu */
		virtual void add(T elm) = 0;
		/* container dan eleman cikarma fonksiyonu */
		virtual void remove(T elm) = 0;
		/* container da eleman arama fonksiyonu */
		virtual int search(T elm) = 0;
		/* container in ilk elemanini dondurur */
		virtual T first() = 0;
		/* container in sonraki elemanini dondurur */
		virtual T next() = 0;
		/* return the container size */
		virtual int contSize() const = 0;
		/* print */
		void print();
		/* other Container i member Container a ekler */
		void addAll(const Container& other);
		/* Container in butun elemanlarini siler */
		void removeAll();
		/* container in vectorunu return eder */
		vector<T> toVector() const;
		/* container elemanlarini siralayan fonksiyon */
		void sort();
		/* swap fonksiyonu */
		void swapValues( T& variable1, T& variable2);
		/* sorted object kontrolu icin gerekli fonksiyon */
		bool SortedObject() const {return isSortedObject;}
		/* set object kontrolu icin gerekli fonksiyon */
		bool SetObject() const {return isSetObject;}
		/* get vector */
		vector<T> getElemsVect() const {return elems;}
	protected:
		vector<T> elems; // elements
		bool isSortedObject; /* obje Sorted classlarindan birine mi ait */
		bool isSetObject; /* obje Set classlarindan birine mi ait */
		int nextCount; /* next fonksiyonu icin gerekli counter. */

	};

	/* return the number of sorted container object elements */
	template <typename T>
	int numOfSortCont(const Container<T>& other);
}
#endif