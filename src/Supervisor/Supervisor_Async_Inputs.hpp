
#ifndef Supervisor_ASYNC_INPUTS_HPP
#define Supervisor_ASYNC_INPUTS_HPP



class Supervisor_Async_Inputs{


    public:
        Supervisor_Async_Inputs(        ){ 
  
        }

        //                                      //
        //                                      //
        //      FUNCTIONS FOR abort PORT       
        //                                      //
        //                                      //

        // The clock will call this to check if there is data ready for the abort port.
        bool ISR_flag_abort() {

        }

        // If there is data ready on the abort port, the clock will call this, retrieve it and propagate it.
        int ISR_decode_abort() {

            }
            
    private:
     
};    
#endif // Supervisor_ASYNC_INPUTS_HPP      
