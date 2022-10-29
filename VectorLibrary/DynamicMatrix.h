#pragma once
#include "DynamicVector.h"

template<typename T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>>
{
public:
  TDynamicMatrix(tsize size = 1);
  TDynamicMatrix(const TDynamicMatrix<T>& m);
  TDynamicMatrix(TDynamicMatrix<T>&& m) noexcept;
  ~TDynamicMatrix();

  TDynamicMatrix<T>& operator=(const TDynamicMatrix<T>& m);
  TDynamicMatrix<T>& operator=(TDynamicMatrix<T>&& m) noexcept;

  tsize size() const noexcept;

  // индексация
  TDynamicVector<T>& operator[](tsize i);
  const TDynamicVector<T>& operator[](tsize i) const;

  // сравнение
  bool operator==(const TDynamicMatrix<T>& m) const noexcept;
  bool operator!=(const TDynamicMatrix<T>& m) const noexcept;

  // скалярные операции
  TDynamicMatrix<T> operator+(T val);
  TDynamicMatrix<T> operator-(T val);
  TDynamicMatrix<T> operator*(T val);

  // векторные операции
  TDynamicMatrix<T> operator+(const TDynamicMatrix<T>& m);
  TDynamicMatrix<T> operator-(const TDynamicMatrix<T>& m);
  TDynamicMatrix<T> operator*(const TDynamicMatrix<T>& m);

  // ввод/вывод
  template<typename T>
  friend std::istream& operator>>(std::istream& istr, TDynamicMatrix<T>& m);

  template<typename T>
  friend std::ostream& operator<<(std::ostream& ostr, TDynamicMatrix<T>& m);
};

template<typename T>
inline TDynamicMatrix<T>::TDynamicMatrix(tsize size) : TDynamicVector<TDynamicVector<T>>(size)
{
  if (size > 0)
  {
    sz = size;
    pMem = new TDynamicVector<T>[sz];
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = TDynamicVector<T>(sz);
    }
  }
  else
  {
    throw '!';
  }
}

template<typename T>
inline TDynamicMatrix<T>::TDynamicMatrix(const TDynamicMatrix<T>& m)
{
  sz = m.sz;
  if (m.pMem == nullptr)
  {
    pMem = nullptr;
  }
  else
  {
    pMem = new TDynamicVector<T>[sz];
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = m.pMem[i];
    }
  }
}

template<typename T>
inline TDynamicMatrix<T>::TDynamicMatrix(TDynamicMatrix<T>&& m) noexcept
{
  sz = m.sz;
  pMem = m.pMem;

  m.sz = 0;
  m.pMem = nullptr;
}

template<typename T>
inline TDynamicMatrix<T>::~TDynamicMatrix()
{
  if (pMem != nullptr)
  {
    delete[] pMem;
    pMem = nullptr;
  }
  sz = 0;
}

template<typename T>
inline TDynamicMatrix<T>& TDynamicMatrix<T>::operator=(const TDynamicMatrix<T>& m)
{
  if (this == &m)
  {
    return *this;
  }
  if (pMem != nullptr)
  {
    delete[] pMem;
  }
  if (m.pMem == nullptr)
  {
    pMem = nullptr;
    sz = 0;
  }
  else
  {
    pMem = new TDynamicVector<T>[m.sz];
    sz = m.sz;
    for (tsize i = 0; i < sz; i++)
    {
      pMem[i] = m.pMem[i];
    }
  }
  return *this;
}

template<typename T>
inline TDynamicMatrix<T>& TDynamicMatrix<T>::operator=(TDynamicMatrix<T>&& m) noexcept
{
  if (this == &m)
  {
    return *this;
  }
  if (pMem != nullptr)
  {
    delete[] pMem;
  }
  pMem = m.pMem;
  sz = m.sz;

  m.pMem = nullptr;
  m.sz = 0;
  return *this;
}

template<typename T>
inline tsize TDynamicMatrix<T>::size() const noexcept
{
  return sz;
}

template<typename T>
inline TDynamicVector<T>& TDynamicMatrix<T>::operator[](tsize i)
{
  if (i < 0 || i > sz || pMem == nullptr)
  {
    throw '!';
  }
  return pMem[i];
}

template<typename T>
inline const TDynamicVector<T>& TDynamicMatrix<T>::operator[](tsize i) const
{
  if (i < 0 || i > sz || pMem == nullptr)
  {
    throw '!';
  }
  return pMem[i];
}

template<typename T>
inline bool TDynamicMatrix<T>::operator==(const TDynamicMatrix<T>& m) const noexcept
{
  if (sz != m.sz)
  {
    return false;
  }
  for (tsize i = 0; i < sz; i++)
  {
    if (pMem[i] != m.pMem[i])
    {
      return false;
    }
  }
  return true;
}

template<typename T>
inline bool TDynamicMatrix<T>::operator!=(const TDynamicMatrix<T>& m) const noexcept
{
  if (sz != m.sz)
  {
    return true;
  }
  for (tsize i = 0; i < sz; i++)
  {
    if (pMem[i] != m.pMem[i])
    {
      return true;
    }
  }
  return false;
}

template<typename T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator+(T val)
{
  TDynamicMatrix res(*this);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] + val;
  }
  return res;
}

template<typename T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator-(T val)
{
  TDynamicMatrix res(*this);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] - val;
  }
  return res;
}

template<typename T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator*(T val)
{
  TDynamicMatrix res(*this);
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] * val;
  }
  return res;
}

template<typename T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator+(const TDynamicMatrix<T>& m)
{
  TDynamicMatrix res(*this);
  if (sz != m.sz)
  {
    throw '!';
  }
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] + m.pMem[i];
  }
  return res;
}

template<typename T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator-(const TDynamicMatrix<T>& m)
{
  TDynamicMatrix res(*this);
  if (sz != m.sz)
  {
    throw '!';
  }
  for (tsize i = 0; i < sz; i++)
  {
    res.pMem[i] = pMem[i] - m.pMem[i];
  }
  return res;
}

template<typename T>
inline TDynamicMatrix<T> TDynamicMatrix<T>::operator*(const TDynamicMatrix<T>& m)
{
  if (sz != m.sz)
  {
    throw '!';
  }
  TDynamicMatrix<T> res(sz);
  for (tsize i = 0; i < sz; i++)
  {
    for (tsize j = 0; j < sz; j++)
    {
      res[i][j] = 0;
      for (tsize l = 0; l < sz; l++)
      {
        res[i][j] += pMem[i][l] * m.pMem[l][j];
      }
    }
  }
  return res;
}

template<typename T>
inline std::istream& operator>>(std::istream& istr, TDynamicMatrix<T>& m)
{
  if (m.sz == 0)
  {
    istr << "";
    return istr;
  }
  for (tsize i = 0; i < m.sz - 1; i++)
  {
    istr << m[i] << "\n";
  }
  istr << m[m.sz - 1];
  return istr;
}

template<typename T>
inline std::ostream& operator<<(std::ostream& ostr, TDynamicMatrix<T>& m)
{
  if (m.pMem == nullptr || m.sz == 0)
  {
    ostr << "";
    return ostr;
  }
  for (tsize i = 0; i < m.sz - 1; i++)
  {
    ostr << m[i] << "\n";
  }
  ostr << m[m.sz - 1];
  return ostr;
}