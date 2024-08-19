#include "catch2/catch.hpp"
#include "Avaliador.hpp"

Leilao emOrdemCrescente()
{
    Lance primeiroLance(Usuario("Bruno Winkeler"), 1000);
    Lance segundoLance(Usuario("Ana Maria"), 2000);
    Leilao leilao("Fiat 147 0Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    
    return leilao;
}

Leilao emOrdemDecrescente()
{
    Lance primeiroLance(Usuario("Bruno Winkeler"), 2000);
    Lance segundoLance(Usuario("Ana Maria"), 1000);
    Leilao leilao("Fiat 147 0Km");
    leilao.recebeLance(primeiroLance);
    leilao.recebeLance(segundoLance);
    
    return leilao;
}

TEST_CASE("Avaliador") {
    // Arrange - Given
    Avaliador avaliador;
    
    SECTION("Leilões ordenados") {
        Leilao leilao = GENERATE(emOrdemCrescente(), emOrdemDecrescente());

        SECTION("Deve recuperar maior lance de leilão") {
            // Act - When
            avaliador.avalia(leilao);

            // Assert - Then
            REQUIRE(2000 == avaliador.recuperaMaiorValor());
        }

        SECTION("Deve recuperar menor lance de leilão") {
            // Act - When
            avaliador.avalia(leilao);

            // Assert - Then
            REQUIRE(1000 == avaliador.recuperaMenorValor());
        }
    }

    SECTION("Deve recuperar os 3 maiores lances") {
        // Arrange - Given
        Lance primeiroLance(Usuario("Bruno Winkeler"), 1000);
        Lance segundoLance(Usuario("Ana Maria"), 2000);
        Lance terceiroLance(Usuario("Pedro Paulo"), 1500);
        Lance quartoLance(Usuario("Patricia Roberta"), 2500);
        
        Leilao leilao("Fiat 147 0Km");
        leilao.recebeLance(primeiroLance);
        leilao.recebeLance(segundoLance);
        leilao.recebeLance(terceiroLance);
        leilao.recebeLance(quartoLance);

        // Act - When
        avaliador.avalia(leilao);

        // Assert - Then
        auto maiores3Lances = avaliador.recupera3MaioresLances();
        REQUIRE(3 == maiores3Lances.size());
        REQUIRE(2500 == maiores3Lances[0].recuperaValor());
        REQUIRE(2000 == maiores3Lances[1].recuperaValor());
        REQUIRE(1500 == maiores3Lances[2].recuperaValor());
    }
}
