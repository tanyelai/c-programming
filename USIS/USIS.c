#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct {
	char Kodu[15];
	char Adi[20];
	int Kredi;
	int Kontenjan;
	char OgrUyID[5];
}Ders;

typedef struct{
	char ID[15];
	char Adi[20];
	char Soyadi[20];
	char Unvan[20];
}OgretimUyesi;

typedef struct{
	char OgrID[20];
	char Adi[20];
	char Soyadi[20];
	int KayitliDersSayisi;
	int AldigiKredi;
}Ogrenci;


void OgrenciEkle(char *);
void OgretimUyesiEkle(char *);
void DersEkle(char *, char *);

void OgrenciSil(char *);
void OgretimUyesiSil(char *);
void DersSil(char *);

void OgrenciDersEkle(int *, int , int , int , char *, char *);
int SatirSay(char* );
void OgrenciDersSil(int *, int , int , int , char *, char *);

// Dosya islemleri icin -- Ekle(); Sil();

void DerseKayitliOgrenciler(char *); // Ders kodu verilen bir derse kayitli olan tum ogrencileri gosteren fonksiyon
void OgrenciDersListele(char *);     // ogrenci no'su verilen bir ogrencinin aldigi tum dersler
void OgrUyesiVerdigiDersler(char *);    // ogretim uyesinin verdigi dersleri listeyen fonk.
void OgrUyesiDersindekiOgrler(char *, char *);    // ogretim uyesinin verdigi bir derse ait kod kullanarak dersi alan tum ogrencilerin listesi 

//******************************************************    MAIN   *********************************************************//
int main(){
	// OgrenciDersKayit.txt otomatik girilmistir.
	
	char fogrdosya[20], fdersdosya[20], fhocadosya[20];
	int maxKredi, maxDers;
	printf("Ogrenci dosyasinin adini giriniz: "); scanf("%s", fogrdosya);
	printf("Ders dosyasinin adini giriniz: "); scanf("%s", fdersdosya);
	printf("Ogretim Uyesi dosyasinin adini giriniz: "); scanf("%s", fhocadosya);
	printf("Ogrencilerin alabilecegi max ders sayisini giriniz: "); scanf("%d", &maxDers);
	printf("Ogrencilerin alabilecegi max kredi sayisini giriniz: "); scanf("%d", &maxKredi);
	FILE *fogrenci, *fders, *fhoca;
	int sayac=0, maxKontenjan = 6;
	int islem,cikis=1;
	
	
	while(cikis){
		system("cls");
		printf("Bir islem seciniz: \n1)Ekleme\n2)Silme\n3)Listeleri Goruntuleme\n4)Cikis\nSecim:");
		scanf("%d", &islem);	
		
		switch(islem){
		case 1:
			system("cls");
			printf("Bir islem seciniz: \n1)Ogretim Uyesi Ekleme\n2)Ders Ekleme\n3)Ogrenci Ekleme\n4)Ogrenci Ders Ekleme\n5)Geri\nSecim:");
			scanf("%d", &islem);
			
			switch(islem){
				
				case 1:
					system("cls");
					OgretimUyesiEkle(fhocadosya); 
					break;
				case 2:
					system("cls");
					DersEkle(fdersdosya, fhocadosya);
					break;
				case 3:	
					system("cls");
					OgrenciEkle(fogrdosya);
					break;
				case 4:
					OgrenciDersEkle(&sayac, maxDers, maxKredi, maxKontenjan, fogrdosya, fdersdosya);
					break;
				case 5:
					break;
			}
			break;
		
		case 2: 
			system("cls");
			printf("Bir islem seciniz: \n1)Ogretim Uyesi Silme\n2)Ders Silme\n3)Ogrenci Silme\n4)Ogrenci Ders Silme\n5)Geri\nSecim:");
			scanf("%d", &islem);
			
			switch(islem){
				case 1:
					system("cls");
					OgretimUyesiSil(fhocadosya); 
					break;
				case 2:
					system("cls");
					DersSil(fdersdosya);
					break;
				case 3:	
					system("cls");
					OgrenciSil(fogrdosya);
					break;
				case 4:
					OgrenciDersSil(&sayac, maxDers, maxKredi, maxKontenjan, fogrdosya, fdersdosya);
					break;
				case 5: 
					break;
			}
			break;
		
		case 3:
			system("cls");
			printf("Bir islem seciniz: \n1)Derse kayitli ogrenci listesi\n2)Ogrencinin aldigi derslerin listesi\n3)Ogretim Uyesinin verdigi dersler"
					"\n4)Ogretim uyesinin verdigi derse ait tum ogrencilerin listesi\nSecim:");
			scanf("%d", &islem);
			
			switch(islem){
				case 1:
					DerseKayitliOgrenciler(fdersdosya);
					break;
				case 2:
					OgrenciDersListele(fogrdosya);
					break;
				case 3:
					OgrUyesiVerdigiDersler(fdersdosya);
					break;
				case 4:
					OgrUyesiDersindekiOgrler(fogrdosya, fdersdosya);
					break;
			}	
			break;
		case 4:
			cikis = 0;
			break;
			
		break;
		}
	}
	
	

	
	return 0;
}
//**************************************************************************************************************************//
int SatirSay(char *dosyaismi){
	char x;
	int satirsayisi=1;
	FILE *dosya;
	dosya = fopen(dosyaismi, "r");	
	if(!dosya){
		printf("\nDosya acilamadi.");
		return 0;
	}
	for( x = getc(dosya); x!= EOF; x = getc(dosya))
		if ( x == '\n')
			satirsayisi++;
	
	fclose(dosya);
	return satirsayisi;
}

void OgretimUyesiEkle(char *fhocadosya){

	OgretimUyesi OgrUy;	
	char line[100];
	int c=1;
		printf("Eklemek istediginiz ogretim uyesi bilgileri:\n");
		printf("ID: ");
		scanf("%s", OgrUy.ID);
	
		FILE *dosya;
		dosya = fopen(fhocadosya, "r");
		if(!dosya)
			printf("Dosya bulunamadi.");
			
		while(!feof(dosya))
		{
			fgets(line, 100, dosya);
			if(strstr(line, OgrUy.ID) != NULL)
			{
				printf("\n%s\n", line);
				printf("Bu Ogretim uyesi zaten mevcut.\n");
				printf("\nYeni bir ogretim uyesi girisi icin herhangi bir tusa basiniz...\n");
				getch();
				return;
			}
			c++;
		}
		fclose(dosya);
		
		dosya = fopen(fhocadosya, "a+");
		if(dosya)
		{	
			if(c < SatirSay(fhocadosya))
				fprintf(dosya,"\n");
			printf("Ad: ");	scanf("%s", OgrUy.Adi);	
			printf("Soyad: ");  scanf("%s", OgrUy.Soyadi);		
			printf("Unvan: ");	scanf("%s", OgrUy.Unvan);
			fprintf(dosya, "\n%s %s %s %s", OgrUy.ID, OgrUy.Adi, OgrUy.Soyadi, OgrUy.Unvan);
			printf("Yeni bir ekleme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			fclose(dosya);
		}
		else printf("Dosya bulunamadý.\n");
	
}

void DersEkle(char *fdersdosya, char *fhocadosya){

	Ders DERS;
	OgretimUyesi OgrUy;
	char line[100]; 
	int c=1;
	DERS.Kontenjan = 0;
		printf("Eklemek istediginiz dersin bilgileri:\n");
		printf("Kodu: ");
		scanf("%s", DERS.Kodu);
	
		FILE *dosya = fopen(fdersdosya, "a+");
		if(!dosya)
			printf("Dosya bulunamadi.");
			
		while(!feof(dosya))
		{
			fgets(line, 100, dosya);
			if(strstr(line, DERS.Kodu) != NULL)
			{
				printf("\n%s\n", line);
				printf("Bu Ders zaten mevcut.\n");
				printf("\nYeni bir ders girisi icin herhangi bir tusa basiniz...\n");
				getch();
				return;
			}
		}
		fclose(dosya);

		int durum=0;	
		printf("Dersin hocasinin id'sini giriniz: \n");
		printf("id: ");
		scanf("%s", OgrUy.ID);
		
		dosya = fopen(fhocadosya, "r");
		if(!dosya)
			printf("Dosya bulunamadi.");
		
		while(!feof(dosya) && durum == 0){
			fgets(line, 100, dosya);
			if(strstr(line, OgrUy.ID) != NULL && c <= SatirSay(fhocadosya))
			{
				printf("\nBu derse atanan ogretim uyesi: %s\n", line);
				strcpy(DERS.OgrUyID, OgrUy.ID);
				printf("Ders ekleme islemine devam etmek icin herhangi bir tusa basiniz.\n");
				durum = 1;
				getch();			
			}	
			else
				durum = 0;
			c++;
		}
		if (durum == 0){
			printf("Atamak istediginiz id'ye sahip bir ogretim uyesi bulunmamaktadir.\n");
			printf("Yeni bir ekleme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			return;
		}
		fclose(dosya);  
		
		dosya = fopen(fdersdosya, "a+");
		if(dosya)
		{	
			printf("Dersin Adi: ");	scanf("%s", DERS.Adi);
			printf("Dersin Kredisi: ");  scanf("%d", &DERS.Kredi);	
			fprintf(dosya, "\n%s %s %d %d %s", DERS.Kodu, DERS.Adi, DERS.Kredi, DERS.Kontenjan, DERS.OgrUyID);
			printf("Yeni bir ekleme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			fclose(dosya);
		}
		else printf("Dosya bulunamadý.\n");
		
		
}

void OgrenciEkle(char *fogrdosya){

	Ogrenci OGRENCI;
	char line[100];
	OGRENCI.AldigiKredi = 0;
	OGRENCI.KayitliDersSayisi = 0;
	int c=1;
	
		printf("Eklemek istediginiz ogrenci bilgileri:\n");
		printf("ID: ");
		scanf("%s", OGRENCI.OgrID);
		
		FILE *dosya;
		dosya = fopen(fogrdosya, "r");
		if(!dosya)
			printf("Dosya bulunamadý.");
			
		while(!feof(dosya))
		{
			fgets(line, 100, dosya);
			if(strstr(line, OGRENCI.OgrID) != NULL && (c <= SatirSay(fogrdosya)))
			{
				printf("\n%s\n", line);
				printf("Bu Ogrenci zaten mevcut.\n");
				printf("\nYeni bir ogrenci girisi icin herhangi bir tusa basiniz...\n");
				getch();
				return;
			}
			c++;
		}
		fclose(dosya);

		dosya = fopen(fogrdosya, "a+");
		if(dosya)
		{	
			printf("Ad: ");	scanf("%s", OGRENCI.Adi);	
			printf("Soyad: ");  scanf("%s", OGRENCI.Soyadi);	
			fprintf(dosya, "\n%s %s %s %d %d", OGRENCI.OgrID, OGRENCI.Adi, OGRENCI.Soyadi, OGRENCI.KayitliDersSayisi, OGRENCI.AldigiKredi);
			printf("Yeni bir ekleme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			fclose(dosya);
		}
		else printf("Dosya bulunamadý.\n");
}

void OgrenciDersEkle(int *sayac, int maxDers, int maxKredi, int maxKontenjan, char *fogrdosya, char *fdersdosya){
	
	FILE *fders, *fogrenci, *fkayit;
	char OgrIDkayit[20], DersKoduKayit[20], satir[100], KayitNO[20], OgrIDkayit2[20], tire[20], DersNoKayit[20], atla[20], zaman[20];
	char ch, *buffer, *ptr;
	int found = 0, c = 1,a = 1; 
	buffer = (char*)malloc(sizeof(char)*1000);
	memset(buffer, 0, 1000*sizeof(char));
	ptr = buffer;
	char bufsatir[100], DersKrediKopya[20], dersKopya[20], KrediKopya[20], KontenjanKopya[20]; 
	memset(bufsatir, 0, 100);
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	sprintf(zaman, "%d-%02d-%02d/%02d:%02d:%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
	
	system("cls");
	
	Ogrenci OGRENCI;
	Ders DERS;
	
	fogrenci = fopen(fogrdosya, "r");
	if(!fogrenci){
		printf("Dosya  bulunamadi.");
		return;
	}
	printf("\nKayit yapilacak Ogrencinin ID'sini giriniz: ");
	scanf("%s", OgrIDkayit);	
	
	while(!feof(fogrenci)){
		
		fgets(satir, 100, fogrenci);
		if(strstr(satir, OgrIDkayit) != NULL && a <= SatirSay(fogrdosya))
		{
			sscanf(satir, "%s %s %s %d %d", OGRENCI.OgrID, OGRENCI.Adi, OGRENCI.Soyadi, &OGRENCI.KayitliDersSayisi, &OGRENCI.AldigiKredi);
			printf("\n\tOgrenci bilgileri:\n \tID: %s\n \tAd: %s\n \tSoyadi: %s\n \tMevcut ders sayisi: %d\n \tMevcut kredi sayisi: %d", OGRENCI.OgrID, OGRENCI.Adi, OGRENCI.Soyadi, OGRENCI.KayitliDersSayisi, OGRENCI.AldigiKredi);
		}
		a++;
	}
	fclose(fogrenci); 
	
	if(OGRENCI.KayitliDersSayisi == maxDers){
		printf("\nOgrenci ders sayisini astigi icin daha fazla ders alamaz.\n");
		getch();
		return;
	}
	
	fders = fopen(fdersdosya, "r");
	if(!fders){
		printf("Dosya bulunamadi.");
		return;
	}	
		
	
	ch=fgetc(fders); 
	printf("\nDERS KODU / DERS ADI / KREDISI / KAYITLI OGRENCI SAYISI / DERSI VEREN OGR. UYESI ID \n"); 
	while(ch!=EOF){ 
        printf("%c",ch); 
	    ch=fgetc(fders); 
    }
    rewind(fders);

		//
	printf("\n\nOgrencinin kaydolmak istedigi dersin kodunu giriniz: ");
	scanf("%s", DersKoduKayit);

	system("cls");
	fkayit = fopen("OgrenciDersKayit.txt", "r");
	if(!fkayit){
		
		printf("\nDosya bulunamadi. Tekrar deneyiniz.\n");
		return;
	}
	while(!feof(fkayit)){
		
		fgets(satir, 100, fkayit);
		if(strstr(satir, OgrIDkayit) != NULL && strstr(satir, DersKoduKayit) != NULL)
		{
			sscanf(satir, "%s %s %s %s %s", KayitNO, OgrIDkayit2, tire, DersKoduKayit, atla);
			printf("\n\tOgrenci ID - Ders kodu -> ONCEKI DURUMU:  %s %s %s %s %s", KayitNO, OgrIDkayit2, tire, DersKoduKayit, atla);
			found = 1;
		}
	}
	fclose(fkayit);
	
	if(found == 1){
		if(!strcmp(atla, "KAYITLI"))
		{
			printf("\n%s numarali Ogrenci %s kodlu derse zaten kayitli.\n", OgrIDkayit, DersKoduKayit);
			printf("Devam etmek icin herhangi bir tusa basiniz.");
			getch();
			return;
		}
	}
	a=1;
	while(!feof(fders))	{	
	
		fgets(satir, 100, fders);
		if(strstr(satir, DersKoduKayit) != NULL && a <= SatirSay(fogrdosya))
		{
			sscanf(satir, "%s %s %d %d %s", DERS.Kodu, DERS.Adi, &DERS.Kredi, &DERS.Kontenjan, DERS.OgrUyID);
			printf("\t\t\nDers bilgileri:\n Ders kodu: %s\n Dersin adi: %s\n Kredi: %d\n Mevcut kontenjan: %d\n Dersi veren Ogretim uyesi ID no: %s\n", DERS.Kodu, DERS.Adi, DERS.Kredi, DERS.Kontenjan, DERS.OgrUyID);
		}
		a++;
	}
	fclose(fders);
	
	//KONTROLLER
	if(DERS.Kontenjan == maxKontenjan){
		printf("\nDers kontenjani dolu.\n");
		printf("Devam etmek icin herhangi bir tusa basiniz.");
		getch();
		return;
	}
	if(OGRENCI.AldigiKredi + DERS.Kredi > maxKredi){
		printf("\nOgrenci alabilecegi kredi sayisini asiyor... Daha az kredili bir derse kaydolabilir.\n");
		printf("Devam etmek icin herhangi bir tusa basiniz.");
		getch();
		return;
	}
	OGRENCI.KayitliDersSayisi++; 
	OGRENCI.AldigiKredi += DERS.Kredi; 
	DERS.Kontenjan++; 
	
	fogrenci = fopen(fogrdosya, "r");

	while(!feof(fogrenci))
	{
		fgets(satir, 100, fogrenci);
		if(strstr(satir, OgrIDkayit) == NULL)
		{
			strcpy(ptr, satir);
			ptr += strlen(satir);
		}
		else
		{			
			itoa(OGRENCI.KayitliDersSayisi, dersKopya, 10);
			itoa(OGRENCI.AldigiKredi, KrediKopya, 10);
			
			strcat(bufsatir, OGRENCI.OgrID);	strcat(bufsatir, " ");
			strcat(bufsatir, OGRENCI.Adi);		strcat(bufsatir, " ");
			strcat(bufsatir, OGRENCI.Soyadi);	strcat(bufsatir, " ");
			strcat(bufsatir, dersKopya);			strcat(bufsatir, " ");
			strcat(bufsatir, KrediKopya);
			if(c < SatirSay(fogrdosya)) strcat(bufsatir, "\n");
						
			strcpy(ptr, bufsatir);
			ptr += strlen(bufsatir);
		}
		c++;
	}
	fclose(fogrenci);
	fogrenci = fopen(fogrdosya, "w");
	fprintf(fogrenci, "%s", buffer);
	fclose(fogrenci);
	
	memset(buffer, 0, 1000*sizeof(char));
	ptr = buffer;
	memset(bufsatir, 0, 100);
	
	c=1;
	fders = fopen(fdersdosya, "r");	
	while(!feof(fders))
	{
		fgets(satir, 100, fders);
		if(strstr(satir, DersKoduKayit) == NULL)
		{
			strcpy(ptr, satir);
			ptr += strlen(satir);
		}
		else
		{			
			itoa(DERS.Kredi, DersKrediKopya, 10);
			itoa(DERS.Kontenjan, KontenjanKopya, 10);
			
			strcat(bufsatir, DERS.Kodu);		strcat(bufsatir, " ");
			strcat(bufsatir, DERS.Adi);			strcat(bufsatir, " ");
			strcat(bufsatir, DersKrediKopya);		strcat(bufsatir, " ");
			strcat(bufsatir, KontenjanKopya);			strcat(bufsatir, " ");
			strcat(bufsatir, DERS.OgrUyID);
			if(c < SatirSay(fdersdosya)) strcat(bufsatir, "\n");			
						
			strcpy(ptr, bufsatir);
			ptr += strlen(bufsatir);
		}
		c++;
	}
	fclose(fders);
	fders = fopen(fdersdosya, "w");
	fprintf(fders, "%s", buffer);
	fclose(fders);

	(*sayac)++;
	fkayit = fopen("OgrenciDersKayit.txt", "a+");
	if(!fkayit){
		printf("Dosya bulunamadi.");
		return;
	}
	fprintf(fkayit, "%d) %s - %s KAYITLI  %s\n", *sayac, OGRENCI.OgrID, DERS.Kodu, zaman);
	fclose(fkayit);	
	printf("\nOgrenci ders kaydi tamamlandi.\n");
	printf("Yeni bir islem icin herhangi bir tusa basiniz...");
	getch();
}

void OgretimUyesiSil(char *fhocadosya){	

		OgretimUyesi OgrUy;
		char line[100];
		char *buffer, *ptr, OgrUyID[10]; 
		buffer = (char*)malloc(sizeof(char)*500);
		memset(buffer, 0, 500*sizeof(char));
		ptr=buffer;
		
		int durum=0;	
		printf("Kaydý silinecek ogretim uyesi ID: ");
		scanf("%s", OgrUy.ID);
		FILE *dosya;
		dosya = fopen(fhocadosya, "r");
		if(!dosya)
			printf("Dosya bulunamadi.");
		
		while(!feof(dosya) && durum == 0){
			fgets(line, 100, dosya);
			if(strstr(line, OgrUy.ID) != NULL)
				durum = 1;
			else
				durum = 0;
		}
		
		if (durum == 0){
			printf("Silmek istediginiz id'ye sahip bir ogretim uyesi bulunmamaktadir.\n");
			printf("Yeni bir silme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			return;
		}
		fclose(dosya);  
		int c=1;	
		dosya = fopen(fhocadosya, "r");
		if(dosya)
		{
			strcpy(OgrUyID, OgrUy.ID);
			while(!feof(dosya))
			{
				fgets(line, 100, dosya);
					if(strstr(line, OgrUyID) == NULL && c < SatirSay(fhocadosya))
				{
					strcpy(ptr, line);
					ptr += strlen(line);
				}
				c++;
			}
			fclose(dosya);
			dosya = fopen(fhocadosya, "w");
			fprintf(dosya, "%s", buffer);
			printf("Basariyla silindi.\nYeni bir silme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			fclose(dosya);
		}
		else printf("\nDosya açýlamadý.");
	}

void DersSil(char *fdersdosya){
		
		Ders DERS;
		char line[100];
		char *buffer, *ptr, DersKODU[10]; 
		buffer = (char*)malloc(sizeof(char)*500);
		memset(buffer, 0, 500*sizeof(char));
		ptr=buffer;
		
		int durum=0;	
		printf("Kaydý silinecek ders kodu: ");
		scanf("%s", DERS.Kodu);
		FILE *dosya;
		dosya = fopen(fdersdosya, "r");
		if(!dosya)
			printf("Dosya bulunamadi.");
		
		while(!feof(dosya) && durum == 0){
			fgets(line, 100, dosya);
			if(strstr(line, DERS.Kodu) != NULL)
				durum = 1;
			else
				durum = 0;
		}
		
		if (durum == 0){
			printf("Silmek istediginiz koda sahip bir ders bulunmamaktadir.\n");
			printf("Yeni bir silme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			return;
		}
		fclose(dosya);  
		
		int c=1;
		dosya = fopen(fdersdosya, "r");
		if(dosya)
		{
			strcpy(DersKODU, DERS.Kodu);
			while(!feof(dosya))
			{
				fgets(line, 100, dosya);
					if(strstr(line, DersKODU) == NULL && c < SatirSay(fdersdosya))
				{
					strcpy(ptr, line);
					ptr += strlen(line);
				}
				c++;
			}
			fclose(dosya);
			
			dosya = fopen(fdersdosya, "w");
			fprintf(dosya, "%s", buffer);
			printf("Basariyla silindi.\nYeni bir silme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			fclose(dosya);
		}
		else printf("\nDosya açýlamadý.");
	}

void OgrenciSil(char *fogrdosya){

		Ogrenci OGRENCI;
		char line[100];
		char *buffer=0, *ptr, OgrID[10]; 
		buffer = (char*)malloc(sizeof(char)*500);
		memset(buffer, 0, 500*sizeof(char));
		ptr=buffer;
		
		int durum=0;	
		printf("Kaydý silinecek ogrenci id: ");
		scanf("%s", OGRENCI.OgrID);
		FILE *dosya;
		dosya = fopen(fogrdosya, "r");
		if(!dosya)
			printf("Dosya bulunamadi.");
		
		while(!feof(dosya) && durum == 0){
			fgets(line, 100, dosya);
			if(strstr(line, OGRENCI.OgrID) != NULL)
				durum = 1;
			else
				durum = 0;
		}
		
		if (durum == 0){
			printf("Silmek istediginiz id'ye sahip bir ogrenci bulunmamaktadir.\n");
			printf("Yeni bir silme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			return;
		}
		fclose(dosya);  
		
		int c=1;
		dosya = fopen(fogrdosya, "r");
		if(dosya)
		{
			strcpy(OgrID, OGRENCI.OgrID);
			while(!feof(dosya))
			{
				fgets(line, 100, dosya);
				if(strstr(line, OgrID) == NULL && c < SatirSay(fogrdosya))
				{
					strcpy(ptr, line);
					ptr += strlen(line);
				}
				c++;
				
			}
			fclose(dosya);
			dosya = fopen(fogrdosya, "w");
			fprintf(dosya, "%s", buffer);
			printf("Basariyla silindi.\nYeni bir silme islemi icin herhangi bir tusa basiniz.\n");
			getch();
			fclose(dosya);
		}
		else printf("\nDosya açýlamadý.");
}

void OgrenciDersSil(int *sayac, int maxDers, int maxKredi, int maxKontenjan, char *fogrdosya, char *fdersdosya){ 

	FILE *fogrenci, *fders, *fkayit;
	char OgrIDkayit[20], DersKoduKayit[20], satir[100], KayitNO[20], OgrIDkayit2[20], tire[20], DersNoKayit[20], atla[20];
	char ch, *buffer, *ptr;
	int found = 0, c = 1; 
	buffer = (char*)malloc(sizeof(char)*1000);
	memset(buffer, 0, 1000*sizeof(char));
	ptr = buffer;
	char bufsatir[100], DersKrediKopya[20], dersKopya[20], KrediKopya[20], KontenjanKopya[20]; 
	memset(bufsatir, 0, 100);
	system("cls");	
	
	Ogrenci OGRENCI;
	Ders DERS;
	
	fogrenci = fopen(fogrdosya, "r");
	if(!fogrenci){
		printf("Dosya bulunamadi.");
		return;
	}
	printf("Ders kaydi silinecek ogrencinin ID'sini giriniz: ");
	scanf("%s", OgrIDkayit);	
	int a = 1;
	while(!feof(fogrenci))
	{
		fgets(satir, 100, fogrenci);
		if(strstr(satir, OgrIDkayit) != NULL && a < SatirSay(fogrdosya))
		{
			printf("%s", satir);
			sscanf(satir, "%s %s %s %d %d", OGRENCI.OgrID, OGRENCI.Adi, OGRENCI.Soyadi, &OGRENCI.KayitliDersSayisi, &OGRENCI.AldigiKredi);
			printf("\n\nOgrenci bilgileri:\n ID: %s\n Adi: %s\n Soyadi: %s\n Mevcut ders sayisi: %d\n Mevcut kredi sayisi: %d\n", OGRENCI.OgrID, OGRENCI.Adi, OGRENCI.Soyadi, OGRENCI.KayitliDersSayisi, OGRENCI.AldigiKredi);
		}
		a++;
	}
	fclose(fogrenci);
	
	fders = fopen(fdersdosya, "r");
	if(!fders){
		printf("Dosya bulunamadi.");
		return;
	}
	
	ch=fgetc(fders); 
	printf("\n Acilan ders listesi: \n"); 
	while(ch!=EOF){ 
        printf("%c",ch); 
	    ch=fgetc(fders); 
    }
    rewind(fders);
    
	fkayit = fopen("OgrenciDersKayit.txt", "r");
	if(!fkayit){
		printf("Dosya bulunamadi.\n");
        return;
	}	
	printf("\nOgrenci durumunu goruntulemek icin herhangi bir tusa basiniz.");
	getch();
	
	system("cls");
	printf("\n Ogrenci-Ders kayit/birakma durumlari: \n"); 
	a=1;
	while(!feof(fkayit))
	{
		fgets(satir, 100, fkayit);
		if(strstr(satir, OgrIDkayit) && a < SatirSay("OgrenciDersKayit.txt")) 
			printf("%s\n", satir); 
		a++;
    }
    rewind(fkayit);
    
	printf("\n\nOgrencinin birakmak istedigi dersin kodunu giriniz: ");
	scanf("%s", DersKoduKayit);
	system("cls");
	a=1;
	while(!feof(fders))
	{
		fgets(satir, 100, fders);
		if(strstr(satir, DersKoduKayit) != NULL && a < SatirSay(fdersdosya) )
		{
			sscanf(satir, "%s %s %d %d %s", DERS.Kodu, DERS.Adi, &DERS.Kredi, &DERS.Kontenjan, DERS.OgrUyID);
			printf("\n\n Ders bilgileri:\nDers kodu: %s\nDersin adi: %s\nKredisi: %d\nMevcut kontenjani: %d\nDersi veren Ogretim uyesi ID no: %s\n", DERS.Kodu, DERS.Adi, DERS.Kredi, DERS.Kontenjan, DERS.OgrUyID);
		}
		a++;
	}
	fclose(fders);
    
    a=1;
    while(!feof(fkayit))
	{
		fgets(satir, 100, fkayit);
		if(strstr(satir, OgrIDkayit) != NULL && strstr(satir, DersKoduKayit) != NULL && a < SatirSay(fdersdosya))
		{
			sscanf(satir, "%s %s %s %s %s", KayitNO, OgrIDkayit2, tire, DersNoKayit, atla);
			printf("\n\nOgrenciNO - Ders kodu -> ONCEKI DURUMU:  %s %s %s %s %s", KayitNO, OgrIDkayit2, tire, DersNoKayit, atla);
			found = 1;
		}
		a++;
	}
	fclose(fkayit);
	
	if(found == 0)
	{
		printf("\nHenuz %s numarali Ogrenci %s dersine kaydolmamis.", OgrIDkayit, DERS.Adi);
		getch();
		return;
	}
	if(strcmp(atla, "BIRAKTI") == 0)
	{
		printf("\nOgrenci bu dersi daha Onceden birakmis.\n");
		getch();
		return;
	}		
	else strcpy(atla, "BIRAKTI");
	
	if(OGRENCI.KayitliDersSayisi >= 0 && OGRENCI.AldigiKredi >= 0 && DERS.Kontenjan >= 0 ){
			OGRENCI.KayitliDersSayisi--;
			OGRENCI.AldigiKredi -= DERS.Kredi;
			DERS.Kontenjan--;
	}
		
	buffer = (char*)malloc(sizeof(char)*20000);
	memset(buffer, 0, 20000*sizeof(char));
	ptr = buffer;
	memset(bufsatir, 0, 100);
	
	fkayit = fopen("OgrenciDersKayit.txt", "r");
	while(!feof(fkayit))
	{
		fgets(satir, 100, fkayit);
		if(strstr(satir, OgrIDkayit) == NULL || strstr(satir, DersKoduKayit) == NULL)
		{	
			strcpy(ptr, satir);
			ptr += strlen(satir);					
		}
		else 
		{
			strcat(bufsatir, KayitNO);			strcat(bufsatir, " ");
			strcat(bufsatir, OgrIDkayit2);		strcat(bufsatir, " ");
			strcat(bufsatir, tire);				strcat(bufsatir, " ");
			strcat(bufsatir, DersNoKayit);		strcat(bufsatir, " ");
			strcat(bufsatir, atla);
			if(c < SatirSay("OgrenciDersKayit.txt")) strcat(bufsatir, "\n");			
						
			strcpy(ptr, bufsatir);
			ptr += strlen(bufsatir);			
		}
		c++;
	}
	fclose(fkayit);
	fkayit = fopen("OgrenciDersKayit.txt", "w");
	fprintf(fkayit, "%s", buffer);
	fclose(fkayit);
	
	memset(buffer, 0, 2000*sizeof(char));
	ptr = buffer;
	memset(bufsatir, 0, 100);
	c = 1;
	fogrenci = fopen(fogrdosya, "r");
	while(!feof(fogrenci))
	{
		fgets(satir, 100, fogrenci);
		if(strstr(satir, OgrIDkayit) == NULL && c <= SatirSay(fdersdosya))
		{
			strcpy(ptr, satir);
			ptr += strlen(satir);
		}
		else
		{			
			itoa(OGRENCI.KayitliDersSayisi, dersKopya, 10);
			itoa(OGRENCI.AldigiKredi, KrediKopya, 10);
			
			strcat(bufsatir, OGRENCI.OgrID);	strcat(bufsatir, " ");
			strcat(bufsatir, OGRENCI.Adi);		strcat(bufsatir, " ");
			strcat(bufsatir, OGRENCI.Soyadi);	strcat(bufsatir, " ");
			strcat(bufsatir, dersKopya);		strcat(bufsatir, " ");
			strcat(bufsatir, KrediKopya);
			if(c < SatirSay(fogrdosya)) strcat(bufsatir, "\n");			
						
			strcpy(ptr, bufsatir);
			ptr += strlen(bufsatir);
		}
		c++;
	}
	fclose(fogrenci);
	fogrenci = fopen(fogrdosya, "w");
	fprintf(fogrenci, "%s", buffer);
	fclose(fogrenci);
	
	memset(buffer, 0, 2000*sizeof(char));
	ptr = buffer;
	memset(bufsatir, 0, 100);
	c = 1;
	fders = fopen(fdersdosya, "r");
	while(!feof(fders))
	{
		fgets(satir, 100, fders);
		if(strstr(satir, DersKoduKayit) == NULL && c <= SatirSay(fogrdosya))
		{
			strcpy(ptr, satir);
			ptr += strlen(satir);
		}
		else
		{			
			itoa(DERS.Kredi, KrediKopya, 10);
			itoa(DERS.Kontenjan, KontenjanKopya, 10);
			
			strcat(bufsatir, DERS.Kodu);		strcat(bufsatir, " ");
			strcat(bufsatir, DERS.Adi);			strcat(bufsatir, " ");
			strcat(bufsatir, dersKopya);		strcat(bufsatir, " ");
			strcat(bufsatir, KontenjanKopya);	strcat(bufsatir, " ");
			strcat(bufsatir, DERS.OgrUyID);
			if(c < SatirSay(fdersdosya))strcat(bufsatir, "\n");			
						
			strcpy(ptr, bufsatir);
			ptr += strlen(bufsatir);
		}
		c++;
	}
	fclose(fders);
	fders = fopen(fdersdosya, "w");
	fprintf(fders, "%s", buffer);
	printf("\n\nSilme islemi basariyla tamamlandi.\n\nYeni bir islem icin herhangi bir tusa basiniz...");
	getch();
	fclose(fders); 
}

void DerseKayitliOgrenciler(char *fdersdosya){
	
	FILE *fders, *fkayit;
	char DersID[20], DersKoduKayit[20], satir[100], KayitNO[20], OgrIDkayit2[20], tire[20], DersNoKayit[20], atla[20];
	int found = 0, c = 1; 

	system("cls");
	
	Ogrenci OGRENCI;
	Ders DERS;

	fders = fopen(fdersdosya, "r");
	if(!fders){
		printf("Dosya  bulunamadi.");
		return;
	}
	printf("\nOgrencileri listenecek Ders'in kodunu giriniz: ");
	scanf("%s", DersID);	
	
	while(!feof(fders)){
		
		fgets(satir, 100, fders);
		if(strstr(satir, DersID) != NULL && c <= SatirSay("OgrenciDersKayit.txt"))
		{
			sscanf(satir, "%s %s %d %d %s", DERS.Kodu, DERS.Adi, &DERS.Kredi, &DERS.Kontenjan, DERS.OgrUyID);
			printf("\tDers bilgileri:\n \tKODU: %s\n \tAdi: %s\n \tDersin kredisi: %d\n \tDersi alan Ogrenci sayisi: %d\n \tDersi veren ogretim uyesi id: %s\n", DERS.Kodu, DERS.Adi, DERS.Kredi, DERS.Kontenjan, DERS.OgrUyID);
			printf("\n\tKayitli dersleri gormek icin herhangi bir tusa basiniz.");
			getch();
		}
		c++;
	}
	fclose(fders); 
	
	fkayit = fopen("OgrenciDersKayit.txt", "r");
	if(!fkayit){	
		printf("\nDosya bulunamadi. Tekrar deneyiniz.\n");
		return;
	}
	system("cls");
	printf("\n\t DERSE KAYITLI OLAN OGRENCILER \t\n");
	
	c=1;
	while(!feof(fkayit)){
		
		fgets(satir, 100, fkayit);
		if(strstr(satir, DersID) != NULL && c < SatirSay("OgrenciDersKayit.txt"))
		{
			sscanf(satir, "%s %s %s %s %s", KayitNO, OgrIDkayit2, tire, DersKoduKayit, atla);
			printf("\n\t<OGRENCI NO> -> %s ", OgrIDkayit2);
			found = 1;
		}
		c++;
	}
	if(found == 0){
		printf("Bu derse kayitli ogrenci bulunmamaktadir.");
	}
		printf("\n\tYeni bir islem icin herhangi bir tusa basiniz.");
		getch();
	fclose(fkayit);
	
}

void OgrenciDersListele(char *fogrdosya){

	FILE *fogrenci, *fkayit;
	char OgrID[20], DersKoduKayit[20], satir[100], KayitNO[20], OgrIDkayit2[20], tire[20], DersNoKayit[20], atla[20];
	int found = 0, c = 1; 

	system("cls");
	
	Ogrenci OGRENCI;
	Ders DERS;
	
	fogrenci = fopen(fogrdosya, "r");
	if(!fogrenci){
		printf("Dosya  bulunamadi.");
		return;
	}
	printf("\nDersleri listenecek Ogrencinin ID'sini giriniz: ");
	scanf("%s", OgrID);	
	
	
	while(!feof(fogrenci)){
		
		fgets(satir, 100, fogrenci);
		if(strstr(satir, OgrID) != NULL && c <= SatirSay("OgrenciDersKayit.txt"))
		{
			sscanf(satir, "%s %s %s %d %d", OGRENCI.OgrID, OGRENCI.Adi, OGRENCI.Soyadi, &OGRENCI.KayitliDersSayisi, &OGRENCI.AldigiKredi);
			printf("\tOgrenci bilgileri:\n \tID: %s\n \tAd: %s\n \tSoyadi: %s\n \tMevcut ders sayisi: %d\n \tMevcut kredi sayisi: %d\n", OGRENCI.OgrID, OGRENCI.Adi, OGRENCI.Soyadi, OGRENCI.KayitliDersSayisi, OGRENCI.AldigiKredi);
			printf("\n\tKayitli dersleri gormek icin herhangi bir tusa basiniz.");
			getch();
		}
		c++;
	}
	fclose(fogrenci); 
	c=1;
	fkayit = fopen("OgrenciDersKayit.txt", "r");
	if(!fkayit){
		
		printf("\nDosya bulunamadi. Tekrar deneyiniz.\n");
		return;
	}
	system("cls");
	printf("\n\t OGRENCININ KAYITLI OLDUGU DERSLER \t\n");
	while(!feof(fkayit)){
		
		fgets(satir, 100, fkayit);
		if(strstr(satir, OgrID) != NULL && c < SatirSay("OgrenciDersKayit.txt"))
		{
			sscanf(satir, "%s %s %s %s %s", KayitNO, OgrIDkayit2, tire, DersKoduKayit, atla);
			printf("\n\t<Ders kodu> -> %s ", DersKoduKayit);
			found = 1;
		}
		c++;
	}
	if(found == 0){
		printf("Bu ogrencinin kayitli dersi bulunmamaktadir.");
		printf("\n\tDevam etmek icin herhangi bir tusa basiniz.");
		getch();
	}
		printf("\n\tYeni bir islem icin herhangi bir tusa basiniz.");
		getch();
	fclose(fkayit);

}

void OgrUyesiVerdigiDersler(char *fdersdosya) {
	
	FILE *fders, *fkayit;
	char OgrUyID[20], satir[100];
	int found = 0, c = 1; 

	system("cls");

	Ders DERS;

	printf("\nDersleri listenecek ogretim uyesinin id'sini giriniz: ");
	scanf("%s", OgrUyID);	
		
	fders = fopen(fdersdosya, "r");
	if(!fders){
		
		printf("\nDosya bulunamadi. Tekrar deneyiniz.\n");
		return;
	}
	system("cls");
	printf("\n\t OGRETIM UYESININ VERDIGI DERSLER \t\n");
	
	while(!feof(fders)){
		
		fgets(satir, 100, fders);
		if(strstr(satir, OgrUyID) != NULL)
		{
			sscanf(satir, "%s %s %d %d %s", DERS.Kodu, DERS.Adi, &DERS.Kredi, &DERS.Kontenjan, DERS.OgrUyID);
			if(!strcmp(OgrUyID, DERS.OgrUyID)){
				printf("\n\t<DERSIN ADI - KODU> -> %s - %s", DERS.Adi, DERS.Kodu);
			}
			found = 1;
		}
		c++;
	}
	if(found == 0){
		printf("Bu hocanin verdigi ders bulunmamaktadir.");
	}
		printf("\n\tYeni bir islem icin herhangi bir tusa basiniz.");
		getch();
	fclose(fders);
	
	
} 

void OgrUyesiDersindekiOgrler(char *fogrdosya, char *fdersdosya) {
	
	FILE *fders, *fkayit, *fogrenci;
	char OgrUyID[20], satir[100];
	char DersID[20], DersKoduKayit[20], KayitNO[20], OgrIDkayit2[20], tire[20], DersNoKayit[20], atla[20];
	int found = 0, c = 1;
	char ch, *buffer, *ptr;
	buffer = (char*)malloc(sizeof(char)*1000);
	memset(buffer, 0, 1000*sizeof(char));
	ptr = buffer;
	char bufsatir[100], dersKopya[20], KrediKopya[20], KontenjanKopya[20], DersKrediKopya[20]; 
	memset(bufsatir, 0, 100);

	system("cls");

	Ders DERS;	
	Ogrenci OGRENCI;

	printf("\nDersleri listenecek ogretim uyesinin id'sini giriniz: ");
	scanf("%s", OgrUyID);	
		
	fders = fopen(fdersdosya, "r");
	if(!fders){
		
		printf("\nDosya bulunamadi. Tekrar deneyiniz.\n");
		return;
	}
	system("cls");
	printf("\n\t OGRETIM UYESININ VERDIGI DERSLER \t\n");
	
	while(!feof(fders)){
		
		fgets(satir, 100, fders);
		if(strstr(satir, OgrUyID) != NULL)
		{
			sscanf(satir, "%s %s %d %d %s", DERS.Kodu, DERS.Adi, &DERS.Kredi, &DERS.Kontenjan, DERS.OgrUyID);
			if(!strcmp(OgrUyID, DERS.OgrUyID)){
				printf("\n\t<DERSIN ADI - KODU> -> %s - %s", DERS.Adi, DERS.Kodu);
			}
			found = 1;
		}
		c++;
	}
	if(found == 0){
		printf("Bu hocanin verdigi ders bulunmamaktadir.");
	}
	fclose(fders);



	fders = fopen(fdersdosya, "r");
	if(!fders){
		printf("Dosya  bulunamadi.");
		return;
	}
	printf("\nOgrencileri listenecek Ders'in kodunu giriniz: ");
	scanf("%s", DersID);
	while(!feof(fders)){
		
		fgets(satir, 100, fders);
		if(strstr(satir, DersID) != NULL && c <= SatirSay(fdersdosya))
		{
			sscanf(satir, "%s %s %d %d %s", DERS.Kodu, DERS.Adi, &DERS.Kredi, &DERS.Kontenjan, DERS.OgrUyID);
			printf("\tDers bilgileri:\n \tKODU: %s\n \tAdi: %s\n \tDersin kredisi: %d\n \tDersi alan Ogrenci sayisi: %d\n \tDersi veren ogretim uyesi id: %s\n", DERS.Kodu, DERS.Adi, DERS.Kredi, DERS.Kontenjan, DERS.OgrUyID);
			printf("\n\tKayitli dersleri gormek icin herhangi bir tusa basiniz.");
			getch();
		}
		c++;
	}
	fclose(fders); 
	
	fkayit = fopen("OgrenciDersKayit.txt", "r");
	if(!fkayit){	
		printf("\nDosya bulunamadi. Tekrar deneyiniz.\n");
		return;
	}
	system("cls");
	printf("\n\t DERSE KAYITLI OLAN OGRENCILER \t\n");
	
	char DersIDkopya[20];
	char sinifListesi[20] = "_SINIFLISTESI.txt";
	strcpy(DersIDkopya, DersID);
	strcat(DersIDkopya, sinifListesi);
	
	fogrenci = fopen(DersIDkopya, "a");
	c=1;
	while(!feof(fkayit)){
		
		fgets(satir, 100, fkayit);
		if(strstr(satir, DersID) != NULL && c <= SatirSay("OgrenciDersKayit.txt"))
		{
			sscanf(satir, "%s %s %s %s %s", KayitNO, OgrIDkayit2, tire, DersKoduKayit, atla);
			printf("\n\t<OGRENCI NO> -> %s ", OgrIDkayit2);
			fprintf(fogrenci, "\t<OGRENCI NO> -> %s\n", OgrIDkayit2);
			
			found = 1;
		}
		c++;
	}
	fclose(fogrenci);
	if(found == 0){
		printf("\nBu derse kayitli ogrenci bulunmamaktadir.\n");
	}
	fclose(fkayit);
	
	printf("\n\tSINIF dosyada listelenmistir.\nYeni bir islem icin herhangi bir tusa basiniz.");
	getch(); 
	

}





















