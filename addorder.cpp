#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void addorder (string orderfile){
	ifstream fin;
	ofstream fout;
	fin.open(orderfile);	
	int  i=0;
	int k=0;
	string s;
	cout << "Enter the order you want to put('price(integer) /n deadline(minutes) /n address(one word) "<<endl;
	while (!fin.eof()){//считаем количество строк в файле
		getline(fin, s);
		k++;
	}
	k--;
	Order*a = new Order[k+1];//выделяем память
	fin.close();
	int sido;
        int sprice;
        int sdeadline;
        string saddress;
        int scourierid;
        int sdtime;
	fin.open(orderfile);	
	for (i=0; i<k; i++){//считываем из файла данные в массив 
		fin >> sido;
		fin >> sprice ;
		fin >> sdeadline;
		fin >> sdtime;
		fin >> saddress;
		fin >> scourierid;
		a[i].setido(sido);
		a[i].setprice(sprice);
		a[i].setdeadline(sdeadline);
		a[i].setdtime(sdtime);
		a[i].setaddress(saddress);
		a[i].setcourierid(scourierid);
	}
	int j, l=0;
	
	while(l==0){
		l=1;
		cin >>sprice>>sdeadline>>saddress;//спрашиваем данные о добавляемом заказе, остальные данные присваиваем автоматически
		if(sdeadline<10){
			cout << "Sorry, we can't deliver your order that fast. Please, try again"<<endl;
			l=0;
		}
	}		
	sido=k+1;
	sdtime=sdeadline;
	while(l==0){//проверка на совпадение id
		l=1;
		for(j=0;j<k;j++){
			if (a[j].getido()==sido){
				sido=sido+1;
				l=0;
			}
		}
	}					
	fin.close();
	a[k].setido(sido);
	a[k].setprice(sprice);	
	a[k].setdeadline(sdeadline);
	a[k].setdtime(sdtime);
	a[k].setaddress(saddress);
	a[k].setcourierid(0);
	fout.open(orderfile, ios::out);
	for (i=0; i<k+1; i++){//перезаписываем в файл массив
		fout << a[i].getido() <<" "<<a[i].getprice()<<" "<<a[i].getdeadline()<<" "<<a[i].getdtime()<<" "<<a[i].getaddress()<<" "<<a[i].getcourierid()<<endl;
	}
	fout.close();
	delete [] a;//уборка
}
