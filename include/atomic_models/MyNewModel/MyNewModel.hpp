#ifndef MyNewModel_HPP
#define MyNewModel_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class MyNewModel_States {    
   IDLE, 
   STATE 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(MyNewModel_States state) {
    switch (state) {
        case MyNewModel_States::IDLE:
            return "IDLE" ;

        case MyNewModel_States::STATE:
            return "STATE" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct MyNewModel_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    MyNewModel_States ___current_state___;
    //State Variables of the model

	MyNewModel_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const MyNewModel_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";

    return os;
}

class MyNewModel: public Atomic<MyNewModel_State> {
    protected:
        std::string model_id;
        
    public:
        Port<INT> APORT;


        explicit MyNewModel(const std::string& id): Atomic<MyNewModel_State>(id, MyNewModel_State()) { 
            APORT = addInPort<INT>("APORT");

            state.___current_state___ = MyNewModel_States::IDLE; //Initial state is IDLE
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<MyNewModel_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            

        }
        using Atomic<MyNewModel_State>::internalTransition;
        using Atomic<MyNewModel_State>::externalTransition;
        using Atomic<MyNewModel_State>::confluentTransition;
        using Atomic<MyNewModel_State>::output;
        using Atomic<MyNewModel_State>::timeAdvance;

        const MyNewModel_State& getState() {
            return state;
        }
        void internalTransition(MyNewModel_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;

            switch (state.___current_state___) { 
                case MyNewModel_States::IDLE:{


                    if(true)
                    {
                        state.___current_state___ = MyNewModel_States::STATE;
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
        
        void externalTransition(MyNewModel_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) APORT->size();
            //flags for port received
            bool ___r_APORT = !APORT->empty();




            if(true)
            {
                state.___current_state___ = MyNewModel_States::IDLE;
                state.sigma = 0;  // For logging
                // write_to_shared_mem(state);
                return;
            }

            switch (state.___current_state___) {
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
             
        void output(const MyNewModel_State& state) const override {

            switch (state.___current_state___) { 
                case MyNewModel_States::IDLE:{

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

        [[nodiscard]] double timeAdvance(const MyNewModel_State& state) const override {
                switch (state.___current_state___) { 

            case MyNewModel_States::IDLE:
                // state.sigma = 0;
                return 0;

            case MyNewModel_States::STATE:
                // state.sigma = std::numeric_limits<double>::infinity();
                return std::numeric_limits<double>::infinity();

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //MyNewModel_HPP