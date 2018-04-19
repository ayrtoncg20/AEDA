#pragma once
#include <iostream>

using namespace std;

class dni_t{
    
    public:
    
        int numero_dni_;
        char letra_dni_;
        static int contador_;
    
        dni_t();
        ~dni_t();
        int get_dni(void);
        void set_dni(int dni);
        int get_contador(void);
        char get_letra(void);
        void set_letra(char letra);
        
        bool operator==(dni_t& dni);
        bool operator!=(dni_t& dni);
        bool operator<(dni_t& dni);
        bool operator>(dni_t& dni);
        bool operator<=(dni_t& dni);
        bool operator>=(dni_t& dni);
        
        friend ostream& operator<<(ostream& os, dni_t dni);
    
    
    
};