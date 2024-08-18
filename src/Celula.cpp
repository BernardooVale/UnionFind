#include "Celula.hpp"
#include <iostream>

Celula::Celula(Aresta* nova) {

	this->aresta = nova;
	this->prox = nullptr;

}

Celula::~Celula() {

	delete this->prox;
	this->prox = nullptr;
	delete this->aresta;
	this->aresta = nullptr;
}

void Celula::setProx(Celula* prox) {
	this->prox = prox;
}

void Celula::adCelula(Celula* nova) {

	if (this->prox == nullptr) {
		this->prox = nova;
	}
	else if (this->prox->pegaCusto() > nova->pegaCusto()) {
		nova->setProx(this->prox);
		this->prox = nova;
	}
	else {
		this->prox->adCelula(nova);
	}
}

int Celula::pegaCusto() { return this->aresta->custo; }
int Celula::pegaOrigem() { return this->aresta->u; }
int Celula::pegaDestino() { return this->aresta->v; }
Celula* Celula::pegaProx() { return this->prox; }