#include "pattern.h"
#include "irregularity.h"

void Pattern::draw(Irregularity irr) const {
    auto step_x = (double)size_x / columns_num;
    auto step_y = (double)size_y / row_num;
    for (int cur_x = step_x; cur_x < size_x; cur_x += step_x) {
        for (int cur_y = step_y; cur_y < size_y; cur_y += step_y) {
            irr.draw(cur_x, cur_y);
        }
    }
}
