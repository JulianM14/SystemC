#include <systemc.h>

SC_MODULE(multiplier) {

	//Ports
	sc_in<int> a;
	sc_in<int> b;
	sc_out<int> c;

	//Funktinality
	void adder_process() {
		c = a + b;
	}

	// Constructor
	SC_HAS_PROCESS(multiplier);
	adder(sc_module_name name) : sc_module(name) {
		SC_METHOD(multiplier_process);
		dont_initialize();
		sensitive << a << b;
	}
};