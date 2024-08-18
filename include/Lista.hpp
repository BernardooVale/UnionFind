#ifndef Lista_HPP
#define Lista_HPP

#include "Celula.hpp"

class Lista{

public:

	Lista();
	~Lista();

	void adCelula(Celula* nova);
	Celula* remove();

private:

	Celula* cabeca;

};

#endif