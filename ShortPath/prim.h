#include "edge.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>
#include <algorithm>
using namespace std;

void delFromUnreach(vector<string>& unreach, string chosen)
{
    int index = -1;
    for (int i = 0; i < unreach.size(); i++)
    {
        if (unreach[i] == chosen)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
        unreach.erase(unreach.begin() + index);
}
bool in_N(set<string> N, string chosen)
{
    for (set<string>::iterator i = N.begin(); i != N.end(); i++)
    {
        if (*i == chosen)
            return 1;
    }
    return 0;
}
bool in_unreach(vector<string> unreach, string chosen)
{
    for (int i = 0; i <unreach.size(); i++)
    {
        if (unreach[i] == chosen)
            return 1;
    }
    return 0;
}
Edge findMinEdge(set<string> N, vector<string> unreach, vector<Edge> edgeList)
{
    vector<Edge> temp;
    for (int i = 0; i < edgeList.size(); i++)
        if ((in_N(N, edgeList[i].start) && in_unreach(unreach, edgeList[i].end) ) 
            || (in_N(N, edgeList[i].end) && in_unreach(unreach, edgeList[i].start) ) )
            temp.push_back(edgeList[i]);

    // the edge containing smallest weight put at first place
    for (int i = 0; i < temp.size(); i++)
        for (int j = i + 1; j < temp.size(); j++)
            if (temp[i].weight > temp[j].weight)
                swap(temp[i], temp[j]);

    // print(temp);
    // cout << endl;
    
    return temp[0];
}

void prim()
{
    int linenum;
    string start;
    vector<Edge> edgeList;
    set<string> vertexSet; // unreachedSet
    vector<string> unreach;
    set<string> N; // reachSet
    vector<Edge> MST; // spanning tree

    cin >> linenum;
    // the input
    string line;
    while (linenum != -1)
    {
        getline(cin, line, '\n');
        
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
        
        linenum--;
    }
    // it means the end of the input
    cin >> start;
    // important to del the first element of edgeList
    edgeList.erase(edgeList.begin());
    // print(vertexSet);
    // print(edgeList);
    // vertexSet turn into unreach in order to prevent some problems
    for (set<string>::iterator it = vertexSet.begin(); it != vertexSet.end(); it++)
        unreach.push_back(*it);
    unreach.erase(unreach.begin() );
    // print(unreach);

    // set start point for N
    N.insert(start);
    delFromUnreach(unreach, start);

    while (!unreach.empty())
    {
        Edge chosen = findMinEdge(N, unreach, edgeList);

        MST.push_back(chosen);

        N.insert(chosen.start);
        N.insert(chosen.end);
        //del the elements
        delFromUnreach(unreach, chosen.start);
        delFromUnreach(unreach, chosen.end);
    }
    sortEdge(MST);
    print(MST);
}