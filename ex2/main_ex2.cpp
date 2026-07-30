#include "analise.hpp"
#include <iostream>
#include <iomanip>

int main() {
    saldo_t s = {
        4.1f, 9.5f, 6.1f,
        -3.5f, 11.1f, 8.1f,
        5.1f, 7.1f, -2.1f
    };

    std::cout << std::fixed << std::setprecision(3);

    std::cout << "movimento: " << maior_movimento(s) << "\n";
    std::cout << "giro: " << giro_medio(s) << "\n";

    auto norm = normalizar(s);
    std::cout << "norm[4]: " << norm[4] << "\n";

    auto intensos = dias_intensos(s);
    std::cout << "intensos: " << intensos.size() << "\n";

    std::cout << "inversoes: " << inversoes(s) << "\n";

    return 0;
}
