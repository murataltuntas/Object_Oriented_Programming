/*
*        Murat ALTUNTAS
*          111044043
*       HW05_111044043
*   Game of life with Class and operator overloading
*/

/* HW06_111044043_Cell.h */
#ifndef HW06_Cell_H
#define HW06_Cell_H

#include <iostream>
using namespace std;

namespace Altuntas
{
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
}
#endif