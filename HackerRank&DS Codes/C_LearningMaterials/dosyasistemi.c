#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)
/**/
struct tarih{
	int gun;
	int ay;
	int yil;
};
struct ogrenci{
	int no;
	char isim[25];
	char soyisim[25];
	struct tarih dogum;
	float Matematik_Notu;
	float Fen_Notu;
	float Turkce_Notu;
};
void kayit(struct ogrenci *A)
{
	char c;
	printf("Ogrenci Numarasini Giriniz:");
	scanf("%d" ,&A->no);
	c=getchar();
	printf("Ogrenci Adini Giriniz:");
    fgets(A->isim,10,stdin);
	printf("Ogrenci Soyadini Giriniz:");
	fgets(A->soyisim,10,stdin);
	printf("Ogrencinin Dogum Tarihini Giriniz:");
	scanf("%d/%d/%d",&A->dogum.gun,&A->dogum.ay,&A->dogum.yil);
	printf("Ogrenci Matematik Notunu Giriniz:");
	scanf("%f",&A->Matematik_Notu);
	printf("Ogrenci Fen Notunu Giriniz:");
	scanf("%f",&A->Fen_Notu);
	printf("Ogrenci Turkce Notunu Giriniz:");
	scanf("%f",&A->Turkce_Notu);
}
void Display(struct ogrenci A)
{
	printf("%s\t ",&A.isim);
	printf("%s\t ",A.soyisim);
	printf("%d/%d/%d\t ",A.dogum.gun,A.dogum.ay,A.dogum.yil);
	printf("%.1f\t ",A.Matematik_Notu);
	printf("%.1f\t ",A.Fen_Notu);
	printf("%.1f\n",A.Turkce_Notu);
	
	return;
}
	


int main() {
     FILE*dosya;
     dosya=fopen("C:/Users/Toygar/Desktop/kodlarfalan/student.bin","rb");
     if(dosya==NULL) dosya=fopen("C:/Users/Toygar/Desktop/kodlarfalan/person.bin","wb");
     int a,k,i;
     struct ogrenci A;
     printf("=========MENU=========\n");
     printf("1) Ogrenci kaydini eklemek.\n");
	 printf("2) Ogrenci kaydini silmek.\n");
	 printf("3) Ogrenci kaydini guncellemek.\n");
	 printf("4) Tum ogrencileri ekranda listelemek.\n");
	 printf("5) Ogrenci numarasina gore kayitlari siralamak. ( Arama anahtari öðrenci numarasidir ).\n");
	 printf("6) Ogrenci ismine gore kayitlari siralamak\n");
	 printf("7) Matematik notuna gore siralama\n");
     printf("8) Fen notuna gore siralama\n");
     printf("9) Turkce notuna gore siralama\n");
     printf("10) Sirali kayitlari 'sorted.bin' dosyasina yaziniz.\n");
     printf("11) Cikis.\n");
     scanf("%d",&a);
     if(a==1){
     	kayit(&A);
     	fread(dosya);
	    fwrite(&A,sizeof(struct ogrenci),1,dosya);
	    
	 }
	if(a==4){
		
		fread(dosya,0,SEEK_END);
		k=ftell(dosya)/sizeof(struct ogrenci);
		fread(dosya,0,SEEK_SET);
	     printf("ISIM\t SOYAD\t DOGUM TARIHI\t MNOT\t FNOT\t TNOT\n");
			for(i=0;i<k;i++){
			fread(&A,sizeof(struct ogrenci),1,dosya);
			
			Display(A);
			
		}
		
		
		
		
	}
     
     
     
     
	fclose(dosya);
	return 0;
}
