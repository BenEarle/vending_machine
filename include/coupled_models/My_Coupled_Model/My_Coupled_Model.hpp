#ifndef My_Coupled_Model_HPP
#define My_Coupled_Model_HPP

#include <cadmium/modeling/devs/coupled.hpp>

#include <iostream>
// C++ Standard Library Headers
#include <limits>
#include <string>

using namespace cadmium;

// ------ Your includes list ------- 

 //Includes for submodels



/**
* @class My_Coupled_Model
* @brief This model used to organize the environment of the My_Coupled_Model DEVS model.
*/
class My_Coupled_Model : public Coupled {
    protected:
        std::string model_id;
	public:
        Port<int> CoupledInput1;
        Port<float> CoupledInput2;

		/**
		* Constructor function for the model.
		* @param id ID of the model.
		*/
		My_Coupled_Model(const std::string& id, int modelArg1, float modelArg2) : Coupled(id) {
            CoupledInput1 = addInPort<int>("CoupledInput1");
            CoupledInput2 = addInPort<float>("CoupledInput2");

            model_id = id;
        
 
            //EICs
            //EOCs
            //ICs

		}

};

#endif //My_Coupled_Model_HPP








