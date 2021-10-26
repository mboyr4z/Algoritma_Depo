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
		
	    scanf("%d",&secim);		// secim alýnýr
	
		switch(secim) {			// seçime göre yinlendirilir fonksiyona
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

	// VERÝ DOSYASINDA ELEMANLAR OKUNUR

	struct veri ogr[1000];		// rastgele uzunlukta ogrenci listesi

	FILE *dosya;				// dosya degiskeni
	fopen_s(&dosya, "veri.bin", "rb");		// bin dosyasý dosya okuma modunda açýldý
	

	
	int satir = 0;
	while(fread(&ogr[satir], sizeof(struct veri), 1, dosya) == 1){		// satýrlar bitene kadar bin dosyasýný oku
		if(ogr[satir].dersKodu != -1){									// eðer derskodu -1 deðilse devam et, -1 olan satýralr silinmiþ demektir
			satir++;		
		}
	}

	fclose(dosya);			// dosyayý kapat
	
	
	// ýndex dosyasýna yerleþtirmeden önce sýralama yapýlýr
	int i, j, yedek;
	
	struct index indexler[1000];			// rastgele index dizisi oluþturuldu
	
	
	
	for(i = 0; i < satir; i++){					// elemanlar diziye aktarýldý
		indexler[i].ogrNo = ogr[i].ogrNo;		// indexlerin ogrensi nosu bin dosyasýndan alýnýr		
		indexler[i].adres = i;					// adres ise bin dosyasýndaki satýrdýr
	}
	
	
	for(i = 0; i < satir - 1; i++){		// index tablosu anahtar deðerimne yani ogrenci nosuna göre sýralanýr ayný þekilde adres de yer deðiþtirir
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
	
	
	FILE * indexDosyasi;			// indexdosyasýna gir
	indexDosyasi = fopen("index.txt", "w" );		// uzerine yazma modunda aç
		
	for(i = 0;i < satir; i++){
		fprintf(indexDosyasi, "%d %d\n", indexler[i].ogrNo, indexler[i].adres);		// satir sayýsý kadar index elemanlarýný yaz
	}
	
    fclose(indexDosyasi);		// index dosyasi kapatýldý
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
	// 4 adet eklenecek adam verisi alýndý

	FILE *veriDosyasi = fopen("veri.bin", "ab" );		// dosya üzerine yazma modunda açýldý
	
	
	if(veriDosyasi == NULL){		// dosya var mý kontrol
		return;
	}

    fwrite(&ogr, sizeof(veri),1, veriDosyasi);		// veri dosyasýna ekle bin dosyasý yani
	fclose(veriDosyasi);		// dosya kapa
	 
	 
	
	indexDosyasiOlustur();				// her eklemede tekrar indexkeme yap
	 
	 
}

void kayitBul(){
	int ogrenciNo;
	printf("ogrenciNo giriniz : ");
	scanf("%d", &ogrenciNo);		// kaydi bulunacak ogrenci no alýnýr
	

	int ogrNo;
	int satir;
	
	int i = 0,j, diziUzunlugu = 0;
	
	FILE * dosya;		// index dosyasý okuma modunda açýlýr
	dosya = fopen("index.txt","r");
	
	while(fscanf(dosya,"%d",&ogrNo)!=EOF)
	{
	    diziUzunlugu++;
	}
	// index dosyasýna kaç eleman olacaðý belirlenir
	
	
	fclose(dosya);		// dosya kapatýlýr
	diziUzunlugu /= 2;  // kaç satýr olduðu bulundu /2 yapýlmasýnýn nedeni index tablosunda 2 adet deðiþken olmasý
	
	dosya = fopen("index.txt","r");		// tekrar index dosyasý açýlýr
	
	int a_ogrNo[diziUzunlugu];		// dizi boyutlarý dinamik olarak belirlenir
	int a_satir[diziUzunlugu];
	
	
    while(fscanf(dosya,"%d",&ogrNo)!=EOF)					// dosya boþalana kadar
	{
		fscanf(dosya,"%d", &satir);				// ogrenciNo(anahtar) ve satir(adres) deðiþkenleri alýnýr ve diziye atanýr
	    
	    a_ogrNo[i] = ogrNo;
	    a_satir[i] = satir;
	    i++;
	}
	
    int indis = binarySearch(a_ogrNo, ogrenciNo, 0, diziUzunlugu - 1);		// binary search fonksiyonuyla aradýðýmýz aýnahtarýn index numarasýný alýrýz
	int yedek = indis;
	
	
	int tumSonuclar[diziUzunlugu];							// Bu dizide ogrenciNosuna karþýlýk gelen adresler tutulur
	int tumSonuclarIndis = 0;
	
	for(i = 0; i < diziUzunlugu; i++){			// dizinin içi boþaltýlýr
		tumSonuclar[i] = -1;
	}

	
	while(yedek != 0 && a_ogrNo[yedek - 1] == ogrenciNo){  // sola doðru kay			// ayný anahtardan birden çok olabilir o yüzden indisini bulduðumuz sýralý index tablosundaki deðerin soluna doðru bakarýz ayný ogrenci numarasýndan(anahtardan) baþka varmý diye
			tumSonuclar[tumSonuclarIndis] = a_satir[yedek - 1];
			tumSonuclarIndis++;
			yedek--;
	}	
	
	
	
	yedek = indis;
	
	while(yedek != diziUzunlugu - 1 && a_ogrNo[yedek + 1] == ogrenciNo){		// saða doðru kay		// bulunan index deðerinin sað tarafýna da bakýlýr ayný anahtardan baþka var mý diye zten anahtarlar ardýþýk sýralý 
		tumSonuclar[tumSonuclarIndis] = a_satir[yedek + 1];
		tumSonuclarIndis++;
		yedek++;
	}
	
	
	tumSonuclar[tumSonuclarIndis] = a_satir[indis];		// son olarak ta þlk baþta bulduðumuz indis atýlýr
	tumSonuclarIndis++;
	
	// Sonuç olarak tumSonuclar dizimizde ilk bulduðumuz adres, o anahtarýn aynýsý olan saðýndaki adresler ve o anahtarýn aynýsý olan solundaki adres deðerleri alýnýr
	

    fclose(dosya);		// dosya kapanýr
    
    
    i = 0;

    
    int tumSonuclarinUzunlugu = 0;
    struct veri arananKisi;
    	// aranan kiþi nesnemiz

    
    fopen_s(&dosya, "veri.bin", "rb");		// veri dosyasý açýlýr
    
    int satirSirasi = 0;
    printf("\nNo   Puan   DersKodu   Sube\n");		// kýsa özet yazý
    while(fread(&arananKisi, sizeof(struct veri), 1, dosya) == 1){		// veri dosyamýzda satýr satýr gezeriz
    	i = 0;
    	while(tumSonuclar[i] != -1){			// tumSonuclar dizimizisin elemaný -1 olmadýðý sürece
    		if(satirSirasi == tumSonuclar[i]){	// gezdiðmiz satýrla bulduðumuz adres deðerleri eþleþiyorsa	
    			printf(" \n%d\t%d\t%d\t%c", arananKisi.ogrNo, arananKisi.puan, arananKisi.dersKodu,arananKisi.sube );		// o satýr bilgilerini yazarýz
			}
			i++;
		}
		satirSirasi++;
	}
	

    fclose(dosya);		// dosyayý kapatýrýz
}



int binarySearch(int array[], int x, int low, int high) {	// amaç aradýðýmýz deðerini orta deðerlere göre karþýlaþtýrýp indisini geri döndürmektir
  if (high >= low) {			// eðer high lowdan yüksekse
    int mid = low + (high - low) / 2; // 		// orta deðer bunlarýn ortalamasýdýr

    // If found at mid, then return it
    if (array[mid] == x)			// eðer eleman dizi ortasýnda ise orta indis döndür
      return mid;

    // Search the left half
    if (array[mid] > x)		// sað taraftaysa saðda kalanlarýn en ortasýna bakarak devam et
      return binarySearch(array, x, low, mid - 1);

    // Search the right half
    return binarySearch(array, x, mid + 1, high);		// sol taraftaysa sola doðru bak
    
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
	
	// numara ve puaný ayýrt edici olsun diye aldýk
	
	struct veri ogr[1000];

	FILE *dosya;
	fopen_s(&dosya, "veri.bin", "rb");// veri dosyasýný aç
	
	
	int indis = 0;
	while(fread(&ogr[indis], sizeof(struct veri), 1, dosya) == 1){
		indis++;
	}		// veri dosyasýný diziye aktar

	int i, j;
	for(i = 0; i < indis; i++){		
		if(ogrenciNumarasi == ogr[i].ogrNo && ogrenciPuani == ogr[i].puan ){ // eðer aradýðýmýz eleman buysa deðerlerini -1 e eþitle
			ogr[i].ogrNo = -1;
			ogr[i].puan = -1;
			ogr[i].dersKodu = -1;
			ogr[i].sube = 'q';
		}
	}
	
	fclose(dosya);		// dosyayý kapat
	
	dosya = fopen("veri.bin", "wb"); // dosyayý yazma modunda aç
	
	for(j = 0; j < indis; j++){		// -1 eþit olan deðerler hariicndekileri yaz dosyaya
		if(ogr[j].ogrNo != -1){
			fwrite(&ogr[j], sizeof(veri),1, dosya);	
		}
	}
	
	

	indexDosyasiOlustur();		// index dosyasýný güncelle
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
	while(fread(&ogr[i], sizeof(struct veri), 1, dosya) == 1){		// veri dosyasýndaki elemanlarý diziye aktar
		i++;
	}
	int sayac = 0;
	for( j = 0;j < i; j++){			 // elemanlar arasýnda tek tek gez
		if(ogr[j].ogrNo == ogrenciNumarasi && ogr[j].dersKodu == ogrenciDersKodu){		//ogrenci numarasi ve ders kodu eþleþyiorsa o elemanla
			sayac++;
			ogr[j].puan = yeniPuan;		// puanýný deðiþtir
		}
	}
	if(sayac == 0){			// ösayac artmamýþsa öyle biri yoktur
		printf("Kisi bulunamadi");
	}
	fclose(dosya);
	remove("veri.bin");		// dosyayý sil
	
	
	dosya = fopen("veri.bin", "wb");  // dosyayý oluþtur
	
	for(j = 0; j < i; j++){			// dosyaya yeni deðerleri yaz
		fwrite(&ogr[j], sizeof(veri),1, dosya);
	}
	
	indexDosyasiOlustur();		// index dosyasýný güncelle
	fclose(dosya);
}

void veriDosyasiniGoster(){   // 6
	
	struct veri ogr[1000];

	FILE *dosya;
	fopen_s(&dosya, "veri.bin", "rb");		// veri dosyasýný aç
	

	int indis = 0;
	while(fread(&ogr[indis], sizeof(struct veri), 1, dosya) == 1){		//eleman bitene kadar diziye aktar
		indis++;
	}

	int i, j;
	printf("No      Puan  DersKodu Sube\n");			// diziyi tek tek gez ve dizinin elemanlarýný yazdýr
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
	
	dosya = fopen("index.txt","r"); // index dosyasýný oku
	
	int ogrNo;
	int satirSirasi;
	
	printf("Anahtar \t Adres \n");
    while(fscanf(dosya,"%d",&ogrNo)!=EOF)		// dosya bitene kadar elemanlarý ogrNý deðiþkenine ata
	{
		printf("%d \t", ogrNo);			// ogrNumarasýný yazdýr
		fscanf(dosya,"%d", &satirSirasi);		// sAdresi de çek
		printf("%d \n", satirSirasi);			// adresi de yazdýr
	}
}

void indexDosyasiniSil(){
	remove("index.txt");		// index dosyasýný kaldýr
}


