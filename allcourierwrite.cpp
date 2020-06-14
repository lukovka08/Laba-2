#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void allcourierwrite(string courierfile){
	ifstream fin;
	fin.open(courierfile);//открываем
	cout<<"Format:"<<endl;
	cout<<"ID NAME PHONE CURRENTORDERID FUTUREORDERID CAR(0 OR 1) CURRENTDELIVERYTIME"<<endl; 
	string s;//выводим построчно
	while (!fin.eof()){
		getline(fin, s);
		cout<<s<<endl;
	}
	fin.close();
}
