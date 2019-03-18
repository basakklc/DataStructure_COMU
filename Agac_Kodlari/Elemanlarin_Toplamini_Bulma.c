struct dugum
{
    int icerik;
    struct dugum *right,*left;
};

struct ikili_Arama_Agaci
{
    struct dugum *kok;
};



//Ağaçtaki elemanları toplama..
int toplam(struct dugum *a)
{
    if(a==NULL)
        return 0;
    /* if(a->left==NULL || a->right ==NULL)
        return toplam2=toplam2+(a->icerik);*/
    return toplam(a->left)+toplam (a->right)+a->icerik;


}


int main(int argc, char** argv)
{
    struct ikili_Arama_Agaci *agac=NULL;
    ikili_Arama_Agaci_Olustur(&agac);
    struct dugum agac2;


    ekle(agac,200);
    ekle(agac,10);
    ekle(agac,30);
    ekle(agac,40);
    ekle(agac,202);
    ekle(agac,52);
    ekle(agac,150);
    printf("%d\n",toplam(agac->kok));
   
}


