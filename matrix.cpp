#include "matrix.h"
#include <cstdint>
#include <iostream>

matrix::matrix(std::uint8_t width,std::uint8_t height)
{
    m_components = std::vector<std::vector<double>>(height, std::vector<double>(width,0) );
}
matrix::matrix(std::vector<std::vector<double>> vec) { m_components = vec; }

std::uint8_t matrix::getWidth()  { std::size(m_components[0]); }
std::uint8_t matrix::getHeight() { std::size(m_components);    }

void matrix::print()
{
    for(std::uint8_t row {0}; row <= getHeight(); ++row) {
        for(std::uint8_t column {0}; column <= getWidth(); ++column) {
            std::cout << m_components[row][column] << ' ';
        }
        if(row < getHeight() - 1) {std::cout << '\n'}
    }
}




