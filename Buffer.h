#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
#include <iostream>
#include <cstdlib>

#include <limits>
void vider_buffer()
{
    std::cin.clear();
    std::cin.seekg(0, std::ios::end);

    if(!std::cin.fail())
    {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a d�j� un �tat valide donc inutile de faire appel � clear()
    }

    else
    {
        std::cin.clear(); // Le flux est dasn un �tat invalide donc on le remet en �tat valide
    }
}



#endif // BUFFER_H_INCLUDED
