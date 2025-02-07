#ifndef New_HPP
#define New_HPP

#include <cadmium/modeling/devs/coupled.hpp>

#include <iostream>
// C++ Standard Library Headers
#include <limits>
#include <string>

using namespace cadmium;

// ------ Your includes list ------- 

 //Includes for submodels
#include "coupled_models/My_Coupled_Model/My_Coupled_Model.hpp"
#include "atomic_models/My_Atomic_Model/My_Atomic_Model.hpp"



/**
* @class New
* @brief This model used to organize the environment of the New DEVS model.
*/
class New : public Coupled {
    protected:
        std::string model_id;
	public:

		/**
		* Constructor function for the model.
		* @param id ID of the model.
		*/
		New(const std::string& id) : Coupled(id) {

            model_id = id;
        
 
            auto My_Coupled_Model_1337660910 = addComponent<My_Coupled_Model>(model_id + "_1" , , );
            auto My_Atomic_Model_161171408 = addComponent<My_Atomic_Model>(model_id + "_2" , );
            //EICs
            //EOCs
            //ICs

		}

};

#endif //New_HPP








