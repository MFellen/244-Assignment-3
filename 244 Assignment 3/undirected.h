#pragma once
#include "vertex.h"
#include "edge.h"
#include "graph.h"
using namespace std;

class Undirected :public Graph {
private:
	Vertex* varray[20];
	Edge* earray[20];
	int nvertex = 0;
	int nedge = 0;
public:
	virtual bool addVertex(Vertex& v);
	virtual bool addVertices(Vertex* vArray); 
	virtual bool removeVertex(Vertex& v);//the edges that connect also deleted

	virtual bool addEdge(Edge& e);
	virtual bool removeEdge(Edge& e); //may result in orphan vertex

	virtual bool searchVertex(const Vertex& v); //checks if its in the graph 
	virtual bool searchEdge(const Edge& e); // checks if its in the graph

	virtual void display() const;

	virtual void toString() const;

	virtual bool clean();
};