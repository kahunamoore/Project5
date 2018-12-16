
#ifndef SSPAPP_H
#define SSPAPP_H

#include <vector>
using std::ifstream;
using std::string;
using std::ostream;
using std::vector;

class SSPapp
{
public:
  void readGraph();
  void processQueries();

private:
  Graph myGraph;
}
