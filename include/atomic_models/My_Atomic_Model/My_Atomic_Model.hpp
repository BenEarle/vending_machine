#ifndef My_Atomic_Model_HPP
#define My_Atomic_Model_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class My_Atomic_Model_States {    
   First_State, 
   Second_State, 
   Third_State 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(My_Atomic_Model_States state) {
    switch (state) {
        case My_Atomic_Model_States::First_State:
            return "First_State" ;

        case My_Atomic_Model_States::Second_State:
            return "Second_State" ;

        case My_Atomic_Model_States::Third_State:
            return "Third_State" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct My_Atomic_Model_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    My_Atomic_Model_States ___current_state___;
    //State Variables of the model

	My_Atomic_Model_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const My_Atomic_Model_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";

    return os;
}

class My_Atomic_Model: public Atomic<My_Atomic_Model_State> {
    protected:
        std::string model_id;
        
    public:
        Port<int> AtomicInput1;
        Port<float> AtomicInput2;
        Port<int> AtomicOutput;


        explicit My_Atomic_Model(const std::string& id, float modelArg): Atomic<My_Atomic_Model_State>(id, My_Atomic_Model_State()) { 
            AtomicInput1 = addInPort<int>("AtomicInput1");
            AtomicInput2 = addInPort<float>("AtomicInput2");
            AtomicOutput = addOutPort<int>("AtomicOutput");

            state.___current_state___ = My_Atomic_Model_States::First_State; //Initial state is First_State
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<My_Atomic_Model_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            

        }
        using Atomic<My_Atomic_Model_State>::internalTransition;
        using Atomic<My_Atomic_Model_State>::externalTransition;
        using Atomic<My_Atomic_Model_State>::confluentTransition;
        using Atomic<My_Atomic_Model_State>::output;
        using Atomic<My_Atomic_Model_State>::timeAdvance;

        const My_Atomic_Model_State& getState() {
            return state;
        }
        void internalTransition(My_Atomic_Model_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
        
        void externalTransition(My_Atomic_Model_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) AtomicInput1->size();
            state.nInputs += (int) AtomicInput2->size();
            //flags for port received
            bool ___r_AtomicInput1 = !AtomicInput1->empty();
            bool ___r_AtomicInput2 = !AtomicInput2->empty();

            switch (state.___current_state___) {
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
             
        void output(const My_Atomic_Model_State& state) const override {
            switch (state.___current_state___) { 
                default:
                    break;
                
            }
            return;
        }

        [[nodiscard]] double timeAdvance(const My_Atomic_Model_State& state) const override {
                switch (state.___current_state___) { 

            case My_Atomic_Model_States::First_State:
                // state.sigma = 0;
                return 0;

            case My_Atomic_Model_States::Second_State:
                // state.sigma = 0;
                return 0;

            case My_Atomic_Model_States::Third_State:
                // state.sigma = 0;
                return 0;

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //My_Atomic_Model_HPP