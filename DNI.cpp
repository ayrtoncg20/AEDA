#include "DNI.hpp"

dni_t::dni_t():

    numero_dni_(0),
    letra_dni_(' ')
    {}
    
dni_t::~dni_t(){
    
}

int dni_t::contador_ = 0;

int dni_t::get_dni(void){
    
    return numero_dni_;
    
}

char dni_t::get_letra(void){
    
    return letra_dni_;
}

void dni_t::set_letra(char letra){
    
    letra_dni_ = letra;
}

void dni_t::set_dni(int dni){
    
    numero_dni_ = dni;
}

int dni_t::get_contador(void){
    
    return contador_;
}

bool dni_t::operator==(dni_t& dni){
    
    contador_++;
    return (numero_dni_ == dni.get_dni());
}

bool dni_t::operator!=(dni_t& dni){
    
    contador_++;
    return (numero_dni_ != dni.get_dni());
}

bool dni_t::operator<(dni_t& dni){
    
    contador_++;
    return (numero_dni_ < dni.get_dni());
}

bool dni_t::operator>(dni_t& dni){
    
    contador_++;
    return (numero_dni_ > dni.get_dni());
}

bool dni_t::operator<=(dni_t& dni){
    
    contador_++;
    return (numero_dni_ <= dni.get_dni());
}

bool dni_t::operator>=(dni_t& dni){
    
    contador_++;
    return (numero_dni_ >= dni.get_dni());
}

ostream& operator<<(ostream& os, dni_t dni){
    
    os << dni.get_dni();
    return os;
}