#include "Avaliador.hpp"
#include <algorithm>

void Avaliador::avalia(Leilao leilao)
{
    std::vector<Lance> lances = leilao.recuperaLances();

    for (Lance lance : lances) {
        if (lance.recuperaValor() > maiorValor) {
            maiorValor = lance.recuperaValor();
        }

        if (lance.recuperaValor() < menorValor) {
            menorValor = lance.recuperaValor();
        }
    }
    
    std::sort(lances.begin(), lances.end(), ordenaLances);
    size_t tamanho = lances.size() > 3 ? 3 : lances.size();
    maiores3Lances = std::vector<Lance>(lances.begin(), lances.begin() + tamanho);
}

float Avaliador::recuperaMaiorValor() const
{
    return maiorValor;
}

float Avaliador::recuperaMenorValor() const
{
    return menorValor;
}

std::vector<Lance> Avaliador::recupera3MaioresLances() const
{
    return maiores3Lances;
}

bool Avaliador::ordenaLances(const Lance& lance1, const Lance& lance2)
{
    return lance1.recuperaValor() > lance2.recuperaValor();
}
