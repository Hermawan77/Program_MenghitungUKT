/* Nama : - Dicky Hermawan (14116005)
          - Rahmad Nurhuda (14116116)
Tugas Besar Dasar Pemrograman
Program Sarana Untuk Menghitung UKT
*/

#include <ctime>     // Random Bilangan
#include <iostream>  // Input Output
#include <conio.h>   // Fungsi Getch
#include <fstream>   // File Eksternal
#include <cstdlib>

using namespace std;

// Membuat Password Agar Menjadi '*'

string bintang(){
	string password;
	char input[128];
	int indeks=0;
	while(1){
		input[indeks]=getch();
		if(input[indeks]=='\r'){
			break;
		}
		else if(input[indeks]==' '){
			input[indeks]=' ';
			indeks++;
			cout << "*";
		}
		else if(input[indeks]=='\b')
		{
			indeks--;
			if(indeks>=0)
			{
				input[indeks]='\b';
				cout << "\b \b";	
			}
			else{
				indeks=0;
			}
		}
		else{
			cout << "*";
			indeks++;
		}
	}
	for(int i=0;i<indeks;i++){
		password+=input[i];
	}
	return password;
}

// Login
void login()
{
	//Reading File
	ifstream file_open;
	int index=0;
	string un[128], pw[128];
	file_open.open("datainduk.txt");
	while(!file_open.eof())
	{
		if(index%2==0)
		{
			getline(file_open, un[index]);
		}
		else
		{
			getline(file_open, pw[index]);
		}
		index++;
	}
	file_open.close();
	
	//Proses
	bool check_un=false, check_pw=false;
	string input_un, input_pw;
	while(1)
	{	
		ofstream dat;
		dat.open("database.txt", ios::app);
		dat << "===================================================================" << endl;
		dat << "No. Pendaftaran : ";
		cout<<"No. Pendaftaran : ";
		getline(cin, input_un);
		cout<<"Password        : ";
		input_pw=bintang();
		for(int i=0; i<index; i++)
		{
			if(input_un==un[i])
			{
				check_un=true;
				break;
			}
		}
		if(check_un)
		{
			for(int i=0; i<index; i++)
			{
				if(input_pw==pw[i])
				{
					check_pw=true;
					break;
				}
			}
			if(check_pw)
			{	
				dat << input_un << endl;
				cout << endl;
				cout<<"Berhasil Login!"<<endl;
				break;
			}
			else
			{
				cout << endl;
				cout<<"Password Salah"<<endl;
				cout << "Silahkan Masukkan dengan benar!";
				cout<<endl << endl;
			}
		}
		else
		{	
			cout << endl;
			cout<<"Username Salah"<<endl;
			cout << "Silahkan Masukkan dengan benar!" << endl << endl;
		}
	dat.close();
	}
}

struct datadiri{
	string nama;
	string ttl;
	string alamat;
	string agama;
	string sekolah;
	char jk;
	string ktp;
	string telp;
	};
	
struct orangtua{
	string ttlayah, alamatayah, pendidikanayah, telpayah;
	string ttlibu, alamatibu, pendidikanibu, telpibu;
};

struct keluarga{
	string nama;
	int umur;
};

int main()
{
	ofstream dat;
	dat.open("database.txt", ios::app);
	
	cout << "\t===================================================================";
				cout << "\t\t\t Tugas Besar Berjudul Program Menentukan UKT" << endl;
				cout << "\t\t\t Mata Kuliah Dasar Pemrograman" << endl;
				cout << "\t===================================================================";
				cout << endl << endl << endl;
	cout << "Silahkan Masukkan No. Pendaftaran & Password";
	cout << endl;
	cout << "*Password adalah tanggal lahir. Contoh : 26-09-1998";
	cout << endl << endl << endl;
	login(); // Memanggil Fungsi Login
	cout << "Press Enter To Continue";
	getch();
	system("cls");
					
	datadiri x[999];
	for(int i=0;i<1;i++){
	cout << "\t===================================================================";
				cout << "\t\t\t\t\t Form UKT" << endl;
				cout << "\t\t\t\tData Diri" << endl;
				cout << "\t===================================================================";
				cout << endl << endl << endl;
				dat << "Nama                 : ";
				cout << "Nama                 : ";
				getline(cin, x[i].nama);
				dat << x[i].nama << endl;
				cout << endl;
				dat << "Tempat Tanggal Lahir : ";
				cout << "Tempat Tanggal Lahir : ";
				getline(cin,x[i].ttl);
				dat << x[i].ttl << endl;
				cout << endl;
				dat << "Alamat               : ";
				cout << "Alamat               : ";
				getline(cin,x[i].alamat);
				dat << x[i].alamat << endl;
				cout << endl;
				dat << "Agama                : ";
				cout << "Agama                : ";
				getline(cin,x[i].agama);
				dat << x[i].agama << endl;
				cout << endl;
				dat << "Asal Sekolah         : ";
				cout << "Asal Sekolah         : ";
				getline(cin,x[i].sekolah);
				dat << x[i].sekolah << endl;
				cout << endl;
				dat << "Jenis Kelamin (L/P)  : ";
				cout << "Jenis Kelamin (L/P)  : ";
				cin >> x[i].jk;
				dat << x[i].jk << endl;
				cout << endl;
				dat << "No. KTP/KK           : ";
				cout << "No. KTP/KK           : ";
				cin >> x[i].ktp;
				dat << x[i].ktp << endl;
				cin.ignore();
				cout << endl;
				dat << "No. Telp             : ";
				cout << "No. Telp             : ";
				cin >> x[i].telp;
				dat << x[i].telp << endl;
				cin.ignore();
				cout << endl;
				cout << "Press Enter To Continue . . . ";
				getch();
				system("cls");
			}
	string ayah, ibu;
	orangtua y[999];
	for(int i=1;i<=1;i++){
	cout << "\t===================================================================";
				cout << "\t\t\t\t\t Form UKT" << endl;
				cout << "\t\t\t\tData Orang Tua" << endl;
				cout << "\t===================================================================";
				cout << endl << endl << endl;
				
				dat << "Nama Ayah            : ";
	            cout << "1. Data Ayah" << endl << endl;
				cout << "Nama Ayah            : ";
	  			getline(cin,ayah);
	  			dat << ayah << endl;
	  			cout << endl;
	  			cout << "Tempat Tanggal Lahir : ";
	  			getline(cin,y[i].ttlayah);
				cout << endl;
	  			cout << "Pendidikan Terakhir  : ";
	  			getline(cin,y[i].pendidikanayah);
				cout << endl;
	  			cout << "No. Telp             : ";
	  			cin >> y[i].telpayah;
	  			
				cout << "Press Enter To Continue . . . ";
				getch();
	  			system("cls");
	  			
	  			
	  			cout << "\t===================================================================";
				cout << "\t\t\t\t\t Form UKT" << endl;
				cout << "\t\t\t\tData Orang Tua" << endl;
				cout << "\t===================================================================";
				cout << endl << endl << endl;
				dat << "Nama Ibu             : ";
	            cout << "2. Data Ibu" << endl << endl;
				cout << "Nama Ibu             : ";
				cin.ignore();
	 			getline(cin,ibu);
	  			dat << ibu << endl;
				cout << endl;
	  			cout << "Tempat Tanggal Lahir : ";
	  			getline(cin,y[i].ttlibu);
	  			cout << endl;
	  			cout << "Pendidikan Terakhir : ";
	  			getline(cin,y[i].pendidikanibu);
				cout << endl;
	  			cout << "No. Telp            : ";
	  			cin >> y[i].telpibu;
	  			cin.ignore();
				cout << endl;
}
				cout << "Press Enter To Continue . . . ";
				getch();
system("cls");
	string pekerjaanayah, pekerjaanibu;
	float gajiayah, gajiibu, n;
	int tanggungan=1;
	keluarga z[999];
	float tagihanlistrik, listrik1, listrik2, listrik3;
	
	cout << "\t===================================================================";
	cout << "\t\t\t\t\t Form UKT" << endl;
	cout << "\t\t\tData Tanggungan Orang Tua" << endl;
	cout << "\t===================================================================";
	cout << endl << endl << endl;
				dat << "Pekerjaan Ayah       : ";
				cout << "1. Data Ayah" << endl << endl;
				cout << "*Beri (-) jika tidak bekerja" << endl;
	  			cout << "Pekerjaan          : ";
	  			cin.ignore();
	  			getline(cin,pekerjaanayah);
	  			dat << pekerjaanayah << endl;
	  			cout << endl;
	  			cout << "*Isi (0) jika tidak bekerja" << endl;
				cout << "Gaji Ayah          : ";
				cin >> gajiayah;
				cout << endl << endl;
				dat << "Pekerjaan Ibu        : ";
				cout << "2. Data Ibu" << endl << endl;
	  			cout << "*Beri (-) jika tidak bekerja" << endl;
				cout << "Pekerjaan          : ";
	  			cin.ignore();
	  			getline(cin,pekerjaanibu);
	  			dat << pekerjaanibu << endl;
	  			cout << endl;
				cout << "*Isi (0) jika tidak bekerja" << endl;
				cout << "Gaji Ibu           : ";
				cin >> gajiibu;
				cout << endl << endl;
system("cls");
				cout << "\t===================================================================";
				cout << "\t\t\t\t\t Form UKT" << endl;
				cout << "\t\t\tData Tanggungan Orang Tua" << endl;
				cout << "\t===================================================================";
				cout << endl << endl << endl;
	
				cout << "3. Data Tanggungan Keluarga" << endl << endl;
				cout << "Selain Pendaftar. Contoh : Adik & Kakak" << endl;
				cout << "Masukkan Jumlah Tanggungan : ";
				cin >> n;
				cout << endl;
				for(int i=1;i<=n;i++){
					cout << "Data Keluarga Ke-" << i;
					cout << endl;
					cout << "Nama                : ";
					cin.ignore();
					getline(cin,z[i].nama);
					cout << endl;
					cout << "Umur                : ";
					cin >> z[i].umur;
					if((z[i].umur>0)&&(z[i].umur<=24)){
						tanggungan = tanggungan + 1;
					}
					cout << endl;
				}
				cout << endl << endl;
				
				cout << "Press Enter To Continue";
				getch();
				system("cls");
				cout << "\t===================================================================";
				cout << "\t\t\t\t\t Form UKT" << endl;
				cout << "\t\t\tData Tanggungan Orang Tua" << endl;
				cout << "\t===================================================================";
				cout << endl << endl << endl;
	
				cout << "4. Tagihan Listrik" << endl << endl;
				cout << "Masukkan Tagihan Listrik 1 Bulan Lalu : ";
				cin >> listrik1;
				cout << "Masukkan Tagihan Listrik 2 Bulan Lalu : ";
				cin >> listrik2;
				cout << "Masukkan Tagihan Listrik 3 Bulan Lalu : ";
				cin >> listrik3;
				tagihanlistrik = (listrik1 + listrik2 + listrik3) / 3;

cout << "Press Enter To Continue";
				getch();
system("cls");
		char bidikmisi;
		int jalur, prodi;
		float total, normalisasi;
		unsigned long int ukt;
		
	cout << "\t===================================================================";
				cout << "\t\t\t\t\t Form UKT" << endl;
				cout << "\t\t\t      Penentuan UKT" << endl;
				cout << "\t===================================================================";
				cout << endl << endl << endl;
			
	unsigned long int regional;
	int provinsi, pilih;
	int gol1 = 500000;
	int gol2 = 1000000;
	int gol3 = 2000000;
	int gol4 = 3500000;
	int gol5 = 5000000;
	int gol6 = 6500000;
	int gol7 = 8000000;
	int gol8 = 9500000;
	
	cout << "1. Aceh";
	cout << "\t\t\t\t2. Sumatera Utara" << endl;
	cout << "3. Sumatera Barat";
	cout << "\t\t4. Bangka Belitung" << endl;
	cout << "5. Kepulauan Riau";
	cout << "\t\t6. Riau" << endl;
	cout << "7. Jambi";
	cout << "\t\t\t8. Bengkulu" << endl;
	cout << "9. Sumatera Selatan";
	cout << "\t\t10. Lampung" << endl;
	cout << "11. Banten";
	cout << "\t\t\t12. DKI Jakarta" << endl;
	cout << "13. Jawa Barat";
	cout << "\t\t\t14. Jawa Tengah" << endl;
	cout << "15. Jawa Timur";
	cout << "\t\t\t16. DIY Yogyakarta" << endl;
	cout << "17. Bali";
	cout << "\t\t\t18. Nusa Tenggara Barat" << endl;
	cout << "19. Nusa Tenggara Timur";
	cout << "\t\t20. Kalimantan Barat" << endl;
	cout << "21. Kalimantan Selatan";
	cout << "\t\t22. Kalimantan Tengah" << endl;
	cout << "23. Kalimantan Timur";
	cout << "\t\t24. Kalimantan Utara" << endl;
	cout << "25. Gorontalo";
	cout << "\t\t\t26. Sulawesi Utara" << endl;
	cout << "27. Sulawesi Tengah";
	cout << "\t\t28. Sulawesi Tenggara" << endl;
	cout << "29. Sulawesi Barat";
	cout << "\t\t30. Sulawesi Selatan" << endl;
	cout << "31. Maluku";
	cout << "\t\t\t32. Maluku Utara" << endl;
	cout << "33. Papua";
	cout << "\t\t\t34. Papua Barat" << endl;
	pilih :
	cout << "Asal Provinsi : ";
	cin >> provinsi;
	switch(provinsi){
		case 1: regional=2500000 ; break;
		case 2: regional=1961354 ; break;
		case 3: regional=1949284 ; break;
		case 4: regional=2538673 ; break;
		case 5: regional=2358454 ; break;
		case 6: regional=2266722 ; break;
		case 7: regional=1906650 ; break;
		case 8: regional=1605000 ; break;
		case 9: regional=2388000 ; break;
		case 10: regional=1908447 ; break;
		case 11: regional=1931180 ; break;
		case 12: regional=3355750 ; break;
		case 13: regional=1420624 ; break;
		case 14: regional=1367000 ; break;
		case 15: regional=1388000 ; break;
		case 16: regional=1337645 ; break;
		case 17: regional=1956727 ; break;
		case 18: regional=1631245 ; break;
		case 19: regional=1525000 ; break;
		case 20: regional=1882900 ; break;
		case 21: regional=2258000 ; break;
		case 22: regional=2227307 ; break;
		case 23: regional=2354800 ; break;
		case 24: regional=2030000 ; break;
		case 25: regional=2030000 ; break;
		case 26: regional=2598000 ; break;
		case 27: regional=1807775 ; break;
		case 28: regional=2002625 ; break;
		case 29: regional=2435625 ; break;
		case 30: regional=2435625 ; break;
		case 31: regional=1925000 ; break;
		case 32: regional=1975000 ; break;
		case 33: regional=2663646 ; break;
		case 34: regional=2421500 ; break;
	default : cout << "Input Salah" << endl;
	goto pilih;
	break;
}	
	system("cls");
	int sipil, sipil1, mesin, mesin1, lingkungan, lingkungan1, arsi, arsi1;
	int pwk, pwk1, informatika, informatika1, elektro, elektro1, geomatika, geomatika1;
	int geofisika, geofisika1, geologi, geologi1, fisika, fisika1, mtk, mtk1, industri;
	int kimia, farmasi, biologi;
	
cout << "Prodi\t\t\t\t\tJalur Masuk" << endl;
	cout << "1. Teknik Sipil\t\t\t\tSNM, SBM, UM " << endl;
	cout << "2. Teknik Mesin\t\t\t\tSNM, SBM, UM" << endl;
	cout << "3. Teknik Lingkungan\t\t\tSNM, SBM, UM" << endl;
	cout << "4. Arsitektur\t\t\t\tSNM, SBM, UM" << endl;
	cout << "5. Perencanaan Wilayah Dan Kota\t\tSNM, SBM, UM" << endl;
	cout << "6. Teknik Informatika\t\t\tSNM, SBM, UM" << endl;
	cout << "7. Teknik Elektro\t\t\tSNM, SBM, UM" << endl;
	cout << "8. Teknik Geomatika\t\t\tSNM, SBM, UM" << endl;
	cout << "9. Teknik Geofisika\t\t\tSNM, SBM, UM" << endl;
	cout << "10. Teknik Geologi\t\t\tSNM, SBM, UM" << endl;
	cout << "11. Fisika\t\t\t\tSNM, SBM, UM" << endl;
	cout << "12. Matematika\t\t\t\tSNM, SBM, UM" << endl;
	cout << "13. Teknik Industri\t\t\tUM" << endl;
	cout << "14. Teknik Kimia\t\t\tUM" << endl;
	cout << "15. Farmasi\t\t\t\tUM" << endl;
	cout << "16. Biologi\t\t\t\tUM" << endl;
	jurusan :
	cout << "Masukkan Prodi Anda : ";
	cin >> prodi;
	
	int masuk, masuk1, masuk2, masuk3, masuk4, masuk5, masuk6, masuk7, masuk8, masuk9, masuk10, masuk11, masuk12, masuk13, masuk14, masuk15;
	switch(prodi){
		case 1: 
				masuk :
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	
				if(jalur==1||jalur==2){
	sipil1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
		goto sipil1;	
	}
	}
	else if(jalur==3){
	sipil :
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << 0;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah Masukan Dengan Benar !!";
		goto sipil;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk;
	}
break;
		case 2: masuk1:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				if(jalur==1||jalur==2){
	mesin1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
		goto mesin1;
	}
	}
	else if(jalur==3){
	mesin:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else {
		cout << "Input Salah !";
		goto mesin;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk1;
	}
break;
		case 3: masuk2:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
		
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				if(jalur==1||jalur==2){
	lingkungan :
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto lingkungan;
	}
	}
	else if(jalur==3){
		lingkungan1 :
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !";
		goto lingkungan1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk2;
	}
break;
		case 4: masuk3:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				if(jalur==1||jalur==2){
					arsi :
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;

	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto arsi;
	}
	}
	else if(jalur==3){
		arsi1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !";
		goto arsi1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk3;
	}
break;
		case 5: masuk4:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				if(jalur==1||jalur==2){
					pwk:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto pwk;
	}
	}
	else if(jalur==3){
	pwk1 :
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
else{
		cout << "Input Salah !";
		goto pwk1;
	}
	}
	else {
		cout << "Input Salah !" << endl;
		goto masuk4;
	}
break;
		case 6: masuk5:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				
				if(jalur==1||jalur==2){
	informatika :
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = 9000000;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = 9000000;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto informatika;
	}
	}
	else if(jalur==3){
		informatika1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = 9000000;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = 9000000;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !";
		goto informatika1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk5;
	}
break;
		case 7: masuk6:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 

				if(jalur==1||jalur==2){
	elektro :
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto elektro;
	}
	}
	else if(jalur==3){
	 elektro1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !";
		goto elektro1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk6;
	}
break;
	case 8: masuk7:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	
				if(jalur==1||jalur==2){
	geomatika:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto geomatika;
	}
	}
	else if(jalur==3){
	geomatika1:	
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !";
		goto geomatika1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk7;
	}
break;
	case 9: masuk8:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	
				if(jalur==1||jalur==2){
	geofisika:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto geofisika;
	}
	}
	else if(jalur==3){
		geofisika1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !" << endl;
		goto geofisika1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk8;
	}
break;
	case 10: masuk9:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	
				if(jalur==1||jalur==2){
	geologi:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto geologi;
	}
	}
	else if(jalur==3){
		geologi1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !" << endl;
		goto geologi1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk9;
	}
break;
	case 11: masuk10:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	
				if(jalur==1||jalur==2){
	fisika:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto fisika;
	}
	}
	else if(jalur==3){
		fisika1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt = 0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !" << endl;
		goto fisika1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk10;
	}
break;
	case 12: masuk11:
				cout <<"1. SNMPTN" << endl;
				cout <<"2. SBMPTN" << endl;
				cout <<"3. Ujian Mandiri" << endl;
				cout << "Jalur Masuk : ";
				cin >> jalur;
				system("cls");
				
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	
				if(jalur==1||jalur==2){
	mtk:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
	if(total<500000){
		ukt = 0;
		cout << "Selamat Anda Terpilih Sebagai Mahasiswa Penerima Beasiswa Bidikmisi" << endl;
		cout << "UKT anda adalah = Rp." << ukt;
	}
	else if((total>500000)&&(total<750000)){
		ukt = gol1;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
}
	else if(bidikmisi=='N'||bidikmisi=='n'){
	normalisasi = (1908447/regional) * (gajiayah + gajiibu);
	total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
	if(total<750000){
		ukt = gol1;
		cout << "UKT anda adalah Gol 1 = Rp." << ukt;
	} 
	else if((total>750000)&&(total<1250000)){
		ukt = gol2;
		cout << "UKT anda adalah Gol 2 = Rp." << ukt;
	}
	else if((total>1250000)&&(total<2750000)){
		ukt = gol3;
		cout << "UKT anda adalah Gol 3 = Rp." << ukt;
	}
	else if((total>2750000)&&(total<4250000)){
		ukt = gol4;
		cout << "UKT anda adalah Gol 4 = Rp." << ukt;
	}
	else if((total>4250000)&&(total<5750000)){
		ukt = gol5;
		cout << "UKT anda adalah Gol 5 = Rp." << ukt;
	}
	else if((total>5750000)&&(total<7000000)){
		ukt = gol6;
		cout << "UKT anda adalah Gol 6 = Rp." << ukt;
	}
	else if((total>7000000)&&(total<8750000)){
		ukt = gol7;
		cout << "UKT anda adalah Gol 7 = Rp." << ukt;
	}
	else if(total>8750000){
		ukt = gol8;
		cout << "UKT anda adalah Gol 8 = Rp." << ukt;
	}
	}
	else{
		cout << "Silahkan Masukkan Input Dengan Benar" << endl;
	goto mtk;
	}
	}
	else if(jalur==3){
	mtk1:
	cout << "Penerima Bidikmisi ? (Y/N)";
	cin >> bidikmisi;
	cout << endl;
	
	if(bidikmisi=='Y'||bidikmisi=='y'){
		if((total>0)&&(total<4250000)){
			ukt =0;
			cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
			cout << "UKT anda sebesar : Rp." << ukt;
		}
		else{
		cout << "Maaf, Pengajuan Beasiswa Anda Ditolak" << endl;
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	}	
	else if(bidikmisi=='N'||bidikmisi=='n'){
		ukt = gol8;
		cout << "UKT anda adalah : Rp." << ukt;
	}
	else{
		cout << "Input Salah !" << endl;
		goto mtk1;
	}
}
	else {
		cout << "Input Salah !" << endl;
		goto masuk11;
	}
break;
			case 13: 
				system("cls");
				cout << "Jalur Masuk : Ujian Mandiri" << endl << endl;			
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				industri:
				cout << "Penerima Bidikmisi ? (Y/N)";
				cin >> bidikmisi;
				cout << endl;
	
		if(bidikmisi=='Y'||bidikmisi=='y'){
				if((total>0)&&(total<4250000)){
					ukt = 0;
						cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
						cout << "UKT anda sebesar : Rp." << ukt;
	}
				else{
					ukt = gol8;
					cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
					cout << "UKT anda adalah : Rp." << ukt;
				}				
	}
		else if(bidikmisi=='N'||bidikmisi=='n'){
			cout << "UKT anda adalah : Rp." << ukt;
		}
	else{
		cout << "Input Salah !" << endl;
		goto industri;
	}
		break;
		case 14: 
				system("cls");
				cout << "Jalur Masuk : Ujian Mandiri" <<endl << endl;			
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				kimia:
				cout << "Penerima Bidikmisi ? (Y/N)";
				cin >> bidikmisi;
				cout << endl;
	
		if(bidikmisi=='Y'||bidikmisi=='y'){
				if((total>0)&&(total<4250000)){
					ukt =0;
						cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
						cout << "UKT anda sebesar : Rp." << ukt;
	}
				else{
					ukt = gol8;
					cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
					cout << "UKT anda adalah : Rp." << ukt;
				}				
	}
		else if(bidikmisi=='N'||bidikmisi=='n'){
			cout << "UKT anda adalah : Rp." << ukt;
		}
	else{
		cout << "Input Salah !" << endl;
		goto kimia;
	}
		break;
		case 15: 
				system("cls");
				cout << "Jalur Masuk : Ujian Mandiri" << endl << endl;			
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				farmasi:
				cout << "Penerima Bidikmisi ? (Y/N)";
				cin >> bidikmisi;
				cout << endl;
	
		if(bidikmisi=='Y'||bidikmisi=='y'){
				if((total>0)&&(total<4250000)){
					ukt = 0;
						cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
						cout << "UKT anda sebesar : Rp." << ukt;
	}
				else{
					ukt = gol8;
					cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
					cout << "UKT anda adalah : Rp." << ukt;
				}				
	}
		else if(bidikmisi=='N'||bidikmisi=='n'){
			cout << "UKT anda adalah : Rp." << ukt;
		}
	else{
		cout << "Input Salah !" << endl;
		goto farmasi;
	}
		break;
		case 16: 
				system("cls");
				cout << "Jalur Masuk : Ujian Mandiri" << endl << endl;			
				normalisasi = (1908447/regional) * (gajiayah + gajiibu);
				total = (normalisasi/tanggungan) + (tagihanlistrik * 0.70); 
				biologi:
				cout << "Penerima Bidikmisi ? (Y/N)";
				cin >> bidikmisi;
				cout << endl;
	
		if(bidikmisi=='Y'||bidikmisi=='y'){
				if((total>0)&&(total<4250000)){
					ukt = 0;
						cout << "Selamat Pengajuan Beasiswa Anda Diterima Sebagai Mahasiswa Bina Lingkungan" << endl;
						cout << "UKT anda sebesar : Rp." << ukt;
	}
				else{
					ukt = gol8;
					cout << "Maaf Pengajuan Beasiswa Anda Ditolak" << endl;
					cout << "UKT anda adalah : Rp." << ukt;
				}				
	}
		else if(bidikmisi=='N'||bidikmisi=='n'){
			cout << "UKT anda adalah : Rp." << ukt;
		}	
	else{
		cout << "Input Salah !" << endl;
		goto biologi;
	}
		break;
		default : cout << "Input Salah !" << endl;
				  goto jurusan;
				  break;
}
cout << endl << endl;
cout << "Press Enter To Continue . . .";
getch();

system("cls");

	cout << "\t===================================================================";
				cout << "\t\t\t\t\t Form UKT" << endl;
				cout << "\t\t\tStatus Kelengkapan Dokumen" << endl;
				cout << "\t===================================================================";
				cout << endl << endl << endl;
				
				for(int i=0;i<1;i++){
				cout << "Nama                 : " << x[i].nama;
				cout << endl;
				cout << "Tempat Tanggal Lahir : " << x[i].ttl;
				cout << endl;
				cout << "Alamat               : " << x[i].alamat;
				cout << endl;
				cout << "Agama                : " << x[i].agama;
				cout << endl;
				cout << "Asal Sekolah         : " << x[i].sekolah;
				cout << endl;
				cout << "Jenis Kelamin        : " << x[i].jk;
				cout << endl;
			}
				cout << "Nama Ayah            : " << ayah;
				cout << endl;
				cout << "Pekerjaan            : " << pekerjaanayah;
				cout << endl;
				cout << "Nama Ibu             : " << ibu;
				cout << endl;
				cout << "Pekerjaan            : " << pekerjaanibu;
				cout << endl;
				dat << "Besar UKT            : Rp.";
				cout << "Besar UKT            : Rp." << ukt;
			cout << endl;
			dat << ukt << endl;
			if(ukt>0){
			int tmp[8];
			
			srand(time(NULL));
			for(int i=0; i<8; i++){
				tmp[i]=rand()%10+1;
					}
			dat << "No. Virtual Account  : ";
			cout << "No. Virtual Account : ";
			for(int i=0; i<8; i++){
				cout << tmp[i];
				dat << tmp[i];
					}
				}
				dat << endl;
cout << endl << endl;
cout << "Data Telah Disimpan Di database.txt ";

dat.close();

return 0;
}
