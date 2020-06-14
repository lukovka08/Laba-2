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
	fin.close();
	fin.open(courierfile);
	Courier *a = new Courier[k+1];//создаем массив объектов
	for (i=0; i<k; i++){
		fin >> a[i].idc;//считываем данные в массив
		fin >> a[i].name ;
		fin >> a[i].phone;
		fin >> a[i].orderid1;
		fin >> a[i].orderid2;
		fin >> a[i].car;
		fin >> a[i].deliverytime;
	}
	fin.close();
	fout.open(courierfile,ios::out);
	for (i=0; i<k; i++){ //перезаписываем данные курьеров обратно, но с id заказов и временем доставки =0
		fout << a[i].idc<<" " <<a[i].name <<" " << a[i].phone <<" " << 0<<" " << 0 <<" " << a[i].car<<" " << 0<<endl;
	}
	fout.close();
	delete[]a;

}
