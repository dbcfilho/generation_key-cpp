#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

// Função para gerar uma senha aleatória
std::string gerarSenha(int comprimento) {
    const std::string caracteresPermitidos = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+";
    const int tamanho = caracteresPermitidos.length();
    std::string senha;

    // Inicializa o gerador de números aleatórios com o tempo atual
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < comprimento; ++i) {
        int indiceAleatorio = std::rand() % tamanho;
        senha += caracteresPermitidos[indiceAleatorio];
    }

    return senha;
}

int main() {
    int comprimento;

    // Solicita ao usuário o comprimento da senha desejada
    std::cout << "Digite o comprimento da senha: ";
    std::cin >> comprimento;

    if (comprimento <= 0) {
        std::cout << "Comprimento inválido. Por favor, insira um número positivo." << std::endl;
        return 1; // Saída com erro
    }

    std::string senhaGerada = gerarSenha(comprimento);

    // Exibe a senha gerada
    std::cout << "Senha gerada: " << senhaGerada << std::endl;

    return 0; // Saída bem-sucedida
}
