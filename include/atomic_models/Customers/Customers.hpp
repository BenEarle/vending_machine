#ifndef Customers_HPP
#define Customers_HPP
#include <cadmium/modeling/devs/atomic.hpp>
// C++ Standard Library Headers
#include <limits>
#include <string>
#include <iostream>

using namespace cadmium;

// ------ Your includes list ------- 
// Include headers
#include "item_selection_t.hpp"

             
//enum for representing the states
enum class Customers_States {    
   Wait_For_Bev, 
   ____Wait_For___Customer, 
   Insert_Money 

}; //end of the enum


// Function to convert the enum for states to an enum to the corresponding string
std::string enumToString(Customers_States state) {
    switch (state) {
        case Customers_States::Wait_For_Bev:
            return "Wait_For_Bev" ;

        case Customers_States::____Wait_For___Customer:
            return "____Wait_For___Customer" ;

        case Customers_States::Insert_Money:
            return "Insert_Money" ;

        default:
            return "invalid";
    }
}


//struct that contains the state variables of the model (as well as some other stuff)
struct Customers_State {
	int nInternals, nExternals, nInputs;
	mutable double clock, sigma;
    Customers_States ___current_state___;
    //State Variables of the model
    mutable item_selection_t beverage_selected;
    mutable float amount_output;
    mutable float total_input;
    mutable bool received_bev;

	Customers_State(): nInternals(), nExternals(), nInputs(), clock(), sigma(std::numeric_limits<double>::infinity()), ___current_state___() {}
};
    
std::ostream &operator << (std::ostream& os, const Customers_State& x) {
    os << "[-|state|-]" << enumToString(x.___current_state___) << "[-|state|-]";
    os << "[-|sigma|-]" << x.sigma << "[-|sigma|-]";
    os << "[-|~:beverage_selected:~|-]" << x.beverage_selected << "[-|~:beverage_selected:~|-]";
    os << "[-|~:amount_output:~|-]" << x.amount_output << "[-|~:amount_output:~|-]";
    os << "[-|~:total_input:~|-]" << x.total_input << "[-|~:total_input:~|-]";
    os << "[-|~:received_bev:~|-]" << x.received_bev << "[-|~:received_bev:~|-]";

    return os;
}

class Customers: public Atomic<Customers_State> {
    protected:
        std::string model_id;
        
    public:
        Port<bool> i_start_customer_activity;
        Port<float> i_change_owed;
        Port<int> i_dispensed_beverage;
        Port<item_selection_t> o_selected_beverage;
        Port<float> o_money;


        explicit Customers(const std::string& id): Atomic<Customers_State>(id, Customers_State()) { 
            i_start_customer_activity = addInPort<bool>("i_start_customer_activity");
            i_change_owed = addInPort<float>("i_change_owed");
            i_dispensed_beverage = addInPort<int>("i_dispensed_beverage");
            o_selected_beverage = addOutPort<item_selection_t>("o_selected_beverage");
            o_money = addOutPort<float>("o_money");

            state.___current_state___ = Customers_States::____Wait_For___Customer; //Initial state is ____Wait_For___Customer
            state.nExternals = 0;
            state.nInternals = 0;
            state.nInputs = 0;
            model_id = id;
            
            // model = std::make_shared<GenericSharedMemoryModel<Customers_shared_memory_struct>>(model_id);
            // Connect the shared memory model.
            // if(!model->connect()) {
            //     std::cout << "[ERROR]: Could not connect the " <<model_id<< " shared memory model"<< std::endl;
            // }
            
            state.beverage_selected.price = 2.00;
            state.beverage_selected.item_id = 12;
            state.amount_output = 1.00;
            state.total_input = 0;
        }
        using Atomic<Customers_State>::internalTransition;
        using Atomic<Customers_State>::externalTransition;
        using Atomic<Customers_State>::confluentTransition;
        using Atomic<Customers_State>::output;
        using Atomic<Customers_State>::timeAdvance;

        const Customers_State& getState() {
            return state;
        }
        void internalTransition(Customers_State& state) const override {
            state.clock += state.sigma;
            //state.sigma = ++state.nInternals;
            switch (state.___current_state___) { 
                case Customers_States::Insert_Money:{
                    state.total_input += state.amount_output;

                    if((state.total_input >= state.beverage_selected.price))
                    {
                        state.___current_state___ = Customers_States::Wait_For_Bev;
                        state.sigma = std::numeric_limits<double>::infinity();  // For logging
                        return; // We switched states, return
                    }
                
                    if((state.total_input < state.beverage_selected.price))
                    {
                        state.___current_state___ = Customers_States::Insert_Money;
                        state.sigma = 5;  // For logging
                        return; // We switched states, return
                    }
                
                return;
                }
                case Customers_States::____Wait_For___Customer:{
                    state.received_bev = false;

                    if(true)
                    {
                        state.___current_state___ = Customers_States::Insert_Money;
                        state.sigma = 5;  // For logging
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
        
        void externalTransition(Customers_State& state, double e) const override {
            state.clock += e;
            state.nExternals += 1;

            //store information about total number of inputs
            state.nInputs += (int) i_start_customer_activity->size();
            state.nInputs += (int) i_change_owed->size();
            state.nInputs += (int) i_dispensed_beverage->size();
            //flags for port received
            bool ___r_i_start_customer_activity = !i_start_customer_activity->empty();
            bool ___r_i_change_owed = !i_change_owed->empty();
            bool ___r_i_dispensed_beverage = !i_dispensed_beverage->empty();

            switch (state.___current_state___) {
                case Customers_States::Wait_For_Bev:{



                    state.received_bev = ___r_i_dispensed_beverage;



                    state.total_input = 0;

                    if(true)
                    {
                        state.___current_state___ = Customers_States::____Wait_For___Customer;
                        state.sigma = 10; // For logging
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
             
        void output(const Customers_State& state) const override {
            switch (state.___current_state___) { 
                case Customers_States::Insert_Money:{

                    if((state.total_input >= state.beverage_selected.price))
                    {

                    }
                
                    if((state.total_input < state.beverage_selected.price))
                    {
                        o_money->addMessage(state.amount_output);

                    }
                
                return;
                }     
                
                case Customers_States::____Wait_For___Customer:{

                    if(true)
                    {
                        o_selected_beverage->addMessage(state.beverage_selected);

                    }
                
                return;
                }     
                
                default:
                    break;
                
            }
            return;
        }

        [[nodiscard]] double timeAdvance(const Customers_State& state) const override {
                switch (state.___current_state___) { 

            case Customers_States::Wait_For_Bev:
                // state.sigma = std::numeric_limits<double>::infinity();
                return std::numeric_limits<double>::infinity();

            case Customers_States::____Wait_For___Customer:
                // state.sigma = 10;
                return 10;

            case Customers_States::Insert_Money:
                // state.sigma = 5;
                return 5;

            default:
                break;
            }
            return state.sigma;
        }      
};
#endif //Customers_HPP