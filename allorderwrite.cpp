#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void Order::allorderwrite(string orderfile){//Вывести все элементы на экран
	ifstream fin;
	fin.open(orderfile);
	string s;
	cout<<"Format:"<<endl;
	cout<<"ID PRICE DEADLINE(MINUTES) DELIVERYTIME(MINUTES) ADRESS COURIERID "<<endl; 
	while (!fin.eof()){//Считаем количество строк в тексте=количество видов объектов
		getline(fin, s);
		cout<<s<<endl;
	}
	fin.close();//Убираем за собой
}
