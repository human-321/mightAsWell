#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstdint>
#include <iostream>

class matrix
{
    private:
        std::vector<std::vector<double>> m_components;

        // the entire point of this is to make it easier to edit components as {1,2} is easier than 1,2 params
        // a list of ents is way more managable than 2 list of uint8's
        struct ent // entry for short
        {
            std::uint8_t row;
            std::uint8_t column;
        };
    
    public:
        

        matrix(std::uint8_t width,std::uint8_t height); // define a matrix of width columns and height rows full of zeros
        matrix(std::vector<std::vector<double>> vec); // define matrix with a matrix duh

        std::uint8_t getWidth()  const; // this is also the rank of the matrix
        std::uint8_t getHeight() const;

        // sets the component value at spot also returns reference to the object so you can chain
        // for example mat.setPart(sdklf).setPart(different sdklf) or mat.setComponent(1,1,.5).setComponent(2,2,3);
        matrix& setComponent(std::uint8_t row,std::uint8_t column, double value); 
        matrix& setComponent(ent entry, double value); // this is so we can do mat.setComponent({0,0},1) much clearer
        matrix& setComponents(std::vector<ent> entrys,double value); // this allows us to do mat.setComponents({ {1,0},{0,1}, ...more stuff... }, 2) very nice CTAP!!!

        void print() const; // simple bare bones display for testing

        friend matrix operator*(matrix& mat,double scalar); // we use a double instead of a double ref to make implicit conversions happen
        matrix operator*=(double scalar) {return (*this) * scalar;}
        matrix operator+() {return *this;} // +mat
        matrix operator-() {return (*this) * -1;} // -mat

};

matrix identityMatrix(int size);


#endif
