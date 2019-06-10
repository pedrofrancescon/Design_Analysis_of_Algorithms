//
//  main.cpp
//  Dijkstra_Prim_Kruskal
//
//  Created by Pedro Francescon Cittolin on 03/06/19.
//  Copyright © 2019 Pedro Francescon Cittolin. All rights reserved.
//

#include "Graph.hpp"

int main(int argc, char *argv[])
{
    int nodeCount = 10;
    Graph g(nodeCount);
    
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 2);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 4, 1);
    g.addEdge(2, 1, 1);
    g.addEdge(2, 3, 2);
    g.addEdge(2, 4, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 6, 2);
    g.addEdge(4, 6, 5);
    g.addEdge(3, 9, 4);
    g.addEdge(9, 6, 2);
    g.addEdge(0, 7, 2);
    g.addEdge(7, 9, 1);
    g.addEdge(4, 5, 2);
    g.addEdge(1, 5, 6);
    g.addEdge(7, 8, 3);
    g.addEdge(1, 8, 4);
    g.addEdge(8, 5, 2);
    g.addEdge(0, 9, 3);
    g.addEdge(0, 8, 5);
    
    int origin = 8;
    int destination = 6;
    int *prec = g.dijkstra(origin, destination);
    
    string output_file = g.getOutputString(prec, destination);
    cout << output_file;
    
    return 0;
}
