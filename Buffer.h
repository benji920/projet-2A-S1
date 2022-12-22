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
        std::cin.ignore(std::numeric_limits<std::streamsize>::max()); // Le flux a déjà un état valide donc inutile de faire appel à clear()
    }

    else
    {
        std::cin.clear(); // Le flux est dasn un état invalide donc on le remet en état valide
    }
}



#endif // BUFFER_H_INCLUDED
