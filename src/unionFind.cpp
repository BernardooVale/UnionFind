#include "unionFind.hpp"
#include <iostream>

UnionFind::UnionFind(int quant) {

	this->tamanho = quant;
	this->subconjuntos = new Subconjunto[quant];
}

UnionFind::~UnionFind() {

	delete[] this->subconjuntos;
	this->subconjuntos = nullptr;
}

void UnionFind::Make(int rep){

	this->subconjuntos[rep].representante = rep;
	this->subconjuntos[rep].rank = 1;
}

int UnionFind::Find(int id) {

	return this->tamanho;
}

bool UnionFind::Union(int id1, int id2) {
	
	int rankT = 0;

	if (this->subconjuntos[id1].representante != this->subconjuntos[id2].representante) {

		rankT = this->subconjuntos[id1].rank + this->subconjuntos[id2].rank;

		if (this->subconjuntos[id1].rank >= this->subconjuntos[id2].rank) {

			this->subconjuntos[id2].representante = this->subconjuntos[id1].representante;
		}
		else {
			this->subconjuntos[id1].representante = this->subconjuntos[id2].representante;
		}
		
		this->subconjuntos[id1].rank = rankT;
		this->subconjuntos[id2].rank = rankT;
		
		this->tamanho--;
		return true;
	}
	return false;
}