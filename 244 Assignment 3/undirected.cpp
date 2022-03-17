#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "undirected.h"
using namespace std;

bool Undirected::addVertex(Vertex& v) {
	if (nvertex + 1 < 20) {
		++nvertex;
		varray[nvertex] = new Vertex(v);
		return true;
	}
	else { return false; }
};
bool Undirected::addVertices(Vertex* varr) {
	if (nvertex + sizeof(*varr) < 20) {
		for (int i = 0; i < sizeof(*varr); i++) {
			++nvertex;
			varray[nvertex] = new Vertex(varr[i]);
		}
		return true;
	}
	else { return false; }
};
bool Undirected::removeVertex(Vertex& v) {
	for (int i = 0; i < nvertex; i++) {
		if (varray[i]->get_id() == v.get_id()) {
			for (int k = 0; k < nedge; k++) {
				if (earray[k]->get_p1().get_id() == v.get_id()|| earray[k]->get_p2().get_id() == v.get_id()) {
					for (int z = k; z < nedge; k++) {
						earray[z] = earray[z + 1];
					}
				}

			}
			for (int j = i; j < nvertex; j++) {
				varray[j] = varray[j + 1];
			}
			return true;
			break;
		}
		else if (i = nvertex - 1) {
			return false;
		}
	}
};

bool Undirected::addEdge(Edge& e){
	if (nedge + 1 < 20) {
		++nedge;
		earray[nedge] = new Edge(e);
		return true;
	}
	else { return false; }
};
bool Undirected::removeEdge(Edge& e){
	for (int k = 0; k < nedge; k++) {
		if (earray[k]->get_id() == e.get_id()) {
			for (int z = k; z < nedge; k++) {
				earray[z] = earray[z + 1];
			}
			return true;
			break;
		}
		else if (k == nedge - 1) { return false; }
	}
};

bool Undirected::searchVertex(const Vertex& v){};
bool Undirected::searchEdge(const Edge& e){
	for (int k = 0; k < nedge; k++) {
		if (earray[k]->get_id() == e.get_id()) {
			for (int z = k; z < nedge; k++) {
				earray[z] = earray[z + 1];
			}
		}
	}
};

void Undirected::display() const{};

void Undirected::toString() const{};

bool Undirected::clean(){};