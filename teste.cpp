#include <iostream>
#include <vector>
#include <string>
#include <map>

//declaração de base de origem e base de destino
int baseOrigem, baseDestino;

//dicionario para mapear Resto : RestoConvertido
std::map<std::string, std::string> valores = {
    {"0", "0"},
    {"1", "1"},
    {"2", "2"},
    {"3", "3"},
    {"4", "4"},
    {"5", "5"},
    {"6", "6"},
    {"7", "7"},
    {"8", "8"},
    {"9", "9"},
    {"10", "A"},
    {"11", "B"},
    {"12", "C"},
    {"13", "D"},
    {"14", "E"},
    {"15", "F"},
    {"16", "G"},
    {"17", "H"},
    {"18", "I"},    
    {"19", "J"},
    {"20", "K"},
    {"21", "L"},
    {"22", "M"},
    {"23", "N"},
    {"24", "O"},
    {"25", "P"},
    {"26", "Q"},
    {"27", "R"},
    {"28", "S"},
    {"29", "T"},
    {"30", "U"},
    {"31", "V"}
    
};
std::vector<std::string> funcaoVetor (unsigned long long int decimal){
    
    std::vector<std::string> vetorConvertido = {"null"};
    //variavel de resto 
    unsigned long long int resto;
    //divisão inicial fora de loop para inicializar o vetor com valor valido(tirar o null)
    resto = decimal % baseDestino; 
    //funcao to_string transforma o inteiro "resto" em string para ser colocado na variavel que armazenará o resto como string
    std::string valorConvertidoString = std::to_string(resto);
    //variavel do resto (como string) é adicionada ao vetor
    vetorConvertido[0] = valores[valorConvertidoString] ;
    //cout decimal para debug
    std::cout << decimal << std::endl;
    //valor decimal é dividido para continuar operação
    decimal/=baseDestino;
    
    //enquanto decimal for maior que 0, será constantemente dividido
    //seu resto continuadamente guardado no vetorConvertido
    while (decimal > 0){
            
            //divisao do decimal para atribuir resto
            resto = decimal % baseDestino;  
            //converte o resto em uma variavel de String
            valorConvertidoString = std::to_string(resto);
            //adiciona o resto no vetor de valores convertidos
            vetorConvertido.push_back(valores[valorConvertidoString]);
            //cout decimal para debug
            std::cout << decimal << std::endl;
            //valor decimal é dividido para continuar operação
            decimal/=baseDestino;

    }
    //apos o fim do while, quando decimal chega a 0, a função retorna o vetor com os valores atribuidos
    return vetorConvertido;
}

int main() {
    //numero maximo = 18446744073709551615 (18 quintilhões)
    unsigned long long int decimal = 18293449;
    std::cout << ("Digite a base de destino: ");
    std::cin >> (baseDestino);
    //chama função que converte (função de vetor)
    std::vector <std::string> vetorConvertido = funcaoVetor (decimal);

    //iteração sobre os binarios convertidos
    std::cout << "valor convertido comeca aqui" << std::endl;
    for (int i = vetorConvertido.size()-1; i >= 0; i--){
        std::cout << vetorConvertido[i];
    }
    return 99999;
    

}
