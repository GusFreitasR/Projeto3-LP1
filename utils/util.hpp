#ifndef UTIL_HPP
#define UTIL_HPP
#include <iostream>

typedef struct {
    int ano;
    int mes;
    int dia;
} Date;

typedef struct {
    std::string cep;
    std::string cidade;
    std::string bairro;
    std::string rua;
    int numero;
} Endereco;



#endif