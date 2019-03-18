#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct CELL {
    char *anahtar;
    struct CELL *next;
};

struct table_node{
    int counter;
    struct CELL *header;
};

struct hash_tablosu{
    struct table_node *tablo_basi;
    int tablo_uzunlugu;
    int multiplier;
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

unsigned hash(char *anahtar, int multiplier, int table_size){
    int i=0;
    unsigned int value=0;
    while(anahtar[i]){
        value = (anahtar[i]+multiplier*value)% table_size;
        i++;
    }
    return value;
}

void initialize_hash_table(struct hash_tablosu **hash_table,int multiplier, int table_size){
    int i;
    *hash_table=(struct hash_tablosu*)malloc(sizeof(struct hash_tablosu));
   if(*hash_table==NULL){
       printf(" Hash tablosu icin yer ayrilamnadi... Hata!!!");
       exit(1);
   }
    (*hash_table)->tablo_basi=(struct table_node *)malloc(table_size*sizeof(struct table_node));
    if((*hash_table)->tablo_basi==NULL){
       printf(" Hash tablosu icin yer ayrilamnadi... Hata!!!");
       exit(1);
    }
    (*hash_table)->tablo_uzunlugu= table_size;
    (*hash_table)->multiplier= multiplier;

    for(i=0; i<table_size; i++){
        ((*hash_table)->tablo_basi+i)->counter = 0;
        ((*hash_table)->tablo_basi+i)->header = NULL;
    }
}



void insert_hash_table(struct hash_tablosu *hash_table,char *anahtar){
    int hash_index = hash(anahtar, hash_table->multiplier,
            hash_table->tablo_uzunlugu);
    if(insert(anahtar,&((hash_table->tablo_basi +hash_index)->header)))
     (hash_table->tablo_basi +hash_index)->counter++;
}


void print_list(struct CELL *l){
    if(l!=NULL){
        printf("%s ", l->anahtar);
        print_list(l->next);
    }

}

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


////Hash Tablosunun aynı olup olmadığını bulma....
int aynimi(struct hash_tablosu *h1, struct hash_tablosu *h2)
{
    int cik;
    struct CELL *liste_basi;
    struct CELL *liste_basi2;
    struct CELL *a,*b;
    if(h1->tablo_uzunlugu!=h2->tablo_uzunlugu)
        return 0;
    for(int i=0;i<h1->tablo_uzunlugu;i++)
    {
        liste_basi=(h1->tablo_basi+i)->header;
        liste_basi2=(h2->tablo_basi+i)->header;
        a=liste_basi;
        b=liste_basi2;

        if(a==NULL && b==NULL)
        {
            cik=1;
            continue;
        }
        while(a!=NULL && b!=NULL )
        {

            if(strcmp(a->anahtar,b->anahtar))
            {
                cik=0;
                break;

            }
            else
            {
                cik=1;
                a=a->next;
                b=b->next;
                continue;
            }
        }

        if(cik==0)
            break;
    }
    if(cik==1)
        return 1;
    else
        return 0;




}
//---------------------------------------------------------------------------//

int main(int argc, char** argv) {
    struct hash_tablosu *htable=NULL;
    initialize_hash_table(&htable,3,3);

    insert_hash_table(htable,"aaaa");
   
    insert_hash_table(htable,"sasa");
    insert_hash_table(htable,"lallla");
    insert_hash_table(htable,"baabab");
    insert_hash_table(htable,"qqee");
    insert_hash_table(htable,"llll");
    print_hash_table(htable);

    struct hash_tablosu *htable2=NULL;
    initialize_hash_table(&htable2,3,3);
    insert_hash_table(htable2,"aaaaa");
    insert_hash_table(htable2,"sasa");
    insert_hash_table(htable2,"lallla");
    insert_hash_table(htable2,"baabab");
    insert_hash_table(htable2,"");
    insert_hash_table(htable2,"qqee");
    insert_hash_table(htable2,"llll");
    print_hash_table(htable2);
    printf("\n\n");
    printf("%d",aynimi(htable,htable2));


}
