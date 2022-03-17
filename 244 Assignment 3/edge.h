#pragma once
#include "vertex.h"
using namespace std;

class Edge {
private:
	static int count;
	int id;
	int weight;
	Vertex p1;
	Vertex p2;
public:
	Edge();
	Edge(int w, Vertex a, Vertex b); //weight is set individually
	Edge(Edge& e);
	int get_id() const;
	int get_weight();
	void set_weight(int w);
	Vertex get_p1();
	void set_p1(Vertex a);
	Vertex get_p2();
	void set_p2(Vertex b);
};