#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void Courier::addcourier (string courierfile)
{
	ifstream fin;
	ofstream fout;
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	string s;
	cout << "Enter the courier you want to put('name /n phone  /n car(0 or 1)')"<<endl;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	int sidc;	
	string sname;
	string sphone;
	int sorderid1;
	int sorderid2;
	int scar; 
	int sdeliverytime;		
	Courier *a = new Courier[k+1];
	fin.close();
	fin.open(courierfile);	
	for (i=0; i<k; i++){
		fin >> sidc;
		fin >> sname ;
		fin >> sphone;
		fin >> sorderid1;
		fin >> sorderid2;
		fin >> scar;
		fin >> sdeliverytime;
		a[i].setidc(sidc);
		a[i].setname(sname);
		a[i].setphone(sphone);
		a[i].setorderid1(sorderid1);
		a[i].setorderid2(sorderid2);
		a[i].setcar(scar);
		a[i].setdeliverytime(sdeliverytime);
	}
	int j;
	cin >>sname>>sphone>>scar;
	sidc=k+1;
	int f=0;
	while(f==0){
		f=1;
		for (i=0; i<k; i++){
			if (a[i].getidc()== sidc){ 
				f=0;
				sidc=sidc+1;	
			}
			if (a[i].getname()== sname){ 
				cout <<"courier with same name already exists. Try the other one"<<endl;
				fin.close();
				exit(0);	
			}
			if (a[i].getphone()== sphone){ 
				cout <<"courier with same phone already exists. Try the other one"<<endl;
				fin.close();
				exit(0);	
			}
		}
	}
	fin.close();
	a[k].setidc(sidc);
	a[k].setname(sname);
	a[k].setphone(sphone);
	a[k].setorderid1(0);
	a[k].setorderid2(0);
	a[k].setcar(scar);
	a[k].setdeliverytime(30-scar*20);
	fout.open(courierfile, ios::out);
	for (i=0; i<k+1; i++){
		fout << a[i].getidc() <<" "<<a[i].getname()<<" "<<a[i].getphone()<<" "<<a[i].getorderid1()<<" "<<a[i].getorderid2()<<" "<<a[i].getcar()<<" "<<a[i].getdeliverytime()<<endl;
	}
	fout.close();
	delete [] a;
}
