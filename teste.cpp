#include <iostream>
#include <vector>
#include <string>


std::vector<std::string> funcaoVetor (unsigned long long int decimal){
    
    std::vector<std::string> vetorConvertido = {"null"};
    unsigned long long int resto;
    //divisão inicial fora de loop para substituir valor de definição do vetorConvertido
    resto = decimal % 2; 
    std::string valorBinario = std::to_string(resto);
    vetorConvertido[0] = valorBinario ;
    std::cout << decimal << std::endl;
    decimal/=2;
    
    //enquanto decimal for maior que 0, será constantemente dividido
    //seu resto continuadamente guardado no vetorConvertido
    while (decimal > 0){
            
            resto = decimal % 2;  
            valorBinario = std::to_string(resto);
            vetorConvertido.push_back(valorBinario);
            std::cout << decimal << std::endl;
            decimal/=2;

    }
    return vetorConvertido;
}

int main() {
    //numero maximo = 18446744073709551615 (18 quintilhões)
    unsigned long long int decimal = 184467440726178461;
    std::vector <std::string> vetorConvertido = funcaoVetor (decimal);

    //iteração sobre os binarios convertidos
    std::cout << "binario comeca aqui" << std::endl;
    for (int i = 0; i < vetorConvertido.size(); i++){
        std::cout << vetorConvertido[i]<< std::endl;
    }
    return 2311;
    

}
