#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<cmath>
#include<string>
#include <iomanip>
#include <fstream>
#include <sstream>
#include<typeinfo>

#define FILTERSIZE 100

using namespace std;

void printKernel(double** array, int fsize);
int imageSize, filterSize, whiteValue, blackValue;
int edgeWidth;

void getParameters();

// FUNCTIONS
double** getMatrix(int size);
double** getMatrixWithEdges(double** arr, int size, int edgeWidth);
double** randomVariables2Array(double** arr,int size,int max, int min);
double** zeroesAndMatrix(double** arr,int size);
double** createGaussian(int filterSize);
double** moveFilterOnMatrix(double** zeromatrix, double** gaussian, int EdgeImageSize, int gaussianSize, int imageSize);
double** cutToMatrix(double** bigMatrix, int imageSize);
void writeLine(int size);
void writeTxt();

// VARIABLES
double** image;
double** imageWithEdges;
double** rand_Array;
double** zeroMatrix;
double** gaussian;
double** filteredMatrix;
double** outputImage;
int parameterArray[4];
ofstream outfile;

int main(){	
   	outfile.open("outputs.txt");
	getParameters();
	imageSize = parameterArray[0];
	filterSize = parameterArray[1];
	whiteValue = parameterArray[2];
	blackValue = parameterArray[3];
	edgeWidth = filterSize / 2;
	
	
	image = getMatrix(imageSize);											// Resim olu�turuldu
	randomVariables2Array(image,imageSize,whiteValue,blackValue);			// Resime rastgele  de�errler atand�
	double** last_Arr = getMatrixWithEdges(image,imageSize,edgeWidth);		// kenarl�klar� eklendi	
	zeroMatrix = zeroesAndMatrix(last_Arr,(imageSize) + (edgeWidth * 2));   // 0 matrisi olu�turuldu ve i�erisine imageyi ald�
	gaussian = createGaussian(filterSize);									// gaussian olu�turuldu
	filteredMatrix = moveFilterOnMatrix(zeroMatrix, gaussian, (imageSize + (edgeWidth) * 2), filterSize, imageSize);		// filtreli resim elde edildi
	outputImage = cutToMatrix(filteredMatrix,imageSize);							// filtreli resim k�rp�larak ��kt� resimi verildi
	


	writeTxt();
	//printKernel(last_Arr,7);
	
	//printKernel(zeroMatrix,21);
	

	//printKernel(filteredMatrix,21);

	//printKernel(outputImage,imageSize);
	
	outfile.close();
	return 0;
}

void writeTxt(){
	outfile << "Input Image (" << imageSize << "x" << imageSize << ")\n";
	
	writeLine(imageSize*9);
	printKernel(image,imageSize);					// resim bast�r�ld�
	writeLine(imageSize*9);
	
	outfile << "Gaussian Filter (" << filterSize << "x" << filterSize << ")\n";
	
	writeLine(filterSize*9);
	printKernel(gaussian,filterSize);					// filtre bast�r�ld�
	writeLine(filterSize*9);
	
	outfile << "Input Grid: Edge Mirrored Image (21x21)\n";
	
	writeLine(21*9);
	printKernel(zeroMatrix,21);					// 0 l� ve kenarl� matris bast�r�ld�
	writeLine(21*9);
	
	outfile << "Output Grid: Cutted-Edge Image (21x21)\n";
	
	writeLine(21*9);
	printKernel(filteredMatrix,21);					// kenarlar� kesilmi� s�f�rl� matris bast�r�ld�
	writeLine(21*9);
	
	outfile << "Output (Filtered) Image ("<< imageSize << "x"<< imageSize <<")\n";
	
	writeLine(imageSize*9);
	printKernel(outputImage,imageSize);					// resim bast�r�ld�
	writeLine(imageSize*9);
	

}

void writeLine(int size){
	int i;
	for(i = 0; i < size ; i++){
		outfile << "-";
	}
	outfile << "\n";
}
void printKernel(double** array, int fsize){
	
	int i, j;
	for (i = 0; i < fsize; i++)
	{
		for (j = 0; j < fsize; j++)
		{
			outfile << fixed << setprecision(4) << setw(9) << array[i][j];	

		}
		outfile << "\n"; 
	}
}



double** cutToMatrix(double** bigMatrix, int imageSize){
	double** outputmatrix = getMatrix(imageSize);
	int i,j,baslangic;
	baslangic = (21 - imageSize) / 2;
	
	int satir = 0, sutun = 0;
	for(i = baslangic; i < baslangic + imageSize; i++){
		sutun = 0;
		for(j = baslangic; j < baslangic + imageSize; j++){
			outputmatrix[satir][sutun] = bigMatrix[i][j];
			sutun++;
		}
		satir++;
	}
	
	
	return outputmatrix;
}

// 	EN SON MOVEFILTERONMATRIX TE kald�n
double** moveFilterOnMatrix(double** zeromatrix, double** gaussian, int EdgeImageSize, int gaussianSize, int imageSize){
	double** yeniMatris = getMatrix(21);
	int i,j,satir,sutun;
	double toplam;
	int baslangic, bitis;
	baslangic = (21 - EdgeImageSize) / 2;
	
	
	
	for(satir = baslangic; satir < baslangic + imageSize; satir++){
		for(sutun = baslangic; sutun < baslangic + imageSize ; sutun++){
			toplam = 0;
			for(i = 0; i < gaussianSize ; i++){
				for(j = 0; j < gaussianSize; j++){
					//cout << gaussian[i][j] << " ";
					//cout << zeromatrix[satir+i][sutun+j] << " ";
					toplam += gaussian[i][j]*zeromatrix[satir + i][sutun + j];
				}
				
			}
		
		    yeniMatris[satir+1][sutun+1] = toplam;
			
		}
		cout << "\n";
	}
	return yeniMatris;
}

double** createGaussian(int filterSize){
	double** gaussian = getMatrix(filterSize);
	
	int i, j;
	
	for(i = 0; i < filterSize; i++){
		for(j = 0; j < filterSize; j++){
			gaussian[i][j] = 0.0370;
		}
	}
	return gaussian;
}

double** getMatrixWithEdges(double** arr, int size,int edgeWidth){
	
    double** last_Arr = getMatrix(size + 2);
    int i,j;
			// matris yarat�ld�

    for(i=0;i<size+2;i++){			// kenar de�erler hallediliyor
    	for(j=0;j<size+2;j++){
    		if(i==0 || i == size + 1 ||  j == 0 || j == size +1){
    			if(i == 0 && j == 0){							
					// sol �st k��e ise
    				last_Arr[0][0] = arr[0][0];
    				
				}else if(i == 0 && j == size + 1){			
						// sa� �st k��e ise
					last_Arr[0][size+1] = arr[0][size-1];
					
				}else if(j == 0 && i == size + 1){				
						// sol alt k��e ise
					last_Arr[size + 1][0] = arr[size - 1][0]; 
					
				}else if(i == size  + 1 && j == size + 1){  		
						// sa� atl k��e ise
					last_Arr[size + 1][size + 1] = arr[size - 1][size - 1];
					
				}else if(i == 0){
						// yukar� �ubuk
						last_Arr[0][j] =  arr[0][j-1];
						
				}else if(j == 0){
						// sol �ubuksa
						last_Arr[i][0] = arr[i-1][0];
						
				}else if(i == size + 1){
					    // alt �ubuksa
					    last_Arr[size + 1][j] = arr[size - 1][j - 1];
					    
				}else if(j == size + 1){
						last_Arr[i][size + 1] = arr[i - 1][size - 1];
				}
			}else{
				last_Arr[i][j] = arr[i-1][j-1];
			}
		}
	}
    edgeWidth -= 1;
    


	if(edgeWidth != 0){
    		return getMatrixWithEdges(last_Arr,size + 2,edgeWidth);
	}else{
			return last_Arr;
	}


}

double** zeroesAndMatrix(double** arr,int size){

	double** zerosMatrix = getMatrix(21);
	int i,j;
	for(i = 0; i < 21 ; i++){
		for(j = 0; j < 21; j++){
			zerosMatrix[i][j] = 0.0000;
		}
	}				// matrisin t�m elemanlar� s�f�rland�.
	
	int basDeger = (21 - size) / 2;
	int sonDeger = 21 - basDeger;
	for(i = basDeger;i < sonDeger ; i++){
		for(j = basDeger ; j < sonDeger ; j++){
			zerosMatrix[i][j] = arr[i - basDeger][j - basDeger];
		}
	}
	
	
	
	
	return zerosMatrix;
}

double** randomVariables2Array(double** arr,int size, int max, int min){
	int i,j;
	for(i = 0 ; i < size ; i++){
		for(j = 0 ; j < size ; j++){
			arr[i][j] = (double)((min + rand()) % max);
		}
	}
	return arr;
}

double** getMatrix(int size){
    double** arr = new double*[size];
    for(int i=0;i<size;i++){
        arr[i] = new double[size];
    }
	
	for(int i = 0;i < size; i++){
		for(int j = 0; j < size; j++){
			arr[i][j]=0.0;
		}
	}
    return arr;    
}

void getParameters(){ 

  ifstream dosyaOku("inputs.txt");
  string satir = "";
  int i=0;
  if ( dosyaOku.is_open() ){

    while ( getline(dosyaOku, satir) ){
	  if(i<4){
		  stringstream degree(satir);		// stringleri int �evirdik
	  int x;
	  degree >> x;
	  parameterArray[i] = x;
	  i++;
	  }else{
		  break;
	  }
	  
    }

    dosyaOku.close();
  }
}





