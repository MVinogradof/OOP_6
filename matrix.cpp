#include "matrix.h"
#include <QDebug>

matrix::matrix(int size)
{
    n = size;
    a.resize(n);
    for (int i=0; i<n; i++)
    {
        a[i].resize(n);
    }
}

matrix::~matrix()
{
    for (int i=0; i<a.size(); i++)
    {
        a[i].clear();
    }
    a.clear();
}
