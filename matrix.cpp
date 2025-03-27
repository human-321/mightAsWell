#include "matrix.h"
#include <cstdint>
#include <iostream>

matrix::matrix(std::uint8_t width,std::uint8_t height)
{
    m_components = std::vector<std::vector<double>>(height, std::vector<double>(width,0) );
}
matrix::matrix(std::vector<std::vector<double>> vec) { m_components = vec; }

std::uint8_t matrix::getWidth()  const { return (m_components[0]).size(); }
std::uint8_t matrix::getHeight() const { return (m_components   ).size(); }

matrix& matrix::setComponent(std::uint8_t row,std::uint8_t column, double value) 
{
    m_components[row][column] = value;
    return *this;
}

void matrix::print() const
{
    for(std::uint8_t row {0}; row < getHeight(); ++row) {
        for(std::uint8_t column {0}; column < getWidth(); ++column) {
            std::cout << m_components[row][column] << ", ";
        }
        if(row < getHeight() - 1) {std::cout << '\n';}
    }
}



std::vector<double&> matrix::getComponentsReferences() const
{
    std::vector<double&> output {};

    for(std::uint8_t row {0}; row < getHeight(); ++row) {
        for(std::uint8_t column {0}; column < getWidth(); ++column) {
            output.push_back(m_components[row][column]);
        }
    }
    
    return output;
    
}

matrix operator*(matrix mat,double scalar)
{
    std::vector<double&> refs {mat.getComponentsReferences()};

    for(std::uint8_t i {0};i < refs.size();++i) {
        refs[i] *= scalar;
    }
    return mat;
}

matrix operator*(double scalar,matrix mat) {return mat * scalar;}






