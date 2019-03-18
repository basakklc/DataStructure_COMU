//Verilen bağlı listenin tek numaralı indisteki elemanlarını bağlıiste olarak dönderme


#include <stdio.h>
#include <stdlib.h>

struct hucre
{
    int icerik;
    struct hucre *sonraki;
};
int eleman_sayisi_Bul(struct hucre *);
void liste_sonuna_ekle(struct hucre **,int );

struct hucre * hucre_olustur (int icerik)
{
    struct hucre *a;
    a=(struct hucre*)malloc(sizeof(struct hucre));
    if(a==NULL)
        printf("hata");
    a->icerik=icerik;
    a->sonraki=NULL;
    return a;
}
void liste_basina_Ekle(struct hucre **a,int icerik )
{
    struct hucre *b;
    b=hucre_olustur(icerik);
    b->sonraki=*a;
    *a=b;
}
void liste_sonuna_ekle(struct hucre **a,int icerik)
{
    struct hucre *b,*c;
    b=*a;
    c=hucre_olustur(icerik);
    if(*a==NULL)
    {
        c->sonraki=*a;
        *a=c;
    }
    else
    {
        while(b->sonraki!=NULL)
            b=b->sonraki;
        b->sonraki=c;
    }
}
void yazdir(struct hucre *y)
{

    struct hucre *a;
    a=y;
    while(a!=NULL)
    {
        printf("%d\n",a->icerik);
        a=a->sonraki;
    }
}


int eleman_sayisi_Bul(struct hucre *y)
{
    struct hucre *a;
    a=y;
    int i=0;
    while(a!=NULL)
    {
        i+=1;
        a=a->sonraki;
    }
    return i;
}

struct hucre * tek_indis(struct hucre *y)
{

    struct hucre *a;
    struct hucre *b=NULL;
    int i;
    i=eleman_sayisi_Bul(y);
    a=y;


    int x=1;



    while(x<i)
    {

        liste_sonuna_ekle(&b,a->icerik);
        a=a->sonraki->sonraki;
        x=x+2;
    }

    if(i%2!=0)
        liste_sonuna_ekle(&b,a->icerik);

    return b;
}


int main()
{
    struct hucre *x=NULL;
    struct hucre *a;
    struct  hucre *y=NULL;
    struct hucre *yeni;
    int sayi;
    liste_sonuna_ekle(&x,10);
    liste_sonuna_ekle(&x,5);
    liste_sonuna_ekle(&x,40);
    liste_sonuna_ekle(&x,21);
    liste_sonuna_ekle(&x,2);
    yazdir(x); y=tek_indis(x);
    yazdir(y);
    printf("\n");
}

