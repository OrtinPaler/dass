#ifndef Director_hpp
#define Director_hpp

#include "Builder.hpp"

class Director {
public:
    TransportElements *createTE(Builder &);
};

#endif /* Director_hpp */
