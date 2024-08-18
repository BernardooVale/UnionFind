#include <iostream>
#include "Celula.hpp"
#include "Lista.hpp"
#include "unionFind.hpp"

int main() {

	int num_vertices, num_arestas, custoT = 0;
	bool msmGrupo = false;
	Lista* arestas = new Lista();

	std::cin >> num_vertices >> num_arestas;

	UnionFind conjuntos = UnionFind(num_vertices);

	for (int i = 0; i < num_vertices; i++) {
		conjuntos.Make(i);
	}

	for (int i = 0; i < num_arestas; i++) {
		Aresta* auxA = new Aresta;

		std::cin >> auxA->u >> auxA->v >> auxA->custo;

		Celula* auxC = new Celula(auxA);
		arestas->adCelula(auxC);
	}

	while (conjuntos.Find(1) != 1) {
		Celula* auxC = arestas->remove();

		msmGrupo = conjuntos.Union(auxC->pegaOrigem(), auxC->pegaDestino());
		if (msmGrupo) { custoT += auxC->pegaCusto(); }

		auxC->setProx(nullptr);
		delete auxC;
		auxC = nullptr;
	}
	
	std::cout << custoT << std::endl;

	delete arestas;
	arestas = nullptr;
	conjuntos.~UnionFind();
}