#include "edge.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Node
{
public:
    string name;
    int distance;
    Node()
    {
        name = "";
        distance = -1;
    }
    Node(string name, int distance)
    {
        this->name = name; 
        this->distance = distance;
    }
    bool operator<(Node rhs) const
    {
        return distance < rhs.distance;
    }
};
ostream& operator<<(ostream& out, Node n)
{
    out << n.name << " " << n.distance;
    return out;
}
void delBigRepeatN(vector<Node>& N)
{
    for (int i = 0; i < N.size(); i++)
    {
        for (int j = i + 1; j < N.size(); j++)
        {
            if (N[i].name == N[j].name)
            {
                if (N[i].distance > N[j].distance)
                {
                    N.erase(N.begin() + i);
                    i--;
                }
                else
                    N.erase(N.begin() + j);
                j--;
            }
        }
    }
}
void sortN(vector<Node>& N)
{
    for (int i = 0; i < N.size(); i++)
    {
        for (int j = i + 1; j < N.size(); j++)
        {
            if (N[i].distance > N[j].distance)
            {
                swap(N[i], N[j]);
            }
        }
    }
}

void dijkstra()
{
    string start;
    vector<Edge> edgeList;
    set<string> nodeSet;
    unordered_map<string, int> distance;
    unordered_map<string, Node> prev;
    priority_queue<Node> Q;
    vector<Node> N;

    int lineno = 0;
    cin >> lineno;
    string line;
    while (lineno != -1)
    {
        getline(cin, line);
        istringstream iss(line);
        string str1, str2;
        int temp;
        iss >> str1; iss >> str2; iss >> temp;
        
        Edge edge(str1, str2, temp);
        edgeList.push_back(edge);

        nodeSet.insert(str1);
        nodeSet.insert(str2);

        lineno--;
    }
    cin >> start;
    
    edgeList.erase(edgeList.begin());
    // print(edgeList);
    // print(nodeSet);
    // initialize
    for (set<string>::iterator it = nodeSet.begin(); it != nodeSet.end(); it++)
    {
        distance[*it] = 9999999; // very big number
        // unknown
        Node node;
        prev[*it] = node;
    }
    distance[start] = 0;
    Q.push(Node(start, distance[start] ) );
    while (!Q.empty())
    {
        Node small = Q.top(); // get the known smallest distance Node
        // cout << Q.top() << endl;
        Q.pop();
        // append to N
        N.push_back(small);

        if (distance[small.name] != small.distance) continue;
        // for each edge outgoing from small as (small.name, out.end)
        for (int i = 0; i < edgeList.size(); i++)
        {
            if (edgeList[i].start == small.name)
            {
                // if d[v] > d[u] + w(u, v)
                if (distance[edgeList[i].end ] > distance[small.name] + edgeList[i].weight ) // w(u, v) means the distance from u to v
                {
                    distance[edgeList[i].end] = distance[small.name] + edgeList[i].weight;
                    prev[edgeList[i].end] = small;
                    Q.push(Node(edgeList[i].end, distance[edgeList[i].end ] ) );
                }
            }
        }
    }
    delBigRepeatN(N);
    sortN(N);
    print(N);
}