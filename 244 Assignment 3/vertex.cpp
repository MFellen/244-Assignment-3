#include "vertex.h"
using namespace std;

int Vertex::count = 1;
Vertex::Vertex() {
	id = count;
	x = 0;
	y = 0;
	s_value = '/0';
	++count;
};
Vertex::Vertex(int a, int b) {
	id = count;
	x = a;
	y = b;
	s_value = '/0';
	++count;
};
Vertex::Vertex(Vertex& v) {
	id = v.get_id();
	x = v.get_x();
	y = v.get_y();
	s_value = v.get_s_value();
};

int Vertex::get_id() const { return id; };

int Vertex::get_x() const { return x; };
void Vertex::set_x(int a) { x = a; };

int Vertex::get_y() const { return y; };
void Vertex::set_y(int b) { y = b; };

string Vertex::get_s_value() { return s_value; };
void Vertex::set_s_value(string s) { s_value = s; };