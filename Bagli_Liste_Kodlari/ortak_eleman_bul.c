//Verilen iki bağlı listede de ortak olarak bulunan elemanları yazdıran fonksiyon

#include <stdio.h>
#include <stdlib.h>

struct hucre
{
    int icerik;
    struct hucre *sonraki;
};


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

void ortak_bul(struct hucre *x,struct hucre *y)
{
    struct hucre *a=x, *b=y;
    while(a!=NULL)
    {
        b=y;
        while(b!=NULL)
        {

            if(a->icerik==b->icerik){
                printf("%d" ,a->icerik);
                printf("\n");
                break;}
            b=b->sonraki;
        }
        a=a->sonraki;
    }
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
    liste_sonuna_ekle(&x,22);
    
    liste_sonuna_ekle(&y,110);
    liste_sonuna_ekle(&y,50);
    liste_sonuna_ekle(&y,40);
    liste_sonuna_ekle(&y,21);
    liste_sonuna_ekle(&y,22);
   
    ortak_bul(x,y);

}

