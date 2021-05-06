#ifndef MATRIX_H
#define MATRIX_H

#include <QVector>

class matrix
{
public:
    int n;
    QVector<QVector<qint16>> a;
    matrix(int);
    ~matrix();
};

#endif // MATRIX_H
