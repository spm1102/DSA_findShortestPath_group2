#include"graph_locate.h"


Location* map_Create(int n) {
    Location* locations = (Location*)malloc(n * sizeof(Location));
    if (locations == NULL) {
        return NULL; 
    }
    return locations;
}

void Location_free(Location* locations){
    free(locations);
}