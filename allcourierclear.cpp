#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
void Courier::allcourierclear(string courierfile, string orderfile){
	ofstream f;
	f.open(courierfile, ios::out);
	f.close();
	ifstream fin;
	ofstream fout;	
	fin.open(orderfile);	
	int  i=0;
	int k=0;
	string s;
	while (!fin.eof()){
		getline(fin, s);
		k++;
	}
	k--;
	Order *a = new Order[k+1];
	fin.close();
	int sido;
        int sprice;
        int sdeadline;
        string saddress;
        int scourierid;
        int sdtime;
	fin.open(orderfile);
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
	fin.close();
	fout.open(orderfile, ios::out);
	for (i=0; i<k; i++){ 
		fout << a[i].getido() <<" "<<a[i].getprice()<<" "<<a[i].getdeadline()<<" "<<a[i].getdtime()<<" "<<a[i].getaddress()<<" "<<0<<endl;
	 } 
	fout.close();
	delete[]a;

}
