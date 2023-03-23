/*
*****************************************
*                                       *
*     Darshan Vala                      *
*     U39780959                         *
*                                       *
*                                       *
*****************************************
*/

#include <iostream>
#include "rotate-array.h"
using namespace std;

// empty RotatableArray
RotatableArray::RotatableArray()
{
  size = 0;
  capacity = DEFAULT_CAPACITY;
  data = new int[capacity];
}

//constructors and assignment
RotatableArray::RotatableArray(const RotatableArray&rry)
{
  int d;

  this -> capacity = rry.capacity;
  this -> data = new int[capacity];
  this -> size = rry.size;

  for(d = 0; d < size; d++)
  {
      this -> data[d] = rry.data[d];
  }
}

RotatableArray::RotatableArray(RotatableArray&&rry)
{
  this -> data = rry.data;
  rry.data = nullptr;
}

RotatableArray& RotatableArray::operator=(const RotatableArray&rry)
{
  int d;

  this -> capacity = rry.capacity;
  this -> data = new int[capacity];
  this -> size = rry.size;

  for(d = 0; d < size; d++)
  {
    this -> data[d] = rry.data[d];
  }

  return *this;
}

RotatableArray& RotatableArray::operator=(RotatableArray&&rry)
{
  this -> data = rry.data;
  rry.data = nullptr;

  return *this;
}


//Destructor
RotatableArray::~RotatableArray()
{
  delete []data;
}

//elements
void RotatableArray::push_back(int object)
{
  if(size == capacity)
  {
    capacity = 2 * capacity;
    int *temp = new int[capacity];

    for(int d = 0; d < size; d++)
    {
      temp[d] = data[d];
    }

    delete []data;
    data = temp;

  }
  data[size] = object;
  size++;
}

int RotatableArray::pop_back()
{
  if(size == 0)
  return 0;

  size--;
  return data[size];
}

int& RotatableArray::operator[](int x)
{
  int &q = data[x];
  return q;
}

int RotatableArray::operator[](int x) const
{
  return data[x];
}


//     >0  rotate right
//     <0   rotate left
void RotatableArray::rotate(int i)
{
  if(i < 0)
  {
    i = -i;
    for(int d = 0; d < i; d++)
    {
      int h;
      h = data[0];

      for(int b = 0; b < size - 1; b++)
      {
        data[b] = data[b+1];
      }

      data[size-1] = h;
    }
  }
  else
  {
    for(int d = 0; d < i; d++)
    {
      int h;
      h = data[size - 1];
      for(int b = size - 1; b > 0; b--)
      {
        data[b] = data[b - 1];
      }
      data[0] = h;
    }
  }
}


//Print
ostream& operator<<(ostream&out, const RotatableArray&rry)
{
  for(int d = 0; d < rry.size; d++)
  {
    out << rry.data[d] <<" ";
  }
  return out;
}
