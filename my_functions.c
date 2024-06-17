#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PASIEN 100

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

// Baca Data Pasien
    Data_Pasien* readDataPasien(const char *filename, int *count) {
        FILE* file = fopen(filename, "r");
        if (!file) {
            printf("Error opening file %s\n", filename);
            return NULL;
        }
        Data_Pasien* dataPasien = (Data_Pasien*)malloc(sizeof(Data_Pasien) * MAX_PASIEN);
        *count = 0;
        char line[1024];
        fgets(line, 1024, file); // skip header
        while (fgets(line, 1024, file)) {
            char* token = strtok(line, ";");
            Data_Pasien pasien;
            if (token) pasien.No = atoi(token);
            token = strtok(NULL, ";");
            if (token) strncpy(pasien.Nama_Lengkap, token, sizeof(pasien.Nama_Lengkap) - 1);
            token = strtok(NULL, ";");
            if (token) strncpy(pasien.Alamat, token, sizeof(pasien.Alamat) - 1);
            token = strtok(NULL, ";");
            if (token) strncpy(pasien.Kota, token, sizeof(pasien.Kota) - 1);
            token = strtok(NULL, ";");
            if (token) strncpy(pasien.Tempat_Lahir, token, sizeof(pasien.Tempat_Lahir) - 1);
            token = strtok(NULL, ";");
            if (token) strncpy(pasien.Tanggal_Lahir, token, sizeof(pasien.Tanggal_Lahir) - 1);
            token = strtok(NULL, ";");
            if (token) pasien.Umur = atoi(token);
            token = strtok(NULL, ";");
            if (token) pasien.No_BPJS = atoll(token);
            token = strtok(NULL, "\n");
            if (token) strncpy(pasien.ID_Pasien, token, sizeof(pasien.ID_Pasien) - 1);
            // Ensure null-termination
            pasien.Nama_Lengkap[sizeof(pasien.Nama_Lengkap) - 1] = '\0';
            pasien.Alamat[sizeof(pasien.Alamat) - 1] = '\0';
            pasien.Kota[sizeof(pasien.Kota) - 1] = '\0';
            pasien.Tempat_Lahir[sizeof(pasien.Tempat_Lahir) - 1] = '\0';
            pasien.Tanggal_Lahir[sizeof(pasien.Tanggal_Lahir) - 1] = '\0';
            pasien.ID_Pasien[sizeof(pasien.ID_Pasien) - 1] = '\0';
            dataPasien[(*count)++] = pasien;
        }
        fclose(file);
        return dataPasien;
    }

// Baca Riwayat Medis Pasien
    Riwayat_Medis_Pasien* readRiwayatMedis(const char* filename, int* count) {
        FILE* file = fopen(filename, "r");
        if (!file) {
            printf("Error opening file %s\n", filename);
            return NULL;
        }
        Riwayat_Medis_Pasien* riwayatMedis = (Riwayat_Medis_Pasien*)malloc(sizeof(Riwayat_Medis_Pasien) * MAX_PASIEN);
        *count = 0;
        char line[1024];
        fgets(line, 1024, file); // skip header
        while (fgets(line, 1024, file)) {
            char* token = strtok(line, ";");
            Riwayat_Medis_Pasien riwayat;
            riwayat.No = atoi(token);
            token = strtok(NULL, ";");
            strcpy(riwayat.Tanggal, token);
            token = strtok(NULL, ";");
            strcpy(riwayat.ID_Pasien, token);
            token = strtok(NULL, ";");
            strcpy(riwayat.Diagnosis, token);
            token = strtok(NULL, ";");
            strcpy(riwayat.Tindakan, token);
            token = strtok(NULL, ";");
            strcpy(riwayat.Kontrol, token);
            token = strtok(NULL, "\n");
            riwayat.Biaya = atof(token);
            riwayatMedis[(*count)++] = riwayat;
        }
        fclose(file);
        return riwayatMedis;
    }

// Tambah Data Pasien
    char* tambahDataPasien(char* name, char* address, char* city, char* birthplace, char* birthdate, int age, long long bpjs, char* id, Data_Pasien* data, int* count) {
        if (*count < MAX_PASIEN) {
            data[*count].No = *count + 1;
            strncpy(data[*count].Nama_Lengkap, name, sizeof(data[*count].Nama_Lengkap) - 1);
            data[*count].Nama_Lengkap[sizeof(data[*count].Nama_Lengkap) - 1] = '\0';
            strncpy(data[*count].Alamat, address, sizeof(data[*count].Alamat) - 1);
            data[*count].Alamat[sizeof(data[*count].Alamat) - 1] = '\0';
            strncpy(data[*count].Kota, city, sizeof(data[*count].Kota) - 1);
            data[*count].Kota[sizeof(data[*count].Kota) - 1] = '\0';
            strncpy(data[*count].Tempat_Lahir, birthplace, sizeof(data[*count].Tempat_Lahir) - 1);
            data[*count].Tempat_Lahir[sizeof(data[*count].Tempat_Lahir) - 1] = '\0';
            strncpy(data[*count].Tanggal_Lahir, birthdate, sizeof(data[*count].Tanggal_Lahir) - 1);
            data[*count].Tanggal_Lahir[sizeof(data[*count].Tanggal_Lahir) - 1] = '\0';
            data[*count].Umur = age;
            data[*count].No_BPJS = bpjs;
            strncpy(data[*count].ID_Pasien, id, sizeof(data[*count].ID_Pasien) - 1);
            data[*count].ID_Pasien[sizeof(data[*count].ID_Pasien) - 1] = '\0';
            (*count)++;
            return strdup("Data berhasil ditambahkan!\n");
        } else {
            return strdup("The array is full!\n");
        }
    }

// Ubah Data Pasien
    char* ubahDataPasien(int num, char* name, char* address, char* city, char* birthplace, char* birthdate, int age, long long bpjs, char* id, Data_Pasien* data, int count) {
        for (int i = 0; i < count; i++) {
            if (data[i].No == num) {
                strncpy(data[i].Nama_Lengkap, name, sizeof(data[i].Nama_Lengkap) - 1);
                data[i].Nama_Lengkap[sizeof(data[i].Nama_Lengkap) - 1] = '\0';
                strncpy(data[i].Alamat, address, sizeof(data[i].Alamat) - 1);
                data[i].Alamat[sizeof(data[i].Alamat) - 1] = '\0';
                strncpy(data[i].Kota, city, sizeof(data[i].Kota) - 1);
                data[i].Kota[sizeof(data[i].Kota) - 1] = '\0';
                strncpy(data[i].Tempat_Lahir, birthplace, sizeof(data[i].Tempat_Lahir) - 1);
                data[i].Tempat_Lahir[sizeof(data[i].Tempat_Lahir) - 1] = '\0';
                strncpy(data[i].Tanggal_Lahir, birthdate, sizeof(data[i].Tanggal_Lahir) - 1);
                data[i].Tanggal_Lahir[sizeof(data[i].Tanggal_Lahir) - 1] = '\0';
                data[i].Umur = age;
                data[i].No_BPJS = bpjs;
                strncpy(data[i].ID_Pasien, id, sizeof(data[i].ID_Pasien) - 1);
                data[i].ID_Pasien[sizeof(data[i].ID_Pasien) - 1] = '\0';
                break;
                return strdup("Data berhasil diubah!\n");
            }
        }
        return strdup("Nomor yang dimasukkan tidak valid!\n");
    }

// Cari Data Pasien
    char* cariDataPasien(char name[], Data_Pasien *data_pasien, int *count) {
        Data_Pasien *foundPasien = NULL;
        for (int i = 0; i < *count; i++) {
            if (strcmp(data_pasien[i].Nama_Lengkap, name) == 0) {
                foundPasien = &data_pasien[i];
                break;
            }
        }
        if (foundPasien) {
            char buffer[1024];
            sprintf(buffer, "Data pasien ditemukan!\nNo.: %d\nNama Lengkap: %s\nAlamat: %s\nKota: %s\nTempat Lahir: %s\nTanggal Lahir: %s\nUmur: %d\nNo. BPJS: %lld\nID Pasien: %s\n", 
                    foundPasien->No, foundPasien->Nama_Lengkap, foundPasien->Alamat, 
                    foundPasien->Kota, foundPasien->Tempat_Lahir, foundPasien->Tanggal_Lahir, 
                    foundPasien->Umur, foundPasien->No_BPJS, 
                    foundPasien->ID_Pasien);
            return strdup(buffer);
        } else {
            return strdup("Data pasien tidak ditemukan!\n");
        }
    }

// Hapus Data Pasien
    char* hapusDataPasien(char *name, Data_Pasien* dataPasien, int *count) {
        for (int i = 0; i < *count; i++) {
            if (strcmp(name, dataPasien[i].Nama_Lengkap) == 0) {
                // Shift elements to the left
                for (int j = i; j < *count - 1; j++) {
                    dataPasien[j] = dataPasien[j + 1];
                    dataPasien[j].No -= 1;
                }
                (*count)--;
                char buffer[1024];
                sprintf(buffer, "Data pasien dengan nama %s telah dihapus.", name);
                return strdup(buffer);
            }
        }
        return strdup("Data pasien tidak ditemukan\n");
    }

// Tambah Riwayat Medis Pasien
    char* tambahRiwayatMedisPasien(char *date, char *id, char *diagnosis, char *action, char *control, double bill, Riwayat_Medis_Pasien *riwayatMedis, int *count) {
        if (*count < MAX_PASIEN) {
            riwayatMedis[*count].No = *count + 1;
            strncpy(riwayatMedis[*count].Tanggal, date, sizeof(riwayatMedis[*count].Tanggal) - 1);
            riwayatMedis[*count].Tanggal[sizeof(riwayatMedis[*count].Tanggal) - 1] = '\0';
            strncpy(riwayatMedis[*count].ID_Pasien, id, sizeof(riwayatMedis[*count].ID_Pasien) - 1);
            riwayatMedis[*count].ID_Pasien[sizeof(riwayatMedis[*count].ID_Pasien) - 1] = '\0';
            strncpy(riwayatMedis[*count].Diagnosis, diagnosis, sizeof(riwayatMedis[*count].Diagnosis) - 1);
            riwayatMedis[*count].Diagnosis[sizeof(riwayatMedis[*count].Diagnosis) - 1] = '\0';
            strncpy(riwayatMedis[*count].Tindakan, action, sizeof(riwayatMedis[*count].Tindakan) - 1);
            riwayatMedis[*count].Tindakan[sizeof(riwayatMedis[*count].Tindakan) - 1] = '\0';
            strncpy(riwayatMedis[*count].Kontrol, control, sizeof(riwayatMedis[*count].Kontrol) - 1);
            riwayatMedis[*count].Kontrol[sizeof(riwayatMedis[*count].Kontrol) - 1] = '\0';
            riwayatMedis[*count].Biaya = bill;
            (*count)++;
            return strdup("Riwayat medis pasien berhasil ditambahkan!\n");
        } else {
            return strdup("Riwayat medis pasien penuh!\n");
        }
    }

// Ubah Riwayat Medis Pasien
    char* ubahRiwayatMedisPasien(int num, char *date, char *id, char *diagnosis, char *action, char *control, double bill, Riwayat_Medis_Pasien* riwayatMedis, int count) {
        // Check if the given record number is valid
        if (num <= 0 || num > count) {
            char* error = (char*)malloc(50);
            strcpy(error, "Nomor riwayat medis tidak valid!\n");
            return error;
        }
        // Create a temporary record with the provided data
        Riwayat_Medis_Pasien perubahan;
        perubahan.No = num;
        // Copy the provided data into the temporary record
        strncpy(perubahan.Tanggal, date, sizeof(perubahan.Tanggal) - 1);
        perubahan.Tanggal[sizeof(perubahan.Tanggal) - 1] = '\0';
        strncpy(perubahan.ID_Pasien, id, sizeof(perubahan.ID_Pasien) - 1);
        perubahan.ID_Pasien[sizeof(perubahan.ID_Pasien) - 1] = '\0';
        strncpy(perubahan.Diagnosis, diagnosis, sizeof(perubahan.Diagnosis) - 1);
        perubahan.Diagnosis[sizeof(perubahan.Diagnosis) - 1] = '\0';
        strncpy(perubahan.Tindakan, action, sizeof(perubahan.Tindakan) - 1);
        perubahan.Tindakan[sizeof(perubahan.Tindakan) - 1] = '\0';
        strncpy(perubahan.Kontrol, control, sizeof(perubahan.Kontrol) - 1);
        perubahan.Kontrol[sizeof(perubahan.Kontrol) - 1] = '\0';
        perubahan.Biaya = bill;
        // Update the record in the array
        riwayatMedis[num - 1] = perubahan;
        // Allocate memory for the success message
        char* success = (char*)malloc(100);
        snprintf(success, 100, "Riwayat medis pada nomor ke-%d telah berhasil diubah!\n", num);
        return success;
    }

// Cari Riwayat Medis Pasien
    char* cariRiwayatMedisPasien(char *date , Riwayat_Medis_Pasien *riwayat_medis_pasien, int *count) {
        Riwayat_Medis_Pasien *foundRiwayat = NULL;
        for (int i = 0; i < *count; i++) {
            if (strcmp(riwayat_medis_pasien[i].Tanggal, date) == 0) {
                foundRiwayat = &riwayat_medis_pasien[i];
                break;
            }
        }
        if (foundRiwayat) {
            char buffer[1024];
            sprintf(buffer, "Riwayat medis pasien ditemukan!\nNo: %d\nTanggal: %s\nID Pasien: %s\nDiagnosis: %s\nTindakan: %s\nKontrol: %s\nBiaya: %.2lf\n", 
                    foundRiwayat->No, foundRiwayat->Tanggal, foundRiwayat->ID_Pasien, 
                    foundRiwayat->Diagnosis, foundRiwayat->Tindakan, foundRiwayat->Kontrol, 
                    foundRiwayat->Biaya);
            return strdup(buffer);
        } else {
            return strdup("Riwayat medis pasien tidak ditemukan!\n");
        }
    }

// Hapus Riwayat Medis Pasien
    char* hapusRiwayatMedisPasien(char *date, Riwayat_Medis_Pasien *riwayat_medis_pasien, int *count) {
        for (int i = 0; i < *count; i++) {
            if (strcmp(date, riwayat_medis_pasien[i].Tanggal) == 0) {
                char date_deleted[50] = "";
                strcpy(date_deleted, riwayat_medis_pasien[i].Tanggal);
                // Shift elements to the left
                for (int j = i; j < *count - 1; j++) {
                    riwayat_medis_pasien[j] = riwayat_medis_pasien[j + 1];
                    riwayat_medis_pasien[j].No -= 1;
                }
                (*count)--;
                char buffer[1024];
                sprintf(buffer, "Riwayat medis pasien tanggal %s telah dihapus.", date);
                return strdup(buffer);
            }
        }
        return strdup("Riwayat medis pasien tidak ditemukan\n");
    }

// Laporan Keuangan
    char* laporanKeuangan(Riwayat_Medis_Pasien* riwayatMedisPasien, int sizeRiwayatMedis) {
        // Struktur untuk menyimpan pendapatan per bulan dan per tahun
        typedef struct {
            int tahun;
            double pendapatanBulanan[12];
            int jumlahDataBulanan[12];
        } PendapatanTahunan;        
        PendapatanTahunan* pendapatan = NULL;
        int jumlahTahun = 0;
        for (int i = 0; i < sizeRiwayatMedis; i++) {
            char tanggal[20];
            strcpy(tanggal, riwayatMedisPasien[i].Tanggal);
            char* token = strtok(tanggal, " ");
            int hari = atoi(token);
            token = strtok(NULL, " ");
            char* namaBulan = token;
            token = strtok(NULL, " ");
            int tahun = atoi(token);
            int bulan = 0;
            if (strcmp(namaBulan, "Januari") == 0) bulan = 0;
            else if (strcmp(namaBulan, "Februari") == 0) bulan = 1;
            else if (strcmp(namaBulan, "Maret") == 0) bulan = 2;
            else if (strcmp(namaBulan, "April") == 0) bulan = 3;
            else if (strcmp(namaBulan, "Mei") == 0) bulan = 4;
            else if (strcmp(namaBulan, "Juni") == 0) bulan = 5;
            else if (strcmp(namaBulan, "Juli") == 0) bulan = 6;
            else if (strcmp(namaBulan, "Agustus") == 0) bulan = 7;
            else if (strcmp(namaBulan, "September") == 0) bulan = 8;
            else if (strcmp(namaBulan, "Oktober") == 0) bulan = 9;
            else if (strcmp(namaBulan, "November") == 0) bulan = 10;
            else if (strcmp(namaBulan, "Desember") == 0) bulan = 11;
            // Cari apakah tahun sudah ada dalam array
            int tahunDitemukan = -1;
            for (int j = 0; j < jumlahTahun; j++) {
                if (pendapatan[j].tahun == tahun) {
                    tahunDitemukan = j;
                    break;
                }
            }
            // Jika tahun belum ada, tambahkan tahun baru ke array
            if (tahunDitemukan == -1) {
                jumlahTahun++;
                pendapatan = (PendapatanTahunan*)realloc(pendapatan, jumlahTahun * sizeof(PendapatanTahunan));
                pendapatan[jumlahTahun - 1].tahun = tahun;
                memset(pendapatan[jumlahTahun - 1].pendapatanBulanan, 0, 12 * sizeof(double));
                memset(pendapatan[jumlahTahun - 1].jumlahDataBulanan, 0, 12 * sizeof(int));
                tahunDitemukan = jumlahTahun - 1;
            }
            // Tambahkan biaya ke pendapatan bulanan dan tahunan
            pendapatan[tahunDitemukan].pendapatanBulanan[bulan] += riwayatMedisPasien[i].Biaya;
            pendapatan[tahunDitemukan].jumlahDataBulanan[bulan]++;
        }
        // Instead of printing, we'll write to a dynamically allocated string
        char* report = malloc(10000 * sizeof(char)); // Allocate a large buffer. Adjust size as needed.
        char buffer[1000]; // Temporary buffer for sprintf
        report[0] = '\0'; // Initialize as an empty string
        char* monthNames[] = {"Januari", "Februari", "Maret", "April", "Mei", "Juni", "Juli", "Agustus", "September", "Oktober", "November", "Desember"};
        // Generate report string
        for (int i = 0; i < jumlahTahun; i++) {
            double totalPendapatanTahunan = 0;
            int totalDataTahunan = 0;        
            sprintf(buffer, "Tahun %d:\n", pendapatan[i].tahun);
            strcat(report, buffer);        
            for (int j = 0; j < 12; j++) {
                double rataRataBulanan = 0;
                if (pendapatan[i].jumlahDataBulanan[j] > 0) {
                    rataRataBulanan = pendapatan[i].pendapatanBulanan[j] / pendapatan[i].jumlahDataBulanan[j];
                }
                sprintf(buffer, "  Bulan %s: Total = %.2f, Rata-rata = %.2f\n", 
                        monthNames[j], pendapatan[i].pendapatanBulanan[j], rataRataBulanan);
                strcat(report, buffer);            
                totalPendapatanTahunan += pendapatan[i].pendapatanBulanan[j];
                totalDataTahunan += pendapatan[i].jumlahDataBulanan[j];
            }        
            double rataRataTahunan = 0;
            if (totalDataTahunan > 0) {
                rataRataTahunan = totalPendapatanTahunan / totalDataTahunan;
            }        
            sprintf(buffer, "  Total Pendapatan Tahunan: %.2f\n  Rata-rata Pendapatan Tahunan: %.2f\n\n", 
                    totalPendapatanTahunan, rataRataTahunan);
            strcat(report, buffer);
        }
        free(pendapatan);
        return report;
    }

// Analisis Pasien dan Penyakit
    char* analisisPasienPenyakit(Riwayat_Medis_Pasien* riwayatMedisPasien, int sizeRiwayatMedis) {
        // Struktur untuk analisa jenis penyakit per bulan dan per tahun
        typedef struct {
            int tahun;
            char** jenispenyakit;
            int** banyakpenyakitbulanan;
            int penyakitCount;
        } analisapenyakit;
        analisapenyakit* datapenyakit = NULL;
        int jumlahTahun = 0;
        for (int i = 0; i < sizeRiwayatMedis; i++) {
            char tanggal[20];
            strcpy(tanggal, riwayatMedisPasien[i].Tanggal);
            char* token = strtok(tanggal, " ");
            int hari = atoi(token);
            token = strtok(NULL, " ");
            char* namaBulan = token;
            token = strtok(NULL, " ");
            int tahun = atoi(token);
            int bulan = 0;
            if (strcmp(namaBulan, "Januari") == 0) bulan = 0;
            else if (strcmp(namaBulan, "Februari") == 0) bulan = 1;
            else if (strcmp(namaBulan, "Maret") == 0) bulan = 2;
            else if (strcmp(namaBulan, "April") == 0) bulan = 3;
            else if (strcmp(namaBulan, "Mei") == 0) bulan = 4;
            else if (strcmp(namaBulan, "Juni") == 0) bulan = 5;
            else if (strcmp(namaBulan, "Juli") == 0) bulan = 6;
            else if (strcmp(namaBulan, "Agustus") == 0) bulan = 7;
            else if (strcmp(namaBulan, "September") == 0) bulan = 8;
            else if (strcmp(namaBulan, "Oktober") == 0) bulan = 9;
            else if (strcmp(namaBulan, "November") == 0) bulan = 10;
            else if (strcmp(namaBulan, "Desember") == 0) bulan = 11;
            // Cari apakah tahun sudah ada dalam array
            int tahunDitemukan = -1;
            for (int j = 0; j < jumlahTahun; j++) {
                if (datapenyakit[j].tahun == tahun) {
                    tahunDitemukan = j;
                    break;
                }
            }
            // Jika tahun belum ada, tambahkan tahun baru ke array
            if (tahunDitemukan == -1) {
                jumlahTahun++;
                datapenyakit = (analisapenyakit*)realloc(datapenyakit, jumlahTahun * sizeof(analisapenyakit));
                datapenyakit[jumlahTahun - 1].tahun = tahun;
                datapenyakit[jumlahTahun - 1].jenispenyakit = NULL;
                datapenyakit[jumlahTahun - 1].banyakpenyakitbulanan = NULL;
                datapenyakit[jumlahTahun - 1].penyakitCount = 0;
                tahunDitemukan = jumlahTahun - 1;
            }
            // Cari apakah jenis penyakit sudah ada dalam array
            int penyakitIndex = -1;
            for (int j = 0; j < datapenyakit[tahunDitemukan].penyakitCount; j++) {
                if (strcmp(datapenyakit[tahunDitemukan].jenispenyakit[j], riwayatMedisPasien[i].Diagnosis) == 0) {
                    penyakitIndex = j;
                    break;
                }
            }
            // Jika jenis penyakit belum ada, tambahkan jenis penyakit baru ke array
            if (penyakitIndex == -1) {
                datapenyakit[tahunDitemukan].penyakitCount++;
                int newCount = datapenyakit[tahunDitemukan].penyakitCount;
                datapenyakit[tahunDitemukan].jenispenyakit = (char**)realloc(datapenyakit[tahunDitemukan].jenispenyakit, newCount * sizeof(char*));
                datapenyakit[tahunDitemukan].jenispenyakit[newCount - 1] = strdup(riwayatMedisPasien[i].Diagnosis);
                datapenyakit[tahunDitemukan].banyakpenyakitbulanan = (int**)realloc(datapenyakit[tahunDitemukan].banyakpenyakitbulanan, newCount * sizeof(int*));
                datapenyakit[tahunDitemukan].banyakpenyakitbulanan[newCount - 1] = (int*)calloc(12, sizeof(int));
                penyakitIndex = newCount - 1;
            }
            datapenyakit[tahunDitemukan].banyakpenyakitbulanan[penyakitIndex][bulan]++;
        }
        // Allocate initial memory for the result string
        size_t resultSize = 1024;
        char* result = (char*)malloc(resultSize);
        result[0] = '\0';  // Initialize the string as empty
        // Hitung dan simpan setiap jenis penyakit per bulan dan per tahun
        char buffer[256];
        for (int i = 0; i < jumlahTahun; i++) {
            snprintf(buffer, sizeof(buffer), "Tahun: %d           Bulan: 1  2  3  4  5  6  7  8  9  10  11  12  total\n", datapenyakit[i].tahun);
            size_t newLength = strlen(result) + strlen(buffer) + 1;
            if (newLength > resultSize) {
                resultSize *= 2;
                result = (char*)realloc(result, resultSize);
            }
            strcat(result, buffer);
            for (int j = 0; j < datapenyakit[i].penyakitCount; j++) {
                snprintf(buffer, sizeof(buffer), "  Penyakit: %s\n", datapenyakit[i].jenispenyakit[j]);
                newLength = strlen(result) + strlen(buffer) + 1;
                if (newLength > resultSize) {
                    resultSize *= 2;
                    result = (char*)realloc(result, resultSize);
                }
                strcat(result, buffer);
                snprintf(buffer, sizeof(buffer), "    Banyak penyakit bulanan: ");
                newLength = strlen(result) + strlen(buffer) + 1;
                if (newLength > resultSize) {
                    resultSize *= 2;
                    result = (char*)realloc(result, resultSize);
                }
                strcat(result, buffer);
                int total = 0;
                for (int k = 0; k < 12; k++) {
                    snprintf(buffer, sizeof(buffer), "%2d  ", datapenyakit[i].banyakpenyakitbulanan[j][k]);
                    newLength = strlen(result) + strlen(buffer) + 1;
                    if (newLength > resultSize) {
                        resultSize *= 2;
                        result = (char*)realloc(result, resultSize);
                    }
                    strcat(result, buffer);
                    total += datapenyakit[i].banyakpenyakitbulanan[j][k];
                }
                snprintf(buffer, sizeof(buffer), "%3d\n", total);
                newLength = strlen(result) + strlen(buffer) + 1;
                if (newLength > resultSize) {
                    resultSize *= 2;
                    result = (char*)realloc(result, resultSize);
                }
                strcat(result, buffer);
            }
            strcat(result, "\n");
        }
        // Bersihkan memori
        for (int i = 0; i < jumlahTahun; i++) {
            for (int j = 0; j < datapenyakit[i].penyakitCount; j++) {
                free(datapenyakit[i].jenispenyakit[j]);
                free(datapenyakit[i].banyakpenyakitbulanan[j]);
            }
            free(datapenyakit[i].jenispenyakit);
            free(datapenyakit[i].banyakpenyakitbulanan);
        }
        free(datapenyakit);
        return result;
    }

// Informasi Kontrol Pasien
    char* informasiKontrolPasien(Riwayat_Medis_Pasien* riwayatMedisPasien, int sizeRiwayatMedis, const char* tanggalDicari) {
        int hari, bulan, tahun;
        // Parse the input date
        if (sscanf(tanggalDicari, "%d %d %d", &hari, &bulan, &tahun) != 3) {
            char* error = (char*)malloc(100);
            strcpy(error, "Format tanggal salah. Harap masukkan dengan format dd mm yyyy.\n");
            return error;
        }
        char bulanStr[12][10] = {
            "Januari", "Februari", "Maret", "April", "Mei", "Juni",
            "Juli", "Agustus", "September", "Oktober", "November", "Desember"
        };
        if (bulan < 1 || bulan > 12) {
            char* error = (char*)malloc(50);
            strcpy(error, "Bulan yang dimasukkan tidak valid.\n");
            return error;
        }
        char tanggalDicariFormatted[20];
        sprintf(tanggalDicariFormatted, "%d %s %d", hari, bulanStr[bulan - 1], tahun);
        int ditemukan = 0;
        // Allocate initial memory for the result string
        size_t resultSize = 1024;
        char* result = (char*)malloc(resultSize);
        result[0] = '\0';  // Initialize the string as empty
        for (int i = 0; i < sizeRiwayatMedis; i++) {
            if (strcmp(riwayatMedisPasien[i].Tanggal, tanggalDicariFormatted) == 0) {
                if (!ditemukan) {
                    snprintf(result + strlen(result), resultSize - strlen(result), "Kontrol pada tanggal %s:\n", tanggalDicariFormatted);
                    ditemukan = 1;
                }
                char buffer[256];
                snprintf(buffer, sizeof(buffer), "No: %d\nID Pasien: %s\nDiagnosis: %s\nTindakan: %s\nKontrol: %s\nBiaya: %.2f\n\n",
                        riwayatMedisPasien[i].No, riwayatMedisPasien[i].ID_Pasien, riwayatMedisPasien[i].Diagnosis,
                        riwayatMedisPasien[i].Tindakan, riwayatMedisPasien[i].Kontrol, riwayatMedisPasien[i].Biaya);                        
                size_t newLength = strlen(result) + strlen(buffer) + 1;
                if (newLength > resultSize) {
                    resultSize *= 2;
                    result = (char*)realloc(result, resultSize);
                }
                strcat(result, buffer);
            }
        }
        if (!ditemukan) {
            snprintf(result + strlen(result), resultSize - strlen(result), "Tidak ada data kontrol pada tanggal %s\n", tanggalDicariFormatted);
        }
        return result;
    }

// Informasi Kontrol Pasien (New)
    char* informasiKontrolPasienNew(char *date , Riwayat_Medis_Pasien *riwayat_medis_pasien, int *count) {
        Riwayat_Medis_Pasien *foundRiwayat = NULL;
        for (int i = 0; i < *count; i++) {
            if (strcmp(riwayat_medis_pasien[i].Kontrol, date) == 0) {
                foundRiwayat = &riwayat_medis_pasien[i];
                break;
            }
        }
        if (foundRiwayat) {
            char buffer[1024];
            sprintf(buffer, "Jadwal kontrol pasien ditemukan!\nNo: %d\nTanggal: %s\nID Pasien: %s\nDiagnosis: %s\nTindakan: %s\nKontrol: %s\nBiaya: %.2lf\n", 
                    foundRiwayat->No, foundRiwayat->Tanggal, foundRiwayat->ID_Pasien, 
                    foundRiwayat->Diagnosis, foundRiwayat->Tindakan, foundRiwayat->Kontrol, 
                    foundRiwayat->Biaya);
            return strdup(buffer);
        } else {
            char buffer[1024];
            sprintf(buffer, "Tidak ada kontrol pada tanggal %s!\n", date);
            return strdup(buffer);
        }
    }

// Tulis Data Pasien
    void tulisDataPasien(const char* filename, Data_Pasien* dataPasien, int count) {
        FILE* file = fopen(filename, "w");
        if (!file) {
            printf("Error opening file %s\n", filename);
            return;
        }
        // Tulis header
        fprintf(file, "No;Nama Lengkap;Alamat;Kota;Tempat Lahir;Tanggal Lahir;Umur (th);No BPJS;ID Pasien\n");
        // Tulis setiap data pasien
        for (int i = 0; i < count; i++) {
            fprintf(file, "%d;%s;%s;%s;%s;%s;%d;%lld;%s\n",
                    dataPasien[i].No,
                    dataPasien[i].Nama_Lengkap,
                    dataPasien[i].Alamat,
                    dataPasien[i].Kota,
                    dataPasien[i].Tempat_Lahir,
                    dataPasien[i].Tanggal_Lahir,
                    dataPasien[i].Umur,
                    dataPasien[i].No_BPJS,
                    dataPasien[i].ID_Pasien);
        }
        fclose(file);
    }

// Tulis Riwayat Medis Pasien
    void tulisRiwayatMedisPasien(const char* filename, Riwayat_Medis_Pasien* riwayatMedisPasien, int count) {
        FILE* file = fopen(filename, "w");
        if (!file) {
            printf("Error opening file %s\n", filename);
            return;
        }
        // Tulis header
        fprintf(file, "No;Tanggal;ID Pasien;Diagnosis;Tindakan;Kontrol;Biaya (Rp)\n");
        // Tulis setiap data pasien
        for (int i = 0; i < count; i++) {
            fprintf(file, "%d;%s;%s;%s;%s;%s;%.2lf\n",
                    riwayatMedisPasien[i].No,
                    riwayatMedisPasien[i].Tanggal,
                    riwayatMedisPasien[i].ID_Pasien,
                    riwayatMedisPasien[i].Diagnosis,
                    riwayatMedisPasien[i].Tindakan,
                    riwayatMedisPasien[i].Kontrol,
                    riwayatMedisPasien[i].Biaya);
        }
        fclose(file);
    }