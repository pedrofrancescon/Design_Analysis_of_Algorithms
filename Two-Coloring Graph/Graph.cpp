//
//  Graph.cpp
//  Coloração
//
//  Created by Pedro Francescon Cittolin on 17/04/19.
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    
    file_content << "graph Colored_graph {\n";
    file_content << "   node [style=filled];\n";
    file_content << "   {node [style=filled,color=skyblue] 1 0 3}\n";
}

void Graph::addEdge(int v, int w)
{
    // Adiciona "w" na lista de adjacência de "v".
    adj[v].push_back(w);
}

bool Graph::breadthSearch(int s)
{
    // Marca todos os vértices como não visitados
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // Cria uma fila
    list<int> queue;
    
    bool current_color = true;

    // Marca o nó atual (s) como visitado e coloca ele na fila
    visited[s] = true;
    queue.push_back(s);

    // Iterador para acessar todos os vértices adjacentes à um vértice
    list<int>::iterator i;

    while(!queue.empty())
    {
        // Pega o primeiro vértice da fila
        s = queue.front();
        queue.pop_front();

        /* Pega todos os vértices adjacentes ao vértice atual (s).
         Marca como visitado todos aqueles que ainda não
         foram visitados e os coloca na fila. */
        for (i = adj[s].begin(); i != adj[s].end(); ++i)
        {
            
            if (!visited[*i])
            {
                _print2File(s, *i, !current_color);

                visited[*i] = true;
                
                // Adiciona vértice adjancente (agora visitado) na fila.
                queue.push_back(*i);
            }
        }
    }
    
    return true;
}

void Graph::_print2File(int node_first, int node_second, bool color)
{
    
    file_content << "   " << node_first << " -- " << node_second << ";\n";
}

string Graph::getOutputString()
{
    file_content << "}";
    
    return file_content.str();
}
