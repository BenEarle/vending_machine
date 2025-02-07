#ifndef Waypoint_Follow_HPP
#define Waypoint_Follow_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 


             
//enum for representing the states
enum class Waypoint_Follow_States {    
   ___Waypoints___Complete 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(Waypoint_Follow_States state) {
    switch (state) {
        case Waypoint_Follow_States::___Waypoints___Complete:
            return "___Waypoints___Complete" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct Waypoint_Follow_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    Waypoint_Follow_States ___current_state___;
    //State Variables of the model

	Waypoint_Follow_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const Waypoint_Follow_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";

    return os;
}

class Waypoint_Follow: public Atomic<Waypoint_Follow_State> {
    protected:
        std::string model_id;
        
    public:
        Port<int> waypoint;


        explicit Waypoint_Follow(const std::string& id): Atomic<Waypoint_Follow_State>(id, Waypoint_Follow_State()) { 
            waypoint = addInPort<int>("waypoint");

            state.___current_state___ = Waypoint_Follow_States::___Waypoints___Complete; //Initial state is ___Waypoints___Complete
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<Waypoint_Follow_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            

        }
        using Atomic<Waypoint_Follow_State>::internalTransition;
        using Atomic<Waypoint_Follow_State>::externalTransition;
        using Atomic<Waypoint_Follow_State>::confluentTransition;
        using Atomic<Waypoint_Follow_State>::output;
        using Atomic<Waypoint_Follow_State>::timeAdvance;

        const Waypoint_Follow_State& getState() {
            return state;
        }
        void internalTransition(Waypoint_Follow_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
        
        void externalTransition(Waypoint_Follow_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) waypoint->size();
            //flags for port received
            bool ___r_waypoint = !waypoint->empty();

            switch (state.___current_state___) {
                default:
                    break;
            }
            // write_to_shared_mem(state);
            return;
        }
             
        void output(const Waypoint_Follow_State& state) const override {
            switch (state.___current_state___) { 
                default:
                    break;
                
            }
            return;
        }

        [[nodiscard]] double timeAdvance(const Waypoint_Follow_State& state) const override {
                switch (state.___current_state___) { 

            case Waypoint_Follow_States::___Waypoints___Complete:
                // state.sigma = std::numeric_limits<double>::infinity();
                return std::numeric_limits<double>::infinity();

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //Waypoint_Follow_HPP