#ifndef Takeoff_HPP
#define Takeoff_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class Takeoff_States {    
   ____Takeoff____Complete 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(Takeoff_States state) {
    switch (state) {
        case Takeoff_States::____Takeoff____Complete:
            return "____Takeoff____Complete" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct Takeoff_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    Takeoff_States ___current_state___;
    //State Variables of the model

	Takeoff_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const Takeoff_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";

    return os;
}

class Takeoff: public Atomic<Takeoff_State> {
    protected:
        std::string model_id;
        
    public:
        Port<int> takeoff_point;
        Port<int> abort_takeoff;
        Port<int> takeoff_complete;
        Port<int> follow_mission;


        explicit Takeoff(const std::string& id): Atomic<Takeoff_State>(id, Takeoff_State()) { 
            takeoff_point = addInPort<int>("takeoff_point");
            abort_takeoff = addInPort<int>("abort_takeoff");
            takeoff_complete = addOutPort<int>("takeoff_complete");
            follow_mission = addOutPort<int>("follow_mission");

            state.___current_state___ = Takeoff_States::____Takeoff____Complete; //Initial state is ____Takeoff____Complete
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<Takeoff_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            

        }
        using Atomic<Takeoff_State>::internalTransition;
        using Atomic<Takeoff_State>::externalTransition;
        using Atomic<Takeoff_State>::confluentTransition;
        using Atomic<Takeoff_State>::output;
        using Atomic<Takeoff_State>::timeAdvance;

        const Takeoff_State& getState() {
            return state;
        }
        void internalTransition(Takeoff_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
        
        void externalTransition(Takeoff_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) takeoff_point->size();
            state.nInputs += (int) abort_takeoff->size();
            //flags for port received
            bool ___r_takeoff_point = !takeoff_point->empty();
            bool ___r_abort_takeoff = !abort_takeoff->empty();

            switch (state.___current_state___) {
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
             
        void output(const Takeoff_State& state) const override {
            switch (state.___current_state___) { 
                default:
                    break;
                
            }
            return;
        }

        [[nodiscard]] double timeAdvance(const Takeoff_State& state) const override {
                switch (state.___current_state___) { 

            case Takeoff_States::____Takeoff____Complete:
                // state.sigma = std::numeric_limits<double>::infinity();
                return std::numeric_limits<double>::infinity();

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //Takeoff_HPP