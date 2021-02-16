//Algoritmo Divide y venceras. Problema del calendario deportivo

#include <stdio.h>
#include <stdlib.h>

void ordenamiento(int **m,int *a,int inicio,int fin){
	int i, j, new;
	if(fin-inicio==2){
		m[inicio][0]=a[fin-1];
		m[fin-1][0]=a[inicio];
	}else{
		new=(inicio+fin)/2;
		ordenamiento(m,a,inicio,new);
		ordenamiento(m,a,new,fin);
		for(i=inicio;i<new;i++){
			m[i][fin-new-1]=a[fin-new+i];
			for(j=new-inicio;j<fin-inicio-1;j++)
				m[i][j]=m[i+new-inicio][j-new+inicio];
		}
		for(i=new;i<fin;i++){
			m[i][fin-new-1]=a[i-new+inicio];
			for(j=new-inicio;j<fin-inicio-1;j++)
				m[i][j]=m[i-new+inicio][j-new+inicio];
		}
	}
}

int main(int argc, char const *argv[]){
	int n,k,i,j,flag=0;
    int **m,*a;

    n=atoi(argv[1]);
    k=n;
    do{
        if(k%2==1)
            flag=1;
        if(k>2)
            k=k/2;
    }while(k>0 && k!=2 && flag==0);

    if(flag==0 && n>=2){
        m=(int**)malloc(sizeof(int*)*n);
    	a=(int*)malloc(sizeof(int)*n);

    	for(i=0;i<n;i++)
    		m[i]=(int*)malloc(sizeof(int)*(n-1));

    	for(i=0;i<n;i++){
    		a[i]=i+1;
    		for(j=1;j<n-1;j++)
    			m[i][j]=0;
    	}

    	ordenamiento(m,a,0,n);

    	for(int i=0;i<n;i++){
    		if(a[i]>9)
    			printf("%d ",a[i]);
    		else
    			printf("%d  ",a[i]);
    		for(int j=0;j<n-1;j++)
    			if(m[i][j]>9)
    				printf("%d ",m[i][j]);
    			else
    				printf("%d  ",m[i][j]);
    		printf("\n");
    	}
    	printf("\n");

    }else
        printf("Numero de equipos erroneo, ingrese solo potencias de 2\n");
}
