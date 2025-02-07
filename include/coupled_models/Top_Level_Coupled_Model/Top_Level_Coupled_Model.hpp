#ifndef Top_Level_Coupled_Model_HPP
#define Top_Level_Coupled_Model_HPP

#include <cadmium/modeling/devs/coupled.hpp>

#include <iostream>
// C++ Standard Library Headers
#include <limits>
#include <string>

using namespace cadmium;

// ------ Your includes list ------- 

 //Includes for submodels



/**
* @class Top_Level_Coupled_Model
* @brief This model used to organize the environment of the Top_Level_Coupled_Model DEVS model.
*/
class Top_Level_Coupled_Model : public Coupled {
    protected:
        std::string model_id;
	public:

		/**
		* Constructor function for the model.
		* @param id ID of the model.
		*/
		Top_Level_Coupled_Model(const std::string& id) : Coupled(id) {

            model_id = id;
        
 
            //EICs
            //EOCs
            //ICs

		}

};

#endif //Top_Level_Coupled_Model_HPP








