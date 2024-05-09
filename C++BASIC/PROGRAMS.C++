//Double Right Triangle Made of Stars
#include<iostream>
using namespace std;
int main()
{
	int i ,j,k;
		for (i=1 ;i<=5 ;i++)
	{
		for(k=i;k<=5 ;k++)
		cout<<" ";
		for(j=1;j<=i;j++)
  	{
		cout<<" *";
	
     }
	
    cout<<endl;
}
	for (i=1 ;i<=4 ;i++)
	{
		for(k=0;k<=i ;k++)
		cout<<" ";
		for(j=4;j>=i;j--)
  	{
		cout<<" *";
	
     }
	
    cout<<endl;
}

}


// Write a program that displays first five numbers and their sum using “While” loop.
#include<iostream>
using namespace std;
int main ()
{
	int i = 1,sum=0;
	while (i <= 5)
	{
		cout << i<<"\n";
		sum += i;
		i++;
	}
	cout << "sum" << sum;
	return 0;
}


//Write a program that displays your name and arid no for five time using “Do-while” loop.
#include<iostream>
using namespace std;
int main()
{
	int i = 1;
	char  name[8] = "zaheer";
	string arid_no = "22-arid-738";
	do 
	{
		cout << name << "\n";
		cout << "arid no" << arid_no << "\n";
		i++;
	} while (i <= 5);

	return 0;
}


//Write a program that displays first five numbers with their squares using “While” loop.
#include<iostream>
using namespace std;
int main()
{
	int i =1 ;
	
	while (i <= 5)
	{
		cout << "number" << i<<"\n";
		cout << "SQUARE" << i*i<<"\n";
		i++;
	}
	
	return 0;
}


// Write a program that inputs a number from user and displays a table of that using “While” loop.
#include<iostream>
using namespace std;
int main()
{
	int i=1, a ;
	cout << "enter an number";
	cin >> a;
	while ( i<=10 )
	{
		cout << a << "*" << i << "="<<i*a <<"\n";
	    i++;
	}

	return 0;
}


// Write a program that displays back-counting from 10 to 1 using “Do-While” loop.
#include<iostream>
using namespace std;
int main()
{
	int i = 10;
	do
	{
		cout << i << endl;
		--i;
		
	} 
	while( i >= 1 );

	return 0;
}

// Write a program that gets starting &amp; ending point from the user &amp; displays all odd
// numbers in the given range using “Do-While” loop.
#include<iostream>
using namespace std;
int main()
{
	int i ,st,end;
	cout << "enter starting point";
	cin >> st;
	cout << "enter ending point";
	cin >> end ;
	 i = st; 
	 do
	{
		 if (i % 2 == 1)
			 cout << i << endl;
			 i++;
	}
	 while (i <= end);
	return 0;
}


// Write a program that displays product of all odd numbers from 1 to 10 using “for” loop.
#include<iostream>
using namespace std;
int main()
{
	int prod = 1;
	for (int i = 1;i<=10 ; i++)
	{
		if (i % 2 == 1)
			prod *= i;
			 i++;
	}
	cout << prod << endl;
	return 0;
}


// Write a program that inputs table number &amp; length of table and then displays the table
using “for” loop.
#include<iostream>
using namespace std;
int main()
{
	int lenght, number;
	cout << "enter  length of table";
	cin >> lenght ;
	cout << "enter table number";
	cin >> number ;


	for (int i = 1;i<=lenght ; i++)
	{
		cout << number << "*" << i << "=" << i*number << "\n";
		}

	return 0;
}


// Write a program that finds the sum of the squares of integers from 1 to n. Where n is a
// positive value entered by the user (i.e Sum= 1 2 +2 2 +3 2 +….+n 2 ). Hint: Use “for” loop.
#include<iostream>
using namespace std;
int main()
{
	int n, square=1,sum=0;
	cout << "enter positive integer";
	cin >> n;

	for (int i = 1;i<=n ; i++)
	{
		square = i * i;
		sum += square;
		
	}
	cout << sum;

	return 0;
}


// Convert Case of a Character                                           
#include <iostream>
using namespace std ;

int main() {
char ch;
string str;
cout<<"enter a char\n";
cin>>ch;
 if(ch>='a'&& ch <='z')
 {cout<<"\nyou entered a lower case\n";
 ch=ch-32;
 cout<<"the uppercase alphabet\n"<<ch;
 }
 else
 {
     cout<<"you entered a lower case alphabet\n";
     ch=ch+32;
     cout<<"the uppr alphaber is \n"<<ch;
 }
    return 0;
}

// Right Angle Triangle with Stars
#include <iostream>
using namespace std;
int main() {
    int n = 20;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (i >= j)
                cout << " *";
            else
                cout << " ";
        }
        cout << endl;
    }
    return 0;
}

// Inverted Right Angle Triangle with Stars and Message
#include <iostream>
using namespace std;
int main() {
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        for (int j = n; j >= 1; j--)
        {
            if (i >= j)
                cout << " * ";
            else
                cout << " ";
        }
        cout << endl;
        } //                       /@   ZAHEER AHMAD   @/
    cout << "*  *  *  *  *  *  *  *  *  *  *";
    cout << endl;
    for (int k = 10; k >= 1; k--)
    {
        for (int space = k; space < 10; space++)
            cout << " ";
    
        for (int m = 1; m <= 10; m++)
            if(k>=m)
            cout << " * ";

        cout << "\n";
    }
    cout << "\t Take care";
    return 0;
}


// IMPLEMENTATION OF 0OP CONCEPTS IN C++     
#include <iostream>
#include <string>
using namespace std;
class Vehicle {
protected:
   string modelName;
   string registrationNumber;
   string owner;
public:
   Vehicle() {}
   Vehicle(string M_NO, string R_NO, string OWN) {
       modelName = M_NO;
       registrationNumber = R_NO;
       owner = OWN;
   }
   string getModelName() {
       return modelName;
   }
   void setModelName(string m) {
       modelName = m;}
   string getRegistrationNumber() {
       return registrationNumber;}
   void setRegistrationNumber(string rNumber) {
       registrationNumber = rNumber;}
   string getOwner()
   {
       return owner;}
   void setOwner(string own) {
       owner = own; }
   string display() {
       return "Model Name: " + modelName + "\nRegistration Number: " + registrationNumber + "\nOwner: " + owner;}
};
class Car : public Vehicle {
private:
   string trunkDimension;
public:
   Car() {}
   Car(string modelName, string registrationNumber, string owner, string tru_Dimen) : Vehicle(modelName, registrationNumber, owner) {
       trunkDimension = tru_Dimen;
   }

   string getTrunkDimension() {
       return trunkDimension;}
   void setTrunkDimension(string tru_Dimen) {
       trunkDimension = tru_Dimen;}
   string display() {
       return Vehicle::display() + "\nTrunk Dimension: " + trunkDimension;}};
class Truck : public Vehicle {
private:
   string cargo_bed;
public:
   Truck() {}
   Truck(string modelName, string registrationNumber, string owner, string cgbed) : Vehicle(modelName, registrationNumber, owner) {
       cargo_bed = cgbed;}
   string getCargoBed() {
       return  cargo_bed; }
   void setTrunkDimension(string cgbed) {
       cargo_bed = cgbed; }
   string display() {
       return Vehicle::display() + "\n Cargo bed Dimension: " + cargo_bed;}
};
int main()
{
   Car c("camry", "22toyota12 ", "ZAHEER", "200X200x500mm");
   Truck t("hilux", "ford", "MOIZ ABDULLAH", "217.5m");
   cout << "ZAHEER CODE \n ARID NO 738\n ";
   cout << c.display() << endl;
   cout << t.display();
   return 0;
   }


// DIFFERENT STRING OPERATIONS IN C++
#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str1 = "Zaheer";
	string str2 = "Ahmad";
	cout << "\t  PROGRAM NO  1" << endl;
	cout << "length of string 1 : " << str1.length() << endl;

	string str3 = str1 + " " + str2;
	cout << endl <<"\t PROGRAM NO  2" << endl;
	cout << "  Concatenation of string 1 and string 2 : " << str3 << endl;
	cout << endl << "\t program no 9" << endl;
	cout << "  First character of string no 1 is : " << str1[0] << endl;

	string  str4 = str3.substr(5, 7);
	cout <<endl <<"\t PROGRAM NO  4" << endl;
	cout << " Substring of string 3 is : " << str4 << endl;

		 if (str1 == "Zaheer") {
			 cout <<endl<< "\t PROGRAM NO  5" << endl;
			 cout << " string ABC IS EQUAL TO 'ZAHEER' " << endl;
		 }

		 int POSITION = str3.find("Zaheer"); 
		 if (POSITION != string::npos) {
			 cout <<endl<< "\t PROGRAM NO  6" << endl;
			 cout << "'r' is found in string 3 at position        \t" << POSITION << endl;
		 }

		 int pos2 = str3.rfind("l"); 
		 if (pos2 != string::npos) {
			 cout <<endl<< "\t PROGRAM NO  7" << endl;
			 cout << "'l' found in str3 at position               \t" << pos2 << endl;
		 }

		 str1.insert(6, " there");
		 cout <<endl<< "\t PROGRAM NO  8" << endl;
		 cout << "After inserting ' there' in string 1:            \t" << str1 << endl;

		 str3.replace(6, 6, "everyone");
		 cout <<endl<< "\t PROGRAM NO  9" << endl;
		 cout << "After replacing 'ahmad' with 'everyone' in str3: \t" << str3 << endl;

		 
		 str2.erase(2, 3); 	
		 cout <<endl<< "\t PROGRAM NO  10" << endl;
		 cout << "After erasing characters in string 2:           \t" << str2 << endl;

		 return 0;
	 }


// DIFFERENT FILE OPERATIONS 
#include <iostream>
#include <fstream>
using namespace std;
int main() {
   streampos positionp, positionp2, begin, pointera;
   int m = 4;
   fstream file;
   file.open("zaheerprogram.txt");
   cout << "my name is zaheer ahmad and this is my oop assignment code" << endl;
   cout << "implementing fuction of file handling" << endl;
   file << "my name is zaheer ahmad" << endl;
   file << "i m writing an oop program" << endl;
   positionp = file.tellp();
   cout << "current position of put pointer = " << positionp << endl;
   file.seekp(10, ios::end);
   file << "i'm using file pointers" << endl;
   positionp2 = file.tellp();
   cout << "position after using seekp() function = " << positionp2 << endl;
   file.close();
   file.open("zaheerprogram.txt", ios::out );
   cout << "Reading from file" << endl;
   begin = file.tellg();
   cout << "position of get pointer = " << begin << endl;
   file.seekg(0, ios::beg);
   pointera = file.tellg();
   cout << "position after using seekg() function = " << pointera << endl;
   file.seekg(0, ios::cur);
   pointera = file.tellg();
   cout << "position after using seekg() function = " << pointera << endl;
   file.seekg(0, ios::end);
   pointera = file.tellg();
   cout << "position after using seekg() function = " << pointera << endl;
   file.seekg(m, ios::beg);
   pointera = file.tellg();
   cout << "position after using seekg() function = " << pointera << endl;
   file.seekg(m, ios::cur);
   pointera = file.tellg();
   cout << "position after using seekg() function = " << pointera << endl;
   file.seekg(-m, ios::cur);
   pointera = file.tellg();
   cout << "position after using seekg() function = " << pointera << endl;
   file.seekg(-m, ios::end);
   pointera = file.tellg();
   cout << "position after using seekg() function = " << pointera << endl;
   file.close();
   return 0;
}


// SIMPLE OOP PROGRAM
#include <iostream>
#include<string>
using namespace std;
class mytype {
private:
	int value;
public:
	mytype(int val) :value(val) {}

};

int main() {

	mytype obj(8);
	cout<<
}