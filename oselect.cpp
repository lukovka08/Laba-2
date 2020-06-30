#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void oselect(string courierfile, string orderfile)
{ 
	ifstream fin;
	ofstream fout;	
	fin.open(orderfile);	
	int  i=0;
	int k=0;
	string s;
	while (!fin.eof()){//количество строк в файле заказов
		getline(fin, s);
		k++;
	}
	k--;
	Order *a = new Order[k+1];//массив заказов
	fin.close();
	fin.open(orderfile);
	int sido;
        int sprice;
        int sdeadline;
        string saddress;
        int scourierid;
        int sdtime;
	int nul=0;
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
		if(a[i].getcourierid()==0){//считаем заказы без курьера
			nul++;
		}	
	}
	int j;
	int x;
	for(i=0;i<k;i++){//сортируем заказы по возрастанию крайнего срока доставки, для более эффективного распределения
		for(j=0;j<k-1;j++){//метод пузырька
			if(a[j].getdeadline()>a[j+1].getdeadline()){
				x=a[j].getido();
				a[j].setido(a[j+1].getido());
				a[j+1].setido(x);
				
				x=a[j].getprice();
				a[j].setprice(a[j+1].getprice());
				a[j+1].setprice(x);
				
				x=a[j].getdeadline();
				a[j].setdeadline(a[j+1].getdeadline());
				a[j+1].setdeadline(x);
				
				x=a[j].getdtime();
				a[j].setdtime(a[j+1].getdtime());
				a[j+1].setdtime(x);
				
				s=a[j].getaddress();
				a[j].setaddress(a[j+1].getaddress());
				a[j+1].setaddress(s);
				
				x=a[j].getcourierid();
				a[j].setcourierid(a[j+1].getcourierid());
				a[j+1].setcourierid(x);
			}
		}
	}	
	string w;	
	fin.close();
	fin.open(courierfile);
	j=0;
	while (!fin.eof()){//теперь считаем курьеров
		getline(fin, w);
		j++;
	}
	j--;
	Courier *b=new Courier[j+1];//создаем массив курьеров
	fin.close();
	fin.open(courierfile);
	int sidc;	
	string sname;
	string sphone;
	int sorderid1;
	int sorderid2;
	int scar; 
	int sdeliverytime;
	for (i=0; i<j; i++){
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
	int tmp=0;
	i=0;
	int f;
	int m=0;
	int t=0;
	for(i=0;i<k;i++){//идем по массиву заказов
		if(a[i].getcourierid()==0){//ищем заказы без курьера
			f=0;//флаг
			for (m=0;m<j;m++){//идем по массиву курьеров
			 	if((f==0)&&(b[m].getorderid1()==0)&&(a[i].getdeadline()>30-20*b[m].getcar())){//если этот заказ еще не присвоили, курьер свободен и достаточно быстрый 
			 		b[m].setorderid1(a[i].getido());//присваиваем соответствующие id
				 	a[i].setcourierid(b[m].getidc());
			 		tmp++;//считаем распределенные заказы
			 		b[m].setdeliverytime(30-20*b[m].getcar());//теперь число не нулевое
			 		a[i].setdtime(b[m].getdeliverytime());
			 		f=1;//флаг, теперь этот заказ назначен
				}	
			}
		}	
	}
	if(tmp<nul){//если еще остались нераспределенные заказы
		for(i=0;i<k;i++){//идем по заказам	
			if(a[i].getcourierid()==0)	{//ищем свободные	
				f=0;//флаг
				for (m=0;m<j;m++){//идем по курьерам	
				 	if((f==0)&&(b[m].getorderid2()==0)&&(a[i].getdeadline()>b[m].getdeliverytime()+30-b[m].getcar()*20)){//если заказ еще не присвоили, и незанятый курьер успеет после выполнения своего текущего заказа
				 		b[m].setorderid2(a[i].getido());//присваиваем нужные id
					 	a[i].setcourierid(b[m].getidc());
					 	a[i].setdtime(b[m].getdeliverytime()+30-20*b[m].getcar());//время доставки этого заказа
				 		f=1;//флаг, теперь заказ назначен
				 		tmp++;
					}	
				}
			}	
		}
	}
	fin.close();
	fout.open(courierfile, ios::out);//перезаписываем курьеров
	for (i=0; i<j; i++){
		fout << b[i].getidc() <<" "<<b[i].getname()<<" "<<b[i].getphone()<<" "<<b[i].getorderid1()<<" "<<b[i].getorderid2()<<" "<<b[i].getcar()<<" "<<b[i].getdeliverytime()<<endl;
	}
	fout.close();
	delete [] b;
	fout.open(orderfile, ios::out);//перезаписываем заказы
	for (i=0; i<k; i++){
		fout << a[i].getido() <<" "<<a[i].getprice()<<" "<<a[i].getdeadline()<<" "<<a[i].getdtime()<<" "<<a[i].getaddress()<<" "<<a[i].getcourierid()<<endl;
	}
	fout.close();
	delete [] a;	//уборка
					
}
