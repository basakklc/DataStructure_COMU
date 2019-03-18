//Bağlı listede istenilen elemanı istediğimiz eleman kadar ileriye taşıyan fonksiyon

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


void tasi(struct hucre **y,int n,int istenen)
{
    struct hucre *a=*y;
    struct hucre *b,*x,*z,*t;
    int i;
    while(a!=NULL)
    {

        if(a->icerik!=istenen)
        {
            z=a;
            a=a->sonraki;
        }
        else if(a->icerik==istenen)
            break;
        else
            return;
       
    }

    if(a==*y)
    {
        printf("hj");
        t=a->sonraki;
        x=hucre_olustur(a->icerik);
        for(i=0; i<=n; i++)
        {
            b=a;
            a=a->sonraki;
        }
        b->sonraki=x;
        x->sonraki=a;
        *y=t;


    }
    else
    {
        t=z->sonraki;
        x=hucre_olustur(a->icerik);
        for(i=0; i<=n; i++)
        {
            b=a;
            a=a->sonraki;
        }
       
        b->sonraki=x;
        x->sonraki=a;
        z->sonraki=t->sonraki;
        free(t);



    }


}









int main()
{
    struct hucre *x=NULL;
    struct hucre *a;
    struct  hucre *y=NULL;
    struct hucre *yeni;
    
    liste_sonuna_ekle(&x,10);
    liste_sonuna_ekle(&x,5);
    liste_sonuna_ekle(&x,40);
    liste_sonuna_ekle(&x,21);
    liste_sonuna_ekle(&x,2);
    yazdir(x);
    printf("\n");
    tasi(&x,1,5);
    yazdir(x);
    
}

