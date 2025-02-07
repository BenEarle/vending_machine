#ifndef I_O_HPP
#define I_O_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class I_O_States {    
   ____Received__Message, 
   ___Received___Message 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(I_O_States state) {
    switch (state) {
        case I_O_States::____Received__Message:
            return "____Received__Message" ;

        case I_O_States::___Received___Message:
            return "___Received___Message" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct I_O_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    I_O_States ___current_state___;
    //State Variables of the model

	I_O_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const I_O_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";

    return os;
}

class I_O: public Atomic<I_O_State> {
    protected:
        std::string model_id;
        
    public:
        Port<int> new_message;


        explicit I_O(const std::string& id): Atomic<I_O_State>(id, I_O_State()) { 
            new_message = addOutPort<int>("new_message");

            state.___current_state___ = I_O_States::____Received__Message; //Initial state is ____Received__Message
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<I_O_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            

        }
        using Atomic<I_O_State>::internalTransition;
        using Atomic<I_O_State>::externalTransition;
        using Atomic<I_O_State>::confluentTransition;
        using Atomic<I_O_State>::output;
        using Atomic<I_O_State>::timeAdvance;

        const I_O_State& getState() {
            return state;
        }
        void internalTransition(I_O_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                case I_O_States::____Received__Message:{


                    if(true)
                    {
                        state.___current_state___ = I_O_States::___Received___Message;
                        state.sigma = 10;  // For logging
                        return; // We switched states, return
                    }
                
                return;
                }
                case I_O_States::___Received___Message:{


                    if(true)
                    {
                        state.___current_state___ = I_O_States::____Received__Message;
                        state.sigma = 10;  // For logging
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
        
        void externalTransition(I_O_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            //flags for port received

            switch (state.___current_state___) {
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
             
        void output(const I_O_State& state) const override {
            switch (state.___current_state___) { 
                case I_O_States::____Received__Message:{

                    if(true)
                    {

                    }
                
                return;
                }     
                
                case I_O_States::___Received___Message:{

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

        [[nodiscard]] double timeAdvance(const I_O_State& state) const override {
                switch (state.___current_state___) { 

            case I_O_States::____Received__Message:
                // state.sigma = 10;
                return 10;

            case I_O_States::___Received___Message:
                // state.sigma = 10;
                return 10;

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //I_O_HPP