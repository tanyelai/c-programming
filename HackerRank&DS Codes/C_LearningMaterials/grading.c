#include <stdio.h>
#include <math.h>
// Yazılması beklenen algoritmik program.
int main()
{
    //Öğrenci sayısı alınır.
    int studentNumber;
    scanf("%d",&studentNumber);
    int i,sayi,arr[studentNumber],res[studentNumber];

    //öğrencilerin notları girilir.
    i=0;
    while (i < studentNumber)
    {
        scanf("%d",&sayi);
        arr[i]= sayi;
    i++;
    }

    //notlar karşılaştırılır ve yuvarlamalar yapılır.
    i=0;
    while (i < studentNumber)
    {
        if (arr[i] % 5 > 2 && !(arr[i] < 38)){
            res[i]= arr[i] + (5 - arr[i] % 5);
        }
        else{
            res[i]= arr[i];
        }
        printf("%d\n",res[i]);
    i++;

    }
}

