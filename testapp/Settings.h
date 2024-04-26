#pragma once

#include<vector>

using namespace std;

extern short width;
extern short height;
extern short fps;
extern int tile_width;
extern int tile_height;
extern vector<int> tiles_per_screen = {width / tile_width, height / tile_height};
