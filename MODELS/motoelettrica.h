#ifndef MOTOELETTRICA_H
#define MOTOELETTRICA_H

#include "motoreelettrico.h"

class MotoElettrica: public MotoreElettrico {
public:
    /**
     * @brief MotoElettrica: costruttore
     * @param targa
     * @param posizione
     * @param km
     * @param capacitaBatteria
     * @param caricaSupportata
     * @param numeroPosti
     * @param ingombro
     */
    MotoElettrica(string targa, string posizione, double km, double capacitaBatteria, double capacitaAttuale,
                  VelocitaRicarica caricaSupportata, u_int potenza, u_int numeroMotori, bool inCarica = false, Colonnina colonninaAttuale = nessuna,
                  u_int numeroPosti = 1, u_int ingombro = 2);
};

#endif // MOTOELETTRICA_H
