#ifndef PORJ_H
#define PORJ_H
#include <string>

//Structures
struct date{
	int day;
	int month;
	int year; };// for Brithday
	
struct servs{
	std::string srv_name;
	int price; };// to match the product with its price
	
struct customer{
	std::string cstID;
	std::string cstname;
	std::string cstemail;
	char gender;
	date dmy;
	std::string phonenum;
	servs services[5]; 
	int total_price=0; };// customer data


//functions
void add(customer & cust); // to Add new customer 
void add(customer cus[], int cusize, int &cusnum); // to Add the new customer to the list of customers
int search(customer cus[], int cusnum); // to Search about any customer with his ID
void delete_rec(customer cus[], int &cusnum); // to Delete any customer by his ID
void  Update(customer cus[], int cusnum); // to Update the customer data
void Sort(customer cus[], int *cusnum); // to Sort the customers in alphabetical
void Sort(customer cus[], int cusnum, int p); // to Sort the customers by Rotating Elements 
void view(customer cus[], int cusnum, int servnum);// to View the customers in list

#endif
