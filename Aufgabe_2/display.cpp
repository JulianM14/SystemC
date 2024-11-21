#include "systemc.h";

SC_MODULE(display) {
	sc_in<int> in1;

	void display_process() {
		cout << "/t display[" //tab display
			<< sc_time_stamp() //liefert aktuelle Simulationszeit
			<< "] : (" << in1.read()
			<< ")" << endl;
	}

	SC_CTOR(display) {
		SC_METHOD(display_process);
		dont_initialize();
		sensitive << in1;
	}
};