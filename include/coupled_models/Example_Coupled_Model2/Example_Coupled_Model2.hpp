#ifndef Example_Coupled_Model2_HPP
#define Example_Coupled_Model2_HPP

#include <cadmium/modeling/devs/coupled.hpp>

#include <iostream>
// C++ Standard Library Headers
#include <limits>
#include <string>

using namespace cadmium;

// ------ Your includes list ------- 

 //Includes for submodels
#include "atomic_models/Example_Atomic_Model/Example_Atomic_Model.hpp"



/**
* @class Example_Coupled_Model2
* @brief This model used to organize the environment of the Example_Coupled_Model2 DEVS model.
*/
class Example_Coupled_Model2 : public Coupled {
    protected:
        std::string model_id;
	public:
        Port<int> Input1;

		/**
		* Constructor function for the model.
		* @param id ID of the model.
		*/
		Example_Coupled_Model2(const std::string& id) : Coupled(id) {
            Input1 = addInPort<int>("Input1");

            model_id = id;
        
 
            auto Example_Atomic_Model_1086124645 = addComponent<Example_Atomic_Model>(model_id + "_1" );
            //EICs
            //EOCs
            //ICs

		}

};

#endif //Example_Coupled_Model2_HPP








