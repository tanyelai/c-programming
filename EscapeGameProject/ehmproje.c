#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define SIZE 100


int main ()
{
	int N=4,M=2,a,n,sum=0;
	int sayace=0,sayacE=0,sayacp=0,sayacP=0;
	int X,pointPl=0;
	char arr[6][10] = {{'e','K','1','0','0','p','0','1','0','C'},{'0','0','p','0','0','1','0','1','0','1'},{'E','1','0','E','0','K','e','1','E','1'},{'0','0','1','1','e','0','0','p','0','K'},{'1','0','G','1','0','1','P','1','1','e'},{'1','P','0','p','K','0','0','E','0','0'}};
	char points[SIZE];


	int i=0,j=0;
	while (1)
	{
		
		
		arr[4][2]='G';
		
		arr [N][M] = 'X';
		for (i=0 ; i<6 ; i++){
			for (j=0 ; j<10 ; j++){
				printf("%c ",arr[i][j]);
			}
			printf("\n");
		}
	 

	
		a = getch();

	
		if ( a == 77 ){ //Sað
			if(M!=9){
				M++;
					if (arr[N][M] == '1')
					M--;
					else
					arr[N][M-1]='0';
			}
		}
		if ( a == 75 ){ //Sol
			if(M!=0){
				M--;
					if (arr[N][M] == '1')
					M++;
					else
					arr[N][M+1]='0';
			}
		}
		
		if ( a == 72 ){ //Yukarý
			if(N!=0){
				N--;
					if (arr[N][M] == '1')
					N++;
					else
					arr[N+1][M]='0';
			}
		}
	
		if ( a == 80 ){ //Aþaðý
			if(N!=5){
				N++;
					if (arr[N][M] == '1')
					N--;
					else
					arr[N-1][M]='0';
			}
		}
		
		if ( arr[N][M] == 'e')
		{
			points[pointPl]='e';
			sayace++;	
			pointPl++;
			for (n=0; n<pointPl; n++){
				printf("  %c",points[n]);
			}                            
			
					
		}
		if ( arr[N][M] == 'E')
		{
			points[pointPl]='E';
			sayacE++;
			pointPl++;
			for (n=0; n<pointPl; n++){
				printf("  %c",points[n]);
			}
			
		}
		if ( arr[N][M] == 'p')
		{
			points[pointPl]='p';
			sayacp++;
			pointPl++;
			for (n=0; n<pointPl; n++){
				printf("  %c",points[n]);
			}
			
		}
		if ( arr[N][M] == 'P')
		{
			points[pointPl]='P';
			sayacP++;
			pointPl++;
			for (n=0; n<pointPl; n++){
				printf("  %c",points[n]);
			}
			
		}
		if ( arr[N][M] == 'K')
		{
			printf("Kaybettiniz.");
			break;
		}
		if ( a == 27)
		{
			printf("Cikis yaptiniz.");
			break;
		}
		if (arr[0][9]== 'X'){
		printf("\nKazandiniz.");
		break;
		}
		
		sleep(1);
		system("cls");  
		
		
		
	}
	
	
	while(sayace!=0 && sayacp!=0){
		sayace--;
		sayacp--;
		sum++;
		
	}
	while(sayacE!=0 && sayacP!=0){
		sayacE--;
		sayacP--;
		sum++;
		
	}
	
	
	printf("\nSkorunuz: %d",sum);
	
	



	return 0;
}
