/*
 *               Murat ALTUNTAS
 *                111044043
 *             HW02_111044043.cpp
 *         Herhangi bir arrayin siralanmis
 *  haldeki n. indexteki elemanini donduren program
 */
#include <iostream>
#include <cstdlib> /* malloc */

using namespace std;

class DayOfYear
{
public:
	/* setters and getters */
	void setDay(int newDay);
	void setMonth(int newMonth);
	void setYear(int newYear);
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear(){ return year; }
private:
	int year;  /* yil */
	int month; /* ay */
	int day;   /* gun */
};

class Person
{
public:
	/* setters and getters */
	void setAge(int newAge);
	void setWeight(int newWeight);
	void setLength(int newLength);
	void setSex(char newSex);
	int getAge() { return age; }
	int getWeight() { return weight; }
	int getLength() { return length; }
	char getSex(){ return sex; }
private:
	int age;    /* Yas */
	int weight; /* Kilo */
	int length; /* Boy */
	char sex;   /* Cinsiyet */
};

/**************** PROTOTYPES ****************/
/* Compare function for integer */
int compareInt (const void * a, const void * b);
/* Compare function for double */
int compareDouble (const void * a, const void * b);
/* Compare function for character */
int compareChar (const void * a, const void * b);
/* Compare function for Person age */
int comparePerson_age (const void * a, const void * b);
/* Compare function for Person weight */
int comparePerson_weight (const void * a, const void * b);
/* Compare function for DayOfYear day */
int compareDayOfYear_day (const void * a, const void * b);
/* Compare function for Person */
int comparePerson(Person p1, Person p2);
/* Compare function for DayOfYear */
int compareDayOfYear(DayOfYear d1, DayOfYear d2);
/* Sort Functions for integer */
int mySort(int arr[], size_t size, int nth, int (* comparator) (const void *, const void *));
/* Sort Functions for double */
double mySort(double arr[], size_t size, int nth, int (* comparator) (const void *, const void *));
/* Sort Functions for character */
char mySort(char arr[], size_t size, int nth, int (* comparator) (const void *, const void *));
/* Sort Functions for Person age */
Person mySort(Person *arr, size_t size, int nth, int (* comparator) (const void *, const void *));
/* Sort Functions for DayOfYear day */
DayOfYear mySort(DayOfYear *arr, size_t size, int nth, int (* comparator) (const void *, const void *));
/* dizinin sirali haldeki n. indexli elemanini donduren fonksiyon */
void * return_nth (const void * base,
				size_t num, size_t size,
				int nth, int (* comparator) (const void *, const void *));
/************* END OF PROTOTYPES *************/

int main()
{
	int *ptrInt;        /* integer pointer */
	double *ptrDouble;  /* double pointer */
	char *ptrChar;      /* character pointer */
	Person *ptrPerson;  /* Person pointer */
	Person *ptrPerson2; /* Person2 pointer */
	DayOfYear *ptrDayOfYear; /* DayOfYear pointer */
	int nthItem = 5;    /* n. eleman */

	int intArr[] = { 9,2,11,3,1,5,7 }; // 7 boyutlu array
	double doubleArr[] = { 5.6, 9.8, 7.6, 2.9, 11.1, 1.11, 3.15 }; // 7 boyutlu array
	char charArr[] = { 'd', 'b', 'f', 'c', 'a', 'e', 'k', 'g'}; // 8 boyutlu array
	Person human[6]; // 6 boyutlu array
	DayOfYear day[9]; // 9 boyutlu array
	
	/* Person dizisine age ve weight degerleri atanir. */
	human[0].setAge(15);
	human[1].setAge(23);
	human[2].setAge(26);
	human[3].setAge(14);
	human[4].setAge(10);
	human[5].setAge(12);

	human[0].setWeight(95);
	human[1].setWeight(81);
	human[2].setWeight(62);
	human[3].setWeight(59);
	human[4].setWeight(100);
	human[5].setWeight(78);

	/* DayOfYear dizisine day degerleri atanir. */
	day[0].setDay(14);
	day[1].setDay(12);
	day[2].setDay(21);
	day[3].setDay(5);
	day[4].setDay(3);
	day[5].setDay(7);
	day[6].setDay(2);
	day[7].setDay(8);
	day[8].setDay(15);

	cout << "--Dizilerin ilk hali.--";

	cout << endl << "int: ";
		for (int i = 0; i < 7; ++i)
			cout << intArr[i] << " ";

	cout << endl << "double: ";
		for (int i = 0; i < 7; ++i)
			cout << doubleArr[i] << " ";

	cout << endl << "char: ";
		for (int i = 0; i < 8; ++i)
			cout << charArr[i] << " ";

	cout << endl << "Person Age: ";
		for (int i = 0; i < 6; ++i)
			cout << human[i].getAge() << " ";

	cout << endl << "Person Weight: ";
		for (int i = 0; i < 6; ++i)
			cout << human[i].getWeight() << " ";

	cout << endl << "DayOfYear Day: ";
		for (int i = 0; i < 9; ++i)
			cout << day[i].getDay() << " ";

	cout << endl << endl;

	ptrInt  = (int*) return_nth(intArr,7,sizeof(int),nthItem,compareInt);
	ptrDouble  = (double*) return_nth(doubleArr,7,sizeof(double),nthItem,compareDouble);
	ptrChar  = (char*) return_nth(charArr,8,sizeof(char),nthItem,compareChar);
	ptrPerson = (Person*) return_nth(human,6,sizeof(Person),nthItem,comparePerson_age);
	ptrPerson2 = (Person*) return_nth(human,6,sizeof(Person),nthItem,comparePerson_weight);
	ptrDayOfYear = (DayOfYear*) return_nth(day,9,sizeof(DayOfYear),nthItem,compareDayOfYear_day);

	cout << "--Diziler artan siraya gore siralanmistir.--\n";
	if (ptrInt != NULL)
	{
		cout << "integer dizinin sirali halindeki ["
			<< nthItem << "] indexli elemani: " 
			<< *ptrInt << endl;
	}
	else
		cout << "integer dizinin [" << nthItem
			<< "] indexli elemani yoktur.\n";

	if (ptrDouble != NULL)
	{
		cout << "double dizinin sirali halindeki ["
			<< nthItem << "] indexli elemani: " 
			<< *ptrDouble << endl;
	}
	else
		cout << "double dizinin [" << nthItem
			<< "] indexli elemani yoktur.\n";

	if (ptrChar != NULL)
	{
		cout << "character dizisinin sirali halindeki ["
			<< nthItem << "] indexli elemani: " 
			<< *ptrChar << endl;
	}
	else
		cout << "character dizisinin [" << nthItem
			<< "] indexli elemani yoktur.\n";

	if (ptrPerson != NULL)
	{
		cout << "Person dizisinin age'e gore sirali halindeki ["
			<< nthItem << "] indexli elemani: " 
			<< (*ptrPerson).getAge() << endl;
	}
	else
		cout << "Person dizisinin [" << nthItem
			<< "] indexli elemani yoktur.\n";

	if (ptrPerson2 != NULL)
	{
		cout << "Person dizisinin kiloya gore sirali halindeki ["
			<< nthItem << "] indexli elemani: " 
			<< (*ptrPerson2).getWeight() << endl;
	}
	else
		cout << "Person dizisinin [" << nthItem
			<< "] indexli elemani yoktur.\n";

	if (ptrDayOfYear != NULL)
	{
		cout << "DayOfYear dizisinin day'a gore sirali halindeki ["
			<< nthItem << "] indexli elemani: " 
			<< (*ptrDayOfYear).getDay() << endl;
	}
	else
		cout << "DayOfYear dizisinin [" << nthItem
			<< "] indexli elemani yoktur.\n";

	cout << "\n--Dizilerin son hali.--";

	cout << endl << "int: ";
		for (int i = 0; i < 7; ++i)
			cout << intArr[i] << " ";

	cout << endl << "double: ";
		for (int i = 0; i < 7; ++i)
			cout << doubleArr[i] << " ";

	cout << endl << "char: ";
		for (int i = 0; i < 8; ++i)
			cout << charArr[i] << " ";

	cout << endl << "Person Age: ";
		for (int i = 0; i < 6; ++i)
			cout << human[i].getAge() << " ";

	cout << endl << "Person Weight: ";
		for (int i = 0; i < 6; ++i)
			cout << human[i].getWeight() << " ";

	cout << endl << "DayOfYear Day: ";
		for (int i = 0; i < 9; ++i)
			cout << day[i].getDay() << " ";

	cout << "\n--Dizilerin iceriginde"
		<< " degisiklik yapilmamistir.--\n";

	return 0;
}

/* DayOfYear setters */
void DayOfYear::setDay(int newDay)
{
	if ((newDay >= 1) && (newDay <= 31))
		day = newDay;
	else
		day = 1;
	/* 1 - 31 disindaki her sayi yanlis
	oldugu icin otomatik olarak 1 atanir. */
}

void DayOfYear::setMonth(int newMonth)
{
	if ((newMonth >= 1) && (newMonth <= 12))
		month = newMonth;
	else
		month = 1;
		/* 1 - 12 disindaki her sayi yanlis
		oldugu icin otomatik olarak 1 atanir. */

}

void DayOfYear::setYear(int newYear)
{
	if ( newYear > 0 )
		year = newYear;
	else
		year = 1900;
}

/* Person Setters */
void Person::setAge(int newAge)
{
	if ( newAge > 0 )
		age = newAge;
	else
		age = 1;
}

void Person::setWeight(int newWeight)
{
	if ( newWeight > 0 )
		weight = newWeight;
	else
		weight = 1;
}

void Person::setLength(int newLength)
{
	if ( newLength > 0 )
		length = newLength;
	else
		length = 1;
}

void Person::setSex(char newSex)
{
	if ((newSex == 'E') ||  (newSex == 'e'))
		sex = newSex;
	else
		sex = 'K';
}

/* compare integer */
int compareInt (const void * a, const void * b)
{
  if ( *(int*)a <  *(int*)b ) return -1;
  if ( *(int*)a == *(int*)b ) return 0;
  if ( *(int*)a >  *(int*)b ) return 1;
}

/* compare Double */
int compareDouble (const void * a, const void * b)
{
  if ( *(double*)a <  *(double*)b ) return -1;
  if ( *(double*)a == *(double*)b ) return 0;
  if ( *(double*)a >  *(double*)b ) return 1;
}

/* compare character */
int compareChar (const void * a, const void * b)
{
  if ( *(char*)a <  *(char*)b ) return -1;
  if ( *(char*)a == *(char*)b ) return 0;
  if ( *(char*)a >  *(char*)b ) return 1;
}

/* compare Person Age */
int comparePerson_age (const void * a, const void * b)
{
  if ( (*(Person*)a).getAge() <  (*(Person*)b).getAge() ) return -1;
  if ( (*(Person*)a).getAge() == (*(Person*)b).getAge() ) return 0;
  if ( (*(Person*)a).getAge() >  (*(Person*)b).getAge() ) return 1;
}

/* compare Person Weight */
int comparePerson_weight (const void * a, const void * b)
{
  if ( (*(Person*)a).getWeight() <  (*(Person*)b).getWeight() ) return -1;
  if ( (*(Person*)a).getWeight() == (*(Person*)b).getWeight() ) return 0;
  if ( (*(Person*)a).getWeight() >  (*(Person*)b).getWeight() ) return 1;
}

/* compare DayOfYear Day */
int compareDayOfYear_day (const void * a, const void * b)
{
  if ( (*(DayOfYear*)a).getDay() <  (*(DayOfYear*)b).getDay() ) return -1;
  if ( (*(DayOfYear*)a).getDay() == (*(DayOfYear*)b).getDay() ) return 0;
  if ( (*(DayOfYear*)a).getDay() >  (*(DayOfYear*)b).getDay() ) return 1;	
}

/* iki Person objesini Age ve Weight'e gore esit
	olup olmadigini kontrol eden fonksiyon */
int comparePerson(Person p1, Person p2)
{
	if (p1.getAge() == p2.getAge())
	{
		if (p1.getWeight() == p2.getWeight())
		{
			return 1;
		}
	}
	return 0;
}

/* iki DayOfYear objesini day'e gore esit
	olup olmadigini kontrol eden fonksiyon */
int compareDayOfYear(DayOfYear d1, DayOfYear d2)
{
	if (d1.getDay() == d2.getDay())
	{
		return 1;	
	}
	return 0;
}

/* integer siralama */
int mySort(int arr[], size_t size, int nth, int (* comparator) (const void *, const void *))
{
	int i,j; /* index */
	int tmp; /* gecici degisken */

	/* bubble sort */
	for(i=0; i<size-1; i++)
		for(j=0; j<size-1; j++)
			if(comparator(arr+j,arr+j+1) == 1)
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}

return *(arr+nth);
}

/* double siralama */
double mySort(double arr[], size_t size, int nth, int (* comparator) (const void *, const void *))
{
	int i,j; /* index */
	double tmp; /* gecici degisken */

	for(i=0; i<size-1; i++)
		for(j=0; j<size-1; j++)
			if(comparator(arr+j,arr+j+1) == 1)
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}

return *(arr+nth);
}

/* character siralama */
char mySort(char arr[], size_t size, int nth, int (* comparator) (const void *, const void *))
{
	int i,j; /* index */
	char tmp; /* gecici degisken */

	for(i=0; i<size-1; i++)
		for(j=0; j<size-1; j++)
			if(comparator(arr+j,arr+j+1) == 1)
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}

return *(arr+nth);
}

/* Person Age siralama */
Person mySort(Person *arr, size_t size, int nth, int (* comparator) (const void *, const void *))
{
	int i,j; /* index */
	Person tmp; /* gecici degisken */

	for(i=0; i<size-1; i++)
		for(j=0; j<size-1; j++)
			if(comparator(arr+j,arr+j+1) == 1)
			{
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}

return *(arr+nth);
}

/* DayOfYear Day siralama */
DayOfYear mySort(DayOfYear *arr, size_t size, int nth, int (* comparator) (const void *, const void *))
{
	int i,j; /* index */
	DayOfYear tmp; /* gecici degisken */

	for(i=0; i<size-1; i++)
		for(j=0; j<size-1; j++)
			if(comparator(arr+j,arr+j+1) == 1)
			{
				tmp.setDay(arr[j].getDay());
				arr[j].setDay(arr[j+1].getDay());
				arr[j+1].setDay(tmp.getDay());
			}

return *(arr+nth);
}

void * return_nth (const void * base,
				size_t num, size_t size,
				int nth, int (* comparator) (const void *, const void *))
{
	/* gecersiz index girildiginde NULL return eder. */
	if ((nth > (num)) || (nth < 0))
	{
		return NULL;
	}

	int i; /* for index */

	if (size == sizeof(int)) /* 4 byte (int) */
	{
		int nItem;   /* sirali dizideki n. eleman */
		int *ptrInt; /* integer pointer */
		/* Malloc ile dizi tipinde, dizi boyutu kadar yer alinir. */
		ptrInt = (int*)malloc(size * num);
		
		/* asil dizinin elemanlari gecici diziye kopyalanir. */
		for (i = 0; i < num; ++i)
		{
			ptrInt[i]=*(int*)(base + i*sizeof(int));
		}

		/* Gecici dizi siralama fonksiyonunda siralanaip n. eleman dondurulur. */
		nItem=mySort(ptrInt, num, nth, comparator);

		/* n. eleman asil dizide bulunup return edilir. */
		for (i = 0; i < num; ++i)
		{
			if (nItem == *(int*)(base + i*sizeof(int)))
			{
				free(ptrInt);
				return (void *)base + i * size;
			}	
		}
	}
	else if (size == sizeof(double)) /* 8 byte (double) */
	{
		double nItem; /* sirali dizideki n. eleman */
		double *ptrDouble; /* double pointer */
		ptrDouble = (double*)malloc(size * num);
		

		for (i = 0; i < num; ++i)
		{
			ptrDouble[i]=*(double*)(base + i*sizeof(double));
		}

		nItem=mySort(ptrDouble, num, nth, comparator);

		for (i = 0; i < num; ++i)
		{
			if (nItem == *(double*)(base + i*sizeof(double)))
			{
				free(ptrDouble);
				return (void *)base + i * size;
			}	
		}
	}
	else if (size == sizeof(char)) /* 1 byte (char) */
	{
		char nItem; /* sirali dizideki n. eleman */
		char *ptrChar; /* character pointer */
		ptrChar = (char*)malloc(size * num);
		

		for (i = 0; i < num; ++i)
		{
			ptrChar[i]=*(char*)(base + i*sizeof(char));
		}

		nItem=mySort(ptrChar, num, nth, comparator);

		for (i = 0; i < num; ++i)
		{
			if (nItem == *(char*)(base + i*sizeof(char)))
			{
				free(ptrChar);
				return (void *)base + i * size;
			}	
		}
	}
	else if (size == sizeof(Person)) /* 16 byte (Person) */
	{
		Person nItem; /* sirali dizideki n. eleman */
		Person *ptrPerson; /* Person pointer */
		ptrPerson = (Person*)malloc(size * num);
		

		for (i = 0; i < num; ++i)
		{
			ptrPerson[i]=*(Person*)(base + i*sizeof(Person));
		}

		nItem=mySort(ptrPerson, num, nth, comparator);

		for (i = 0; i < num; ++i)
		{
			if (comparePerson(nItem, *(Person*)(base + i*sizeof(Person))))
			{
				free(ptrPerson);
				return (void *)base + i * size;
			}
		}
	}
	else if (size == sizeof(DayOfYear)) /* 12 byte (DayOfYear) */
	{
		DayOfYear nItem; /* sirali dizideki n. eleman */
		DayOfYear *ptrDayOfYear; /* DayOfYear pointer */
		ptrDayOfYear = (DayOfYear*)malloc(size * num);
		

		for (i = 0; i < num; ++i)
		{
			ptrDayOfYear[i]=*(DayOfYear*)(base + i*sizeof(DayOfYear));
		}

		nItem=mySort(ptrDayOfYear, num, nth, comparator);

		for (i = 0; i < num; ++i)
		{
			if (compareDayOfYear(nItem, *(DayOfYear*)(base + i*sizeof(DayOfYear))))
			{	
				free(ptrDayOfYear);
				return (void *)base + i * size;
			}
		}	
	}
	else
	{
		return NULL;
	}
}
/*########## END OF PROGRAM ##########*/