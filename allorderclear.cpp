#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void allorderclear(string courierfile, string orderfile){
	ofstream f;
	f.open(orderfile, ios::out);//делаем пустым файл с заказами
	f.close();
	ifstream fin;
	ofstream fout;	
	fin.open(courierfile);	//открываем
	int  i=0;
	int k=0;
	string s;
	while (!fin.eof()){//считываем построчно, считаем строки
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
	fin.close();
	fout.open(courierfile,ios::out);
	for (i=0; i<k; i++){ //перезаписываем данные курьеров обратно, но с id заказов и временем доставки =0
		fout << a[i].getidc() <<" "<<a[i].getname()<<" "<<a[i].getphone()<<" "<<0<<" "<<0<<" "<<a[i].getcar()<<" "<<0<<endl;
	}
	fout.close();
	delete[]a;

}
