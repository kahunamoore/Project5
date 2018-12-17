/**
 * @file MinPriority.cpp   Definition of functions for the prioroty queue
 *
 * @brief
 *    Stores strings in a vector that is sorted in a heap queue by
 * minimum value based on a given 'key' integer.
 *
 * @author Jonathan Willis
 * @date 11/4/18
 */

#include <vector>
#include <iostream>
#include <string>
#include <limits>
#include "minpriority.h"
using std::cout;
using std::endl;

/**
 * Empty Element constructor
*/
MinPriorityQueue::Element::Element()
{
  id = nullptr;
  key = 0;
}

/**
 * Full Element constructor
 *
 * @param iniID initial id
 * @param iniKEY initial key
*/
MinPriorityQueue::Element::Element(const string& iniID, int iniKEY)
{
  id = new string(iniID);
  key = iniKEY;
}

/**
 * Element deconstructor
*/
MinPriorityQueue::Element::~Element()
{
  *id = "";
  id = nullptr;
  key = 0;
}

/**
 * MinPriorityQueue constructor
*/
MinPriorityQueue::MinPriorityQueue()
{
  minHeap.clear();
}

/**
 * MinPriorityQueue deconstructor
*/
MinPriorityQueue::~MinPriorityQueue()
{
   vector<Element*>::iterator it = minHeap.begin();
   while (it != minHeap.end())
   {
      delete *it;
      it++;
   }
}

/**
 * MinPriorityQueue insert
 *
 * @param id name of the object
 * @param key weight of object to be sorted
 *
 * Inserts new element to back of vector
*/
void MinPriorityQueue::insert(const string& id, int key)
{
  Element* temp = new Element(id, key);
  minHeap.push_back(temp);
  decreaseKey(id, key);
}

/**
 * MinPriorityQueue decreaseKey
 *
 * @param id name of the object to be changed
 * @param newKey the new weight of the object
 * @param i index of the object
 *
 * Changes the key of a given element to a lesser value
*/
void MinPriorityQueue::decreaseKey(string id, int newKey)
{
  int i;
  for (int j = 0; j < (int)minHeap.size(); j++)
  {
    if(*minHeap[j]->id == id)
    {
      i = j;
    }
  }

  if(newKey > minHeap[i]->key)
  {
    std::cerr << "New key is larger than last key" << '\n';
  }
  else
  {
    minHeap[i]->key = newKey;
    while(i > 0 && minHeap[parent(i)]->key > minHeap[i]->key)
    {
      Element temp(*minHeap[i]->id, minHeap[i]->key);
      *minHeap[i]->id = *minHeap[parent(i)]->id;
      minHeap[i]->key = minHeap[parent(i)]->key;
      *minHeap[parent(i)]->id = *temp.id;
      minHeap[parent(i)]->key = temp.key;
      i = parent(i);
    }
  }
}

/**
 * MinPriorityQueue extractMin
 *
 * @param min name of the smallest object
 *
 * Removes the first (smallest) element and returns the id
*/
string MinPriorityQueue::extractMin()
{
  if(minHeap.size() < 1)
  {
    std::cerr << "heap underflow" << '\n';
    return "";
  }
  else
  {
    string min = *minHeap[0]->id;
    *minHeap[0]->id = *minHeap[minHeap.size() - 1]->id;
    minHeap[0]->key = minHeap[minHeap.size() - 1]->key;
    minHeap.pop_back();
    minHeapify(0);
    return min;
  }
}

/**
 * MinPriorityQueue buildMinHeap
 *
 * Makes sure everything is where it should be
*/
void MinPriorityQueue::buildMinHeap()
{
  for (int i = (minHeap.size() / 2); i < 0; i--)
  {
    minHeapify(i);
  }
}

/**
 * MinPriorityQueue minHeapify
 *
 * @param i index of the object to be sorted
 * @param l left child of the object
 * @param r right child of the object
 * @param smallest index of the object with the smallest key
 *
 * Sets the object at the given index to be where it should be
*/
void MinPriorityQueue::minHeapify(int i)
{
  int l = left(i);
  int r = right(i);
  int smallest;
  if(l <= (int)minHeap.size() && minHeap[l]->key < minHeap[i]->key)
  {
    smallest = l;
  }
  else
  {
    smallest = i;
  }
  if(r <= (int)minHeap.size() && minHeap[r]->key < minHeap[smallest]->key)
  {
    smallest = r;
  }
  if(smallest != i)
  {
    Element temp(*minHeap[i]->id, minHeap[i]->key);
    *minHeap[i]->id = *minHeap[smallest]->id;
    minHeap[i]->key = minHeap[smallest]->key;
    *minHeap[smallest]->id = *temp.id;
    minHeap[smallest]->key = temp.key;
    minHeapify(smallest);
  }
}

/**
 * MinPriorityQueue parent
 *
 * @param i index of object
 *
 * returns index of the parent of the object at index i
*/
int MinPriorityQueue::parent(int i)
{
  return (i / 2);
}

/**
 * MinPriorityQueue left
 *
 * @param i index of object
 *
 * returns the left child of the object at index i
*/
int MinPriorityQueue::left(int i)
{
  return (i * 2);
}

/**
 * MinPriorityQueue right
 *
 * @param i index of object
 *
 * returns the right child of the object at index i
*/
int MinPriorityQueue::right(int i)
{
  return ((i * 2) + 1);
}
