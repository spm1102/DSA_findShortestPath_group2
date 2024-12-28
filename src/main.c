#include"gui.h"

int main() {
    SetTargetFPS(60);
    Location* locations = map_Create(NUM_LOCATIONS);
    locations[0] = (Location){0, 21.006211796348794, 105.84313378943492, "BKHN"};
    locations[1] = (Location){1, 20.97219877068389, 105.85889857369466, "Ho Yen So"};
    locations[2] = (Location){2, 21.037027459347335, 105.8346345090695, "Lang Bac"};
    locations[3] = (Location){3, 20.980656370023265, 105.84199651092882, "Ben xe Giap Bat"};
    locations[4] = (Location){4, 21.024447507760456, 105.8576622560684, "Nha hat lon"};
    locations[5] = (Location){5, 21.01717187766406, 105.84439224284921, "Cong vien Thong nhat"};
    locations[6] = (Location){6, 21.003582324317634, 105.83062874982583, "Dai hoc Y Ha Noi"};
    locations[7] = (Location){7, 20.99452302551067, 105.86784964740552, "Times City"};
    locations[8] = (Location){8, 20.995071164280986, 105.85628263909797, "Goc De"};
    locations[9] = (Location){9, 20.965414574646058, 105.84228679384964, "Ben xe Nuoc Ngam"};

    cell_t** grid = GRID_Create(locations);

    GUI_INIT(grid);
    GRID_Free(grid);
    Location_free(locations);

    return 0;
}




