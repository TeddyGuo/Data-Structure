#include "prim.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

ostream& operator<<(ostream& out, Edge edge)
{
    out << edge.start << " " << edge.end << " " << edge.weight;
    return out;
}

template <class T>
void print(vector<T> t)
{
    for (int i = 0; i < t.size(); i++)
    {
        cout << t[i] << endl;
    }
}
void appendPath(vector<Edge> edgeList, vector<Edge>& tempList, string vertex)
{
    for (int i = 0; i < edgeList.size(); i++)
    {
        if (edgeList[i].end == vertex || edgeList[i].start == vertex)
            tempList.push_back(edgeList[i]);
    }
    
}
bool has_in(vector<string> vertexList, Edge edge)
{
    short start = 0, end = 0;
    for (int i = 0; i < vertexList.size(); i++)
    {
        if (edge.start == vertexList[i])
            start = 1;
        if (edge.end == vertexList[i])
            end = 1;
    }
    if (start == 1 && end == 1)
        return 1;
    return 0;
}
void delPath(vector<Edge> path, vector<string> vertexList, vector<Edge>& tempList)
{
    for (int i = 0; i < path.size(); i++)
    {
        for (int j = 0; j < tempList.size(); j++)
        {
            if (path[i].equal(tempList[j] ) )
            {
                tempList.erase(tempList.begin() + j);
                j--;
            }
        }
    }
    for (int i = 0; i < tempList.size(); i++)
    {
        if (has_in(vertexList, tempList[i] ) )
        {
            tempList.erase(tempList.begin() + i);
            i--;
        }
    }
    
}
void minPath(vector<Edge>& tempList)
{
    int index = 0;
    if (tempList.size() == 1)
        return;
    else
    {
        for (int i = 1; i < tempList.size(); i++)
        {
            if (tempList[index].weight > tempList[i].weight )
                index = i;
        }
        Edge edge(tempList[index]);
        tempList.clear();
        tempList.push_back(edge);
    }
    return;
}
void appendVertex(vector<string>& vertexList, Edge edge)
{
    vertexList.push_back(edge.start);
    vertexList.push_back(edge.end);
    sort( vertexList.begin(), vertexList.end() );
    vertexList.erase( unique( vertexList.begin(), vertexList.end() ), vertexList.end() );
}

void prim()
{
    string start;
    vector<string> vertexList;
    vector<Edge> path;
    vector<Edge> edgeList;
    set<string> vertexSet;

    // the input
    string line;
    while (getline(cin, line, '\n'))
    {
        // it means the end of the input
        if (line.size() == 1)
        {
            start = line;
            break;
        }
        else
        {
            istringstream iss(line);
            string line1, line2;
            int temp;

            iss >> line1;
            vertexSet.insert(line1);
            iss >> line2;
            vertexSet.insert(line2);
            iss >> temp;
            Edge edge(line1, line2, temp);
            edgeList.push_back(edge);
        }
    }
    
    vertexList.push_back(start);
    for (int i = 0; i < vertexSet.size() - 1; i++)
    {
        vector<Edge> tempList;
        for (int j = 0; j < vertexList.size(); j++)
        {
            appendPath(edgeList, tempList, vertexList[j]);
        }

        delPath(path, vertexList, tempList);

        minPath(tempList);
        path.push_back(tempList[0] );

        appendVertex(vertexList, tempList[0]);
    }
    
    print(path);
}