#include <stdio.h>
#include <stdlib.h>
#include<time.h>
struct dugum
{
    int key;///iceriğin tutuldugu bir dugum yapısı;
};

struct heap
{
    int eleman_sayisi;///asıl elemanları;
    int kapasite;///normal alani;
    struct dugum *dizi;///dugum elemanlarından olusan dizimi;
};

struct heap * heap_olustur (int kapasite) ///gelen kapasite orantısında bir heapde o boyutta bir dizi  oluşruacagız;
{
    struct heap *h;
    h=(struct heap*) malloc (sizeof(struct heap));
    if(h==NULL)
        printf("yer ayrilmamiş");
    h->dizi=(struct dugum * )malloc(sizeof(struct dugum)*kapasite);
    if(h->dizi==NULL)
        printf("yer ayrılmamis");

    h->eleman_sayisi=0;///heap şuanda boş olduğu için eleman =0 oldu.
    h->kapasite=kapasite;
    return h;
}

void initialize_heap(struct heap *heap,int eleman_sayisi,int aralik) ///heapi dolduruyoruz.
{
    int i,j;
    srand(time(NULL));
    int sayim;
    int cik;
    heap->dizi[0].key=rand()%aralik;
    for(i=1;i<eleman_sayisi;i++)
    {
        while(1)
        {

            sayim=rand()%aralik;
            for( j=0;j<i;j++) ///tekrar etmesini önlüyor.
            {
                if(heap->dizi[j].key==sayim)
                  {

                    break;
                  }
            }

            heap->dizi[i].key=sayim; ///random atadıgı an bir indisi dolduruyor. ikinci indise geçiyor.
            break;
        }
    }
    heap->eleman_sayisi=eleman_sayisi; ///eleman sayısını güncelliyorum. önceden 0 dı şimdi atadıgım kadar oldu.

}

void buble_down(struct heap *heap,int index)
{
    int sol=index*2+1;///ikili yiginin solu mu sagı mı..gibi
    int sag=index*2+0;
    int temp_key;
    while((sol<heap->eleman_sayisi && heap->dizi[sol].key>heap->dizi[index].key)  || (sag<heap->eleman_sayisi && heap->dizi[sag].key>heap->dizi[index].key))
    {
        if(sag>=heap->eleman_sayisi || heap->dizi[sol].key>heap->dizi[sag].key )///sagında eklenecek bir şey yok veya sol buyuk
        {                                                                     ///yani her türlü değişim soldan olacak..

            temp_key=heap->dizi[sol].key;///sol ile değiştirilme işlemi gerçekleşti.
            heap->dizi[sol].key=heap->dizi[index].key;
            heap->dizi[index].key=temp_key;
            index=2*index+1;///index önceden 0 dı şimdi solun yerine geçti bu yuzden solun kuralını aldı.
        }
        else///dizinin solu boş veya sol sagdan kuçük.
        {
            temp_key=heap->dizi[sag].key; ///sag ile değiştirilme işlemi.
            heap->dizi[sag].key=heap->dizi[index].key;
            heap->dizi[index].key=temp_key;
            index=2*index+2;
        }
        sol=2*index+1;///yeni sol;
        sag=2*index+2;///yeni sag;
    }
}





void heapify(struct heap *heap)
{
    for(int i=heap->eleman_sayisi/2;i>=0;i--)
    {
        buble_down(heap,i);
    }
}

void buble_up(struct heap *heap,int index)
{
    int temp_key;
    int parent = (index-1)/2;///her defasında parentla karşılaştıracagız.
    if(index>=0 && heap->dizi[parent].key<heap->dizi[index].key)
    {
        while(heap->dizi[parent].key<heap->dizi[index].key && parent>=0)
        {
            temp_key=heap->dizi[index].key;/// değişimişlemi
            heap->dizi[index].key=heap->dizi[parent].key;
            heap->dizi[parent].key=temp_key;
            index=parent;///bu sefer eklenenin parentinin parentini yaparak üste çıkıyoruzzz

            parent=(index-1)/2;


        }
    }



}

void insert(struct heap *heap,int key)///elle ekleme ;
{
    if(heap->eleman_sayisi<heap->kapasite)///ekleme yapmam için gereken şart...
    {
        heap->eleman_sayisi++;///artık ekliyorum artıyor.
        heap->dizi[heap->eleman_sayisi-1].key=key; ///dizi indisleri 0 la başlar...
        ///buble_up(heap,heap->eleman_sayisi-1);
heapify(heap);

    }
}
void print_heap(struct heap * heap)
{
    int i;

    for( i=0;i<heap->eleman_sayisi;i++)
    {

        printf("%5d",heap->dizi[i].key);
    }

}

void delete_max(struct heap *heap)
{
    int temp_key;
    if(heap->eleman_sayisi>1)
    {
        temp_key=heap->dizi[0].key;/// degğişimişlemi
        heap->dizi[0].key=heap->dizi[heap->eleman_sayisi-1].key;
        heap->dizi[heap->eleman_sayisi-1].key=temp_key;
        heap->eleman_sayisi--;
        buble_down(heap,0);///siliniince buble down yapıyoruz.
    }
}

void heap_sort(struct heap *heap)
{
    for(int i=1;i<heap->eleman_sayisi;i++)
        delete_max(heap);
    //heap->eleman_sayisi=
}









int main()
{
   struct heap *heap;
   heap=heap_olustur(90);
   //initialize_heap(heap,8,90);
   heapify(heap);
   insert(heap,10);
   insert(heap,0);
   insert(heap,20);
   insert(heap,30);
   //insert(heap,10);
   insert(heap,330);

    printf("\n");
     print_heap(heap);
     printf("\n");

   delete_max(heap);


   print_heap(heap);
   //heapify(heap);
   printf("\n");
  // print_heap(heap);

//printf("ddd");
    return 0;
}
