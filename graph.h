#ifndef GRAPH_H
#define GRAPH_H

#include <matrix.h>

class graph
{
private:
    matrix *m;

public:
    graph();
    ~graph();
    void new_matrix(int);
    int get_n();
    int get_a(int, int);
    void set_a(int, int, int);
};

#endif // GRAPH_H
