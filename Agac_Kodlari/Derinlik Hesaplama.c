struct dugum
{
    int icerik;
    struct dugum *right,*left;
};

struct ikili_Arama_Agaci
{
    struct dugum *kok;
};

//Ağacın Derinliğini Hesaplama
int derinlik(struct dugum * root)              

{

    if (root==NULL)

    {

        return -1;

    }
    else
    {

        int lDepth = derinlik(root->left);

        int rDepth = derinlik(root->right);

        if (lDepth > rDepth)

            return(lDepth+1);

        else
            return(rDepth+1);

    }

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
    printf("%d\n",derinlik(agac->kok));
}


