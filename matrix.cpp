#include "matrix.h"
#include <cstdint>

std::uint8_t matrix::getWidth()  { std::size(m_components[0]); }
std::uint8_t matrix::getHeight() { std::size(m_components);    }

void matrix::print()
{
    for(std::uint8_t row {0}; row <= getHeight(); ++row) {
        for(std::uint8_t column {0}; column <= getHeight(); ++column) {
            
        }
    }
}




