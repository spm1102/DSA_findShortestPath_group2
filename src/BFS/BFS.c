#include "BFS.h"

void BFS(graph_t* p_graph, cell_t** grid,int startVertex, int destination, void (*GUI_displayPath)(graph_t* p_graph, cell_t **grid)) {
    BFS_queue_t* p_queue = BFS_QUEUE_Create();
    //Put the source node to the queue
    BFS_QUEUE_Put(p_queue, startVertex);
    while(p_queue->front != NULL){
        //Get node from the queue
        BFS_node_t* minNode = BFS_QUEUE_Get(p_queue);
        int currentVertex = minNode->vertex;
        BFS_NODE_Free(minNode);
        //Check if the destination is found
        if(currentVertex == destination){
            break;
        }
        // Check if the node is visited
        if(p_graph->vertices[currentVertex].visited) {
            continue;
        }
        p_graph->vertices[currentVertex].visited = 1;
        GUI_displayPath(p_graph, grid);
        // Put all adjacent node to the queue
        edge_t* temp = p_graph->vertices[currentVertex].edge;
        while(temp != NULL){
            int nextVertex = temp->dest;
            if(!p_graph->vertices[nextVertex].visited){
                p_graph->vertices[nextVertex].preVertex = currentVertex;
                BFS_QUEUE_Put(p_queue, nextVertex);
            }
            temp = temp->next;
        }
    }
    BFS_QUEUE_Free(p_queue);
}