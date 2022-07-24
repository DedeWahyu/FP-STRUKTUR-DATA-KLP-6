#include <iostream>
#include <conio.h>

using namespace std;

struct Mahasiswa
{
	float responsi, nilai_tugas, nilai_uts, nilai_uas;
	float presensi,tugas,uts,uas;
	
};
	
int main()
{
	Mahasiswa mhs[100];
	Mahasiswa *ptr, persentase;
	ptr = &persentase;
	char matkul[30];
	float hasil_responsi[100], hasil_tugas[100], hasil_uts[100], hasil_uas[100];
	float hasil_akhir[100];
	int menu,jumlah,temp,i,j,kiri,kanan,tengah;
	char cek,cek2,grade;
	string cari,nama[100],nim[100];
	bool ketemu = false;
	
	pilihan:
	cout << "=>=>=>=>=> PROGRAM MENGHITUNG NILAI AKHIR MATA KULIAH <=<=<=<=<=\n" << endl;
	cout << "Pilihlah sesuai angka!" << endl;
	cout << "1. Masukkan persentase nilai" << endl;
	cout << "2. Masukkan data mahasiswa" << endl;
	cout << "3. Tampilkan data mahasiswa" << endl;
	cout << "4. Mencari nama mahasiswa" << endl;
	cout << "5. Menghapus semua data (Opsi 1, 2, 3, dan 4)" << endl;
	cout << "6. Selesai\n" << endl;
	
	cout << "Masukkan pilihan anda : ";
	cin >> menu;
	
	cout << endl;
	switch (menu)
	{
		case 1:
			cout << "1. Masukkan persentase responsi : ";
			cin >> (*ptr).responsi;
			cout << "2. Masukkan persentase tugas : ";
			cin >> (*ptr).tugas;
			cout << "3. Masukkan persentase UTS : ";
			cin >> (*ptr).uts;
			cout << "4. Masukkan persentase UAS : ";
			cin >> (*ptr).uas;
			cout << endl;
			
			cout << "Apakah anda yakin dengan data yang sudah diinputkan?" << endl;
			cout << "(Y/N) : ";
			cin >> cek;
			cout << endl;
			
			if (cek == 'Y')
			{
				cout << "Persentase berhasil ditambahkan! Tekan enter untuk melanjutkan" << endl;
				getch();
				system("cls");
				goto pilihan;
			}
			else if (cek == 'y')
			{
				cout << "Persentase berhasil ditambahkan! Tekan enter untuk melanjutkan" << endl;
				getch();
				system("cls");
				goto pilihan;
			}
			else
			{
				cout << "Persentase gagal ditambahkan! Tekan enter untuk kembali ke menu" << endl;
				getch();
				(*ptr).responsi = 0;
				(*ptr).tugas = 0;
				(*ptr).uts = 0;
				(*ptr).uas = 0;
				system("cls");
				goto pilihan;
			}			
			break;
		case 2:
			if ((*ptr).responsi == 0)
			{
				cout << "Silahkan isi dengan lengkap pilihan pertama! Tekan enter untuk melanjutkan" << endl;
				getch();
				system("cls");
				goto pilihan;
			}
			else
			{
				cin.ignore();
				cout << "Masukkan nama mata kuliah : ";
				cin.getline(matkul,50);
				cout << "Masukkan jumlah mahasiswa yang ingin di data : ";
				cin >> jumlah;
				cout << endl;
			
				cin.ignore();
				for (i = 0; i < jumlah; i++)
				{
					cout << i+1 << ". Masukkan nama mahasiswa : ";
					cin >> nama[i];
					cout << "   Masukkan NIM mahasiswa : ";
					cin >> nim[i];
					cout << "   Masukkan nilai responsi : ";
					cin >> mhs[i].responsi;
					cout << "   Masukkan nilai tugas : ";
					cin >> mhs[i].nilai_tugas;
					cout << "   Masukkan nilai UTS : ";
					cin >> mhs[i].nilai_uts;
					cout << "   Masukkan nilai UAS : ";
					cin>> mhs[i].nilai_uas;
					cout << endl;
	
					cin.ignore();
				
					hasil_responsi[i] = mhs[i].responsi * persentase.responsi / 100;
					hasil_tugas[i] = mhs[i].nilai_tugas * persentase.tugas / 100;
					hasil_uts[i] = mhs[i].nilai_uts * persentase.uts / 100;
					hasil_uas[i] = mhs[i].nilai_uas * persentase.uas / 100;
					hasil_akhir[i] = hasil_responsi[i] + hasil_tugas[i] + hasil_uts[i] + hasil_uas[i];
				}
				cout << "Apakah anda yakin dengan data yang sudah diinputkan?" << endl;
				cout << "(Y/N) : ";
				cin >> cek2;
				cout << endl;
			
				if (cek2 == 'Y')
				{
					cout << "Data mahasiswa berhasil ditambahkan! Tekan enter untuk melanjutkan" << endl;
					getch();
					system("cls");
					goto pilihan;
				}
				else if (cek2 == 'y')
				{
					cout << "Data mahasiswa berhasil ditambahkan! Tekan enter untuk melanjutkan" << endl;
					getch();
					system("cls");
					goto pilihan;
				}
				else
				{
					for (i = 0; i < jumlah; i++)			
					{
						nama[i] = "";
					}
					cout << "Data mahasiswa gagal ditambahkan! Tekan enter untuk kembali ke menu" << endl;
					getch();
					system("cls");
					goto pilihan;
				}			
			}			
			break;
		case 3:
			if (nama[0] == "")
			{
				cout << "Silahkan isi dengan lengkap pilihan kedua! Tekan enter untuk melanjutkan" << endl;
				getch();
				system("cls");
				goto pilihan;
			}
			else
			{
				for (i = 0; i < jumlah; i++)
				{
					cout << i+1 << ". Nama mata kuliah : " << matkul << endl;
					cout << "   Mahasiswa bernama " << nama[i]	<< " dengan NIM " << nim[i] << " nilai persentasi yang dihasilkan : " << endl;
					cout << "   Nilai responsi * " << (*ptr).responsi << "% = " << hasil_responsi[i] << endl;
					cout << "   Nilai tugas * " << (*ptr).tugas << "% = " << hasil_tugas[i] << endl;
					cout << "   Nilai UTS * " << (*ptr).uts << "% = " << hasil_uts[i] << endl;
					cout << "   Nilai UAS * " << (*ptr).uas << "% = " << hasil_uas[i] << endl;
					cout << "   Hasil akhir mahasiswa " << nama[i] << " memperoleh nilai = " << hasil_akhir[i] << endl;
				
				if (hasil_akhir[i] >= 80)
				{
					grade = 'A';
				}
				else if (hasil_akhir[i] >= 70)
				{
					grade = 'B';
				}
				else if (hasil_akhir[i] >= 60) 
				{
					grade = 'C';
				}
				else if (hasil_akhir[i] >= 50)
				{
					grade = 'D';
				}
				else
				{
					grade = 'E';
				}				
				cout << "   Grade nilai yang didapat = " << grade << endl;
				cout << endl;		
				}
			cout << "Data sudah ditampilkan! Tekan enter untuk kembali ke menu utama" << endl;
			getch();
			system("cls");
			goto pilihan;
			}			
			break;	
		case 4:
			if (nama[0] == "")
			{
				cout << "Silahkan isi dengan lengkap pilihan kedua! Tekan enter untuk melanjutkan" << endl;
				getch();
				system("cls");
				goto pilihan;
			}
			else
			{
				cout << "Masukkan nama mahasiswa yang dicari : ";
				cin >> cari;
			
				kiri = 0;
				kanan = jumlah - 1;
			
				while (kiri <= kanan)
				{
					tengah = (kiri+kanan)/2;
					if (cari == nama[tengah])
					{
						ketemu = true;
						break;
					}
					else if (cari < nama[tengah])
					{
						kanan = tengah - 1;
					}
					else
					{
						kiri = tengah + 1;
					}
				}
				for (i = 0; i < jumlah; i++)
				{
					if (cari == nama[i])
					{
						ketemu = true;
						break;
					}
				}
				cout << endl;
				
				if (ketemu)
				{
					cout << "Mahasiswa bernama " << cari << " ditemukan pada index ke-" << i << endl;
					cout << endl;
					cout << i+1 << ". Nama mata kuliah : " << matkul << endl;
					cout << "   Mahasiswa bernama " << nama[i]	<< " dengan NIM " << nim[i] << " nilai persentasi yang dihasilkan : " << endl;
					cout << "   Nilai responsi * " << (*ptr).responsi << "% = " << hasil_responsi[i] << endl;
					cout << "   Nilai tugas * " << (*ptr).tugas << "% = " << hasil_tugas[i] << endl;
					cout << "   Nilai UTS * " << (*ptr).uts << "% = " << hasil_uts[i] << endl;
					cout << "   Nilai UAS * " << (*ptr).uas << "% = " << hasil_uas[i] << endl;
					cout << "   Hasil akhir mahasiswa " << nama[i] << " memperoleh nilai = " << hasil_akhir[i] << endl;
					
					if (hasil_akhir[i] >= 80)
					{
						grade = 'A';
					}
					else if (hasil_akhir[i] >= 70)
					{
						grade = 'B';
					}
					else if (hasil_akhir[i] >= 60) 
					{
						grade = 'C';
					}
					else if (hasil_akhir[i] >= 50)
					{
						grade = 'D';
					}
					else
					{
						grade = 'E';
					}	
								
					cout << "   Grade nilai yang didapat = " << grade << endl;
					cout << endl;
					
					cout << "Data yang anda cari ketemu! tekan enter untuk kembali" << endl;
					ketemu = false;
					getch();
					system("cls");
					goto pilihan;
				}
				else
				{
					cout << "Nama mahasiswa tidak ditemukan!" << endl;
					getch();
					system("cls");
					goto pilihan;					
				}
			}	
			break;
		case 5:
			if (nama[0] == "")
			{
				cout << "Data belum terisi silahkan isi data sebelum menghapus! tekan enter untuk melanjutkan" << endl;
				getch();
				system("cls");
				goto pilihan;
			}
			else
			{
				for (i = 0; i < jumlah; i++)			
				{
					nama[i] = "";
				}
			
				(*ptr).responsi = 0;
				(*ptr).tugas = 0;
				(*ptr).uts = 0;
				(*ptr).uas = 0;
			
				cout << "Data 1, 2, 3, dan 4 sudah dihapus! Tekan enter untuk kembali" << endl;
				getch();
				system("cls");
				goto pilihan;
			}			
			break;
		case 6:
			cout << "Program Selesai" << endl;
			return 0;
		default:
			cout << "Pilihan yang anda masukkan tidak ada di menu! Tekan enter untuk melanjutkan" << endl;
			getch();
			system("cls");
			goto pilihan;		
	}
}
