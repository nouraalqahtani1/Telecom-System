#include "proj.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	
	char person, yes_no, *again; // char 'person' is for user to choose if he customer or employee. 
	const int size=20; 
	customer custs[size]; // custs is array of customers data
	bool found=false;
	int i, j;
	string ID;
	int choose, num, custnum=0; // 'num' is the customer number in the array, 'custnum' is a counter of how many customers we have
	int serv, serv_num=0, numsrv; //'serv' is to choose the service, 'serv_num' is a counter for customer's services, 'numsrv' is to choose the number of services array
	servs *srv; // srv is a pointer for the dynamic array of the services and their price
	srv= new servs [10]; // the beginning of the dynamic array
	int *poin= &choose; 
	again= new char; // the beginning of the dynamic value
	
	ofstream outFile;//output file object
	outFile.open("TelecomSystem.txt");// Reading Data
	if(outFile.is_open()== true ||outFile.is_open()){
		string vote;
		cout<<" How excited are you about the program?";
		cin>>vote;
		outFile<<vote<<"\n";
	}
	outFile.close();
	
	ifstream inFile;//input file object
	inFile.open("TelecomSystem2.txt");// Reading Data
	if(inFile.is_open()== true ||inFile.is_open()){
	int a;
	cout<<"From 1 to 10 how excited are you? ";
	cin>>a;
	inFile>>a;
	}
	inFile.close();

	custs[0].cstID= "012344";
	custs[0].cstname= "Ail";
	custs[0].cstemail = "Ail1@gmail.com";
	custs[0].gender= 'M';
	custs[0].dmy.day= 23;
	custs[0].dmy.month= 12;
	custs[0].dmy.year= 2002;
	custs[0].phonenum="0002354876"; //Defining the first customer
	custnum++;
	
	custs[1].cstID= "012938";
	custs[1].cstname= "Sara";
	custs[1].cstemail = "sara@gmail.com";
	custs[1].gender= 'F';
	custs[1].dmy.day= 9;
	custs[1].dmy.month= 1;
	custs[1].dmy.year= 2013;
	custs[1].phonenum= "0004358337"; //Defining the second customer
	custnum++;
		
	custs[2].cstID= "012935";
	custs[2].cstname= "Noor";
	custs[2].cstemail = "NR12@gmail.com";
	custs[2].gender= 'F';
	custs[2].dmy.day= 1;
	custs[2].dmy.month= 3;
	custs[2].dmy.year= 1996;
	custs[2].phonenum= "00558081239"; //Defining the 3ed customer
	custnum++;

	srv[0].srv_name="Post50"; //the services and their price
	srv[0].price=50;
	srv[1].srv_name="Post150";
	srv[1].price=150;
	srv[2].srv_name="Pre55";
	srv[2].price=55;
	srv[3].srv_name="Pre200";
	srv[3].price=200;
	srv[4].srv_name="Postnet30";
	srv[4].price=30;
	srv[5].srv_name="Postnet250";
	srv[5].price=250;
	srv[6].srv_name="Prenet35";
	srv[6].price=35;
	srv[7].srv_name="Prenet150";
	srv[7].price=150;
	srv[8].srv_name="60 SAR";
	srv[8].price=60;
	srv[9].srv_name="350 SAR";
	srv[9].price=350;

	
	cout<<"\t \t Hello \t Welcome to Telecom System \n ";
	cout<<endl <<"If you are a CUSTOMER enter A" <<endl <<"If you are an EMPLOYEE enter B"<<endl <<"your choise is:";
	cin>>person;
	
	do{
		if (person=='a' || person=='A'){
			while (found==false){// this loop will work antil found = true
			cout<<endl <<"\t \t welcome our customer";
			cout<<"\n are you new customer?(Y/N) "; 
			cin>>yes_no;// if 'yes_no'= y the code will make the user enter his data, else if 'yes_no'= n the code will make the user enter his ID and search about it, if it was found then the loop will stop
			
			if (yes_no=='y'||yes_no=='Y'){
				num=custnum;
				 add(custs, size, custnum);}
				 
			else {
				
				cout<<"\n what is your ID? ";
				cin>> ID;
				for(i=0; i<size; ++i){
						if(custs[i].cstID ==ID){
							found=true;
							num=i;
							cout<<endl <<"Hello "<<custs[i].cstname <<endl;} }}}
				 	 
			cout<<endl <<"Which service you want? \n" <<"Mobile services: \n";
			cout<<"1. Packages \n" <<"2. Internet \n" <<"3. Online Recharge \n" <<"4. Other services \n" <<"your choise is:";
			cin>>*poin; // to enter tne value of 'choose', to choose the type of service
			
			switch(choose){ // for service the suer want
				case 1:
					cout<<endl<<"Packages: \n";
					cout<<"1. Postpaid \n" <<"2. Prepaid \n" <<"your choise is:";
					cin>> serv;
					
					if (serv==1){ 
					cout<<"\nPostpaid: \n";
					cout<<endl <<"1. Post50: \n \t" <<"Minutes: 50 \n \t" <<"Data: 15 GB \n \t" <<"50 SAR \n";
					cout<<endl <<"2. Post150: \n \t" <<"Minutes: 100 \n \t" <<"Data: 60 GB \n \t" <<"150 SAR \n";
					cout<<"\nenter the number of your choise: ";
					if (serv_num <5){ // if the number of services less then 5 
					cin>> numsrv; // the number of service customer want
					numsrv--; // to equal the service in the array srv
					custs[num].services[serv_num]=srv[numsrv]; // to put the service in customer data
					serv_num++; }
					else cout<<"your services are enough"; // if the number of services more then 5 
					break; }
			
					if (serv==2){
					cout<<endl <<"3. Pre55: \n \t" <<"Minutes: 550 \n \t" <<"Data: 20 GB \n \t" <<"Validity: 30 Days \n \t" <<"55 SAR \n";
					cout<<endl <<"4. Pre200: \n \t" <<"Minutes: 2000 \n \t" <<"Data: unlimited GB \n \t" <<"Validity: 30 Days \n \t" <<"200 SAR \n";
					cout<<"\nenter the number of your choise: ";
					if (serv_num <5){
					cin>> numsrv;
					numsrv--;
					custs[num].services[serv_num]=srv[numsrv];
					serv_num++; }
					else cout<<"your services are enough";
					break;                                }
				
				case 2:
					cout<<endl<<"\nInternet: \n";
					cout<<"1. Postpaid \n" <<"2. Prepaid \n";
					cin>> serv;
					if (serv==1){
					cout<<"Postpaid: \n";
					cout<<endl <<"5. Postnet30: \n \t" <<"social: 5 GB \n \t" <<"Data: 5 GB \n \t" <<"30 SAR \n";
					cout<<endl <<"6. Postnet250: \n \t" <<"social: 50 GB \n \t" <<"Data: 50 GB \n \t" <<"250 SAR \n";
					cout<<"\nenter the number of your choise: ";
					if (serv_num <5){
					cin>> numsrv;
					numsrv--;
					custs[num].services[serv_num]=srv[numsrv];
					serv_num++; }
					else cout<<"your services are enough";}
					
					if (serv==2){
					cout<<"\nPrepaid: \n";
					cout<<endl <<"7. Prenet35: \n \t" <<"Data: 30 GB \n \t" <<"Validity: 30 Days \n \t" <<"35 SAR \n";
					cout<<endl <<"8. Pre200: \n \t" <<"Data: unlimited GB \n \t" <<"Validity: 30 Days \n \t" <<"200 SAR \n";
					cout<<"\nenter the number of your choise: ";
					if (serv_num <5){
					cin>> numsrv;
					numsrv--;
					custs[num].services[serv_num]=srv[numsrv];
					serv_num++; }
					else cout<<"your services are enough";}
					break;
				
				case 3:
					cout<<endl<<"\nOnline Recharge: \n";
					cout<<endl <<"9. 60 SAR \n \t";
					cout<<endl <<"10. 350 SAR \n \t";
					cout<<"\nenter the number of your choise: ";
					if (serv_num <5){
					cin>> numsrv;
					numsrv--;
					custs[num].services[serv_num]=srv[numsrv];
					serv_num++; }
					else cout<<"your services are enough";
					break;
					
				case 4:
					cout<<"\nOther services \n \n1. update your data \n2. view your data \n3. your BILL \n4. delete service" <<endl <<"your choise is:";
					cin>>serv;
					if (serv==1){
						cout<<"\n ***enter the new data please*** \n"; //to updata the customer data
						cout<<"ID: "; cin>>custs[num].cstID;
						cout<<"Name: "; cin>>custs[num].cstname;
						cout<<"Email: "; cin>>custs[num].cstemail;
						cout<<"Gender: "; cin>>custs[num].gender;
						cout<<"Birthday: "; cin>>custs[num].dmy.day >>custs[num].dmy.month >>custs[num].dmy.year;
						cout<<"your phone number: "; cin>>custs[num].phonenum; }
					
					if (serv==2){ // to view the customer data
						cout<<"\nID: " <<custs[num].cstID;
						cout<<"\nName: " <<custs[num].cstname;
						cout<<"\nEmail: " <<custs[num].cstemail;
						cout<<"\nGender: " <<custs[num].gender;
						cout<<"\nBirthday: " <<custs[num].dmy.day <<"-" <<custs[num].dmy.month <<"-" <<custs[num].dmy.year;
						cout<<"\nphone number: " <<custs[num].phonenum;
						cout<<"\nservices: ";
						for (i=0; i<serv_num; i++){
							cout<<endl <<i+1 <<": " <<custs[num].services[i].srv_name;} }
						
					if (serv==3){ 
						for (i=0; i<serv_num; i++){// to calculat the Total price
							cout<<endl <<i+1 <<": " <<custs[num].services[i].srv_name;
							cout<<"   " <<custs[num].services[i].price <<endl;
							custs[num].total_price+=custs[num].services[i].price;}
					cout<<"\nTotal price: " <<custs[num].total_price;}
					
					if (serv==4){
						cout<<"\nservices: ";
						for (i=0; i<serv_num; i++){
							cout<<endl <<i+1 <<": " <<custs[num].services[i].srv_name;}
						cout<<"\nwhat the number of the service you want to delete? ";
						cin>>numsrv;
						while (numsrv<serv_num){ // to delete a service
						custs[num].services[numsrv-1].srv_name= custs[num].services[numsrv].srv_name;
						custs[num].services[numsrv-1].price= custs[num].services[numsrv].price;
						numsrv++;}
						serv_num--;
						cout<<"\n \t \t **your service was delete**";	}	
					break;
				
				default:
					cout<<"That is not a possible choice"; }} // if the user enter unpossible choice
				
		if (person=='b' || person=='B'){
		cout<<endl <<"\t welcome back \n" <<"what do you want to do?";
		cout<<endl <<"1. add customer \n" <<"2. delete customer \n" <<"3. change the order of the customers list \n" <<"4. update customer data \n" <<"5. view all customers data \n";
		cin>>choose; 
		
		switch (*poin){
			case 1: //to add naw customer
				add(custs, size, custnum);
				break;
			
			case 2://to delete a customer
				delete_rec(custs, custnum);
				break;
				
			case 3:
				cout <<"\n 1. in alphabetical \n 2. the position"<<endl <<"your choise is:"; 
				cin>>choose;
				
				if (choose==1) // sort by alphabetical
				Sort(custs, &custnum);
				
				if (choose==2){
				view(custs, custnum, serv_num);
				cout<<"Enter the current postion for the customers you want to bring it to first postion: "; // sort by position
				int pos;
				cin>>pos;
				Sort(custs,custnum, pos);}
				break;
				
			case 4:
				Update(custs, custnum); // to update customer data
				break;
			
			case 5:
				view(custs, custnum, serv_num); // to view customers data
				break;
				
				
			default:
				cout<<"That is not a possible choice";}}
		
		
		cout<<endl<<"\ndo you want to do anything else?(Y/N): ";
		cin>>*again;
	} while (*again=='y' || *again=='Y');
	
	delete again; // delete the dynamic value
	delete [] srv; // delete the dynamic array
	
	return 0;
}
