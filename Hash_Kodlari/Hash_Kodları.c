#include <stdio.h>
#include <stdlib.h>
struct CELL
{
    char * anahtar;
    struct CELL *next;
};
struct table_node
{
    int counter;
    struct CELL *header;
};
struct hash_table
{
    int multipler;
    int eleman_sayisi;
    struct table_node *tablo_basi ;
};

void initialize_hashtable(int carpan,int tablo_uzunlugu,struct hash_table **h)
{
    *h=(struct hash_table *)malloc (sizeof(struct hash_table));///burada hash tablosunun özellikleri için malloc ile yer açtıkk
    if(*h==NULL)
        printf("yer ayrılmamış");
    (*h)->tablo_basi=(struct table_node *)malloc(tablo_uzunlugu*sizeof(struct table_node));///table node için yer ayırdık..
    if((*h)->tablo_basi==NULL){
       printf(" Hash tablosu icin yer ayrilamnadi... Hata!!!");
       exit(1);
    }
    (*h)->multipler=carpan; ///hash table degerlerini girdik..
    (*h)->eleman_sayisi=tablo_uzunlugu;
    for(int i=0;i<tablo_uzunlugu;i++)///table node değerlerini girdik...
    {
        ((*h)->tablo_basi+i)->counter=0;
        ((*h)->tablo_basi+i)->header=NULL;
    }
}
void printlist(struct CELL *a)///recursive olarak bağlı liste yazdıır.
{
    if(a!=NULL)
    {
        printf("%s",a->anahtar);
        printlist(a->next);
    }
}

void print_hash_table(struct hash_table *h)///hash tablosunu yazdıracagız içinde collisions olaylarından dogan
                                                ///listeler olabilir onlarıda bastıracagız...
{
    if(h)
{


    for(int i=0;i<h->eleman_sayisi;i++)
    {
        printf("%d:(%d)",i,(h->tablo_basi+i)->counter);
        printlist((h->tablo_basi+i)->header);///i. indexteki liste_basini printliste gönder iste onu bassın.
        ///listeyi bastıktan sonra 1 satir asagı kayıp 2 .indise gitsin..
        printf("\n");
    }
}
}

unsigned hash(char *anahtar,int multipler,int table_size)///hash fonksiyonudur işlevi değişebilir...
{
    unsigned int value=0;
    int i=0;
    while(anahtar[i])
    {
        value=(anahtar[i]+multipler*value)%table_size;
        i++;
    }
    return value;
}
int insert(char *anahtar,struct CELL **l)///çakışma olup olmadıgını varsa liste oluşturacagını bildirir
                                             ///  bunun için baglı listenin headerına ve eklşecegm değere ihtiyacim var ...
{
    if(*l==NULL)
    {
        ///sona ekleme mantıgı,,,
        (*l)=(struct CELL*)malloc(sizeof(struct CELL));///cell için bir yer ayırdım...
        (*l)->anahtar=(char*)malloc(sizeof(char)*strlen(anahtar)+1);///bu cellin içindekiler için yer ayırdım +1 '/0' için
        strcpy((*l)->anahtar,anahtar);///ekle;
        (*l)->next=NULL;
        return 1;
    }
    else if(strcmp(anahtar,(*l)->anahtar)) ///aynı ındex üretilmiş bir ileri git(baglı lıstenin bir sonrasına )....
                                                ///eger varsa 0 çıkar ve eklemez 1 çıkarsabir sonkine ekler..
        return insert(anahtar,&((*l)->next));
    else
        return 0;
}
void insert_hash_table(struct hash_table *h,char *anahtar)
{
    int h_inex=hash(anahtar,h->multipler,h->eleman_sayisi);///atıyorum "ankara" ekleyecegim bunun hangi indexe ekleneceğini bulur

    ///çakışma olup olmamasını kontrol ederrr
    if(insert(anahtar,&((h->tablo_basi+h_inex)->header)))///eklemişsem countu bir arttır
       ( h->tablo_basi+h_inex)->counter++;
}
int delete_sil(struct CELL **h, char *silinecek)///silecegimizin indexinde farklı farklı uyeler buunabilir...
{
    struct CELL *simdiki,*onceki;///node silme gini düşün baglı liste
    simdiki=*h;
    while(simdiki!=NULL && strcmp(silinecek,simdiki->anahtar))///silinecek şimdikide yoksailerlett bulana kadarrr
                                                                    ///bunun için 1 dönmeli 0 dönerse eşit olur ve alta girmez bulmuştur..
    {
        onceki=simdiki;
        simdiki=simdiki->next;
    }
    if(!simdiki)
        return 0;
    if(simdiki==*h)///liste başındadır..
    {
        (*h)=(*h)->next;

    }
    else
    {
        onceki->next=simdiki->next;
    }

    ///maloocla ayırdıgımız yerlerin hepsini silmeliyiz...

    free(simdiki->anahtar);
    free(simdiki);
    return 1;

}

void delete_hash_table(struct hash_table *h,char *silinen)
{
    int h_index=hash(silinen,h->multipler,h->eleman_sayisi);
    if(delete_sil((&(h->tablo_basi+h_index)->header),silinen))
        (h->tablo_basi+h_index)->counter--;
}
void liste_yok_et(struct CELL **liste_basi){
    struct CELL *onceki;
    while(*liste_basi){/// bağli liste silme mantıgı gibii
        onceki=*liste_basi;
        *liste_basi=(*liste_basi)->next;
        free(onceki->anahtar);///fakat buradad da mallocla oluşturdugum her şeyi silmeliyim...
        free(onceki);
    }
}



void hash_table_yok_et(struct hash_table ** hash_table)///tablonun içinde bir şey kalmamayacak değişecegi için "**"...
{
   int index;
    if(*hash_table){
        for(index=0; index < (*hash_table)->eleman_sayisi ;index++)///sırayla indisleri gönderiyor ve o indisdeki listeleri siliyoruz..
            liste_yok_et(&((*hash_table)->tablo_basi+index)->header);
        free((*hash_table)->tablo_basi);///orada malloc ile oluşturdugum şeyleri de silmeliyim..
        free(*hash_table);
    }
    *hash_table=NULL;///en sonunda hepsini sildiğim içinnn hashtablom nullu göstermeliii
}

void hash_tablosu_genislet(struct hash_table **h,int yeniboyut,int yenicarpan)
{
    struct CELL *lb;
    struct hash_table *yeni_tablo;
    initialize_hashtable(yenicarpan,yeniboyut,&yeni_tablo);
    if(h)
        {
    for(int i=0;i<(*h)->eleman_sayisi;i++)
    {
       lb=((*h)->tablo_basi+i)->header;
        while(lb!=NULL)
        {

            insert_hash_table(yeni_tablo,lb->anahtar);
            lb=lb->next;
        }
    }
    hash_table_yok_et(h);
    *h=yeni_tablo;}
}





int main()
{
    struct hashtable *htable=NULL;
    initialize_hashtable(3,3,&htable);
    //print_hash_table(htable);
    insert_hash_table(htable,"kadayif");
    insert_hash_table(htable,"Trabzonspor");
    insert_hash_table(htable,"kadayif");
    insert_hash_table(htable,"gundogdu");
    insert_hash_table(htable,"besiktas");
    insert_hash_table(htable,"baklava");
    insert_hash_table(htable,"dembaba");
    insert_hash_table(htable,"cardoza");
    //print_hash_table(htable);
    //delete_hash_table(htable,"besiktas");
    print_hash_table(htable);
   //hash_table_yok_et(&htable);
    //print_hash_table(htable);
    hash_tablosu_genislet(&htable,10,10);
    print_hash_table(htable);

    return 0;
}
