using Dado = char;

class Pilha
{
    private:
        enum { MAX = 2};
        Dado dados[MAX];
        int indice;

    
    public:
        Pilha();

        bool Vazia() const;
        bool Cheia() const;

        bool Empilhar(const Dado & dado);
        bool Desempilhar(Dado & dado);
}
