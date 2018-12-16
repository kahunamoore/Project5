
#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include "graph.h"
using std::cout;
using std::endl;

//constructors
Graph::Graph()
{

}

Graph::Vertex::Vertex()
{
  pi = "";
  key = 0;
}

Graph::Vertex::Vertex(string s, int i)
{
  pi = s;
  key = i;
}

Graph::Neighbor::Neighbor()
{
  name = "";
  weight = 0;
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
  key = 0;
}

Graph::Neighbor::~Neighbor()
{
  name = "";
  weight = 0;
}

void Graph::addVertex(string name)
{

}














//End
