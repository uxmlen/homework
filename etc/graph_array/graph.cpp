#include "graph.h"

GraphInt& GraphInt::add_vertex(int vnumber)
{
    verteces_[vertex_count_++] = vnumber;
    return *this;
}

GraphInt& GraphInt::add_edge(int v1, int v2, int weight)
{
    matrix_[v1][v2] = weight;
    matrix_[v2][v1] = weight;
    return *this;
}

void GraphInt::del_edge(int v1, int v2)
{
    matrix_[v1][v2] = 0;
    matrix_[v2][v1] = 0;
}
void GraphInt::del_vertex(int vnumber)
{
    size_t i, index_num;
    for (i = 0; i < SIZE; ++i) {
        matrix_[i][vnumber] = 0;
        matrix_[vnumber][i] = 0;
    }
    for (i = 0; i < vertex_count_; ++i) {
        if (verteces_[i] == vnumber) {
            index_num = i;
        }
    }
    vertex_count_--;
    for (i = index_num; i < vertex_count_; ++i) {
        verteces_[i] = verteces_[i + 1];
    }
}
