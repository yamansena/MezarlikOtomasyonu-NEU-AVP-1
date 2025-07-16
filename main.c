#include <stdio.h>
#include <stdlib.h>

typedef struct tarihler
{
    int olumyil;
    char olumay[12];
    int olumgun;

}tarihler2;

typedef struct kisiBilgi
{

    char ad;
    char soyad;
    char sehir;
    char dogumyeri;
    int evraknumarasi;

    tarihler2 *tarih;

}kisiBilgi2;





kisiBilgi2 *kisibilgisi;
kisiBilgi2 *kisibilgisi2;


int  kisi=0;

void kisi_ekle()
{
    int i,j;
    kisibilgisi2 = (kisiBilgi2*)malloc(sizeof(kisibilgisi2)*(kisi+1));

    for(i=0; i<kisi; i++)
    {
        *(kisibilgisi2+i)= *(kisibilgisi+i);
    }
    kisibilgisi = kisibilgisi2;

    printf("Olen kisinin Adini giriniz: ");
    scanf("%s",&(kisibilgisi+kisi)->ad);

    printf("Olen kisinin soyadini giriniz: ");
    scanf("%s",&(kisibilgisi+kisi)->soyad);

    printf("Olen kisinin dogum yerini giriniz: ");
    scanf("%s",&(kisibilgisi+kisi)->dogumyeri);

    printf("Olen kisinin mezarinin defnedilmesi istediginiz sehri giriniz: ");
    scanf("%s",&(kisibilgisi+kisi)->sehir);

    printf("Olen kisinin olum gununu sayilarla giriniz: ");
    scanf("%d",&((kisibilgisi+kisi)->tarih)->olumgun);

    printf("Olen kisinin oldugu ayi harf karakterleriyle giriniz: ");
    scanf("%s",&((kisibilgisi+kisi)->tarih)->olumay);

    printf("Olen kisinin oldugu yili sayilarla giriniz : ");
    scanf("%d",&((kisibilgisi+kisi)->tarih)->olumyil);

    printf("Kaydettiginiz kisiye evrak numarasi veriniz :  ");
    scanf("%d",&(kisibilgisi+kisi)->evraknumarasi);

    (kisibilgisi+kisi)->tarih=(kisiBilgi2*)malloc(sizeof(kisiBilgi2)*(kisi+1));

    kisi++;

}

void kisi_listele()
{
    if(kisibilgisi == NULL)
    {
        printf("\n boyle bir kisi kaydi yoktur\n");
        return 1;

    }

    int j;
    for(j=0;j<kisi;j++)
    {
        printf("\n Olen Kisinin adi: %s\n",j+1,(kisibilgisi+j)->ad);
        printf("\n Olen Kisinin soyadi :%s\n",j+1,(kisibilgisi+j)->soyad);

    }
}

void kisi_sil()
{

	int i,j,evrakno;
    printf("Silmek istediginiz kisinin evrak numarasini giriniz : %d ");
    scanf("%d",&evrakno);


     

    for(i=0;i<kisi;i++)
    {
        if((kisibilgisi+i)->evraknumarasi==evrakno)
        {
            for(j=evrakno;j<kisi;j++)
            {


                *(kisibilgisi+(j-1))=*(kisibilgisi+j);


            }
            kisi--;
            kisibilgisi2=(kisiBilgi2*)malloc(sizeof(kisiBilgi2)*kisi);
            for(j=0;j<kisi;j++)
            {

                *(kisibilgisi2+j)=*(kisibilgisi+j);


            }
            kisibilgisi = kisibilgisi2;
        }
    }

	if(kisibilgisi == NULL)
    {
        printf("\n Sistem de boyle bir kayit yoktur\n");
        return 1;
	}

}

void kisi_guncelleme()
{


    int i,j,evrakno;
    printf("Guncellemek istediginiz evrak numarasini giriniz : %d");
    scanf("%s",&evrakno);

    if(kisibilgisi==NULL)
    {
        printf("\nKisi kaydi bulunmamaktadir.\n");

        return 1;
    }

    for(i=0;i<kisi;i++)
    {
        if((kisibilgisi2 + i) ->evraknumarasi==evrakno)
        {


    printf("÷len kisinin Adini giriniz: ");
    scanf("%s",(kisibilgisi+i)->ad);

    printf("Olen kisinin soyadini giriniz: ");
    scanf("%s",(kisibilgisi+i)->soyad);

    printf("Olen kisinin dogum yerini giriniz: ");
    scanf("%s",(kisibilgisi+i)->dogumyeri);


    printf("Olen kisinin mezar¨n¨n defnedilmesi istediginiz sehri giriniz: ");
    scanf("%s",(kisibilgisi+i)->sehir);

    printf("Olen kisinin olum gununu sayilarla giriniz: ");
    scanf("%d",&((kisibilgisi+i)->tarih)->olumgun);

    printf("Olen kisinin oldugu ayi harf karakterleriyle giriniz: ");
    scanf("%s",&((kisibilgisi+i)->tarih)->olumay);

    printf("Olen kisinin oldugu yili sayilarla giriniz : ");
    scanf("%d",&((kisibilgisi+i)->tarih)->olumyil);
    break;

        }
    }


}

void kisi_ara()
{

    int i,j,evrakno,sayac=0;
    printf("Aramak istediginiz kisinin evrak numarasini giriniz :%d");
    scanf("%d",&evrakno);

    if(kisibilgisi==NULL)
    {
        printf("\n Arad¨g¨n¨z kisi sistemde kayitli degildir.\n");

        return 1 ;

    }
    for(i=0;i<kisi;i++)
    {
        if((kisibilgisi+i)->evraknumarasi==evrakno)
        {
            sayac = 1;
            printf("Olen kisinin Adi : ");
            scanf("%s",(kisibilgisi+kisi)->ad);

            printf("Olen kisinin soyadi : ");
            scanf("%s",(kisibilgisi+kisi)->soyad);

            printf("Olen kisinin dogum yeri : ");
            scanf("%s",(kisibilgisi+kisi)->dogumyeri);


            printf("Olen kisinin mezar¨n¨n defnedildigi sehir: ");
            scanf("%s",(kisibilgisi+kisi)->sehir);

            printf("Olen kisinin olum gunu: ");
            scanf("%d",&((kisibilgisi+kisi)->tarih)->olumgun);

            printf("Olen kisinin oldugu ay: ");
            scanf("%s",&((kisibilgisi+kisi)->tarih)->olumay);

            printf("Olen kisinin oldugu yil : ");
            scanf("%d",&((kisibilgisi+kisi)->tarih)->olumyil);
            break;



        }
    }
    if(sayac==0)
    {
        printf("Aradiginiz kisi sistemde bulunamadi!\n\n\n",evrakno);

    }
}

void miras_detay()
{
   printf("1.Mirasinizi devlete bagislayabilirsiniz .\n 2. Mirasinizi cocuklaraniza birakabilirsiniz.\n");

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
    printf("*Miras bilgilerini ogrenmek  icin 6 tusunu tuslayiniz.\n");
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
            printf("Kaydiniz basariyla tamamlanmistir. Ana menuye donmek icin herhangi bir sayi giriniz.-> ");
            scanf("%d",&menudencikis);
            break;
        case 2:

            kisi_listele();
            printf("\n Ana menuye donmek icin herhangi bir sayi giriniz.-> ");
            scanf("%d",&menudencikis);
            break;
        case 3:
            system("cls");
            kisi_sil();
            printf("Kisi basariyla silinmistir. Ana menuye donmek icin herhangi bir sayi giriniz.-> ");
            scanf("%d",&menudencikis);
            break;

            //break;
        case 4:
            system("cls");
            kisi_guncelleme();
            printf("Guncellemeniz basariyla tamamlandi. Ana menuye donmek icin herhangi bir sayi giriniz.-> ");
            scanf("%d",&menudencikis);
            break;

        case 5:
            system("cls");
            kisi_ara();
            printf("Isleminiz basariyla tamamlandi. Ana menuye donmek icin herhangi bir sayi giriniz.-> ");
            scanf("%d",&menudencikis);
            break;

        case 6:
            system("cls");
            miras_detay();
            printf("Isleminiz basariyla tamamlandi. Ana menuye donmek icin herhangi bir sayi giriniz.-> ");
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
        	printf("by.\n");
        	break;
		}
   }

    return 0;
}

