/*
*        Murat ALTUNTAS
*          111044043
*       HW05_111044043
*   Game of life with Class and operator overloading
*/

/* HW05_111044043.h */
#ifndef HW05_H
#define HW05_H

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include <vector>
using namespace std;

class Cell
{
public:
	/* No parameter constructor */
	Cell();
	/* 2 Parameter Constructor */
	Cell(int koorX, int koorY);
	/* getters */
	int getX() const {return coordinateX;}
	int getY() const {return coordinateY;}
	/* setters */
	void setX(const int);
	void setY(const int);
    /* logical operators */
    bool operator<(const Cell& other) const;
    bool operator>(const Cell& other) const;
    bool operator<=(const Cell& other) const;
    bool operator>=(const Cell& other) const;
    bool operator==(const Cell& other) const;
    bool operator!=(const Cell& other) const;
    // post increment/decrement operators
    Cell operator++(const int ignore);    
    Cell operator--(const int ignore);    
    // pre increment/decrement operators
    Cell& operator++();    
    Cell& operator--();  
	/* i/ostream functions */
    friend std::ostream& operator<<(std::ostream& outs, const Cell& other);
    friend std::istream& operator>>(std::istream& ins, Cell& other);

public:
	int coordinateX;
	int coordinateY;
};

class GameOfLife
{
public:
	/* No parameter constructor */
	GameOfLife();
	/* getters */
	int getRow() const {return row;}
	int getColumn() const {return column;}
	/* setters */
	void setRow(const int);
	void setColumn(const int);
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
	// post increment/decrement operators
    GameOfLife operator++(const int ignore);    
    GameOfLife operator--(const int ignore);    
    // pre increment/decrement operators
    GameOfLife& operator++();    
    GameOfLife& operator--();
    // binary operators
    GameOfLife operator+(const Cell& other);
    GameOfLife operator-(const Cell& other);
    // index operator
    vector<Cell> operator[](const int ind);
    // compound assignment operators
    GameOfLife& operator+=(const GameOfLife& other);
    /* i/ostream functions */
    friend std::ostream& operator<<(std::ostream& outs, const GameOfLife& other);

private:
	int row;    /* num of row */
	int column; /* num of column*/
	static int numOfLiveCell;
	vector<Cell> livingCells; /* canli hucre vectoru */
	vector<Cell> tempCells; /* gecici vector */
	vector< vector<Cell> > vectVect; /* vektör vektörü */
	Cell tmpObj; /* atamalar icin yardimci obje (push_back icin) */

	/* Komsu hucrelerdeki yasayan canli hucre sayisini donduren fonksiyon */
	int controlNumOfLiveCell(const int boardRow, const int boardColumn);
	/* bir board'dakini digerine aktarma fonksiyonu */
	void transfer();
};
#endif