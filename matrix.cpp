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
matrix& matrix::setComponent(ent entry, double value)
{
    m_components[entry.row][entry.column] = value;
    return *this;
}
matrix& matrix::setComponents(std::vector<ent> entrys,double value)
{
    for(ent entry : entrys) {
        setComponent(entry,value);
    }
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


matrix operator*(matrix& mat,double scalar)
{
    for(std::uint8_t row {0}; row < mat.getHeight(); ++row) {
        for(std::uint8_t column {0}; column < mat.getWidth(); ++column) {
            mat.m_components[row][column] *= scalar;
        }
    }
    matrix temp {mat};
    return temp; // to make the errors shut up
}

matrix operator*(double scalar,matrix& mat) {return mat * scalar;}





//this is non matrix memeber functions nor overloads

matrix identityMatrix(int size)
{
    matrix mat(size,size);
    int i {0};
    while (i < size)
    {
        mat.setComponent(i,i,1);
        ++i;
    }
    return mat;
}







