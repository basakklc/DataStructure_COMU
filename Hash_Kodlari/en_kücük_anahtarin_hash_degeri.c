//Hash tablosundaki en küçük anahtarın hash değeri..
 //ascii tablosuna göre(sıralama..) 

#include <stdio.h>
#include <stdlib.h>
#include<string.h>



struct CELL {
    char *anahtar;
    struct CELL *next;
};

int insert(char *anahtar, struct CELL **l){
    if(*l==NULL){
        *l=(struct CELL*)malloc(sizeof(struct CELL));
        (*l)->anahtar=(char*)malloc((strlen(anahtar)+1)*sizeof(char));
        strcpy((*l)->anahtar,anahtar);
        (*l)->next=NULL;
        return 1;
    }
    else if(strcmp(anahtar,(*l)->anahtar))
        return insert(anahtar, &((*l)->next));
    else return 0;
}

//---------------------------------------------------------------------------//

void print_list(struct CELL *l){
    if(l!=NULL){
        printf("%s ", l->anahtar);
        print_list(l->next);
    }

}

//---------------------------------------------------------------------------//

struct table_node{
    int counter;
    struct CELL *header;
};

//---------------------------------------------------------------------------//

struct hash_tablosu{
    struct table_node *tablo_basi;
    int tablo_uzunlugu;
    int multiplier;
};

//---------------------------------------------------------------------------//

unsigned hash(char *anahtar, int multiplier, int table_size){
    int i=0;
    unsigned int value=0;
    while(anahtar[i]){
        value = (anahtar[i]+multiplier*value)% table_size;
        i++;
    }
    return value;
}

//---------------------------------------------------------------------------//


void insert_hash_table(struct hash_tablosu *hash_table,char *anahtar){
    int hash_index = hash(anahtar, hash_table->multiplier,
            hash_table->tablo_uzunlugu);
    if(insert(anahtar,&((hash_table->tablo_basi +hash_index)->header)))
     (hash_table->tablo_basi +hash_index)->counter++;
}

//---------------------------------------------------------------------------//

void print_hash_table(struct hash_tablosu *hash_table){
    if(hash_table){
        int index;
        printf("----- HASH TABLOSU -----\n");
        for(index=0; index<hash_table->tablo_uzunlugu; index++){
            printf("%d : (%d) ",index,(hash_table->tablo_basi +index)->counter);
            print_list((hash_table->tablo_basi+index)->header);
            printf("\n");
        }
    }
    //else printf("Hash Tablosu Bos ...\n");
}



void en_kucuk_anahtar_hash_degeri(struct hash_tablosu *h)
{
    struct CELL *liste_basi,*a,*b,*c;
    char kucuk[]="z";

    int indis;

    for(int i=0;i<h->tablo_uzunlugu;i++)
    {
       liste_basi=(h->tablo_basi+i)->header;
       a=liste_basi;
       for(int j=0;j<(h->tablo_basi+i)->counter;j++)
       {
            if( strcmp(kucuk,a->anahtar)>0)
            {

                strcpy( kucuk,a->anahtar);

            }
            a=a->next;



       }
      // continue;


    }
    int h_index=hash(kucuk,3,3);
    printf("%s ",kucuk);
    printf("%d",h_index);



}

int main(int argc, char** argv) {
    struct hash_tablosu *htable=NULL;
    struct hash_tablosu *hatable=NULL;

    initialize_hash_table(&htable,3,3);
    print_hash_table(htable);
    insert_hash_table(htable,"ali");
    insert_hash_table(htable,"Ayşe");
    insert_hash_table(htable,"Fatma");
    insert_hash_table(htable,"AA");
    insert_hash_table(htable,"Ahmet");
    insert_hash_table(htable,"İSTANBUL");
    insert_hash_table(htable,"baklava");
    insert_hash_table(htable,"ssss");
    insert_hash_table(htable,"kkk");
    print_hash_table(htable);
    en_kucuk_anahtar_hash_degeri(htable);


}




















