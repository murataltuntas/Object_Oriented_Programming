/* HW03_111044043.cpp */

#ifndef HW03
#define HW03

#include <iostream>
#include <cmath> /* sqrt() */
#include "HW03_111044043.h"
using namespace std;

/* parametresiz constructor */
Vect3D::Vect3D() : coordX(0.0), coordY(0.0), coordZ(0.0)
{/*Body intentionally empty.*/}

/* 1 parametreli constructor */
Vect3D::Vect3D(double koorX)
			: coordX(koorX), coordY(0.0), coordZ(0.0)
{/*Body intentionally empty.*/}

/* 2 parametreli constructor */
Vect3D::Vect3D(double koorX, double koorY)
			: coordX(koorX), coordY(koorY), coordZ(0.0)
{/*Body intentionally empty.*/}

/* 3 parametreli constructor */
Vect3D::Vect3D(double koorX, double koorY, double koorZ)
			: coordX(koorX), coordY(koorY), coordZ(koorZ)
{/*Body intentionally empty.*/}

/* setters */
void Vect3D::setX(const double koorX)
{
	coordX = koorX;
}

void Vect3D::setY(const double koorY)
{
	coordY = koorY;
}

void Vect3D::setZ(const double koorZ)
{
	coordZ = koorZ;
}

/* input functions */
void Vect3D::input()
{
	double crdX, crdY, crdZ; /* coordinate X, Y, Z */

	cout << "Please enter coordinate of X : " ;
	cin >> crdX;
	cout << "Please enter coordinate of Y : " ;
	cin >> crdY;
	cout << "Please enter coordinate of Z : " ;
	cin >> crdZ;

	/* objenin koordinatlari degistirilir. */
	setX(crdX);
	setY(crdY);
	setZ(crdZ);
}

/* output functions */
void Vect3D::output()
{
	cout << "X-coordinate: " << getX() << endl;
	cout << "Y-coordinate: " << getY() << endl;
	cout << "Z-coordinate: " << getZ() << endl;
}

/* dot Product Function */
double Vect3D::dotProduct(Vect3D temp)
{
	/* dot product islemi */
	return ((getX() * temp.getX()) + (getY() * temp.getY()) + (getZ() * temp.getZ()));
}

/* vector (cross) product function */
Vect3D Vect3D::crossProduct(Vect3D obj)
{
	Vect3D temp; /* gecici obje (return etmek icin) */
	temp.setX((getY() * (obj.getZ())) - (getZ() * (obj.getY())));
	temp.setY((getZ() * (obj.getX())) - (getX() * (obj.getZ())));
	temp.setZ((getX() * (obj.getY())) - (getY() * (obj.getX())));
	return temp;
}

/* magnitude functions */
double Vect3D::magnitude()
{
	/* magnitude (buyukluk) bulma islemi */
	return (sqrt((getX() * (getX())) + (getY() * (getY())) + (getZ() * (getZ()))));
}

/* Call-By-Reference example function*/
void Vect3D::CBReferance(Vect3D & obj)
{
	/* koordinat degerleri degistirilir. */
	obj.setX(12.34);
	obj.setY(12.34);
	obj.setZ(12.34);

	obj.output();
}

/* Call-By-Value example function */
void Vect3D::CBValue(Vect3D obj)
{
	/* koordinat degerleri degistirilir. */
	obj.setX(43.21);
	obj.setY(43.21);
	obj.setZ(43.21);

	obj.output();
}
#endif
