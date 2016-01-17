/*
*        Murat ALTUNTAS
*          111044043
*       HW08_111044043
*          Container
*
* HW08_111044043_SortedContainer.cpp
*/
#ifndef HW08_SORTED_CONTAINER_CPP
#define HW08_SORTED_CONTAINER_CPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "HW08_111044043_SortedContainer.h"
using namespace std;
/************************************************/
/*************** SortedContainer ****************/
/************************************************/
namespace Altuntas {
	/* Constructor */
	template<class T>
	SortedContainer<T>::SortedContainer( ) : Container<T>()
	{
		Container<T>::isSortedObject = true;
		Container<T>::isSetObject = false;
	}

	/* container a eleman ekleme fonksiyonu */
	template<class T>
	void SortedContainer<T>::add(T elm)
	{
		if (sizeof(elm)!=sizeof(T))
			throw out_of_range("SetContainer::search(T elm): type mismatch");
		
		/* push_back() fonksiyonunun firlatabilecegi
		bad_alloc exception u icin main e catch eklenmistir. */
		Container<T>::elems.push_back(elm);
		Container<T>::sort();
	}

	/* container da eleman arama fonksiyonu */
	template<class T>
	int SortedContainer<T>::search(T elm)
	{
		if (Container<T>::elems.empty())
			throw out_of_range("SortedContainer::search(T elm): empty container");

		for (int i = 0; i < contSize(); ++i)
			if (Container<T>::elems[i] == elm)
				return i;

		throw out_of_range("SortedContainer::search(T elm): element not found");
	}

	/* container dan eleman cikarma fonksiyonu */
	template<class T>
	void SortedContainer<T>::remove(T elm)
	{
		if (Container<T>::elems.empty())
			throw out_of_range("SortedContainer::remove(T elm): empty container"); 

		// erase the element
		Container<T>::elems.erase (Container<T>::elems.begin()+(search(elm)));
	}

	/* container in ilk elemanini dondurur */
	template<class T>
	T SortedContainer<T>::first()
	{
		if (Container<T>::elems.empty())
			throw out_of_range("SortedContainer::first(): empty container");

		Container<T>::nextCount = 0;
		return Container<T>::elems.at(Container<T>::nextCount);
	}
	/* container in sonraki elemanini dondurur */
	template<class T>
	T SortedContainer<T>::next()
	{
		Container<T>::nextCount++;
		return Container<T>::elems.at(Container<T>::nextCount);
	}
	/* return the container size */
	template<class T>
	int SortedContainer<T>::contSize() const
	{
		return Container<T>::elems.size();
	}
}
#endif