#include <stdio.h>
#include <stdlib.h>

struct oda{
	int id;
	int yukseklik;
	int genislik;
	int uzunluk;
};

void ScanRooms(struct oda *oda, int odasayisi){
	int i,j,hacim;
	for(i=1; i<odasayisi-1; i++){
		if( (oda[i-1].yukseklik * oda[i-1].genislik * oda[i-1].uzunluk) < (oda[i].yukseklik * oda[i].genislik * oda[i].uzunluk) ){
			if((oda[i+1].yukseklik * oda[i+1].genislik * oda[i+1].uzunluk) < (oda[i].yukseklik * oda[i].genislik * oda[i].uzunluk) )
				printf("hacmi buyuk oda: %d\n",oda[i].id);
		}
	}
	printf("\n\n");
}

void GetInfo(struct oda *oda, int odasayisi){
	int i;
	for(i=0; i<odasayisi; i++){
		printf("\nid: ");
		scanf("%d",&oda[i].id);
		printf("yukseklik: ");
		scanf("%d",&oda[i].yukseklik);
		printf("\ngenislik: ");
		scanf("%d",&oda[i].genislik);
		printf("\nuzunluk: ");
		scanf("%d",&oda[i].uzunluk);
		}
}

void sortbyVolume(struct oda *oda, int odasayisi){
	
	int i,j;
	struct oda tmp;
	
	for(i=0;i<odasayisi-1;i++){
		for(j=0;j<odasayisi-1-i;j++){
			if( (oda[j].yukseklik * oda[j].genislik * oda[j].uzunluk) > (oda[j+1].yukseklik * oda[j+1].genislik * oda[j+1].uzunluk)){
				tmp = oda[j];
				oda[j] = oda[j+1];
				oda[j+1]= tmp;
			}
		}
	}
}

void printfInfo(struct oda *oda, int odasayisi){
	int i,hacim;
	
	for(i=0;i<odasayisi;i++){
		hacim = oda[i].genislik * oda[i].uzunluk * oda[i].yukseklik;
		printf("%d-%d-%d-%d-%d\n",oda[i].id,oda[i].yukseklik,oda[i].genislik,oda[i].uzunluk,hacim);
	}
	printf("\n\n");
}

int main(){
	
	printf("oda sayisini giriniz : ");
	
	int N;
	scanf("%d",&N);
	
	struct oda *oda;
	oda=malloc(sizeof(struct oda)*N);
	
	GetInfo(oda, N);
	ScanRooms(oda, N);
	printfInfo(oda, N);
	sortbyVolume(oda, N);
	printfInfo(oda, N);
	
	free(oda);
	return 0;
}
