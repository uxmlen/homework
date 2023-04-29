#include <iostream>

#include "graph.h"

int main()
{
    GraphInt graph;
    graph.add_vertex(0)
        .add_vertex(1)
        .add_vertex(2)
        .add_vertex(3)
        .add_vertex(4)
        .add_vertex(5);

    graph.add_edge(0, 2, 13)
        .add_edge(0, 4, 21)
        .add_edge(0, 5, 27)
        .add_edge(5, 4, 11)
        .add_edge(1, 5, 38)
        .add_edge(1, 4, 43)
        .add_edge(2, 4, 77)
        .add_edge(3, 2, 82);

    graph.dfs(0);
    graph.bfs(0);
    graph.find_shortest_path(4);
    return 0;
}
