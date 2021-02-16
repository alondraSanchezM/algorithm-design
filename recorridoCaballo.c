//Algoritmo Backtracking - Recorrido del caballo por todo el tablero de ajedrez

#include <stdio.h>

#define n 6

int tablero[n][n];
int opc[n*n];
int x,y,i;

void opcionesSalto(int d){  
	switch(opc[i]){
	case 0:
		x = x-1*d;
		y = y+2*d;
	    break;
	case 1:
		x = x-2*d;
		y = y+1*d;
	    break;
	case 2:
		x = x-2*d;
		y = y-1*d;
	    break;
	case 3:
		x = x-1*d;
		y = y-2*d;
	    break;
	case 4:
		x = x+1*d;
		y = y-2*d;
	    break;
	case 5:
		x = x+2*d;
		y = y-1*d;
	    break;
	case 6:
		x = x+2*d;
		y = y+1*d;
	   break;
	case 7:
		x = x+1*d;
		y = y+2*d;
	   break;
	default:
	    break;
	}
}

void blacktracking(){
	for (i=1;i<=n*n;i++){
		if(x>=0&&x<n && y>=0&&y<n && tablero[x][y]==-1){
			tablero[x][y]=i;
		}else{
			i=i-1;
			opcionesSalto (-1);
			while (opc[i]==7){
				 tablero[x][y]=-1;
				 opc[i]=0;
				 i=i-1;
				 opcionesSalto (-1);
			}
			opc[i]=opc[i]+1;
		}
		opcionesSalto(1);
	}
}

int main (){

	for (x=0; x<n; x++)
		for (y=0; y<n; y++)
			tablero[x][y] = -1;

	printf("\nIngrese la posición inicial\n");
	printf("Ingrese el valor de x: ");
	scanf("%d",&x);
	printf("Ingrese el valor de y: ");
	scanf("%d",&y);
	x--;
	y--;

	blacktracking();

	printf("\n\nEl recorrido del caballo es: \n\n");
	for(x=0;x<n;x++){
		for(y=0; y<n; y++){
			if(tablero[x][y]>9)
				printf("%d ",tablero[x][y]);
			else
				printf("%d  ",tablero[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}
