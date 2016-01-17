/*
*        Murat ALTUNTAS
*          111044043
*       HW07_111044043
*        DocumentIndex
*/

/* HW07_111044043_List.h */

#ifndef HW07_List_H
#define HW07_List_H

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include <sstream> // for istringstream
#include <string>
using namespace std;

namespace Altuntas
{
	class List
	{
	public:
		/* No parameter constructor */
		List();
		/* 2 Parameter Constructor */
		List(string word1);
		/* copy constructor */
		List(const List& other);
		/* assignment operator */
		List& operator=(const List& other);
		/* getters */
		string getWord() const {return word;}
		int getCapacity() const {return capacity;}
		int getUsed() const {return used;}
		int getLineNo() const {return lineNo;}
		int* getIndexArr() const {return indexArr;}
		/* setters */
		void setWord(const string);
		void setCapacity(const int);
		void setUsed(const int);
		void setLineNo(const int);
		/* index arrayina satir numarasi ekleme fonksiyonu */
		void addLine(int line);
		/* index arrayini siralama fonksiyonu. */
		void sortIndexArr();
		/* destructor */
		~List();

	private:
		string word; // kelime
		int* indexArr; // kelimelerin bulundugu satirin tutuldugu dizi
		int lineNo; // satir numarasi
		int capacity; // indexArr kapasitesi
		int used; // indexArr kullanilan alani
	};
}
#endif