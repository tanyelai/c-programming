#include <stdio.h>
#define SIZE 100
#define SIZE2 10000

int main()
{
	int N,M,row,column,num,first_qua,current_element,previous_element,k=0,counter=1,new_qua=0,element=0;
	scanf("%d %d",&N,&M);		// matris boyutu
	first_qua = N*M;
	int arr[SIZE][SIZE];	
	int new_array[SIZE2];			// compression iþlemini kolaylaþtýrmak için 
	int new_matrix[SIZE][SIZE]
	
	printf("Enter your elements:\n");
	for(row=0; row<N; row++){						// elemanlarý alýyoruz
		for (column=0; column<M; column++){
			scanf("%d",&num);
			arr[row][column] = num;
		}
	}
	
	// EK **************************************************************
	printf("\n---Before Compression---\n");
	for(row=0; row<N; row++){						// elemanlarý basýyoruz
		for (column=0; column<M; column++){
			printf("%d ",arr[row][column]);
		}
		printf("\n");
	}
	////////////////////////////////////////////////////////////////////
	column=1;	// Column 1 'den baþlar çünkü previous'a sahibiz, elimizdeki mevcut alana ulaþmalýyýz.
	for(row=0; row<N; row++){
		while(column<M){     // Initializing en altta yapýlýyor
			if( column == 0){			// Current-> Column 0 durumu için matriste atlama gerçekleþir ve sistemi bozar(previous'un row'u bir önceki kalmalý), bunu engellemek için koyulan if			
				previous_element = arr[row-1][M-1];		//Kuyruk olarak takip eden kontrol elementi
				current_element = arr[row][column];		//Bulunduðumuz konum
			}
			else{
				previous_element = arr[row][column-1];
				current_element = arr[row][column];
			}	
			
			if ( current_element == previous_element )	// Ardý ardýna gelen ayný elemanlarý sayýyoruz
				counter++;
				
			else {									// Ayný olmamasý halinde geride 
				new_array[k]=counter;
				new_array[k+1]=previous_element;
				counter = 1;
				k += 2;
				new_qua = k;
			}
			
			if ( first_qua == (row+1)*(column+1) ) {     //  Matrisin son elemanýna geldiðinde
				new_array[k]=counter;			   //  Current'ýn tuttuðu elemanýn çöpe atýlmamasý için
				new_array[k+1]=current_element;	   //	bu if'i açýyoruz
				k += 2;
				new_qua = k;
			}
		column++;
		}
			column=0;	//Ýlk baþlangýç harici 0. sütun sýkýntý çýkarmýyor. Bu yüzden hata yapmamak için 0'a sarmalýyýz, her satýr deðiþikliðinde.		
	}
	
	printf("\n-After compression- New array-\n");
	for (element = 0; element < new_qua; element++){
		printf("%d ",new_array[element]);
	}
	float res;
	res = new_qua / (float)first_qua;			
	printf("\nCompression Ratio : %.2f\n", (1-res) );
	
	int r=0;
	current_element = new_array[r+1];
	// EK DECODING**************************************************************
	printf("\nA new matrix after Decompression\n");
	for(row=0; row<N; row++){						// Arraye decode uygulayarak yeni matris üretiliyor.
		for (column=0; column<M; column++){
			if( r == 0 &&  new_array[r] > 0 ){
				new_array[r]--;
				new_matrix[row][column] = current_element;
			}
			else if( new_array[r] > 1){
				new_array[r]--;
				new_matrix[row][column] = current_element;
			}
			else{
				r+=2;
				current_element = new_array[r+1];
				new_matrix[row][column] = current_element;
			}
		
			printf("%d ",new_matrix[row][column]);
		}
		printf("\n");
	}
	////////////////////////////////////////////////////////////////////

	return 0;
}
