
#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include "graph.h"
using std::string;
using std::vector;
//using std::sort;

//constructors
Graph::Graph()
{
  currentSource = "";
}

Graph::Vertex::Vertex()
{
  pi = "";
  key = (int)NULL;
}

Graph::Vertex::Vertex(string s, int i)
{
  pi = s;
  key = i;
}

Graph::Neighbor::Neighbor()
{
  name = "";
  weight = (int)NULL;
}

Graph::Neighbor::Neighbor(string s, int i)
{
  name = s;
  weight = i;
}

Graph::~Graph()
{

}

Graph::Vertex::~Vertex()
{
  pi = "";
  key = (int)NULL;
}

Graph::Neighbor::~Neighbor()
{
  name = "";
  weight = (int)NULL;
}

void Graph::addVertex(string name)
{
  Vertex x = Vertex(name, verticies.size());
  verticies.insert(std::pair<string, Vertex>(name, x));
  minQ.insert(x.pi, x.key);
}

void Graph::addEdge(string from, string to, int weight)
{
  Neighbor x = Neighbor(to, weight);
  if(adjList.find(from) != adjList.end())
  {
    adjList[from].push_back(x);
  }
  else
  {
    vector<Neighbor> myNeighbors;
    myNeighbors.push_back(x);
    adjList.insert(std::pair<string, vector<Neighbor>>(from, myNeighbors));
  }
}












//End
