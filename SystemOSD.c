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
 void menu_awal()
 {
     system("cls");
     int pilihan;
    printf("Simulasi Aplikasi Online Shop distro\n");
    printf("====================================\n\n");
    printf("1. Daftar\n");
    printf("2. Login\n");
    printf("3. Exit\n\n");

    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        daftar();
    }
    else if (pilihan==2)
    {
        login();
    }
    else if (pilihan==3)
    {
        exit(1);
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        menu_awal();
    }
    getch();
 }
void menu_utama()
{
    system("cls");
    int pilihan;
    printf("Selamat Datang Customer %s di Online Shop Distro\n\n", tampung->nama);
    printf("1. Lihat Barang\n");
    printf("2. Order\n");
    printf("3. Pembayaran\n");
    printf("4. Logout\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        lihat_barang();
    }
    else if (pilihan==2)
    {
        order();
    }
    else if (pilihan==3)
    {
        pembayaran();
    }
    else if (pilihan==4)
    {
        menu_awal();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        menu_utama();
    }
    getch();

}
lihat_barang()
{
    system("cls");
    int pilihan;
    printf("Our Product\n");
    printf("=============\n\n");
    printf("1. Topi\n");
    printf("2. Baju\n");
    printf("3. Celana\n");
    printf("4. Sepatu\n");
    printf("5. Menu Utama\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        Topi();
    }
    else if (pilihan==2)
    {
        Baju();
    }
    else if (pilihan==3)
    {
        Celana();
    }
    else if (pilihan==4)
    {
        Sepatu();
    }
    else if (pilihan==5)
    {
        menu_utama();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        lihat_barang();
    }
    getch();
}
order()
{
    system("cls");
    int pilihan;
    printf("1. Pemesanan\n");
    printf("2. Pemilihan Mode Pengiriman\n");
    printf("3. Tagihan\n");
    printf("4. Menu Utama\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        pemesanan();
    }
    else if (pilihan==2)
    {
        mode_pengiriman();
    }
    else if (pilihan==3)
    {
        tagihan();
    }
    else if (pilihan==4)
    {
        menu_utama();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        order();
    }
    getch();
}
pembayaran()
{
    system("cls");
    int pilihan,pilihanx, norek, setor,notran ;
    tagih1=(struct tagihan*)malloc(sizeof(struct tagihan));
    char namabank[20];
    printf("Pembayaran\n");
    printf("============\n\n");
    printf("Nama Customer       = %s\n",tagih.nama);
    printf("Total Tagihan         = Rp. %d\n", tagih.total_tagihan);
    printf("\n\nBayar Via : \n");
    printf("1. Bayar Langsung\n");
    printf("2. Bill ATM\n");
    printf("3. Menu Utama\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        printf("Inputkan Nomor Rekning  : ");
        scanf("%d", &norek);fflush(stdin);
        printf("Inputkan Nama Bank      :");
        gets(namabank);fflush(stdin);
        printf("Inputkan Jumlah Setoran :");
        scanf("%d", &setor);
        if (setor==tagih.total_tagihan)
        {
            total_tagihan=0;
            harga_barang=0;
            ongkos=0;
            tagih.total_tagihan=0;
            tagih.total_harga_barang=0;
            tagih.ongkos_pengiriman=0;
            printf("Tagihan Lunas !! ");
        }

        printf("\n\n");
    printf("1. Menu Utama\n");
    printf("2. Menu Sebelumnya\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihanx);
    if (pilihanx==1)
    {
        menu_utama();
    }
    else if (pilihanx==2)
    {
        tagihan();
    }
    else
    {
        printf("Input yg anda masukkan salah !! ");
        menu_utama();
    }
    }
    else if (pilihan==2)
    {
        printf("Inputkan Nomor Rekening  : ");
        scanf("%d", &norek);fflush(stdin);
        printf("Inputkan Nama Bank      :");
        gets(namabank);fflush(stdin);
        printf("Inputkan Nomor transaksi  : ");
        scanf("%d", &notran);fflush(stdin);
        printf("Inputkan Jumlah Setoran :");
        scanf("%d", &setor);
        if (setor==tagih.total_tagihan)
        {
            total_tagihan=0;
            harga_barang=0;
            ongkos=0;
            tagih.total_tagihan=0;
            tagih.total_harga_barang=0;
            tagih.ongkos_pengiriman=0;
            printf("Tagihan Lunas !! ");
        }

        printf("\n\n");
    printf("1. Menu Utama\n");
    printf("2. Menu Sebelumnya\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihanx);
    if (pilihanx==1)
    {
        menu_utama();
    }
    else if (pilihanx==2)
    {
        tagihan();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        menu_utama();
    }
    }
    else if (pilihan==3)
    {
        menu_utama();
    }
    else
    {
        printf("Input yg anda masukkan salah !! ");
        menu_utama();
    }
}
Topi()
{
    system("cls");
    int i,pilihan;
    printf("\t\tHat Product\n");
    printf("Kode Barang \tNama Barang \t\tHarga \t\tSize\n");
    printf("======================================================================\n\n");
    for (i=0;i<5;i++)
    {
        printf("%s \t\t%s \t\tRp. %d \t\t%s \n", brg[i].kode_barang, brg[i].nama_barang, brg[i].harga, brg[i].size);
    }
    printf("\n\n");
    printf("1. Order\n");
    printf("2. Menu Sebelumnya\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        order();
    }
    else if (pilihan==2)
    {
        lihat_barang();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        Topi();
    }
}
Baju()
{
    system("cls");
    int i,pilihan;
    printf("\t\tClothes Product\n");
    printf("Kode Barang \tNama Barang \t\tHarga \t\tSize\n");
    printf("=====================================================================\n\n");
    for (i=5;i<10;i++)
    {
        printf("%s \t\t%s \t\tRp. %d \t\t%s \n", brg[i].kode_barang, brg[i].nama_barang, brg[i].harga, brg[i].size);
    }
    printf("\n\n");
    printf("1. Order\n");
    printf("2. Menu Sebelumnya\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        order();
    }
    else if (pilihan==2)
    {
        lihat_barang();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        Baju();
    }

}
Celana()
{
    system("cls");
    int i, pilihan;
    printf("\t\tPants Product\n");
    printf("Kode Barang \tNama Barang \t\t\tHarga \t\tSize\n");
    printf("========================================================================\n\n");
    for (i=10;i<15;i++)
    {
        printf("%s \t\t%s \t\tRp. %d \t\t%s \n", brg[i].kode_barang, brg[i].nama_barang, brg[i].harga, brg[i].size);
    }
    printf("\n\n");
    printf("1. Order\n");
    printf("2. Menu Sebelumnya\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        order();
    }
    else if (pilihan==2)
    {
        lihat_barang();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        Celana();
    }
}
Sepatu()
{
    system("cls");
    int i, pilihan;
    printf("\t\tShoes Product\n");
    printf("Kode Barang \tNama Barang \t\t\tHarga \t\tSize\n");
    printf("=========================================================================\n\n");
    for (i=15;i<20;i++)
    {
        printf("%s \t\t%s \t\tRp. %d \t\t%s \n", brg[i].kode_barang, brg[i].nama_barang, brg[i].harga, brg[i].size);
    }
    printf("\n\n");
    printf("1. Order\n");
    printf("2. Menu Sebelumnya\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        order();
    }
    else if (pilihan==2)
    {
        lihat_barang();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        Sepatu();
    }
}
pemesanan()
{
    system("cls");
    int i, pilihan, price;
    tampung_barang=(struct barang*)malloc(sizeof(struct barang));
    char kode[20], jawab[5];fflush(stdin);

    printf("\nInputkan kode barang: ");
    gets(kode); strcpy(tagih.kode_barang,kode);fflush(stdin);
    printf("\nJumlah yang dipesan: ");
    scanf("%d", &jumlah);fflush(stdin);
    for (i=0;i<20;i++)
    {
         if (strcmp(kode,brg[i].kode_barang)==0)
    {
        strcpy(tagih.nama_barang,brg[i].nama_barang);
        harga_barang=harga_barang+(brg[i].harga*jumlah);
        price=brg[i].harga;
    }
    }
    printf("Inputkan ukuran barang: ");
    gets(ukuran);strcpy(tagih.size,ukuran);
    printf("\n\nTotal Pemesanan(Harga X Jumlah)\nHarga Barang Rp. %d X %d\n========\nTotal  Rp. %d,-",price,jumlah, harga_barang);

    tagih.total_harga_barang=harga_barang;
    printf("\n\n");
    printf("1. Pengiriman\n");
    printf("2. Menu Sebelumnya\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        mode_pengiriman();
    }
    else if (pilihan==2)
    {
        order();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        pemesanan();
    }

}
mode_pengiriman()
{
    system("cls");
    int pilihan,pilihanx;
    char alamat[30];fflush(stdin);
    printf("Masukkan Alamat Lengkap yang dituju:\n");
    gets(alamat);strcpy(tagih.alamat,alamat);fflush(stdin);
    printf("\nPilih Maskapai untuk Mengirim Barang:\n");
    printf("1. Tiki Rp. 28.000/barang\n");
    printf("2. JNE Rp. 25.000/barang\n");
    printf("3. Indah Cargo Rp. 22.000/barang\n");
     printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        ongkos=28000*jumlah;
        tagih.ongkos_pengiriman=ongkos;
        printf("\nBiaya Pengiriman (Ongkos * Jumlah Barang) Rp.28000 * %d= %d\n  ", jumlah, ongkos);
    }
    else if (pilihan==2)
    {
        ongkos=25000*jumlah;
        tagih.ongkos_pengiriman=ongkos;
        printf("\nBiaya Pengiriman (Ongkos * Jumlah Barang) Rp.25000 * %d= %d", jumlah, ongkos);
    }
    else if (pilihan==3)
    {
        ongkos=22000*jumlah;
        tagih.ongkos_pengiriman=ongkos;
        printf("\nBiaya Pengiriman (Ongkos * Jumlah Barang) Rp.22000 * %d= %d", jumlah, ongkos);
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        mode_pengiriman();
    }
    printf("\n\n");
    printf("1. Tagihan\n");
    printf("2. Menu order\n");
    printf("Masukkan pilihan anda: ");
    scanf ("%d", &pilihanx);
    if (pilihanx==1)
    {
        tagihan();
    }
    else if (pilihanx==2)
    {
        order();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        mode_pengiriman();
    }

}
tagihan()
{
    system("cls");
    int pilihan;
    strcpy(tagih.nama,tampung->nama);
    total_tagihan=harga_barang+ongkos;
    tagih.total_tagihan=total_tagihan;
    printf("Nama Customer       = %s\n", tagih.nama);
    printf("Alamat Customer     = %s\n", tagih.alamat);
    printf("Kode Barang         = %s\n", tagih.kode_barang);
    printf("Nama Barang         = %s\n", tagih.nama_barang);
    printf("Ukuran Barang       = %s\n", tagih.size);
    printf("Total harga barang  = Rp. %d\n", tagih.total_harga_barang);
    printf("Biaya Pengiriman    = Rp. %d\n", tagih.ongkos_pengiriman);
    printf("Total Biaya         = Rp. %d", tagih.total_tagihan);

    printf("\n\n");
    printf("1. Bayar Tagihan\n");
    printf("2. Menu Order\n");
    printf("Masukkan Pilihan Anda: ");
    scanf ("%d", &pilihan);
    if (pilihan==1)
    {
        pembayaran();
    }
    else if (pilihan==2)
    {
        order();
    }
    else
    {
        printf("Input yg anda masukkan salah !! Silahkan Ulangi Kembali");
        tagihan();
    }
}

