#include<stdio.h>


int main()
{
	int i=0;
	char sifre[20];
	printf("--------------Telefon Tuslama Sistemi--------------\n\n\n");
	int sayi=1;
	printf("  ----------------------------\n");
	printf(" |  |1|   |   |2|   |   |3|   |\n")	;
	printf(" |  ( )   |   ABC   |   DEF   |\n");
	printf("  ----------------------------\n");
	printf(" |  |4|   |   |5|   |   |6|   |\n")	;
	printf(" |  GHI   |   JKL   |   MNO   |\n");
	printf("  ----------------------------\n");
	printf(" |  |7|   |   |8|   |   |9|   |\n")	;
	printf(" |  PRS   |   TUV   |   XYZ   |\n");
	printf("  ----------------------------\n");
	
	printf("\n\n[ Lutfen Tuslamaya Baslayiniz ]\n\n");

	
	while(sayi!=0)
	{
			printf("%d.HARF = ",i+1);
			scanf("%d",&sayi);
		
		if (sayi==1)
		{
			
			sifre[i]=' ';
			i++;
		
		}
	 		else if(sayi==2)
		{
				sifre[i]='a';
			i++;
		
			
		}
			else if(sayi==22)
		{
				sifre[i]='b';
			i++;
		
			
		}
			else if(sayi==222)
		{
				sifre[i]='c';
			i++;
			
			
		}
			else if(sayi==3)
		{
				sifre[i]='d';
			i++;
		
			
		}
			else if(sayi==33)
		{
				sifre[i]='e';
			i++;
		
		}
			else if(sayi==333)
		{
				sifre[i]='f';
			i++;
		
		}
			else if(sayi==4)
		{
				sifre[i]='g';
			i++;
		
		}
			else if(sayi==44)
		{
				sifre[i]='h';
			i++;
		
		}
			else if(sayi==444)
		{
				sifre[i]='i';
			i++;
		
		}
			else if(sayi==5)
		{
				sifre[i]='j';
			i++;
		
			
		}
			else if(sayi==55)
		{
				sifre[i]='k';
			i++;
		}
			else if(sayi==555)
		{
			sifre[i]='l';
			i++;
	
			
		}
			else if(sayi==6)
		{
				sifre[i]='m';
			i++;
	
		}
			else if(sayi==66)
		{
				sifre[i]='n';
			i++;
		
		}
			else if(sayi==666)
		{
				sifre[i]='o';
			i++;
		
		}
			else if(sayi==7)
		{
				sifre[i]='p';
			i++;

			
		}
			else if(sayi==77)
		{
				sifre[i]='r';
			i++;
	
		}
			else if(sayi==777)
		{
				sifre[i]='s';
			i++;
	
		}
			else if(sayi==8)
		{
				sifre[i]='t';
			i++;
	
		}
			else if(sayi==88)
		{
				sifre[i]='u';
				i++;
		}
			else if(sayi==888)
		{
				sifre[i]='v';
			i++;
		
			
		}
			else if(sayi==9)
		{
			sifre[i]='x';
			i++;
		
		}
			else if(sayi==99)
		{
			sifre[i]='y';
			i++;
		
			
		}
			else if(sayi==999)
		{
			sifre[i]='z';
			i++;
		
		}
		else if(sayi==0)
		{
			break;
			
		}
		else
		{
	 		printf("boyle bir tuslama yok sayiyi tekrar gir\n");
		}
		
	}
	
	printf("\n\nSifreniz : ");
	i=0;
	while(sifre[i]!='\0')
	{
		printf("%c",sifre[i]);
		i++;
	}
		
	return 0;
}
