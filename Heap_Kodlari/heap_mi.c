#include <stdio.h>
#include <stdlib.h>

int heap_mi(int a[],int last_index)
{
    int l=last_index;
    int parent=(last_index-1)/2;
    int sol=2*parent+1;
    int sag=2*parent+2;
    int count2=0;
    int count=0;
    while(parent>0)
    {
        if(a[parent]<a[sol] && a[parent]<a[sag]) ///min heap
        {

            count=count+1;

        }

        if(a[parent]>a[sol] && a[parent]>a[sag])
        {

            count2=count2+1;

        }
        last_index=last_index-2;
            parent=(last_index-1)/2;
            sol=2*parent+1;
            sag=2*parent+2;


    }
    if(count2==(l-1)/2 || count==(l-1)/2)
    {
       // printf("fghj");
        return 1;
    }

    else
        return 0;


}
int main()
{
   int a[]={20,50,60,230,220,70,80,200,210,240};
   printf("%d  ",heap_mi(a,9));
}
