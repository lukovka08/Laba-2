#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void Courier::csearchphone(string courierfile){
	ifstream fin;
	ofstream fout;	
	fin.open(courierfile);	
	int  i=0;
	int k=0;
	cout <<"Enter the phone you want to find"<<endl;
	string s;
	while (!fin.eof()){
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
	int tmp=-1;
	cin >>sphone;
	for (i=0; i<k; i++){ 
		if (a[i].getphone()== sphone){
			cout << a[i].getidc() <<" "<<a[i].getname()<<" "<<a[i].getphone()<<" "<<a[i].getorderid1()<<" "<<a[i].getorderid2()<<" "<<a[i].getcar()<<" "<<a[i].getdeliverytime()<<endl;
			tmp=1;		
		} 
	}
	if (tmp==-1){
		cout<<"There's no such phone"<<endl;
	}	
	fout.close();
	delete[]a;
}

