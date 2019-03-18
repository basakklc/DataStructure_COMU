struct dugum
{
    int icerik;
    struct dugum *right,*left;
};

struct ikili_Arama_Agaci
{
    struct dugum *kok;
};

//Yaprak silme..
void yaprak_sil(struct dugum **kok)
{
    struct dugum *a;
    a=*kok;
    if(*kok==NULL)
        return;


    if((*kok)->left == NULL && (*kok)->right == NULL)
    {

      //  free(*kok);

        yaprak_sil(&(*kok)->left);

        yaprak_sil(&(*kok)->right);
         free(*kok);


        *kok=NULL;




    }

    else
    {
        yaprak_sil(&(*kok)->left);

        yaprak_sil(&(*kok)->right);
    }

}

void preorderYardimci(struct dugum *kok)
{
    if(kok!=NULL)  ///if(kok==NULL) return;
    {
        printf("%d\n",kok->icerik);
        preorderYardimci(kok->left);
        preorderYardimci(kok->right);
    }
}

void preorder(struct ikili_Arama_Agaci *agac)
{
    if(agac->kok==NULL)
        return;
    else
        preorderYardimci(agac->kok);
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
    yaprak_sil(agac);
    preorder(agac);
}


