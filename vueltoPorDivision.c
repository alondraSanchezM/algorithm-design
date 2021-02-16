//Algoritmo Voraz. Dar cambio por monedas mediante división

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void combSort(int numCantidades, int cantidades[]){
    int j, ayuda;
    float fd=numCantidades;
	bool change = true;

    do{
        if((fd/1.3)>1)
            fd=(int)(fd/1.3);
        else
            fd=1;
        change=false;
        for(int i=0;i<numCantidades-fd;i++){
            j=i+fd;
            if(cantidades[i]<cantidades[j]){
                ayuda=cantidades[i];
                cantidades[i]=cantidades[j];
                cantidades[j]=ayuda;
                change = true;
            }
        }
    }while((fd!=1)||(change));
}

int main(int argc, char const *argv[]) {
    int num, res, numCantidades;

    numCantidades=atoi(argv[1]);
    num=atoi(argv[2]);

    int cantidades[numCantidades], cambio[numCantidades];

    printf("Ingrese las denominaciones de las monedas: \n");
    for(int i=0; i<numCantidades; i++)
        scanf("%i",&cantidades[i]);

    combSort(numCantidades,cantidades);

    for(int i=0; i<numCantidades; i++){
            cambio[i]=num/cantidades[i];
            num=num%cantidades[i];
    }

    printf("El cambio a dar es: \n");
    for(int i=0; i<numCantidades; i++)
        printf("%i monedas de %i\n", cambio[i], cantidades[i]);
}
