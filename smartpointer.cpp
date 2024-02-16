/*La idea de los punteros inteligentes es hacer explícita la propiedad del puntero, facilitan la liberacion de memoria de forma automatica
y es de gran utilidad en programas complejos en los que no queremos estar liberando memoria de manera manual, y no sabemos exactamente cuando 
va a terminar una funcion o como va a derivar el flujo de la misma.

los smartpoints pueden ser de tipo 'unique pointer' (unique_ptr<>) o 'shared pointer' (shared_ptr<>).
el unique pointer, como su nombre lo dice, es un puntero unico, y no puede funcionar si existen copias del mismo.
el shared pointer en cambio, se puede utilizar repetidas veces en el programa
 */

// ejemplo de un programa sencillo con smart pointers
#include <iostream>
#include <memory>
using namespace std;

class advertencia {
    public: 
   advertencia () {
        cout <<"advertencia para CONSTRUCTOR"<< endl;
    }

    ~advertencia () {
        cout <<"advertencia para DESTRUCTOR"<< endl;
    }
};

void funcion_random () {
    int r = rand();

    if (r < RAND_MAX / 2) {
        cout <<"Se activa la primera ejecucion \n";
    }
    else {
        cout <<"Se activa la segunda ejecucion \n";
    }
};



int main () {
unique_ptr<advertencia> instancia (new advertencia);

for (int i = 0; i < 6; i++) {
    funcion_random ();
}

return 0;
};