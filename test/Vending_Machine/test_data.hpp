
#ifndef TEST_DATA_Vending_Machine
#define TEST_DATA_Vending_Machine
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <string>
#include <variant>


//seek the Variant Goblin to find your variants...
#include "Vending_Machine_Variant_Goblin.hpp"
std::map<int, std::string> get_test_names()
{
    std::map<int, std::string> names;
    names[1] = "Standard_Purchase";
    return names;
}
    //---------------------------------------------------------
    //Test Case Data   ---------------------------------------------------------
    //---------------------------------------------------------
std::map<int, std::map<std::string, std::vector<std::tuple<double, Variant_Goblin>>>> get_test_cases()
{

    //Test Case: 1 Input Data ---------------------------------------------------------
    std::map<std::string, std::vector<std::tuple<double, Variant_Goblin>>> tc1;
    std::vector<std::tuple<double, Variant_Goblin>> i_beverage_selection_1; 
    i_beverage_selection_1.push_back(std::make_tuple(5, item_selection_t({12, 2.50})));
    tc1["i_beverage_selection"] = i_beverage_selection_1;
    std::vector<std::tuple<double, Variant_Goblin>> i_money_1; 
    i_money_1.push_back(std::make_tuple(10, float(5)));
    tc1["i_money"] = i_money_1;

    std::map<int, std::map<std::string, std::vector<std::tuple<double, Variant_Goblin>>>> test_cases;
    test_cases[1] = tc1;
    return test_cases;
}

    //---------------------------------------------------------
    //Expected Outputs   ---------------------------------------------------------
    //---------------------------------------------------------
std::map<int, std::map<std::string, std::vector<std::tuple<int, Variant_Goblin>>>> get_comparator_data()
{

    //Test Case: 1 Expected Outputs ---------------------------------------------------------
    std::map<std::string, std::vector<std::tuple<int, Variant_Goblin>>> eo1;

    std::map<int, std::map<std::string, std::vector<std::tuple<int, Variant_Goblin>>>> comparator_data;
    comparator_data[1] = eo1;
    return comparator_data;
}

    //---------------------------------------------------------
    //Expected State Transitions   ---------------------------------------------------------
    //---------------------------------------------------------
std::map<int, std::map<std::string, std::vector<std::string>>> get_path_data()
{

    //Test Case: 1 State Transitions ---------------------------------------------------------
    std::vector<std::string> Vending_Machine_st_1 = {};
    std::map<std::string, std::vector<std::string>> test_paths_tc1;
    test_paths_tc1["Vending_Machine"] = Vending_Machine_st_1;

    std::map<int, std::map<std::string, std::vector<std::string>>> path_data;
    path_data[1] = test_paths_tc1;
    return path_data;
}

    //---------------------------------------------------------
    //Constructor Args   ---------------------------------------------------------
    //---------------------------------------------------------
std::map<int, std::map<int, Variant_Goblin>> get_constructor_data()
{

    //Test Case: 1 Constructor Args ---------------------------------------------------------
    std::map<int, Variant_Goblin> Vending_Machine_ca_1;
    std::map<int,  std::map<int, Variant_Goblin>> con_args_data;
    con_args_data[1] = Vending_Machine_ca_1;
    return con_args_data;
}
int get_test_set_size()
{
    return 1;
}
#endif;
