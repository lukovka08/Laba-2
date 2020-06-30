#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include "classes.h"
using namespace std;
int main(){
	string courierfile;
	string orderfile;
	cout << "Good morning."<<endl;//доброе утро
	string s;
	int n, m;
	int k=0;
	int l=0;
	int y=0;
	fstream fin;
	while (k==0){//считываение имени файла с данными о курьерах 
		cout << "---------------Please enter new courier database name:(txt file!)- print '0' if you cant---------------"<<endl;
		cin >> s;
		if (s=="0"){//выход
			cout<<" Thank you, see you later"<<endl; 
			exit(0);
		}
		courierfile=s;
		fin.open(courierfile);
		if(!fin.is_open()){//существует ли такой файл
			cout <<"---------------Sorry, database can not be found. Please try again---------------"<<endl;
		}
		else{	
			cout<<"---------------Courier database changed sucsessfully---------------"<<endl;
			k=1;
		}
		fin.close();
	}
	k=0;
	while (k==0){//ввод базы данных для заказов
		cout << "---------------Please enter new order database name:(txt file!)- print '0' if you cant---------------"<<endl;
		cin >> s;
		if (s=="0"){
			cout<<"Great, see you later"<<endl; 
			exit(0);
			
		}
		s;
		fin.open(s);
		if(!fin.is_open()){//существует ли этот файл
			cout <<"---------------Sorry, database can not be found. Please try again---------------"<<endl;
		}
		else{	
			cout<<"---------------Order database changed sucsessfully---------------"<<endl;
			k=1;
			orderfile=s;
		}
		fin.close();
	}
	int g;
	k=0;
	while (k==0){//главное меню
		cout <<"Press 42- to see help"<<endl;
		cout <<"---------------------------------------"<<endl;
		cin >> n;
		y=0;
		for(y=0;y<25;y++){cout<<endl;}
		y=0;
		oselect(courierfile, orderfile);//функция распределения заказов по курьерам, работает автоматически каждую итерацию
		switch (n){
		case 42://справка
			cout <<"---------------Press:---------------"<<endl;	
			cout <<"0- to start time"<<endl;
			cout <<"1- to show courier list"<<endl;
			cout <<"2- to show order list"<<endl;
			cout <<"10- to start work with couriers"<<endl;
			cout <<"20- to start work with orders"<<endl;
			cout <<"100- to end up program"<<endl;
		break;
		case 0://промотать время вперед на n минут
			runtime(courierfile, orderfile);
		break;
		case 100://конец программы
			k=1;
			cout<<"＼(￣▽￣)／ (*¯︶¯*) ＼(＾▽＾)／ Thank you, see you soon＼(￣▽￣)／ (*¯︶¯*) ＼(＾▽＾)／"<<endl; 
		break;
		case 1://вывод всех курьеров
			allcourierwrite(courierfile);
		break;
		case 2://вывод всех заказов
			allorderwrite(orderfile);
		break;
		case 10://работа с курьерами
			while(l==0){//меню раоботы с курьерами
				cout <<"Press 42- to see help"<<endl;
				cin>>m;
				l=0;
				for(l=0;l<25;l++){cout<<endl;}
				l=0;
				oselect(courierfile, orderfile);//распределение заказов по курьерам
				switch (m){
				case 42://справка
					cout <<"---------------Press:---------------"<<endl;	
					cout <<"1- to show courier list"<<endl;
					cout <<"11- to add courier"<<endl;
					cout <<"12- to fire courier"<<endl;
					cout <<"13- to find courier with id"<<endl;
					cout <<"14- to find courier by his name"<<endl;
					cout <<"15- to find courier by his phone"<<endl;
					cout <<"18- to clear courier list"<<endl;
					cout <<"19- to change courier database"<<endl;
					cout <<"100- to return to main menu"<<endl;
				break;
				case 1://вывести список курьеров
					allcourierwrite(courierfile);
				break;
				case 2://вывод всех заказов
				allorderwrite(orderfile);
				break;
				case 100://выход в главное меню
					l=1;
				break;
				case 11://добавить курьера
					addcourier(courierfile);
				break;
				case 12://удалить курьера
					courierdeleting(courierfile, orderfile);
				break;
				case 13://найти курьера по id
					csearchid(courierfile);
				break;
				case 14://найти по имени
					csearchname(courierfile);
				break;
				case 15://найти по телефону
					csearchphone(courierfile);
				break;
				case 18://очистить список курьеров
					allcourierclear(courierfile, orderfile);
				break;
				case 19://смена базы данных курьеров(аналогично первой)
					g=0;
					while (g==0){
						cout << "---------------Please enter new courier database name:(txt file!)- print '0' if you cant---------------"<<endl;	
						cin >> s;
						if (s=="0"){
							g==1;
						}
						fin.open(s);
						if(!fin.is_open()){
							cout <<"---------------Sorry, database can not be found. Please try again---------------"<<endl;
						}
						else{	
							cout<<"---------------Courier database changed sucsessfully---------------"<<endl;
							g=1;
							courierfile=s;
						}
						fin.close();
					}
				break;
				}
			}
		break;
		case 20://работа с заказами
			while(l==0){
				cout <<"Press 42- to see help"<<endl;
				oselect(courierfile, orderfile);//распределение заказов
				cin>>m;
				l=0;
				for(l=0;l<25;l++){cout<<endl;}
				l=0;	
				switch (m){
				case 42://справка
					cout <<"21- to add order"<<endl;
					cout <<"22- to find order with id"<<endl;
					cout <<"23- to show order list"<<endl;
					cout <<"24- to clear order list"<<endl;
					cout <<"29- to change order database"<<endl;		
					cout <<"100- to do to the main menu"<<endl;
				break;
				case 100://в главное меню
					l=1;
				break;
				case 21://добавить заказ
					addorder(orderfile);
				break;
				case 22://найти по id
					osearchid(orderfile);
				break;
				case 23://вывести список заказов
					allorderwrite(orderfile);
				break;
				case 24://очистить файл заказов
					allorderclear(courierfile, orderfile);
				break;
				case 99://смена файла(аналогично начальной
					g=0;
					while (g==0){
						cout << "---------------Please enter new order database name:(txt file!)- print '0' if you cant---------------"<<endl;	
						cin >> s;
						if (s=="0"){
							g==1;
						}
						fin.open(s);
						if(!fin.is_open()){
							cout <<"---------------Sorry, database can not be found. Please try again---------------"<<endl;
						}
						else{	
							cout<<"---------------Order database changed sucsessfully---------------"<<endl;
							g=1;
							orderfile=s;
						}
						fin.close();
					}
				break;
				}
			}
		break;
		default://неправильный ввод
			cout<<"You uncorrect data. Please, try again"<<endl;
		break;
		}
	}
	return 0;
}
