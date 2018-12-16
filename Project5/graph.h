
#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <map>
#include <string>
//#include <sort>

#include "minpriority.h"

using std::string;
using std::vector;
//using std::sort;
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

  class Neighbor
  {
  public:
    string name;
    int weight;
    Neighbor();
    Neighbor(string, int);
    ~Neighbor();
  };

  class Vertex
  {
  public:
    string pi;
    int key;
    Vertex();
    Vertex(string, int);
    ~Vertex();
  };

  void buildSSPTree(string source);
  void relax(string u, string v, int weight);

  string currentSource;
  map<string, Vertex> verticies;
  map<string, vector<Neighbor>> adjList;
  MinPriorityQueue minQ;
};

#endif //GRAPH_H
