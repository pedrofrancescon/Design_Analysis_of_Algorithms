//
//  Graph.hpp
//  Dijkstra_Prim_Kruskal
//
//  Created by Pedro Francescon Cittolin on 03/06/19.
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <sstream>
#include <list>
#include <queue>
#define INFINITE 10000000

using namespace std;

class Graph
{
private:
    int V; // número de vértices
    
    // ponteiro para um array contendo as listas de adjacências
    list<pair<int, int> > * adj;
    
public:
    
    // construtor
    Graph(int V);
    
    // adiciona uma aresta ao grafo de v1 à v2
    void addEdge(int v1, int v2, int weight);
    
    // algoritmo de Dijkstra
    int* dijkstra(int orig, int dest);
    
    // Retorna conteúdo do arquivo p/ gerar imagem do grafo.
    string getOutputString(int *prec, int dest);
};

#endif /* Graph_hpp */
