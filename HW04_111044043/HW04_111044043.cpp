/*
*        Murat ALTUNTAS
*          111044043
*       HW04_111044043
*   Game of life with Class
*/

/* HW04_111044043.cpp */
#ifndef HW04
#define HW04

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include <vector>
#include "HW04_111044043.h"
using namespace std;

int GameOfLife::numOfLiveCell = 0;

/* parametresiz constructor */
Cell::Cell() : coordinateX(0) , coordinateY(0)
{/*Body intentionally empty.*/}

/* 2 parametreli constructor */
Cell::Cell(int koorX, int koorY)
		: coordinateX(koorX) , coordinateY(koorY)
{/*Body intentionally empty.*/}

/* setters */
void Cell::setX(const int koorX)
{coordinateX = koorX;}

void Cell::setY(const int koorY)
{coordinateY = koorY;}

GameOfLife::GameOfLife()
{
	row=0;
	column=0;
}

/* setters */
void GameOfLife::setRow(int tmpRow)
{
	if (tmpRow >= 0)
	{
		row = tmpRow;
	}
	else
		row = 0;
}
void GameOfLife::setColumn(int tmpClmn)
{
	if (tmpClmn >= 0)
	{
		column = tmpClmn;
	}
	else
		column = 0;
}
/* Print Board */
void GameOfLife::printBoard()
{
	int i, /* satir */
		j; /* sutun */
	bool serachCheck = false; /* canli hucrelerin varliginin testi icin */

	for (i = 0; i < getRow(); ++i)
	{
		for (j = 0; j < getColumn(); ++j)
		{
			/* canli hucrelerin koordinatlarini karsilastiran dongu */
			for (int k = 0; k < livingCells.size(); ++k)
			{
				if((livingCells[k].getX() == i) && (livingCells[k].getY() == j))
				{
					serachCheck = true;
					break;
				}
			}
			
			if (serachCheck)
				cout << "X";
			else
				cout << " ";

			serachCheck = false;
		}
		cout << endl;
	}
}

/* Dosyadan okuma fonksiyonu */
bool GameOfLife::readFile(const char* fileName)
{
	int m=0,n=0; // indisler icin
	ifstream fileStream (fileName, ifstream::in);

	/* Dosya kontrol */
	if (fileStream.good() != 1)
	{
		/* Dosya acilamaz ise */
		cerr << "Dosya yok yada acilamiyor!\n";
		cerr << "Try Again!\n";
		fileStream.close(); //dosya kapatilir
		return false; //false return edilir
	}

	char c = fileStream.get(); // ilk karakter okunur

	/* Dosya okundugu surece doner */
	while (fileStream.good())
	{

		if (c == '\n')
		{
			m++; // har satir sonunda 1 arttirilir.
			n=0; 
		}
		else
		{
			if ((c == 'X') || (c == 'x'))
			{
				tmpObj.setX(m);
				tmpObj.setY(n);
				livingCells.push_back(tmpObj);
				numOfLiveCell++;
			}
			
			n++;
			column = n;	// toplam sutun sayisi
		}

		c = fileStream.get();
	}

	row = m; //toplam satir sayisi

	fileStream.close(); // dosya kapatilir
	return true;
}

/* Dosyaya yazma fonksiyonu */
void GameOfLife::writeFile(const char* fileName)
{
	ofstream outStream (fileName, ofstream::out);

	int i,j; //index
	bool serachCheck = false; /* canli hucrelerin varliginin testi icin */

	// final board output dosyasina yazilir.
	for (i = 0; i < getRow(); ++i)
	{
		for (j = 0; j < getColumn(); ++j)
		{
			/* canli hucrelerin koordinatlarini karsilastiran dongu */
			for (int k = 0; k < livingCells.size(); ++k)
			{
				if((livingCells[k].getX() == i) && (livingCells[k].getY() == j))
				{
					serachCheck = true; /* hucre canli ise true olur */
					break;
				}
			}
			
			if (serachCheck)
				outStream << "X";
			else
				outStream << " ";

			serachCheck = false;
		}
		outStream << endl;
	}

	/* Dosya kapatilir */
	outStream.close();
}

/* Komsu hucrelerdeki yasayan canli hucre sayisini donduren fonksiyon */
int GameOfLife::controlNumOfLiveCell(const int boardRow, const int boardColumn)
{
	int i,j; // for index
	int numOfLive=0; // yasayan komsu hucre sayisi

	for (i = (boardRow - 1); i <= boardRow + 1; ++i)
	{
		for (j = (boardColumn - 1); j <= boardColumn + 1; ++j)
		{
			/* array indexleri negatif olamaz, sutun ve satir sayisindan kucuk olmak zorundadir */
			if (((i>=0 && j>=0) && (i<getRow() && j<getColumn())) && ((i != boardRow) || (j != boardColumn)))
			{
				/* canli hucrelerin koordinatlarini karsilastiran dongu */
				for (int k = 0; k < livingCells.size(); ++k)
				{
					if((livingCells[k].getX() == i) && (livingCells[k].getY() == j))
					{
						numOfLive++;/* her canli komsu icin 1 arttirilir. */
					}
				}
			}
		}
	}
	return numOfLive; /* yasayan komsu hucre sayisi return edilir. */	
}

/* Hucrelerin yasama yada olme durumunu control eden fonksiyon */
void GameOfLife::play()
{
	char tmp; // gecici hucre degiskeni
	int i,j; // array index
	bool serachCheck = false; /* canli hucrelerin varliginin testi icin */

	for (i = 0; i < getRow(); ++i)
	{
		for (j = 0; j < getColumn(); ++j)
		{
			/* secili hucrenin canli olup olmadigini kontrol eder */
			for (int k = 0; k < livingCells.size(); ++k)
			{
				if((livingCells[k].getX() == i) && (livingCells[k].getY() == j))
				{
					serachCheck = true;
					break;
				}
			}

			/* hucre canli ise */
			if (serachCheck)
			{
				if((controlNumOfLiveCell(i, j) == 2) || (controlNumOfLiveCell(i, j) == 3))
					tmp = 'X';  /* 2 yada 3 canli komsusu var ise hayatta kalir */
				else
				{
					tmp = ' ';  /* diger durumlarda 'is dead' */
					numOfLiveCell--;
				}
			}
			else /* hucre olu ise */
			{
				if(controlNumOfLiveCell(i, j) == 3)
				{
					tmp = 'X'; /* 3 canli komsusu var ise canlanir. */
					numOfLiveCell++;
				}
				else
					tmp = ' '; /* diger durumlarda degisim olmaz. */
			}
		
			/* tempCells vectoru yeni board daki canli hucreler ile doldurulur */
			if (tmp == 'X')
			{
				tmpObj.setX(i);
				tmpObj.setY(j);
				tempCells.push_back(tmpObj);
			}

			serachCheck = false;
		}
	}
	
	/* gecici board dolunca icerigi asil board'a aktarilir. */
	transfer();
}

/* bir board'dakini digerine aktarma fonksiyonu */
void GameOfLife::transfer()
{	
	livingCells.clear();
	livingCells.insert(livingCells.begin(), tempCells.begin(), tempCells.end());
	tempCells.clear();
}

/* bir objedeki canli hucreleri digerine ekler */
void GameOfLife::addLiveCell(const GameOfLife & other)
{
	bool serachCheck = true;
	int temp;
	temp = livingCells.size(); 

	/* eklenen objedeki canli hucre sayisi kadar donen dongu */
	for (int i = 0; i < other.livingCells.size(); ++i)
	{
		/* eklenilen objedeki canli hucre sayisi kadar donen dongu */
		for (int k = 0; k < temp; ++k)
		{
			/* iki objeninde ayni koordinattaki hucrelerinin canli olup olmadigini kontrol eder. */
			if((livingCells[k].getX() == other.livingCells[i].getX()) && (livingCells[k].getY() == other.livingCells[i].getY()))
			{
				/* ayni koordinattaki hucrelerin ikiside canli ise false doner */
				serachCheck = false;
				break;
			}
		}

		if (serachCheck)
		{
			livingCells.push_back(other.livingCells[i]);
			numOfLiveCell++;
		}

		serachCheck = true;
	}

	if (row < other.getRow())
		row = other.getRow();

	if (column < other.getColumn())
		column = other.getColumn();
}
	/* oyunlardaki toplam canli hucre sayisini donduren fonksiyon */
int GameOfLife::totalNumOfLiveCell()
{
	return numOfLiveCell;
}
/* Board boyutlarini degistiren fonksiyon */
void GameOfLife::resizeBoard(const int rw, const int clmn)
{
	row=rw;
	column=clmn;
}
#endif