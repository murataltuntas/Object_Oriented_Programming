/*
*        Murat ALTUNTAS
*          111044043
*       HW05_111044043
*   Game of life with Class and operator overloading
*/

/* HW06_111044043_TEST.cpp */
#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include "HW06_111044043_Cell.h"
#include "HW06_111044043_GameOfLife.h"
using namespace std;
using namespace Altuntas;

int main()
{
	char inFileName[256];  // input file name
	char outFileName[256]; // output file name
	int numOfStep; // step sayisi
	char endGame; // oyun secme ve bitirme icin gerekli degisken

	Cell cell1;
	Cell cell2(3,7);

	cout << "1. hucrenin X ve Y koordinatlarini giriniz: ";
	cin >> cell1;
	cout << "\n1. hucrenin X ve Y koordinatlari\n";
	cout << cell1;
	cout << "\n2. hucrenin X ve Y koordinatlari\n";
	cout << cell2;

	cout << "\nBoolean Expressions\n";
        cout << "cell1 == cell2   ==> " << boolalpha << (cell1 == cell2) << endl;
        cout << "cell1 == cell1   ==> " << boolalpha << (cell1 == cell1) << endl;
        cout << "cell1 != cell2   ==> " << boolalpha << (cell1 != cell2) << endl;
        cout << "cell1 < cell2    ==> " << boolalpha << (cell1 < cell2) << endl;
        cout << "cell1 > cell2    ==> " << boolalpha << (cell1 > cell2) << endl;
        cout << "cell1 <= cell2   ==> " << boolalpha << (cell1 <= cell2) << endl;
        cout << "cell1 >= cell2   ==> " << boolalpha << (cell1 >= cell2) << endl;

    cout << "\nUnary operators\n";
        cout << "cell2\n" << cell2 << endl;
        cell2++;
        cout << "cell2++\n" << cell2 << endl;
        cell2--;
        cout << "cell2--\n" << cell2 << endl;
        ++cell2;
        cout << "++cell2\n" << cell2 << endl;
        --cell2;
        cout << "--cell2\n" << cell2 << endl;

	cout << "\nPostfix cell2++: Start value of object cell2:\n";
	cout << cell2 << endl;
	Cell tmp = cell2++;
	cout << "Value returned: \n";
	cout << tmp << endl;
	cout << "Changed object \n";
	cout << cell2 << endl;
 
	cout << "\nPrefix ++cell2: Start value of object cell2: \n";
	cout << cell2 << endl;
	tmp = ++cell2;
	cout << "Value returned: \n";
	cout << tmp << endl;
	cout << "Changed object: \n";
	cout << cell2 << endl;
 /************************************************************************/

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

	Cell cell3(13,20);
	Cell cell4(3,5);
	Cell cell5(1,1);
	Cell cell6(2,2);

	cout << "---- Game 1 ----\n";
	cout << oyun1;

	cout << "---- Game 2 ----\n";
	cout << oyun2;

	cout << "---- Game 3 ----\n";
	cout << oyun3;

	cout << "---- Game 4 ----\n";
	cout << oyun4;

	cout << "---- Game 5 ----\n";
	cout << oyun5;

	cout << "oyun1 + cell(1,1)\n";
	oyun1 + cell5;
	cout << oyun1;

	cout << "oyun1 + cell(3,5)\n";
	oyun1 + cell4;
	cout << oyun1;

	cout << "oyun1 + cell(13,20)\n";
	oyun1 + cell3;
	cout << oyun1;

	cout << "oyun1 - cell(3,5)\n";
	oyun1 - cell4;
	cout << oyun1;

	cout << "oyun1 - cell(2,2)\n";
	oyun1 - cell6;
	cout << oyun1;

	cout << "oyun1 += oyun2\n";
	oyun1 += oyun2;
	cout << oyun1;

	/* parantez */
	cout << "oyun1(11,5)\n";
	cout << oyun1(11,5) << endl;
	cout << "oyun1(14,11)\n";
	cout << oyun1(14,11) << endl;
	/* cift index. */

	for (int i = 0; i < oyun1.getIUsed(); ++i)
	{
		cout << oyun1[11][i];
	}
	
	cout << "\nilk adimi hangi oyun ile yapmak istersiniz?\n";
	cout << "Game 1 icin A ya \nGame 2 icin B ye \n";
	cout << "Game 3 icin C ye \nGame 4 icin D ye\n";
	cout << "Game 5 icin E ye basiniz!\n";
	cout << "Oyunlardan cikmak istiyorsaniz Q ya basiniz!\n";
	cout << "Lutfen secim yapiniz: ";
	cin >> endGame;

	do
	{
		if ((endGame == 'A') || (endGame == 'a'))
			{
				cout << "\nBir adim ileriye oynamak icin P ye\n"
					 << "Bir adim geriye  oynamak icin G ye\n"
					 << "Board i yeniden boyutlandirmak icin R ye basiniz!\n"
					 << "Lutfen secim yapiniz: ";
				cin >> endGame;
				if ((endGame == 'P') || (endGame == 'p'))
				{
					oyun1++;
					cout << oyun1;
				}
				else if ((endGame == 'G') || (endGame == 'g'))
				{
					oyun1--;
					cout << oyun1;
				}
				else if ((endGame == 'R') || (endGame == 'r'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun1.setRow(tmpRow);
					oyun1.setColumn(tmpClmn);
					cout << oyun1;
				}
				else
					cout << "\nYanlis karakter girdiniz Lutfen tekrar deneyin: ";
			}
		else if ((endGame == 'B') || (endGame == 'b'))
			{
				cout << "\nBir adim ileriye oynamak icin P ye\n"
					 << "Bir adim geriye  oynamak icin G ye\n"
					 << "Board i yeniden boyutlandirmak icin R ye basiniz!\n"
					 << "Lutfen secim yapiniz: ";
				cin >> endGame;
				if ((endGame == 'P') || (endGame == 'p'))
				{
					oyun2++;
					cout << oyun2;
				}
				else if ((endGame == 'G') || (endGame == 'g'))
				{
					oyun2--;
					cout << oyun2;
				}
				else if ((endGame == 'R') || (endGame == 'r'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun2.setRow(tmpRow);
					oyun2.setColumn(tmpClmn);
					cout << oyun2;
				}
				else
					cout << "\nYanlis karakter girdiniz Lutfen tekrar deneyin: ";
			}
		else if ((endGame == 'C') || (endGame == 'c'))
			{
				cout << "\nBir adim ileriye oynamak icin P ye\n"
					 << "Bir adim geriye  oynamak icin G ye\n"
					 << "Board i yeniden boyutlandirmak icin R ye basiniz!\n"
					 << "Lutfen secim yapiniz: ";
				cin >> endGame;
				if ((endGame == 'P') || (endGame == 'p'))
				{
					oyun3++;
					cout << oyun3;
				}
				else if ((endGame == 'G') || (endGame == 'g'))
				{
					oyun3--;
					cout << oyun3;
				}
				else if ((endGame == 'R') || (endGame == 'r'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun3.setRow(tmpRow);
					oyun3.setColumn(tmpClmn);
					cout << oyun3;
				}
				else
					cout << "\nYanlis karakter girdiniz Lutfen tekrar deneyin: ";
			}
		else if ((endGame == 'D') || (endGame == 'd'))
			{
				cout << "\nBir adim ileriye oynamak icin P ye\n"
					 << "Bir adim geriye  oynamak icin G ye\n"
					 << "Board i yeniden boyutlandirmak icin R ye basiniz!\n"
					 << "Lutfen secim yapiniz: ";
				cin >> endGame;
				if ((endGame == 'P') || (endGame == 'p'))
				{
					oyun4++;
					cout << oyun4;
				}
				else if ((endGame == 'G') || (endGame == 'g'))
				{
					oyun4--;
					cout << oyun4;
				}
				else if ((endGame == 'R') || (endGame == 'r'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun4.setRow(tmpRow);
					oyun4.setColumn(tmpClmn);
					cout << oyun4;
				}
				else
					cout << "\nYanlis karakter girdiniz Lutfen tekrar deneyin: ";
			}
		else if ((endGame == 'E') || (endGame == 'e'))
			{
				cout << "\nBir adim ileriye oynamak icin P ye\n"
					 << "Bir adim geriye  oynamak icin G ye\n"
					 << "Board i yeniden boyutlandirmak icin R ye basiniz!\n"
					 << "Lutfen secim yapiniz: ";
				cin >> endGame;
				if ((endGame == 'P') || (endGame == 'p'))
				{
					oyun5++;
					cout << oyun5;
				}
				else if ((endGame == 'G') || (endGame == 'g'))
				{
					oyun5--;
					cout << oyun5;
				}
				else if ((endGame == 'R') || (endGame == 'r'))
				{
					int tmpRow, tmpClmn;
					cout << "Yeni Row boyutunu giriniz: ";
					cin >> tmpRow;
					cout << "Yeni Column boyutunu giriniz: ";
					cin >> tmpClmn;
					oyun5.setRow(tmpRow);
					oyun5.setColumn(tmpClmn);
					cout << oyun5;
				}
				else
					cout << "\nYanlis karakter girdiniz Lutfen tekrar deneyin: ";
			}
		else if ((endGame == 'Q') || (endGame == 'q'))
			break;
		else
			cout << "\nYanlis karakter girdiniz Lutfen tekrar deneyin: ";
		
		cout << "\nBir sonraki adimi seciniz: "
			 << "\nGame 1 icin A ya \nGame 2 icin B ye \n"
			 << "Game 3 icin C ye \nGame 4 icin D ye\n"
			 << "Game 5 icin E ye basiniz!\n"
			 << "Oyunlardan cikmak istiyorsaniz Q ya basiniz!\n"
			 << "Lutfen secim yapiniz: ";
		cin >> endGame;

	}while(endGame);

	cout << "\nGame 1 e Game 2 eklenirse\n";
	oyun1 += oyun2;
	cout << oyun1;

	cout << "\nGame 1 bir geri alinirsa\n";
	--oyun1;
	cout << oyun1;

	cout << "\nGame 3 e Game 4 eklenirse\n";
	cout << "Game 3 += Game 4\n";
	oyun3 += oyun4;
	cout << oyun3;

	cout << "\nGame 3 bir geri alinirsa\n";
	oyun3--;
	cout << oyun3;

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