/*
*        Murat ALTUNTAS
*          111044043
*       HW07_111044043
*        DocumentIndex
*/

/* HW07_111044043_TEST.cpp */
#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include <sstream> // for istringstream
#include <string>
#include "HW07_111044043_List.h"
#include "HW07_111044043_DocumentIndex.h"
using namespace std;
using namespace Altuntas;

int main()
{
	DocumentIndex document1("doc1.txt");

	document1.readFile();
	document1.addList();
	document1.editList();

	DocumentIndex document2("doc2.txt");

	document2.readFile();
	document2.addList();
	document2.editList();

	DocumentIndex document3("doc3.txt");

	document3.readFile();
	document3.addList();
	document3.editList();

//	cout << document1;
	document1.writeFile("output1.txt");

	/* index e yeni kelimeler ve satir numaralari eklenir. */
	document2.addWordAndLineNo("murat" ,13);
	document2.addWordAndLineNo("vulputate" ,44);
//	cout << document2;
	document2.writeFile("output2.txt");

	cout << "\nDosya adi giriniz: ";
	cin >> document3;
	cout << document3;
	document3.writeFile("output3.txt");

	/* += operatorunun testi */
	document3 += document2;
	document3.writeFile("output4.txt");

	/* + operatorunun testi */
	document1 = document1 + document2;
	document1.writeFile("output5.txt");

	/* satir numarasi alan index operatorunun testi */
	cout << endl << "document 3  -  5. satir: " << document3[5] << endl;

	/* string alan index operatorunun testi */
	/* girilen string in gectigi satirlardaki satir
	   numaralarindan olusan bir dizi dondurur. */
	int* ptr = document1["mauris"];
	cout << endl << "string in gectigi ilk satir: " << *ptr << endl;

	return 0;
}