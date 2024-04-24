#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int max_destinasi = 100;

struct ulasan{
	float rating;
	string komentar;
};

struct destinasiwisata{
	string nama;
	string lokasi;
	ulasan ulas;
};


void tambahDestinasi(destinasiwisata destinasi[], int &jmlh, int *total);
void displayDestinasi(destinasiwisata destinasi[], int jmlh, int *total);
void updateDestinasi(destinasiwisata destinasi[], int jmlh, int *total);
void deleteDestinasi(destinasiwisata destinasi[], int &jmlh, int *total);
void quicksort(destinasiwisata destinasi[], int low, int high);
void sequentialSearch(destinasiwisata destinasi[], int jmlh);
void selectionSort(destinasiwisata destinasi[], int jmlh);
void binarySearch(destinasiwisata destinasi[], int jmlh);
void bubbleSort(destinasiwisata destinasi[], int jmlh);

bool login(string user_input, string pass_input) {
    // Username dan password yang valid
    string Username = "Qurrata Ayuni";
    string Password = "2309106001";

    // Memeriksa apakah username dan password cocok dengan yang valid
    if (user_input == Username && pass_input == Password) {
        return true;
    } else {
        return false;
    }
}



bool ulangMenu(char ulang){
	cout<<"\nApakah ingin mengulang? (y/n)";
	cin>>ulang;
	cout<<endl;
	
	if (ulang == 'Y' || ulang == 'y'){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	destinasiwisata destinasi[max_destinasi];
	string user_input, pass_input;;
    string lanjut = "y";
	char pilihan,pilih_update,ulang;
	int jmlh = 0;
	int *total = &jmlh;
	int low, high;
	
	cout<<"============================="<<endl;
	cout<<"     M E N U  L O G I N"<<endl;
	cout<<"=============================\n\n";
	
	
	for(int i = 1; i<4; i++){
		cout<<"Masukan Username : ";
		getline(cin,user_input);
		cout<<"Masukan Password : ";
		cin>>pass_input;
		if(login(user_input, pass_input)){
			cout<<"\n============================="<<endl;
			cout<<"       Login Berhasil "<<endl;
			cout<<"============================="<<endl;
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
	if(login(user_input, pass_input) == false){
		cout<<"\nAnda telah mencoba login sebanyak 3x,"<<endl;
		cout<<"Memberhentikan program..."<<endl;
		system("pause");
		
	}
	while(login(user_input, pass_input) == true){
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
	    cout<<"| 5 | Sorting Destinasi             |"<<endl;
	    cout<<"| 6 | Searching Destinasi           |"<<endl;
	    cout<<"| 7 | Keluar                        |"<<endl;
	    cout<<"====================================="<<endl;
	    cout<<"Pilihan (1-7) : ";
	    cin>>pilihan;
	    
	    switch(pilihan){
	    	case '1':
	    		tambahDestinasi(destinasi, jmlh, total);
	    		break;
	    	case '2':
	    		displayDestinasi(destinasi, jmlh, total);
	    		system("pause");
	    		break;
	    	case '3':
	    		updateDestinasi(destinasi, jmlh, total);
	    		system("pause");
	    		break;
	    	case '4':
	    		deleteDestinasi(destinasi, jmlh, total);
	    		break;
	    	case '5':
	    		char sort;
				cout<<"Sorting berdasarkan : "<<endl;
				cout<<"1. Nama Destinasi "<<endl;
				cout<<"2. Lokasi Destinasi "<<endl;
				cout<<"3. Rating Destinasi "<<endl;
				cout<<"Pilih : "; cin>>sort;
	
				if(sort == '1'){
					quicksort(destinasi, 0, jmlh - 1);
					cout<<"\nData berhasil diurutkan"<<endl;
	 			    system("pause");
				} else if(sort == '2'){
					bubbleSort(destinasi, jmlh);
					cout<<"\nData berhasil diurutkan"<<endl;
	 			    system("pause");
				} else if(sort == '3'){
					selectionSort(destinasi, jmlh);
					cout<<"\nData berhasil diurutkan"<<endl;
	 			    system("pause");
				} else {
					cout<<"\nPilihan tidak valid"<<endl;
				}
	    		break;
	    	case '6':
				char search;
				cout<<"Cari Destinasi berdasarkan :"<<endl;
				cout<<"1. Nama Destinasi "<<endl;
				cout<<"2. Lokasi Destinasi "<<endl;
				cout<<"Pilih : "; cin>>search;
				cin.ignore();
				
				if(search == '1'){
					binarySearch(destinasi,jmlh);
				} else if (search == '2'){
					sequentialSearch(destinasi, jmlh);
				} else {
					cout<<"\nPilihan tidak valid"<<endl;
				}
				break;
	    	case '7':
	    		system("cls");
    			cout<<"==========================="<<endl;
				cout<<" Memberhentikan Program..."<<endl;
    			cout<<"==========================="<<endl;
				system("pause");
				lanjut = "t";
	    		exit(0);
	    	default:
	    		cout<<"Menu tidak valid. Silahkan coba kembali"<<endl;
	    		system("pause");
	    		break;
			}
				
	}
	return 0;
}

void tambahDestinasi(destinasiwisata destinasi[], int &jmlh, int *total){
	if(jmlh < max_destinasi){
		cout<<"\nMasukkan nama destinasi : ";
		cin.ignore();
		getline(cin, destinasi[jmlh].nama);
		cout<<"Masukkan lokasi destinasi : ";
		getline(cin, destinasi[jmlh].lokasi);
		
		do {
            cout << "Masukkan rating destinasi (1-5) : ";
            cin >> destinasi[jmlh].ulas.rating;
            if (cin.fail() || destinasi[jmlh].ulas.rating < 1 || destinasi[jmlh].ulas.rating > 5) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Input tidak valid. Harap masukkan angka antara 1-5." <<endl;
            }
        } while (cin.fail() || destinasi[jmlh].ulas.rating < 1 || destinasi[jmlh].ulas.rating > 5);

		cout<<"Ulasan : ";
		cin.ignore();
		getline(cin, destinasi[jmlh].ulas.komentar);
		
		jmlh ++;
		cout<<"\nDestinasi berhasil ditambahkan\n"<<endl;
		displayDestinasi(destinasi, jmlh, total);
		
		char ulang;
		if(ulangMenu(ulang) == true){
			tambahDestinasi(destinasi, jmlh, total);
		}
	}
	else{
		cout<<"\nMaaf, batas maksimal destinasi wisata telah mencapai maksimum!"<<endl;
	}
}
void displayDestinasi(destinasiwisata destinasi[], int jmlh, int *total){
	if(jmlh>0){
		cout<<"\nJumlah Data Saat Ini : "<<*total<<endl;
		cout << "\n===== Daftar Destinasi Wisata =====\n";
		for (int i=0; i<jmlh;i++){
			cout<<"\nData ke-"<<i<<endl;
			cout<<"Nama Destinasi : "<<destinasi[i].nama<<endl;
			cout<<"Lokasi : "<<destinasi[i].lokasi<<endl;
			cout<<"Rating : "<<destinasi[i].ulas.rating<<endl;
			cout<<"Ulasan :"<<destinasi[i].ulas.komentar<<endl;
			cout << "\n===================================\n";
			}
		}
		
	else {
		cout<<"\nBelum ada destinasi wisata yang ditambahkan"<<endl;
	}
}
	
	
void updateDestinasi(destinasiwisata destinasi[], int jmlh, int *total){
	if(jmlh>0){
		displayDestinasi(destinasi, jmlh, total);
		char pilih_update;
		int indeks;
		do{
			cout<<"\nMasukkan indeks destinasi yang ingin diubah : ";
			cin>>indeks;
			if(cin.fail() || indeks < 0 || indeks >= jmlh){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<<"\nInput tidak valid. Masukkan indeks yang benar"<<endl;
			}	
		}while (cin.fail() || indeks < 0 || indeks >= jmlh); 
		
			
		cout<<"\n1. Nama Destinasi"<<endl;
		cout<<"2. Lokasi Destinasi"<<endl;
		cout<<"3. Rating Destinasi"<<endl;
		cout<<"Pilih menu (1-3) : ";
		cin>>pilih_update;
			
		if (cin.fail() || pilih_update < '1' || pilih_update > '3') {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<< "\nInput tidak valid. Harap masukkan angka 1-3." << endl;
            return;
        }
			
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
			do {
           		cout << "Masukkan rating destinasi (1-5) : ";
           		cin >> destinasi[jmlh].ulas.rating;
            	if (cin.fail() || destinasi[jmlh].ulas.rating < 1 || destinasi[jmlh].ulas.rating > 5) {
              		cin.clear();
               		cin.ignore(numeric_limits<streamsize>::max(), '\n');
            		cout << "Input tidak valid. Harap masukkan angka antara 1-5." <<endl;
            	}
       		} while (cin.fail() || destinasi[jmlh].ulas.rating < 1 || destinasi[jmlh].ulas.rating > 5);
							
			cout<<"\nDestinasi berhasil diperbarui"<<endl;
			displayDestinasi(destinasi, jmlh, total);
		}
		char ulang;
		if(ulangMenu(ulang) == true){
			updateDestinasi(destinasi, jmlh, total);
		}
		}
		else{	
			cout<<"\nBelum ada destinasi wisata yang ditambahkan"<<endl;
		}
	}


void deleteDestinasi(destinasiwisata destinasi[], int &jmlh, int *total){
	if(jmlh>0){
		displayDestinasi(destinasi,jmlh, total);
		int indeks;
		cout<<"\nMasukkan indeks destinasi yang ingin dihapus : ";
		cin>>indeks;
		
		if(indeks>=0 && indeks < jmlh){
			for(int i=indeks; i<jmlh-1;i++){
				destinasi[i] = destinasi[i+1];
			}
			
			jmlh--;
			cout<<"\nDestinasi berhasil dihapus"<<endl;
			displayDestinasi(destinasi, jmlh, total);
		}
		else{
			cout<<"\nIndeks tidak valid"<<endl;
		}
		char ulang;
		if(ulangMenu(ulang) == true){ 
			deleteDestinasi(destinasi, jmlh, total);
		}		
	}
	else{
		cout<<"\nBelum ada destinasi yang ditambahkan"<<endl;
	}
}

void swap(string& a, string& b){
	string temp = a;
	a = b;
	b = temp;
}

int partisi(destinasiwisata destinasi[], int low, int high){
	string pivot = destinasi[high].nama;
	int i = low - 1;
		
	for(int j = low; j < high; j++){
		if(destinasi[j].nama < pivot){
			i++;
			swap(destinasi[i].nama, destinasi[j].nama);
		}
	}
		
	swap(destinasi[i + 1], destinasi[high]);
	return (i + 1);
}	

void quicksort(destinasiwisata destinasi[], int low, int high){
	if(low < high){
		int pi = partisi(destinasi, low, high);
		
		quicksort(destinasi, low, pi - 1);
		quicksort(destinasi, pi + 1, high);
	}
}

void bubbleSort(destinasiwisata destinasi[], int jmlh){
	bool swapped;
	    for (int i = 0; i < jmlh - 1; i++) {
	        swapped = false;
	        for (int j = 0; j < jmlh - i - 1; j++) {
	            if (destinasi[j].lokasi > destinasi[j + 1].lokasi) {
	                swap(destinasi[j], destinasi[j+1]);
	                swapped = true;
	            }
	        }
	        if (!swapped) {
	            break;
	        }
	    }
}

void selectionSort(destinasiwisata destinasi[], int jmlh){
    int max;
    for(int i = 0; i < jmlh - 1; i++){
        max = i;
        for(int j = i + 1; j < jmlh; j++){
            if(destinasi[j].ulas.rating > destinasi[max].ulas.rating){
                max = j;
            }
        }
        swap(destinasi[max], destinasi[i]);
    }
}

void binarySearch(destinasiwisata destinasi[], int jmlh){
	quicksort(destinasi, 0, jmlh - 1);
	string nama;
	
	cout<<"Masukkan Nama Destinasi yang dicari : ";
    getline(cin,nama);
	
	int awal = 0;
	int akhir = jmlh-1;
	int tengah;
	bool find = false;
	
	while(awal <= akhir){
		tengah = awal + (akhir - awal)/2;
		
		if(nama == destinasi[tengah].nama){
			find = true;

            for (int i = tengah; i >= awal && destinasi[i].nama == nama; --i) {
                cout << "\nData Ditemukan!" << endl;
                cout<<"Nama Destinasi : "<<destinasi[i].nama<<endl;
                cout<<"Lokasi : "<<destinasi[i].lokasi<<endl;
                cout<<"Rating : "<<destinasi[i].ulas.rating<<endl;
                cout<<"Ulasan : "<<destinasi[i].ulas.komentar<<endl;
            }

            for (int i = tengah + 1; i <= akhir && destinasi[i].nama == nama; ++i) {
                cout << "\nData Ditemukan!" << endl;
                cout<<"Nama Destinasi : "<<destinasi[i].nama<<endl;
                cout<<"Lokasi : "<<destinasi[i].lokasi<<endl;
                cout<<"Rating : "<<destinasi[i].ulas.rating<<endl;
                cout<<"Ulasan : "<<destinasi[i].ulas.komentar<<endl;
            }

			break;
		} 
        
        if (nama < destinasi[tengah].nama){
			akhir = tengah - 1;
		} else {
			awal = tengah + 1;
		}
	}
	
	if(!find){
		cout<<"\nData Tidak Ditemukan"<<endl;
        cout<<nama;
	}
	system("pause");
}

void sequentialSearch(destinasiwisata destinasi[], int jmlh){
	string lokasi;
	cout<<"Masukan Lokasi Destinasi yang dicari : "; getline(cin,lokasi);
	
	bubbleSort(destinasi, jmlh);
	
	bool find = false;
	for(int i = 0; i < jmlh; i++){
		if(destinasi[i].lokasi == lokasi){
			find = true;
			cout<<"\nData Ditemukan!"<<endl;
			cout<<"\nNama Destinasi : "<<destinasi[i].nama<<endl;
			cout<<"Lokasi : "<<destinasi[i].lokasi<<endl;
			cout<<"Rating : "<<destinasi[i].ulas.rating<<endl;
			cout<<"Ulasan : "<<destinasi[i].ulas.komentar<<endl;
		}
	}
	if(!find){
		cout<<"\nData Tidak Ditemukan"<<endl;
	}
	system("pause");
}
