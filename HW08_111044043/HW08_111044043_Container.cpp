/*
*        Murat ALTUNTAS
*          111044043
*       HW08_111044043
*          Container
*
* HW08_111044043_Container.cpp
*/

#ifndef HW08_CONTAINER_CPP
#define HW08_CONTAINER_CPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "HW08_111044043_Container.h"
using namespace std;

/************************************************/
/***************** Container ********************/
/************************************************/
/* other Container i member Container a ekler */
namespace Altuntas {
	template<class T>
	void Container<T>::addAll(const Container& other)
	{
		/* secilen obje set claslarindan birine ait
		ise ayni elemanlari tekrar eklemeyi engeller */
		if(isSetObject == true)
			for (int j = 0; j < other.contSize(); ++j)
			{
				int i, gecici = -1;
				for (i = 0; i < contSize(); ++i)
					if (elems[i] == other.elems[j])
						gecici = i;

				if (gecici == -1)
					elems.push_back(other.elems[j]);
			}
		else
			for (int j = 0; j < other.contSize(); ++j)
			{
				elems.push_back(other.elems[j]);
			}

		if (isSortedObject)
		{
			sort();
		}
	}
	/* Container in butun elemanlarini siler */
	template<class T>
	void Container<T>::removeAll()
	{
		elems.clear();
	}
	/* container in vectorunu return eder */
	template<class T>
	vector<T> Container<T>::toVector() const
	{
		return elems;
	}
	/* print */
	template<class T>
	void Container<T>::print()
	{
		for (unsigned i=0; i < elems.size(); i++)
			cout << ' ' << elems[i];
		cout << "\n";
	}

	/* container elemanlarini siralayan fonksiyon */
	template<class T>
	void Container<T>::sort()
	{
		bool control=true;
		while (control)
		{
			control=false;
			for (int j = 0; j < contSize()-1; ++j)
			{
				if (elems.at(j) > elems.at(j+1))
				{
					swapValues(elems.at(j), elems.at(j+1));
					control=true;
				}
				
			}
		}
	}
	/* swap fonksiyonu */
	template<class T>
	void Container<T>::swapValues( T& variable1, T& variable2)
	{
		T temp;
		temp = variable1;
		variable1 = variable2;
		variable2 = temp;
	}

	/************************************************/
	/************** Global Function *****************/
	/************************************************/
	/* return the number of sorted container object */
	template <typename T>
	int numOfSortCont(const Container<T>& other)
	{
		/* secilen obje sorted class larindan birine ait ise */
		if (other.SortedObject())
		{
			return other.contSize();
		}
		
	}
}
#endif