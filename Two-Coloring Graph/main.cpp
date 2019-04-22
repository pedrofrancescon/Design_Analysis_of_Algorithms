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
    // Cria um grafo de 4 nós
    Graph g(4);
    // Adiciona nós e respectivos nós adjacentes
    g.addEdge(0, 1);
    g.addEdge(2, 1);
    g.addEdge(2, 0);
    g.addEdge(2, 3);

    bool is_colorable = g.breadthSearch(2);
    
    if (is_colorable)
    {
        string output_file = g.getOutputString();
        cout << output_file;
        return 0;
    }
    
    else
        return 1;
}

