#include "ficha.hpp"
#include <iostream>

int main() {
    ficha f(
        "placa ABC1D23\n"
        "diaria 150\n"
        "categoria=SUV\n"
    );

    // Versão estrita
    std::cout << f.ler("placa") << "\n";
    std::cout << f.ler_int("diaria") << "\n";

    // Captura em cascata
    try {
        f.ler("inexistente");
    } catch (const campo_error& e) {
        std::cout << e.what() << "\n";
    } catch (const locadora_error& e) {
        std::cout << "locadora: " << e.what() << "\n";
    }

    try {
        f.ler_int("categoria");
    } catch (const tipo_error& e) {
        std::cout << e.what() << "\n";
    }

    // Versão segura
    auto p = f.ler_seguro("placa");
    std::cout << p.value_or("N/A") << "\n";

    auto x = f.ler_int_seguro("xxx");
    std::cout << x.value_or(-1) << "\n";

    return 0;
}
