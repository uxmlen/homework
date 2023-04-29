#include <iostream>

#include "graph.h"

int main()
{
    GraphInt graph;
    graph.add_vertex(0)
        .add_vertex(1)
        .add_vertex(3)
        .add_vertex(4)
        .add_vertex(2);

    graph.add_edge(0, 1)
        .add_edge(0, 2)
        .add_edge(3, 4)
        .add_edge(1, 3)
        .add_edge(2, 3)
        .add_edge(0, 3);

    graph.dfs(0);
    graph.bfs(0);
    return 0;
}
