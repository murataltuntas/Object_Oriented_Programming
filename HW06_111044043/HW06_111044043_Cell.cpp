/*
*        Murat ALTUNTAS
*          111044043
*       HW05_111044043
*   Game of life with Class and operator overloading
*/

/* HW06_111044043_Cell.cpp */
#ifndef HW06_Cell
#define HW06_Cell

#include <iostream>
#include "HW06_111044043_Cell.h"
using namespace std;

namespace Altuntas
{
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


	/* logical operators */
	/* once Y 'ye bakilir esitlik durumunda x' e bakilir */
	bool Cell::operator<(const Cell& other) const
	{
	    if (coordinateY < other.getY())
	    {
	    	return true;
	    }
	    else if (coordinateY == other.getY())
	    {
	    	if (coordinateX < other.getX())
	    		return true;
	    	else
	    		return false;
	    }
	    else
	    	return false;
	}

	bool Cell::operator>(const Cell& other) const    
	{
	    if (coordinateY > other.getY())
	    {
	    	return true;
	    }
	    else if (coordinateY == other.getY())
	    {
	    	if (coordinateX > other.getX())
	    		return true;
	    	else
	    		return false;
	    }
	    else
	    	return false;
	}

	bool Cell::operator<=(const Cell& other) const    
	{
	    if (coordinateY < other.getY())
	    {
	    	return true;
	    }
	    else if (coordinateY == other.getY())
	    {
	    	if (coordinateX <= other.getX())
	    		return true;
	    	else
	    		return false;
	    }
	    else
	    	return false;
	}

	bool Cell::operator>=(const Cell& other) const    
	{
		
		if (coordinateY > other.getY())
	    {
	    	return true;
	    }
	    else if (coordinateY == other.getY())
	    {
	    	if (coordinateX >= other.getX())
	    		return true;
	    	else
	    		return false;
	    }
	    else
	    	return false;
	}

	bool Cell::operator==(const Cell& other) const    
	{
	    return ((coordinateX == other.getX()) && (coordinateY == other.getY()));
	}

	bool Cell::operator!=(const Cell& other) const
	{
	    return !(*this == other);
	}

	// postfix increment/decrement operators
	Cell Cell::operator++(const int ignore)
	{
		int tempX =coordinateX;
		int tempY =coordinateY;
	    coordinateX++;
	    coordinateY++;
	    return Cell(tempX,tempY);
	}

	Cell Cell::operator--(const int ignore)
	{
	    coordinateX--;
	    coordinateY--;
	    return *this;
	}

	// prefix increment/decrement operators
	Cell& Cell::operator++()
	{
	    ++coordinateX;
	    ++coordinateY;
	    return *this;
	}

	Cell& Cell::operator--()
	{
	    --coordinateX;
	    --coordinateY;
	    return *this;
	}

	/*Uses iostream // i/ostream functions*/
	ostream& operator <<(ostream& outs, const Cell& other)
	{
		outs << "X coordinate : " << other.coordinateX << endl;
		outs << "Y coordinate : " << other.coordinateY << endl;
		return outs;
	}

	/*Uses iostream: */
	istream& operator >>(istream& ins, Cell& other)
	{
		ins >> other.coordinateX;
		ins >> other.coordinateY;
		return ins;
	}
}
/************************************************************/
#endif