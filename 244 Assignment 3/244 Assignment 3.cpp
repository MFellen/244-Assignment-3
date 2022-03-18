#include <iostream>
#include <string>
#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "undirected.h"
using namespace std;

int main(){
    Vertex v1;
    Vertex v2;
    Vertex v3;
    Vertex v4;
    
    Edge e1(1,v1,v2);
    Edge e2(1, v1, v3);
    Edge e3(1, v1, v4);
    Edge e4(1, v2, v3);
    Edge e5(1, v3, v4);
    
    Undirected g1;
    Undirected g2;
    Undirected g3;

    g1.addVertex(v1);
    g1.addVertex(v2);
    g1.addVertex(v3);
    g2.addVertex(v4);
    
    g1.addEdge(e1);
    g1.addEdge(e2);
    g1.addEdge(e3);
    g1.addEdge(e4);
    g2.addEdge(e5);
    
    g1.toString();
    g1.display();
    
    g1 = g1 + g2;
    g1.toString();
    g1.display();

    cout << "remove e2" << endl;
    g1.removeEdge(e2);
    g1.toString();
    g1.display();

    cout << "remove v1" << endl;
    ++g1;
    g1.removeVertex(v1);
    cout << g1 << (g1>g2) << endl << (g1==g2);
    return 0;
}

