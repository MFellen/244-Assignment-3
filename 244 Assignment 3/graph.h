#pragma once
#include "vertex.h"
#include "edge.h"
using namespace std;

class Graph {
protected:
	Vertex* varray[20];
	Edge* earray[20];
public:
	Graph() {
		for (int i = 0; i < 20; i++) {
			varray[i] = nullptr;
			earray[i] = nullptr;
		}
	};
	virtual ~Graph() {};
	virtual bool addVertex(Vertex& v) = 0;
	virtual bool addVertices(Vertex* vArray) = 0; //the edges that connect also deleted
	virtual bool removeVertex(Vertex& v) = 0;
	
	virtual bool addEdge(Edge& e) = 0;
	virtual bool removeEdge(Edge& e) = 0; //may result in orphan vertex

	virtual bool searchVertex(const Vertex& v) = 0; //checks if its in the graph 
	virtual bool searchEdge(const Edge& e) = 0; // checks if its in the graph

	virtual void display() const = 0;

	virtual void toString() const = 0;

	virtual bool clean() = 0;
};