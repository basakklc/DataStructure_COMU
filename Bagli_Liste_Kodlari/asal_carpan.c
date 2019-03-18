//Kullanıcıdan alınan sayıyı bağlı liste içinde bulup asal çarpanlarını bağlı liste şeklinde return etmek

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

struct hucre * asalcarpan(int sayi)
{
    struct hucre *a=NULL;
    int i;
    struct hucre *b,*c,*d;
    b=a;

    for(i=2; sayi!=1; i++)
    {
        if(sayi%i==0)
        {
            sayi=sayi/i;
            liste_sonuna_ekle(&a,i);
            i--;
        }
    }
    b=a;
    c=b->sonraki;
    while(b!=NULL)
    {
        c=b->sonraki;
        while(c!=NULL)
        {


            if(b->icerik==c->icerik)
            {
                d=c;
                c=c->sonraki;
                b->sonraki=c;
                free(d);
            }
            else
                c=c->sonraki;
        }
        b=b->sonraki;

    }



    return a;
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


    printf("hangi sayi alinsin:");
    scanf("%d",&sayi);
    yeni=asalcarpan(sayi);
    yazdir(yeni);

}
