#include "frota.hpp"
#include <iostream>
#include <iomanip>

int main() {
    frota reg;

    reg.registrar("ABC1D23", 150.f);
    reg.registrar("XYZ9K88", 320.f);
    reg.registrar("QRS4T21", 90.f);
    reg.registrar("JKL2M55", 210.f);
    reg.registrar("PLACA00", 120.f);

    std::cout << std::fixed << std::setprecision(1);

    // Duplicado
    try {
        reg.registrar("ABC1D23", 99.f);
    } catch (const veiculo_duplicado& e) {
        std::cout << e.what() << "\n";
    }

    // Busca
    auto g = reg.buscar("JKL2M55");
    std::cout << g.value_or(-1.f) << "\n";
    std::cout << reg.buscar("xxx").value_or(-1.f) << "\n";

    // Top 3
    for (auto [placa, diaria] : reg.top_n(3)) {
        std::cout << placa << ": " << diaria << "\n";
    }

    reg.remover("XYZ9K88");
    std::cout << reg.tamanho() << "\n";

    return 0;
}
