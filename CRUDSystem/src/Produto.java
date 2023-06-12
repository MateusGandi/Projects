class Produto {
    private static int id = 1;
    private String nome;
    private int quantidade;
    private double preco;
    private double custoProducao;
    private String fornecedor;

    public Produto(String nome, int quantidade, double preco, double custoProducao, String fornecedor) {
        this.id = getId();
        this.nome = nome;
        this.quantidade = quantidade;
        this.preco = preco;
        this.custoProducao = custoProducao;
        this.fornecedor = fornecedor;
    }

    public int getId() {
        return id++;
    }

    public String getNome() {
        return nome;
    }

    public int getQuantidade() {
        return quantidade;
    }

    public double getPreco() {
        return preco;
    }

    public double getCustoProducao() {
        return custoProducao;
    }

    public String getFornecedor() {
        return fornecedor;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setQuantidade(int quantidade) {
        this.quantidade = quantidade;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public void setCustoProducao(double custoProducao) {
        this.custoProducao = custoProducao;
    }

    public void setFornecedor(String fornecedor) {
        this.fornecedor = fornecedor;
    }

}