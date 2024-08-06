#include <iostream>
#include <geos/geom/Coordinate.h>

int main()
{
    geos::geom::Coordinate c{0,0};

    std::cout<<c<<std::endl;

    std::cout<<"OK"<<std::endl;

}
