#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void Order::runtime(string courierfile, string orderfile){//перемотка времени вперед
	ifstream fin;
	ofstream fout;	
	int  i=0;
	int n;
	int k=0;
	string s;
	cout<<"Please, enter time(in minutes) you want to go:"<<endl;
	int l=0;
	int j;
	cin >>n;//СКОЛЬКО МИНУТ
	for (int g=0;g<n;g++){//идем в цикле по одной минуте за раз
	fin.open(courierfile);
	l=0;
	while (!fin.eof()){//считываем количество курьеров
		getline(fin, s);
		l++;
	}
	l--;
	int sidc;	
	string sname;
	string sphone;
	int sorderid1;
	int sorderid2;
	int scar; 
	int sdeliverytime;
	fin.close();
	fin.open(courierfile);
	Courier *b = new Courier[l+1];
	for (i=0; i<l; i++){//считываем курьеров
		fin >> sidc;
		fin >> sname ;
		fin >> sphone;
		fin >> sorderid1;
		fin >> sorderid2;
		fin >> scar;
		fin >> sdeliverytime;
		b[i].setidc(sidc);
		b[i].setname(sname);
		b[i].setphone(sphone);
		b[i].setorderid1(sorderid1);
		b[i].setorderid2(sorderid2);
		b[i].setcar(scar);
		b[i].setdeliverytime(sdeliverytime);
	}
	fin.close();
	fin.open(orderfile);
	k=0;
	while (!fin.eof()){//считываем количество заказов
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
	fin.close();
	fin.open(orderfile);
	Order *a = new Order[k+1];
	for (i=0; i<k; i++){//считываем заказы
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
	fin.close();
	fout.open(orderfile, ios::out);
	for (i=0; i<k; i++){ //идем по массиву заказов
		a[i].setdtime(a[i].getdtime()-1);//уменьшаем дедлайн и время до доставки на минуту
		a[i].setdeadline(a[i].getdeadline()-1);
		if (a[i].getdtime()>=1){//если заказ еще не доставлен, записываем аго в файл
			fout << a[i].getido() <<" "<<a[i].getprice()<<" "<<a[i].getdeadline()<<" "<<a[i].getdtime()<<" "<<a[i].getaddress()<<" "<<a[i].getcourierid()<<endl;
		}
		else{//если заказ доставлен 
			if(a[i].getcourierid()==0){
				a[i].setdeadline(-10);//заказ так и не распределили
			}
			else{
				a[i].setdeadline(-20);//заказ взял курьер и доставил
			}
		} 
	}
	fout.close();
	fout.open(courierfile, ios::out); 
	for(j=0;j<l;j++){//идем по массиву курьеров
		b[j].setdeliverytime(b[j].getdeliverytime()-1);//уменьшаем время доставки на единицу
		if (b[j].getdeliverytime()==0){//если только что оно стало нулем, значит сейчас доставлялся заказ
			b[j].setorderid1(b[j].getorderid2());//начинает доставлять второй заказ
			b[j].setorderid2(0);//освобождает место для второго заказа
			if(b[j].getorderid1()>0){
				b[j].setdeliverytime(30-20*b[j].getcar());//в зависимости от скорости, определяем время доставки
			}
			else{
				b[j].setdeliverytime(0);//если нет заказов, время доставки=0 
			}					
		}
		if(b[j].getdeliverytime()<0)//держим числа у людей без заказов больше нуля
		{b[j].setdeliverytime(0);}
		fout << b[j].getidc() <<" "<<b[j].getname()<<" "<<b[j].getphone()<<" "<<b[j].getorderid1()<<" "<<b[j].getorderid2()<<" "<<b[j].getcar()<<" "<<b[j].getdeliverytime()<<endl;
 //переписываем данные о курьерах
	}		
	cout<<" "<<g+1<<" minutes passed"<<endl;//выводим сообщение о прошедших миутах
	fout.close();
	for (i=0; i<k; i++){ //идем по массиву заказов
		if(a[i].getdeadline()==-10){//если у заказа прошел дадлайн
			cout<<"----------------ATTENTION: Sorry, order "<<a[i].getido()<<" wasn't delivered----------------"<<endl;
		}
		if(a[i].getdeadline()==-20){//Если заказ был доставлен
			cout <<"---------------ATTENTION: Order "<<a[i].getido()<<" was delivered--------------"<<endl;
		} 
	}
	delete[]a;//уборка
	delete[]b;
	}
}
