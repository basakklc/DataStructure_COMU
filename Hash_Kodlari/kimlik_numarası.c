//Bir hash fonksiyonuna Tc kimlik numarası ve sondan kaç karakter alacaksak o değerde bir sayıgiriliyor ve size tc kimlik numarasının sonundan itibaren o sayıda kadar alıp değer gönderiyor.
 //Örneğin hash(“1235678945”,3) değerlerini gönderdiğiniz zaman 549 değeri göndermeli. 

int hash(char *tc,int kuvvet)
{

  char *b;
  b=(char *)malloc(sizeof(char)*kuvvet);
  int j=0;
  for(int a=strlen(tc)-1;a>strlen(tc)-1-kuvvet;a--)
  {
      b[j]=tc[a];
      j=j+1;

  }

  return atoi(b);
}



int main()
{
  int sayi;
  char *b;
  printf("tc kimik no girin :");
   b=(char *)malloc(sizeof(char)*11);
  scanf("%s",b);
sayi=hash(b,3);
  printf("%d",sayi);


}

