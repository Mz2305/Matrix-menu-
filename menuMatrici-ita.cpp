#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif
#define MAX 100

int dimMatrixC, dimMatrixR;
float matrixA[MAX][MAX], matrixB[MAX][MAX];

//Prototipi  (definisce le funzioni)
float determinate();
float determinante1(float matrixA[MAX][MAX], int card);
float subMatrix (float matrixA[MAX][MAX], int card);
float det1(float matrixA[MAX][MAX]);
float det2(float matrixA[MAX][MAX]);
float det3(float matrixA[MAX][MAX], int card);
void matrixTrasposta();
void inserisciMatrix(int dimMatrixR, int dimMatrixC);
int mostraMenu();
void determinante();
void somma();
void differenza();
void prodotto();
void sarrus();
void prodottoscalare();
void risoluzionesistemi();

void risoluzionesistemi(){
	int i,j,k;
	float detA,detX;
	float X;
  	float matrixB[MAX][MAX];
  	float matrixR[MAX][MAX];
  	
    printf("Inserisci i coefficenti: \n");  
    inserisciMatrix(3,3);
    printf("Inserisci i risultati: \n");
	for (i=0 ; i<3; i++){
		for (j=0; j<1; j++){
				printf("Elemento [%d][%d]: ",i+1 ,j+1 );
				scanf("%f",&matrixB[i][j]);
			}
	}
    printf("\n");
    printf ("La matrice e':\n");
    for (i=0; i<3; i++){
		for (j=0; j<1; j++){
			printf (" %.2f",matrixB[i][j]);              
		}
		printf ( "\n");
	}
    
    for (i=0; i<3; i++){
		for (j=0; j<3; j++){
			matrixR[i][j]=matrixA[i][j];              
		}
	}
    detA=determinante1(matrixA,3);
    //printf("detA = %f  \n \n", detA);
    for(k=0;k<3;k++){
    	for (i=0; i<3; i++){
            for (j=0; j<3; j++){
				matrixR[j][k]=matrixB[j][0];
			}
        }   
        /*printf ("La matrice e':\n");
    	for (i=0; i<3; i++){
            for (j=0; j<3; j++){
				printf (" %.2f",matrixR[i][j]);              
			}
            printf ( "\n");
        }*/
		detX=determinante1(matrixR,3);
		X=detX/detA;
		printf("x %d = %f \n", k+1, X);
  	    for (i=0; i<3; i++){
            for (j=0; j<3; j++){
				matrixR[j][k]=matrixA[j][k];
			}
        }
	}
}

void prodottoscalare(){
	int i,j,dimVetA,dimVetB, ris=0;
	float vettoreA[MAX][MAX];
	float vettoreB[MAX][MAX];
	float vettoreF[MAX][MAX];
	
	printf("Dimensioni dei vettori? "); 
    scanf("%d",&dimVetA);
    dimVetB=dimVetA;
    
	for(i=0;i<dimVetA;i++){
		printf("Elemento [0][%d]: ",i+1 ); 
        scanf("%f",&vettoreA[0][i]); 
	}
	printf("\n\n");
    for(i=0;i<dimVetB;i++){
		printf("Elemento [%d][0]: ",i+1 ); 
        scanf("%f",&vettoreB[i][0]);  
	}
	printf("\n\n");
    printf("Vettore finale: \n");
    for(i=0; i<dimVetA; i++){
    	vettoreF[i][0]=vettoreA[0][i]*vettoreB[i][0];
    	printf("Ele Finale [%d][0]= ",i+1);
    	printf("%.2f ",vettoreF[i][0]);
    	printf("\n");
    	ris=ris+vettoreA[0][i]*vettoreB[i][0];
    }
	printf("\n");
    printf("risultato= %d ", ris);
}

void inserisciMatrix(int dimMatrixR, int dimMatrixC){
	int i,j;
    printf("Inserisci gli elementi della matrice: ");  
 	printf("\n"); 
    for (i=0 ; i<dimMatrixR; i++){
		for (j=0; j<dimMatrixC; j++){
			printf("Elemento [%d][%d]: ",i+1 ,j+1 );
			scanf("%f",&matrixA[i][j]);
		}
	}
    printf("\n");
    printf ("La matrice e':\n");
    for (i=0; i<dimMatrixR; i++){
		for (j=0; j<dimMatrixC; j++){
			printf (" %.2f",matrixA[i][j]);              
		}
		printf ( "\n");
	}
}
	
void matrixTrasposta(){
	int i,j;
	float matrixT[MAX][MAX];
	printf("Dimensioni della matrice? "); 
	printf("colonne: "); 
    scanf("%d",&dimMatrixC); 
    printf("righe: "); 
    scanf("%d",&dimMatrixR);
	inserisciMatrix(dimMatrixR,dimMatrixC);
	for (i=0 ; i<dimMatrixR; i++){
		for (j=0; j<dimMatrixC; j++){          	
			matrixT[j][i]=matrixA[i][j];	             
		}
	}

    printf ("La matrice trasposta e':\n");
    for (i=0 ; i<dimMatrixC; i++){
		for (j=0; j<dimMatrixR; j++){
			printf (" %.2f",matrixT[i][j]);  	             
		}
		printf("\n"); 
	}
	
}

float detMatrixIJ2(float matrixA[MAX][MAX], int card, int c){
	int i,j;
	int k,newCard=card-1;
	float matrixAIJ[MAX][MAX];
    float detTemp;
	int	pot=0;
	
	for (i=1 ; i<card; i++){
		k=0;
		for (j=0; j<card; j++){    	
			if (j!=c){
				matrixAIJ[i-1][k]=matrixA[i][j];
				k=k+1;
			}		             
		}
	}
   	detTemp=det2(matrixAIJ);
   	//printf ("\n minCompl %.2f\n",detTemp);
   	return detTemp;
}


float det1(float matrixA[MAX][MAX]){
	float det;
	
	det=matrixA[0][0];
	return det;
}

float det2(float matrixA[MAX][MAX]){
	float det;
	
	det=matrixA[0][0]*matrixA[1][1]-matrixA[0][1]*matrixA[1][0];
	return det;
}

float det3(float matrixA[MAX][MAX], int card){
	int i,j; 
	float detJ=0,minCompl;
	float pot;
	for (j=0; j<card; j++){
       	minCompl=detMatrixIJ2(matrixA,card,j);
        if ((j % 2)==0){
       		detJ=detJ+matrixA[0][j]*(minCompl); 
	  	} else {
	   		detJ=detJ-matrixA[0][j]*(minCompl); 
	  	}  	
		//printf ("\n detJ=%.2f\n",detJ);
    }
    printf("\n"); 
	return detJ;
}

float determinante1(float matrixA[MAX][MAX], int card){
	int i=0,j; 
	float det;
	int	pot=0;
	
	if (card==1){
	    det=matrixA[0][0];
	} else if (card==2){
	    det=matrixA[0][0]*matrixA[1][1]-matrixA[0][1]*matrixA[1][0];
	} else {	
        det=det3(matrixA,3);   	
		printf("\n"); 			             
    }
    
    return det;
}
 

void determinante(){
 	float detMatrix;
 	float c=0; 
 	int dimMatrix;
 	int i,j; 
	
	printf("Dimensioni della matrice? "); 
	printf("righe e colonne: "); 
    scanf("%d",&dimMatrix); 
     
    dimMatrixR=dimMatrix;
    dimMatrixC=dimMatrix;
	
	inserisciMatrix(dimMatrixR,dimMatrixC);
	
	detMatrix = determinante1(matrixA, dimMatrix); 
	
    printf ("Il determinante e': \n");  	         
    printf ("detMatrix= %.2f\n",detMatrix); 
	
	/*dimMatrixC=dimMatrix; 
	dimMatrixR=dimMatrix;
	detMatrix = matrixTrasposta(matrixA, dimMatrixC, dimMatrixR); */		
}

void somma(){
	int i,j,k;
	float matrixR[MAX][MAX];
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			matrixR[i][j]=0;
		}
	}
	int NumMatrici,maxR=0,maxC=0;
 	printf("Quante matrici vuoi sommare?");  
    scanf("%d",&NumMatrici); 
 
	for(k=0;k<NumMatrici;k++){
	
		printf("Dimensioni della matrice? \n"); 
		printf("righe: "); 
   		scanf("%d",&dimMatrixR);
		printf("colonne: "); 
   		scanf("%d",&dimMatrixC);
   		
   		inserisciMatrix(dimMatrixR,dimMatrixC);
   		
   		
   		if(dimMatrixR>maxR){
   			maxR=dimMatrixR;
   		}
   		if(dimMatrixC>maxC){
   			maxC=dimMatrixC;
   		}   		
   		for (i=0 ; i<dimMatrixR; i++){
            for (j=0; j<dimMatrixC; j++){
             	if(k==0){
					matrixR[i][j]=matrixA[i][j];
				} else {
					matrixR[i][j]=matrixR[i][j]+matrixA[i][j];
				}
           	}
        }
        
    	printf("\n");
	}
	
	printf ("la matrice somma e':\n");
 	for (i=0; i<maxR; i++){
		for (j=0; j<maxC; j++){
			printf (" %f",matrixR[i][j]);              
		}
    	printf ( "\n");
	}
}

void differenza(){
	int i,j,k, maxR=0, maxC=0;
	float matrixR[MAX][MAX];
	int NumMatrici;
	
 	printf("Quante matrici vuoi sottrarre?");  
    scanf("%d",&NumMatrici); 
 
	for(k=0;k<NumMatrici;k++){ 
	
		printf("Dimensioni della matrice? \n"); 
		printf("righe: "); 
   		scanf("%d",&dimMatrixR);
		printf("colonne: "); 
   		scanf("%d",&dimMatrixC);
   		
   		inserisciMatrix(dimMatrixR,dimMatrixC);
   		
   		if(dimMatrixR>maxR){
   			maxR=dimMatrixR;
   		}
   		if(dimMatrixC>maxC){
   			maxC=dimMatrixC;
   		}   		
   		for (i=0 ; i<dimMatrixR; i++){
            for (j=0; j<dimMatrixC; j++){
             	if(k==0){
					matrixR[i][j]=matrixA[i][j];
				} else {
					matrixR[i][j]=matrixR[i][j]-matrixA[i][j];
				}
           	}
        }
        
    	printf("\n");
	}  
	
	printf ("la matrice differenza e':\n");
 	for (i=0; i<maxR; i++){
		for (j=0; j<maxC; j++){
			printf (" %f",matrixR[i][j]);              
		}
    	printf ( "\n");
	}
}

void prodotto(){
 	int i,j,k,r1,c1,r2,c2;
    printf ("\n");
    printf("Inserisci le dimensioni della prima matrice \n");  
    printf ("righe: ");
    scanf("%d",&r1); 
	printf ("colonne: ");
    scanf("%d",&c1); 
	printf ("\n");
	
	float matrixA[r1][c1]; 
	
    for (i=0 ; i<r1; i++){
		for (j=0; j<c1; j++){
			printf("Elemento [%d][%d]: ",i+1 ,j+1 );
			scanf("%f",&matrixA[i][j]);
		}
	}
    printf ("\n");
    printf ("la prima matrice e':\n");
    for (i=0 ; i<r1; i++){
		for (j=0; j<c1; j++){
			printf (" %.2f",matrixA[i][j]);              
		}
		printf ( "\n");
	}
    printf ("\n");
    printf ("Inserire la seconda matrice:\n");  
	printf ("righe: %d ",c1);
    r2=c1; 
    printf ("\n"); 
	printf ("colonne: ");
    scanf("%d",&c2); 
	printf ("\n"); 
	
	float matrixB[r2][c2];
	        
    for (i=0 ; i<r2; i++){
		for (j=0; j<c2; j++){
			printf("Elemento [%d][%d]: ",i+1 ,j+1 );
			scanf("%f",&matrixB[i][j]);
        }
    }
    printf ("\n");
    printf ("la seconda matrice e':\n");
    for (i=0; i<r2; i++){
		for (j=0; j<c2; j++){
			printf (" %.2f",matrixB[i][j]);              
		}
		printf ( "\n");
	}    	 
	float matrixR[r1][c2];  	
	for (i=0 ; i<r1; i++){
		for (j=0; j<c2; j++){
			matrixR[i][j]=0;
		}
	}    
    printf ("\n"); 
    printf ("La matrice prodotto e':\n");
    for (i=0 ; i<r1; i++){
		for (k=0; k<c2; k++){
			for (j=0; j<c1; j++){
				matrixR[i][k]=matrixR[i][k]+matrixA[i][j]*matrixB[j][k];                			 
			}
			printf (" %.2f",matrixR[i][k]);
		}
		printf ( "\n");
	}  
		
	printf ( "\n"); 
}

void sarrus(){
	int i,j;
	float matrixB[MAX][MAX];
	int detSarrus,dimMatrix;
	int det1=1,det2=1,det3=1,detDestra=0,detSinistra=0;
    printf("\n");
    
	printf("Dimensioni della matrice? "); 
	printf("righe e colonne: 3\n");
	dimMatrix=3;
	
	inserisciMatrix(dimMatrix,dimMatrix);
	
	for (i=0 ; i<dimMatrix; i++){
		for (j=0; j<dimMatrix+(dimMatrix-1); j++){
			if(j<dimMatrix){
				matrixB[i][j]=matrixA[i][j];
			} else {
				matrixB[i][j]=matrixA[i][j-dimMatrix];
			}
		}
	}
	printf("\n");
    printf ("La matrice Sarrus e':\n");
    for (i=0 ; i<dimMatrix; i++){
		for (j=0; j<dimMatrix+(dimMatrix-1); j++){
			printf (" %.2f",matrixB[i][j]);  	             
		}
		printf("\n"); 
	}

   	/*detSarrus=(matrixB[0][0]*matrixB[1][1]*matrixB[2][2]+matrixB[0][1]*matrixB[1][2]*matrixB[2][3]+matrixB[0][2]*matrixB[1][3]*matrixB[2][4])-(matrixB[0][2]*matrixB[1][1]*matrixB[2][0]+matrixB[0][3]*matrixB[1][2]*matrixB[2][1]+matrixB[0][4]*matrixB[1][3]*matrixB[2][2]);
   	printf("\n"); 
	printf("detSarrus = %d (senza for) \n", detSarrus);
	printf("\n");*/
	
	for(i=0;i<dimMatrix;i++) {
		for(j=0;j<dimMatrix+(dimMatrix-1);j++){
			if(i==j){
				det1=det1*matrixB[i][j];
			} else {
				if(i==j-1) {
					det2=det2*matrixB[i][j];
				} else {
					if(i==j-2) {
						det3=det3*matrixB[i][j];
					}
				}
			}
		}
	}
	detDestra=det1+det2+det3;
	
	det1=1;
	det2=1;
	det3=1;
	
	for(i=0;i<dimMatrix;i++){
		for(j=0;j<dimMatrix+(dimMatrix-1);j++){
			if(i+j==2){
				det1=det1*matrixB[i][j];
			} else {
				if(i+j==3 && j!=0){
					det2=det2*matrixB[i][j];
				} else {
					if(i+j==4){
						det3=det3*matrixB[i][j];
					}
				}
			}
		}
	}
	detSinistra=det1+det2+det3;
	detSarrus=detDestra-detSinistra;
	printf("detSarrus = %d \n", detSarrus);
	printf("\n");
	
}

int main(){
  int scelta;
  do {
 	
    scelta = mostraMenu();
    switch (scelta){
      case 1:{
        determinante();
        break;
      }
      case 2:{
        matrixTrasposta();
        break;
      }
      case 3:{
        differenza();
        break;
      }
      case 4:{
        prodotto();
        break;
      }
      case 5:{
        somma();
        break;
      }
      case 6:{
        sarrus();
        break;
      }
      case 7:{
      	prodottoscalare();
      	break;
      }
      case 8:{
      	risoluzionesistemi();
      	break;
	  }
    }
  } while (scelta != 0);
  return 0;
}

int mostraMenu() {
  int scelta;
  do{

    printf ("\n");
    printf ("\t\t**********************************************\n");
    printf ("\t\t*                  MENU                      *\n");
    printf ("\t\t**********************************************\n");
    printf ("\t\t* 1 DETERMINANTE                             *\n");
    printf ("\t\t* 2 TRASPOSTA                                *\n");
    printf ("\t\t* 3 DIFFERENZA DI MATRICI                    *\n");
    printf ("\t\t* 4 PRODOTTO DI MATRICI                      *\n");
    printf ("\t\t* 5 SOMMA DI MATRICI                         *\n");
    printf ("\t\t* 6 REGOLA DI SARRUS                         *\n");
    printf ("\t\t* 7 PRODOTTO SCALARE TRA 2 VETTORI           *\n");
    printf ("\t\t* 8 RISOLUZIONI SISTEMI CON CRAMER           *\n");
	printf ("\t\t* 0 =======> USCITA                          *\n");
    printf ("\t\t**********************************************\n\n\n");

    printf ("\t\tInserire scelta (1, 2, 3, 4, 5, 6, 7, 8 oppure 0)   :    ");
    fflush(stdin);
    scanf ("%d", &scelta);
    if ((scelta < 0) || (scelta > 8))
    {
      printf ("\n\nERRORE Digitare la scelta corretta.....\n\n");
    
    }
    else;
  } while ((scelta < 0) || (scelta > 8));
	printf ("\n\n");
  return scelta;
}
