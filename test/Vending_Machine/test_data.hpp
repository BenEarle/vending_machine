
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
    names[1] = "two_inserts";
    names[2] = "user_gets_change";
    names[3] = "one_insert";
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
    i_beverage_selection_1.push_back(std::make_tuple(1, item_selection_t((12, 2))));
    i_beverage_selection_1.push_back(std::make_tuple(10, item_selection_t(1)));
    tc1["i_beverage_selection"] = i_beverage_selection_1;
    std::vector<std::tuple<double, Variant_Goblin>> i_money_1; 
    i_money_1.push_back(std::make_tuple(5, float(1)));
    tc1["i_money"] = i_money_1;

    //Test Case: 2 Input Data ---------------------------------------------------------
    std::map<std::string, std::vector<std::tuple<double, Variant_Goblin>>> tc2;
    std::vector<std::tuple<double, Variant_Goblin>> i_beverage_selection_2; 
    i_beverage_selection_2.push_back(std::make_tuple(1, item_selection_t(12, 2.50)));
    i_beverage_selection_2.push_back(std::make_tuple(12, item_selection_t(1)));
    tc2["i_beverage_selection"] = i_beverage_selection_2;
    std::vector<std::tuple<double, Variant_Goblin>> i_money_2; 
    i_money_2.push_back(std::make_tuple(10, float(2)));
    tc2["i_money"] = i_money_2;

    //Test Case: 3 Input Data ---------------------------------------------------------
    std::map<std::string, std::vector<std::tuple<double, Variant_Goblin>>> tc3;
    std::vector<std::tuple<double, Variant_Goblin>> i_beverage_selection_3; 
    i_beverage_selection_3.push_back(std::make_tuple(1, item_selection_t(30, 1)));
    tc3["i_beverage_selection"] = i_beverage_selection_3;
    std::vector<std::tuple<double, Variant_Goblin>> i_money_3; 
    i_money_3.push_back(std::make_tuple(5, float(1)));
    tc3["i_money"] = i_money_3;

    std::map<int, std::map<std::string, std::vector<std::tuple<double, Variant_Goblin>>>> test_cases;
    test_cases[1] = tc1;
    test_cases[2] = tc2;
    test_cases[3] = tc3;
    return test_cases;
}

    //---------------------------------------------------------
    //Expected Outputs   ---------------------------------------------------------
    //---------------------------------------------------------
std::map<int, std::map<std::string, std::vector<std::tuple<int, Variant_Goblin>>>> get_comparator_data()
{

    //Test Case: 1 Expected Outputs ---------------------------------------------------------
    std::map<std::string, std::vector<std::tuple<int, Variant_Goblin>>> eo1;
    std::vector<std::tuple<int, Variant_Goblin>> o_change_1_eo; 
    o_change_1_eo.push_back(std::make_tuple(1, float(0)));
    o_change_1_eo.push_back(std::make_tuple(2, float(12)));
    eo1["o_change"] = o_change_1_eo;

    //Test Case: 2 Expected Outputs ---------------------------------------------------------
    std::map<std::string, std::vector<std::tuple<int, Variant_Goblin>>> eo2;
    std::vector<std::tuple<int, Variant_Goblin>> o_change_2_eo; 
    o_change_2_eo.push_back(std::make_tuple(1, float(0.50)));
    o_change_2_eo.push_back(std::make_tuple(2, float(12)));
    eo2["o_change"] = o_change_2_eo;

    //Test Case: 3 Expected Outputs ---------------------------------------------------------
    std::map<std::string, std::vector<std::tuple<int, Variant_Goblin>>> eo3;
    std::vector<std::tuple<int, Variant_Goblin>> o_change_3_eo; 
    o_change_3_eo.push_back(std::make_tuple(1, float(0)));
    o_change_3_eo.push_back(std::make_tuple(2, float(30)));
    eo3["o_change"] = o_change_3_eo;

    std::map<int, std::map<std::string, std::vector<std::tuple<int, Variant_Goblin>>>> comparator_data;
    comparator_data[1] = eo1;
    comparator_data[2] = eo2;
    comparator_data[3] = eo3;
    return comparator_data;
}

    //---------------------------------------------------------
    //Expected State Transitions   ---------------------------------------------------------
    //---------------------------------------------------------
std::map<int, std::map<std::string, std::vector<std::string>>> get_path_data()
{

    //Test Case: 1 State Transitions ---------------------------------------------------------
    std::vector<std::string> Vending_Machine_st_1 = {"____Wait_For___Selection", "_____Collect____Currency", "Check_Amount", "_____Collect____Currency", "Check_Amount", "Output_Change", "____Dispense___Beverage", "____Wait_For___Selection"};
    std::map<std::string, std::vector<std::string>> test_paths_tc1;
    test_paths_tc1["Vending_Machine"] = Vending_Machine_st_1;

    //Test Case: 2 State Transitions ---------------------------------------------------------
    std::vector<std::string> Vending_Machine_st_2 = {"____Wait_For___Selection", "_____Collect____Currency", "Check_Amount", "_____Collect____Currency", "Check_Amount", "Output_Change", "____Dispense___Beverage", "____Wait_For___Selection"};
    std::map<std::string, std::vector<std::string>> test_paths_tc2;
    test_paths_tc2["Vending_Machine"] = Vending_Machine_st_2;

    //Test Case: 3 State Transitions ---------------------------------------------------------
    std::vector<std::string> Vending_Machine_st_3 = {"____Wait_For___Selection", "_____Collect____Currency", "Check_Amount", "Output_Change", "____Dispense___Beverage", "____Wait_For___Selection"};
    std::map<std::string, std::vector<std::string>> test_paths_tc3;
    test_paths_tc3["Vending_Machine"] = Vending_Machine_st_3;

    std::map<int, std::map<std::string, std::vector<std::string>>> path_data;
    path_data[1] = test_paths_tc1;
    path_data[2] = test_paths_tc2;
    path_data[3] = test_paths_tc3;
    return path_data;
}

    //---------------------------------------------------------
    //Constructor Args   ---------------------------------------------------------
    //---------------------------------------------------------
std::map<int, std::map<int, Variant_Goblin>> get_constructor_data()
{

    //Test Case: 1 Constructor Args ---------------------------------------------------------
    std::map<int, Variant_Goblin> Vending_Machine_ca_1;

    //Test Case: 2 Constructor Args ---------------------------------------------------------
    std::map<int, Variant_Goblin> Vending_Machine_ca_2;

    //Test Case: 3 Constructor Args ---------------------------------------------------------
    std::map<int, Variant_Goblin> Vending_Machine_ca_3;
    std::map<int,  std::map<int, Variant_Goblin>> con_args_data;
    con_args_data[1] = Vending_Machine_ca_1;
    con_args_data[2] = Vending_Machine_ca_2;
    con_args_data[3] = Vending_Machine_ca_3;
    return con_args_data;
}
int get_test_set_size()
{
    return 3;
}
#endif;
