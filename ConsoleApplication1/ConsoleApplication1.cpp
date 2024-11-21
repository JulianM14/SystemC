#include <systemc.h>

SC_MODULE(HelloWorld) {
    SC_CTOR(HelloWorld) {
        // Prozess registrieren, der bei der Simulationszeit 0 aufgerufen wird.
        SC_THREAD(say_hello);
    }

    void say_hello() {
        // "Hallo, Welt!" in die Standardausgabe schreiben
        cout << "Hallo, Welt! von SystemC" << endl;
    }
};

int sc_main(int argc, char* argv[]) {
    // Erstelle das Modul-Objekt
    HelloWorld hello_world("Hallo World");

    // Starte die Simulation
    sc_start();

    return 0;
}


