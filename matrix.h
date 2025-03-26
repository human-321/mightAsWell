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
        matrix(int width,int height);
        matrix(std::vector<std::vector<double>> vec);

        std::uint8_t getWidth()  const;
        std::uint8_t getHeight() const;

        void print() const;
};


#endif
