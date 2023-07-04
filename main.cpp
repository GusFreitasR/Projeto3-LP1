
#include <iostream>

#include "empresa.hpp"

int main() {
    //Criando a empresa como foi indicado pelo professor
    Empresa *atacadoDosCalcados=new Empresa("Atacado dos Calcados", "40.101.588/0001-98", 156289.56);
    atacadoDosCalcados->carregarFuncoes();

    return 0;
}