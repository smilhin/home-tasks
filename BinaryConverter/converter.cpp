#include <iostream>
#include <string>

std::string GetBin(int x)
{
    int* ptr1 = &x;                             // an integer pointer to a variable x, 4 bytes long
    char* ptr2 = (char*)ptr1;                   // a char pointer to a variable x, 1 byte long
    int var = 0;                                // a temporary variable
    std::string binary = "";                     // string variable to store our value

    for (int i = 0; i < 4; i++)                  // first for loop to iterate through char blocks 1 byte each
    {
        char temp = *ptr2;                      // temporary variable to store a char block (8 bits)
        for (int j = 0; j < 8; j++)              // second for loop to iterate within a char block 
        {
            var = ((temp >> j) & 1);                /* temporary variable is being bitwise rightshifted by the value j and
                                                       then the last bit is compared to one; true gives 1, false 0*/
            
            binary += std::to_string(var);       // value of var is assigned to binary
        }
        ptr2++;                                  //char pointer is being incremented, so pointer jumps to the second char block (1 byte jump)
        
    }
    reverse(binary.begin(), binary.end());      //reverse function for binary
    return binary;                              
}

std::string GetHex(int x) {

    char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    char* ptr = (char*)&x;
    int var = 0;
    std::string hex = "";

    for (int i = 0; i < 4; i++) {
        char temp = *ptr;
        for (int j = 0; j < 2; j++) {
            var = (temp >> 4 * j) & 15;
            hex += digits[var];
        }
        ptr++;
    }

    reverse(hex.begin(), hex.end());
    return hex;

}