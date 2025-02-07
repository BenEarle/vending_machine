
#ifndef Example_Coupled_Model_ASYNC_INPUTS_HPP
#define Example_Coupled_Model_ASYNC_INPUTS_HPP



class Example_Coupled_Model_Async_Inputs{


    public:
        Example_Coupled_Model_Async_Inputs(        ){ 
  
        }

        //                                      //
        //                                      //
        //      FUNCTIONS FOR CoupledInput1 PORT       
        //                                      //
        //                                      //

        // The clock will call this to check if there is data ready for the CoupledInput1 port.
        bool ISR_flag_CoupledInput1() {

        }

        // If there is data ready on the CoupledInput1 port, the clock will call this, retrieve it and propagate it.
        int ISR_decode_CoupledInput1() {

            }
            
    private:
     
};    
#endif // Example_Coupled_Model_ASYNC_INPUTS_HPP      
