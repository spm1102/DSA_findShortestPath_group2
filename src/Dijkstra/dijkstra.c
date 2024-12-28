#include "dijkstra.h"
void dijkstra(graph_t *p_graph, cell_t **grid, int startVertex, int destination, void (*GUI_displayPath)(graph_t *p_graph, cell_t **grid))
{
    DIJKSTRA_queue_t *p_queue = NULL;
    p_queue = DIJKSTRA_QUEUE_Create();
    //Set the distance to the source of startVertex
    p_graph->vertices[startVertex].total_dist = 0;
    //Put the source node to queue
    DIJKSTRA_QUEUE_Put(p_queue, startVertex, 0);
    while (p_queue->front != NULL)
    {
        DIJKSTRA_node_t *minNode = DIJKSTRA_QUEUE_Get(p_queue);
        int currentVertex = minNode->vertex;
        DIJKSTRA_NODE_Free(minNode);

         if (currentVertex == destination)
        {
            break;
        }

        if (p_graph->vertices[currentVertex].visited)
        {
            continue;
        }
        p_graph->vertices[currentVertex].visited = 1;
        GUI_displayPath(p_graph, grid);

        edge_t *temp = p_graph->vertices[currentVertex].edge;
        while (temp != NULL)
        {
            int nextVertex = temp->dest;
            double weight = temp->weight;
            //Priority queue ( the nearer the node is to the source, the more likely it is to the front of the queue)
            if (!p_graph->vertices[nextVertex].visited)
            {
                //Arrange checked nodes into order
                //They are arranged following to thri distane to the source node
                double new_dist = p_graph->vertices[currentVertex].total_dist + weight;
                if (new_dist < p_graph->vertices[nextVertex].total_dist)
                {
                    p_graph->vertices[nextVertex].total_dist = new_dist;
                    p_graph->vertices[nextVertex].preVertex = currentVertex;
                    DIJKSTRA_QUEUE_Put(p_queue, nextVertex, new_dist);
                }
            }
            temp = temp->next;
        }
    }
    DIJKSTRA_QUEUE_Free(p_queue);
}