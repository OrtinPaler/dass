#include "Director.hpp"

TransportElements *Director::createTE(Builder &builder) {
    builder.createTE();
    builder.buildPassenger();
    builder.buildDriver();
    builder.buildTransport();
    return builder.getResult();
}
