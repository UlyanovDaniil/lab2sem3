#pragma once
#include <iostream>
#include "DynamicVector.h"

template<typename T>
class TLowTriangleMatrix : TDynamicVector<TDynamicVector<T>>
{
public:
  TLowTriangleMatrix(tsize size = 1);
  TLowTriangleMatrix(const TLowTriangleMatrix<T>& ltm);
  TLowTriangleMatrix(TLowTriangleMatrix<T>&& ltm) noexcept;
  ~TLowTriangleMatrix();

  TLowTriangleMatrix<T>& operator=(const TLowTriangleMatrix<T>& ltm);
  TLowTriangleMatrix<T>& operator=(TLowTriangleMatrix<T>&& ltm) noexcept;

  tsize size() const noexcept;

  // индексация
  TDynamicVector<T>& operator[](tsize i);
  const TDynamicVector<T>& operator[](tsize i) const;

  // сравнение
  bool operator==(const TLowTriangleMatrix<T>& ltm) const noexcept;
  bool operator!=(const TLowTriangleMatrix<T>& ltm) const noexcept;

  // скалярные операции
  TLowTriangleMatrix<T> operator+(T val);
  TLowTriangleMatrix<T> operator-(T val);
  TLowTriangleMatrix<T> operator*(T val);

  // векторные операции
  TLowTriangleMatrix<T> operator+(const TLowTriangleMatrix<T>& ltm);
  TLowTriangleMatrix<T> operator-(const TLowTriangleMatrix<T>& ltm);
  TLowTriangleMatrix<T> operator*(const TLowTriangleMatrix<T>& ltm);

  // ввод/вывод
  template<typename T>
  friend std::istream& operator>>(std::istream& istr, TLowTriangleMatrix<T>& ltm);

  template<typename T>
  friend std::ostream& operator<<(std::ostream& ostr, TLowTriangleMatrix<T>& ltm);
};

template<typename T>
inline TLowTriangleMatrix<T>::TLowTriangleMatrix(tsize size) : TDynamicVector<TDynamicVector<T>>(size)
{
  if (size > 0)
  {
    sz = size;
    pMem = new TDynamicVector<T>[sz];
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = TDynamicVector<T>(i + 1);
    }
  }
  else
  {
    throw '!';
  }
}

template<typename T>
inline TLowTriangleMatrix<T>::TLowTriangleMatrix(const TLowTriangleMatrix<T>& ltm)
{
  sz = ltm.sz;
  if (ltm.pMem == 0)
  {
    pMem = 0;
  }
  else
  {
    pMem = new TDynamicVector<T>[sz];
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = ltm.pMem[i];
    }
  }
}

template<typename T>
inline TLowTriangleMatrix<T>::TLowTriangleMatrix(TLowTriangleMatrix<T>&& ltm) noexcept
{
  sz = ltm.sz;
  pMem = ltm.pMem;

  ltm.sz = 0;
  ltm.pMem = nullptr;
}

template<typename T>
inline TLowTriangleMatrix<T>::~TLowTriangleMatrix()
{
  if (pMem != nullptr)
  {
    delete[] pMem;
    pMem = 0;
  }
  sz = 0;
}

template<typename T>
inline TLowTriangleMatrix<T>& TLowTriangleMatrix<T>::operator=(const TLowTriangleMatrix<T>& ltm)
{
  if (this == &ltm)
  {
    return *this;
  }
  if (pMem != nullptr)
  {
    delete[] pMem;
  }
  if (ltm.pMem == nullptr)
  {
    pMem = nullptr;
    sz = 0;
  }
  else
  {
    pMem = new TDynamicVector<T>[ltm.sz];
    sz = ltm.sz;
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = ltm.pMem[i];
    }
  }
  return *this;
}

template<typename T>
inline TLowTriangleMatrix<T>& TLowTriangleMatrix<T>::operator=(TLowTriangleMatrix<T>&& ltm) noexcept
{
  if (this == &ltm)
  {
    return *this;
  }
  if (pMem != nullptr)
  {
    delete[] pMem;
  }
  pMem = ltm.pMem;
  sz = ltm.sz;

  ltm.pMem = nullptr;
  ltm.sz = 0;
  return *this;
}

template<typename T>
inline tsize TLowTriangleMatrix<T>::size() const noexcept
{
  return sz;
}

template<typename T>
inline TDynamicVector<T>& TLowTriangleMatrix<T>::operator[](tsize i)
{
  if (i < 0 || i > sz || pMem == nullptr)
  {
    throw '!';
  }
  return pMem[i];
}

template<typename T>
inline const TDynamicVector<T>& TLowTriangleMatrix<T>::operator[](tsize i) const
{
  if (i < 0 || i > sz || pMem == nullptr)
  {
    throw '!';
  }
  return pMem[i];
}

template<typename T>
inline bool TLowTriangleMatrix<T>::operator==(const TLowTriangleMatrix<T>& ltm) const noexcept
{
  if (sz != ltm.sz)
  {
    return false;
  }
  for (tsize i = 0; i < sz; i++)
  {
    if (pMem[i] != ltm.pMem[i])
    {
      return false;
    }
  }
  return true;
}

template<typename T>
inline bool TLowTriangleMatrix<T>::operator!=(const TLowTriangleMatrix<T>& ltm) const noexcept
{
  if (sz != ltm.sz)
  {
    return true;
  }
  for (tsize i = 0; i < sz; i++)
  {
    if (pMem[i] != ltm.pMem[i])
    {
      return true;
    }
  }
  return false;
}

template<typename T>
inline TLowTriangleMatrix<T> TLowTriangleMatrix<T>::operator+(T val)
{
  TDynamicMatrix res(*this);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] + val;
  }
  return res;
}

template<typename T>
inline TLowTriangleMatrix<T> TLowTriangleMatrix<T>::operator-(T val)
{
  TDynamicMatrix res(*this);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] - val;
  }
  return res;
}

template<typename T>
inline TLowTriangleMatrix<T> TLowTriangleMatrix<T>::operator*(T val)
{
  TDynamicMatrix res(*this);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] * val;
  }
  return res;
}

template<typename T>
inline TLowTriangleMatrix<T> TLowTriangleMatrix<T>::operator+(const TLowTriangleMatrix<T>& ltm)
{
  TDynamicMatrix res(*this);
  if (sz != ltm.sz)
  {
    throw '!';
  }
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] + ltm.pMem[i];
  }
  return res;
}

template<typename T>
inline TLowTriangleMatrix<T> TLowTriangleMatrix<T>::operator-(const TLowTriangleMatrix<T>& ltm)
{
  TDynamicMatrix res(*this);
  if (sz != ltm.sz)
  {
    throw '!';
  }
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] + ltm.pMem[i];
  }
  return res;
}

template<typename T>
inline TLowTriangleMatrix<T> TLowTriangleMatrix<T>::operator*(const TLowTriangleMatrix<T>& ltm)
{
  if (sz != ltm.sz)
  {
    throw '!';
  }
  TLowTriangleMatrix<T> res(sz);
  for (tsize i = 0; i < sz; i++)
  {
    for (tsize j = 0; j < sz; j++)
    {
      if (i >= j)
      {
        res[i][j] = 0;
        for (tsize l = 0; l < sz; l++)
        {
          if (i >= l && l >= j)
          {
            res[i][j] += pMem[i][l] * ltm.pMem[l][j];
          }
        }
      }
    }
  }
  return res;
}

template<typename T>
inline std::istream& operator>>(std::istream& istr, TLowTriangleMatrix<T>& ltm)
{
  if (ltm.sz == 0)
  {
    istr << "";
    return istr;
  }
  for (tsize i = 0; i < m.sz - 1; i++)
  {
    istr << ltm[i] << "\n";
  }
  istr << ltm[ltm.sz - 1];
  return istr;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& ostr, TLowTriangleMatrix<T>& ltm)
{
  if (ltm.pMem == nullptr || ltm.sz == 0)
  {
    ostr << "";
    return ostr;
  }
  for (tsize i = 0; i < ltm.sz - 1; i++)
  {
    ostr << ltm[i] << "\n";
  }
  ostr << ltm[ltm.sz - 1];
  return ostr;
}
