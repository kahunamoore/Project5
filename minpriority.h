/**
 * @file MinPriority.h   Declaration of the MinPriorityQueue class.
 *
 * @author Jonathan Willis
 * @date 11/4/18
 */

#ifndef MINPRIORITY_H
#define MINPRIORITY_H

#include <vector>
using std::ifstream;
using std::string;
using std::ostream;
using std::vector;

class MinPriorityQueue
{
public:
  MinPriorityQueue();                 //constructor
  ~MinPriorityQueue();                //deconstructor
  void insert(const string&, int);    //inserts new element to back
  void decreaseKey(string, int);      //reduces key of given element
  string extractMin();                //removes first (smallest) element

private:
  class Element                       //declaration of Element
  {
  public:
    string* id;                       //name of object
    int key;                          //where object goes in queue
    Element();                        //constructors...
    Element(const string&, int);
    ~Element();
  };
  void buildMinHeap();                 //makes sure entire queue is sorted
  vector<Element*> minHeap;            //queue to use
  void minHeapify(int i);              //sorts index i into queue
  int parent(int i);                   //returns parent of object
  int left(int i);                     //returns left child
  int right(int i);                    //returns right child
};

#endif
