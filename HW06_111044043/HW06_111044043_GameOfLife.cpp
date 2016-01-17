/*
*        Murat ALTUNTAS
*          111044043
*       HW05_111044043
*   Game of life with Class and operator overloading
*/

/* HW06_111044043_GameOfLife.cpp */
#ifndef HW06_GameOfLife
#define HW06_GameOfLife

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
#include "HW06_111044043_GameOfLife.h"
using namespace std;

namespace Altuntas
{
	int GameOfLife::numOfLiveCell = 0;

	/****** GameOfLife ******/
	GameOfLife::GameOfLife()
	{
		row=0;
		column=0;
		capacity = 50;
		used = 0;
		moveCounter=0;
		
		usedArr = new int[capacity];
		history = new cellPtr[capacity];

		for (int i = 0; i < capacity; ++i)
		{
			history[i] = new Cell[capacity];
		}
	}

	GameOfLife::GameOfLife(const GameOfLife& other)
	{
		row = other.row;
		column = other.column;
		capacity = other.capacity;
		used = other.used;
		canliHucreler = new Cell[capacity];
		for (int i = 0; i < used; ++i)
			canliHucreler[i] = other.canliHucreler[i];
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
	void GameOfLife::setCapacity(int tmpCpcty)
	{
		if (tmpCpcty >= 0)
		{
			capacity = tmpCpcty;
		}
		else
			capacity = 0;
	}
	void GameOfLife::setUsed(int tmpUsd)
	{
		if (tmpUsd >= 0)
		{
			used = tmpUsd;
		}
		else
			used = 0;
	}
	void GameOfLife::setIndexUsed(int tmpIUsd)
	{
		if (tmpIUsd >= 0)
		{
			indexUsed = tmpIUsd;
		}
		else
			indexUsed = 0;
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
				for (int k = 0; k < getUsed(); ++k)
				{
					if((canliHucreler[k].getX() == i) && (canliHucreler[k].getY() == j))
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
		int count=0;
		int height, width;
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

		fileStream >> height >> width; /* yukseklik ve genislik alinir */
		capacity = height * width; /* carpilip capacity'e eklenir. */

		canliHucreler = new Cell[capacity];

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
					canliHucreler[count] = tmpObj;
					numOfLiveCell++;
					count++;
				}
				
				n++;
				column = n;	// toplam sutun sayisi
			}

			c = fileStream.get();
		}

		moveCounter=0;
		row = m; //toplam satir sayisi
		used = count; //canli hucre sayisi
		for (int i = 0; i < used; ++i)
		{
			history[moveCounter][i] = canliHucreler[i];
		}
		usedArr[moveCounter] = used;
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
				for (int k = 0; k < getUsed(); ++k)
				{
					if((canliHucreler[k].getX() == i) && (canliHucreler[k].getY() == j))
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
					for (int k = 0; k < getUsed(); ++k)
					{
						if((canliHucreler[k].getX() == i) && (canliHucreler[k].getY() == j))
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
		int count=0; // counter
		bool serachCheck = false; /* canli hucrelerin varliginin testi icin */
		geciciHucreler = new Cell[getCapacity()]; // gecici hucrelere yer alinir

		for (i = 0; i < getRow(); ++i)
		{
			for (j = 0; j < getColumn(); ++j)
			{
				/* secili hucrenin canli olup olmadigini kontrol eder */
				for (int k = 0; k < getUsed(); ++k)
				{
					if((canliHucreler[k].getX() == i) && (canliHucreler[k].getY() == j))
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
					geciciHucreler[count] = tmpObj;
					count++;
				}

				serachCheck = false;
			}
		}
		
		used = count;
		/* gecici board dolunca icerigi asil board'a aktarilir. */
		transfer();
	}

	/* bir board'dakini digerine aktarma fonksiyonu */
	void GameOfLife::transfer()
	{	
		delete[] canliHucreler;
		canliHucreler = new Cell[getCapacity()];

		for (int i = 0; i < getUsed(); ++i)
		{
			canliHucreler[i] = geciciHucreler[i];
		}
	}

	/* bir objedeki canli hucreleri digerine ekler */
	void GameOfLife::addLiveCell(const GameOfLife & other)
	{
		bool serachCheck = true;
		int temp;
		temp = getUsed();
		Cell* tmprory;

		if (getCapacity() < other.getCapacity())
		{
			capacity = other.getCapacity();
			tmprory = new Cell[capacity];

			for (int b = 0; b < getUsed(); ++b)
			{
				tmprory[b] = canliHucreler[b];
			}

			delete[] canliHucreler;
			canliHucreler = new Cell[capacity];

			for (int c = 0; c < getUsed(); ++c)
			{
				canliHucreler[c] = tmprory[c];
			}

			delete[] tmprory;
		}

		/* eklenen objedeki canli hucre sayisi kadar donen dongu */
		for (int i = 0; i < other.getUsed(); ++i)
		{
			/* eklenilen objedeki canli hucre sayisi kadar donen dongu */
			for (int k = 0; k < temp; ++k)
			{
				/* iki objeninde ayni koordinattaki hucrelerinin canli olup olmadigini kontrol eder. */
				if((canliHucreler[k].getX() == other.canliHucreler[i].getX()) && (canliHucreler[k].getY() == other.canliHucreler[i].getY()))
				{
					/* ayni koordinattaki hucrelerin ikiside canli ise false doner */
					serachCheck = false;
					break;
				}
			}

			if (serachCheck)
			{
				canliHucreler[used] = other.canliHucreler[i];
				numOfLiveCell++;
				used++;
			}

			serachCheck = true;
		}

		if (row < other.getRow())
			row = other.getRow();

		if (column < other.getColumn())
			column = other.getColumn();

		moveCounter++;
		for (int i = 0; i < getUsed(); ++i)
		{
			history[moveCounter][i] = canliHucreler[i];
		}
		usedArr[moveCounter] = getUsed();

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
	/* assignment operator */
	GameOfLife& GameOfLife::operator=(const GameOfLife& other)
	{
		if (capacity != other.capacity)
		{
			delete [] canliHucreler;
			canliHucreler = new Cell[other.capacity];
		}

		capacity = other.capacity;
		used = other.used;
		row = other.row;
		column = other.column;
		for (int i = 0; i < used; ++i)
			canliHucreler[i] = other.canliHucreler[i];

		return *this;
	}

	// postfix increment/decrement operators
	GameOfLife GameOfLife::operator++(const int ignore)
	{
		moveCounter++;
		play();
		for (int i = 0; i < getUsed(); ++i)
		{
			history[moveCounter][i] = canliHucreler[i];
		}
		usedArr[moveCounter] = getUsed();

	    return *this;
	}

	GameOfLife GameOfLife::operator--(const int ignore)
	{
		if (moveCounter > 0)
		{
			moveCounter--;
			delete[] canliHucreler;
			canliHucreler = new Cell[capacity];
			for (int i = 0; i < usedArr[moveCounter]; ++i)
			{
				canliHucreler[i] = history[moveCounter][i];
			}
			used = usedArr[moveCounter];
		}
		else
		{
			cout << "Bu Oyun daha fazla geriye alinamaz.";
		}
		
	    return *this;
	}

	// prefix increment/decrement operators
	GameOfLife& GameOfLife::operator++()
	{
		moveCounter++;
		play();
		for (int i = 0; i < getUsed(); ++i)
		{
			history[moveCounter][i] = canliHucreler[i];
		}
		usedArr[moveCounter] = getUsed();

	    return *this;
	}

	GameOfLife& GameOfLife::operator--()
	{
		if (moveCounter > 0)
		{
			moveCounter--;
			delete[] canliHucreler;
			canliHucreler = new Cell[capacity];
			for (int i = 0; i < usedArr[moveCounter]; ++i)
			{
				canliHucreler[i] = history[moveCounter][i];
			}
			used = usedArr[moveCounter];
		}
		else
		{
			cout << "Bu Oyun daha fazla geriye alinamaz.";
		}
		return *this;
	}

	/* binary operators +  */
	GameOfLife GameOfLife::operator+(const Cell& other)
	{
		bool serachCheck = true;
		int tmpCellsSize;
		tmpCellsSize= getUsed(); 

	   
		/* eklenilen objedeki canli hucre sayisi kadar donen dongu */
		for (int k = 0; k < tmpCellsSize; ++k)
		{
			/* eklenecek olan Cell objesi oyunun icinde var mi diye kontrol edilir. */
			if((canliHucreler[k].getX() == other.getX()) && (canliHucreler[k].getY() == other.getY()))
			{
				/* ayni koordinattaki hucrelerin ikiside canli ise false doner */
				serachCheck = false;
				break;
			}
		}

		if (serachCheck)
		{
			canliHucreler[used] = other;
			numOfLiveCell++;
			used++;
			moveCounter++;
			for (int i = 0; i < getUsed(); ++i)
			{
				history[moveCounter][i] = canliHucreler[i];
			}
			usedArr[moveCounter] = getUsed();
		}

			
		if (row < other.getX())
			row = other.getX() + 1;

		if (column < other.getY())
			column = other.getY() + 1;
	    return *this;
	}

	/* binary operators -  */
	GameOfLife GameOfLife::operator-(const Cell& other)
	{
		bool serachCheck = false;
		int tmpCellsSize, k;
		tmpCellsSize= getUsed(); 

	   
		//* eklenilen objedeki canli hucre sayisi kadar donen dongu /
		for (k = 0; k < tmpCellsSize; ++k)
		{
			//* eklenecek olan Cell objesi oyunun icinde var mi diye kontrol edilir. /
			if((canliHucreler[k].getX() == other.getX()) && (canliHucreler[k].getY() == other.getY()))
			{
				//* ayni koordinattaki hucrelerin ikiside canli ise false doner /
				serachCheck = true;
				break;
			}
		}

		if (serachCheck)
		{
			// erase the kth element
			for (int j = k; j < tmpCellsSize-1; ++j)
				canliHucreler[j] = canliHucreler[j+1];

			used--;
			numOfLiveCell--;
			moveCounter++;
			for (int i = 0; i < getUsed(); ++i)
			{
				history[moveCounter][i] = canliHucreler[i];
			}
			usedArr[moveCounter] = getUsed();
		}

	    return *this;
	}

	/* += operatoru */
	GameOfLife& GameOfLife::operator+=(const GameOfLife& other)
	{
		addLiveCell(other);
	    return *this;
	}

	/* index operator for non-const objects */
	Cell* GameOfLife::operator[](const int ind)
	{
		int tmpCellsSize, k, count=0;
		tmpCellsSize= getUsed(); 
		Cell* tmpClls;
	   
		tmpClls = new Cell[tmpCellsSize];
		//* eklenilen objedeki canli hucre sayisi kadar donen dongu 
		for (k = 0; k < tmpCellsSize; ++k)
		{
		    if(canliHucreler[k].getX() == ind){
		    	tmpClls[count] = canliHucreler[k];
		    	count++;
		    }
	    }
	    indexUsed=count;
	    return tmpClls;
	}

	Cell GameOfLife::operator () (const int x, const int y){
	//return (*this)[x][y] ---birinci index operatorunden yararlanarak
	// call function operatorunu implement edebilirdik.
	
	/* eklenilen objedeki canli hucre sayisi kadar donen dongu */
		for (int k = 0; k < getUsed(); ++k)
		{
			if (canliHucreler[k].getX() == x && canliHucreler[k].getY() == y)
			{
				return canliHucreler[k];
			}
		}
		return Cell(-1000,-1000);
	}


	/*Uses iostream - ostream function*/
	ostream& operator <<(ostream& outs, const GameOfLife& other)
	{
		int i, /* satir */
			j; /* sutun */
		bool serachCheck = false; /* canli hucrelerin varliginin testi icin */
		for (i = 0; i < other.getRow(); ++i)
		{
			for (j = 0; j < other.getColumn(); ++j)
			{
				/* canli hucrelerin koordinatlarini karsilastiran dongu */
				for (int k = 0; k < other.getUsed(); ++k)
				{
					if((other.canliHucreler[k].getX() == i) && (other.canliHucreler[k].getY() == j))
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
		return outs;
	}
	/* destructor */
	GameOfLife::~GameOfLife()
	{
		delete[] canliHucreler;
	}
}
#endif