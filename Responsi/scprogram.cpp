#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int pil;
int option();
int Add();
int Delete();
int tampil();

struct simpul{
	
   	char nama[30], nim[20], prodi[20], ipk[11];
   	struct simpul *next;
} 
	*baru, 
	*awal = NULL, 
	*akhir = NULL,
	*hapus,
	*temp;

int main() {
	
	do {
   	
     	cout <<"------------------------------------------------------"<<"\n";
     	cout << "		 Data Mahasiswa" << "\n";
     	cout <<"------------------------------------------------------"<<"\n";
     	cout << "1: Tambah" << '\n';
     	cout << "2: Hapus" << '\n';
     	cout << "3: Tampil" << '\n';
     	cout << "4: Exit" << '\n';
     	cout << "Pilih (1-4): ";
     	cin>>pil;
     	option();
   }
   		while(pil!=4);
  		return 0;
}

int option() {
	
   	if(pil==1)
    	Add();
   	else if(pil==2)
    	Delete();
   	else if(pil==3)
    	tampil();
   	else
    	return 0;
}

int Add() {
   baru=(simpul*)malloc(sizeof(struct simpul));
   cout<<"Data Mahasiswa"<<endl;
   cout<<"---------------------"<<endl;
   cin.ignore();
   cout<<"NIM : ";
   cin.getline(baru->nim,20);
   cout<<"Nama : ";
   cin.getline(baru->nama,30);
   cout<<"Prodi : ";
   cin.getline(baru->prodi,20);
   cout<<"IPK : ";
   cin.getline(baru->ipk,11);
   cin.ignore();
   baru->next=NULL;
   
   if(awal==NULL)
   {
       awal=baru;
   }
   else
   {
       akhir->next=baru;
   }
   akhir=baru;
   akhir->next=NULL;
}


int Delete() {
   if (awal==NULL)
       cout<<"Kosong"<<endl;
   else if(awal==akhir)
   {
        hapus=awal;
        awal=awal->next;   
   }
   else {
       hapus=awal;
       while(hapus->next!=akhir)
            hapus=hapus->next;
       akhir=hapus;
       hapus=akhir->next;
       akhir->next=NULL;
   
   }
}
   
int tampil()
{
    if (awal==NULL)
         cout<<"Kosong"<<endl;
    else
    {
        temp=awal;
        while(temp!=NULL)
        {
           cout<<"NIM	: "<<temp->nim<<endl;
           cout<<"NAMA	: "<<temp->nama<<endl;
           cout<<"Prodi	: "<<temp->prodi<<endl;
           cout<<"IPK	: "<<temp->ipk<<endl;
           cout<<endl;
           temp=temp->next;
        }
    }
    getch();
}

