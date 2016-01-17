/*
*        Murat ALTUNTAS
*          111044043
*       HW08_111044043
*          Container
*
* HW08_111044043_SortedSetContainer.h
*/
#ifndef HW08_SORTED_SET_CONTAINER_H
#define HW08_SORTED_SET_CONTAINER_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "HW08_111044043_Container.h"
#include "HW08_111044043_Container.cpp"
using namespace std;

namespace Altuntas {
	template<class T>
	class SortedSetContainer : public Container<T>
	{
	public:
		SortedSetContainer();
		/* container a eleman ekleme fonksiyonu */
		void add(T elm);
		/* container dan eleman cikarma fonksiyonu */
		void remove(T elm);
		/* container da eleman arama fonksiyonu */
		int search(T elm);
		/* container in ilk elemanini dondurur */
		T first();
		/* container in sonraki elemanini dondurur */
		T next();
		/* return the container size */
		int contSize() const;
	};
}
#endif