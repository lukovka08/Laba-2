#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Order {
private:
	int ido;
        int price;
        int deadline;
        string address;
        int courierid;
        int dtime;
public:
	void allorderwrite(string orderfile);
	void addorder (string orderfile);
	void osearchid(string orderfile);
	void runtime(string courierfile, string orderfile);

	int getido() { return ido; } // геттер для ido
	void setido(int sido) { ido = sido; } // сеттер для ido
 
	int getprice() { return price; } // геттер для price
	void setprice(int sprice) { price = sprice; } // сеттер для price
 
	int getdeadline() { return deadline; } // геттер для deadline
	void setdeadline(int sdeadline) { deadline = sdeadline; } // сеттер для deadline
 
	string getaddress() { return address; } // геттер для address
	void setaddress(string saddress) { address = saddress; } // сеттер для address
 
	int getcourierid() { return courierid; } // геттер для courierid
	void setcourierid(int scourierid) { courierid = scourierid; } // сеттер для courierid
 
	int getdtime() { return dtime; } // геттер для dtime
	void setdtime(int sdtime) { dtime = sdtime; } // сеттер для dtime
};
class Courier {
private:
	int idc;	
	string name;
	string phone;
	int orderid1;
	int orderid2;
	int car; 
	int deliverytime;
public:
	void addcourier(string courierfile);
	void allorderclear(string courierfile, string orderfile);
	void allcourierwrite(string courierfile);
	void allcourierclear(string courierfile, string orderfile);
	void courierdeleting(string courierfile, string orderfile);
	void csearchid(string courierfile);
	void csearchname(string courierfile);
	void csearchphone(string courierfile);
	void oselect(string courierfile, string orderfile);
	
	int getidc() { return idc; } // геттер для idc
	void setidc(int sidc) { idc = sidc; } // сеттер для idc

	string getname() { return name; } // геттер для name
	void setname(string sname) { name = sname; } // сеттер для name
 
	string getphone() { return phone; } // геттер для phone
	void setphone(string sphone) { phone = sphone; } // сеттер для phone
 
	int getorderid1() { return orderid1; } // геттер для orderid1
	void setorderid1(int sorderid1) { orderid1= sorderid1; } // сеттер для orderid1
 
	int getorderid2() { return orderid2; } // геттер для orderid2
	void setorderid2(int sorderid2) { orderid2 = sorderid2; } // сеттер для address
 
	int getcar() { return car; } // геттер для car
	void setcar(int scar) { car = scar; } // сеттер для car
 
	int getdeliverytime() { return deliverytime; } // геттер для deliverytime
	void setdeliverytime(int sdeliverytime) { deliverytime = sdeliverytime; } // сеттер для deliverytime
};
