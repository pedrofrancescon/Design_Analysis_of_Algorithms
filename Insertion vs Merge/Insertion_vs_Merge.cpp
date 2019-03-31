//
//  Insertion_vs_Merge.cpp
//
//  Created by Pedro Francescon Cittolin.
//

#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <chrono>

#define ARRAY_LENGHT 10
#define TIME time_point<high_resolution_clock> 
#define DURATION duration<double>

using namespace std;
using namespace chrono;

//MERGE SORT
/*---------------------------------------------------------------------*/

void merge(int *vetor, int comeco, int meio, int fim) {
    
    //vetor auxiliar p/ juntar as metades ordenadas do vetor sem sobrescrever os valores
    int *vetAux;
    //variáveis auxiliares p/ iteração no vetor auxiliar
    int com1 = comeco, com2 = meio+1, comAux = 0, tam = fim-comeco+1;
    vetAux = new int[tam];
    //vetAux = (int*)malloc(tam * sizeof(int));
    
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

// função auxiliar que chama a verdadeira função que executa o Merge Sort (mergeSrt)
DURATION mergeSort(int *vetor, int comeco, int fim){
    TIME mergeStart = high_resolution_clock::now();
    
    //chamadas de função recurvisamente apenas nessa linha, possibilitando marcar o tempo de execução fora do escopo
    mergeSrt(vetor, comeco, fim);
    TIME mergeFinish = high_resolution_clock::now();
    DURATION elapsedMerge = mergeFinish - mergeStart;
    return elapsedMerge;
}

//INSERTION SORT
/*---------------------------------------------------------------------*/

DURATION insertion_sort(int arr[], int n) {
    
    TIME insertionStart = high_resolution_clock::now();
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
    
    TIME insertionFinish = high_resolution_clock::now();
    DURATION elapsedInsertion = insertionFinish - insertionStart;
    return elapsedInsertion;
}

/*---------------------------------------------------------------------*/

void limpar() {
    cout << string( 100, '\n' );
    return;
}
 
void pausarExecução() {
    cout << "\nPressione qualquer tecla para continuar..." << endl;
    cin.ignore().get();
}

/*---------------------------------------------------------------------*/

void preencheVetor(int *arr, int tamanho) {
    for(int i = 0; i < tamanho; ++i) {
        arr[i] = (rand() % tamanho);
    }
}

void inicializarVetor(int * &arr, int tamanho) {
    free(arr);
    arr = new int[tamanho];
    preencheVetor(arr, tamanho);
}

//usada para não perder as posições iniciais do vetor depois de executar a ordenação
void copiaVetor(int *arr_origem, int *arr_destino, int tamanho) {
    for(int i = 0; i < tamanho; ++i) {
        arr_destino[i] = arr_origem[i];
    }
}

void imprimeVetor(int *vet, int tamanho, bool deve_imprimir) {
    if (deve_imprimir) {
        for (int i=0; i < tamanho; i++)
            cout << vet[i] << " ";
        cout << endl;
    }
}

/*---------------------------------------------------------------------*/

int main() {
    setlocale(LC_ALL, "Portuguese");
    srand(time(NULL));

    int tamanho_vetor = 0;
    int *vet = NULL, *vet_copy = NULL;
    bool deve_imprimir = false;

    int menu = 4;
    while (true) {
        if (menu == 0) {
            limpar();
            cout << "INSERTION SORT vs. MERGE SORT\n\n";
            cout << "Selecione uma das opções abaixo:\n";
            cout << "1 - Executar Insertion Sort\n";
            cout << "2 - Executar Merge Sort\n";
            cout << "3 - Comparar Insertion Sort e Merge Sort\n";
            cout << "4 - Mudar tamanho do vetor\n";
            cout << "5 - Mostrar posições do vetor no final da execução?\n";
            cout << "6 - Sair\n\n";
            cout << "Digite aqui: ";
            cin >> menu;
        } else if (menu == 1) {
            limpar();
            imprimeVetor(vet, tamanho_vetor, deve_imprimir);
            DURATION tempo = insertion_sort(vet, tamanho_vetor);
            imprimeVetor(vet, tamanho_vetor, deve_imprimir);

            cout << "Tempo de execução: " << tempo.count() << " s" << endl;
            
            copiaVetor(vet_copy, vet, tamanho_vetor);
            pausarExecução();
            menu = 0;
        } else if (menu == 2) {
            limpar();
            
            imprimeVetor(vet, tamanho_vetor, deve_imprimir);
            DURATION tempo = mergeSort(vet, 0, tamanho_vetor-1);
            imprimeVetor(vet, tamanho_vetor, deve_imprimir);
            
            cout << "Tempo de execução: " << tempo.count() << " s"  << endl;
            
            copiaVetor(vet_copy, vet, tamanho_vetor);
            pausarExecução();
            menu = 0;
        } else if (menu == 3) {
            limpar();
            imprimeVetor(vet, tamanho_vetor, deve_imprimir);
            DURATION tempo = insertion_sort(vet, tamanho_vetor);
            imprimeVetor(vet, tamanho_vetor, deve_imprimir);
            
            cout << "Insertion Sort: " << tempo.count() << " s\n" << endl;
            
            copiaVetor(vet_copy, vet, tamanho_vetor);

            imprimeVetor(vet, tamanho_vetor, deve_imprimir);
            tempo = mergeSort(vet, 0, tamanho_vetor-1);
            imprimeVetor(vet, tamanho_vetor, deve_imprimir);
            
            cout << "Merge Sort: " << tempo.count() << " s\n"  << endl;
            
            copiaVetor(vet_copy, vet, tamanho_vetor);
            pausarExecução();
            menu = 0;
        } else if (menu == 4) {
            limpar();
            cout << "Digite o tamanho do vetor de entrada: ";
            cin >> tamanho_vetor;
            inicializarVetor(vet, tamanho_vetor);
            preencheVetor(vet, tamanho_vetor);
            inicializarVetor(vet_copy, tamanho_vetor);
            copiaVetor(vet, vet_copy, tamanho_vetor);
            menu = 0;
        } else if (menu == 5) {
            limpar();
            
            int aux = 2;
            cout << "Vc quer que o programa mostre o as posições do vetor antes e depois da execução?\n";
            cout << "1 - Sim\n";
            cout << "2 - Não\n\n";
            cout << "Digite aqui: ";
            cin >> aux;
            
            if (aux == 1) {
                deve_imprimir = true;
            } else {
                deve_imprimir = false;
            }
            
            menu = 0;
        } else if (menu == 6) {
            break;
        } else {
            limpar();
            cout << "\nO valor digitado não corresponde a nenhuma opção do menu\n";
            pausarExecução();
            menu = 0;
        }
    }
    
    free(vet);
    return 0;
}
