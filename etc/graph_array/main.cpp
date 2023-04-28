#include <iostream>

#include "graph.h"

int main()
{
    GraphInt g;
    g.add_vertex(0).add_vertex(1).add_vertex(3);

    g.add_edge(0, 1, 5);
    return 0;
}
