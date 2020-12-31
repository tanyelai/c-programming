#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
// OYUN INTERAKTIF OLARAK KULLANICI TARAFINDAN OYNANMAKTADIR // OK TUSLARI VE SPACE ( DONDURME ) // 

int main(){
	char arr[12][10] = {{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'},{'O','O','O','O','O','O','O','O','O','O'}};
	int sekil_no, anlik_satir, anlik_sutun, dondurme_kontrol=0, flag=1,i,j,t, islem, counter_deleter=0,flag2,dondurme_kontrol_L,secim=0,score[10],skor=0,k=0,point=0,point_counter=0,temp;


	printf("TETRIS OYUNUNA HOS GELDINIZ\n\n");
	while ( secim != 4 ){
		printf("\n1-Oyna\n");
		printf("2-Skor Tablosu\n");
		printf("3-Bilgilendirme\n");
		printf("4-Cikis\nSecim: ");
		scanf("%d",&secim);
		switch ( secim ){
			case 1:
				system("cls");
				for(i=0; i<12; i++){
					for(j=0; j<10; j++){
						arr[i][j] = 'O';
					}
				}
				skor=0;
				while(1)
	{
	//   SHAPES
	// Her yıldız (*) birim kutuyu temsil etmektedir. 
	// Karakter olan büyük o (O) matristeki boşlukları temsil etmektedir. 
	
	if(flag==1){
		srand(time(NULL));
		sekil_no = 1+rand()%6;
		if ( sekil_no == 1){ //// 1 birim kare
			if ( arr[0][5] != '*' && arr[0][0] != '*' && arr[0][1]!= '*' && arr[0][2]!= '*' && arr[0][3]!= '*' && arr[0][4]!= '*' && arr[0][6]!= '*' && arr[0][7]!= '*' && arr[0][8]!= '*' && arr[0][9]!= '*' && arr[0][10]!= '*'){
				arr[0][5] = '*';
				anlik_satir = 0;
				anlik_sutun = 5;
			}
			else {
				printf("Kaybettiniz. Skorunuz: %d",skor); 
				score[k]=skor;
				k++;
				break;
			}
			
		}
		if ( sekil_no == 2){ //// 2'li çizgi
			if ( arr[0][5] != '*' && arr[1][5] != '*' && arr[0][0] != '*' && arr[0][1]!= '*' && arr[0][2]!= '*' && arr[0][3]!= '*' && arr[0][4]!= '*' && arr[0][6]!= '*' && arr[0][7]!= '*' && arr[0][8]!= '*' && arr[0][9]!= '*' && arr[0][10]!= '*' ){
				arr[0][5] = '*';
				arr[1][5] = '*';
				anlik_satir = 1;
				anlik_sutun = 5;
			}
			else {
				printf("Kaybettiniz. Skorunuz: %d",skor);
				score[k]=skor;
				k++;
				break;
			}
			
		}
		if( sekil_no == 3 ){ //// 3'lü çizgi
			if (  arr[1][5] != '*' && arr[2][5] != '*' && arr[0][0] != '*' && arr[0][1]!= '*' && arr[0][2]!= '*' && arr[0][3]!= '*' && arr[0][4]!= '*'&& arr[0][5] != '*' && arr[0][6]!= '*' && arr[0][7]!= '*' && arr[0][8]!= '*' && arr[0][9]!= '*' && arr[0][10]!= '*' ){
				arr[0][5] = '*';
				arr[1][5] = '*';
				arr[2][5] = '*';
				anlik_satir = 2;
				anlik_sutun = 5;
			}
			else {
				printf("Kaybettiniz. Skorunuz: %d",skor);
				score[k]=skor;
				k++;
				break;
			}
			
		}
		if( sekil_no == 4 ){ //// 2 birim KARE 
			if ( arr[0][5] != '*' && arr[1][5] != '*' && arr[0][6] != '*' && arr[1][6] != '*' && arr[0][0] != '*' && arr[0][1]!= '*' && arr[0][2]!= '*' && arr[0][3]!= '*' && arr[0][4]!= '*' && arr[0][7]!= '*' && arr[0][8]!= '*' && arr[0][9]!= '*' && arr[0][10]!= '*'){
				arr[0][5] = '*';
				arr[1][5] = '*';
				arr[0][6] = '*';
				arr[1][6] = '*';
				anlik_satir = 1;
				anlik_sutun = 5;
			}
			else {
				printf("Kaybettiniz. Skorunuz: %d",skor);
				score[k]=skor;
				k++;
				break;
			}	
		}
		if( sekil_no == 5 ){ //// Z HARFI 
			if ( arr[0][4] != '*' && arr[0][5] != '*' && arr[1][5] != '*' && arr[1][6] != '*'&& arr[0][0] != '*' && arr[0][1]!= '*' && arr[0][2]!= '*' && arr[0][3]!= '*' && arr[0][6]!= '*' && arr[0][7]!= '*' && arr[0][8]!= '*' && arr[0][9]!= '*' && arr[0][10]!= '*'){
				arr[0][4] = '*';
				arr[0][5] = '*';
				arr[1][5] = '*';
				arr[1][6] = '*';
				anlik_satir = 0;
				anlik_sutun = 5;
			}
			else {
				printf("Kaybettiniz. Skorunuz: %d",skor);
				score[k]=skor;
				k++;
				break;
			}
		}
		if( sekil_no == 6 ){ //// L HARFI 
			if ( arr[0][5] != '*' && arr[1][5] != '*' && arr[2][5] != '*' && arr[2][6] != '*' && arr[0][0] != '*' && arr[0][1]!= '*' && arr[0][2]!= '*' && arr[0][3]!= '*' && arr[0][4]!= '*' && arr[0][6]!= '*' && arr[0][7]!= '*' && arr[0][8]!= '*' && arr[0][9]!= '*' && arr[0][10]!= '*' ){
				arr[0][5] = '*';
				arr[1][5] = '*';
				arr[2][5] = '*';
				arr[2][6] = '*';
				anlik_satir = 1;
				anlik_sutun = 5;
			}
			else {
				printf("Kaybettiniz. Skorunuz: %d",skor);
				score[k]=skor;
				k++;
				break;
			}
		}
		
	
			
		dondurme_kontrol_L = 0;
		dondurme_kontrol = 0;
	}
	

	for (i=0 ; i<12 ; i++){
			for (j=0 ; j<10 ; j++){
				printf("%c ",arr[i][j]);
				}
			printf("\n");	
		}	
		printf("\nSKORUNUZ: %d",skor);
	
	flag=0;
	islem = getch();
	/// DÖNDÜRME İŞLEMLERİ
	/// HEP SAAT YÖNÜNDE DÖNECEKTİR " SPACE TUŞU " KULLANILACAKTIR 
	if ( islem == 32 ){

		if ( sekil_no == 2 && dondurme_kontrol == 0 && anlik_sutun < 9 ){ //// 2'li çizgi
			if ( arr[anlik_satir][anlik_sutun+1] != '*' ){
				arr[anlik_satir-1][anlik_sutun] = 'O';
				arr[anlik_satir][anlik_sutun+1] = '*';	
				dondurme_kontrol++;	
				flag=0;	
			}
			else
				printf("Bu yone dondurulemez.");
		}
		else if (sekil_no == 2 && dondurme_kontrol == 1 ){
				arr[anlik_satir-1][anlik_sutun] = '*';
				arr[anlik_satir][anlik_sutun+1] = 'O';	
				dondurme_kontrol = 0;
				flag=0;	
			}
	
		
		
		
		if( sekil_no == 3 && dondurme_kontrol == 0 && anlik_sutun < 8  ){ //// 3'lü çizgi
			if ( arr[anlik_satir][anlik_sutun+1] != '*' && arr[anlik_satir][anlik_sutun+2] != '*' ){
				arr[anlik_satir-2][anlik_sutun] = 'O';
				arr[anlik_satir-1][anlik_sutun] = 'O';	
				arr[anlik_satir][anlik_sutun+1] = '*';
				arr[anlik_satir][anlik_sutun+2] = '*';
				dondurme_kontrol++;
				flag=0;
			}
		}
		else if ( sekil_no == 3 && dondurme_kontrol == 1  ) {
				arr[anlik_satir-2][anlik_sutun] = '*';
				arr[anlik_satir-1][anlik_sutun] = '*';	
				arr[anlik_satir][anlik_sutun+1] = 'O';
				arr[anlik_satir][anlik_sutun+2] = 'O';
				dondurme_kontrol = 0;
				flag=0;
			}
			
			
			
		if( sekil_no == 5 && dondurme_kontrol == 0 && anlik_satir > 0 && anlik_sutun > 0){ /////////// ZZZZZZ HARFI
			if ( arr[anlik_satir][anlik_sutun+1] != '*' && arr[anlik_satir-1][anlik_sutun+1] != '*' ){
				arr[anlik_satir][anlik_sutun-1] = 'O';
				arr[anlik_satir+1][anlik_sutun+1] = 'O';
				arr[anlik_satir-1][anlik_sutun+1] = '*';
				arr[anlik_satir][anlik_sutun+1] = '*';
				dondurme_kontrol++;
				flag=0;
				
			}
		}
		else if( sekil_no == 5 && dondurme_kontrol == 1 && anlik_satir > 0 && anlik_sutun > 0){
			if( arr[anlik_satir][anlik_sutun-1] != '*' && arr[anlik_satir+1][anlik_sutun+1] != '*' ){
				arr[anlik_satir][anlik_sutun-1] = '*';
				arr[anlik_satir+1][anlik_sutun+1] = '*';
				arr[anlik_satir-1][anlik_sutun+1] = 'O';
				arr[anlik_satir][anlik_sutun+1] = 'O';
				dondurme_kontrol++;
				flag=0;
			}	
		}
		
		
		
	
		if( sekil_no == 6 && dondurme_kontrol_L == 0 && anlik_sutun < 9 && anlik_sutun > 0 ){ ///////////   L  HARFI
			if ( arr[anlik_satir][anlik_sutun+1] != '*' && arr[anlik_satir-1][anlik_sutun+1] != '*' && arr[anlik_satir][anlik_sutun-1] != '*' ){
				arr[anlik_satir][anlik_sutun+1] = '*';
				arr[anlik_satir-1][anlik_sutun+1] = '*';
				arr[anlik_satir][anlik_sutun-1] = '*';
				arr[anlik_satir+1][anlik_sutun+1] = 'O';
				arr[anlik_satir+1][anlik_sutun] = 'O';
				arr[anlik_satir-1][anlik_sutun] = 'O';
				dondurme_kontrol_L++;
				flag=0;
			}
		}
		else if( sekil_no == 6 && dondurme_kontrol_L == 1 && anlik_sutun < 9 && anlik_satir > 0 && anlik_sutun > 0 ){ ///////////   L  HARFI
			if ( arr[anlik_satir+1][anlik_sutun] != '*' && arr[anlik_satir-1][anlik_sutun-1] != '*' && arr[anlik_satir-1][anlik_sutun] != '*'  ){
				arr[anlik_satir+1][anlik_sutun] = '*';
				arr[anlik_satir-1][anlik_sutun-1] = '*';
				arr[anlik_satir-1][anlik_sutun] = '*';
				arr[anlik_satir-1][anlik_sutun+1] = 'O';
				arr[anlik_satir][anlik_sutun-1] = 'O';
				arr[anlik_satir][anlik_sutun+1] = 'O';
				dondurme_kontrol_L++;
				flag=0;
			}
		}
		else if( sekil_no == 6 && dondurme_kontrol_L == 2 && anlik_sutun < 9 && anlik_satir > 0 && anlik_sutun > 0){ ///////////   L  HARFI
			if ( arr[anlik_satir][anlik_sutun+1] != '*' && arr[anlik_satir][anlik_sutun-1] != '*' && arr[anlik_satir+1][anlik_sutun-1] != '*'  ){
				arr[anlik_satir][anlik_sutun+1] = '*';
				arr[anlik_satir][anlik_sutun-1] = '*';
				arr[anlik_satir+1][anlik_sutun-1] = '*';
				arr[anlik_satir-1][anlik_sutun-1] = 'O';
				arr[anlik_satir-1][anlik_sutun] = 'O';
				arr[anlik_satir+1][anlik_sutun] = 'O';
				dondurme_kontrol_L++;
				flag=0;
			}
		}
		else if( sekil_no == 6 && dondurme_kontrol_L == 3 && anlik_sutun < 9 && anlik_satir>0 && anlik_sutun > 0 ){ ///////////   L  HARFI
			if ( arr[anlik_satir-1][anlik_sutun] != '*' && arr[anlik_satir+1][anlik_sutun+1] != '*' && arr[anlik_satir+1][anlik_sutun] != '*'  ){
				arr[anlik_satir-1][anlik_sutun] = '*';
				arr[anlik_satir+1][anlik_sutun+1] = '*';
				arr[anlik_satir+1][anlik_sutun] = '*';
				arr[anlik_satir][anlik_sutun-1] = 'O';
				arr[anlik_satir][anlik_sutun+1] = 'O';
				arr[anlik_satir+1][anlik_sutun-1] = 'O';
				dondurme_kontrol_L++;
				flag=0;
			}
		}
		
			
	if(dondurme_kontrol == 2)
		dondurme_kontrol = 0;
	if(dondurme_kontrol_L == 4)
		dondurme_kontrol_L = 0;
	
	}
	
		
	if ( islem == 77 ){  //Sağ OK
			if ( sekil_no == 1  ){
				if( arr[anlik_satir][anlik_sutun+1] != '*' && anlik_sutun < 9){
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun+1] = '*';
					anlik_sutun++;
					flag=0;
				}
				else
					printf("Bu yone gidemezsiniz.");
				
			}
			
			//// ŞEKİL 2 //////////
			
			if ( sekil_no == 2 && dondurme_kontrol == 0 ){ //// 2'li çizgi dikey
				if ( arr[anlik_satir][anlik_sutun+1] != '*' && arr[anlik_satir-1][anlik_sutun+1] != '*' && anlik_sutun < 9 ){
					arr[anlik_satir-1][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun+1] = '*';	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun+1] = '*';
					anlik_sutun++;
					flag=0;
				}
				else {
					printf("Bu yone gidemezsiniz.");
				}
			}
			if ( sekil_no == 2 &&  dondurme_kontrol == 1 ){ //// 2'li çizgi yatık
				if ( arr[anlik_satir][anlik_sutun+2] != '*' && anlik_sutun < 8  ){
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun+2] = '*';	
					anlik_sutun++;		
					flag=0;
				}
				else {
					printf("Bu yone gidemezsiniz.");
				}	
				
			
			}
			
			/////// ŞEKİL3 //////////
			if( sekil_no == 3 &&  dondurme_kontrol == 0 ){ //// 3'lü çizgi dikey
				if ( arr[anlik_satir][anlik_sutun+1] != '*' && arr[anlik_satir-1][anlik_sutun+1] != '*' && arr[anlik_satir-2][anlik_sutun+1] != '*' && anlik_sutun < 9 ){
					arr[anlik_satir-2][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun] = 'O';	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir-2][anlik_sutun+1] = '*';
					arr[anlik_satir-1][anlik_sutun+1] = '*';
					arr[anlik_satir][anlik_sutun+1] = '*';
					anlik_sutun++;
					flag=0;
				}
				else {
					printf("Bu yone gidemezsiniz.");
				}
			}
			if( sekil_no == 3 &&  dondurme_kontrol == 1  ){ //// 3'lü çizgi yatık
				if ( arr[anlik_satir][anlik_sutun+3] != '*' && anlik_sutun < 7 ){	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun+3] = '*';
					anlik_sutun++;
					flag=0;
				}
				else {
					printf("Bu yone gidemezsiniz.");
				}
				
			}
			
			if ( sekil_no == 4 && anlik_sutun < 8 ){
				if ( arr[anlik_satir][anlik_sutun+2] != '*' && arr[anlik_satir-1][anlik_sutun+2] != '*' ){
					arr[anlik_satir-1][anlik_sutun] = 'O';	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun+2] = '*';
					arr[anlik_satir][anlik_sutun+2] = '*';
					anlik_sutun++;
					flag=0;
				}
				else
					printf("Bu yone gidenemezsiniz.");
				
			}
			///////////// Z HARFI   ///////////
			if( sekil_no == 5 &&  dondurme_kontrol == 0  ){
				if ( arr[anlik_satir+1][anlik_sutun+2] != '*' && arr[anlik_satir][anlik_sutun+1] != '*' && anlik_sutun < 8 ){
					arr[anlik_satir][anlik_sutun-1] = 'O';	
					arr[anlik_satir+1][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun+1] = '*';
					arr[anlik_satir+1][anlik_sutun+2] = '*';
					anlik_sutun++;
					flag=0;
				}
				else
					printf("Bu yone gidenemezsiniz.");
			}
			if( sekil_no == 5 &&  dondurme_kontrol == 1  ){
				if ( arr[anlik_satir+1][anlik_sutun+1] != '*' && arr[anlik_satir][anlik_sutun+2] != '*' && arr[anlik_satir-1][anlik_sutun+2] != '*' && anlik_sutun < 8){
					arr[anlik_satir-1][anlik_sutun+1] = 'O';	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun+1] = '*';
					arr[anlik_satir-1][anlik_sutun+2] = '*';
					arr[anlik_satir][anlik_sutun+2] = '*';
					anlik_sutun++;
					flag=0;
				}
				else
					printf("Bu yone gidenemezsiniz.");
			}
			
			if( sekil_no == 6 && dondurme_kontrol_L == 0 ){ ///////////   L  HARFI
				if ( arr[anlik_satir][anlik_sutun+1] != '*' && arr[anlik_satir-1][anlik_sutun+1] != '*' && arr[anlik_satir+1][anlik_sutun+2] != '*' && anlik_sutun < 8 ){
					arr[anlik_satir][anlik_sutun+1] = '*';
					arr[anlik_satir-1][anlik_sutun+1] = '*';
					arr[anlik_satir+1][anlik_sutun+2] = '*';
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun] = 'O';
					anlik_sutun++;
					flag=0;
				}
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 1 ){ ///////////   L  HARFI
				if ( arr[anlik_satir][anlik_sutun+2] != '*' && arr[anlik_satir-1][anlik_sutun+2] != '*' && anlik_sutun < 8 ){
					arr[anlik_satir][anlik_sutun+2] = '*';
					arr[anlik_satir-1][anlik_sutun+2] = '*';
					arr[anlik_satir][anlik_sutun-1] = 'O';
					arr[anlik_satir-1][anlik_sutun+1] = 'O';
					anlik_sutun++;
					flag=0;
				}
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 2 ){ ///////////   L  HARFI
				if ( arr[anlik_satir-1][anlik_sutun+1] != '*' && arr[anlik_satir][anlik_sutun+1] != '*' && arr[anlik_satir+1][anlik_sutun+1] != '*' && anlik_sutun < 9 ){
					arr[anlik_satir-1][anlik_sutun+1] = '*';
					arr[anlik_satir][anlik_sutun+1] = '*';
					arr[anlik_satir+1][anlik_sutun+1] = '*';
					arr[anlik_satir-1][anlik_sutun-1] = 'O';
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun] = 'O';
					anlik_sutun++;
					flag=0;
				}
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 3 ){ ///////////   L  HARFI
				if ( arr[anlik_satir+1][anlik_sutun] != '*' && arr[anlik_satir][anlik_sutun+2] != '*' && anlik_sutun < 8 ){
					arr[anlik_satir+1][anlik_sutun] = '*';
					arr[anlik_satir][anlik_sutun+2] = '*';
					arr[anlik_satir+1][anlik_sutun-1] = 'O';
					arr[anlik_satir][anlik_sutun-1] = 'O';
					anlik_sutun++;
					flag=0;
				}
			}
			
			
			
			

			
		
	}	
	
	
	
	
	if ( islem == 75 ){ //Sol OK
		if ( sekil_no == 1 ){
				if( arr[anlik_satir][anlik_sutun-1] != '*' && anlik_sutun > 0 ){
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun-1] = '*';
					anlik_sutun--;
					flag=0;
				}
				else
					printf("Bu yone gidemezsiniz.");
				
			}
			
			//// ŞEKİL 2 //////////
			
			if ( sekil_no == 2 &&  dondurme_kontrol == 0 ){ //// 2'li çizgi dikey
				if ( arr[anlik_satir][anlik_sutun-1] != '*' && arr[anlik_satir-1][anlik_sutun-1] != '*' && anlik_sutun > 0  ){
					arr[anlik_satir-1][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun-1] = '*';	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun-1] = '*';
					anlik_sutun--;
					flag=0;
				}
				else {
					printf("Bu yone gidemezsiniz.");
				}
			}
			if ( sekil_no == 2 &&  dondurme_kontrol == 1 ){ //// 2'li çizgi yatık
				if ( arr[anlik_satir][anlik_sutun-1] != '*' && anlik_sutun > 0  ){
					arr[anlik_satir][anlik_sutun-1] = '*';
					arr[anlik_satir][anlik_sutun+1] = 'O';	
					anlik_sutun--;		
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
				
				
			
			}
			
			/////// ŞEKİL3 //////////
			if( sekil_no == 3 && dondurme_kontrol == 0 ){ //// 3'lü çizgi dikey
				if ( arr[anlik_satir][anlik_sutun-1] != '*' && arr[anlik_satir-1][anlik_sutun-1] != '*' && arr[anlik_satir-2][anlik_sutun-1] != '*' && anlik_sutun > 0  ){
					arr[anlik_satir-2][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun] = 'O';	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir-2][anlik_sutun-1] = '*';
					arr[anlik_satir-1][anlik_sutun-1] = '*';
					arr[anlik_satir][anlik_sutun-1] = '*';
					anlik_sutun--;
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
				
			}
			if( sekil_no == 3 && dondurme_kontrol == 1  ){ //// 3'lü çizgi yatık
				if ( arr[anlik_satir][anlik_sutun-1] != '*' && anlik_sutun > 0 ){	
					arr[anlik_satir][anlik_sutun+2] = 'O';
					arr[anlik_satir][anlik_sutun-1] = '*';
					anlik_sutun--;
					flag=0;
				}
				else {
					printf("Bu yone gidemezsiniz.");
				}
				
			}
			
			if ( sekil_no == 4 ){
				if ( arr[anlik_satir][anlik_sutun-1] != '*' && arr[anlik_satir-1][anlik_sutun-1] != '*' && anlik_sutun > 0){
					arr[anlik_satir-1][anlik_sutun+1] = 'O';	
					arr[anlik_satir][anlik_sutun+1] = 'O';
					arr[anlik_satir-1][anlik_sutun-1] = '*';
					arr[anlik_satir][anlik_sutun-1] = '*';
					anlik_sutun--;
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
				
			}
			
			if ( sekil_no == 5 && dondurme_kontrol == 0 ){
				if (  arr[anlik_satir][anlik_sutun-2] != '*' && arr[anlik_satir+1][anlik_sutun-1] != '*' && anlik_sutun > 1  ){
					arr[anlik_satir][anlik_sutun] = 'O';	
					arr[anlik_satir+1][anlik_sutun+1] = 'O';
					arr[anlik_satir+1][anlik_sutun-1] = '*';
					arr[anlik_satir][anlik_sutun-2] = '*';
					anlik_sutun--;
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
			}
			if ( sekil_no == 5 && dondurme_kontrol == 1 ){
				if (  arr[anlik_satir-1][anlik_sutun] != '*' && arr[anlik_satir][anlik_sutun-1] != '*' && arr[anlik_satir+1][anlik_sutun-1] != '*' && anlik_sutun > 0  ){
					arr[anlik_satir-1][anlik_sutun+1] = 'O';	
					arr[anlik_satir][anlik_sutun+1] = 'O';
					arr[anlik_satir+1][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun] = '*';
					arr[anlik_satir][anlik_sutun-1] = '*';
					arr[anlik_satir+1][anlik_sutun-1] = '*';
					anlik_sutun--;
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
			}
			
			if( sekil_no == 6 && dondurme_kontrol_L == 0 ){ ///////////   L  HARFI
				if ( arr[anlik_satir][anlik_sutun-1] != '*' && arr[anlik_satir-1][anlik_sutun-1] != '*' && arr[anlik_satir+1][anlik_sutun-1] != '*' && anlik_sutun > 0){
					arr[anlik_satir][anlik_sutun-1] = '*';
					arr[anlik_satir-1][anlik_sutun-1] = '*';
					arr[anlik_satir+1][anlik_sutun-1] = '*';
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun+1] = 'O';
					anlik_sutun--;
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 1 ){ ///////////   L  HARFI
				if ( arr[anlik_satir][anlik_sutun-2] != '*' && arr[anlik_satir-1][anlik_sutun] != '*' && anlik_sutun > 1 ){ 
					arr[anlik_satir][anlik_sutun-2] = '*';
					arr[anlik_satir-1][anlik_sutun] = '*' ;
					arr[anlik_satir][anlik_sutun+1] = 'O';
					arr[anlik_satir-1][anlik_sutun+1] = 'O';
					anlik_sutun--;
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 2 ){ ///////////   L  HARFI
				if ( arr[anlik_satir-1][anlik_sutun-2] != '*' && arr[anlik_satir][anlik_sutun-1] != '*' && arr[anlik_satir+1][anlik_sutun-1] != '*' && anlik_sutun > 1 ){ 
					arr[anlik_satir-1][anlik_sutun-2] = '*';
					arr[anlik_satir][anlik_sutun-1] = '*';
					arr[anlik_satir+1][anlik_sutun-1] = '*';
					arr[anlik_satir-1][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun] = 'O';
					anlik_sutun--;
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 3 ){ ///////////   L  HARFI
				if ( arr[anlik_satir][anlik_sutun-2] = '*' && arr[anlik_satir+1][anlik_sutun-2] != '*'  && anlik_sutun > 1 ){
					arr[anlik_satir][anlik_sutun-2] = '*';
					arr[anlik_satir+1][anlik_sutun-2] = '*';
					arr[anlik_satir][anlik_sutun+1] = 'O';
					arr[anlik_satir+1][anlik_sutun-1] = 'O';
					anlik_sutun--;
					flag=0;
				}
				else 
					printf("Bu yone gidemezsiniz.");
			}
			
	}
	
	
	
	
	if ( islem == 80 ){ //Aşağı OK 
			if ( sekil_no == 1 ){
				if( arr[anlik_satir+1][anlik_sutun] != '*' && anlik_satir < 11){
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun] = '*';
					anlik_satir++;
					flag=0;
				}
				else
					flag=1;
				
			}
			
			//// ŞEKİL 2 //////////
			
			if ( sekil_no == 2 &&  dondurme_kontrol == 0  ){ //// 2'li çizgi dikey
				if ( arr[anlik_satir+1][anlik_sutun] != '*' &&  anlik_satir < 11 ){
					arr[anlik_satir-1][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun] = '*';	
					anlik_satir++;
					flag=0;
				}
				else {
					flag=1;
				}
			}
			if ( sekil_no == 2 &&  dondurme_kontrol == 1 ){ //// 2'li çizgi yatık
				if ( arr[anlik_satir+1][anlik_sutun+1] != '*' && arr[anlik_satir+1][anlik_sutun] != '*' && anlik_satir < 11  ){
					arr[anlik_satir+1][anlik_sutun] = '*';
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun+1] = '*';
					arr[anlik_satir][anlik_sutun+1] = 'O';	
					anlik_satir++;	
					flag=0;	
				}
				else {
					flag=1;	
				}	
				
			
			}
			
			/////// ŞEKİL3 //////////
			if( sekil_no == 3 &&  dondurme_kontrol == 0 ){ //// 3'lü çizgi dikey
				if ( arr[anlik_satir+1][anlik_sutun] != '*'  && anlik_satir < 11 ){
					arr[anlik_satir+1][anlik_sutun] = '*';
					arr[anlik_satir-2][anlik_sutun] = 'O';
					anlik_satir++;
					flag=0;
				}
				else {
					flag=1;
				}
			}
			if( sekil_no == 3 &&  dondurme_kontrol == 1 ){ //// 3'lü çizgi yatık
				if ( arr[anlik_satir+1][anlik_sutun] != '*' && arr[anlik_satir+1][anlik_sutun+1] != '*' && arr[anlik_satir+1][anlik_sutun+2] != '*' && anlik_satir < 11 ){	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir][anlik_sutun+1] = 'O';	
					arr[anlik_satir][anlik_sutun+2] = 'O';
					arr[anlik_satir+1][anlik_sutun] = '*';
					arr[anlik_satir+1][anlik_sutun+1] = '*';
					arr[anlik_satir+1][anlik_sutun+2] = '*';
					anlik_satir++;
					flag=0;
				}
				else {
					flag=1;
				}
				
			}
			
			if ( sekil_no == 4 ){
				if ( arr[anlik_satir+1][anlik_sutun] != '*' && arr[anlik_satir+1][anlik_sutun+1] != '*' && anlik_satir < 11 ){
					arr[anlik_satir-1][anlik_sutun] = 'O';	
					arr[anlik_satir-1][anlik_sutun+1] = 'O';
					arr[anlik_satir+1][anlik_sutun] = '*';
					arr[anlik_satir+1][anlik_sutun+1] = '*';
					anlik_satir++;
					flag=0;
				}
				else
					flag=1;
				
			}
			
			if ( sekil_no == 5 && dondurme_kontrol == 0 ){
				if (  arr[anlik_satir+1][anlik_sutun-1] != '*' && arr[anlik_satir+2][anlik_sutun] != '*' && arr[anlik_satir+2][anlik_sutun+1] != '*' && anlik_satir < 10 ){
					arr[anlik_satir][anlik_sutun-1] = 'O';	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun+1] = 'O';
					arr[anlik_satir+1][anlik_sutun-1] = '*';
					arr[anlik_satir+2][anlik_sutun] = '*';
					arr[anlik_satir+2][anlik_sutun+1] = '*';
					anlik_satir++;
					flag=0;
				}
				else
					flag=1;
			}
			else if ( sekil_no == 5 && dondurme_kontrol == 1 ){
				if (  arr[anlik_satir+2][anlik_sutun] != '*' && arr[anlik_satir+1][anlik_sutun+1] != '*' && anlik_satir < 10 ){
					arr[anlik_satir-1][anlik_sutun+1] = 'O';	
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir+2][anlik_sutun] = '*';
					arr[anlik_satir+1][anlik_sutun+1] = '*';
					anlik_satir++;
					flag=0;
				}
				else
					flag=1;
			}
			
			
			
			if( sekil_no == 6 && dondurme_kontrol_L == 0 ){ ///////////   L  HARFI
				if ( arr[anlik_satir+2][anlik_sutun] != '*' && arr[anlik_satir+2][anlik_sutun+1] != '*' && anlik_satir < 10 ){ //////////////
					arr[anlik_satir+2][anlik_sutun] = '*';
					arr[anlik_satir+2][anlik_sutun+1] = '*';
					arr[anlik_satir-1][anlik_sutun] = 'O';
					arr[anlik_satir+1][anlik_sutun+1] = 'O';
					anlik_satir++;
					flag=0;
				}
				else
					flag=1;
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 1 ){ ///////////   L  HARFI
				if ( arr[anlik_satir+1][anlik_sutun-1] != '*' && arr[anlik_satir+1][anlik_sutun] != '*' && arr[anlik_satir+1][anlik_sutun+1] != '*' && anlik_satir < 11  ){ 
					arr[anlik_satir+1][anlik_sutun-1] = '*';
					arr[anlik_satir+1][anlik_sutun] = '*';
					arr[anlik_satir+1][anlik_sutun+1] = '*';
					arr[anlik_satir][anlik_sutun-1] = 'O';
					arr[anlik_satir][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun+1] = 'O';
					anlik_satir++;
					flag=0;
				}
				else
					flag=1;
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 2 ){ ///////////   L  HARFI
				if ( arr[anlik_satir+2][anlik_sutun] != '*' && arr[anlik_satir][anlik_sutun-1] != '*' && anlik_satir < 10 ){ 
					arr[anlik_satir+2][anlik_sutun] = '*';
					arr[anlik_satir][anlik_sutun-1] = '*';
					arr[anlik_satir-1][anlik_sutun] = 'O';
					arr[anlik_satir-1][anlik_sutun-1] = 'O';
					anlik_satir++;
					flag=0;
				}
				else
					flag=1;
			}
			if( sekil_no == 6 && dondurme_kontrol_L == 3 ){ ///////////   L  HARFI
				if ( arr[anlik_satir+2][anlik_sutun-1] != '*' && arr[anlik_satir+1][anlik_sutun] != '*' && arr[anlik_satir+1][anlik_sutun+1] != '*' && anlik_satir < 10 ){
					arr[anlik_satir+2][anlik_sutun-1] = '*';
					arr[anlik_satir+1][anlik_sutun] = '*';
					arr[anlik_satir+1][anlik_sutun+1] = '*';
					arr[anlik_satir][anlik_sutun+1] = 'O';
					arr[anlik_satir][anlik_sutun-1] = 'O';
					arr[anlik_satir][anlik_sutun] = 'O';
					anlik_satir++;
					flag=0;
				}
				else
					flag=1;
			}
			
		
		///////////////////////// SILME ISLEMLERI	
		}
		for( i=2; i<12; i++){
			counter_deleter=0;
			for ( j=0; j<10; j++){
				if(arr[i][j] == '*'){
					counter_deleter++;
					
				}
			}
			if (counter_deleter == 10){
				point = i;
				point_counter++;
				if(flag==1){
					skor += 100;
					for( i=point; i>0; i--){
						for ( j=0; j<10; j++ ){
							arr[i][j] = arr[i-1][j];
						}
					}

				}
					
			}
		}
		
		sleep(0.7);
		system("cls");
	}		
	break;
		case 2:
			system("cls");
			printf("--- SKOR TABLOSU ---");
			for(i=0; i<k-1; i++){
				for(j=i+1; j<k; j++){
					if(score[i] < score[j]){
						temp=score[i];
						score[i]=score[j];
						score[j]=temp;
					}
				}
			}
			for(i=0; i<k; i++){
				printf("\n%d.SKOR: %d",i+1,score[i]);
			}
			printf("\n");
			
			break;
		case 3: 
			system("cls");
			printf("\n\tSPACE karakteri donme islemini gerceklestirir.\n\tKlavyedeki yon tuslari ile sag sol ve asagi hareket edebilirsiniz.\n\tHer tamamladiginiz satir icin 100 puan kazanirsiniz.\n\tOyun suresince alinan en yuksek puani Skor tablosundan gorebilirsiniz.\n");
			break;
		case 4:
			break;
	}
	
				
		}
	}




	

