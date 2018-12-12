#ifndef PRIM_H
#define PRIM_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void prim();

template <class T>
void print(vector<T> t);

class Edge
{
public:
    string start;
    string end;
    int weight;
    Edge(string start, string end, int weight)
    {
        this->start = start;
        this->end = end;
        this->weight = weight;
    }
    Edge(const Edge& edge)
    {
        this->start = edge.start;
        this->end = edge.end;
        this->weight = edge.weight;
    }
    bool equal(Edge edge)
    {
        if (edge.start == this->start && edge.end == this->end && edge.weight == this->weight)
            return 1;
        return 0;
    }
};

ostream& operator<<(ostream&, Edge);

#endif