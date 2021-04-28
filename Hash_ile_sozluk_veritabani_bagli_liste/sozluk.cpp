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
			sozluk1=fopen("sozluk1.txt","r");						// sozluk1.txt den istedi�imiz sat�r� �ekiyoruz
			for(i=0;i<sn;i++)
			fgets(satir,sizeof(satir),sozluk1);
			fclose(sozluk1);
		}
		
		/*-------TR karakterleri degistir-------*/
		void trharfleridegistir(int i){
			int j=0;
				while(j<78){    									
					
					if(tr[i][j]=='�' || tr[i][j]=='�'){
						tr[i][j]='s';
					}
					
					if(tr[i][j]=='�' || tr[i][j]=='�'){
						tr[i][j]='c';
					}
					
					if(tr[i][j]=='�' || tr[i][j]=='�'){
						tr[i][j]='i';
					}
					
					if(tr[i][j]=='�' || tr[i][j]=='�'){
						tr[i][j]='g';
					}
					
					if(tr[i][j]=='�'||tr[i][j]=='�'){
						tr[i][j]='o';
					}
					
					if(tr[i][j]=='�' ||tr[i][j]=='�'){
						tr[i][j]='u';
					}
					
					j++;
			}
		}



		/*----TUM HARFLER HARFLER� BUYUTULDU----*/
		void harfbuyut(int i){
			int j=0;
			while(j<37){	
				if(eng[i][j]>='a' && eng[i][j]<='z'){			//ENG dizisindeki HARFLER� B�Y�T
						eng[i][j]-=32;
				}		
				j++;
			}
			j=0;
			
			while(j<78){	
				if(tr[i][j]>='a' && tr[i][j]<='z'){				//TR dizisindeki HARFLER� B�Y�T
					tr[i][j]-=32;	
				}
				j++;
			}				
		}
		
		/*------�ND�S� ALINAN KE�MEN�N HASH�N� BUL------*/
		int hashbul(int i){
			int toplam=0;	
			for(int j=0;j<37;j++){
				if(eng[i][j]!=32){
						toplam+=(eng[i][j]*asal[j]);			// toplam de�eri bo� karakter haricinde di�er karakterlerin hash toplam�
				}				
			}
			
			toplam=toplam%5721;									// toplam tablo boyutuna g�re modudur
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
		harfbuyut(i);										//SONRA t�m harfleri b�y�k yap
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
	
	typedef bagli node;										// node adl� d���m olu�tur
	
	node *aktif;
	node *aktif2;
	node *engbas[5721];										// ing kelimeler i�in root olu�turuldu
	node *trbas[5721];										// tr kelimeler i�in root olu�turuldu
	
	
	
	
	
	/*----------KEL�MELER�N HASH� HESAPLANIP YER�NE OTURACAK----------*/
	
	for(i=0;i<5721;i++){
	
		int toplam=hashbul(i);								//hash hesaplama yeri
	

		if(engbas[toplam]==NULL)							//ing . kelimenin yerle�ece�i yer bo�sa
		{	
		
			engbas[toplam]=(node *)malloc(sizeof(node));	//engbas'a yer a�
			trbas[toplam]=(node *)malloc(sizeof(node));		//trbas'a yer a�
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
		}													// e�er �ak��ma varsa
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
			aktif->sonraki->sonraki=NULL;					//bos olan yerin sonras�na NULL ata
			
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
	//													S�ZL�K1.TXT YE YAZDIRILAN KOD BLO�U
	
		//	BU KISIMDA SOZLUK1.TXT YE KEL�MELER� D�ZENLEY�P YERLE�T�RD�K
			
			
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
				if(kelime[j]>='a' && kelime[j]<='z'){			//ENG dizisindeki HARFLER� B�Y�T
						kelime[j]-=32;
				}		
				j++;
			}
			
			j=0;
			
			for(int j=0;j<37;j++){
				if(kelime[j]!=32){
						toplam+=(kelime[j]*asal[j]);			// toplam de�eri bo� karakter haricinde di�er karakterlerin hash toplam�
				}				
			}
			
			toplam=toplam%5721;									// toplam tablo boyutuna g�re modudur
			
			satiroku((toplam*2)+1);								// girilen kelimeyle hashi ayn� olan sat�r� �ek
			j=0;
			e=0;
			sayac =0;
			
			while(j<1000){
				if(kelime[e]==satir[j]){						// girilen kelimeyle istenilenin harflerini kar��la�t�r
					e++;										
					j++;
					
					if(e==strlen(kelime)){						//e�er t�m harfler uyu�tuysa d�ng�y� k�r
						break;
					}
				}else{
					e=0;
					while(satir[j]!='*'){						// e�er girilen kelime de�ilse bi sonraki y�ld�za kadar ilerle
						j++;
					}
					sayac++;									//Ba�l� listede ka��nc� eleman oldu�unu ��renmek i�in sayac� artt�r
					j+=1;
				}
			}
			
			sayac/=2;
			int t=0;
			e=0;		
			satiroku((toplam*2)+2);								// bu sayede kelimenin txt'de t�rk�e ba�l� listesine eri�tik
			
			while(sayac>=0){									// girilen kelime ka��nc� y�ld�zdan sonraysa
				if(sayac==0){
					while(satir[e]!='*'){
						printf("%c",satir[e]);					// t�rk�eside o kadar y�ld�zdan sonrad�r ve t�rk�eyi yazd�r
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
