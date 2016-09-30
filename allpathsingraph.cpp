// C++ program to print all paths from a source to destination.
#include<iostream>
#include <list>
using namespace std;
 
// A directed graph using adjacency list representation
class Graph
{
    int V;    // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists
 
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , int , bool [], int [], int &);
 
public:
    Graph(int V);   // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s, int d);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
 
void Graph::printAllPathsUtil(int u, int d, bool visited[],int path[], int &path_index)
{
    visited[u] = true;
    path[path_index] = u;
    path_index++;
    if (u == d)
    {
        for (int i = 0; i<path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
    else 
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, d, visited, path, path_index);
    }
    path_index--;
    visited[u] = false;
}
 

 
void Graph::printAllPaths(int s, int d)
{
    bool *visited = new bool[V];
 
    int *path = new int[V];
    int path_index = 0;
 
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    printAllPathsUtil(s, d, visited, path, path_index);
}
 
int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(2, 0);
    g.addEdge(2, 1);
    g.addEdge(1, 3);
 
    int s = 2, d = 3;
    cout << "Following are all different paths from " << s
         << " to " << d << endl;
    g.printAllPaths(s, d);
 
    return 0;
}

