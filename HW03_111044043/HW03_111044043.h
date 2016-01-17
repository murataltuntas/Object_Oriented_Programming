/*HW03_111044043.h*/

#ifndef HW03_H
#define HW03_H

#include <iostream>
/* 3 boyutlu vector class i */
class Vect3D
{
public:
	/* constuctors */
	Vect3D();
	Vect3D(const double koorX);
	Vect3D(const double koorX, const double koorY);
	Vect3D(const double koorX, const double koorY, const double koorZ);
	/* setters */
	void setX(const double koorX);
	void setY(const double koorY);
	void setZ(const double koorZ);
	/* getters */
	double getX() const {return coordX;}
	double getY() const {return coordY;}
	double getZ() const {return coordZ;}
	/* input and output functions */
	void input();
	void output();
	/* dot Product , vector (cross) product and magnitude functions */
	double dotProduct(const Vect3D);
	Vect3D crossProduct(const Vect3D);
	double magnitude();
	/* Call-By-Value and Call-By-Reference example functions */
	void CBReferance(Vect3D &);
	void CBValue(Vect3D);

private:	
	double coordX,  /* X ekseni */
		coordY,		/* Y ekseni */
		coordZ;		/* Z ekseni */

};

#endif
