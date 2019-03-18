//kullanıcıdan alınan bir sayıya bölünen tüm elemanları listeden silip başka bir listeye ekleme 
 //ana listede bölen elemanlar olmayacak.
  //dödürülen listede bölünmüş elemanlar olacak

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

void elemansil(struct hucre **y,int silinen)
{
    struct hucre *a,*b;
    a=*y;
    while(a!=NULL && a->icerik!=silinen)
    {
        b=a;
        a=a->sonraki;
    }
    if(a==NULL)
        return;
    else
    {
        if(*y==a)
        {
            *y=(*y)->sonraki;
        }

        else
        {
            b->sonraki=a->sonraki;
        }
        free(a);
    }
}


struct hucre * bolme(struct hucre ** a, int kaca)
{
    struct hucre *b=NULL;
    struct hucre *h=*a;
    while(h!=NULL)
    {
        if((h->icerik)%kaca==0)
            {
                liste_basina_Ekle(&b,h->icerik);
                elemansil(a,h->icerik);
            }
            h=h->sonraki;
    }
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
    yazdir(x);
    printf("hangi sayi alinsin:");
    scanf("%d",&sayi);
    yeni=bolme(&x,sayi);
    yazdir(yeni);
    printf("\n");
    yazdir(x);
    printf("\n");
  
  }

