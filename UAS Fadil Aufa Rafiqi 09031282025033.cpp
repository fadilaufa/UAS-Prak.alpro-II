#include<iostream>
#include <cstdlib>
using namespace std;

void tampil(struct data isi[]);
void cari1(struct data isi[]);
void cari2(struct data isi[]);
void cari3(struct data isi[]);


struct data {
		int no;
		string namabrg;
		int harga;
		int stok;
	};

int main (){
	
	struct data isi[11], swap;
	isi[1].no = 1 ;		isi[1].namabrg = "Obeng	" ; isi[1].harga = 13500 ;		isi[1].stok = 45 ;
	isi[2].no = 2 ;		isi[2].namabrg = "Gembok	" ; isi[2].harga = 18900 ;		isi[2].stok = 29 ;
	isi[3].no = 3 ;		isi[3].namabrg = "Tang	" ; isi[3].harga = 12500 ;		isi[3].stok = 14 ;
	isi[4].no = 4 ;		isi[4].namabrg = "Kabel	" ; isi[4].harga = 5500  ;		isi[4].stok = 31 ;
	isi[5].no = 5 ;		isi[5].namabrg = "Sabun	" ; isi[5].harga = 2000  ;		isi[5].stok = 50 ;
	isi[6].no = 6 ;		isi[6].namabrg = "Odol	" ; isi[6].harga = 3100  ;		isi[6].stok = 22 ;
	isi[7].no = 7 ;		isi[7].namabrg = "Pel	" ; isi[7].harga = 9000  ;		isi[7].stok = 65 ;
	isi[8].no = 8 ;		isi[8].namabrg = "Sapu	" ; isi[8].harga = 13800 ;		isi[8].stok = 11 ;
	isi[9].no = 9 ;		isi[9].namabrg = "Pisau	" ; isi[9].harga = 22000 ;		isi[9].stok = 5  ;
	isi[10].no = 10;		isi[10].namabrg = "Piring	" ; isi[10].harga = 3300  ;		isi[10].stok = 42 ;
	
	tampil(isi);
	cout<<endl;
	cout<<"   Menu awal : "<<endl;
	cout<<"    1.pencarian"<<endl;
	cout<<"    2.pengurutan"<<endl;
	cout<<"   Pilihan : ";
	int menu1;
	cin>>menu1;
	if (menu1 == 1){
		cout<<"   Menu Pencarian Barang berdasarkan : "<<endl;
		cout<<"    1. Nomor barang  "<<endl;
		cout<<"    2. Harga barang < 5000 "<<endl;
		cout<<"    3. Data stok > 30 "<<endl;
		cout<<"   Pilihan : ";
		int pilih;
		cin>>pilih;
		cout<<endl;
		
		if (pilih == 1){
			cari1(isi);
		}
		else if (pilih == 2){
			cari2(isi);
		}
		else if (pilih == 3){
			cari3(isi);
		}
	}
	else if (menu1 == 2){
		cout<<"   Menu Pengurutan Barang  : "<<endl;
		cout<<"    1. Harga barang dari terendah (bubble sort)  "<<endl;
		cout<<"    2. Harga barang dari terendah (insertion sort)  "<<endl;
		cout<<"    3. Harga barang dari tertinggi (shell sort)  "<<endl;
		cout<<"   Pilihan : ";
		int pilih2;
		cin>>pilih2;
		cout<<endl;
		
		if (pilih2 == 1){
			int z,y,a;
			for (z=1; z<10; z++){
				for (y=1; y<10; y++){
					if (isi[y].harga > isi[y+1].harga){ 
						swap = isi[y];
						isi[y] = isi[y+1];
						isi[y+1] = swap;
					}
				}
			}
			cout<<"   urutan   no         Barang            Harga		Stok \n";
			for (a=1; a<=10; a++){
				cout<<"     "<<a<<"      "<< isi[a].no <<"    	"<<isi[a].namabrg<<" 	"<< isi[a].harga<<"    	" << isi[a].stok<<"   ";
				cout<<endl;
			}
		}
		else if (pilih2 == 2){
			int k, j, kecil;
			for (k=1; k<11; k++){
		 		kecil=k;
				for (j=k; j<11; j++){
			 		if (isi[kecil].harga > isi[j].harga)
			 			kecil = j;
			 	}
			swap = isi[k];     //mengisi swap dengan isi dari pes sekarang
			isi[k] = isi[kecil]; //mengisi pes sekarang dengan pes selanjutnya
			isi[kecil] = swap;
			}
			cout<<"   urutan   no         Barang            Harga		Stok \n";
			for (int a=1; a<=10; a++){
				cout<<"     "<<a<<"      "<< isi[a].no <<"    	"<<isi[a].namabrg<<" 	"<< isi[a].harga<<"    	" << isi[a].stok<<"   ";
				cout<<endl;
			}
		}
		else if (pilih2 == 3){
			for (int i = 10 / 2; i > 0; i = i / 2) {
		        for (int j = i; j < 10; j++) {
		            for (int k = j - i; k >= 0; k = k - i) {
		                if (isi[k + i].harga < isi[k].harga)
		                    break;
		                else {
		                	swap = isi[k];
		                	isi[k] = isi[k+1];
		                	isi[k+1] = swap;
		                }
		            }
		        }
		    }
		    cout<<endl;
		    cout<<"   urutan   no         Barang            Harga		Stok \n";
		    for (int a=1; a<=10; a++){
				cout<<"     "<<a<<"      "<< isi[a].no <<"    	"<<isi[a].namabrg<<" 	"<< isi[a].harga<<"    	" << isi[a].stok<<"   ";
				cout<<endl;
			}
		}
		
	}
		
}

void tampil(struct data isi[]) {
	cout<<"   no          Barang            Harga		Stok \n";
	for (int a=1; a<=10; a++){
		cout<<"     "<< isi[a].no <<"    	"<<isi[a].namabrg<<" 	"<< isi[a].harga<<"    	" << isi[a].stok<<"   ";
		cout<<endl;
	}
}

void cari1(struct data isi[]){
	int no;
	bool found;
	 
	cout << "   Masukkan Nomor Barang : ";
	cin >>no;
	cout<<endl;
	  
	found = false;
	int i = 1;
	while ((i<=10) && (!found)){
		if ( no == isi[i].no)
			found = true;
		else
			i++;
	}
	cout<<"   no          Barang            Harga		Stok \n";
	cout<<"     "<< isi[no].no <<"    	"<<isi[no].namabrg<<" 	"<< isi[no].harga<<"    	" << isi[no].stok<<"   ";
	cout<<endl<<"   ================================================="<<endl;
	
}

void cari2(struct data isi[]){
	cout<<"   Barang dengan Harga Kurang dari 5000 "<<endl;
   	cout<<endl;
   	int i = 1;
   	cout<<"   no          Barang            Harga		Stok \n";
    while (i<=10){
    	if (  isi[i].harga < 5000 ){
			cout<<"     "<< isi[i].no <<"    	"<<isi[i].namabrg<<" 	"<< isi[i].harga<<"    	" << isi[i].stok<<"   ";
    		cout<<endl;
    	} 
    i++;
    }
}

void cari3(struct data isi[]){
	cout<< "   Daftar Barang Dengan Stok lebih dari 30"<<endl;
   	cout<<endl;
   	int i = 1;
   	cout<<"   no          Barang            Harga		Stok \n";
    while (i<=10){
    	if (  isi[i].stok > 30 ){
			cout<<"     "<< isi[i].no <<"    	"<<isi[i].namabrg<<" 	"<< isi[i].harga<<"    	" << isi[i].stok<<"   ";
    		cout<<endl;
    	} 
    i++;
    }
}

