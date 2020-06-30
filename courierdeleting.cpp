#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;

void courierdeleting(string courierfile, string orderfile){//удаление курьера
	ifstream fin;
	ofstream fout;	
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the id you want to delete"<<endl;
	string s;
	int x1,x2;
	while (!fin.eof()){//считываем количество строк в файле курьеров
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
	Courier *a = new Courier[k+1];//создаем массив курьеров
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
	int tmp=-1;
	cin >> sidc;//считываем удаляемый id
	for (i=0; i<k; i++){ 
		if (a[i].getidc()== sidc){
			tmp=i;
			x1=a[i].getorderid1();//запоминаем номера его заказов
			x2=a[i].getorderid2();
		}
	}
	fin.close();	
	if (tmp>-1){//если такой курьер нашелся
		fout.open(courierfile, ios::out);
		for (i=0; i<k; i++){
			if(i!=tmp){//всех курьеров не с его id заносим в файл
				fout << a[i].getidc() <<" "<<a[i].getname()<<" "<<a[i].getphone()<<" "<<a[i].getorderid1()<<" "<<a[i].getorderid2()<<" "<<a[i].getcar()<<" "<<a[i].getdeliverytime()<<endl;
			}
		}
		fout.close();
	}
	else{//если не нашелся, то не перезаписываем файл
		cout<<"We don't have courier with this id. Please? try again"<<endl;
	}
	delete[]a;//уборка
	fin.open(orderfile);//начинаем работу с файлом заказов
	k=0;
	while (!fin.eof()){//считываем количество строк
		getline(fin, s);
		k++;
	}
	k--;
	int sido;
        int sprice;
        int sdeadline;
        string saddress;
        int scourierid;
        int sdtime;
        Order *b = new Order[k+1];//создаем массив заказов
	fin.close();
	fin.open(orderfile);
	for (i=0; i<k; i++){
		fin >> sido;
		fin >> sprice ;
		fin >> sdeadline;
		fin >> sdtime;
		fin >> saddress;
		fin >> scourierid;
		b[i].setido(sido);
		b[i].setprice(sprice);
		b[i].setdeadline(sdeadline);
		b[i].setdtime(sdtime);
		b[i].setaddress(saddress);
		b[i].setcourierid(scourierid);
		if ((b[i].getido()==x1)||(b[i].getido()==x1)){//заказы удаленного курьера делаем свободными
			b[i].setcourierid(0);
		}	
	}
	fin.close();
	fout.open(orderfile, ios::out);
	for (i=0; i<k; i++){ //перезаписываем массив заказов
		fout << b[i].getido() <<" "<<b[i].getprice()<<" "<<b[i].getdeadline()<<" "<<b[i].getdtime()<<" "<<b[i].getaddress()<<" "<<b[i].getcourierid()<<endl;
	}
	fout.close();
	delete[]b;//уборка

}

