#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//MERGE SORT
/*---------------------------------------------------------------------*/

void merge(int *vetor, int comeco, int meio, int fim) {
    
    //vetor auxiliar p/ juntar as metades ordenadas do vetor sem sobrescrever os valores
    int *vetAux;
    //variáveis auxiliares p/ iteração no vetor auxiliar
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    //vetAux = new int[tam];
    vetAux = (int*)malloc(tam * sizeof(int));
    
    //itera nas duas metades ordenadas do vetor "ao mesmo tempo"
    while(com1 <= meio && com2 <= fim){
        //se o valor da primeira metade é menor do que da segunda metade...
        if(vetor[com1] < vetor[com2]) {
            //coloca no vetor auxiliar
            vetAux[comAux] = vetor[com1];
            //passa pro proximo valor da PRIMEIRA metade
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            //passa pro proximo valor da SEGUNDA metade
            com2++;
        }
        comAux++;
    }
    
    //termina de copiar se sobrou algo na primeira metade
    while(com1 <= meio){
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    //termina de copiar se sobrou algo na segunda metade
    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = comeco; comAux <= fim; comAux++){
        //copia vetor auxilizar ordenado p/ o vetor orignal
        vetor[comAux] = vetAux[comAux-comeco];
    }

    free(vetAux);
}

void mergeSrt(int *vetor, int comeco, int fim) {
    /* aqui é a condição base da chamada recursiva, se o começo não for menor do que o
     fim, quer dizer que o vetor tem tamanho igual a 1 e não precisa mais ser dividido */
    if (comeco < fim) {
        //acha o ponto médio do vetor
        int meio = (fim+comeco)/2;
        //chama a função recursivamente p/ a primeira metade do vetor
        mergeSrt(vetor, comeco, meio);
        //chama a função recursivamente p/ a segunda metade do vetor
        mergeSrt(vetor, meio+1, fim);
        //junta as duas metades
        merge(vetor, comeco, meio, fim);
    }
}

int main(int argc, char *argv[])
{
	FILE *file;
	file = fopen(argv[1], "r");
	if(!file)
	{
		printf("Erro ao abrir o arquivo.\n");
		return 1;
	}
	
	int n=0;
	char ch;
	while((ch=fgetc(file)) != EOF)
		if(ch == ' ')
			n++;
	n++;
	rewind(file);
	
	int* vet = malloc(n*sizeof(int));
	for(int i=0; i < n; i++)
		fscanf(file, "%d", &vet[i]);
	fclose(file);
	
	clock_t begin = clock();
	mergeSrt(vet, 0, n-1);
	clock_t end = clock();
	
	double timeSpent = (double)(end-begin) / CLOCKS_PER_SEC;
	
	for(int i=0; i < n; i++)
		printf("%d ", vet[i]);
	printf("\n");
	printf("%.8f\n", timeSpent);

	return 0;
}
