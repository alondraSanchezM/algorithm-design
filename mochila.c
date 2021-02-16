//Algoritmo Voraz. Problema de la mochila llevar los objetos más valiosos

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//defaul move direction
/*for (s=0; s<n*n; s++){
	M[s] =0;
}*/

struct objetos{
	float peso;
	float valor;
    float prop;
};

int main(int argc, char const *argv[]) {
    int n, k, l=0, m=0;
	float sumP = 0, sumV = 0, c = 0;
	float pesoT, pesoMochila, valorMochila, fracc;

    n=atoi(argv[1]);
    pesoT=atoi(argv[2]);
    struct objetos obj[n];
	struct objetos mochila[n];

    printf("Ingrese el peso y valor de los posibles objetos a transportar\n");
    for(int i=0; i<n; i++){
        printf("Objeto %d :",i+1);
		scanf("%f",&obj[i].peso);
		scanf("%f",&obj[i].valor);
	    obj[i].prop = obj[i].valor/obj[i].peso;
		c = c + obj[i].peso;
	}
	if(c>pesoT){
	    //Combsort
	    struct objetos ayuda;
	    int j;
		float fd = n;
		bool cambio = true;
		do{
			if((fd/1.3)>1)
				fd=(int)(fd/1.3);
			else
				fd=1;
			cambio=false;
			for(int i=0;i<n-fd;i++){
				j=i+fd;
				if(obj[i].prop<obj[j].prop){
					ayuda=obj[i];
					obj[i]=obj[j];
					obj[j]=ayuda;
					cambio = true;
				}
			}
		}while((fd!=1)||(cambio));
	    //------------------------

		for(int i=0; pesoMochila<pesoT; i++){
			if((pesoMochila+obj[i].peso)<=pesoT){
				mochila[l]=obj[i];
				pesoMochila=pesoMochila+obj[i].peso;
				valorMochila=valorMochila+obj[i].valor;
				//printf("Valor: %f , Peso: %f con prop de: %f\n", mochila[l].valor,mochila[l].peso,mochila[l].prop);
			}
			else{
				fracc=(pesoT-pesoMochila)/obj[i].peso;
				valorMochila=valorMochila+(fracc*obj[i].valor);
				pesoMochila=pesoMochila+(fracc*obj[i].peso);
				mochila[l].valor=fracc*obj[i].valor;
				mochila[l].peso=fracc*obj[i].peso;
				mochila[l].prop=obj[i].valor/obj[i].peso;
				//printf("Valor: %f , Peso: %f con prop de: %f\n", mochila[l].valor,mochila[l].peso,mochila[l].prop);
			}
			l++;
			m++;
		}

		for (int i=0; i<m; i++){
			sumP = sumP+mochila[i].peso;
			sumV = sumV+mochila[i].valor;
		}

		printf("El valor de los objetos en la mochila es: %.2f\n", sumV);
	}else
		printf("Todos los objetos caben en la mochila\n");

























}
