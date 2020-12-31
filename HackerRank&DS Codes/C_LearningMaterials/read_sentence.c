#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int i = 4;
    double d = 4.0;
    char s[] = "HackerRank ";
    int x;
    double y;
    char name[100];
    scanf("%d", &x);
    scanf("%lf", &y);
    scanf(" %[^\n]s", name);
    printf("%d\n", (i + x));
    printf("%.1lf\n", (y + d));
    printf("%s", s);
    printf("%s", name);

    return 0;
}
