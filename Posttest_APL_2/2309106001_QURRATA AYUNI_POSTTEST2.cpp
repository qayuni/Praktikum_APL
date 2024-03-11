#include <iostream>

using namespace std;

const int max_destinasi = 100;

struct destinasiwisata{
	string nama;
	string lokasi;
	float rating;
};

void tambahDestinasi(destinasiwisata destinasi[], int &jmlh);
void displayDestinasi(destinasiwisata destinasi[], int jmlh);
void updateDestinasi(destinasiwisata destinasi[], int jmlh);
void deleteDestinasi(destinasiwisata destinasi[], int &jmlh);

int main(){
	destinasiwisata destinasi[max_destinasi];
	string username = "Qurrata Ayuni";
	string password = "2309106001";
	string user_input,login;
    string lanjut = "y";
	string pass_input;
	char pilihan,pilih_update;
	int jmlh = 0;
	
	cout<<"============================="<<endl;
	cout<<"     M E N U  L O G I N"<<endl;
	cout<<"=============================\n\n";
	
	
	for(int i = 1; i<4; i++){
		cout<<"Masukan Username : ";
		getline(cin,user_input);
		cout<<"Masukan Password : ";
		cin>>pass_input;
		if(user_input == username && pass_input == password){
			cout<<"\n============================="<<endl;
			cout<<"       Login Berhasil "<<endl;
			cout<<"============================="<<endl;
			login = "berhasil";
			system("pause");
			break;
			}
		else{
			cout<<"\n=============================="<<endl;
			cout<<" Username atau Password Salah"<<endl;
			cout<<"    Silahkan cek Kembali"<<endl;
			cout<<"==============================\n"<<endl;
			cin.ignore();
			continue;
			}
	}
	if(login != "berhasil"){
		cout<<"\nAnda telah mencoba login sebanyak 3x,"<<endl;
		cout<<"Memberhentikan program..."<<endl;
		system("pause");
		
	}
	while(login == "berhasil" &&  (lanjut == "y"|| lanjut == "Y")){
		system("cls");
		cout<<"====================================="<<endl;
	    cout<<"|   Program Data Destinasi Wisata   |"<<endl;
	    cout<<"====================================="<<endl;
	    cout<<"|            Pilih Menu             |"<<endl;
	    cout<<"====================================="<<endl;
	    cout<<"| 1 | Tambah Destinasi Wisata       |"<<endl;
	    cout<<"| 2 | Tampilkan Destinasi Wisata    |"<<endl;
	    cout<<"| 3 | Perbarui Destinasi Wisata     |"<<endl;
	    cout<<"| 4 | Hapus Destinasi Wisata        |"<<endl;
	    cout<<"====================================="<<endl;
	    cout<<"Pilihan (1-4) : ";
	    cin>>pilihan;
	    
	    switch(pilihan){
	    	case '1':
	    		tambahDestinasi(destinasi, jmlh);
	    		break;
	    	case '2':
	    		displayDestinasi(destinasi, jmlh);
	    		break;
	    	case '3':
	    		updateDestinasi(destinasi, jmlh);
	    		break;
	    	case '4':
	    		deleteDestinasi(destinasi, jmlh);
	    		break;
	    	default:
	    		cout<<"Menu tidak valid. Silahkan coba kembali";
	    		break;
			}
			cout<<"\nIngin melanjutkan? (y/n) : ";
			cin>>lanjut;
			if(lanjut == "n" || lanjut == "N"){
				system("cls");
    			cout<<"==========================="<<endl;
				cout<<" Memberhentikan Program..."<<endl;
    			cout<<"==========================="<<endl;
				system("pause");
				lanjut = "t";
			}
			else if(lanjut == "y" || lanjut == "Y"){
				lanjut = "y";
			}
			else{
				cout<<"\nMaaf, pilihan anda tidak valid."<<endl;
				cout<<"Silahkan coba lagi."<<endl;
				system("pause");
				lanjut = "y";
			}	
	}
	return 0;
}

void tambahDestinasi(destinasiwisata destinasi[], int &jmlh){
	if(jmlh < max_destinasi){
		cout<<"Masukkan nama destinasi : ";
		cin.ignore();
		getline(cin, destinasi[jmlh].nama);
		cout<<"Masukkan lokasi destinasi : ";
		getline(cin, destinasi[jmlh].lokasi);
		cout<<"Masukkan rating destinasi (1-5) : ";
		cin>>destinasi[jmlh].rating;
		
		jmlh ++;
		cout<<"\nDestinasi berhasil ditambahkan"<<endl;
	}
	else{
		cout<<"\nMaaf, batas maksimal destinasi wisata telah mencapai maksimum!"<<endl;
	}
}
void displayDestinasi(destinasiwisata destinasi[], int jmlh){
	if(jmlh>0){
		cout << "\n===== Daftar Destinasi Wisata =====\n";
		for (int i=0; i<jmlh;i++){
			cout<<"\nData ke-"<<i<<endl;
			cout<<"Nama Destinasi : "<<destinasi[i].nama<<endl;
			cout<<"Lokasi : "<<destinasi[i].lokasi<<endl;
			cout<<"Rating : "<<destinasi[i].rating<<endl;
		}
		cout << "\n===================================\n";
	}
	else{
		cout<<"\nBelum ada destinasi wisata yang ditambahkan"<<endl;
	}
}
	
	
void updateDestinasi(destinasiwisata destinasi[], int jmlh){
	if(jmlh>0){
		displayDestinasi(destinasi, jmlh);
		char pilih_update;
		int indeks;
		cout<<"\nMasukkan indeks destinasi yang ingin diubah : ";
		cin>>indeks;
			
		if(indeks>=0 && indeks < jmlh){
			cout<<"\n1. Nama Destinasi"<<endl;
			cout<<"2. Lokasi Destinasi"<<endl;
			cout<<"3. Rating Destinasi"<<endl;
			cout<<"Pilih menu (1-3) : ";
			cin>>pilih_update;
			
			if(pilih_update == '1'){
				cout<<"\nMasukkan nama destinasi baru : ";
				cin.ignore();
				getline(cin, destinasi[indeks].nama);
								
				cout<<"\nDestinasi berhasil diperbarui"<<endl;
			}
			else if(pilih_update == '2'){
				cout<<"\nMasukkan lokasi destinasi baru : ";
				cin.ignore();
				getline(cin, destinasi[indeks].lokasi);
					
				cout<<"\nDestinasi berhasil diperbarui"<<endl;
			}
			else if(pilih_update == '3'){
				cout<<"\nMasukkan rating destinasi baru (1-5) : ";
				cin>>destinasi[indeks].rating;
				
				cout<<"\nDestinasi berhasil diperbarui"<<endl;
			}
			else{
				cout<<"\nMenu tidak valid"<<endl;
			}
		}
		}
		else{	
			cout<<"\nBelum ada destinasi wisata yang ditambahkan"<<endl;
		}
	}


void deleteDestinasi(destinasiwisata destinasi[], int &jmlh){
	if(jmlh>0){
		displayDestinasi(destinasi,jmlh);
		int indeks;
		cout<<"\nMasukkan indeks destinasi yang ingin dihapus : ";
		cin>>indeks;
		
		if(indeks>=0 && indeks < jmlh){
			for(int i=indeks; i<jmlh-1;i++){
				destinasi[i] = destinasi[i+1];
			}
			
			jmlh--;
			cout<<"\nDestinasi berhasil dihapus"<<endl;
		}
		else{
			cout<<"\nIndeks tidak valid"<<endl;
		}		
	}
	else{
		cout<<"\nBelum ada destinasi yang ditambahkan"<<endl;
	}
}

