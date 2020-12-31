#include <stdio.h>
#include <stdlib.h>


int main() {
  int n;
  scanf("%d", &n);
  char *p1;
	
  p1 = (char*)malloc(n * sizeof(char));
	int i=0;
  for (i = 0; i < n; i++){
	printf("%d",i); 
  	scanf("%c", p1[i]);
  	
  }
    
	
  int counter = 0;
  int sea_lvl = 0;

  for (i = 0; i < n; i++) {

    if (*(p1 + i) == 'U')
      ++sea_lvl;
    if (*(p1 + i) == 'D')
      --sea_lvl;

    if (sea_lvl == 0 && *(p1 + i) == 'U')
      ++counter;
  }
  printf("%d",counter);

  return 0;
}


