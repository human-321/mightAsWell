#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cstdint>

class matrix
{
    private:
        std::vector<std::vector<double>> m_components;
    
    public:
        matrix(std::uint8_t width,std::uint8_t height);
        matrix(std::vector<std::vector<double>> vec);

        std::uint8_t getWidth();
        std::uint8_t getHeight();

        void print();
};


#endif
