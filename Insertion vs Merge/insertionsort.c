#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//INSERTION SORT
/*---------------------------------------------------------------------*/

void insertion_sort(int arr[], int n) {
    
    int key, j;
    
    //O Insertion Sort percorre todo o array arr[] de tamanho n, analisando elemento por elemento
    for (int i = 1; i < n; i++)
    {
        /* key é o elemento/número que está atualmente sendo analisado,
         usamos essa variável para não perder esse valor durante o processo */
        key = arr[i];
        
        //j é a posição anterior do elemento que está sendo analisado (key) no array
        j = i-1;
        
        /* este while "vai voltando" no array arr[] caso o elemento key não esteja numa posição
         correta, ou seja, se o elemento anterior for maior do que ele (não estão em ordem) */
        while (j >= 0 && arr[j] > key)
        {
            //joga o número anteior pra frente, para poder jogar o valor atual para traz
            arr[j+1] = arr[j];
            j--;
        }
        
        //aqui achou uma posição em que ele está ordenado no vetor, então coloca ele de volta na posição correta
        arr[j+1] = key;
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
	insertion_sort(vet, n);
	clock_t end = clock();
	
	double timeSpent = (double)(end-begin) / CLOCKS_PER_SEC;
	
	for(int i=0; i < n; i++)
		printf("%d ", vet[i]);
	printf("\n");
	printf("%.8f\n", timeSpent);

	return 0;
}
