#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct tarihler
{
    int olumyil;
    char olumay[20];
    int olumgun;

} tarihler2;


typedef struct kisiBilgi
{

    char ad[10];
    char soyad[10];
    char sehir[10];
    char dogumyeri[10];
    int evraknumarasi;

    tarihler2 *tarih;

} kisiBilgi2;





kisiBilgi2 *kisibilgisi;
kisiBilgi2 *kisibilgisi2;


int  kisi=0;

void kisi_ekle()
{
    int i,j;
    kisibilgisi2 = (kisiBilgi2*)malloc(sizeof(kisiBilgi2)*(kisi+1)); //yer ayirdim

    for(i=0; i<kisi; i++)
    {
        *(kisibilgisi2+i)= *(kisibilgisi+i);
    }
    kisibilgisi = kisibilgisi2;



    char isim[20];
    char soyisim[20];
    char dogumyerismi[20];
    char sehirisim[20];
    char olumayisim[20];


    printf("Kaydettiginiz kisiye evrak numarasi veriniz :  ");
    scanf("%d",&(kisibilgisi+kisi)->evraknumarasi);

    printf("Olen kisinin Adini giriniz: ");
    scanf("%s", &isim);
    strcpy((kisibilgisi+kisi)->ad,isim);


    printf("Olen kisinin soyadini giriniz: ");
    scanf("%s",&soyisim);
    strcpy((kisibilgisi+kisi)->soyad,soyisim);

    printf("Olen kisinin dogum yerini giriniz: ");
    scanf("%s",&dogumyerismi);
    strcpy((kisibilgisi+kisi)->dogumyeri,dogumyerismi);

    printf("Olen kisinin mezarinin defnedilmesi istediginiz sehri giriniz: ");
    scanf("%s",&sehirisim);
    strcpy((kisibilgisi+kisi)->sehir,sehirisim);

    (kisibilgisi+kisi)->tarih=(tarihler2*)malloc(sizeof(tarihler2)*(kisi+1));

    printf("Olen kisinin olum gununu sayilarla giriniz: ");
    scanf("%d",&((kisibilgisi+kisi)->tarih)->olumgun);

    printf("Olen kisinin oldugu ayi harf karakterleriyle giriniz: ");
    scanf("%s",&olumayisim);
    strcpy(((kisibilgisi+kisi)->tarih)->olumay,olumayisim);

    printf("Olen kisinin oldugu yili sayilarla giriniz : ");
    scanf("%d",&((kisibilgisi+kisi)->tarih)->olumyil);



    kisi++;

}

void kisi_listele()
{


    int i;
    for(i=0; i<kisi; i++)
    {
        printf(" Kisinin adi : %s \n ",(kisibilgisi+i)-> ad);
        printf("Kisinin soyadi : %s \n ",(kisibilgisi+i)->soyad);
        printf("Kisinin dogum yeri : %s \n ",(kisibilgisi+i)->dogumyeri);
        printf("Kisinin defnedildigi : %s \n ",(kisibilgisi+i)-> sehir);
        printf("Kisinin olum tarihi : %d %s %d \n ",((kisibilgisi+i)->tarih)->olumgun,((kisibilgisi+i)->tarih)->olumay,((kisibilgisi+i)->tarih)->olumyil);


    }

    if(kisibilgisi == NULL)
    {
        printf("\n boyle bir kisi kaydi yoktur\n");


    }
}

void kisi_sil()
{

    int i,j,evrakno,sayac=0;
    printf("Silmek istediginiz kisinin evrak numarasini giriniz :  ");
    scanf("%d",&evrakno);


    for(i=0; i<kisi; i++)
    {

        if(((kisibilgisi+i)->evraknumarasi)==evrakno)
        {
            sayac = 1;
            for(j=evrakno; j<kisi; j++)
            {

                *(kisibilgisi+(j-1))=*(kisibilgisi+j);

            }
            kisi--;
            kisibilgisi2=(kisiBilgi2*)malloc(sizeof(kisiBilgi2)*kisi);
            for(j=0; j<kisi; j++)
            {

                *(kisibilgisi2+j)=*(kisibilgisi+j);


            }
            kisibilgisi = kisibilgisi2;

            printf(" Kisi basariyla silinmistir.");

        }
    }
    if(sayac==0)
    {
        printf("Silmek istediginiz kisi sistemde bulunamamistir.");
    }



}

void kisi_guncelleme()
{

    int i,j,evrakno,sayac=0;
    printf("Guncellemek istediginiz evrak numarasini giriniz : ");
    scanf("%d",&evrakno);


    for(i=0; i<kisi; i++)
    {

        if(((kisibilgisi+i)->evraknumarasi)==evrakno)
        {
            sayac = 1;

            char isim[20];
            char soyisim[20];
            char dogumyerismi[20];
            char sehirisim[20];
            char olumayisim[20];




            printf("Olen kisinin Adini giriniz: ");
            scanf("%s", &isim);
            strcpy((kisibilgisi+kisi)->ad,isim);


            printf("Olen kisinin soyadini giriniz: ");
            scanf("%s",&soyisim);
            strcpy((kisibilgisi+kisi)->soyad,soyisim);

            printf("Olen kisinin dogum yerini giriniz: ");
            scanf("%s",&dogumyerismi);
            strcpy((kisibilgisi+kisi)->dogumyeri,dogumyerismi);

            printf("Olen kisinin mezarinin defnedilmesi istediginiz sehri giriniz: ");
            scanf("%s",&sehirisim);
            strcpy((kisibilgisi+kisi)->sehir,sehirisim);


        }

    }

    if(sayac==0)
    {
        printf("Guncellemek istediginiz kisi sistemde bulunamadi.");
    }





}

void kisi_ara()
{

    int i,j,evrakno,sayac=0;
    printf("Aramak istediginiz kisinin evrak numarasini giriniz :");
    scanf("%d",&evrakno);
    char isim[20];
    char soyisim[20];
    char dogumyerismi[20];
    char sehirisim[20];
    char olumayisim[20];



    for(i=0; i<kisi; i++)
    {
        if((kisibilgisi+i)->evraknumarasi==evrakno)
        {
            sayac = 1;

            printf(" Kisinin adi : %s \n ",(kisibilgisi+i)-> ad);
            printf("Kisinin soyadi : %s \n ",(kisibilgisi+i)->soyad);
            printf("Kisinin dogum yeri : %s \n ",(kisibilgisi+i)->dogumyeri);
            printf("Kisinin defnedildigi : %s \n ",(kisibilgisi+i)-> sehir);
            printf("Kisinin olum tarihi : %d %s %d \n ",((kisibilgisi+i)->tarih)->olumgun,((kisibilgisi+i)->tarih)->olumay,((kisibilgisi+i)->tarih)->olumyil);


        }


    }
    if(sayac==0)
    {
        printf("Aradiginiz kisi sistemde bulunamadi!\n\n\n",evrakno);

    }

}

void yas ()
{
    int dogumyil,olumyil,yas;

    printf("Kisinin dogum yilini giriniz : ");
    scanf("%d",&dogumyil);

    printf("Kisinin olum yilini giriniz : ");
    scanf("%d",&olumyil);

    yas = olumyil-dogumyil;
    if(yas<0)
    {
         printf("Hatali islem! Tekrar deneyiniz . ");

    }



    if(0<yas && yas<20)
    {
        printf("Kisinin oldugu yas = %d\n",yas);
        printf("Kisi cocuk kategorisindedir.");
    }
    if(yas>=20 && 35>yas)
    {
        printf("Kisinin oldugu yas = %d\n",yas);
        printf("Kisi genc yasdadir.");
    }

    if(35==yas )
    {
        printf("Kisinin oldugu yas = %d\n",yas);
        printf("Kisi orta yasdadir.");
    }

    if(yas>50)
    {
        printf("Kisinin oldugu yas = %d\n",yas);
        printf("Kisi yaslidir.");
    }



}

void print_menu()
{
    system("cls");
    printf("\t\t\t\t------------ MEZARLIK OTOMASYONUNA HOSGELDINIZ ! ------------\n\n");
    printf("LUTFEN ISLEM YAPMAK ISTEDIGINIZ TUSU TIKLAYIP ENTERE BASIN\n\n");
    printf("  =========================================================\n");
    printf("* Yeni kisi eklemek icin 1 tusunu tuslayiniz.\n");
    printf(" -----------------------------------------------------------\n");
    printf("* Kisileri listelemek icin 2 tusunu tuslayiniz.\n");
    printf(" -----------------------------------------------------------\n");
    printf("* Kisi bilgilerini silmek icin 3 tusunu tuslayiniz.\n");
    printf(" -----------------------------------------------------------\n");
    printf("* Kisi bilgilerini  guncellemek icin 4 tusunu tuslayiniz.\n");
    printf(" -----------------------------------------------------------\n");
    printf("*Kisi bilgilerini aramak icin 5 tusunu tuslayiniz.\n");
    printf(" -----------------------------------------------------------\n");
    printf("*Kisinin olum yasini ogrenmek  icin 6 tusunu tuslayiniz.\n");
    printf(" -----------------------------------------------------------\n");
    printf("* Mezarlik otomasyonundan cikmak icin 7 tusunu tuslayiniz.\n");
    printf(" ===========================================================\n");
}





int main()
{
    int menu,say=1,evrakno,listedencikis,menudencikis;

    while(1)
    {
        print_menu();		//her dongude menu tekrar yazilacak
        printf("isleminiz : ");
        scanf("%d",&menu);

        switch(menu)
        {
        case 1:
            system("cls");
            kisi_ekle();
            printf("\nKaydiniz basariyla tamamlanmistir. Ana menuye donmek icin herhangi bir sayi giriniz.->\n ");
            scanf("%d",&menudencikis);
            break;
        case 2:
            system("cls");
            kisi_listele();
            printf("\n Ana menuye donmek icin herhangi bir sayi giriniz.->\n ");
            scanf("%d",&menudencikis);
            break;
        case 3:
            system("cls");
            kisi_sil();
            printf("\n Ana menuye donmek icin herhangi bir sayi giriniz.-> \n");
            scanf("%d",&menudencikis);
            break;

        case 4:
            system("cls");
            kisi_guncelleme();
            printf("\n Ana menuye donmek icin herhangi bir sayi giriniz.-> \n");
            scanf("%d",&menudencikis);
            break;

        case 5:
            system("cls");
            kisi_ara();
            printf("\nIsleminiz basariyla tamamlandi. Ana menuye donmek icin herhangi bir sayi giriniz.->\n ");
            scanf("%d",&menudencikis);
            break;

        case 6:
            system("cls");
            yas();
            printf("\nIsleminiz basariyla tamamlandi. Ana menuye donmek icin herhangi bir sayi giriniz.-> \n");
            scanf("%d",&menudencikis);
            break;
        case 7:
            say = 0;
            break;
        default:

            printf("hatali giris. tekraar deneyin\n");
            break;
        }

        if(say == 0)
        {
            system("cls");
            printf("\t\t\t\t*******Saglicakla kalin.*******\n");
            break;
        }
    }

    return 0;
}
