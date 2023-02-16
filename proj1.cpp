#include "proj.h"
#include <iostream>
using namespace std;

int i, j;

// add function
void add(customer & cust){
	cout<<"ID: "; cin>>cust.cstID;
	cout<<"Name: "; cin>>cust.cstname;
	cout<<"Email: "; cin>>cust.cstemail;
	cout<<"Gender: "; cin>>cust.gender;
	cout<<"Birthday: "; cin>>cust.dmy.day >>cust.dmy.month >>cust.dmy.year;
	cout<<"your number phone: "; cin>>cust.phonenum;
}


// add2 function
void add(customer cus[], int cusize, int &cusnum){
	while (cusnum<cusize){
		add(cus[cusnum]);
		cusnum++;
		break;}
}


// search function
int search(customer cus[], int cusnum){
	int number;
	string id;
	bool fond=false;
	while (fond==false){
		cout<<"\n what is the ID for the customer you want: ";
		cin>> id;
		for (i=0; i<cusnum; i++){
			if (cus[i].cstID==id){
				cout<<"was found!\n";
				number=i;
				fond=true;}}
		if (cus[number].cstID!=id){
			cout<<"was not found!\n";
			number=-1;} }

	return number;
}


// delete function
void delete_rec(customer cus[], int &cusnum){
	int number;
	number=search(cus, cusnum);
	while (number<cusnum){
	cus[number].cstID= cus[number+1].cstID;
	cus[number].cstname= cus[number+1].cstname;
	cus[number].cstemail= cus[number+1].cstemail;
	cus[number].gender= cus[number+1].gender;
	cus[number].dmy.day= cus[number+1].dmy.day;
	cus[number].dmy.month= cus[number+1].dmy.month;
	cus[number].dmy.year= cus[number+1].dmy.year;
	cus[number].phonenum= cus[number+1].phonenum;
	number++;}
	cusnum--;
	cout<<"\n \t \t **the customer data was delete**";
}


// Update function
void  Update(customer cus[], int cusnum){
	int number;
	number= search(cus, cusnum);
	cout<<"ID: "; cin>>cus[number].cstID;
	cout<<"Name: "; cin>>cus[number].cstname;
	cout<<"Email: "; cin>>cus[number].cstemail;
	cout<<"Gender: "; cin>>cus[number].gender;
	cout<<"Birthday: "; cin>>cus[number].dmy.day >>cus[number].dmy.month >>cus[number].dmy.year;
	cout<<"phone number: "; cin>>cus[number].phonenum;
}


// Sort function
void Sort(customer cus[], int *cusnum){
	customer temp;
	bool order=false;
	if (*cusnum<2)
		cout<<"nothing to sort!! \n";
	else {
	for (i=0; i<*cusnum-1; i++){
		order=true;
		for (j=0; j<*cusnum-1; j++){
			if (cus[j].cstname.compare (cus[j+1].cstname)>0){
				order=false;
				temp=cus[j];
				cus[j]=cus[j+1];
				cus[j+1]=temp; } } } }
}


//sort2  Rotating Elements 
void Sort(customer cus[], int cusnum, int p){
//	printArray(cus,cusnum);
	customer temp[cusnum];
	int newPositionIndex;
	for (i=0; i<cusnum ;i++)
	{ 
		newPositionIndex=i+(cusnum-p+1);
		if (newPositionIndex>=cusnum)
 			newPositionIndex=newPositionIndex %cusnum;
		temp[newPositionIndex]=cus[i];
	}
	
	for (i=0; i<cusnum ;i++)
		cus[i]=temp[i]; //copy element by element

}


//view function
void view(customer cus[], int cusnum, int servnum){
	cout<<"ID \t Name\tEmail  \t\t   Gender \t Birth Day \t Phone Number \t  services    \t Total price \n";
	for (i=0;i< cusnum; i++){
		cout<<
		cus[i].cstID<<"\t"<<cus[i].cstname<<"  "<<cus[i].cstemail<<"\t\t"<<cus[i].gender<<"\t"<<cus[i].dmy.day<<"-"<<cus[i].dmy.month<<"-"<<cus[i].dmy.year<<"\t"<<cus[i].phonenum; 
		for (j=0; j<servnum; j++){
			cout<<" " <<j+1 <<": " <<cus[i].services[j].srv_name;}
		cout<<"\t" <<cus[i].total_price<<endl;}
}
