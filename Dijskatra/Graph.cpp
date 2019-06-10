//
//  Graph.cpp
//  Dijkstra_Prim_Kruskal
//
//  Created by Pedro Francescon Cittolin on 03/06/19.
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#include "Graph.hpp"

Graph::Graph(int V)
{
    this->V = V; // atribui o número de vértices
    
    /*
     Cria as listas onde cada lista é uma lista de pairs
     onde cada pair é formado pelo vértice destino e o custo
     */
    adj = new list<pair<int, int> >[V];
}

void Graph::addEdge(int v1, int v2, int weight)
{
    /*
     Arestas são adicionadas com redundância na lista de
     adjacências p/ garantir que todos os vértices vizinhos vão ser
     visitados a partir de qualquer vértice inicial
     */
    adj[v1].push_back(make_pair(v2, weight));
    adj[v2].push_back(make_pair(v1, weight));
}

int* Graph::dijkstra(int orig, int dest)
{
    // Vetor de distâncias
    int dist[V];
    
    // Vetor de precedentes
    int *prec = new int[V];
    
    /*
     Vetor de visitados serve para caso o vértice já tenha sido
     expandido (visitado), não expandir mais
     */
    int visited[V];
    
    // Fila de prioridades de pair (distancia, vértice)
    priority_queue < pair<int, int>,
    vector<pair<int, int> >, greater<pair<int, int> > > pq;
    
    // Inicia o vetor de distâncias e visitados
    for(int i = 0; i < V; i++)
    {
        dist[i] = INFINITE;
        prec[i] = -1;
        visited[i] = false;
    }
    
    // A distância de orig para orig é 0
    dist[orig] = 0;
    
    // Insere na fila
    pq.push(make_pair(dist[orig], orig));
    
    // Loop do algoritmo
    while(!pq.empty())
    {
        pair<int, int> p = pq.top(); // extrai o pair do topo
        int u = p.second; // obtém o vértice do pair
        pq.pop(); // remove da fila
        
        // Verifica se o vértice não foi expandido
        if(visited[u] == false)
        {
            // Marca como visitado
            visited[u] = true;
            
            list<pair<int, int> >::iterator it;
            
            // Percorre os vértices "v" adjacentes de "u"
            for(it = adj[u].begin(); it != adj[u].end(); it++)
            {
                // Obtém o vértice adjacente e o custo da aresta
                int v = it->first;
                int edgeWeight = it->second;
                
                if (!visited[v])
                {
                    // Relaxamento (u, v)
                    if(dist[v] > (dist[u] + edgeWeight))
                    {
                        // Atualiza a distância de "v", atualiza vetor de precedentes e insere na fila
                        dist[v] = dist[u] + edgeWeight;
                        prec[v] = u;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }
    }
    
    // Retorna o vetor de precedentes
    return prec;
}

string Graph::getOutputString(int *prec, int dest)
{
    
    stringstream final_content;
    
    final_content << "graph Dijkstra {\n";
    final_content << "   edge [len=2];\n";
    
    int path[V];
    
    for (int i = 0; i < V; i++)
        path[i] = -1;
    
    int i = dest;
    
    while(prec[i] != -1)
    {
        path[i] = prec[i];
        i = prec[i];
    }
    
    path[i] = prec[i];
    
    for (int u = 0; u < V; u++)
    {
        list<pair<int, int> >::iterator it;
        
        // percorre os vértices "v" adjacentes de "u"
        for(it = adj[u].begin(); it != adj[u].end(); it++)
        {
            // obtém o vértice adjacente e o custo da aresta
            int v = it->first;
            int edgeWeight = it->second;
            
            if (!(v < u))
            {
                stringstream str;
                
                if (path[v] == u || path[u] == v)
                {
                   str << "  " << u << " -- " << v << "[label=" << edgeWeight << ",style=bold,color=red] ;\n";
                }
                else
                {
                    str << "  " << u << " -- " << v << "[label=" << edgeWeight << "] ;\n";
                }
                
                final_content << str.str();

            }
        }
    }
    
    final_content << "}";
    
    return final_content.str();
}
