#include<stdio.h>
#include<sys/stat.h>
#include <stdlib.h>

void indexDosyasiOlustur();
void indexDosyasiniSil();
void indexDosyasiniGoster();
void kayitEkle();
void kayitBul();
void kayitGuncelle();
void kayitSil();
void veriDosyasiniGoster();

typedef struct veri{		// bin dosyasi icin
	int ogrNo;	
	int dersKodu;
	int puan;
	char sube;
}veri;

typedef struct index{			// text icin struct
	int ogrNo;
	int adres;
}index;


int main(){
	int secim;					// secim degeri
	
	do{
		printf("\n\n********** SECIM EKRANI **********\n");
		printf("[1] Index Dosyasi Olustur\n");
		printf("[2] Kayit Ekle\n");
		printf("[3] Kayit Bul\n");
		printf("[4] Kayit Sil\n");
		printf("[5] Kayit Guncelle\n");
		printf("[6] Veri Dosyasini Goster\n");
		printf("[7] Index Dosyasini Goster\n");
		printf("[8] Index Dosyasini Sil\n");
		printf("[0] Programi Kapat\n");
		
	    scanf("%d",&secim);		// secim al�n�r
	
		switch(secim) {			// se�ime g�re yinlendirilir fonksiyona
			case 0:
				break;
			case 1:
				indexDosyasiOlustur();
			    break;
			case 2:
				kayitEkle();
		        break;
			case 3:
				kayitBul();
		        break;
		 	case 4:
		 		kayitSil();
		        break;
		    case 5:	
		    	kayitGuncelle();
			 	break;
	   	    case 6:
	   	    	veriDosyasiniGoster();
			    break;
		    case 7:
		    	indexDosyasiniGoster();
		        break;
		    case 8:
		    	indexDosyasiniSil();
	   		    break;
		   	default :
	   		    printf("Yanlis Secim. Tekrar Deneyin.");
	   		    break;
		}
		
	}while(secim != 0);
	

	
	return 0;
}

void indexDosyasiOlustur(){

	// VER� DOSYASINDA ELEMANLAR OKUNUR

	struct veri ogr[1000];		// rastgele uzunlukta ogrenci listesi

	FILE *dosya;				// dosya degiskeni
	fopen_s(&dosya, "veri.bin", "rb");		// bin dosyas� dosya okuma modunda a��ld�
	

	
	int satir = 0;
	while(fread(&ogr[satir], sizeof(struct veri), 1, dosya) == 1){		// sat�rlar bitene kadar bin dosyas�n� oku
		if(ogr[satir].dersKodu != -1){									// e�er derskodu -1 de�ilse devam et, -1 olan sat�ralr silinmi� demektir
			satir++;		
		}
	}

	fclose(dosya);			// dosyay� kapat
	
	
	// �ndex dosyas�na yerle�tirmeden �nce s�ralama yap�l�r
	int i, j, yedek;
	
	struct index indexler[1000];			// rastgele index dizisi olu�turuldu
	
	
	
	for(i = 0; i < satir; i++){					// elemanlar diziye aktar�ld�
		indexler[i].ogrNo = ogr[i].ogrNo;		// indexlerin ogrensi nosu bin dosyas�ndan al�n�r		
		indexler[i].adres = i;					// adres ise bin dosyas�ndaki sat�rd�r
	}
	
	
	for(i = 0; i < satir - 1; i++){		// index tablosu anahtar de�erimne yani ogrenci nosuna g�re s�ralan�r ayn� �ekilde adres de yer de�i�tirir
		for(j = 0; j < satir - i - 1; j++){
			if(indexler[j].ogrNo > indexler[j+1].ogrNo){
				
				yedek = indexler[j].ogrNo;		// yedekle
				indexler[j].ogrNo = indexler[j + 1].ogrNo;		// ata	
				indexler[j+1].ogrNo =  yedek;			// ata
				
				yedek = indexler[j].adres;
				indexler[j].adres = indexler[j + 1].adres;
				indexler[j +  1].adres = yedek;
				
			}
		}
	}
	
	
	FILE * indexDosyasi;			// indexdosyas�na gir
	indexDosyasi = fopen("index.txt", "w" );		// uzerine yazma modunda a�
		
	for(i = 0;i < satir; i++){
		fprintf(indexDosyasi, "%d %d\n", indexler[i].ogrNo, indexler[i].adres);		// satir say�s� kadar index elemanlar�n� yaz
	}
	
    fclose(indexDosyasi);		// index dosyasi kapat�ld�
}

void kayitEkle(){ 		

	struct veri ogr;		// ogrenci struct nesnesi
	
	
	printf("Ogrenci No[int] : ");
	scanf("%d", &ogr.ogrNo);

	printf("Ders Kodu[int] : ");
	scanf("%d", &ogr.dersKodu);

	printf("Puan[int] : ");
	scanf("%d", &ogr.puan);
	
	printf("Sube[char] : ");		// CHAR
	scanf("%s", &ogr.sube);
	// 4 adet eklenecek adam verisi al�nd�

	FILE *veriDosyasi = fopen("veri.bin", "ab" );		// dosya �zerine yazma modunda a��ld�
	
	
	if(veriDosyasi == NULL){		// dosya var m� kontrol
		return;
	}

    fwrite(&ogr, sizeof(veri),1, veriDosyasi);		// veri dosyas�na ekle bin dosyas� yani
	fclose(veriDosyasi);		// dosya kapa
	 
	 
	
	indexDosyasiOlustur();				// her eklemede tekrar indexkeme yap
	 
	 
}

void kayitBul(){
	int ogrenciNo;
	printf("ogrenciNo giriniz : ");
	scanf("%d", &ogrenciNo);		// kaydi bulunacak ogrenci no al�n�r
	

	int ogrNo;
	int satir;
	
	int i = 0,j, diziUzunlugu = 0;
	
	FILE * dosya;		// index dosyas� okuma modunda a��l�r
	dosya = fopen("index.txt","r");
	
	while(fscanf(dosya,"%d",&ogrNo)!=EOF)
	{
	    diziUzunlugu++;
	}
	// index dosyas�na ka� eleman olaca�� belirlenir
	
	
	fclose(dosya);		// dosya kapat�l�r
	diziUzunlugu /= 2;  // ka� sat�r oldu�u bulundu /2 yap�lmas�n�n nedeni index tablosunda 2 adet de�i�ken olmas�
	
	dosya = fopen("index.txt","r");		// tekrar index dosyas� a��l�r
	
	int a_ogrNo[diziUzunlugu];		// dizi boyutlar� dinamik olarak belirlenir
	int a_satir[diziUzunlugu];
	
	
    while(fscanf(dosya,"%d",&ogrNo)!=EOF)					// dosya bo�alana kadar
	{
		fscanf(dosya,"%d", &satir);				// ogrenciNo(anahtar) ve satir(adres) de�i�kenleri al�n�r ve diziye atan�r
	    
	    a_ogrNo[i] = ogrNo;
	    a_satir[i] = satir;
	    i++;
	}
	
    int indis = binarySearch(a_ogrNo, ogrenciNo, 0, diziUzunlugu - 1);		// binary search fonksiyonuyla arad���m�z a�nahtar�n index numaras�n� al�r�z
	int yedek = indis;
	
	
	int tumSonuclar[diziUzunlugu];							// Bu dizide ogrenciNosuna kar��l�k gelen adresler tutulur
	int tumSonuclarIndis = 0;
	
	for(i = 0; i < diziUzunlugu; i++){			// dizinin i�i bo�alt�l�r
		tumSonuclar[i] = -1;
	}

	
	while(yedek != 0 && a_ogrNo[yedek - 1] == ogrenciNo){  // sola do�ru kay			// ayn� anahtardan birden �ok olabilir o y�zden indisini buldu�umuz s�ral� index tablosundaki de�erin soluna do�ru bakar�z ayn� ogrenci numaras�ndan(anahtardan) ba�ka varm� diye
			tumSonuclar[tumSonuclarIndis] = a_satir[yedek - 1];
			tumSonuclarIndis++;
			yedek--;
	}	
	
	
	
	yedek = indis;
	
	while(yedek != diziUzunlugu - 1 && a_ogrNo[yedek + 1] == ogrenciNo){		// sa�a do�ru kay		// bulunan index de�erinin sa� taraf�na da bak�l�r ayn� anahtardan ba�ka var m� diye zten anahtarlar ard���k s�ral� 
		tumSonuclar[tumSonuclarIndis] = a_satir[yedek + 1];
		tumSonuclarIndis++;
		yedek++;
	}
	
	
	tumSonuclar[tumSonuclarIndis] = a_satir[indis];		// son olarak ta �lk ba�ta buldu�umuz indis at�l�r
	tumSonuclarIndis++;
	
	// Sonu� olarak tumSonuclar dizimizde ilk buldu�umuz adres, o anahtar�n ayn�s� olan sa��ndaki adresler ve o anahtar�n ayn�s� olan solundaki adres de�erleri al�n�r
	

    fclose(dosya);		// dosya kapan�r
    
    
    i = 0;

    
    int tumSonuclarinUzunlugu = 0;
    struct veri arananKisi;
    	// aranan ki�i nesnemiz

    
    fopen_s(&dosya, "veri.bin", "rb");		// veri dosyas� a��l�r
    
    int satirSirasi = 0;
    printf("\nNo   Puan   DersKodu   Sube\n");		// k�sa �zet yaz�
    while(fread(&arananKisi, sizeof(struct veri), 1, dosya) == 1){		// veri dosyam�zda sat�r sat�r gezeriz
    	i = 0;
    	while(tumSonuclar[i] != -1){			// tumSonuclar dizimizisin eleman� -1 olmad��� s�rece
    		if(satirSirasi == tumSonuclar[i]){	// gezdi�miz sat�rla buldu�umuz adres de�erleri e�le�iyorsa	
    			printf(" \n%d\t%d\t%d\t%c", arananKisi.ogrNo, arananKisi.puan, arananKisi.dersKodu,arananKisi.sube );		// o sat�r bilgilerini yazar�z
			}
			i++;
		}
		satirSirasi++;
	}
	

    fclose(dosya);		// dosyay� kapat�r�z
}



int binarySearch(int array[], int x, int low, int high) {	// ama� arad���m�z de�erini orta de�erlere g�re kar��la�t�r�p indisini geri d�nd�rmektir
  if (high >= low) {			// e�er high lowdan y�ksekse
    int mid = low + (high - low) / 2; // 		// orta de�er bunlar�n ortalamas�d�r

    // If found at mid, then return it
    if (array[mid] == x)			// e�er eleman dizi ortas�nda ise orta indis d�nd�r
      return mid;

    // Search the left half
    if (array[mid] > x)		// sa� taraftaysa sa�da kalanlar�n en ortas�na bakarak devam et
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);		// sol taraftaysa sola do�ru bak
    
  }

  return -1;
}

void kayitSil(){
	int ogrenciNumarasi;
	int ogrenciPuani;
	
	int silinecekSatir;
	printf("Silienecek Ogrencinin Numarasi : ");
	scanf("%d", &ogrenciNumarasi);
	
	printf("Silinecek Ogrencinin Puani : ");
    scanf("%d", &ogrenciPuani);
	
	// numara ve puan� ay�rt edici olsun diye ald�k
	
	struct veri ogr[1000];

	FILE *dosya;
	fopen_s(&dosya, "veri.bin", "rb");// veri dosyas�n� a�
	
	
	int indis = 0;
	while(fread(&ogr[indis], sizeof(struct veri), 1, dosya) == 1){
		indis++;
	}		// veri dosyas�n� diziye aktar

	int i, j;
	for(i = 0; i < indis; i++){		
		if(ogrenciNumarasi == ogr[i].ogrNo && ogrenciPuani == ogr[i].puan ){ // e�er arad���m�z eleman buysa de�erlerini -1 e e�itle
			ogr[i].ogrNo = -1;
			ogr[i].puan = -1;
			ogr[i].dersKodu = -1;
			ogr[i].sube = 'q';
		}
	}
	
	fclose(dosya);		// dosyay� kapat
	
	dosya = fopen("veri.bin", "wb"); // dosyay� yazma modunda a�
	
	for(j = 0; j < indis; j++){		// -1 e�it olan de�erler hariicndekileri yaz dosyaya
		if(ogr[j].ogrNo != -1){
			fwrite(&ogr[j], sizeof(veri),1, dosya);	
		}
	}
	
	

	indexDosyasiOlustur();		// index dosyas�n� g�ncelle
	fclose(dosya);
	
}

void kayitGuncelle(){
	int ogrenciNumarasi;
	int ogrenciDersKodu;
	int silinecekSatir;
	int yeniPuan;
	
	printf("Guncellenecek Ogrencinin Numarasi : ");
	scanf("%d", &ogrenciNumarasi);
	
	printf("Guncellenecek Ogrencinin Ders Kodu : ");
	scanf("%d", &ogrenciDersKodu);


	printf("YENI PUAN : ");
	scanf("%d", &yeniPuan);	
	

	FILE *dosya;
	dosya = fopen("veri.bin", "rb");
	
	struct veri ogr[1000];
	
	int i = 0,j;
	while(fread(&ogr[i], sizeof(struct veri), 1, dosya) == 1){		// veri dosyas�ndaki elemanlar� diziye aktar
		i++;
	}
	int sayac = 0;
	for( j = 0;j < i; j++){			 // elemanlar aras�nda tek tek gez
		if(ogr[j].ogrNo == ogrenciNumarasi && ogr[j].dersKodu == ogrenciDersKodu){		//ogrenci numarasi ve ders kodu e�le�yiorsa o elemanla
			sayac++;
			ogr[j].puan = yeniPuan;		// puan�n� de�i�tir
		}
	}
	if(sayac == 0){			// �sayac artmam��sa �yle biri yoktur
		printf("Kisi bulunamadi");
	}
	fclose(dosya);
	remove("veri.bin");		// dosyay� sil
	
	
	dosya = fopen("veri.bin", "wb");  // dosyay� olu�tur
	
	for(j = 0; j < i; j++){			// dosyaya yeni de�erleri yaz
		fwrite(&ogr[j], sizeof(veri),1, dosya);
	}
	
	indexDosyasiOlustur();		// index dosyas�n� g�ncelle
	fclose(dosya);
}

void veriDosyasiniGoster(){   // 6
	
	struct veri ogr[1000];

	FILE *dosya;
	fopen_s(&dosya, "veri.bin", "rb");		// veri dosyas�n� a�
	

	int indis = 0;
	while(fread(&ogr[indis], sizeof(struct veri), 1, dosya) == 1){		//eleman bitene kadar diziye aktar
		indis++;
	}

	int i, j;
	printf("No      Puan  DersKodu Sube\n");			// diziyi tek tek gez ve dizinin elemanlar�n� yazd�r
	for(i = 0; i < indis; i++){
		
		printf("%d\t",ogr[i].ogrNo);
		printf("%d\t",ogr[i].puan);
		printf("%d\t",ogr[i].dersKodu);
		printf("%c\n",ogr[i].sube);
	}
	
	fclose(dosya);
}

void indexDosyasiniGoster(){
	FILE* dosya;
	
	dosya = fopen("index.txt","r"); // index dosyas�n� oku
	
	int ogrNo;
	int satirSirasi;
	
	printf("Anahtar \t Adres \n");
    while(fscanf(dosya,"%d",&ogrNo)!=EOF)		// dosya bitene kadar elemanlar� ogrN� de�i�kenine ata
	{
		printf("%d \t", ogrNo);			// ogrNumaras�n� yazd�r
		fscanf(dosya,"%d", &satirSirasi);		// sAdresi de �ek
		printf("%d \n", satirSirasi);			// adresi de yazd�r
	}
}

void indexDosyasiniSil(){
	remove("index.txt");		// index dosyas�n� kald�r
}


