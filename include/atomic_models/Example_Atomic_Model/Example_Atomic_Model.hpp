#ifndef Example_Atomic_Model_HPP
#define Example_Atomic_Model_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class Example_Atomic_Model_States {    
   Idle, 
   Do_Something 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(Example_Atomic_Model_States state) {
    switch (state) {
        case Example_Atomic_Model_States::Idle:
            return "Idle" ;

        case Example_Atomic_Model_States::Do_Something:
            return "Do_Something" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct Example_Atomic_Model_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    Example_Atomic_Model_States ___current_state___;
    //State Variables of the model
    mutable bool received_input;
    mutable int received_data;

	Example_Atomic_Model_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const Example_Atomic_Model_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";
    os << "[-|~:received_input:~|-]" << x.received_input << "[-|~:received_input:~|-]";
    os << "[-|~:received_data:~|-]" << x.received_data << "[-|~:received_data:~|-]";

    return os;
}

class Example_Atomic_Model: public Atomic<Example_Atomic_Model_State> {
    protected:
        std::string model_id;
        
    public:
        Port<int> Input1;


        explicit Example_Atomic_Model(const std::string& id): Atomic<Example_Atomic_Model_State>(id, Example_Atomic_Model_State()) { 
            Input1 = addInPort<int>("Input1");

            state.___current_state___ = Example_Atomic_Model_States::Idle; //Initial state is Idle
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<Example_Atomic_Model_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            
            state.received_input = false;
            state.received_data = -1;
        }
        using Atomic<Example_Atomic_Model_State>::internalTransition;
        using Atomic<Example_Atomic_Model_State>::externalTransition;
        using Atomic<Example_Atomic_Model_State>::confluentTransition;
        using Atomic<Example_Atomic_Model_State>::output;
        using Atomic<Example_Atomic_Model_State>::timeAdvance;

        const Example_Atomic_Model_State& getState() {
            return state;
        }
        void internalTransition(Example_Atomic_Model_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                case Example_Atomic_Model_States::Do_Something:{


                    if(true)
                    {
                        state.___current_state___ = Example_Atomic_Model_States::Idle;
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
        
        void externalTransition(Example_Atomic_Model_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) Input1->size();
            //flags for port received
            bool ___r_Input1 = !Input1->empty();

            switch (state.___current_state___) {
                case Example_Atomic_Model_States::Idle:{





                    if(true)
                    {
                        state.___current_state___ = Example_Atomic_Model_States::Do_Something;
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
             
        void output(const Example_Atomic_Model_State& state) const override {
            switch (state.___current_state___) { 
                case Example_Atomic_Model_States::Do_Something:{

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

        [[nodiscard]] double timeAdvance(const Example_Atomic_Model_State& state) const override {
                switch (state.___current_state___) { 

            case Example_Atomic_Model_States::Idle:
                // state.sigma = std::numeric_limits<double>::infinity();
                return std::numeric_limits<double>::infinity();

            case Example_Atomic_Model_States::Do_Something:
                // state.sigma = 0;
                return 0;

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //Example_Atomic_Model_HPP