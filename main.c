#include <stdio.h>
#include <string.h>

struct musteri {
    char isim[50];
    char telnum[15];
    float usage;
    float totalbill;
};
struct musteri musteriler[100];
int mustericount =0;


void kayitekle() {
    if (mustericount < 100) {
        printf("\nIsim giriniz:");
        scanf(" %[^\n]s",musteriler[mustericount].isim);
        printf("\nTelefon numarasi giriniz: ");
        scanf("%s", musteriler[mustericount].telnum);
        printf("\nKullanim suresi giriniz(dakika olarak):");
        scanf("%f", &musteriler[mustericount].usage);
        musteriler[mustericount].totalbill = musteriler[mustericount].usage*0.1;
           mustericount++;
        printf("\nKayit basariyla tamamlandi");
    }
    else {
        printf("\nMaksimum kayit numarasina ulasildi!\n");
    }
}

void kayitgoruntule() {
    printf("\nName\tTelefon numarasi\tKullanim(dakika)""Bill($)\n");
    for (int i = 0; i<mustericount; i++) {
        printf("%s\t%s\t%.2f\t\t%.2f\n",musteriler[i].isim,musteriler[i].telnum,musteriler[i].usage,musteriler[i].totalbill);
    }
}

void kayityenile(char telnum[]) {
    for (int i = 0; i<mustericount; i++) {
        if (strcmp(musteriler[i].telnum,telnum)==0) {
            printf("\n%s icin yeni kullanim süresi giriniz(dakika):",musteriler[i].isim);
            scanf("%f", &musteriler[i].usage);
            musteriler[i].totalbill = musteriler[i].usage * 0.1;

        }
    }
    printf("Kayit basariyla yenilendi..\n");
}
void odemegoruntule(char telnum[]) {
    for (int i =0; i<mustericount; i++) {
        if (strcmp(musteriler[i].telnum,telnum)==0) {
            printf("%s\t%s\t%.2f\t\t%.2f\n",musteriler[i].isim,musteriler[i].telnum,musteriler[i].usage, musteriler[i].totalbill);
            return;
        }
    }
    printf("Kayit bulunamadi!\n");
}
void kayitsil(char telnum[]) {
    for (int i = 0; i<mustericount; i++) {
        if (strcmp(musteriler[i].telnum,telnum)==0) {
            for (int j =i; j<mustericount-1; j++) {
                musteriler[j]=musteriler[j+1];
            }
            mustericount--;
            printf("Kayit basariyla silinmistir.\n");
            return ;
        }
    }
    printf("Kayit bulunamadi!\n");
}
void menuoynat() {
    printf("\n1.Yeni kayit ekle\n");
    printf("2.Kayitleri goruntule\n");
    printf("3.Kayit yenile\n");
    printf("4.Odemeyi goruntule\n");
    printf("5.Kayit sil\n");
    printf("6.Cikis\n");
}

int main() {
    int secim;
    char telnum[15];
    while (1){
    menuoynat();
    printf("Seciminizi giriniz:");
        scanf("%d", &secim);

switch (secim) {
    case 1:
    kayitekle();
    break;
    case 2:
        kayitgoruntule();
    break;
    case 3:
        printf("\nYenilemek istediginiz kayitin telefon numarasini giriniz:");
    scanf("%s",telnum);
    kayityenile(telnum);
    break;
    case 4:
        printf("\nOdeme goruntelemek istediginiz telefon numarasini giriniz:");
    scanf("%s",telnum);
    odemegoruntule(telnum);
    break;
    case 5:
        printf("\nKayitini silmek istediginiz telefon numarasini giriniz:");
    scanf("%s",telnum);
    kayitsil(telnum);
    break;
    case 6:
        return 0;
    default:
        printf("\nGecersiz bir islem denediniz lutfen tekrar deneyiniz...\n");

}
}
return 0;
}