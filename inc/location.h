#ifndef LOCATION_H
#define LOCATION_H

#define NUM_LOCATIONS 10
#define GRID_SIZE 10

typedef struct {
    int symbol;
    double lat;
    double lon;
    char name[100];
} Location;

typedef struct {
    int x;
    int y;
    int symbol;
} position_t;

position_t* convertToGridCoordinate(double lat, double lon, position_t* pos);
int grid_2_symbol (int* grid_idx, int vertex);
#endif