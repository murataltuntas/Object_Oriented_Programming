/*
*        Murat ALTUNTAS
*          111044043
*       HW07_111044043
*        DocumentIndex
*/

/* HW07_111044043_DocumentIndex.cpp */

#ifndef HW07_DocumentIndex
#define HW07_DocumentIndex

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include <sstream> // for istringstream
#include <string>
#include <cstdlib> // for  exit(1);
#include "HW07_111044043_List.h"
#include "HW07_111044043_DocumentIndex.h"
using namespace std;

namespace Altuntas
{
	/* constructor */
	DocumentIndex::DocumentIndex()
	{
		fileName = "";
		usedList = 0;
		numOfWord=0;
		numOfLine=0;
		tmpUsedList=0;
	}

	/* constructor */
	DocumentIndex::DocumentIndex(string fileNm)
	{
		fileName = fileNm;
		usedList = 0;
		numOfWord=0;
		numOfLine=0;
		tmpUsedList=0;
	}
	/* copy constructor */
	DocumentIndex::DocumentIndex(const DocumentIndex & other)
	{
		fileName = other.fileName;
		numOfWord = other.numOfWord;
		numOfLine = other.numOfLine;
		capacityList = other.capacityList;
		usedList = other.usedList;
		listArr = new List[capacityList];

		for (int i = 0; i < usedList; ++i)
			listArr[i]=other.listArr[i];

	}

	/* assignment operator */
	DocumentIndex& DocumentIndex::operator=(const DocumentIndex& other)
	{
		if (capacityList!= other.capacityList)
		{
			delete[] listArr;
			listArr = new List[other.capacityList];
		}

		fileName = other.fileName;
		numOfWord = other.numOfWord;
		numOfLine = other.numOfLine;
		capacityList = other.capacityList;
		usedList = other.usedList;

		for (int i = 0; i < usedList; ++i)
			listArr[i]=other.listArr[i];

		return *this;		
	}

	/* Dosyadan okuma fonksiyonu */
	void DocumentIndex::readFile()
	{
		string line; /* bir satiri tutmak icin */
		ifstream myfile (fileName.c_str());
		if (myfile.is_open())/* dosyanin acilip acilmadigi kontrol edilir */
		{
			while(getline (myfile,line)) /* dosyadan satir satir okuma yapilir. */
			{
				numOfLine++; /* sair sayisini tutar */
				istringstream iss(line); /* cumleyi kelimelere ayiran fonksiyon */
				string word; /* bir kelimeyi tutmak icin */
				while(iss >> word) {
					numOfWord++;
				}
			}
			myfile.close(); /* dosya kapatilir */

			capacityList = numOfWord;
			listArr = new List[capacityList];
			tmpListArr = new List[capacityList];
		}
		else{
			cerr << "Unable to open file\n"; /* dosya acilmaz ise hata mesaji verir */
			exit(1); // dosya yok yada acilmaz ise cikar
		}
	}
	/* dosyaya yazma fonksiyonu */
	void DocumentIndex::writeFile(string flNm)
	{
		ofstream outStream (flNm.c_str(), ofstream::out);

		for (int i = 0; i < usedList; ++i)
		{
			outStream << listArr[i].getWord() << " ";
				 for (int j = 0; j < listArr[i].getUsed(); ++j)
				 {
				 	outStream << listArr[i].getIndexArr()[j] << " ";
				 }
			outStream << endl;
		}

		/* Dosya kapatilir */
		outStream.close();
	}
	/* listeye ekleme fonksiyonu */
	void DocumentIndex::addList()
	{
		string line; //* bir satiri tutmak icin *
		int lineCount=0;
		int wordCount=0;
		ifstream myfile (fileName.c_str());
		if (myfile.is_open())//* dosyanin acilip acilmadigi kontrol edilir *
		{
			while(getline (myfile,line)) //* dosyadan satir satir okuma yapilir. *
			{
				lineCount++; //* sair sayisini tutar *
				istringstream iss(line); //* cumleyi kelimelere ayiran fonksiyon *
				string word1; //* bir kelimeyi tutmak icin *
				while(iss >> word1) {
					listArr[wordCount].setWord(word1);
					listArr[wordCount].setLineNo(lineCount);
					wordCount++;
				}
			}
			usedList = wordCount;
			myfile.close(); //* dosya kapatilir *
		}
		else cerr << "Unable to open file\n"; //* dosya acilmaz ise hata mesaji verir *
	}
	/* listeyi siralama */
	void DocumentIndex::listSort()
	{
		int i,j; //* index *
		List tmp; //* gecici degisken *
		for(i=0; i<usedList-1; i++)
		{
			for(j=0; j<usedList-1; j++)
			{
				if(listArr[j].getWord() > listArr[j+1].getWord())
				{
					tmp = listArr[j];
					listArr[j] = listArr[j+1];
					listArr[j+1] = tmp;
				}
			}
		}
	}
	/* listeyi düzenleme fonksiyonu */
	void DocumentIndex::editList()
	{
		for (int i = 0; i < usedList; ++i)
		{
			matchList(listArr[i].getWord(), listArr[i].getLineNo());
		}

	/* kopyalama */
		for (int i = 0; i < tmpUsedList; ++i)
		{
			listArr[i] = tmpListArr[i];
		}
		usedList = tmpUsedList;

		listSort();
	}
	/* ayni kelimelerin satir sayilarini tek bir dizide toplar. */
	void DocumentIndex::matchList(string wrd, int lnNo)
	{
		bool test=true;
		/* liste boş ise ilk elemana gelen veriler atilir. */
		if (tmpUsedList == 0)
		{
			tmpListArr[0].setWord(wrd);
			tmpListArr[0].addLine(lnNo);
			tmpUsedList++;	
		}

		for (int i = 0; i < tmpUsedList; ++i)
		{
			/* kelimeler ayni ise satir numarasi diziye eklenir. */
			if(tmpListArr[i].getWord() == wrd)
			{
				tmpListArr[i].addLine(lnNo);
				test=false;
			}
		}
		/* kelimeler farkli ise listenin bir sonraki elemanina eklenir */
		if(test){
			tmpListArr[tmpUsedList].setWord(wrd);
			tmpListArr[tmpUsedList].addLine(lnNo);
			tmpUsedList++;
		}
	}

	/* parametre olarak kelime alir, kelimenin gectigi satir numaralarini dondurur. */
	int* DocumentIndex::operator[](const string myWord)
	{
		for (int i = 0; i < usedList; ++i)
		{
			if (listArr[i].getWord() == myWord)
				return listArr[i].getIndexArr();
		}
		cout << "Aranan kelime indexte bulunamadi!\n";
	}
	/* parametre olarak satir numarasi alir, o satirdaki kelimeleri dondurur. */
	string DocumentIndex::operator[](const int lineNo)
	{
		string line; /* bir satiri tutmak icin */
		ifstream myfile (fileName.c_str());
		int count=0;
		if (myfile.is_open())/* dosyanin acilip acilmadigi kontrol edilir */
		{
			while(getline (myfile,line)) /* dosyadan satir satir okuma yapilir. */
			{
				count++; /* sair sayisini tutar */
				if (count == lineNo)
				{
					myfile.close(); /* dosya kapatilir */
					return line;
				}
			}
			myfile.close(); /* dosya kapatilir */
		}
		else cerr << "Unable to open file\n"; //* dosya acilmaz ise hata mesaji verir *
		
		cout << "Aranan indexte sonuc bulunamadi!\n";
	}
	/* kelime ve onun satir numarasini ekleyen fonksiyon */
	void DocumentIndex::addWordAndLineNo(string newWord, int newLineNo)
	{
		bool test=true;

		for (int i = 0; i < usedList; ++i)
		{
			/* eklenen kelime listede var ise sadece satir numarasi eklenir */
			if(listArr[i].getWord() == newWord){
				listArr[i].addLine(newLineNo);
				test = false;
			}
		}
		
		if(test)
		{
			listArr[usedList].setWord(newWord);
			listArr[usedList].addLine(newLineNo);
			usedList++;
			listSort();
		}
	}
	
	// binary operators
	const DocumentIndex DocumentIndex::operator+(const DocumentIndex& other)
	{
		/* gecici bir obje olusturulur. */
		DocumentIndex tmpDocIn("doc3.txt");
		tmpDocIn.readFile();
		bool test=true;
		int count =0;

		tmpDocIn.capacityList = capacityList + other.capacityList;
		tmpDocIn.usedList = usedList;

		/* gecici objeye yer alinir */
		delete[] tmpDocIn.listArr;
		tmpDocIn.listArr = new List[tmpDocIn.capacityList];

		for (int i = 0; i < tmpDocIn.usedList; ++i)
		{
			tmpDocIn.listArr[i] = listArr[i];
		}

		for (int j = 0; j < other.getNumOfUsedList(); ++j)
		{
			for (int i = 0; i < tmpDocIn.usedList; ++i)
			{
				/* kelimeler ayni ise satir numarasi dizileri birleştirilir */
				if (tmpDocIn.listArr[i].getWord() == other.listArr[count].getWord())
				{
					for (int l = 0; l < other.listArr[count].getUsed(); ++l)
					{
						tmpDocIn.listArr[i].addLine(other.listArr[count].getIndexArr()[l]);
					}
					test = false;
				}
			}

			if (test)
			{
				tmpDocIn.listArr[tmpDocIn.usedList] = other.listArr[count];
				tmpDocIn.usedList++;
			}
			test = true;
			count++;
		}

		/* siralama kismi */
		int b,n; //* index *
		List tmp; //* gecici degisken *
		for(b=0; b<tmpDocIn.usedList-1; b++)
		{
			for(n=0; n<tmpDocIn.usedList-1; n++)
			{
				if(tmpDocIn.listArr[n].getWord() > tmpDocIn.listArr[n+1].getWord())
				{
					tmp = tmpDocIn.listArr[n];
					tmpDocIn.listArr[n] = tmpDocIn.listArr[n+1];
					tmpDocIn.listArr[n+1] = tmp;
				}
			}
		}

		return tmpDocIn;
	}

	// compound assignment operators
	DocumentIndex& DocumentIndex::operator+=(const DocumentIndex& other)
	{
		bool test=true;
		int count =0;

		capacityList += other.capacityList;
		List * tmpArr = new List[capacityList];
		int tmpUsed = usedList;

		for (int i = 0; i < tmpUsed; ++i)
		{
			tmpArr[i] = listArr[i];
		}

		/* listeye bastan yer alinir. */
		delete[] listArr;
		listArr = new List[capacityList];

		for (int i = 0; i < tmpUsed; ++i)
		{
			listArr[i] = tmpArr[i];
		}

		for (int j = 0; j < other.getNumOfUsedList(); ++j)
		{
			for (int i = 0; i < usedList; ++i)
			{
				if (listArr[i].getWord() == other.listArr[count].getWord())
				{
					for (int l = 0; l < other.listArr[count].getUsed(); ++l)
					{
						listArr[i].addLine(other.listArr[count].getIndexArr()[l]);
						test = false;
					}
				}
			}

			if (test)
			{
				listArr[usedList] = other.listArr[count];
				++usedList;
			}
			test = true;
			count++;
		}

		listSort();
		return *this;
	}
	
	/* print */
	void DocumentIndex::printListArr() const
	{
		for (int i = 0; i < usedList; ++i)
		{
			cout << listArr[i].getWord() << " ";
				 for (int j = 0; j < listArr[i].getUsed(); ++j)
				 {
				 	cout << listArr[i].getIndexArr()[j] << " ";
				 }
			cout << endl;
		}
	}

	/*Uses iostream - ostream functions*/
	ostream& operator <<(ostream& outs, const DocumentIndex& other)
	{
		other.printListArr();
		return outs;
	}

	istream& operator >>(std::istream& ins, DocumentIndex& other)
	{
		string fName; // Dosya adi
		ins >> fName; // dosya adi alinir
		DocumentIndex tmp(fName); // gecici obje olusturulur
		tmp.readFile();
		tmp.addList();
		tmp.editList();
		tmp.listSort();
		other = tmp; // gercek objeye atama yapilir.
		return ins;
	}

	/* destructor */
	DocumentIndex::~DocumentIndex()
	{
		delete[] listArr;
		delete[] tmpListArr;
	}
}
#endif