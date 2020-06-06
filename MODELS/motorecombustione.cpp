#include "MODELS/motorecombustione.h"


MotoreCombustione::MotoreCombustione(string targa, string posizione, double km, u_int numeroPosti, u_int ingombro,
                                     double capacitaSerbatoio,double litriSerbatoio, Carburante tipoCarburante, u_int cilindrata, u_int emissioni):
    Veicolo(targa, posizione, km, numeroPosti, ingombro), _capacitaSerbatoio(capacitaSerbatoio), _litriSerbatoio(litriSerbatoio),
    _tipoCarburante(tipoCarburante), _cilindrata(cilindrata), _emissioni(emissioni) {}

MotoreCombustione::~MotoreCombustione() {}

double MotoreCombustione::consumoKm() const {
    double consumo = ingombro();
    if(_tipoCarburante == benzina)
        consumo = consumo * 1.2;
    else if(tipoCarburante() == gpl || tipoCarburante() == metano)
         consumo = consumo * 1.5;
    return (consumo * (_cilindrata / 1000)) / 100;
}

double MotoreCombustione::autonomia() const {
        return consumoKm() * litriSerbatoio();
}

short int MotoreCombustione::fattoreGreen() const {
    double somma = 0;
    if(_tipoCarburante == benzina)
        somma = somma - 2;              // benzina negativo
    else if(_tipoCarburante == diesel)
        somma = somma - 3;              // diesel negativo
    else somma = somma - 1;             // metano, gpl negativo
    somma = somma - _cilindrata / 100;  // cilindrata negativo
    somma = somma - _emissioni / 10;    // emissioni negativo

    if(ingombro() <= 2)
        somma = somma + 1;              // meno ingombro positivo
    if(capacitaPosti() > 1)
        somma = somma + 2;              // piu' posti positivo
    if(guasti() <= 10)
        somma = somma + 1;              // meno guasti positivo

    if(somma < -10) return -10;
    if(somma > 10)  return 10;

    return somma;
}

double MotoreCombustione::capacitaSerbatoio() const {
    return _capacitaSerbatoio;
}

double MotoreCombustione::litriSerbatoio() const {
    return _litriSerbatoio;
}

MotoreCombustione::Carburante MotoreCombustione::tipoCarburante() const {
    return _tipoCarburante;
}

unsigned short MotoreCombustione::cilindrata() const {
    return _cilindrata;
}

unsigned short MotoreCombustione::emissioni() const {
    return _emissioni;
}

void MotoreCombustione::setLitriSerbatoio(double litriSerbatoio)
{
    _litriSerbatoio = litriSerbatoio;
}
