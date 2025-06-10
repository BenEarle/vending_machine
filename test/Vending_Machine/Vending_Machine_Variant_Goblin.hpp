
#ifndef VARIANT_GOBLIN_HPP
#define VARIANT_GOBLIN_HPP

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <variant>



#include "include/coupled_models/Vending_Machine/Vending_Machine.hpp" // included because it will already have included all the custom types

//This variant holds every type that the ports can output
using Variant_Goblin = std::variant<item_selection_t, float>;
#endif;