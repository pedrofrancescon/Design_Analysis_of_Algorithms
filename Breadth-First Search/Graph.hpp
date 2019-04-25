//
//  Graph.hpp
//  Coloração
//
//  Created by Pedro Francescon Cittolin on 17/04/19.
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

#define NO_COLOR -1

#include <iostream>
#include <sstream>
#include <fstream>
#include <list>

using namespace std;

/* Classe que representa um grafo com
 lista de adjacências */
class Graph {
private:
    // Conteudo do arquivo p/ gerar imagem do grafo.
    stringstream file_edges;
    stringstream nodes_green;
    stringstream nodes_blue;
    // Indica se o grafo pode ser colorido com duas cores. Valor inicial = verdadeiro.
    bool canBe2Colored;
    // Num. de vértices
    int V;
    // Um vetor de listas de adjacências.
    list<int> *adj;
    
    /*--------------------------*/
    
    void _addEdge2File(int node_first, int node_second);
    void _addColor2Vertex(int color, int vertex);
    
public:
    Graph(int V);
    
    // Adiciona uma aresta no grafo entre "v" e "w"
    void addEdge(int v, int w);
    
    // Executa busca em largura a partir de um vértice "s"
    void breadthSearch(int s);
    
    // Retorna conteúdo do arquivo p/ gerar imagem do grafo.
    string getOutputString();
    
};

#endif

