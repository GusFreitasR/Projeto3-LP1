/**
* \file main.cpp
* \authors Emanuel Kywal, Marcos Vinícius e Gustavo Freitas.
* \date 04-07-2023
*/    

#include <iostream>

#include "functions/empresa.hpp"

int main() {
    // Criando a empresa como foi indicado pelo professor.
    Empresa *atacadoDosCalcados=new Empresa("Atacado dos Calcados", "40.101.588/0001-98", 156289.56);
    atacadoDosCalcados->carregarFuncoes();

    return 0;
}
