#include <stdio.h>
#include <stdlib.h>

int main() {
  int n, *arr, i, j, res = 0;
  scanf("%d", &n);

  arr = (int *)malloc((n + 1) * sizeof(int));
  for (i = 1; i <= n; i++)
    scanf("%d", arr + i);

  for (i = 1; i <= n; i++) {

    for (j = 1; j <= n; j++) {

      if (arr[arr[j]] == i)
        printf("%d\n", j);
    }
  }

  return 0;
}
