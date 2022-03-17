#pragma once
#include <string>
using namespace std;

class Vertex {
private:
	static int count;
	int id;
	int x;
	int y;
	string s_value;
public:
	Vertex();
	Vertex(int a, int b);
	Vertex(string s);
	Vertex(Vertex& v);
	int get_id() const;
	int get_x() const;
	void set_x(int a);
	int get_y() const;
	void set_y(int b);
	string get_s_value();
	void set_s_value(string s);
};