#include <iostream>
#include <string>
#include "converter.h"


int main()
{
    
    std::cout << GetBin(15) << std::endl;
    std::cout << GetBin(256) << std::endl;

    std::cout << GetHex(15) << std::endl;
    std::cout << GetHex(256) << std::endl;

}


