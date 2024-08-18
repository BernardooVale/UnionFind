#include "Lista.hpp"
#include <iostream>

Lista::Lista() {

	this->cabeca = nullptr;
}

Lista::~Lista() {

	delete this->cabeca;
	this->cabeca = nullptr;
}

void Lista::adCelula(Celula* nova) {

	if (this->cabeca == nullptr) {
		this->cabeca = nova;
	} else if (this->cabeca->pegaCusto() > nova->pegaCusto()) {
		nova->setProx(this->cabeca);
		this->cabeca = nova;
	}
	else {
		this->cabeca->adCelula(nova);
	}

}

Celula* Lista::remove() {

	Celula* aux = this->cabeca;
	this->cabeca = this->cabeca->pegaProx();

	return aux;
}