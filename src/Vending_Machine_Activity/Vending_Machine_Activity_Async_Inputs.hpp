
#ifndef Vending_Machine_Activity_ASYNC_INPUTS_HPP
#define Vending_Machine_Activity_ASYNC_INPUTS_HPP



class Vending_Machine_Activity_Async_Inputs{


    public:
        Vending_Machine_Activity_Async_Inputs(        ){ 
  
        }

        //                                      //
        //                                      //
        //      FUNCTIONS FOR i_start_customer_activity PORT       
        //                                      //
        //                                      //

        // The clock will call this to check if there is data ready for the i_start_customer_activity port.
        bool ISR_flag_i_start_customer_activity() {

        }

        // If there is data ready on the i_start_customer_activity port, the clock will call this, retrieve it and propagate it.
        bool ISR_decode_i_start_customer_activity() {

            }
            
    private:
     
};    
#endif // Vending_Machine_Activity_ASYNC_INPUTS_HPP      
