#include "systemc.h"

SC_MODULE(adder) {

	//Ports
	sc_in<int> a;
	sc_in<int> b;
	sc_out<int> c;

	//Funktinality
	void adder_process() {
		c = a + b;
	}

	// Constructor
	SC_HAS_PROCESS(adder);
	adder(sc_module_name name) : sc_module(name) {
		SC_METHOD(adder_process);
		dont_initialize();
		sensitive << a << b;
	}
};