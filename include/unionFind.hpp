#ifndef UnionFind_HPP
#define UnionFind_HPP

typedef struct s_edge {
    int u = -1;
    int v = -1;
    int custo = -1;
} Aresta;
typedef struct s_subset {
    int representante = -1;
    int rank = -1;
} Subconjunto;

class UnionFind {
public:
    UnionFind(int quantidade_subconjuntos);
    ~UnionFind();
    void Make(int x);
    int Find(int x);
    bool Union(int x, int y);
private:
    int tamanho;
    Subconjunto* subconjuntos;
};

#endif