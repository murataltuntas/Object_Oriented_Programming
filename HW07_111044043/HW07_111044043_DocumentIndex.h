/*
*        Murat ALTUNTAS
*          111044043
*       HW07_111044043
*        DocumentIndex
*/

/* HW07_111044043_DocumentIndex.h */

#ifndef HW07_DocumentIndex_H
#define HW07_DocumentIndex_H

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include <sstream> // for istringstream
#include <string>
#include "HW07_111044043_List.h"
using namespace std;

namespace Altuntas
{
	class DocumentIndex
	{
	public:
		/* constructors */
		DocumentIndex();
		DocumentIndex(string);
		/* copy constructors */
		DocumentIndex(const DocumentIndex & other);
		/* getters */
		int getNumOfWord() const {return numOfWord;}
		int getNumOfLine() const {return numOfLine;}
		int getNumOfCapacityList() const {return capacityList;}
		int getNumOfUsedList() const {return usedList;}
		/* assignment operator */
		DocumentIndex& operator=(const DocumentIndex& other);
		/* parametre olarak kelime alir, kelimenin gectigi satir numaralarini dondurur. */
		int* operator[](const string word);
		/* parametre olarak satir numarasi alir, o satir da bulunan kelimeleri dondurur. */
		string operator[](const int lineNumber);
		// binary operators
		const DocumentIndex operator+(const DocumentIndex& other);
		// compound assignment operators
		DocumentIndex& operator+=(const DocumentIndex& other);
		/* i/ostream functions */
		friend std::ostream& operator<<(std::ostream& outs, const DocumentIndex& other);
		friend std::istream& operator>>(std::istream& ins, DocumentIndex& other);
		/* Dosyadan okuma fonksiyonu */
		void readFile();
		/* Dosyaya yazma fonksiyonu */
		void writeFile(string);
		/* listeye ekleme fonksiyonu */
		void addList();
		/* listedeki ayni kelimeleri kaldirip duzenli liste olusturma fonksiyonu */
		void editList();
		/* kelime ve onun satir numarasini ekleyen fonksiyon */
		void addWordAndLineNo(string, int);
		/* destructor */
		~DocumentIndex();
	private:
		string fileName; // dosya adi
		int numOfWord; // kelime sayisi
		int numOfLine; // satir sayisi

		List* listArr; /* stringlerin ve lineNo larin atildigi liste */
		int usedList; /* listenin kullanilan kismi */
		int capacityList; /* listenin kapasitesi */

		List* tmpListArr; /* stringlerin ve lineNo larin atildigi liste */
		int tmpUsedList; /* listenin kullanilan kismi */

		/* print list */
		void printListArr() const;
		/* edit list yardimci fonksiyonu */
		void matchList(string wrd, int lnNo);
		/* listeyi siralama */
		void listSort();
	};
}
#endif