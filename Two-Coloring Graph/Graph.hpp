//
//  Graph.hpp
//  Coloração
//
//  Created by Pedro Francescon Cittolin on 17/04/19.
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#ifndef Graph_hpp
#define Graph_hpp

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
    stringstream file_content;
    // Num. de vértices
    int V;
    // Um vetor de listas de adjacências.
    list<int> *adj;
    
    /*--------------------------*/
    
    void _print2File(int node_first, int node_second, bool color);
    
public:
    Graph(int V);
    
    // Adiciona uma aresta no grafo entre "v" e "w"
    void addEdge(int v, int w);
    
    // Executa busca em largura a partir de um vértice "s"
    bool breadthSearch(int s);
    
    // Retorna conteúdo do arquivo p/ gerar imagem do grafo.
    string getOutputString();
    
};

#endif

