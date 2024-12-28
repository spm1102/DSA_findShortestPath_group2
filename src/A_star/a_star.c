#include "a_star.h"

void a_star_queue(graph_t *p_graph, cell_t** grid, int startVertex, int destination, void (*GUI_displaypPath)(graph_t *p_graph, cell_t** grid))
{
    A_STAR_queue_t *p_queue = NULL;
    p_queue = A_STAR_QUEUE_Create();
    p_graph->vertices[startVertex].total_dist = 0;
    A_STAR_QUEUE_Put(p_queue, startVertex, 0, p_graph);
    while (p_queue->front != NULL)
    {
        A_STAR_node_t *minNode = A_STAR_QUEUE_Get(p_queue, p_graph);
        int currentVertex = minNode->vertexName;
        A_STAR_NODE_Free(minNode);

        if (currentVertex == destination)
        {
            break;
        }

        p_graph->vertices[currentVertex].visited = 1;
        GUI_displaypPath(p_graph, grid);
        //Put all the adjacent nodes into the priority queue following to their distance to the source + the heuristic distance to the destination
        edge_t *temp = p_graph->vertices[currentVertex].edge;
        while (temp != NULL)
        {
            int nextVertex = temp->dest;
            double weight = temp->weight;

            if (!p_graph->vertices[nextVertex].visited)
            {
                double newDist = p_graph->vertices[currentVertex].total_dist + weight;
                double heuristic_of_nextVertex = p_graph->vertices[nextVertex].heuristic_dist;
                if (newDist + heuristic_of_nextVertex < p_graph->vertices[nextVertex].total_dist + heuristic_of_nextVertex)
                {
                    p_graph->vertices[nextVertex].total_dist = newDist;
                    p_graph->vertices[nextVertex].preVertex = currentVertex;
                    A_STAR_QUEUE_Put(p_queue, nextVertex, newDist, p_graph);
                }
            }
            temp = temp->next;
        }
    }
    A_STAR_QUEUE_Free(p_queue);
}