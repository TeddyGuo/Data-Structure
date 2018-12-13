#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

template <class T>
void print(vector<T> t)
{
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << endl;
    }
}
template <class T>
void print(set<T> t)
{
    for (typename set<T>::iterator it = t.begin(); it != t.end(); it++)
    {
        cout << *it << endl;
    }
}
void print_out_vertices(unordered_map<string, unordered_map<string, int> > vertices)
{
    int count = 1;
    for (unordered_map<string, unordered_map<string, int> >::iterator it = vertices.begin(); it != vertices.end(); it++)
    {
        count = 1;
        cout << it->first << " ";
        for (unordered_map<string, int>::iterator i = it->second.begin(); i != it->second.end(); i++)
        {
            cout << count++ << ": ";
            cout << i->first << " " << i->second << " ";
        }
        cout << endl;
    }
}

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

ostream& operator<<(ostream& out, Edge edge)
{
    out << edge.start << " " << edge.end << " " << edge.weight;
    return out;
}

void sortEdge(vector<Edge>& edgeList)
{
    for (int i = 0; i < edgeList.size(); i++)
    {
        for (int j = i + 1; j < edgeList.size(); j++)
        {   
            if (edgeList[i].weight > edgeList[j].weight)
            {
                swap(edgeList[i], edgeList[j]);
            }
        }
    }
}
void add_vertex(string label, vector<Edge> edgeList, unordered_map<string, unordered_map<string, int> >& vertices)
{
    for (int i = 0; i < edgeList.size(); i++)
        if (label == edgeList[i].start)
            vertices[label][edgeList[i].end] = edgeList[i].weight;
}

#endif