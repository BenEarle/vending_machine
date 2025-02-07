#ifndef External_Messages_HPP
#define External_Messages_HPP

#include <cadmium/modeling/devs/coupled.hpp>

#include <iostream>
// C++ Standard Library Headers
#include <limits>
#include <string>

using namespace cadmium;

// ------ Your includes list ------- 

 //Includes for submodels
#include "atomic_models/I_O/I_O.hpp"



/**
* @class External_Messages
* @brief This model used to organize the environment of the External_Messages DEVS model.
*/
class External_Messages : public Coupled {
    protected:
        std::string model_id;
	public:
        Port<int> message;

		/**
		* Constructor function for the model.
		* @param id ID of the model.
		*/
		External_Messages(const std::string& id) : Coupled(id) {
            message = addOutPort<int>("message");

            model_id = id;
        
 
            auto I_O_3407629774 = addComponent<I_O>(model_id + "_1" );
            //EICs
            //EOCs
            addCoupling(I_O_3407629774->new_message, message);
            //ICs

		}

};

#endif //External_Messages_HPP








