#include <iostream>
#include <vector>
#include <string>
#include <map>
int baseOrigem, baseDestino;

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
    {"16", "H"},
    {"17", "I"},    
    {"18", "J"},
    {"19", "K"},
    {"20", "L"},
    {"21", "M"},
    {"22", "N"},
    {"23", "O"},
    {"24", "P"},
    {"25", "Q"},
    {"26", "R"},
    {"27", "S"},
    {"28", "T"},
    {"29", "U"},
    {"30", "V"},
    {"31", "W"},
    {"32", "X"}
    
};
std::vector<std::string> funcaoVetor (unsigned long long int decimal){
    
    std::vector<std::string> vetorConvertido = {"null"};
    unsigned long long int resto;
    //divisão inicial fora de loop para substituir valor de definição do vetorConvertido
    resto = decimal % baseDestino; 
    std::string valorConvertidoString = std::to_string(resto);
    vetorConvertido[0] = valores[valorConvertidoString] ;
    std::cout << decimal << std::endl;
    decimal/=baseDestino;
    
    //enquanto decimal for maior que 0, será constantemente dividido
    //seu resto continuadamente guardado no vetorConvertido
    while (decimal > 0){
            
            resto = decimal % baseDestino;  
            valorConvertidoString = std::to_string(resto);
            vetorConvertido.push_back(valores[valorConvertidoString]);
            std::cout << decimal << std::endl;
            decimal/=baseDestino;

    }
    return vetorConvertido;
}

int main() {
    //numero maximo = 18446744073709551615 (18 quintilhões)
    unsigned long long int decimal = 18293449;
    std::cout << ("Digite a base de destino: ");
    std::cin >> (baseDestino);
    std::vector <std::string> vetorConvertido = funcaoVetor (decimal);

    //iteração sobre os binarios convertidos
    std::cout << "valor convertido comeca aqui" << std::endl;
    
    for (int i = vetorConvertido.size()-1; i >= 0; i--){
        std::cout << vetorConvertido[i];
    }
    return 2311;
    

}
