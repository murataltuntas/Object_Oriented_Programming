/*
*        Murat ALTUNTAS
*          111044043
*       HW05_111044043
*   Game of life with Class and operator overloading
*/

/* HW06_111044043_GameOfLife.h */
#ifndef HW06_GameOfLife_H
#define HW06_GameOfLife_H

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include "HW06_111044043_Cell.h"
using namespace std;

namespace Altuntas
{
	class GameOfLife
	{
	public:
		/* No parameter constructor */
		GameOfLife();
		/* copy constructor */
		GameOfLife(const GameOfLife& other);
		/* getters */
		int getRow() const {return row;}
		int getColumn() const {return column;}
		int getCapacity() const {return capacity;}
		int getUsed() const {return used;}
		int getIUsed() const {return indexUsed;}
		/* setters */
		void setRow(const int);
		void setColumn(const int);
		void setCapacity(const int);
		void setUsed(const int);
		void setIndexUsed(const int);
		/* Dosyadan okuma fonksiyonu */
		bool readFile(const char* fileName);
		/* Dosyaya yazma fonksiyonu */
		void writeFile(const char* fileName);
		/* board i ekrana basan fonksiyon */
		void printBoard();
		/* Hucrelerin yasama yada olme durumunu control eder 
		   bir sonraki adimi hesaplar */
		void play();
		/* bir objedeki canli hucreleri digerine ekler */
		void addLiveCell(const GameOfLife & other);	
		/* oyunlardaki toplam canli hucre sayisini donduren fonksiyon */
		static int totalNumOfLiveCell();
		/* Board boyutlarini degistiren fonksiyon */
		void resizeBoard(const int rw, const int clmn);
		/* Gonderilen Objenin Row sayisini donduren Fonksiyon */
		int returnRow(const GameOfLife & other) const {return other.getRow();}
		/* Gonderilen Objenin Column sayisini donduren Fonksiyon */
		int returnColumn(const GameOfLife & other) const {return other.getColumn();}
		/* assignment operator */
		GameOfLife& operator=(const GameOfLife& other);
		/* post increment/decrement operators */
		GameOfLife operator++(const int ignore);    
		GameOfLife operator--(const int ignore);    
		// pre increment/decrement operators
		GameOfLife& operator++();    
		GameOfLife& operator--();
		// binary operators
		GameOfLife operator+(const Cell& other);
		GameOfLife operator-(const Cell& other);
		// index operator
		Cell* operator[](const int ind);
		/* parantez operatoru */
		Cell operator()(const int ind1, const int ind2);
		// compound assignment operators
		GameOfLife& operator+=(const GameOfLife& other);
		/* i/ostream functions */
		friend std::ostream& operator<<(std::ostream& outs, const GameOfLife& other);
		/* destructor */
		~GameOfLife();
	private:
		int row;    /* num of row */
		int column; /* num of column*/
		int capacity; /* array capacity */
		int used;     /* array used */
		int indexUsed; /* for index */
		static int numOfLiveCell;
		Cell* canliHucreler;
		Cell* geciciHucreler;
		Cell tmpObj; /* atamalar icin yardimci obje */
		typedef Cell* cellPtr;
		cellPtr* history; /* oyunu geri almak icin tanimlanmis */
		int* usedArr; /* used larin tutuldugu array */
		int moveCounter; /* haraket sayisi */
		/* Komsu hucrelerdeki yasayan canli hucre sayisini donduren fonksiyon */
		int controlNumOfLiveCell(const int boardRow, const int boardColumn);
		/* bir board'dakini digerine aktarma fonksiyonu */
		void transfer();
	};
}
#endif