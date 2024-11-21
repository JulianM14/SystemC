#include <systemc.h>



SC_MODULE(stimuli) {
	// Ports
	sc_in<bool> clk;
	sc_out<int> out1;
	sc_out<int> out2;

	// Funktionalität
	void stimuli_process() {
		int tmp1 = 0;
		int tmp2 = 0;
		while (true) {
			tmp1 = tmp1 + 1;
			tmp2 = tmp2 + 2;
			cout << "\t stimuli ["
				<< sc_time_stamp()
				<< "] : (" << tmp1
				<< "," << tmp2 << ")";
			out1.write(tmp1);
			out2.write(tmp2);
			wait();
		}

	}
	// Konstruktor 
	SC_CTOR(stimuli) {
		SC_THREAD(stimuli_process);
		dont_initialize();
		sensitive << clk.pos();
	}
};