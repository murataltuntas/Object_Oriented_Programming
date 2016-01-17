/*
*        Murat ALTUNTAS
*          111044043
*       HW07_111044043
*        DocumentIndex
*/

/* HW07_111044043_List.cpp */

#ifndef HW07_List
#define HW07_List

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include <sstream> // for istringstream
#include <string>
#include "HW07_111044043_List.h"
using namespace std;

namespace Altuntas
{
	/* parametresiz constructor */
	List::List()
	{
		word = "";
		capacity = 100;
		used = 0;
		lineNo = 0;
		
		indexArr = new int[capacity];
	}

	/* tek parametreli (string alan) constructor */
	List::List(string word1)
	{
		word = word1;
		capacity = 100;
		used = 0;
		lineNo = 0;
		
		indexArr = new int[capacity];
	}

	/* copy constructor */
	List::List(const List& other)
	{
		capacity = other.capacity;
		used = other.used;
		word = other.word;
		lineNo = other.lineNo;
		indexArr = new int[capacity];
		for (int i = 0; i < used; ++i)
			indexArr[i] = other.indexArr[i];
	}
	/* index arrayina satir numarasi ekleme fonksiyonu */
	void List::addLine(int line)
	{
		indexArr[used] = line;
		used++;
		sortIndexArr();
	}
	/* index arrayini siralama fonksiyonu. */
	void List::sortIndexArr()
	{
		int i,j; //* index *
		int tmp; //* gecici degisken *
		for(i=0; i<used-1; i++) {
			for(j=0; j<used-1; j++) {
				if(indexArr[j] > indexArr[j+1])
				{
					tmp = indexArr[j];
					indexArr[j] = indexArr[j+1];
					indexArr[j+1] = tmp;
				}
			}
		}
	}
	/* assignment operator */
	List& List::operator=(const List& other)
	{
		if (capacity != other.capacity)
		{
			delete [] indexArr;
			indexArr = new int[other.capacity];
		}

		word = other.word;
		lineNo = other.lineNo;
		capacity = other.capacity;
		used = other.used;
		for (int i = 0; i < used; ++i)
			indexArr[i] = other.indexArr[i];

		return *this;
	}

	/* setters */
	void List::setWord(const string strWrd)
	{
			word = strWrd;
	}
	void List::setCapacity(const int tmpCpcty)
	{
		if (tmpCpcty >= 0)
		{
			capacity = tmpCpcty;
		}
		else
			capacity = 0;
	}
	void List::setLineNo(const int tmplnn)
	{
			lineNo = tmplnn;
	}
	void List::setUsed(const int tmpUsd)
	{
		if (tmpUsd >= 0)
		{
			used = tmpUsd;
		}
		else
			used = 0;
	}
	/* destructor */
	List::~List()
	{
		delete[] indexArr;
	}
}
#endif