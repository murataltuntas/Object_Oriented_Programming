/*
*        Murat ALTUNTAS
*          111044043
*       HW01_111044043
*        Game of life
*/

#include <iostream>
#include <fstream> // dosyadan okuma yazma icin
using namespace std;

#define SIZE 1024 // array size

/**************** PROTOTYPES ****************/
/* Dosyadan okuma fonksiyonu */
bool readFile(int& numOfRow, int& numOfColumn, char fileName[SIZE], char firstBoard[SIZE][SIZE]);
/* Dosyaya yazma fonksiyonu */
void writeFile(int& numOfRow, int& numOfColumn, char finalBoard[SIZE][SIZE],char fileName[SIZE]);
/* Ekrana basma fonksiyonu */
void print(int& numOfRow, int& numOfColumn, char board[SIZE][SIZE]);
/* Hucrelerin yasama yada olme durumunu control eden fonksiyon*/
void controlBoard(int& numOfRow, int& numOfColumn, char board[SIZE][SIZE], char finalBoard[SIZE][SIZE]);
/* Komsu hucrelerdeki yasayan canli hucre sayisini donduren fonksiyon */
int controlNumOfLiveCell(int& numOfRow, int& numOfColumn, int boardRow, int boardColumn, char board[SIZE][SIZE]);
/* Bir board'dakini digerine aktarma fonksiyonu */
void transfer(int& numOfRow, int& numOfColumn, char firstBoard[SIZE][SIZE], char secondBoard[SIZE][SIZE]);
/************* END OF PROTOTYPES *************/

int main() {

	int numOfStep; // step sayisi
	int count=0; // sayac
	int row; // satir sayisi
	int column; // sutun sayisi
	char inFileName[SIZE]; //  input file name
	char outFileName[SIZE]; // output file name
	char board1[SIZE][SIZE]; // ilk board
	char board2[SIZE][SIZE]; // gecici board

	/* dosya okuma duzgun gerceklesmedigi surece tekrar eden dongu */
	do{
		cout << "Entry File Name: ";
		cin >> inFileName;
	}while(readFile(row,column,inFileName,board1) == false);

	cout << "Entry Number Of Step: ";
	cin >> numOfStep;

	cout << "-------------------------------- first board\n";
	print(row,column,board1); /* Board ekrana basilir. */	
	cin.get(); // Enter tusunu algilar

	while((count != numOfStep))
	{
		controlBoard(row,column,board1,board2);
		cin.get(); // Enter tusunu algilar
		count++;
		cout << "-------------------------------- Step: " << count;
		print(row,column,board1);/* Board ekrana basilir. */
	}

	/* final board'i output dosyasina yazma kismi */
	cout << "\nEntry Final Board Output File Name: ";
	cin >> outFileName;
	writeFile(row,column,board1, outFileName);

	return 0;
}

/* Dosyadan okuma fonksiyonu */
bool readFile(int& numOfRow, int& numOfColumn, char fileName[SIZE], char firstBoard[SIZE][SIZE])
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
			firstBoard[m][n] = c;
			n++;
			numOfColumn = n;	// toplam sutun sayisi
		}

		c = fileStream.get();
	}

	numOfRow = m; //toplam satir sayisi

	fileStream.close(); // dosya kapatilir
	return true;
}

/* Dosyaya yazma fonksiyonu */
void writeFile(int& numOfRow, int& numOfColumn, char finalBoard[SIZE][SIZE],char fileName[SIZE])
{
	ofstream outStream (fileName, ofstream::out);

	int i,j; //index

	// final board output dosyasina yazilir.
	for (i = 0; i < numOfRow; ++i)
	{
		for (j = 0; j < numOfColumn; ++j)
		{
			outStream << finalBoard[i][j];
		}
		outStream << endl;
	}

	/* Dosya kapatilir */
	outStream.close();
}

/* Ekrana yazdirma fonksiyonu */
void print(int& numOfRow, int& numOfColumn, char board[SIZE][SIZE])
{
	int i,j; //index
	for (i = 0; i < numOfRow; ++i)
	{
		for (j = 0; j < numOfColumn; ++j)
		{
			cout << board[i][j];
		}
		cout << endl;		
	}
}

/* Hucrelerin yasama yada olme durumunu control eden fonksiyon */
void controlBoard(int& numOfRow, int& numOfColumn, char board[SIZE][SIZE], char finalBoard[SIZE][SIZE])
{
	int numOfLive=0; // canli hucre sayisi
	char tmp; // gecici hucre degiskeni
	int i,j; // array index
	
	for (i = 0; i < numOfRow; ++i)
	{
		for (j = 0; j < numOfColumn; ++j)
		{
			/* hucre canli ise */
			if ((board[i][j] == 'X') || (board[i][j] == 'x'))
			{
				if((controlNumOfLiveCell(numOfRow,numOfColumn,i, j, board) == 2) || (controlNumOfLiveCell(numOfRow,numOfColumn,i, j, board) == 3))
					tmp = 'X';  /* 2 yada 3 canli komsusu var ise hayatta kalir */
				else
					tmp = ' ';  /* diger durumlarda 'is dead' */
			}
			else /* hucre olu ise */
			{
				if(controlNumOfLiveCell(numOfRow,numOfColumn,i, j, board) == 3)
					tmp = 'X'; /* 3 canli komsusu var ise canlanir. */
				else
					tmp = ' '; /* diger durumlarda degisim olmaz. */
			}		
				
			finalBoard[i][j] = tmp; /* yeni durum gecici board'a tasinir */
		}
	}
	
	transfer(numOfRow,numOfColumn,board,finalBoard);  /* gecici board dolunca icerigi asil board'a aktarilir. */
}

/* Komsu hucrelerdeki yasayan canli hucre sayisini donduren fonksiyon */
int controlNumOfLiveCell(int& numOfRow, int& numOfColumn, int boardRow, int boardColumn, char board[SIZE][SIZE])
{
	int i,j; // for index
	int numOfLive=0; // yasayan komsu hucre sayisi

	for (i = (boardRow - 1); i <= boardRow + 1; ++i)
	{
		for (j = (boardColumn - 1); j <= boardColumn + 1; ++j)
		{
			/* array indexleri negatif olamaz, sutun ve satir sayisindan kucuk olmak zorundadir */
			if (((i>=0 && j>=0) && (i<numOfRow && j<numOfColumn)) && ((i != boardRow) || (j != boardColumn)))
			{
				if((board[i][j] == 'X') || (board[i][j] == 'x'))
					numOfLive++; /* her canli komsu icin 1 arttirilir. */
			}
		}
	}
	return numOfLive; /* yasayan komsu hucre sayisi return edilir. */	
}

/* bir board'dakini digerine aktarma fonksiyonu */
void transfer(int& numOfRow, int& numOfColumn, char firstBoard[SIZE][SIZE], char secondBoard[SIZE][SIZE])
{
	int i,j; // index
	for (i = 0; i < numOfRow; ++i)
	{
		for (j = 0; j < numOfColumn; ++j)
		{
			firstBoard[i][j] = secondBoard[i][j];
		}
	}
}
/*############# END OF THE PROGRAM #############*/