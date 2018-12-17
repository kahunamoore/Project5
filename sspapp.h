
#ifndef SSPAPP_H
#define SSPAPP_H

#include <vector>

#include "graph.h"

using std::ifstream;
using std::string;
using std::ostream;
using std::vector;

class SSPapp
{
public:
  void readGraph();
  void processQueries();
  void printGraph();

private:
  Graph myGraph;
};

#endif // SSPAPP_H
