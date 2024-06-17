#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

typedef struct {
    int No;
    char Nama_Lengkap[50];
    char Alamat[100];
    char Kota[50];
    char Tempat_Lahir[50];
    char Tanggal_Lahir[30];
    int Umur;
    long long No_BPJS;
    char ID_Pasien[20];
} Data_Pasien;

typedef struct {
    int No;
    char Tanggal[20];
    char ID_Pasien[20];
    char Diagnosis[50];
    char Tindakan[50];
    char Kontrol[20];
    double Biaya;
} Riwayat_Medis_Pasien;

Data_Pasien *readDataPasien(const char* filename, int* count);
Riwayat_Medis_Pasien* readRiwayatMedis(const char* filename, int* count);
char* tambahDataPasien(char* name, char* address, char* city, char* birthplace, char* birthdate, int age, long long bpjs, char* id, Data_Pasien* data, int* count);
char* ubahDataPasien(int num, char* name, char* address, char* city, char* birthplace, char* birthdate, int age, long long bpjs, char* id, Data_Pasien* data, int count);
char* cariDataPasien(char name[], Data_Pasien *data_pasien, int *count);
char* hapusDataPasien(char *name, Data_Pasien* dataPasien, int *count);
char* tambahRiwayatMedisPasien(char *date, char *id, char *diagnosis, char *action, char *control, double bill, Riwayat_Medis_Pasien *riwayatMedis, int *count);
char* ubahRiwayatMedisPasien(int num, char *date, char *id, char *diagnosis, char *action, char *control, double bill, Riwayat_Medis_Pasien* riwayatMedis, int count);
char* hapusRiwayatMedisPasien(char *date, Riwayat_Medis_Pasien *riwayat_medis_pasien, int *count);
char* cariRiwayatMedisPasien(char *date , Riwayat_Medis_Pasien *riwayat_medis_pasien, int *count);
char* laporanKeuangan(Riwayat_Medis_Pasien* riwayatMedisPasien, int sizeRiwayatMedis);
char* analisisPasienPenyakit(Riwayat_Medis_Pasien* riwayatMedisPasien, int sizeRiwayatMedis);
char* informasiKontrolPasien(Riwayat_Medis_Pasien* riwayatMedisPasien, int sizeRiwayatMedis, const char* tanggalDicari);
char* informasiKontrolPasienNew(char *date , Riwayat_Medis_Pasien *riwayat_medis_pasien, int *count);
void tulisDataPasien(const char* filename, Data_Pasien* dataPasien, int count);
void tulisRiwayatMedisPasien(const char* fileName, Riwayat_Medis_Pasien* riwayatMedisPasien, int count);

#endif