#include "vertex.h"
#include "edge.h"
#include <cmath>
using namespace std;

int Edge::count = 1;
Edge::Edge() {
	id = count;
	weight = 0;
	p1 = Vertex();
	p2 = Vertex();
	++count;
}
Edge::Edge(int w, Vertex a, Vertex b) {
	id = count;
	weight = w;
	p1 = a;
	p2 = b;
	++count;
}
Edge::Edge(Edge& e) {
	id = e.id;
	weight = e.get_weight();
	p1 = e.get_p1();
	p2 = e.get_p2();
}

int Edge::get_id() const { return id; };

int Edge::get_weight() { return weight; };
void Edge::set_weight(int w) { weight = w; };

Vertex Edge::get_p1() { return p1;};
void Edge::set_p1(Vertex a) { p1 = a; };

Vertex Edge::get_p2() { return p2;};
void Edge::set_p2(Vertex b) { p2 = b; };