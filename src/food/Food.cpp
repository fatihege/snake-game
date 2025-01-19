#include "Food.h"

#include "../utils/Utility.h"
#include "../utils/Config.h"

Food::Food() {
    refresh();
}

void Food::refresh() {
    position = {Utility::randomNumber(1, GRID_WIDTH), Utility::randomNumber(1, GRID_HEIGHT)};
    special = Utility::randomNumber(0, 5) == 1;
}

std::pair<int, int> Food::getPosition() const {
    return position;
}

bool Food::isSpecial() const {
    return special;
}
