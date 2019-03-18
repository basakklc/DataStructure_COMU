struct dugum
{
    int icerik;
    struct dugum *right,*left;
};

struct ikili_Arama_Agaci
{
    struct dugum *kok;
};



//Düğümün değeri tekse tek düğüm kabul et ve bunun sayısını bul..
int tekDugumSayiyiHesapla(struct dugum *kok)
{
    if(kok==NULL)
        return 0;

    if((kok->icerik)%2==0)
        return tekDugumSayiyiHesapla(kok->left)+tekDugumSayiyiHesapla(kok->right);

    else
        return 1+tekDugumSayiyiHesapla(kok->left)+tekDugumSayiyiHesapla(kok->right);

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
    printf("%d\n",tekDugumSayiyiHesapla(agac->kok));
   
}


