#pragma once
#include "vertex.h"
#include "edge.h"
#include "graph.h"
using namespace std;

class Undirected :public Graph {
private:
	int nvertex = 0;
	int nedge = 0;
public:
	Undirected();
	~Undirected();
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
	Undirected& operator= (const Undirected& u);
	
	friend Undirected operator+ (Undirected& u1, Undirected& u2);
	friend bool operator> (Undirected& u1, Undirected& u2);
	friend bool operator== (const Undirected& u1, const Undirected & u2);
	friend void operator++(Undirected& u);
	friend ostream& operator<<(ostream& output, const Undirected& u);
};

