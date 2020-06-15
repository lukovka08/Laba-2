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
	int ido; ///< id заказа (идентификатор заказа)
        int price; ///< цена заказа (количество денег , отданных за заказ)
        int deadline; ///< срок доставки заказа (число часов)
        string address; ///< адрес доставки (район)
        int courierid; ///< id сотрудника (индентификатор сотрудника)
        int dtime; ///< время доставки заказа (число часов)
public:
	/*!   
	       \arg courierfile Файл с курьерами
		   \arg orderfile Файл с заказами
    */
	friend void allorderclear(string courierfile, string orderfile); // очистить файл заказов
	/*!
	     \arg orderfile Файл с заказами
	*/
	friend void allorderwrite(string orderfile); // вывести список заказов
	/*!
	      \arg courierfile Файл с курьерами
		  \arg orderfile Файл с заказами
	*/
    friend void oselect(string courierfile, string orderfile); // распределение заказов по курьерам
	/*!
	       \arg orderfile Файл с заказами
	*/
	friend void addorder (string orderfile); // добавить заказ
	/*!
	        \arg orderfile Файл с заказами
	*/
	friend void osearchid(string orderfile); // поиск по id
	/*!
	         \arg courierfile Файл с курьерами
			 \arg orderfile Файл с заказами
	*/
	friend void runtime(string courierfile, string orderfile); // промотать время вперед на n минут
};
/*!
           \brief Класс для работы с курьерами
*/
class Courier {
private: 
	int idc; ///<  id сотрудника (идентификатор сотрудника)
	string name; ///< имя сотрудника ( имя )
	string phone; ///< телефон сотрудника (номер телефона)
	int orderid1; ///< текущий заказ (есть, нет)
	int orderid2; ///< будующий заказ (есть, нет)
	int car; ///< машина для доставки (есть, нет)
	int deliverytime; ///< время через которое курьер освободится (число часов)
public:
	/*!
	         \arg courierfile Файл с курьерами
			 \arg orderfile Файл с заказами
	*/
	friend void runtime(string courierfile, string orderfile); // промотать время вперед на n минут
	/*!
	         \arg courierfile Файл с курьерами
	*/
	friend void csearchid(string courierfile); // найти курьера по id
	/*!
	          \arg courierfile Файл с курьерами
	*/
	friend void addcourier(string courierfile); // добавить курьера
	/*!
	          \arg courierfile Файл с курьерами
			  \arg orderfile Файл с заказами
	*/
	friend void courierdeleting(string courierfile, string orderfile); // удалить курьера
	/*!
	            \arg courierfile Файл с курьерами
	*/
	friend void csearchname(string courierfile); // найти курьера по имени
	/*!
				\arg courierfile Файл с курьерами
	*/
	friend void csearchphone(string courierfile); // найти курьера по телефону
	/*!
			  \arg courierfile Файл с курьерами
			  \arg orderfile Файл с заказами
	*/
	friend void allcourierclear(string courierfile, string orderfile); // очистить список курьеров
	/*!
				\arg namefile Файл с курьерами
	*/
	friend void allcourierwrite(string namefile); // вывести список курьеров
	/*!
			  \arg courierfile Файл с курьерами
			  \arg orderfile Файл с заказами
	*/
	friend void oselect(string courierfile, string orderfile); // распределение заказов по курьерам
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
