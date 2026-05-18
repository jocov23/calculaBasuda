#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

//declaração de base de origem e base de destino
int baseOrigem, baseDestino;
std::string valor;
std::string caracteresEspeciais ="-+_!@#$%¨&*(){}[]<>:;?^~´`.|'"",\\";
std::string caractereInvalido = "";

//dicionario para mapear Resto : RestoConvertido
// std::map<std::string, std::string> valores = {
//     {"0", "0"}, {"1", "1"},{"2", "2"},{"3", "3"},{"4", "4"},{"5", "5"},{"6", "6"},{"7", "7"},
//     {"8", "8"},{"9", "9"},{"10", "A"},{"11", "B"},{"12", "C"},{"13", "D"},{"14", "E"},
//     {"15", "F"},{"16", "G"},{"17", "H"},{"18", "I"},{"19", "J"},{"20", "K"},{"21", "L"},
//     {"22", "M"},{"23", "N"},{"24", "O"},{"25", "P"},{"26", "Q"},{"27", "R"},{"28", "S"},
//     {"29", "T"},{"30", "U"},{"31", "V"}
    
// };
std::string valores = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
//dicionario para mapear RestoConvertido : Resto
std::map<std::string, std::string> valoresInverso = {
    {"0", "0"}, {"1", "1"},{"2", "2"},{"3", "3"},{"4", "4"},{"5", "5"},{"6", "6"},{"7", "7"},
    {"8", "8"},{"9", "9"},{"A", "10"},{"B", "11"},{"C", "12"},{"D", "13"},{"E", "14"},
    {"F", "15"},{"G", "16"},{"H", "17"},{"I", "18"},{"J", "19"},{"K", "20"},{"L", "21"},
    {"M", "22"},{"N", "23"},{"O", "24"},{"P", "25"},{"Q", "26"},{"R", "27"},{"S", "28"},
    {"T", "29"},{"U", "30"},{"V", "31"}
    
};

///std::vector<int> funcaoVetorParadecimal()
//{
   // return 0;
//}
unsigned long long int funcaoParaDecimal (std::string valor, int baseOrigem){
    int valorDecimal=0;
    int expoente = valor.size()-1;
    for (int i = 0; i< valor.size(); i++){
        char valorChar = valor[i];
        std::string valorString(1, valorChar);
        std::string caractereConvertido = valoresInverso[valorString];
        int inteiroCaractere = std::stoi(caractereConvertido);
        valorDecimal+= inteiroCaractere * (std::pow(baseOrigem, expoente));
        //std::cout << valorDecimal << std::endl;
        expoente-=1;

    }

    return valorDecimal;
}


std::vector<std::string> funcaoVetorDoDecimal (unsigned long long int valorDecimal){
    
    std::vector<std::string> valoresConvertidosDoDecimal = {"null"};
    //variavel de resto 
    unsigned long long int resto;
    //divisão inicial fora de loop para inicializar o vetor com valor valido(tirar o null)
    resto = valorDecimal% baseDestino; 
    //funcao to_string transforma o inteiro "resto" em string e atribui a variavel restoString
    std::string restoString = std::to_string(resto);
    //variavel do resto (como string) é adicionada ao vetor
    valoresConvertidosDoDecimal[0] = std::string(1, valores[resto]);
    //cout decimal para debug

    //std::cout << valorDecimal << std::endl;

    //valor decimal é dividido para continuar operação
    valorDecimal/=baseDestino;
    
    //enquanto decimal for maior que 0, será constantemente dividido
    //seu resto continuadamente guardado no vetorConvertido
    while (valorDecimal > 0){
            
            //divisao do decimal para atribuir resto
            resto = valorDecimal % baseDestino;  
            //converte o resto em uma variavel de String
            restoString = std::to_string(resto);
            //adiciona o resto no vetor de valores convertidos
            valoresConvertidosDoDecimal.push_back(std::string(1, valores[resto]));
            //cout decimal para debug

            //std::cout << valorDecimal << std::endl;

            //valor decimal é dividido para continuar operação
            valorDecimal/=baseDestino;

    }
    //apos o fim do while, quando decimal chega a 0, a função retorna o vetor com os valores atribuidos
    return valoresConvertidosDoDecimal;
}

int main() {
    //numero maximo = 18446744073709551615 (18 quintilhões)
    unsigned long long int valorDecimal;
    int parar = 0;
    //ciclo de repetição
    while (true) {
        std::string caractereInvalido = "";
        std::cout << ("Digite a base de Origem[2-32] ou '1' para sair: ");
        std::cin >> (baseOrigem);
        //termino do programa
        if (baseOrigem == 1){
            std::cout << ("Encerrando o programa..");
            break;
        }
        //validacao de base valida
        if (baseOrigem < 2 || baseOrigem > 32) {
        std::cout << "\nERRO: Base de origem invalida (deve ser entre 2 e 32)!\n\n" << std::endl;
        continue; 
        }
        
        std::cout << ("Digite a base de destino: ");
        std::cin >> (baseDestino);
        //validacao de base valida
        if (baseDestino < 2 || baseDestino > 32) {
            std::cout << "ERRO: Base de destino invalida (deve ser entre 2 e 32)!" << std::endl;
            continue; 
        }
        
        std::cout << "Digite o numero para converter: ";
        std::cin >> valor;
        
        //range loop que modifica cada caractere da string 'valor' para uppercase
        for (char& caractere : valor){
            caractere = std::toupper(static_cast<unsigned char>(caractere));
        }
        
        //validação de valor inserido pelo usuario
        for (int i = baseOrigem; i < 32; i++ ){
            std::string numeroString = std::to_string(i);
            caractereInvalido += valores[i];
        }
        if (valor.find_first_of(caracteresEspeciais) != std::string::npos){
                std::cout << ("\n\nInsira um valor valido sem caracteres especiais!\n\n");
                continue;
        }else if(valor.find_first_of(caractereInvalido) != std::string::npos){
            std::cout << ("\n\nInsira um valor valido da base de origem!\n\n");
            continue;
        }
        
        
        if (baseOrigem == 10){
            //converte a string de valores para unsigned long long int
            valorDecimal = std::stoull(valor);
            //atribui valores ao vetor de numeros convertidos
            std::vector <std::string> valoresConvertidosDodecimal = funcaoVetorDoDecimal (valorDecimal);
            //itera sobre os valores convertidos e mostra no terminal
            std::cout << "valor convertido comeca aqui" << std::endl;
            for (int i = valoresConvertidosDodecimal.size()-1; i >= 0; i--){
                std::cout << valoresConvertidosDodecimal[i];
            }
            std::cout << ("\n\n\n");
        
        }else{
            valorDecimal = funcaoParaDecimal(valor, baseOrigem);
            std::vector <std::string> valoresConvertidosDodecimal = funcaoVetorDoDecimal (valorDecimal);
            //itera sobre os valores convertidos e mostra no terminal
            std::cout << "valor convertido comeca aqui" << std::endl;
            for (int i = valoresConvertidosDodecimal.size()-1; i >= 0; i--){
                std::cout << valoresConvertidosDodecimal[i];
            }
            std::cout << ("\n\n\n");
        }
    
        
    }
    return 0;
}

