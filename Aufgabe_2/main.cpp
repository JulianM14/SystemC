#include <systemc.h>
#include "stimuli.cpp"
#include "display.cpp"
#include "module_adder.cpp"

#include "module_multiplier.cpp"


int sc_main(int argc, char* argv[]) {
	// Signale
	sc_signal<int> sig1; 
	sc_signal<int> sig2; sc_signal<int> sig3; 
	// Clock
	sc_clock clk; 
	// Module
	stimuli *S; 
	adder *A; 
	display *D; 
	// Modul Instanziierung und Mapping 
	S = new stimuli("stimuli");
	S->clk(clk); 
	S->out1(sig1); 
	S->out2(sig2);

	A = new adder("adder"); 
	A->a(sig1);
	A->b(sig2); 
	A->c(sig3);
	D = new display("display"); 
	D->in1(sig3);
	// Start der Simulation 
	sc_start(sc_time(10,SC_NS)); 
	return 0;
};