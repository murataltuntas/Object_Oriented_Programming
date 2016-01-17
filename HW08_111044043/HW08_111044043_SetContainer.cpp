/*
*        Murat ALTUNTAS
*          111044043
*       HW08_111044043
*          Container
*
* HW08_111044043_SetContainer.cpp
*/
#ifndef HW08_SET_CONTAINER_CPP
#define HW08_SET_CONTAINER_CPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "HW08_111044043_SetContainer.h"
using namespace std;

/************************************************/
/*************** SetContainer *******************/
/************************************************/
/* Constructor */
namespace Altuntas {
	template<class T>
	SetContainer<T>::SetContainer( ) : Container<T>()
	{
		Container<T>::isSortedObject = false;
		Container<T>::isSetObject = true;
	}

	/* container a eleman ekleme fonksiyonu */
	template<class T>
	void SetContainer<T>::add(T elm)
	{
		if (sizeof(elm)!=sizeof(T))
			throw out_of_range("SetContainer::search(T elm): type mismatch");

			int i, gecici = -1;
		/* eklenecek olan eleman daha once
		container da varmi diye kontrol edilir. */
		for (i = 0; i < contSize(); ++i)
			if (Container<T>::elems[i] == elm)
				gecici = i;

		/* yok ise eklenir. */
		if (gecici == -1)
		{
			/* push_back() fonksiyonunun firlatabilecegi
			bad_alloc exception u icin main e catch eklenmistir. */
			Container<T>::elems.push_back(elm);
		}
	}

	/* container da eleman arama fonksiyonu */
	template<class T>
	int SetContainer<T>::search(T elm)
	{
		/* container bos ise exception firlatir. */
		if (Container<T>::elems.empty())
			throw out_of_range("SetContainer::search(T elm): empty container");

		for (int i = 0; i < contSize(); ++i)
			if (Container<T>::elems[i] == elm)
				return i;
		/* container da eleman bulunamaz ise exception firlatir. */
		throw out_of_range("SetContainer::search(T elm): element not found");
	}

	/* container dan eleman cikarma fonksiyonu */
	template<class T>
	void SetContainer<T>::remove(T elm)
	{
		/* container bos ise exception firlatir. */
		if (Container<T>::elems.empty())
			throw out_of_range("SetContainer::remove(T elm): empty container"); 

		// erase the element
		Container<T>::elems.erase (Container<T>::elems.begin()+(search(elm)));
	}

	/* container in ilk elemanini dondurur */
	template<class T>
	T SetContainer<T>::first()
	{
		/* container bos ise exception firlatir. */
		if (Container<T>::elems.empty())
			throw out_of_range("SetContainer::first(): empty container");

		Container<T>::nextCount = 0;
		return Container<T>::elems.at(Container<T>::nextCount);
	}
	/* container in sonraki elemanini dondurur */
	template<class T>
	T SetContainer<T>::next()
	{
		Container<T>::nextCount++;
		return Container<T>::elems.at(Container<T>::nextCount);
	}
	/* return the container size */
	template<class T>
	int SetContainer<T>::contSize() const
	{
		return Container<T>::elems.size();
	}
}
#endif