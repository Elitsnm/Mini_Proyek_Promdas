#include <stdio.h>
#include <string.h>

int main() {
    // Deklarasi array 2 dimensi untuk menyimpan maksimal 100 judul buku (masing-masing hingga 100 karakter)
    char judul[100][100] = {
        "Holy Mother",
        "Dont Let Go",
        "Love In Chaos",
        "Your Mean Girl",
        "Maaf",
        "Ayesha",
        "Laut Bercerita",
        "Teluk Alaska",
        "Perempuan Di Titik Nol",
        "Cantik Itu Luka"
    };
// Array untuk menyimpan nama penulis buku, sesuai urutan judul
char penulis[100][100] = {
    "Akiyoshi Rikako",
    "Pipit Andriany",
    "Yenni Marissa",
    "Erlin Cahyadi",
    "Siksta Alia",
    "Uzma Jalaluddin",
    "Leila Shalika Chudori",
    "Eka Aryani",
    "Nawal El Saadawi",
    "Eka Kurniawan"
};
// Array untuk menyimpan tahun terbit buku
int tahun[100] = {
    2015, 2018, 2018, 2018, 2019,
    2019, 2017, 2019, 1975, 2002
};

int jumlah = 10; // Menyimpan jumlah buku yang sudah ada
int pilihan;     // Menyimpan input menu dari user
int i;           // Variabel umum
char cari[100];  // Variabel untuk menyimpan input pencarian judul

while (1) { 
    printf("\nMenu:\n");
    printf("1. Tambah Buku\n");
    printf("2. Lihat Semua Buku\n");
    printf("3. Cari Buku (berdasarkan judul)\n");
    printf("4. Hapus Buku\n");
    printf("0. Keluar\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilihan); // Menerima input menu dari user

    if (pilihan == 1) {  // Menu tambah buku
        if (jumlah < 100) {  // Mengecek apakah masih ada ruang untuk menambahkan buku
            printf("Masukkan judul buku : ");
            scanf("%s", judul[jumlah]); // Input judul buku

            printf("Masukkan penulis: ");
            scanf("%s", penulis[jumlah]); // Input penulis

            printf("Masukkan tahun terbit: ");
            scanf("%d", &tahun[jumlah]); // Input tahun terbit buku

            jumlah++; // Tambah jumlah buku
            printf("Buku berhasil ditambahkan!\n");
        } else {
            printf("Kapasitas penuh!\n"); // Jika sudah mencaoai kapasitas maksimum
        }
    } else if (pilihan == 2) { // Menu melihat semua buku
        if (jumlah == 0) {
            printf("Belum ada buku yang tersimpan.\n"); // Jika belum ada buku
        } else {
            for (i = 0; i < jumlah; i++) { // Menampilkan semua data buku
                printf("\nBuku ke-%d\n", i + 1);
                printf("Judul   :%s\n", judul[i]);
                printf("Penulis :%s\n", penulis[i]);
                printf("Tahun   :%d\n", tahun[i]);
            }
        }
    } else if (pilihan == 3) { // Menu cari buku berdasarkan judul
        printf("Masukkan judul buku yang dicari:  ");
        scanf("%s", cari); // Input judul yang akan dicari
        int ketemu = 0; // Untuk mendai apakah buku ditemukan atau tidak
        
        for (i = 0; i < jumlah; i++) {
            if (strcmp(judul[i], cari) == 0) { // Membandingkan string input dengan daftar judul
                printf("\nBuku ditemukan!\n");
                printf("Judul   :%s\n", judul[i]);
                printf("Penulis :%s\n", penulis[i]);
                printf("Tahun   :%d\n", tahun[i]);
                ketemu = 1;
            }
        }

        if (ketemu == 0) {
            printf("Buku tidak ditemukan.\n"); // Jika tidak ditemukan
        }
    } else if (pilihan == 4) { // Menu hapus buku
        printf("Masukkan nomor buku yang ingin dihapus (1 - %d): ", jumlah);
        int hapus;
        scanf("%d", &hapus); // Input nomor buku yang akan dihapus

        if (hapus >= 1 && hapus <= jumlah) {
            for (i = hapus - 1; i < jumlah - 1; i++) {
                for (int j = 0; j < 100; j++) {
                    judul[i][j] = judul[i + 1][j];
                    penulis[i][j] = penulis[i + 1][j];
                }
                tahun[i] = tahun[i + 1];
            }
            jumlah--; // Kurangi jumlah buku
            printf("Buku berhasil dihapus.\n");
        } else {
            printf("Nomor tidak valid.\n"); // Jika nomor tidak sesuai
        }
    } else if (pilihan == 0) { // Keluar dari program
        printf("Terima kasih! Program selesai.\n");
        break; // Keluar dari loop utama
    } else {
        printf("Pilihan tidak valid. Silahkan coba lagi.\n");
    }

}

return 0;
}