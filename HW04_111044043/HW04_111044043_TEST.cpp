/*
*        Murat ALTUNTAS
*          111044043
*       HW04_111044043
*   Game of life with Class
*/

/* HW04_111044043_TEST.cpp */
#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include <vector>
#include "HW04_111044043.h"
using namespace std;

int main()
{
	char inFileName[256];  // input file name
	char outFileName[256]; // output file name
	int numOfStep; // step sayisi
	char endGame; // oyun secme ve bitirme icin gerekli degisken

	GameOfLife oyun1;
	GameOfLife oyun2;
	GameOfLife oyun3;
	GameOfLife oyun4;
	GameOfLife oyun5;

	/* dosya okuma duzgun gerceklesmedigi surece tekrar eden dongu */
	do{
		cout << "Entry File Name Game 1: ";
		cin >> inFileName;
	}while(oyun1.readFile(inFileName)  == false);

	/* dosya okuma duzgun gerceklesmedigi surece tekrar eden dongu */
	do{
		cout << "Entry File Name Game 2: ";
		cin >> inFileName;
	}while(oyun2.readFile(inFileName)  == false);

	/* dosya okuma duzgun gerceklesmedigi surece tekrar eden dongu */
	do{
		cout << "Entry File Name Game 3: ";
		cin >> inFileName;
	}while(oyun3.readFile(inFileName)  == false);

	/* dosya okuma duzgun gerceklesmedigi surece tekrar eden dongu */
	do{
		cout << "Entry File Name Game 4: ";
		cin >> inFileName;
	}while(oyun4.readFile(inFileName)  == false);

	/* dosya okuma duzgun gerceklesmedigi surece tekrar eden dongu */
	do{
		cout << "Entry File Name Game 5: ";
		cin >> inFileName;
	}while(oyun5.readFile(inFileName)  == false);

	cout << "---- Game 1 ----\n";
	oyun1.printBoard();

	cout << "---- Game 2 ----\n";
	oyun2.printBoard();

	cout << "---- Game 3 ----\n";
	oyun3.printBoard();

	cout << "---- Game 4 ----\n";
	oyun4.printBoard();

	cout << "---- Game 5 ----\n";
	oyun5.printBoard();

	cout << "\nilk adimi hangi oyun ile yapmak istersiniz?\n";
	cout << "Game 1 icin A ya \nGame 2 icin B ye \n";
	cout << "Game 3 icin C ye \nGame 4 icin D ye\n";
	cout << "Game 5 icin E ye basiniz!\n";
	cout << "Herhangi bir oyunu yeniden boyutlandirmak icin R ye basiniz!\n";
	cout << "Oyunlardan cikmak istiyorsaniz Q ya basiniz!\n";
	cout << "Lutfen secim yapiniz: ";
	cin >> endGame;

	do
	{
		if ((endGame == 'A') || (endGame == 'a'))
			{
				oyun1.play();
				oyun1.printBoard();
				cout << "Bir sonraki adimi seciniz: ";
			}
		else if ((endGame == 'B') || (endGame == 'b'))
			{
				oyun2.play();
				oyun2.printBoard();
				cout << "Bir sonraki adimi seciniz: ";
			}
		else if ((endGame == 'C') || (endGame == 'c'))
			{
				oyun3.play();
				oyun3.printBoard();
				cout << "Bir sonraki adimi seciniz: ";
			}
		else if ((endGame == 'D') || (endGame == 'd'))
			{
				oyun4.play();
				oyun4.printBoard();
				cout << "Bir sonraki adimi seciniz: ";
			}
		else if ((endGame == 'E') || (endGame == 'e'))
			{
				oyun5.play();
				oyun5.printBoard();
				cout << "Bir sonraki adimi seciniz: ";
			}
		else if ((endGame == 'R') || (endGame == 'r'))
			{
				cout << "\nYeniden boyutlandirilacak oyunu seciniz!\n";
				cout << "Game 1 icin A ya \nGame 2 icin B ye\n";
				cout << "Game 3 icin C ye \nGame 4 icin D ye\n";
				cout << "Game 5 icin E ye basiniz!\n";
				cin >> endGame;
				if ((endGame == 'A') || (endGame == 'a'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun1.setRow(tmpRow);
					oyun1.setColumn(tmpClmn);
					oyun1.printBoard();
				}
				else if ((endGame == 'B') || (endGame == 'b'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun2.setRow(tmpRow);
					oyun2.setColumn(tmpClmn);
					oyun2.printBoard();
				}
				else if ((endGame == 'C') || (endGame == 'c'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun3.setRow(tmpRow);
					oyun3.setColumn(tmpClmn);
					oyun3.printBoard();
				}
				else if ((endGame == 'D') || (endGame == 'd'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun4.setRow(tmpRow);
					oyun4.setColumn(tmpClmn);
					oyun4.printBoard();
				}
				else if ((endGame == 'E') || (endGame == 'e'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun5.setRow(tmpRow);
					oyun5.setColumn(tmpClmn);
					oyun5.printBoard();
				}
				else
					cout << "\nSectiginiz Oyun Bulunmamaktadir!\n";
				cout << "Bir sonraki adimi seciniz: ";
			}
		else if ((endGame == 'Q') || (endGame == 'q'))
			break;
		else
			cout << "\nYanlis karakter girdiniz Lutfen tekrar deneyin: ";
		
		cin >> endGame;

	}while(endGame);

	oyun1.addLiveCell(oyun2);

	cout << "\n2. oyundaki canli hucreler 1. oyuna eklenirse.\n";
	oyun1.printBoard();

	cout << "Game 2 Row   : " << oyun1.returnRow(oyun2);
	cout << "\nGame 2 Column: " << oyun1.returnColumn(oyun2);

	cout << "\nnumber of living Cells: " << GameOfLife::totalNumOfLiveCell() << endl;
	
	/* final board'i output dosyasina yazma kismi */
	cout << "\nEntry Final Board Output File Name for Game 1: ";
	cin >> outFileName;
	oyun1.writeFile(outFileName);
	
	/* final board'i output dosyasina yazma kismi */
	cout << "\nEntry Final Board Output File Name for Game 2: ";
	cin >> outFileName;
	oyun2.writeFile(outFileName);

	/* final board'i output dosyasina yazma kismi */
	cout << "\nEntry Final Board Output File Name for Game 3: ";
	cin >> outFileName;
	oyun3.writeFile(outFileName);

	/* final board'i output dosyasina yazma kismi */
	cout << "\nEntry Final Board Output File Name for Game 4: ";
	cin >> outFileName;
	oyun4.writeFile(outFileName);

	/* final board'i output dosyasina yazma kismi */
	cout << "\nEntry Final Board Output File Name for Game 5: ";
	cin >> outFileName;
	oyun5.writeFile(outFileName);

	return 0;
}