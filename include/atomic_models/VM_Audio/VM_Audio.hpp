#ifndef VM_Audio_HPP
#define VM_Audio_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class VM_Audio_States {    
   Speak, 
   ____Wait_For___Message 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(VM_Audio_States state) {
    switch (state) {
        case VM_Audio_States::Speak:
            return "Speak" ;

        case VM_Audio_States::____Wait_For___Message:
            return "____Wait_For___Message" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct VM_Audio_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    VM_Audio_States ___current_state___;
    //State Variables of the model
    mutable std::string message;

	VM_Audio_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const VM_Audio_State& x) {
    os << "[-|name|-]" << "VM_Audio" << "[-|name|-]";
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";
    os << "[-|~:message:~|-]" << x.message << "[-|~:message:~|-]";

    return os;
}

class VM_Audio: public Atomic<VM_Audio_State> {
    protected:
        std::string model_id;
        
    public:
        Port<std::string> i_message_to_speak;


        explicit VM_Audio(const std::string& id): Atomic<VM_Audio_State>(id, VM_Audio_State()) { 
            i_message_to_speak = addInPort<std::string>("i_message_to_speak");

            state.___current_state___ = VM_Audio_States::____Wait_For___Message; //Initial state is ____Wait_For___Message
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<VM_Audio_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            

        }
        using Atomic<VM_Audio_State>::internalTransition;
        using Atomic<VM_Audio_State>::externalTransition;
        using Atomic<VM_Audio_State>::confluentTransition;
        using Atomic<VM_Audio_State>::output;
        using Atomic<VM_Audio_State>::timeAdvance;

        const VM_Audio_State& getState() {
            return state;
        }
        void internalTransition(VM_Audio_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                case VM_Audio_States::Speak:{


                    if(true)
                    {
                        state.___current_state___ = VM_Audio_States::____Wait_For___Message;
                        state.sigma = std::numeric_limits<double>::infinity();  // For logging
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
        
        void externalTransition(VM_Audio_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) i_message_to_speak->size();
            //flags for port received
            bool ___r_i_message_to_speak = !i_message_to_speak->empty();

            switch (state.___current_state___) {
                case VM_Audio_States::____Wait_For___Message:{



                    if(___r_i_message_to_speak){
                        state.message = i_message_to_speak->getBag().back();
                    }



                    if(true)
                    {
                        state.___current_state___ = VM_Audio_States::Speak;
                        state.sigma = 0; // For logging
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
             
        void output(const VM_Audio_State& state) const override {
            switch (state.___current_state___) { 
                case VM_Audio_States::Speak:{
                    std::cout << state.message << std::endl;
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

        [[nodiscard]] double timeAdvance(const VM_Audio_State& state) const override {
                switch (state.___current_state___) { 

            case VM_Audio_States::Speak:
                // state.sigma = 0;
                return 0;

            case VM_Audio_States::____Wait_For___Message:
                // state.sigma = std::numeric_limits<double>::infinity();
                return std::numeric_limits<double>::infinity();

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //VM_Audio_HPP