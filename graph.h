
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
using std::ifstream;
using std::string;
using std::ostream;
using std::vector;
using std::map;

class Graph
{
public:
  Graph();
  ~Graph();
  void addVertex(string name);
  void addEdge(string from, string to, int weight);
  string getShortestPath(string from, string to);

private:
  string currentSource;
  map<string,Vertex> verticies;
  map<string, vector<Neighbor>> adjList;
  MinPriorityQueue minQ;

  class Vertex
  {
  public:
    string pi;
    int key;
    Vertex();
    Vertex(string, int);
    ~Vertex();
  }

  class Neighbor
  {
  public:
    string name;
    int weight;
    Neighbor();
    Neighbor(string, int);
    ~Neighbor();
  }

  void buildSSPTree(string source);
  void relax(string u, string v, int weight);
}

#endif
