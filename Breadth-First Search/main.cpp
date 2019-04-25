//
//  main.cpp
//  Coloração
//
//  Created by Pedro Francescon Cittolin on 17/04/19.
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#include "Graph.hpp"

int main()
{
    int graph_size = 9;
    
    // Cria um grafo de "graph_size" nós
    Graph g(graph_size);
    // Adiciona nós e respectivos nós adjacentes (arestas)
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(0, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 8);
    
    // Executa busca em largura a partir do nó "0"
    g.breadthSearch(0);
    
    string output_file = g.getOutputString();
    cout << output_file;
    return 0;
}

