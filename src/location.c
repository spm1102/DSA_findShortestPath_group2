#include"location.h"



position_t* convertToGridCoordinate(double lat, double lon, position_t* pos) {

    double lat_min = 20.965414574646058;  
    double lat_max = 21.037027459347335;  
    double lon_min = 105.83062874982583; 
    double lon_max = 105.86784964740552; 
    
    pos->y = GRID_SIZE - 1 - (int)(GRID_SIZE * (lat - lat_min) / (lat_max - lat_min));
    pos->x = (int)(GRID_SIZE * (lon - lon_min) / (lon_max - lon_min));
    
    if(pos->y >= GRID_SIZE) pos->y = GRID_SIZE - 1;
    if(pos->x >= GRID_SIZE) pos->x = GRID_SIZE - 1;
    if(pos->y < 0) pos->y = 0;
    if(pos->x < 0) pos->x = 0;

    return pos;
}

    
int grid_2_symbol (int* grid_idx, int vertex) {
    for (int i=0; i<10; i++) {
        if (vertex == grid_idx[i]) return i;
    }
}