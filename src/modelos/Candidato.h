#ifndef CANDIDATO_H
#define CANDIDATO_H

#include <string>
#include <ctime>
using namespace std;

class Candidato {
private:
    string nombre;
    string apellido;
    string identificacion;
    char sexo; // 'M' o 'F'
    string estadoCivil; // Casado, Soltero, Unión libre, Divorciado
    int diaNacimiento, mesDNacimiento, birthYear;
    string ciudadNacimiento;
    string ciudadResidencia;
    string partido;
    bool esPresidencial;
    string vicepresidente; // Solo si es presidencial
    int numeroTarjeton; // Para identificar en el tarjetón

public:
    // Constructor
    Candidato();
    Candidato(string n, string a, string id, char s, string ec,
              int d, int m, int y, string cn, string cr, string p, bool pres, string vp = "");

    // Getters
    string Candidato::getNombre() const { return nombre; }
    string Candidato::getApellido() const { return apellido; }
    string Candidato::getIdentificacion() const { return identificacion; }
    char Candidato::getSexo() const { return sexo; }
    string Candidato::getEstadoCivil() const { return estadoCivil; }
    string Candidato::getCiudadNacimiento() const { return ciudadNacimiento; }
    string Candidato::getCiudadResidencia() const { return ciudadResidencia; }
    string Candidato::getPartido() const { return partido; }
    bool Candidato::getEsPresidencial() const { return esPresidencial; }
    string Candidato::getVicepresidente() const { return vicepresidente; }
    int Candidato::getNumeroTarjeton() const { return numeroTarjeton; }

    // Setters
    void Candidato::setPartido(string p) { partido = p; }
    void Candidato::setNumeroTarjeton(int num) { numeroTarjeton = num; }
    void Candidato::setVicepresidente(string vp) { vicepresidente = vp; }
 
};

// Constructor vacío
Candidato::Candidato() 
    : nombre(""), apellido(""), identificacion(""), sexo('M'), 
      estadoCivil(""), diaNacimiento(0), mesDacimiento(0), anoNacimiento(0),
      ciudadNacimiento(""), ciudadResidencia(""), partido(""), 
      esPresidencial(false), vicepresidente(""), numeroTarjeton(0) {}

// Constructor con parámetros
Candidato::Candidato(string n, string a, string id, char s, string ec, 
                     int d, int m, int y, string cn, string cr, string p, bool pres, string vp)
    : nombre(n), apellido(a), identificacion(id), sexo(s), estadoCivil(ec),
      diaNacimiento(d), mesDacimiento(m), anoNacimiento(y),
      ciudadNacimiento(cn), ciudadResidencia(cr), partido(p),
      esPresidencial(pres), vicepresidente(vp), numeroTarjeton(0) {}

// Calcular edad
int Candidato::calcularEdad() const {
    time_t now = time(0);
    tm* localtm = localtime(&now);
    int actualYear = 1900 + localtm->tm_year;
    int edad = actualYear - birthYear;
    
    // Ajustar si aún no ha cumplido años
    int mesActual = 1 + localtm->tm_mon;
    int diaActual = localtm->tm_mday;
    
    if (mesActual < mesDNacimiento || (mesActual == mesDNacimiento && diaActual < diaNacimiento)) {
        edad--;
    }
    
    return edad;
}
#endif //CANDIDATO_H
