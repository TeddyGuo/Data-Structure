#include "edge.h"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

bool different_tree(vector<vector<string> > forest, string start, string end)
{
    int position1 = -1, position2 = -1;
    for (int i = 0; i < forest.size(); i++)
    {
        for (int j = 0; j < forest[i].size(); j++)
        {
            if (start == forest[i][j]) position1 = i;
            if (end == forest[i][j]) position2 = i;
        }
    }
    if (position1 != position2) return 1;
    return 0;
}
void addForest(vector<vector<string> >& forest, string start, string end)
{
    // get position of start and end
    vector<string> start_vec;
    vector<string> end_vec;
    int position1 = -1, position2 = -1;
    for (int i = 0; i < forest.size(); i++)
    {
        for (int j = 0; j < forest[i].size(); j++)
        {
            if (start == forest[i][j]) 
            {
                position1 = i;
                start_vec = forest[i];
            }
            if (end == forest[i][j]) 
            {
                position2 = i;
                end_vec = forest[i];
            }
        }
    }
    // del original vector elements
    if (position1 < position2)
    {
        forest.erase(forest.begin() + position1);
        position2 = position2 - 1;
        forest.erase(forest.begin() + position2);
    }
    else
    {
        forest.erase(forest.begin() + position2);
        position1 = position1 - 1;
        forest.erase(forest.begin() + position1);
    }
    // combine two vectors
    start_vec.insert( start_vec.end(), end_vec.begin(), end_vec.end() );
    // insert
    forest.insert(forest.begin(), start_vec);
}

void kruskal()
{
    set<string> F;
    vector<vector<string> > forest;
    vector<Edge> MST;
    vector<Edge> edgeList;

    int lineno = 0;
    cin >> lineno;

    string line;
    while (lineno != -1)
    {
        getline(cin, line, '\n');
        istringstream iss(line);
        string str1, str2;
        int temp = 0;

        iss >> str1; iss >> str2; iss >> temp;
        Edge edge(str1, str2, temp);
        edgeList.push_back(edge);

        F.insert(str1); F.insert(str2);

        lineno--;
    }
    cout << endl;
    // del first element of edgeList
    edgeList.erase(edgeList.begin() );
    // print(edgeList);
    sortEdge(edgeList);
    // print(edgeList);
    // turn set to vec
    for (set<string>::iterator it = F.begin(); it != F.end(); it++)
    {
        vector<string> temp;
        temp.push_back(*it);
        forest.push_back(temp);
    }

    while (edgeList.size() != 0)
    {
        // remove the first element from edgeList or Q
        Edge edge(edgeList[0]);
        edgeList.erase(edgeList.begin() );

        if (different_tree(forest, edge.start, edge.end) )
        {
            MST.push_back(edge);
            // Forest deal
            addForest(forest, edge.start, edge.end);
        }
    }
    print(MST);
}