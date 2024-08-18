#ifndef Celula_HPP
#define Celula_HPP

#include "unionFind.hpp"

class Celula{

public:

	Celula(Aresta* nova);
	~Celula();

	void adCelula(Celula* nova);
	void setProx(Celula* prox);
	Celula* pegaProx();

	int pegaOrigem();
	int pegaDestino();
	int pegaCusto();

private:

	Aresta* aresta;
	Celula* prox;
};

#endif