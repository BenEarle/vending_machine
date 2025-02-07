#ifndef Vending_Machine_Activity_HPP
#define Vending_Machine_Activity_HPP

#include <cadmium/modeling/devs/coupled.hpp>

#include <iostream>
// C++ Standard Library Headers
#include <limits>
#include <string>

using namespace cadmium;

// ------ Your includes list ------- 

 //Includes for submodels
#include "atomic_models/Vending_Machine/Vending_Machine.hpp"
#include "atomic_models/Customers/Customers.hpp"



/**
* @class Vending_Machine_Activity
* @brief This model used to organize the environment of the Vending_Machine_Activity DEVS model.
*/
class Vending_Machine_Activity : public Coupled {
    protected:
        std::string model_id;
	public:
        Port<bool> i_start_customer_activity;
        Port<int> o_logged_dispense_id;

		/**
		* Constructor function for the model.
		* @param id ID of the model.
		*/
		Vending_Machine_Activity(const std::string& id) : Coupled(id) {
            i_start_customer_activity = addInPort<bool>("i_start_customer_activity");
            o_logged_dispense_id = addOutPort<int>("o_logged_dispense_id");

            model_id = id;
        
 
            auto Vending_Machine_1495258907 = addComponent<Vending_Machine>(model_id + "_1" );
            auto Customers_559098369 = addComponent<Customers>(model_id + "_2" );
            //EICs
            addCoupling(i_start_customer_activity, Customers_559098369->i_start_customer_activity);
            //EOCs
            addCoupling(Vending_Machine_1495258907->o_dispense_id, o_logged_dispense_id);
            //ICs
            addCoupling(Customers_559098369->o_selected_beverage, Vending_Machine_1495258907->i_beverage_selection);
            addCoupling(Vending_Machine_1495258907->o_change, Customers_559098369->i_change_owed);
            addCoupling(Vending_Machine_1495258907->o_dispense_id, Customers_559098369->i_dispensed_beverage);
            addCoupling(Customers_559098369->o_money, Vending_Machine_1495258907->i_money);

		}

};

#endif //Vending_Machine_Activity_HPP








