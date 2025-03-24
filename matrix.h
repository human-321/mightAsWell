#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstdint>

class matrix
{
    private:
        std::vector<std::vector<double>> m_components;
    
    public:
        std::uint8_t getWidth();
        std::uint8_t getHeight();

        void print();
};


#endif