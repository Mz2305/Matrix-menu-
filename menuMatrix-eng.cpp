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
//float determinant();
float determinante1(float matrixA[MAX][MAX], int card);
float subMatrix (float matrixA[MAX][MAX], int card);
float det1(float matrixA[MAX][MAX]);
float det2(float matrixA[MAX][MAX]);
float det3(float matrixA[MAX][MAX], int card);
void transposedMatrix();
void insertMatrix(int dimMatrixR, int dimMatrixC);
int showMenu();
void determinant();
void sum();
void difference();
void product();
void sarrus();
void scalarProduct();
void systemsResolution();

void systemsResolution(){
	int i,j,k;
	float detA,detX;
	float X;
  	float matrixB[MAX][MAX];
  	float matrixR[MAX][MAX];
  	
    printf("Enter coefficients: \n");  
    insertMatrix(3,3);
    printf("Enter results: \n");
	for (i=0 ; i<3; i++){
		for (j=0; j<1; j++){
				printf("Element [%d][%d]: ",i+1 ,j+1 );
				scanf("%f",&matrixB[i][j]);
			}
	}
    printf("\n");
    printf ("The matrix is:\n");
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
		printf("\nx%d = %f \n", k+1, X);
  	    for (i=0; i<3; i++){
            for (j=0; j<3; j++){
				matrixR[j][k]=matrixA[j][k];
			}
        }
	}
}

void scalarProduct(){
	int i,j,dimVetA,dimVetB, ris=0;
	float vettoreA[MAX][MAX];
	float vettoreB[MAX][MAX];
	float vettoreF[MAX][MAX];
	
	printf("Dimensions of the vectors? "); 
    scanf("%d",&dimVetA);
    dimVetB=dimVetA;
    
	for(i=0;i<dimVetA;i++){
		printf("Element [0][%d]: ",i+1 ); 
        scanf("%f",&vettoreA[0][i]); 
	}
	printf("\n\n");
    for(i=0;i<dimVetB;i++){
		printf("Element [%d][0]: ",i+1 ); 
        scanf("%f",&vettoreB[i][0]);  
	}
	printf("\n\n");
    printf("Final vector: \n");
    for(i=0; i<dimVetA; i++){
    	vettoreF[i][0]=vettoreA[0][i]*vettoreB[i][0];
    	printf("Final element [%d][0]= ",i+1);
    	printf("%.2f ",vettoreF[i][0]);
    	printf("\n");
    	ris=ris+vettoreA[0][i]*vettoreB[i][0];
    }
	printf("\n");
    printf("result = %d ", ris);
}

void insertMatrix(int dimMatrixR, int dimMatrixC){
	int i,j;
    printf("Insert the elements of the matrix: ");  
 	printf("\n"); 
    for (i=0 ; i<dimMatrixR; i++){
		for (j=0; j<dimMatrixC; j++){
			printf("Element [%d][%d]: ",i+1 ,j+1 );
			scanf("%f",&matrixA[i][j]);
		}
	}
    printf("\n");
    printf ("The matrix is:\n");
    for (i=0; i<dimMatrixR; i++){
		for (j=0; j<dimMatrixC; j++){
			printf (" %.2f",matrixA[i][j]);              
		}
		printf ( "\n");
	}
}
	
void transposedMatrix(){
	int i,j;
	float matrixT[MAX][MAX];
	printf("Dimension of the matrix? "); 
	printf("columns: "); 
    scanf("%d",&dimMatrixC); 
    printf("lines: "); 
    scanf("%d",&dimMatrixR);
	insertMatrix(dimMatrixR,dimMatrixC);
	for (i=0 ; i<dimMatrixR; i++){
		for (j=0; j<dimMatrixC; j++){          	
			matrixT[j][i]=matrixA[i][j];	             
		}
	}

    printf ("The transposed matrix is:\n");
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
    }
    
    return det;
}
 

void determinant(){
 	float detMatrix;
 	float c=0; 
 	int dimMatrix;
 	int i,j; 
	
	printf("Dimension of the matrix? "); 
	printf("Lines and columns: "); 
    scanf("%d",&dimMatrix); 
     
    dimMatrixR=dimMatrix;
    dimMatrixC=dimMatrix;
	
	insertMatrix(dimMatrixR,dimMatrixC);
	
	detMatrix = determinante1(matrixA, dimMatrix); 
	
    printf ("The determinant is: \n");  	         
    printf ("detMatrix= %.2f\n",detMatrix); 
	
	/*dimMatrixC=dimMatrix; 
	dimMatrixR=dimMatrix;
	detMatrix = transposedMatrix(matrixA, dimMatrixC, dimMatrixR); */		
}

void sum(){
	int i,j,k;
	float matrixR[MAX][MAX];
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++){
			matrixR[i][j]=0;
		}
	}
	int NumMatrici,maxR=0,maxC=0;
 	printf("How many matrices do you want to add?");  
    scanf("%d",&NumMatrici); 
 
	for(k=0;k<NumMatrici;k++){
	
		printf("Dimension of the matrix? \n"); 
		printf("lines: "); 
   		scanf("%d",&dimMatrixR);
		printf("columns: "); 
   		scanf("%d",&dimMatrixC);
   		
   		insertMatrix(dimMatrixR,dimMatrixC);
   		
   		
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
        
	}
	
	printf ("The sum matrix is:\n");
 	for (i=0; i<maxR; i++){
		for (j=0; j<maxC; j++){
			printf (" %f",matrixR[i][j]);              
		}
    	printf ( "\n");
	}
}

void difference(){
	int i,j,k, maxR=0, maxC=0;
	float matrixR[MAX][MAX];
	int NumMatrici;
	
 	printf("How many matrices do you want to subtract?");  
    scanf("%d",&NumMatrici); 
 
	for(k=0;k<NumMatrici;k++){ 
	
		printf("Dimension of the matrix? \n"); 
		printf("lines: "); 
   		scanf("%d",&dimMatrixR);
		printf("columns: "); 
   		scanf("%d",&dimMatrixC);
   		
   		insertMatrix(dimMatrixR,dimMatrixC);
   		
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
	
	printf ("The difference matrix is:\n");
 	for (i=0; i<maxR; i++){
		for (j=0; j<maxC; j++){
			printf (" %f",matrixR[i][j]);              
		}
    	printf ( "\n");
	}
}

void product(){
 	int i,j,k,r1,c1,r2,c2;
    printf ("\n");
    printf("Enter the dimensions of the first matrix \n");  
    printf ("lines: ");
    scanf("%d",&r1); 
	printf ("columns: ");
    scanf("%d",&c1); 
	printf ("\n");
	
	float matrixA[r1][c1]; 
	
    for (i=0 ; i<r1; i++){
		for (j=0; j<c1; j++){
			printf("Element [%d][%d]: ",i+1 ,j+1 );
			scanf("%f",&matrixA[i][j]);
		}
	}
    printf ("\n");
    printf ("The first matrix is:\n");
    for (i=0 ; i<r1; i++){
		for (j=0; j<c1; j++){
			printf (" %.2f",matrixA[i][j]);              
		}
		printf ( "\n");
	}
    printf ("\n");
    printf ("Insert the second matrix:\n");  
	printf ("lines: %d ",c1);
    r2=c1; 
    printf ("\n"); 
	printf ("columns: ");
    scanf("%d",&c2); 
	printf ("\n"); 
	
	float matrixB[r2][c2];
	        
    for (i=0 ; i<r2; i++){
		for (j=0; j<c2; j++){
			printf("Element [%d][%d]: ",i+1 ,j+1 );
			scanf("%f",&matrixB[i][j]);
        }
    }
    printf ("\n");
    printf ("The second matrix is:\n");
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
    printf ("The product matrix is:\n");
    for (i=0 ; i<r1; i++){
		for (k=0; k<c2; k++){
			for (j=0; j<c1; j++){
				matrixR[i][k]=matrixR[i][k]+matrixA[i][j]*matrixB[j][k];                			 
			}
			printf (" %.2f",matrixR[i][k]);
		}
		printf ( "\n");
	} 
}

void sarrus(){
	int i,j;
	float matrixB[MAX][MAX];
	int detSarrus,dimMatrix;
	int det1=1,det2=1,det3=1,detDestra=0,detSinistra=0;
    printf("\n");
    
	printf("Dimension of the matrix? "); 
	printf("lines and columns: 3\n");
	dimMatrix=3;
	
	insertMatrix(dimMatrix,dimMatrix);
	
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
    printf ("The Sarrus matrix is:\n");
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
 	
    scelta = showMenu();
    switch (scelta){
      case 1:{
        determinant();
        break;
      }
      case 2:{
        transposedMatrix();
        break;
      }
      case 3:{
        difference();
        break;
      }
      case 4:{
        product();
        break;
      }
      case 5:{
        sum();
        break;
      }
      case 6:{
        sarrus();
        break;
      }
      case 7:{
      	scalarProduct();
      	break;
      }
      case 8:{
      	systemsResolution();
      	break;
	  }
    }
  } while (scelta != 0);
  return 0;
}

int showMenu() {
  int scelta;
  do{

    printf ("\n");
    printf ("\t\t**********************************************\n");
    printf ("\t\t*                  MENU                      *\n");
    printf ("\t\t**********************************************\n");
    printf ("\t\t* 1 DETERMINANT                              *\n");
    printf ("\t\t* 2 TRANSPOSED MATRIX                        *\n");
    printf ("\t\t* 3 DIFFERENCE OF MATRIXES                   *\n");
    printf ("\t\t* 4 MATRIX PRODUCT                           *\n");
    printf ("\t\t* 5 SUM OF MATRIXES                          *\n");
    printf ("\t\t* 6 SARRUS RULE                              *\n");
    printf ("\t\t* 7 SCALAR PRODUCT BETWEEN 2 VECTORS         *\n");
    printf ("\t\t* 8 SYSTEMS RESOLUTIONS WITH CRAMER          *\n");
	printf ("\t\t* 0 =======> EXIT                            *\n");
    printf ("\t\t**********************************************\n\n\n");

    printf ("\t\tEnter choice (1, 2, 3, 4, 5, 6, 7, 8 or 0)   :    ");
    fflush(stdin);
    scanf ("%d", &scelta);
    if ((scelta < 0) || (scelta > 8))
    {
      printf ("\n\nERROR Type the correct choice.....\n\n");
    
    }
    else;
  } while ((scelta < 0) || (scelta > 8));
	printf ("\n\n");
  return scelta;
}
