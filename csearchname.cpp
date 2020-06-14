#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void csearchname(string courierfile){
	ifstream fin;
	ofstream fout;	
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the name you want to find"<<endl;
	string s;
	while (!fin.eof()){//считаем количество строк
		getline(fin, s);
		k++;
	}
	k--;
	Courier *a = new Courier[k+1];//создаем массив
	fin.close();
	fin.open(courierfile);
	for (i=0; i<k; i++){//заполняем массив из файла
		fin >> a[i].idc;
		fin >> a[i].name ;
		fin >> a[i].phone;
		fin >> a[i].orderid1;
		fin >> a[i].orderid2;
		fin >> a[i].car;
		fin >> a[i].deliverytime;
	}
	int tmp=-1;
	string name;
	cin >>name;//искомое имя
	for (i=0; i<k; i++){ 
		if (a[i].name== name){//ищем совпадения, выводим
			cout << a[i].idc<<" " <<a[i].name <<" " << a[i].phone <<" " << a[i].orderid1<<" " << a[i].orderid2 <<" "<<a[i].car<<" "<<a[i].deliverytime<<endl;
			tmp=1;		
		} 
	}
	if (tmp==-1){//если имени не нашлось
		cout<<"There's no such name"<<endl;
	}	
	fout.close();
	delete[]a;//уборка
}

