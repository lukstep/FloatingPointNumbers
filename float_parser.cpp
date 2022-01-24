#include <bitset>
#include <cmath>
#include <iostream>

union float32_t
{
    float f;
    uint32_t bytes;
    struct
    {
        uint32_t mantissa : 23;
        uint32_t exponenta : 8; 
        uint32_t sign : 1;
    } bits; 
};


int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        std::cerr << "Invalid input!" << std::endl;
        return 1;
    }
    
    float32_t input;
    input.f = std::stof(std::string(argv[1]));

    std::cout << "Input: " << input.f << std::endl;
    std::cout << "\tBytes:\t\t0x" << std::hex << input.bytes << "  " << std::bitset<32>(input.bytes) << std::endl;
    if(input.bits.sign) 
    {
        std::cout << "\tSign\t\t-1" << std::endl; 
    }
    else
    {
        std::cout << "\tSign:\t\t+1" << std::endl;    
    }

    uint32_t exponenta_bits = input.bits.exponenta;

    std::cout << "\tExponenta:\t0x" << exponenta_bits << std::endl;
    std::cout << "\tMantissa:\t0x" << input.bits.mantissa << std::endl;
}


