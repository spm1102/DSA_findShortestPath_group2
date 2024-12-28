#include "GRAPH_GEN.h"
// Create a graph for 3 algorithm
graph_t *GEN_GRAPH_Create(const cell_t **grid)
{

    graph_t *p_graph = GRAPH_Create(grid);
    // 0:34, 1:79, 2:10, 3: 37, 4:71, 5:32, 6: 4, 7: 95, 8:65, 9:39
    EDGE_Add(p_graph, 34, 37, 3.2);     
    EDGE_Add(p_graph, 34, 32, 1.5);
    EDGE_Add_oneWay(p_graph, 4, 34, 2.3);
    EDGE_Add(p_graph, 34, 65, 2.5);


    EDGE_Add(p_graph, 79, 37, 3.2);
    EDGE_Add(p_graph, 79, 95, 4.9);
    EDGE_Add(p_graph, 79, 65, 4.4);
    EDGE_Add_oneWay(p_graph, 79, 39, 1.7);

    EDGE_Add(p_graph, 10, 71, 2.9);
    EDGE_Add(p_graph, 10, 32, 3.5);
    EDGE_Add(p_graph, 10, 4, 4.2);

    EDGE_Add_oneWay(p_graph, 37, 4, 3.5);
    EDGE_Add_oneWay(p_graph, 37, 95, 4.5);
    EDGE_Add(p_graph, 37, 65, 3.4);
    EDGE_Add_oneWay(p_graph, 37, 39, 3.4);

    EDGE_Add(p_graph, 71, 32, 2.4);
    EDGE_Add(p_graph, 71, 95, 4.3);

    EDGE_Add(p_graph, 32, 4, 3.7);
    
    EDGE_Add_oneWay(p_graph, 39, 4, 5.1);

    EDGE_Add_oneWay(p_graph, 95, 65, 2.0);

    return p_graph;
}