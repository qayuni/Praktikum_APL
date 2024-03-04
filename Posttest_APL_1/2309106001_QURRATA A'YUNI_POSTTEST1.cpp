#include <iostream>

using namespace std;

int main(){
	string username = "Qurrata Ayuni";
	string password = "2309106001";
	string user_input,login;
    string lanjut = "y";
	string pass_input;
	int  rupiah, usd_rp, eur_rp, yen_rp;
	float rp_usd, rp_eur, rp_yen, usd_eur, usd_yen,eur_usd, eur_yen, yen_usd, yen_eur;
	float dolar, euro, yen;
	char pilihan;
	
	
	
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
	    cout<<"=================================="<<endl;
	    cout<<"|   Program konversi Mata Uang   |"<<endl;
	    cout<<"=================================="<<endl;
	    cout<<"|        Pilih Mata Uang         |"<<endl;
	    cout<<"=================================="<<endl;
	    cout<<"| 1 | Rupiah > Dollar, Euro, Yen |"<<endl;
	    cout<<"| 2 | Dollar > Rupiah, Euro, Yen |"<<endl;
	    cout<<"| 3 | Euro > Rupiah, Dollar, Yen |"<<endl;
	    cout<<"| 4 | Yen > Rupiah, Dollar, Euro |"<<endl;
	    cout<<"=================================="<<endl;
	    cout<<"Pilihan : ";
	    cin>>pilihan;
	    
	    
		
		switch(pilihan){
	    case  '1':
	    	cout<<"Nominal Rupiah : ";
	    	cin>>rupiah;
	    	rp_usd = static_cast<float>(rupiah)* 0.000064;
	    	rp_eur = static_cast<float>(rupiah)* 0.000059;
	    	rp_yen = static_cast<float>(rupiah)* 0.0096;

	    	cout<<"Rp" <<rupiah<<" = $"<<rp_usd<<endl;
	    	cout<<"Rp" <<rupiah<<" = €"<<rp_eur<<endl;
	    	cout<<"Rp" <<rupiah<<" = ¥"<<rp_yen<<endl;
	    break;
	    case '2':
	    	cout<<"Nominal Dolar : ";
	    	cin>>dolar;
	    	usd_rp = static_cast<int>(dolar)* 15701;
	    	usd_eur = dolar * 0.92;
	    	usd_yen = dolar * 150,10;

	    	cout<<"$"<<dolar<<" = Rp"<<usd_rp<<endl;
	    	cout<<"$"<<dolar<<" = €"<<usd_eur<<endl;
	    	cout<<"$"<<dolar<<" = ¥"<<usd_yen<<endl;
	    break;
	    case '3':
	    	cout<<"Nominal Euro : ";
	    	cin>>euro;
	    	eur_rp = static_cast<int>(euro)* 17043;
	    	eur_usd = euro *1.09;
	    	eur_yen = euro *162.93;

	    	cout<<"€"<<euro<<" = Rp"<<eur_rp<<endl;
	    	cout<<"€"<<euro<<" = $" <<eur_usd<<endl;
	    	cout<<"€"<<euro<<" = ¥"<<eur_yen<<endl;
	    break;
	    case '4':
	    	cout<<"Nominal Yen : ";
	    	cin>>yen;
	    	yen_rp = static_cast<int>(yen)* 104;
	    	yen_usd = yen * 0.0067;
	    	yen_eur = yen * 0.0061;

	    	cout<<"¥"<<yen<<" = Rp"<<yen_rp<<endl;
	    	cout<<"¥"<<yen<<" = $"<<yen_usd<<endl;
	    	cout<<"¥"<<yen<<" = €"<<yen_eur<<endl;
	    break;
        default:
            cout<<"Menu tidak tersedia"<<endl;
        break;
        }
        cout<<"Ingin melanjutkan ? (y/t) ";
        cin>>lanjut;
        if (lanjut == "t" || lanjut == "T"){
        	system("cls");
    		cout<<"==========================="<<endl;
   			cout<<" Memberhentikan Program..."<<endl;
    		cout<<"==========================="<<endl;
			system("pause");
			lanjut = "t";
			
		}
		else{
			cout<<"Maaf, pilihan anda salah."<<endl;
			cout<<"Silahkan coba lagi."<<endl;
			cin.clear();
	    	cin.ignore();
		}
	}
    
	return 0;
}

