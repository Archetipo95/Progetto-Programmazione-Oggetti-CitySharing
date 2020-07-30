#ifndef MOTOREELETTRICO_H
#define MOTOREELETTRICO_H

#include "veicolo.h"
#include "EXCEPTIONS/notinchargeexception.h"

class MotoreElettrico : virtual public Veicolo {
public:

    enum Colonnina {
        nessuna, lowHome, lowPublic, medium, ultraFast
    };

    enum VelocitaRicarica {
        lenta = 1, media, veloce
    };

    MotoreElettrico(
                    string targa,
                    string posizione,
                    unsigned long km,
                    unsigned short numeroPosti,
                    unsigned short ingombro,
                    unsigned int potenza,
                    unsigned short numeroMotori,
                    bool inCarica,
                    double capacitaBatteria,
                    double capacitaAttuale,
                    VelocitaRicarica caricaSupportata,
                    Colonnina colonninaAttuale
                   );

    virtual ~MotoreElettrico();

    // metodi virtuali implementati
    virtual double consumoKm() const;
    virtual double autonomia() const;
    virtual short int fattoreGreen() const;

    // calcola il tempo rimanente al veicolo per ranggiungere il 100% di carica
    short tempoRimanenteCaricaCompleta() const;

    // calcola la percentuale della batteria in quel momento
    unsigned short percentualeCarica() const;

    // metodi get
    bool inCarica() const;
    double capacitaBatteria() const;
    double capacitaAttuale() const;
    VelocitaRicarica caricaSupportata() const;
    Colonnina colonninaAttuale() const;

    // metodi set
    void setInCarica(bool inCarica, Colonnina colonnina = nessuna);
    void setCapacitaAttuale(double capacitaAttuale);

private:
    const unsigned int _potenza;                       // Potenza del motore (Wh)
    const unsigned short _numeroMotori;                  // Il numero di motori presenti (da 1 a 4)
    bool _inCarica;                             // Se si sta caricando
    const double _capacitaBatteria;             // Ampere-ora massimi
    double _capacitaAttuale;                    // Ampere-ora attuali
    const VelocitaRicarica _caricaSupportata;   // La massima velocità alla quale può essere ricaricata (da 1 a 4)
    Colonnina _colonninaAttuale;                // Tipo di colonnina alla quale è collegata se inCarica

};

#endif // MOTOREELETTRICO_H
