#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void Order::osearchid(string orderfile){//поиск заказа по id
	ifstream fin;
	ofstream fout;	
	fin.open(orderfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the id you want to find"<<endl;
	string s;
	while (!fin.eof()){//количество строк
		getline(fin, s);
		k++;
	}
	k--;
	Order *a = new Order[k+1];//массив из заказов
	fin.close();
	fin.open(orderfile);
	int sido;
        int sprice;
        int sdeadline;
        string saddress;
        int scourierid;
        int sdtime;
	for (i=0; i<k; i++){
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
	int tmp=-1;
	cin >>sido;//искомый id
	for (i=0; i<k; i++){ 
		if (a[i].getido()==sido){//ищем id, выводим, если есть 
			cout << a[i].getido() <<" "<<a[i].getprice()<<" "<<a[i].getdeadline()<<" "<<a[i].getdtime()<<" "<<a[i].getaddress()<<" "<<a[i].getcourierid()<<endl;
			tmp=1;		
		} 
	}
	if (tmp==-1){//если не было совпадений
		cout<<"---------------There's no such id---------------"<<endl;
	}	
	fout.close();
	delete[]a;//уборка
}
