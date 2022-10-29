#pragma once
#include "DynamicVector.h"

template <typename T>
class TDynamicVector;

template <typename T>
class TVectorIterator
{
protected:
  TDynamicVector<T>& vector;
  int index;
public:
  TVectorIterator(TDynamicVector<T>& v);
  TVectorIterator(TDynamicVector<T>& v, int _index);

  bool operator==(const TVectorIterator<T>& v);
  bool operator!=(const TVectorIterator<T>& v);

  TVectorIterator<T> operator++();
  TVectorIterator<T> operator--();

  T& operator*();
};

template<typename T>
inline TVectorIterator<T>::TVectorIterator(TDynamicVector<T>& v) : vector(v)
{
  index = 0;
}

template<typename T>
inline TVectorIterator<T>::TVectorIterator(TDynamicVector<T>& v, int _index) : vector(v)
{
  index = _index;
}

template<typename T>
inline bool TVectorIterator<T>::operator==(const TVectorIterator<T>& v)
{
  if (&vector == &(v.vector) && index != v.index)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename T>
inline bool TVectorIterator<T>::operator!=(const TVectorIterator<T>& v)
{
  if (&vector != &(v.vector) || index != v.index)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<typename T>
inline TVectorIterator<T> TVectorIterator<T>::operator++()
{
  TVectorIterator<T> res(*this);
  res.index++;
  if (res.index > res.vector.size())
  {
    res.index = res.vector.size();
  }
  return res;
}

template<typename T>
inline TVectorIterator<T> TVectorIterator<T>::operator--()
{
  TVectorIterator<T> res(*this);
  res.index--;
  if (res.index < 0)
  {
    res.index = 0;
  }
  return res;
}

template<typename T>
inline T& TVectorIterator<T>::operator*()
{
  return vector.at(index);
}
