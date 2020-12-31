#include <stdio.h>

int age_func(int age)
{
    //Deðerlerimizi tanýmladýk
    int i,sayi,j,max;
    scanf("%d",&age);
    int arr[age];
    int max_counter = 0;
    //Burada amaç diziye(pastaya) çocuðun yaþý kaçsa o kadar mum eklemek
    i=0;
    while (i < age)
    {
        scanf("%d",&sayi);
        arr[i]=sayi;
        i++;
    }
    //Burada max deðeri ayýklamak için ayrý bir döngü açýyoruz
    max = arr[0];
    j=0;
    while (j < age)
    {
        if (arr[j] > max){
            max = arr[j];
        }
    j++;
    }
    //Ayýkladýðýmýz maximum büyüklükteki mumlarý sayaç yardýmýyla sayýyoruz
    i=0;
    while (i < age)
    {
        if (max == arr[i]){
            max_counter = max_counter + 1;
        }
    i++;
    }
    printf("%d",max_counter);
    return max_counter;
}

int main()
{
    int max_counter;
    age_func(max_counter);

}

