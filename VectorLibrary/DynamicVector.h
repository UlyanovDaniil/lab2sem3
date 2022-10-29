#pragma once
#include <iostream>
#include "VectorIterator.h"

typedef long tsize;

template <typename T>
class TVectorIterator;

template<typename T>
class TDynamicVector
{
protected:
  tsize sz;
  T* pMem;
public:
  TDynamicVector(tsize size = 1);
  TDynamicVector(T* arr, tsize size);
  TDynamicVector(const TDynamicVector<T>& v);
  TDynamicVector(TDynamicVector<T>&& v) noexcept;
  ~TDynamicVector();

  TDynamicVector<T>& operator=(const TDynamicVector<T>& v);
  TDynamicVector<T>& operator=(TDynamicVector<T>&& v) noexcept;

  tsize size() const noexcept;

  // индексация
  T& operator[](tsize i);
  const T& at(tsize i) const;

  // сравнение
  bool operator==(const TDynamicVector<T>& v) const noexcept;
  bool operator!=(const TDynamicVector<T>& v) const noexcept;

  // скалярные операции
  TDynamicVector<T> operator+(T val);
  TDynamicVector<T> operator-(T val);
  TDynamicVector<T> operator*(T val);

  // векторные операции
  TDynamicVector<T> operator+(const TDynamicVector<T>& v);
  TDynamicVector<T> operator-(const TDynamicVector<T>& v);
  T operator*(const TDynamicVector<T>& v);

  // ввод/вывод
  template<typename T>
  friend std::istream& operator>>(std::istream& istr, TDynamicVector<T>& v);

  template<typename T>
  friend std::ostream& operator<<(std::ostream& ostr, TDynamicVector<T>& v);

  TVectorIterator<T> begin();
  TVectorIterator<T> end();
};

template<typename T>
inline TDynamicVector<T>::TDynamicVector(tsize size)
{
  if (size > 0)
  {
    pMem = new T[size];
    sz = size;
  }
  else
  {
    throw '!';
  }
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(T* arr, tsize size)
{
  if ((size > 0) && (arr != nullptr))
  {
    pMem = new T[size];
    sz = size;
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = arr[i];
    }
  }
  else
  {
    throw '!';
  }
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(const TDynamicVector<T>& v)
{
  if (v.pMem == nullptr)
  {
    pMem = nullptr;
    sz = 0;
  }
  else
  {
    sz = v.sz;
    pMem = new T[sz];
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = v.pMem[i];
    }
  }
}

template<typename T>
inline TDynamicVector<T>::TDynamicVector(TDynamicVector<T>&& v) noexcept
{
  sz = v.sz;
  pMem = v.pMem;

  v.sz = 0;
  v.pMem = nullptr;
}

template<typename T>
inline TDynamicVector<T>::~TDynamicVector()
{
  if (pMem != nullptr)
  {
    delete[] pMem;
    pMem = nullptr;
  }
  sz = 0;
}

template<typename T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(const TDynamicVector<T>& v)
{
  if (this == &v)
  {
    return *this;
  }
  if (pMem != nullptr)
  {
    delete[] pMem;
  }
  if (v.pMem == nullptr)
  {
    pMem = nullptr;
    sz = 0;
  }
  else
  {
    pMem = new T[v.sz];
    sz = v.sz;
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = v.pMem[i];
    }
  }
  return *this;
}

template<typename T>
inline TDynamicVector<T>& TDynamicVector<T>::operator=(TDynamicVector<T>&& v) noexcept
{
  if (this == &v)
  {
    return *this;
  }
  if (pMem != nullptr)
  {
    delete[] pMem;
  }
  pMem = v.pMem;
  sz = v.sz;

  v.pMem = nullptr;
  v.sz = 0;
  return *this;
}

template<typename T>
inline tsize TDynamicVector<T>::size() const noexcept
{
  return sz;
}

template<typename T>
inline T& TDynamicVector<T>::operator[](tsize i)
{
  if (i < 0 || i > sz || pMem == nullptr)
  {
    throw '!';
  }
  return pMem[i];
}

template<typename T>
inline const T& TDynamicVector<T>::at(tsize i) const
{
  if (i < 0 || i > sz || pMem == nullptr)
  {
    throw '!';
  }
  return pMem[i];
}

template<typename T>
inline bool TDynamicVector<T>::operator==(const TDynamicVector<T>& v) const noexcept
{
  if (sz != v.sz)
  {
    return false;
  }
  for (tsize i = 0; i < sz; i++)
  {
    if (pMem[i] != v.pMem[i])
    {
      return false;
    }
  }
  return true;
}

template<typename T>
inline bool TDynamicVector<T>::operator!=(const TDynamicVector<T>& v) const noexcept
{
  if (sz != v.sz)
  {
    return true;
  }
  for (tsize i = 0; i < sz; i++)
  {
    if (pMem[i] != v.pMem[i])
    {
      return true;
    }
  }
  return false;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(T val)
{
  TDynamicVector<T> res(sz);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] + val;
  }
  return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(T val)
{
  TDynamicVector<T> res(sz);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] - val;
  }
  return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator*(T val)
{
  TDynamicVector<T> res(sz);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] * val;
  }
  return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator+(const TDynamicVector<T>& v)
{
  if (sz != v.sz)
  {
    throw '!';
  }
  TDynamicVector<T> res(sz);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] + v.pMem[i];
  }
  return res;
}

template<typename T>
inline TDynamicVector<T> TDynamicVector<T>::operator-(const TDynamicVector<T>& v)
{
  if (sz != v.sz)
  {
    throw '!';
  }
  TDynamicVector<T> res(sz);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] - v.pMem[i];
  }
  return res;
}

template<typename T>
inline T TDynamicVector<T>::operator*(const TDynamicVector<T>& v)
{
  if (sz != v.sz)
  {
    throw '!';
  }
  T res = 0;
  for (tsize i = 0; i < sz; i++)
  {
    res += pMem[i] * v.pMem[i];
  }
  return res;
}

template<typename T>
inline std::istream& operator>>(std::istream& istr, TDynamicVector<T>& v)
{
  if (v.sz == 0)
  {
    istr >> "";
    return istr;
  }
  for (tsize i = 0; i < v.sz; i++)
  {
    istr >> v[i];
  }
  return istr;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& ostr, TDynamicVector<T>& v)
{
  if (v.pMem == nullptr || v.sz == 0)
  {
    ostr << "";
    return ostr;
  }
  for (tsize i = 0; i < v.sz - 1; i++)
  {
    ostr << v[i] << " ";
  }
  ostr << v[v.sz - 1];
  return ostr;
}

template<typename T>
inline TVectorIterator<T> TDynamicVector<T>::begin()
{
  return TVectorIterator<T>(*this);
}

template<typename T>
inline TVectorIterator<T> TDynamicVector<T>::end()
{
  return TVectorIterator<T>(*this, this->size());
}