//
//  Graph.cpp
//  Coloração
//
//  Created by Pedro Francescon Cittolin on 17/04/19.
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#include "Graph.hpp"

void Graph::breadthSearch(int s)
{
    // Vetor que diz quais nós ja foa visitados. Iniciam todos não visitados.
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
    {
        visited[i] = false;
    }

    // Cria uma fila
    list<int> queue;

    // Marca o nó atual (s) como visitado e coloca ele na fila
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
            
            _addEdge2File(s, *i);
            
            if (!visited[*i])
            {
                visited[*i] = true;
                
                // Adiciona vértice adjancente (agora visitado) na fila.
                queue.push_back(*i);
            }
        }
    }
}

/*-------------------------------------------------------------*/

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
    
    canBe2Colored = true;
}

void Graph::addEdge(int v, int w)
{
    // Adiciona "w" na lista de adjacência de "v".
    adj[v].push_back(w);
}

void Graph::_addEdge2File(int node_first, int node_second)
{
    file_edges << "   " << node_first << " -- " << node_second << ";\n";
}

void Graph::_addColor2Vertex(int color, int vertex)
{
    // Considerando a cor verde como "1"
    if (color)
        nodes_green << vertex << " ";
    
    // Considerando a cor azul como "0"
    else
        nodes_blue << vertex << " ";
}

string Graph::getOutputString()
{
    
    stringstream final_content;
    
    final_content << "graph Colored_graph {\n";
    final_content << "   node [style=filled];\n";
    
    if (canBe2Colored)
    {
        final_content << "   {node [style=filled,color=darkseagreen2] " << nodes_green.str() << "}\n";
        final_content << "   {node [style=filled,color=lightblue] " << nodes_blue.str() << "}\n";
    }
    
    final_content << file_edges.str();
    
    final_content << "}";
    
    return final_content.str();
}
