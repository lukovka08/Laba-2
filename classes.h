#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
/*!
	\brief Класс для работы с заказами
*/
class Order {
private:
	int ido; ///< идентефикатор заказа
        int price; ///< цена заказа 
        int deadline; ///< крайний срок доставки
        string address; ///< адрес доставки
        int courierid; ///< идентификатор курьера 
        int dtime; ///< время, через которое заказ будет доставлен 
public:
	/*!
	    \brief геттер  ido
	*/
	int getido() { return ido; } // геттер для ido
	/*!
	    \brief сеттер ido
	*/
	void setido(int sido) { ido = sido; } // сеттер для ido
 /*!
     \brief геттер  price
 */
	int getprice() { return price; } // геттер для price
	/*!
		\brief сеттер price
	*/
	void setprice(int sprice) { price = sprice; } // сеттер для price
  /*!
	 \brief геттер  deadline
 */
	int getdeadline() { return deadline; } // геттер для deadline
	/*!
		\brief сеттер deadline
	*/
	void setdeadline(int sdeadline) { deadline = sdeadline; } // сеттер для deadline
  /*!
	 \brief геттер  address
 */
	string getaddress() { return address; } // геттер для address
	/*!
		\brief сеттер  address
	*/
	void setaddress(string saddress) { address = saddress; } // сеттер для address
  /*!
	 \brief геттер courierid
 */
	int getcourierid() { return courierid; } // геттер для courierid
	/*!
		\brief сеттер courierid
	*/
	void setcourierid(int scourierid) { courierid = scourierid; } // сеттер для courierid
  /*!
	 \brief геттер dtime
 */
	int getdtime() { return dtime; } // геттер для dtime
	/*!
		\brief сеттер dtime
	*/
	void setdtime(int sdtime) { dtime = sdtime; } // сеттер для dtime
};
/*!
	\brief Класс для работы с курьерами
*/
class Courier {
private:
	int idc; ///< идентефикатор курьера	
	string name; ///< имя курьера
	string phone; ///< номер телефона курьера
	int orderid1; ///< текущий заказ курьера
	int orderid2; ///< будующий заказ курьера
	int car; ///< наличие машины 
	int deliverytime; ///< время, через которое курьер доставит текущий заказ
public:
	/*!
	      \brief геттер idc
*/
	int getidc() { return idc; } // геттер для idc
	 /*!
	      \brief сеттер idc
 */
	void setidc(int sidc) { idc = sidc; } // сеттер для idc
	/*!
		  \brief геттер name
*/
	string getname() { return name; } // геттер для name
	 /*!
		  \brief сеттер name
 */
	void setname(string sname) { name = sname; } // сеттер для name
 /*!
		  \brief геттер phone
*/
	string getphone() { return phone; } // геттер для phone
	/*!
	    \brief сеттер phone
	*/
	void setphone(string sphone) { phone = sphone; } // сеттер для phone
 /*!
		  \brief геттер orderid1
*/
	int getorderid1() { return orderid1; } // геттер для orderid1
	/*!
		\brief сеттер orderid1
	*/
	void setorderid1(int sorderid1) { orderid1= sorderid1; } // сеттер для orderid1
 /*!
		  \brief геттер orderid2
*/
	int getorderid2() { return orderid2; } // геттер для orderid2
	/*!
		\brief сеттер orderid2
	*/
	void setorderid2(int sorderid2) { orderid2 = sorderid2; } // сеттер для address
 /*!
		  \brief геттер car
*/
	int getcar() { return car; } // геттер для car
	/*!
		\brief сеттер car
	*/
	void setcar(int scar) { car = scar; } // сеттер для car
 /*!
		  \brief геттер deliverytime
*/
	int getdeliverytime() { return deliverytime; } // геттер для deliverytime
	/*!
		\brief сеттер deliverytime
	*/
	void setdeliverytime(int sdeliverytime) { deliverytime = sdeliverytime; } // сеттер для deliverytime
};
void allorderwrite(string orderfile);
void allorderclear(string courierfile, string orderfile);
void allcourierwrite(string courierfile);
void allcourierclear(string courierfile, string orderfile);
void courierdeleting(string courierfile, string orderfile);
void oselect(string courierfile, string orderfile);
void addorder (string orderfile);
void osearchid(string orderfile);
void runtime(string courierfile, string orderfile);
void csearchid(string courierfile);
void csearchname(string courierfile);
void csearchphone(string courierfile);
void addcourier(string courierfile);
