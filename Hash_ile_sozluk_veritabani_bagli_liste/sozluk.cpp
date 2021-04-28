#include<stdio.h>
#include<stdlib.h>
#include<cstdlib>
#include<conio.h>
#include<string.h>

char eng[5721][37];
char tr[5721][78];
int asal[37]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157};

		
		char satir[1000];
		
		FILE *sozluk1;
		
		void satiroku(int sn){
			int i=0;
			sozluk1=fopen("sozluk1.txt","r");						// sozluk1.txt den istediðimiz satýrý çekiyoruz
			for(i=0;i<sn;i++)
			fgets(satir,sizeof(satir),sozluk1);
			fclose(sozluk1);
		}
		
		/*-------TR karakterleri degistir-------*/
		void trharfleridegistir(int i){
			int j=0;
				while(j<78){    									
					
					if(tr[i][j]=='þ' || tr[i][j]=='Þ'){
						tr[i][j]='s';
					}
					
					if(tr[i][j]=='ç' || tr[i][j]=='Ç'){
						tr[i][j]='c';
					}
					
					if(tr[i][j]=='ý' || tr[i][j]=='Ý'){
						tr[i][j]='i';
					}
					
					if(tr[i][j]=='ð' || tr[i][j]=='Ð'){
						tr[i][j]='g';
					}
					
					if(tr[i][j]=='ö'||tr[i][j]=='Ö'){
						tr[i][j]='o';
					}
					
					if(tr[i][j]=='ü' ||tr[i][j]=='Ü'){
						tr[i][j]='u';
					}
					
					j++;
			}
		}



		/*----TUM HARFLER HARFLERÝ BUYUTULDU----*/
		void harfbuyut(int i){
			int j=0;
			while(j<37){	
				if(eng[i][j]>='a' && eng[i][j]<='z'){			//ENG dizisindeki HARFLERÝ BÜYÜT
						eng[i][j]-=32;
				}		
				j++;
			}
			j=0;
			
			while(j<78){	
				if(tr[i][j]>='a' && tr[i][j]<='z'){				//TR dizisindeki HARFLERÝ BÜYÜT
					tr[i][j]-=32;	
				}
				j++;
			}				
		}
		
		/*------ÝNDÝSÝ ALINAN KEÝMENÝN HASHÝNÝ BUL------*/
		int hashbul(int i){
			int toplam=0;	
			for(int j=0;j<37;j++){
				if(eng[i][j]!=32){
						toplam+=(eng[i][j]*asal[j]);			// toplam deðeri boþ karakter haricinde diðer karakterlerin hash toplamý
				}				
			}
			
			toplam=toplam%5721;									// toplam tablo boyutuna göre modudur
			return toplam;
		}

	
int main() {
	
	int i=0,j=0;

	FILE *fp;
	fp=fopen("sozluk.txt","r");
	
	while(i<5721){											// sozlukten tum kelimeler cekildi
		fgets(eng[i],37,fp);
		fgets(tr[i],80,fp);
		
		
	
		
		i++;
	}
	i=0;
	fclose(fp);

	while(i<5721){
		trharfleridegistir(i);								//TR olan harfleri degistir
		harfbuyut(i);										//SONRA tüm harfleri büyük yap
		i++;
	}
	i=0;
	
	
	int toplam=0;											
	int e=0;

	struct bagli{											// bagli liste dizi nesne
		char trdizi[78];
		char engdizi[37];
		bagli * sonraki;
	};
	
	typedef bagli node;										// node adlý düðüm oluþtur
	
	node *aktif;
	node *aktif2;
	node *engbas[5721];										// ing kelimeler için root oluþturuldu
	node *trbas[5721];										// tr kelimeler için root oluþturuldu
	
	
	
	
	
	/*----------KELÝMELERÝN HASHÝ HESAPLANIP YERÝNE OTURACAK----------*/
	
	for(i=0;i<5721;i++){
	
		int toplam=hashbul(i);								//hash hesaplama yeri
	

		if(engbas[toplam]==NULL)							//ing . kelimenin yerleþeceði yer boþsa
		{	
		
			engbas[toplam]=(node *)malloc(sizeof(node));	//engbas'a yer aç
			trbas[toplam]=(node *)malloc(sizeof(node));		//trbas'a yer aç
			engbas[toplam]->sonraki=NULL;					//engbas sonraki ne NULL ata
			trbas[toplam]->sonraki=NULL;					//trbas sonraki ne NULL ata
			
			while(e<37){				
				engbas[toplam]->engdizi[e]=eng[i][e];		//engbas'a karakter al
				e++;
			}
			e=0;
			j=0;
			while(j<78){
				trbas[toplam]->trdizi[j]=tr[i][j];			//trbas'a karakter al
				j++;
			}
			j=0;	
		}													// eðer çakýþma varsa
		else
		{
			
			aktif=engbas[toplam];							//aktif engbas oldu
			while(aktif->sonraki!=NULL){
				aktif=aktif->sonraki;						//aktif son dolu yere geldi
			}
			
			aktif->sonraki=(node *)malloc(sizeof(node));	//bos olan node'a yer ata
			
			while(e<37){
				aktif->sonraki->engdizi[e]=eng[i][e];		//bos olan yere karakter al
				e++;
			}
			e=0;
			aktif->sonraki->sonraki=NULL;					//bos olan yerin sonrasýna NULL ata
			
			//TR KISMI
			
					
			aktif=trbas[toplam];							//aktif trbas oldu
			while(aktif->sonraki!=NULL){
				aktif=aktif->sonraki;						//dolu olan son node'a kadar gel
			}
							
			aktif->sonraki=(node *)malloc(sizeof(node));	//bos olan node'a yer ac	
		
			while(e<78){
				aktif->sonraki->trdizi[e]=tr[i][e];			//bos olan yere karakter al
				e++;
			}
			e=0;
			
			aktif->sonraki->sonraki=NULL;					//dolan yerin sonrakine NULL ata
		}
		
	}

	int sayac=0;
	j=0;
	e=0;
	char dinamik[1000];
	//													SÖZLÜK1.TXT YE YAZDIRILAN KOD BLOÐU
	
		//	BU KISIMDA SOZLUK1.TXT YE KELÝMELERÝ DÜZENLEYÝP YERLEÞTÝRDÝK
			
			
		FILE *fp1;
		fp1=fopen("sozluk1.txt","a");
			for(i=0;i<5721;i++){
				aktif=engbas[i];
				aktif2=trbas[i];
				
				if(aktif!=NULL){
					
					while(aktif!=NULL){
						while(j<37){
							if(aktif->engdizi[j]==32 && aktif->engdizi[j+1]==32)
							{
								break;
							}
							fprintf(fp1,"%c",aktif->engdizi[j]);
							j++;
						}
						j=0;
						aktif=aktif->sonraki;
						fprintf(fp1,"**");
					}
					fprintf(fp1,"\n");
					
					
					while(aktif2!=NULL){
						for(j=0;j<78;j++){
							dinamik[e]=aktif2->trdizi[j];
							e++;
							
							if(aktif2->trdizi[j+2] == NULL){
								dinamik[e]='*';
								dinamik[e+1]='*';
								e+=2;
								break;
							}
							
							
							
						}
						
						aktif2=aktif2->sonraki;
					}
					fprintf(fp1,"%s\n",dinamik);
					e=0;
					j=0;
					while(j<1000){
						dinamik[j]=NULL;
						j++;
					}
					j=0;
				}
				else{
					fprintf(fp1,"bos\nbos\n");
				}
					
			}
		
		
			
		
			printf("kelime gir :");
			char kelime[37];
			gets(kelime);

			toplam=0;
				
			while(j<37){	
				if(kelime[j]>='a' && kelime[j]<='z'){			//ENG dizisindeki HARFLERÝ BÜYÜT
						kelime[j]-=32;
				}		
				j++;
			}
			
			j=0;
			
			for(int j=0;j<37;j++){
				if(kelime[j]!=32){
						toplam+=(kelime[j]*asal[j]);			// toplam deðeri boþ karakter haricinde diðer karakterlerin hash toplamý
				}				
			}
			
			toplam=toplam%5721;									// toplam tablo boyutuna göre modudur
			
			satiroku((toplam*2)+1);								// girilen kelimeyle hashi ayný olan satýrý çek
			j=0;
			e=0;
			sayac =0;
			
			while(j<1000){
				if(kelime[e]==satir[j]){						// girilen kelimeyle istenilenin harflerini karþýlaþtýr
					e++;										
					j++;
					
					if(e==strlen(kelime)){						//eðer tüm harfler uyuþtuysa döngüyü kýr
						break;
					}
				}else{
					e=0;
					while(satir[j]!='*'){						// eðer girilen kelime deðilse bi sonraki yýldýza kadar ilerle
						j++;
					}
					sayac++;									//Baðlý listede kaçýncý eleman olduðunu öðrenmek için sayacý arttýr
					j+=1;
				}
			}
			
			sayac/=2;
			int t=0;
			e=0;		
			satiroku((toplam*2)+2);								// bu sayede kelimenin txt'de türkçe baðlý listesine eriþtik
			
			while(sayac>=0){									// girilen kelime kaçýncý yýldýzdan sonraysa
				if(sayac==0){
					while(satir[e]!='*'){
						printf("%c",satir[e]);					// türkçeside o kadar yýldýzdan sonradýr ve türkçeyi yazdýr
						e++;
					}
					break;
				}else{
					while(1){
						if(satir[e]=='*' && satir[e+1]=='*'){
							sayac--;
							e+=2;
							break;
						}
						e++;
					}
		
				}
			}

    return 0;
}
