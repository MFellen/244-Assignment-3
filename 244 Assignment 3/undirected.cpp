#include "vertex.h"
#include "edge.h"
#include "graph.h"
#include "undirected.h"
#include <iostream>
using namespace std;

Undirected::Undirected():Graph() {}
Undirected::~Undirected() {}

bool Undirected::addVertex(Vertex& v) {
	if (nvertex + 1 < 20) {
		varray[nvertex] = new Vertex(v);
		++nvertex;
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
			for (int j = i; j < nvertex; j++) {
				varray[j] = varray[j + 1];
			}
			--nvertex;
			for (int k = 0; k < nedge; k++) {
				if (earray[k]->get_p1().get_id() == v.get_id() || earray[k]->get_p2().get_id() == v.get_id()) {
					while (earray[k]->get_p1().get_id() == v.get_id() || earray[k]->get_p2().get_id() == v.get_id()) {
						for (int z = k; z < nedge; z++) {
							earray[z] = earray[z + 1];
						}
						--nedge;
					}
				}

			}
			return true;
			break;
		}
		else if (i == nvertex - 1) {
			return false;
		}
	}
};

bool Undirected::addEdge(Edge& e){
	if (nedge + 1 < 20) {
		earray[nedge] = new Edge(e);
		++nedge;
		return true;
	}
	else { return false; }
};
bool Undirected::removeEdge(Edge& e){
	for (int k = 0; k < nedge; k++) {
		if (earray[k]->get_id() == e.get_id()) {
			for (int z = k; z < nedge; z++) {
				earray[z] = earray[z + 1];
			}
			--nedge;
			return true;
			break;
		}
		else if (k == nedge - 1) { return false; }
	}
};

bool Undirected::searchVertex(const Vertex& v){
	for (int i = 0; i < nvertex; i++) {
		if (varray[i]->get_id() == v.get_id()) {
			return true;
			break;
		}
		else if (i == nvertex - 1) {
			return false;
		}
	}
};
bool Undirected::searchEdge(const Edge& e){
	for (int k = 0; k < nedge; k++) {
		if (earray[k]->get_id() == e.get_id()) {
			for (int z = k; z < nedge; k++) {
				earray[z] = earray[z + 1];
			}
			return true;
			break;
		}
		else if (k == nedge - 1) {
			return false;
		}
	}
};

void Undirected::display() const{
	cout << "Printing each vertex and which ones its atached to." << endl;
	for (int i = 0; i < nvertex; i++) {
		cout << varray[i]->get_id() << ": ";
		for (int k = 0; k < nedge; k++) {
			if (earray[k]->get_p1().get_id() == varray[i]->get_id()) {
				cout << earray[k]->get_p2().get_id() << ' ';
			}
			if (earray[k]->get_p2().get_id() == varray[i]->get_id()) {
				cout << earray[k]->get_p1().get_id() << ' ';
			}
		}
		cout << endl;
	}
};

void Undirected::toString() const{
	cout << "Edges (v1,v2,w):"<< endl;
	for (int i = 0; i < nedge; i++) {
		cout << "(" << earray[i]->get_p1().get_id() << ',' << earray[i]->get_p2().get_id() <<',' << earray[i]->get_weight()<<')' << endl;
	}
};

bool Undirected::clean() {
	for (int i = 0; i < 20; i++) {
		varray[i] = nullptr;
		earray[i] = nullptr;
	}
	nedge = 0;
	nvertex = 0;
	return true;
};

Undirected& Undirected::operator=(const Undirected& u) {
	for (int i = 0; i < 20; i++) {
		earray[i] = u.earray[i];
		varray[i] = u.varray[i];
	}
	nvertex = u.nvertex;
	nedge = u.nedge;
	return *this;
}

Undirected operator+(Undirected& u1, Undirected& u2) {
	for (int i = 0; i < u2.nvertex; i++) {
		u1.addVertex(*u2.varray[i]);
	}
	for (int i = 0; i < u2.nedge; i++) {
		u1.addEdge(*u2.earray[i]);
	}
	return u1;
}
bool operator> (Undirected& u1, Undirected& u2) {
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < u1.nedge; i++) {
		sum1 = sum1 + u1.earray[i]->get_weight();
	}
	for (int i = 0; i < u2.nedge; i++) {
		sum2 = sum2 + u2.earray[i]->get_weight();
	}
	return (sum1 > sum2);
};
bool operator== (const Undirected& u1, const Undirected& u2) {
	for (int i = 0; i < 20; i++) {
		if (!(u1.earray[i]->get_id() == u2.earray[i]->get_id()&&u1.earray[i]->get_id() == u2.earray[i]->get_id())) {
			return false;
			break;
		}
		return true;
	}
};
void operator++(Undirected& u) {
	for (int i=0; i < u.nedge; i++) {
		u.earray[i]->set_weight(u.earray[i]->get_weight()+1);
	}
};
ostream& operator<<(ostream& output, const Undirected& u) {
	output << "printing Graph"<< endl;
	u.toString();
	u.display();
	return output;
};