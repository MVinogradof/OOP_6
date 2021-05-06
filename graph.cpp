#include "graph.h"

graph::graph()
{
    m = nullptr;
}

graph::~graph()
{
    if (m != nullptr) delete m;
}

void graph::new_matrix(int size)
{
    m = new matrix(size);
}

int graph::get_n()
{
    return m->n;
}

int graph::get_a(int i, int j)
{
    return m->a[i][j];
}

void graph::set_a(int a, int i, int j)
{
    m->a[i][j] = a;
}
