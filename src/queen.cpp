#include "queen.h"

Queen::Queen(ColorEnum color) : Figure(color) {
    sprite.setTextureRect(get_figure_rect_from_name_and_color("queen"));
}