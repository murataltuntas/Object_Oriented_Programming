/* HW03_111044043_TEST.cpp */

/*
*        Murat ALTUNTAS
*          111044043
*       HW03_111044043
*        Vect3D class
*   3 Boyutlu vector class i
*/

#include <iostream>
#include "HW03_111044043.h"
using namespace std;

int main()
{
	/* objeler olusturulur. */
	Vect3D vector1;
	Vect3D vector2(1.2);
	Vect3D vector3(4.8, 7.9);
	Vect3D vector4(5.1, 2.4, 3.6);
	Vect3D vector5(1.9, 2.8, 3.7);
	Vect3D vector6;

	cout << "\n1. Vector \n";
	vector1.output();
	cout << "\n2. Vector \n";
	vector2.output();
	cout << "\n3. Vector \n";
	vector3.output();
	cout << "\n4. Vector \n";
	vector4.output();
	cout << "\n5. Vector \n";
	vector5.output();

	/* setter fonksiyonlari ile gerekli degisiklikler yapilir. */
	vector1.setX(4.4);
	vector1.setZ(5.2);
	vector2.setY(6.6);
	vector3.setZ(8.8);
	vector4.setX(2.2);
	vector5.setX(0.8);
	vector5.setZ(3.6);

	cout << "\n--Set edildikten sonra objeler--\n";

	cout << "\n1. Vector \n";
	vector1.output();
	cout << "\n2. Vector \n";
	vector2.output();
	cout << "\n3. Vector \n";
	vector3.output();
	cout << "\n4. Vector \n";
	vector4.output();
	cout << "\n5. Vector \n";
	vector5.output();

	/* 1. ornek */

	/* dot product yapilir */
	cout << "\nvector1 ve vector4 ile yapilan "
		<< "dot Product isleminin sonucu: "
		<< vector1.dotProduct(vector4) << endl;

	/* cross product yapilir */	
	vector6 = vector2.crossProduct(vector5);
	
	cout << "\nvector2 ve vector5 ile yapilan cross "
		<< "Product isleminin sonucunda olusan yeni vector: \n";
	vector6.output();

	/* vectorun magnitude (buyuklugu) bulunur. */
	cout << "\nvector3 un buyuklugu (magnitude) "
		<< vector3.magnitude() << endl;

	/* 2. ornek */

	/* dot product yapilir */
	cout << "\nvector2 ve vector3 ile yapilan "
		<< "dot Product isleminin sonucu: "
		<< vector2.dotProduct(vector3) << endl;

	/* cross product yapilir */	
	vector6 = vector3.crossProduct(vector1);
	
	cout << "\nvector3 ve vector1 ile yapilan cross "
		<< "Product isleminin sonucunda olusan yeni vector: \n";
	vector6.output();

	/* vectorun magnitude (buyuklugu) bulunur. */
	cout << "\nvector5 un buyuklugu (magnitude) "
		<< vector5.magnitude() << endl;
	
	cout << "\nCall-by-value ile gonderilen bir "
		<< "obje uzerinde yapilan degisiklikler "
		<< "disariya yansimaz. \nObje gonderilirken "
		<< "bir kopyasi olusur ve o kopya uzerinde "
		<< "degisiklik yapilir. \nYapilan degisiklikler "
		<< "fonksiyon disina yansimaz.\n\n";

	/* call-by-value ornegi */
	cout << "Call-By-Value yapan fonksiyonun icinde vector6: \n";
	vector1.CBValue(vector6);
	
	cout << "\nFonksiyon icinde obje elemanlari "
		<< "degistirilir. \nAma disarida tekrer objenin "
		<< "eski hali kullanilir." << endl;

	cout << "\nMainde vector6: \n";
	vector6.output();
	cout << endl;

	cout << "\nCall-by-reference ile gonderilen bir "
		<< "obje uzerinde yapilan degisiklikler "
		<< "disariya da yansir. \nObje gonderilirken "
		<< "bir kopyasi olusmaz ve objenin kendisi uzerinde "
		<< "degisiklik yapilir. \nYapilan degisiklikler "
		<< "fonksiyonun disina da yansir.\n\n";

	/* call-by-reference ornegi */
	cout << "Call-By-Reference yapan fonksiyonun icinde vector6: \n";
	vector1.CBReferance(vector6);
	cout << endl;

	cout << "\nFonksiyon icinde obje elemanlari "
		<< "degistirilir. \nDisarida objenin "
		<< "degismis hali kullanilir." << endl;

	cout << "\nMainde vector6: \n";
	vector6.output();
	cout << endl;

	return 0;
}

/*############# END OF THE PROGRAM #############*/
