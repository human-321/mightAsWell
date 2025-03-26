#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstdint>
#include <iostream>

class matrix
{
    private:
        std::vector<std::vector<double>> m_components;
    
    public:
        matrix(std::uint8_t width,std::uint8_t height); // define a matrix of width columns and height rows full of zeros
        matrix(std::vector<std::vector<double>> vec); // define matrix with a matrix duh

        std::uint8_t getWidth()  const;
        std::uint8_t getHeight() const;

        // sets the component value at spot also returns reference to the object so you can chain
        // for example mat.setPart(sdklf).setPart(different sdklf) or mat.setComponent(1,1,.5).setComponent(2,2,3);
        matrix& setComponent(std::uint8_t row,std::uint8_t column, double value);

        void print() const; // simple bare bones display for testing
};


#endif
