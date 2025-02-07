#ifndef Example_Atomic_Model2_HPP
#define Example_Atomic_Model2_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class Example_Atomic_Model2_States {    
   IDLE, 
   DoSomething 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(Example_Atomic_Model2_States state) {
    switch (state) {
        case Example_Atomic_Model2_States::IDLE:
            return "IDLE" ;

        case Example_Atomic_Model2_States::DoSomething:
            return "DoSomething" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct Example_Atomic_Model2_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    Example_Atomic_Model2_States ___current_state___;
    //State Variables of the model

	Example_Atomic_Model2_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const Example_Atomic_Model2_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";

    return os;
}

class Example_Atomic_Model2: public Atomic<Example_Atomic_Model2_State> {
    protected:
        std::string model_id;
        
    public:
        Port<int> Input1;
        Port<int> Output1;
        Port<float> Output2;


        explicit Example_Atomic_Model2(const std::string& id): Atomic<Example_Atomic_Model2_State>(id, Example_Atomic_Model2_State()) { 
            Input1 = addInPort<int>("Input1");
            Output1 = addOutPort<int>("Output1");
            Output2 = addOutPort<float>("Output2");

            state.___current_state___ = Example_Atomic_Model2_States::IDLE; //Initial state is IDLE
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<Example_Atomic_Model2_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            

        }
        using Atomic<Example_Atomic_Model2_State>::internalTransition;
        using Atomic<Example_Atomic_Model2_State>::externalTransition;
        using Atomic<Example_Atomic_Model2_State>::confluentTransition;
        using Atomic<Example_Atomic_Model2_State>::output;
        using Atomic<Example_Atomic_Model2_State>::timeAdvance;

        const Example_Atomic_Model2_State& getState() {
            return state;
        }
        void internalTransition(Example_Atomic_Model2_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
        
        void externalTransition(Example_Atomic_Model2_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) Input1->size();
            //flags for port received
            bool ___r_Input1 = !Input1->empty();

            switch (state.___current_state___) {
                case Example_Atomic_Model2_States::IDLE:{





                    if(true)
                    {
                        state.___current_state___ = Example_Atomic_Model2_States::DoSomething;
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
             
        void output(const Example_Atomic_Model2_State& state) const override {
            switch (state.___current_state___) { 
                default:
                    break;
                
            }
            return;
        }

        [[nodiscard]] double timeAdvance(const Example_Atomic_Model2_State& state) const override {
                switch (state.___current_state___) { 

            case Example_Atomic_Model2_States::IDLE:
                // state.sigma = std::numeric_limits<double>::infinity();
                return std::numeric_limits<double>::infinity();

            case Example_Atomic_Model2_States::DoSomething:
                // state.sigma = 0;
                return 0;

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //Example_Atomic_Model2_HPP