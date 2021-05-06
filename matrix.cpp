#include "matrix.h"
#include <QDebug>

matrix::matrix(int size)
{
    qDebug() << "1";
    n = size;
    a.resize(n);
    qDebug() << "2";
    for (int i=0; i<n; i++)
    {
        a[i].resize(n);
    }
    qDebug() << "3";
}

matrix::~matrix()
{
    for (int i=0; i<a.size(); i++)
    {
        a[i].clear();
    }
    a.clear();
}
