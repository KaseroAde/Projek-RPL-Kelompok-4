#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 5
struct anggota
{
    char nama[20];
    char email[20];
    char ttl[20];
    char username[20];
    char password[20];
    struct anggota *next;
};
struct anggota *data;
struct anggota *tampung;
int harga_barang, ongkos, total_tagihan, jumlah;
harga_barang=0, ongkos=0, total_tagihan=0;
char  ukuran[10];
struct barang
{
    char kode_barang[20];
    char nama_barang[30];
    int harga;
    char size[10];
};
struct barang brg[20]=
{
  "tp001","sixpax hat",111000,"S, L, XL",
  "tp002","wrng hat",101000,"S, L, XL",
  "tp003","wdzg! hat",120000,"S, L, XL",
  "tp004","evilarmy hat",115000,"S, L, XL",
  "tp005","volcom hat",160000,"S, L, XL",
  "bj001","wrng tees",123000,"S, L, XL",
  "bj002","wdzg! shirt",210000,"S, L, XL",
  "bj003","evilarmy shirt",220000,"S, L, XL",
  "bj004","volcom tees",220000,"S, L, XL",
  "bj005","LTP poloshirt",156000,"S, L, XL",
  "cl001","wrangler skinny",356000,"S, L, XL",
  "cl002","levi's 511 slimfit",689000,"S, L, XL",
  "cl003","wrangler slimfit",459000,"S, L, XL",
  "cl004","embajeans         ",345000,"S, L, XL",
  "cl005","levi's 501 regular",559000,"S, L, XL",
  "sp001","converse all-star",549000,"40 - 44",
  "sp002","converse jack purcel",720000,"39 - 44",
  "sp003","nike sb           ",719000,"40 - 43",
  "sp004","vans authentic     ",550000,"40 - 44",
  "sp005","adidas samba       ",899000,"39 - 43",
};
struct barang *tampung_barang;
struct tagihan
{
    char nama[20];
    char alamat[20];
    char kode_barang[20];
    char nama_barang[20];
    char size[20];
    int total_harga_barang;
    int ongkos_pengiriman;
    int total_tagihan;
};
struct tagihan tagih;
struct tagihan *tagih1;

main()
{
    menu_awal();
}
 void daftar()
 {
    system("cls");
    tampung=(struct anggota*)malloc(sizeof(struct anggota));
    char verifikasi;
    printf("Selamat Datang di Simulasi Aplikasi OSD\n");
    printf("=========================================\n\n");
    printf("Silahkan Inputkan Data Diri Anda!!\n");fflush(stdin);
    printf("Nama*\t\t=");gets(tampung->nama);fflush(stdin);
    printf("Email*\t\t=");gets(tampung->email);fflush(stdin);
    printf("TTL*\t\t=");gets(tampung->ttl);fflush(stdin);
    printf("Username*\t=");gets(tampung->username);fflush(stdin);
    printf("Password*\t=");gets(tampung->password);fflush(stdin);
    printf("\n\nNB: *(wajib diisi)");
    printf("\n\nApakah data di atas sudah benar (y/n)?  ");
    scanf("%c", &verifikasi);
    if (verifikasi=='y' || verifikasi=='Y')
    {
        menu_utama();
    }
    else
    {
        free(tampung);
        daftar();
    }
 }

 void login()
 {
    system("cls");
    char user[20], pass[20];
    printf("Silahkan Login dengan Username dan Password Anda !!\n");fflush(stdin);
    printf("Username\t:");gets(user);fflush(stdin);
    printf("Password\t:");gets(pass);fflush(stdin);
    if (strcmp(user,tampung->username)==0 && strcmp(pass,tampung->password)==0)
    {
        menu_utama();
    }
    else
    {
        login();
    }
 }
