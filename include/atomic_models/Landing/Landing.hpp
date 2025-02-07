#ifndef Landing_HPP
#define Landing_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class Landing_States {    
   ____Landing____Complete, 
   Landing 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(Landing_States state) {
    switch (state) {
        case Landing_States::____Landing____Complete:
            return "____Landing____Complete" ;

        case Landing_States::Landing:
            return "Landing" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct Landing_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    Landing_States ___current_state___;
    //State Variables of the model

	Landing_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const Landing_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";

    return os;
}

class Landing: public Atomic<Landing_State> {
    protected:
        std::string model_id;
        
    public:
        Port<int> landing_point;
        Port<int> abort_landing;
        Port<int> landing_complete;


        explicit Landing(const std::string& id): Atomic<Landing_State>(id, Landing_State()) { 
            landing_point = addInPort<int>("landing_point");
            abort_landing = addInPort<int>("abort_landing");
            landing_complete = addOutPort<int>("landing_complete");

            state.___current_state___ = Landing_States::Landing; //Initial state is Landing
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<Landing_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            

        }
        using Atomic<Landing_State>::internalTransition;
        using Atomic<Landing_State>::externalTransition;
        using Atomic<Landing_State>::confluentTransition;
        using Atomic<Landing_State>::output;
        using Atomic<Landing_State>::timeAdvance;

        const Landing_State& getState() {
            return state;
        }
        void internalTransition(Landing_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                case Landing_States::____Landing____Complete:{


                    if(true)
                    {
                        state.___current_state___ = Landing_States::Landing;
                        state.sigma = 10;  // For logging
                        return; // We switched states, return
                    }
                
                return;
                }
                case Landing_States::Landing:{


                    if(true)
                    {
                        state.___current_state___ = Landing_States::____Landing____Complete;
                        state.sigma = 0;  // For logging
                        return; // We switched states, return
                    }
                
                return;
                }
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
        
        void externalTransition(Landing_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) landing_point->size();
            state.nInputs += (int) abort_landing->size();
            //flags for port received
            bool ___r_landing_point = !landing_point->empty();
            bool ___r_abort_landing = !abort_landing->empty();

            switch (state.___current_state___) {
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
             
        void output(const Landing_State& state) const override {
            switch (state.___current_state___) { 
                case Landing_States::____Landing____Complete:{

                    if(true)
                    {

                    }
                
                return;
                }     
                
                case Landing_States::Landing:{

                    if(true)
                    {

                    }
                
                return;
                }     
                
                default:
                    break;
                
            }
            return;
        }

        [[nodiscard]] double timeAdvance(const Landing_State& state) const override {
                switch (state.___current_state___) { 

            case Landing_States::____Landing____Complete:
                // state.sigma = 0;
                return 0;

            case Landing_States::Landing:
                // state.sigma = 10;
                return 10;

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //Landing_HPP