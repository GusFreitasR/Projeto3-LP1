#include <iostream>
#include "..\utils\util.hpp"
#include "pessoa.hpp"
#include "asg.hpp"
#include "gerente.hpp"
#include "vendedor.hpp"
#include "empresa.hpp"
#include <fstream>
#include <vector>

using namespace std;

//=== Construtores

/// \brief Construtor vazio. 
Empresa::Empresa() {}

/**
* \brief Construtor parametrizado.
* \param nome Nome fantasia da empresa.
* \param cnpj CNPJ da empresa.
* \param faturamento Faturamento mensal da empresa.
*/  
Empresa::Empresa(string nome, string cnpj, float faturamento)
{
    this->cnpj = cnpj;
    this->faturamentoMensal = faturamento;
    this->nomeEmpresa = nome;
}

//=== Getters e setters da classe empresa.

/**
* \brief Obtém o faturamento mensal da empresa.
* \return O faturamento mensal da empresa.
*/
float Empresa::getFaturamentoMensal()
{
    return this->faturamentoMensal;
}

/**
* \brief Define o faturamento mensal da empresa.
* \param faturamento O faturamento mensal da empresa.
*/
void Empresa::setFaturamentoMensal(float faturamento)
{
    this->faturamentoMensal = faturamento;
}

/**
* \brief Obtém o nome da empresa.
* \return O nome da empresa.
*/
string Empresa::getNomeEmpresa()
{
    return this->nomeEmpresa;
}

/**
* \brief Define o nome da empresa.
* \param nome O nome da empresa.
*/
void Empresa::setNomeEmpresa(string nome)
{
    this->nomeEmpresa = nome;
}

/**
* \brief Obtém o CNPJ da empresa.
* \return O CNPJ da empresa.
*/
string Empresa::getCnpj()
{
    return this->cnpj;
}

/**
* \brief Define o CNPJ da empresa.
* \param cnpj O CNPJ da empresa.
*/
void Empresa::setCnpj(string cnpj)
{
    this->cnpj = cnpj;
}

/**
* \brief Obtém os ASGs (Assistentes de Serviços Gerais) da empresa.
* \return Um vetor contendo os ASGs da empresa.
*/
vector<Asg> Empresa::getAsgs()
{
    return this->asgs;
}

/**
* \brief Obtém os vendedores da empresa.
* \return Um vetor contendo os vendedores da empresa.
*/
vector<Vendedor> Empresa::getVendedores()
{
    return this->vendedores;
}

/**
* \brief Obtém os gerentes da empresa.
* \return Um vetor contendo os gerentes da empresa.
*/
vector<Gerente> Empresa::getGerentes()
{
    return this->gerentes;
}

//=== Funções da empresa

/**
* \brief Carrega as chamadas de funções a partir de um arquivo.
*/
void Empresa::carregarFuncoes()
{
    ifstream file("funcoes.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    while (getline(file, line))
    {
        if (line == "carregarEmpresa()")
            carregarEmpresa();
        else if (line == "carregarAsg()")
            carregarAsg();
        else if (line == "carregarVendedor()")
            carregarVendedor();
        else if (line == "carregarGerente()")
            carregarGerente();
        else if (line == "carregaDono()")
            carregaDono();
        else if (line == "imprimeAsgs()")
            imprimeAsgs();
        else if (line == "imprimeVendedores()")
            imprimeVendedores();
        else if (line == "imprimeGerentes()")
            imprimeGerentes();
        else if (line == "imprimeDono()")
            imprimeDono();
        else if (line == "buscaFuncionario()")
        {
            string parametro;
            getline(file, parametro);
            buscaFuncionario(parametro);
        }
        else if (line == "calculaSalarioFuncionario()")
        {
            string parametro;
            getline(file, parametro);
            calculaSalarioFuncionario(parametro);
        }
        else if (line == "calculaTodoOsSalarios()")
        {
            calculaTodosOsSalarios();
        }

        else if (line == "calcularRecisao()")
        {
            string matricula;
            string datas;
            Date data;

            getline(file, matricula);

            getline(file, datas);
            data.ano = stoi(datas);
            getline(file, datas);
            data.mes = stoi(datas);
            getline(file, datas);
            data.dia = stoi(datas);

            calcularRecisao(matricula, data);
        }
        else if (line == "demitirFuncionario()")
        {
            string matricula;
            string datas;
            Date data;

            getline(file, matricula);

            getline(file, datas);
            data.ano = stoi(datas);
            getline(file, datas);
            data.mes = stoi(datas);
            getline(file, datas);
            data.dia = stoi(datas);

            demitirFuncionario(matricula, data);
        }
        else if (line == "contratarFuncionario()")
        {
            contratarFuncionario();
        }
    }
}

/**
* \brief Carrega os dados pessoais e profissionais do dono da empresa a partir de um arquivo.
*/
void Empresa::carregaDono()
{
    ifstream file("dono.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    getline(file, line);
    getline(file, line);

    getline(file, line);
    dono.setNome(line);

    getline(file, line);
    dono.setCpf(line);

    getline(file, line);
    int filhos = stoi(line);
    dono.setQntFilhos(filhos);

    getline(file, line);
    dono.setEstadoCivil(line);

    Endereco endereco;
    getline(file, line);
    endereco.cidade = line;
    getline(file, line);
    endereco.cep = line;
    getline(file, line);
    endereco.bairro = line;
    getline(file, line);
    endereco.rua = line;
    getline(file, line);
    int num = stoi(line);
    endereco.numero = num;
    dono.setEnderecoPessoal(endereco);

    Date date_nasc;
    getline(file, line);
    int ano = stoi(line);
    date_nasc.ano = ano;
    getline(file, line);
    int mes = stoi(line);
    date_nasc.mes = mes;
    getline(file, line);
    int dia = stoi(line);
    date_nasc.dia = dia;
    dono.setDataNascimento(date_nasc);

    file.close();
}

/**
* \brief Carrega as informações da empresa a partir de um arquivo.
*/
void Empresa::carregarEmpresa()
{
    ifstream file("empresa.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    getline(file, line);
    getline(file, line);

    getline(file, line);
    setNomeEmpresa(line);
    getline(file, line);
    setCnpj(line);
    getline(file, line);
    setFaturamentoMensal(stof(line));

    file.close();
}

/**
* \brief Carrega os dados pessoais e profissionais dos asgs da empresa a partir de um arquivo.
*/
void Empresa::carregarAsg()
{
    ifstream file("asg.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    Asg asg;
    Endereco endereco;
    Date data_nasc, data_ingresso;

    while (getline(file, line))
    {
        getline(file, line);
        getline(file, line);

        getline(file, line);
        asg.setNome(line);
        getline(file, line);
        asg.setCpf(line);
        getline(file, line);
        asg.setQntFilhos(stoi(line));
        getline(file, line);
        asg.setEstadoCivil(line);

        getline(file, line);

        getline(file, line);
        endereco.cidade = line;
        getline(file, line);
        endereco.cep = line;
        getline(file, line);
        endereco.bairro = line;
        getline(file, line);
        endereco.rua = line;
        getline(file, line);
        endereco.numero = stoi(line);
        asg.setEnderecoPessoal(endereco);

        getline(file, line);

        getline(file, line);
        data_nasc.ano = stoi(line);
        getline(file, line);
        data_nasc.mes = stoi(line);
        getline(file, line);
        data_nasc.dia = stoi(line);
        asg.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        asg.setMatricula(line);
        getline(file, line);
        asg.setSalario(line);
        getline(file, line);
        asg.setAdicionalInsalubridade(stof(line));
        getline(file, line);
        asg.setFaltas(stoi(line));

        getline(file, line);

        getline(file, line);
        data_ingresso.ano = stoi(line);
        getline(file, line);
        data_ingresso.mes = stoi(line);
        getline(file, line);
        data_ingresso.dia = stoi(line);
        asg.setIngressoEmpresa(data_ingresso);

        asgs.push_back(asg);
    }

    file.close();
}

/**
* \brief Carrega os dados pessoais e profissionais dos vendedores da empresa a partir de um arquivo.
*/
void Empresa::carregarVendedor()
{
    ifstream file("vendedor.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    Vendedor vendedor;
    Endereco endereco;
    Date data_nasc, data_ingresso;

    while (getline(file, line))
    {
        getline(file, line);
        getline(file, line);

        getline(file, line);
        vendedor.setNome(line);
        getline(file, line);
        vendedor.setCpf(line);
        getline(file, line);
        vendedor.setQntFilhos(stoi(line));
        getline(file, line);
        vendedor.setEstadoCivil(line);

        getline(file, line);

        getline(file, line);
        endereco.cidade = line;
        getline(file, line);
        endereco.cep = line;
        getline(file, line);
        endereco.bairro = line;
        getline(file, line);
        endereco.rua = line;
        getline(file, line);
        endereco.numero = stoi(line);
        vendedor.setEnderecoPessoal(endereco);

        getline(file, line);

        getline(file, line);
        data_nasc.ano = stoi(line);
        getline(file, line);
        data_nasc.mes = stoi(line);
        getline(file, line);
        data_nasc.dia = stoi(line);
        vendedor.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        vendedor.setMatricula(line);
        getline(file, line);
        vendedor.setSalario(line);
        getline(file, line);
        char tipo = line[0];
        vendedor.setTipoVendedor(tipo);
        getline(file, line);
        vendedor.setFaltas(stoi(line));

        getline(file, line);

        getline(file, line);
        data_ingresso.ano = stoi(line);
        getline(file, line);
        data_ingresso.mes = stoi(line);
        getline(file, line);
        data_ingresso.dia = stoi(line);
        vendedor.setIngressoEmpresa(data_ingresso);

        vendedores.push_back(vendedor);
    }

    file.close();
}

/**
* \brief Carrega os dados pessoais e profissionais dos gerentes da empresa a partir de um arquivo.
*/
void Empresa::carregarGerente()
{
    ifstream file("gerente.txt");
    string line;
    if (!(file.is_open()))
    {
        cout << "Arquivo nao pode ser aberto" << endl;
        return;
    }

    Gerente gerente;
    Endereco endereco;
    Date data_nasc, data_ingresso;

    while (getline(file, line))
    {
        getline(file, line);
        getline(file, line);

        getline(file, line);
        gerente.setNome(line);
        getline(file, line);
        gerente.setCpf(line);
        getline(file, line);
        gerente.setQntFilhos(stoi(line));
        getline(file, line);
        gerente.setEstadoCivil(line);

        getline(file, line);

        getline(file, line);
        endereco.cidade = line;
        getline(file, line);
        endereco.cep = line;
        getline(file, line);
        endereco.bairro = line;
        getline(file, line);
        endereco.rua = line;
        getline(file, line);
        endereco.numero = stoi(line);
        gerente.setEnderecoPessoal(endereco);

        getline(file, line);

        getline(file, line);
        data_nasc.ano = stoi(line);
        getline(file, line);
        data_nasc.mes = stoi(line);
        getline(file, line);
        data_nasc.dia = stoi(line);
        gerente.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        gerente.setMatricula(line);
        getline(file, line);
        gerente.setSalario(line);
        getline(file, line);
        gerente.setParticipacaoLucros(stof(line));
        getline(file, line);
        gerente.setFaltas(stoi(line));

        getline(file, line);

        getline(file, line);
        data_ingresso.ano = stoi(line);
        getline(file, line);
        data_ingresso.mes = stoi(line);
        getline(file, line);
        data_ingresso.dia = stoi(line);
        gerente.setIngressoEmpresa(data_ingresso);

        gerentes.push_back(gerente);
    }

    file.close();
}

/**
 * \brief Função que imprime a lista de profissionais ASG carregados.
 */
void Empresa::imprimeAsgs()
{
    cout << "Lista de profissionais ASG:" << endl;
    cout << "****************************" << endl;
    for (auto i : asgs)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de Nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereco: Rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQntFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na empresa: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "**********************************" << endl;
    }
}

/**
 * \brief Função que imprime a lista de profissionais ASG carregados.
 */
void Empresa::imprimeVendedores()
{
    cout << "Lista de vendedores:" << endl;
    cout << "****************************" << endl;
    for (auto i : vendedores)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereco: Rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQntFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na empresa: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "**********************************" << endl;
    }
}

/**
 * \brief Função que imprime a lista de profissionais ASG carregados.
 */
void Empresa::imprimeGerentes()
{
    cout << "Lista de gerentes:" << endl;
    cout << "****************************" << endl;
    for (auto i : gerentes)
    {
        cout << "Nome: " << i.getNome() << endl;
        cout << "CPF: " << i.getCpf() << endl;
        cout << "Data de nascimento: " << i.getDataNascimento().dia << "/" << i.getDataNascimento().mes << "/" << i.getDataNascimento().ano << endl;
        cout << "Endereço: Rua " << i.getEnderecoPessoal().rua << ", " << i.getEnderecoPessoal().numero << endl;
        cout << "Estado civil: " << i.getEstadoCivil() << endl;
        cout << "Numero de filhos: " << i.getQntFilhos() << endl;
        cout << "Salario: " << i.calcularSalario() << endl;
        cout << "Numero de faltas: " << i.getFaltas() << endl;
        cout << "Matricula: " << i.getMatricula() << endl;
        cout << "Data de ingresso na empresa: " << i.getIngressoEmpresa().dia << "/" << i.getIngressoEmpresa().mes << "/" << i.getIngressoEmpresa().ano << endl;
        cout << "**********************************" << endl;
    }
}

/**
 * \brief Função que imprime a lista de profissionais ASG carregados.
 */
void Empresa::imprimeDono()
{
    cout << "****************************" << endl;
    cout << "Informacoes sobre dono:" << endl;
    cout << "Nome: " << dono.getNome() << endl;
    cout << "CPF: " << dono.getCpf() << endl;
    cout << "Data de date_nasc: " << dono.getDataNascimento().dia << "/" << dono.getDataNascimento().mes << "/" << dono.getDataNascimento().ano << endl;
    cout << "Endereco: Rua " << dono.getEnderecoPessoal().rua << ", " << dono.getEnderecoPessoal().numero << endl;
    cout << "Estado civil: " << dono.getEstadoCivil() << endl;
    cout << "Numero de filhos: " << dono.getQntFilhos() << endl;
    cout << "****************************" << endl;
}

/**
 * \brief Função que busca um funcionário na empresa pelo número de matrícula.
 * \param matricula A matrícula do funcionário a ser buscado.
 * \return Retorna true se o funcionário for encontrado, caso contrário, retorna false.
 */
bool Empresa::buscaFuncionario(string matricula)
{
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario encontrado." << endl;
            return true;
        }
    }
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario encontrado." << endl;
            return true;
        }
    }
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "Funcionario encontrado." << endl;
            return true;
        }
    }
    cout << "Nao existe um funcionario com essa matricula em nosso sistema" << endl;
    return false;
}

/**
 * \brief Função que calcula o salário de um funcionário com base no número de matrícula.
 * \param matricula A matrícula do funcionário.
 * \return Retorna o valor do salário do funcionário se encontrado, caso contrário, retorna -1.
 */
float Empresa::calculaSalarioFuncionario(string matricula)
{
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario " << i.getNome() << " e: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario " << i.getNome() << " e: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "O salario do funcionario " << i.getNome() << " e: " << i.calcularSalario() << endl;
            return i.calcularSalario();
        }
    }
    cout << "Nao existe um funcionario com essa matricula em nosso sistema" << endl;
    return -1;
}

/**
 * \brief Função que calcula o salário de todos os funcionários da empresa e salva em um arquivo.
 */
void Empresa::calculaTodosOsSalarios()
{
    float total = 0, asg_total = 0, vendedor_total = 0, gerente_total = 0;
    ofstream file("salva_salarios.txt");
    if (!(file.is_open()))
    {
        cout << "Arquivo não pode ser aberto!" << endl;
        return;
    }

    for (auto i : asgs)
    {
        file << "Nome do funcionario: " << i.getNome() << endl;
        cout << "Nome do funcionario: " << i.getNome() << endl;
        file << "Cargo do funcionario: ASG" << endl;
        cout << "Cargo do funcionario: ASG" << endl;
        file << "Salario do funcionario: " << i.calcularSalario() << endl;
        cout << "Salario do funcionario: " << i.calcularSalario() << endl;
        file << "------------------------------------------" << endl;
        cout << "------------------------------------------" << endl;
        total += i.calcularSalario();
        asg_total += i.calcularSalario();
    }
    file << "******************************" << endl;
    cout << "******************************" << endl;
    for (auto i : vendedores)
    {
        file << "Nome do funcionario: " << i.getNome() << endl;
        cout << "Nome do funcionario: " << i.getNome() << endl;
        file << "Cargo do funcionario: vendedor" << endl;
        cout << "Cargo do funcionario: vendedor" << endl;
        file << "Salario do funcionario: " << i.calcularSalario() << endl;
        cout << "Salario do funcionario: " << i.calcularSalario() << endl;
        file << "------------------------------------------" << endl;
        cout << "------------------------------------------" << endl;
        total += i.calcularSalario();
        vendedor_total += i.calcularSalario();
    }
    file << "******************************" << endl;
    cout << "******************************" << endl;
    for (auto i : gerentes)
    {
        file << "Nome do funcionario: " << i.getNome() << endl;
        cout << "Nome do funcionario: " << i.getNome() << endl;
        file << "Cargo do funcionario: gerente" << endl;
        cout << "Cargo do funcionario: gerente" << endl;
        file << "Salario do funcionario: " << i.calcularSalario() << endl;
        cout << "Salario do funcionario: " << i.calcularSalario() << endl;
        file << "------------------------------------------" << endl;
        cout << "------------------------------------------" << endl;
        total += i.calcularSalario();
        gerente_total += i.calcularSalario();
    }
    file << "******************************" << endl;
    cout << "******************************" << endl;

    file << "Total de salarios dos funcionarios ASG: " << asg_total << endl;
    cout << "Total de salarios dos funcionarios ASG: " << asg_total << endl;
    file << "Total de salarios dos vendedores: " << vendedor_total << endl;
    cout << "Total de salarios dos vendedores: " << vendedor_total << endl;
    file << "Total de salarios dos gerentes: " << gerente_total << endl;
    cout << "Total de salarios dos gerentes: " << gerente_total << endl;

    file << "******************************" << endl;
    cout << "******************************" << endl;
    file << "Total de salarios dos funcionarios: " << total << endl;
    cout << "Total de salarios dos funcionarios: " << total << endl;

    file.close();

    ofstream relatorio("relatorioFinanceiro.txt");
    relatorio<<"######### Relatório Financeiro #########"<<endl<<endl;
    cout<<"######### Relatório Financeiro #########"<<endl<<endl;

    relatorio<<"Cargo: ASG"<<endl;
    cout<<"Cargo: ASG"<<endl;
    for(auto i : asgs) {
        relatorio<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
        cout<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
    }
    relatorio<<"Total ASG: "<<asg_total<<endl<<endl;
    cout<<"Total ASG: "<<asg_total<<endl<<endl;

    relatorio<<"Cargo: Vendedor"<<endl;
    cout<<"Cargo: Vendedor"<<endl;
    for(auto i : vendedores) {
        relatorio<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
        cout<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
    }
    relatorio<<"Total Vendedor: "<<vendedor_total<<endl<<endl;
    cout<<"Total Vendedor: "<<vendedor_total<<endl<<endl;

    relatorio<<"Cargo: Gerente"<<endl;
    cout<<"Cargo: Gerente"<<endl;
    for(auto i : gerentes) {
        relatorio<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
        cout<<i.getMatricula()<<" - "<<i.getNome()<<" - "<<i.calcularSalario()<<endl;
    }
    relatorio<<"Total Gerente: "<<gerente_total<<endl<<endl;
    cout<<"Total Gerente: "<<gerente_total<<endl<<endl;

    relatorio<<"CUSTO TOTAL: R$ "<<total<<endl<<endl;
    cout<<"CUSTO TOTAL: R$ "<<total<<endl<<endl;

    relatorio<<"FATURAMENTO MENSAL: R$ "<<faturamentoMensal<<endl<<endl;
    cout<<"FATURAMENTO MENSAL: R$ "<<faturamentoMensal<<endl<<endl;

    relatorio<<"CUSTO ASG(%): "<<(asg_total/total)*100<<"%"<<endl;
    relatorio<<"CUSTO Vendedor(%): "<<(vendedor_total/total)*100<<"%"<<endl;
    relatorio<<"CUSTO Gerente(%): "<<(gerente_total/total)*100<<"%"<<endl<<endl;
    cout<<"CUSTO ASG(%): "<<(asg_total/total)*100<<"%"<<endl;
    cout<<"CUSTO Vendedor(%): "<<(vendedor_total/total)*100<<"%"<<endl;
    cout<<"CUSTO Gerente(%): "<<(gerente_total/total)*100<<"%"<<endl<<endl;

    float lucro = faturamentoMensal - total;
    relatorio<<"LUCRO DA EMPRESA: "<<lucro<<endl<<endl;
    cout<<"LUCRO DA EMPRESA: "<<lucro<<endl<<endl;

    if(lucro >= 0) {
        relatorio<<"SITUAÇÃO: Lucro"<<endl;
        cout<<"SITUAÇÃO: Lucro"<<endl;
    }
    else {
        relatorio<<"SITUAÇÃO: Prejuízo"<<endl;
        cout<<"SITUAÇÃO: Prejuízo"<<endl;
    }

    relatorio.close();
}

/**
 * \brief Calcula os anos de estadia de um certo funcionário dado a sua matrícula e data de saída.
 * 
 * \param matricula A matrícula do funcionário.
 * \param data A data de saída.
 * \return O número de anos de estadia do funcionário.
 */
int Empresa::calcularAnos(string matricula, Date data){
    for(auto asg = asgs.begin(); asg != asgs.end(); asg++) {
        if((*asg).getMatricula() == matricula){
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*asg).getIngressoEmpresa().ano*365 - (*asg).getIngressoEmpresa().mes*30 - (*asg).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            return anos;
        }
    }
    for(auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
        if((*vend).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*vend).getIngressoEmpresa().ano*365 - (*vend).getIngressoEmpresa().mes*30 - (*vend).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            return anos;
        }
    }

    for(auto ger = gerentes.begin(); ger != gerentes.end(); ger++) {
        if((*ger).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*ger).getIngressoEmpresa().ano*365 - (*ger).getIngressoEmpresa().mes*30 - (*ger).getIngressoEmpresa().dia;
            int anos = diastotais/365;
            return anos;
        }
    }

    return 0;
}

/**
 * \brief Calcula os meses de estadia de um certo funcionário dado a sua matrícula e data de saída.
 * 
 * \param matricula A matrícula do funcionário.
 * \param data A data de saída.
 * \return O número de meses de estadia do funcionário.
 */
int Empresa::calcularMeses(string matricula, Date data){
    for(auto asg = asgs.begin(); asg != asgs.end(); asg++) {
        if((*asg).getMatricula() == matricula){
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*asg).getIngressoEmpresa().ano*365 - (*asg).getIngressoEmpresa().mes*30 - (*asg).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            int meses = diastotais/30;
            return meses;
        }
    }
    for(auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
        if((*vend).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*vend).getIngressoEmpresa().ano*365 - (*vend).getIngressoEmpresa().mes*30 - (*vend).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            int meses = diastotais/30;
            return meses;
        }
    }

    for(auto ger = gerentes.begin(); ger != gerentes.end(); ger++) {
        if((*ger).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*ger).getIngressoEmpresa().ano*365 - (*ger).getIngressoEmpresa().mes*30 - (*ger).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            int meses = diastotais/30;
            return meses;
        }
    }

    return 0;
}

/**
 * \brief Calcula os dias de estadia de um certo funcionário dado a sua matrícula e data de saída.
 * 
 * \param matricula A matrícula do funcionário.
 * \param data A data de saída.
 * \return O número de dias de estadia do funcionário.
 */
int Empresa::calcularDias(string matricula, Date data){
    for(auto asg = asgs.begin(); asg != asgs.end(); asg++) {
        if((*asg).getMatricula() == matricula){
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*asg).getIngressoEmpresa().ano*365 - (*asg).getIngressoEmpresa().mes*30 - (*asg).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            diastotais -= 30*calcularMeses(matricula, data);
            return diastotais;
        }
    }
    for(auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
        if((*vend).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*vend).getIngressoEmpresa().ano*365 - (*vend).getIngressoEmpresa().mes*30 - (*vend).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            diastotais -= 30*calcularMeses(matricula, data);
            return diastotais;
        }
    }

    for(auto ger = gerentes.begin(); ger != gerentes.end(); ger++) {
        if((*ger).getMatricula() == matricula) {
            int diastotais = data.ano*365 + data.mes*30 + data.dia - (*ger).getIngressoEmpresa().ano*365 - (*ger).getIngressoEmpresa().mes*30 - (*ger).getIngressoEmpresa().dia;
            diastotais -= 365*calcularAnos(matricula, data);
            diastotais -= 30*calcularMeses(matricula, data);
            return diastotais;
        }
    }

    return 0;
}

/**
* \brief Atualiza o arquivo externo de asg's com os dados atuais.
*/
void Empresa::atualizarAsg(){
        try {
        ofstream arquivo("asg.txt");
        
            if (arquivo.is_open()) {
            for(auto asg = asgs.begin(); asg!=asgs.end(); asg++){
            arquivo << "#########################################################"<< endl;
            arquivo << "ASG Nº: "<< asg - asgs.begin() << endl;
            arquivo << "##### DADOS PESSOAIS #####" << endl;
            arquivo << (*asg).getNome() << endl;
            arquivo << (*asg).getCpf() << endl;
            arquivo << (*asg).getQntFilhos()<< endl;
            arquivo << (*asg).getEstadoCivil()<< endl;
            arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****"<< endl;
            arquivo << (*asg).getEnderecoPessoal().cidade << endl;
            arquivo << (*asg).getEnderecoPessoal().cep << endl;
            arquivo << (*asg).getEnderecoPessoal().bairro << endl;
            arquivo << (*asg).getEnderecoPessoal().rua << endl;
            arquivo << (*asg).getEnderecoPessoal().numero << endl;
            arquivo << "***** Data de nascimento (ano, mes, dia) ****"<< endl;
            arquivo << (*asg).getDataNascimento().ano << endl;
            arquivo << (*asg).getDataNascimento().mes << endl;
            arquivo << (*asg).getDataNascimento().dia << endl;
            arquivo << "##### DADOS FUNCIONAIS #####"<< endl;
            arquivo << (*asg).getMatricula()<< endl;
            arquivo << (*asg).getSalario() << endl;
            arquivo << (*asg).getAdicionalInsalubridade() << endl;
            arquivo << (*asg).getFaltas() << endl;
            arquivo << "***** Data de ingresso (ano, mes, dia) ****"<< endl;
            arquivo << (*asg).getIngressoEmpresa().ano << endl;
            arquivo << (*asg).getIngressoEmpresa().mes << endl;
            arquivo << (*asg).getIngressoEmpresa().dia << endl;
            }

            arquivo.close();
            cout << "Asgs atualizados com sucesso!" << endl;
        } else {
            throw runtime_error("Erro ao abrir o arquivo.");
        }
    } catch (exception& ex) {
        cerr << "Erro: " << ex.what() << endl;
    }
}

/**
* \brief Atualiza o arquivo externo de vendedores com os dados atuais.
*/
void Empresa::atualizarVendedor() {
    try {
        ofstream arquivo("vendedor.txt");

        if (arquivo.is_open()) {
            for (auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
                arquivo << "#########################################################" << endl;
                arquivo << "VENDEDOR Nº: " << vend - vendedores.begin() << endl;
                arquivo << "##### DADOS PESSOAIS #####"<< endl;
                arquivo << (*vend).getNome() << endl;
                arquivo << (*vend).getCpf() << endl;
                arquivo << (*vend).getQntFilhos() << endl;
                arquivo << (*vend).getEstadoCivil() << endl;
                arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
                arquivo << (*vend).getEnderecoPessoal().cidade << endl;
                arquivo << (*vend).getEnderecoPessoal().cep << endl;
                arquivo << (*vend).getEnderecoPessoal().bairro << endl;
                arquivo << (*vend).getEnderecoPessoal().rua << endl;
                arquivo << (*vend).getEnderecoPessoal().numero << endl;
                arquivo << "***** Data de nascimento (ano, mes, dia) ****"<< endl;
                arquivo << (*vend).getDataNascimento().ano << endl;
                arquivo << (*vend).getDataNascimento().mes << endl;
                arquivo << (*vend).getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####"<< endl;
                arquivo << (*vend).getMatricula() << endl;
                arquivo << (*vend).getSalario() << endl;
                arquivo << (*vend).getTipoVendedor() << endl;
                arquivo << (*vend).getFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****"<< endl;
                arquivo << (*vend).getIngressoEmpresa().ano << endl;
                arquivo << (*vend).getIngressoEmpresa().mes << endl;
                arquivo << (*vend).getIngressoEmpresa().dia << endl;
            }

            arquivo.close();
            cout << "Vendedores atualizados com sucesso!" <<endl;
        } else {
            throw runtime_error("Erro ao abrir o arquivo.");
        }
    } catch (exception& ex) {
        cerr << "Erro: " << ex.what() << endl;
    }
}

/**
* \brief Atualiza o arquivo externo de gerentes com os dados atuais.
*/
void Empresa::atualizarGerente() {
    try {
        ofstream arquivo("gerente.txt");

        if (arquivo.is_open()) {
            for (auto gen = gerentes.begin(); gen != gerentes.end(); gen++) {
                arquivo << "#########################################################" << endl;
                arquivo << "GERENTE Nº: " << gen - gerentes.begin() << endl;
                arquivo << "##### DADOS PESSOAIS #####"<< endl;
                arquivo << (*gen).getNome() << endl;
                arquivo << (*gen).getCpf() << endl;
                arquivo << (*gen).getQntFilhos() << endl;
                arquivo << (*gen).getEstadoCivil() << endl;
                arquivo << "***** Endereço (cidade, cep, bairro, rua e numero) ****" << endl;
                arquivo << (*gen).getEnderecoPessoal().cidade << endl;
                arquivo << (*gen).getEnderecoPessoal().cep << endl;
                arquivo << (*gen).getEnderecoPessoal().bairro << endl;
                arquivo << (*gen).getEnderecoPessoal().rua << endl;
                arquivo << (*gen).getEnderecoPessoal().numero << endl;
                arquivo << "***** Data de nascimento (ano, mes, dia) ****"<< endl;
                arquivo << (*gen).getDataNascimento().ano << endl;
                arquivo << (*gen).getDataNascimento().mes << endl;
                arquivo << (*gen).getDataNascimento().dia << endl;
                arquivo << "##### DADOS FUNCIONAIS #####"<< endl;
                arquivo << (*gen).getMatricula() << endl;
                arquivo << (*gen).getSalario() << endl;
                arquivo << (*gen).getParticipacaoLucros() << endl;
                arquivo << (*gen).getFaltas() << endl;
                arquivo << "***** Data de ingresso (ano, mes, dia) ****"<< endl;
                arquivo << (*gen).getIngressoEmpresa().ano << endl;
                arquivo << (*gen).getIngressoEmpresa().mes << endl;
                arquivo << (*gen).getIngressoEmpresa().dia << endl;
            }

            arquivo.close();
            cout << "Gerentes atualizados com sucesso!" << endl;
        } else {
            throw runtime_error("Erro ao abrir o arquivo.");
        }
    } catch (const exception& ex) {
        cerr << "Erro: " << ex.what() << endl;
    }
}

/**
 * \brief Demite um funcionário com base em sua matrícula e data de desligamento.
 *
 * \param matricula A matrícula do funcionário a ser demitido.
 * \param desligamento A data de desligamento do funcionário.
 */
void Empresa::demitirFuncionario(string matricula, Date desligamento) {
    for(auto asg = asgs.begin(); asg != asgs.end(); asg++) {
        if((*asg).getMatricula() == matricula) {
            

            cout<< "##############################"<<endl;
            cout<< "    Relatorio Demissional    "<<endl;
            cout<< "##############################"<<endl;
            cout<< "Cargo: ASG"<<endl;
            cout<< "Nome: "<<(*asg).getNome()<<endl;
            cout<< "CPF: "<<(*asg).getCpf()<<endl;
            cout<< "Matrícula: "<<(*asg).getMatricula()<<endl;
            cout<< "Data de ingresso: "<<(*asg).getIngressoEmpresa().dia<<"/"<<(*asg).getIngressoEmpresa().mes<<"/"<<(*asg).getIngressoEmpresa().ano<<endl;
            cout<< "Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<< "******************************"<<endl;
            cout<< "Valor de recisão: "<<(*asg).calcularRecisao(desligamento)<<endl;
            cout<< "******************************"<<endl;
            cout<< "Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: ASG"<<endl;
            file<<"Nome: "<<(*asg).getNome()<<endl;
            file<<"CPF: "<<(*asg).getCpf()<<endl;
            file<<"Matrícula: "<<(*asg).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*asg).getIngressoEmpresa().dia<<"/"<<(*asg).getIngressoEmpresa().mes<<"/"<<(*asg).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*asg).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;
            file.close();

            asgs.erase(asg);
            atualizarAsg();
            return;
        }
    }

    for(auto vend = vendedores.begin(); vend != vendedores.end(); vend++) {
        if((*vend).getMatricula() == matricula) {

            cout<<"##############################"<<endl;
            cout<<"    Relatorio Demissional    "<<endl;
            cout<<"##############################"<<endl;
            cout<<"Cargo: Vendedor"<<endl;
            cout<<"Nome: "<<(*vend).getNome()<<endl;
            cout<<"CPF: "<<(*vend).getCpf()<<endl;
            cout<<"Matrícula: "<<(*vend).getMatricula()<<endl;
            cout<<"Data de ingresso: "<<(*vend).getIngressoEmpresa().dia<<"/"<<(*vend).getIngressoEmpresa().mes<<"/"<<(*vend).getIngressoEmpresa().ano<<endl;
            cout<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<<"******************************"<<endl;
            cout<<"Valor de recisão: "<<(*vend).calcularRecisao(desligamento)<<endl;
            cout<<"******************************"<<endl;
            cout<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: Vendedor"<<endl;
            file<<"Nome: "<<(*vend).getNome()<<endl;
            file<<"CPF: "<<(*vend).getCpf()<<endl;
            file<<"Matrícula: "<<(*vend).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*vend).getIngressoEmpresa().dia<<"/"<<(*vend).getIngressoEmpresa().mes<<"/"<<(*vend).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*vend).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;
            file.close();

            vendedores.erase(vend);
            
    
            atualizarVendedor();
            return;
        }
    }

    for(auto ger = gerentes.begin(); ger != gerentes.end(); ger++) {
        if((*ger).getMatricula() == matricula) {

            cout<<"##############################"<<endl;
            cout<<"    Relatorio Demissional    "<<endl;
            cout<<"##############################"<<endl;
            cout<<"Cargo: Gerente"<<endl;
            cout<<"Nome: "<<(*ger).getNome()<<endl;
            cout<<"CPF: "<<(*ger).getCpf()<<endl;
            cout<<"Matrícula: "<<(*ger).getMatricula()<<endl;
            cout<<"Data de ingresso: "<<(*ger).getIngressoEmpresa().dia<<"/"<<(*ger).getIngressoEmpresa().mes<<"/"<<(*ger).getIngressoEmpresa().ano<<endl;
            cout<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            cout<<"******************************"<<endl;
            cout<<"Valor de recisão: "<<(*ger).calcularRecisao(desligamento)<<endl;
            cout<<"******************************"<<endl;
            cout<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;

            ofstream file("relatorio-demissional.txt");
            file<<"##############################"<<endl;
            file<<"    Relatorio Demissional    "<<endl;
            file<<"##############################"<<endl;
            file<<"Cargo: Gerente"<<endl;
            file<<"Nome: "<<(*ger).getNome()<<endl;
            file<<"CPF: "<<(*ger).getCpf()<<endl;
            file<<"Matrícula: "<<(*ger).getMatricula()<<endl;
            file<<"Data de ingresso: "<<(*ger).getIngressoEmpresa().dia<<"/"<<(*ger).getIngressoEmpresa().mes<<"/"<<(*ger).getIngressoEmpresa().ano<<endl;
            file<<"Data de demissão: "<<desligamento.dia<<"/"<<desligamento.mes<<"/"<<desligamento.ano<<endl;
            file<<"******************************"<<endl;
            file<<"Valor de recisão: "<<(*ger).calcularRecisao(desligamento)<<endl;
            file<<"******************************"<<endl;
            file<<"Tempo de trabalho: "<<calcularAnos(matricula, desligamento)<<" anos, "<<calcularMeses(matricula, desligamento)<<" meses e "<<calcularDias(matricula, desligamento)<<" dias"<<endl;
            file.close();

            gerentes.erase(ger);
            cout << "Funcionário demitido com sucesso. Relatório demissional gerado." << endl;
            atualizarGerente();
            
            return;
        }
    }
    cout << "Não existe funcionario com essa matricula" << endl;
}

/**
 * \brief Contrata um novo funcionário com base nas informações fornecidas em um arquivo.
 * O formato do arquivo deve seguir um padrão específico.
 */
void Empresa::contratarFuncionario() {
    ifstream file("novoFuncionario.txt");
    string line;
    getline(file, line);
    if(line == "ASG"){
        Asg asg;
        getline(file, line);
        getline(file, line);
        asg.setNome(line);
        getline(file, line);
        asg.setCpf(line);
        getline(file, line);
        asg.setQntFilhos(stoi(line));
        getline(file, line);
        asg.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        asg.setEnderecoPessoal(endereco);

        getline(file, line);

        Date data_nasc;
        getline(file, line);
        data_nasc.ano=stoi(line);
        getline(file, line);
        data_nasc.mes=stoi(line);
        getline(file, line);
        data_nasc.dia=stoi(line);
        asg.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        asg.setMatricula(line);
        getline(file, line);
        asg.setSalario(line);
        getline(file, line);
        asg.setAdicionalInsalubridade(stof(line));
        getline(file, line);
        asg.setFaltas(stoi(line));

        getline(file, line);

        Date date_ing;
        getline(file, line);
        date_ing.ano=stoi(line);
        getline(file, line);
        date_ing.mes=stoi(line);
        getline(file, line);
        date_ing.dia=stoi(line);
        asg.setIngressoEmpresa(date_ing);

        asgs.push_back(asg);

        atualizarAsg();
        return;
    }
    if(line == "Vendedor") {
        Vendedor vendedor;
        getline(file, line);
        vendedor.setNome(line);
        getline(file, line);
        vendedor.setCpf(line);
        getline(file, line);
        vendedor.setQntFilhos(stoi(line));
        getline(file, line);
        vendedor.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        vendedor.setEnderecoPessoal(endereco);

        getline(file, line);

        Date data_nasc;
        getline(file, line);
        data_nasc.ano=stoi(line);
        getline(file, line);
        data_nasc.mes=stoi(line);
        getline(file, line);
        data_nasc.dia=stoi(line);
        vendedor.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        vendedor.setMatricula(line);
        getline(file, line);
        vendedor.setSalario(line);
        getline(file, line);
        vendedor.setTipoVendedor(line[0]);
        getline(file, line);
        vendedor.setFaltas(stoi(line));

        getline(file, line);

        Date date_ing;
        getline(file, line);
        date_ing.ano=stoi(line);
        getline(file, line);
        date_ing.mes=stoi(line);
        getline(file, line);
        date_ing.dia=stoi(line);
        vendedor.setIngressoEmpresa(date_ing);

        vendedores.push_back(vendedor);
        
        atualizarVendedor();
        return;
    }
    if(line == "Gerente") {
        Gerente gerente;
        getline(file, line);
        gerente.setNome(line);
        getline(file, line);
        gerente.setCpf(line);
        getline(file, line);
        gerente.setQntFilhos(stoi(line));
        getline(file, line);
        gerente.setEstadoCivil(line);

        getline(file, line);

        Endereco endereco;
        getline(file, line);
        endereco.cidade=line;
        getline(file, line);
        endereco.cep=line;
        getline(file, line);
        endereco.bairro=line;
        getline(file, line);
        endereco.rua=line;
        getline(file, line);
        endereco.numero=stoi(line);
        gerente.setEnderecoPessoal(endereco);

        getline(file, line);

        Date data_nasc;
        getline(file, line);
        data_nasc.ano=stoi(line);
        getline(file, line);
        data_nasc.mes=stoi(line);
        getline(file, line);
        data_nasc.dia=stoi(line);
        gerente.setDataNascimento(data_nasc);

        getline(file, line);

        getline(file, line);
        gerente.setMatricula(line);
        getline(file, line);
        gerente.setSalario(line);
        getline(file, line);
        gerente.setParticipacaoLucros(stof(line));
        getline(file, line);
        gerente.setFaltas(stoi(line));

        getline(file, line);

        Date date_ing;
        getline(file, line);
        date_ing.ano=stoi(line);
        getline(file, line);
        date_ing.mes=stoi(line);
        getline(file, line);
        date_ing.dia=stoi(line);
        gerente.setIngressoEmpresa(date_ing);

        gerentes.push_back(gerente);
        atualizarGerente();
        return;
    }
}

/**
 * \brief Calcula o valor da rescisão de um funcionário com base em sua matrícula e data de desligamento.
 *
 * \param matricula A matrícula do funcionário.
 * \param date_off A data de desligamento do funcionário.
 * \return O valor da rescisão do funcionário.
 */
float Empresa::calcularRecisao(string matricula, Date date_off)
{
    for (auto i : asgs)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisao do funcionario "<< i.getNome() <<" e: " << i.calcularRecisao(date_off) << endl;
            return i.calcularRecisao(date_off);
        }
    }
    
    for (auto i : vendedores)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisao do funcionario " << i.getNome() <<" e: "<< i.calcularRecisao(date_off) << endl;
            return i.calcularRecisao(date_off);
        }
    }
    for (auto i : gerentes)
    {
        if (i.getMatricula() == matricula)
        {
            cout << "A recisao do funcionario "<< i.getNome() <<" e: " << i.calcularRecisao(date_off) << endl;
            return i.calcularRecisao(date_off);
        }
    }
    cout << "Nao existe um funcionario com essa matricula em nosso sistema" << endl;
    return -1;
}