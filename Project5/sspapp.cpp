
#include <iostream>

#include "sspapp.h"
using std::cin;
using std::cout;
using std::endl;

void SSPapp::readGraph()
{
    //std::cout << "TODO: readGraph" << std::endl;
    // pseudo code
    // read Vertex count
    int vertexCount;
    cout << "Enter number of verticies: " << endl;
    cin >> vertexCount;
    // read Vertexes
    for(int i = 1; i < vertexCount; i++)
    {
      string vertexName;
      cout << "Enter vertex name: " << endl;
      cin >> vertexName;
      myGraph.addVertex(vertexName);
    }
    // read Edge count
    int edgeCount;
    cout << "Enter number of edges: " << endl;
    cin >> edgeCount;
    // read Edges
    for (int i = 1; i < edgeCount; i++)
    {
      string from;
      string to;
      int weight;
      cout << "Enter starting vertex, ending vertex, and weight: " << endl;
      cin >> from;
      cin >> to;
      cin >> weight;
      myGraph.addEdge(from, to, weight);
    }
}

void SSPapp::processQueries()
{
    std::cout << "TODO: processQueries" << std::endl;
    // while (not eof || input == quit
    //    read query
    //    find min path
    //    print result
    // endwhile
}

int main()
{
    SSPapp myApp;
    myApp.readGraph();
    myApp.processQueries();
}
