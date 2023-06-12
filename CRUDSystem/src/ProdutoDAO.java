import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
//Objetivo principal é organizar as principais funções do CRUD e organziar para se comunicar com banco de dados
class ProdutoDAO {
    private List<Produto> produtos;
    private ConnectionFactory connection;
    public ProdutoDAO() {
        produtos = new ArrayList<>();
        this.connection = new ConnectionFactory();
    }

    public void adicionarProduto(Produto produto) throws ClassNotFoundException {
        String sql = "INSERT INTO produto(nome, quantidade, preco, custoProducao, fornecedor)"+
                "VALUES (?,?,?,?,?)";

        Connection conn = connection.recuperarConexão();
        try {
            PreparedStatement preparedStatement = conn.prepareStatement(sql);

            preparedStatement.setString(1,produto.getNome());
            preparedStatement.setDouble(2,produto.getQuantidade());
            preparedStatement.setDouble(3,produto.getPreco());
            preparedStatement.setDouble(4,produto.getCustoProducao());
            preparedStatement.setString(5,produto.getFornecedor());
            preparedStatement.execute();
            System.out.println("adicionado com sucesso!");

        }catch (SQLException e){
            throw  new RuntimeException(e);
        }
        produtos.add(produto);
    }

    public void atualizarProduto(Produto produto) {
        for (Produto prod : produtos) {
            if (prod.getId() == produto.getId()) {
                prod.setNome(produto.getNome());
                prod.setQuantidade(produto.getQuantidade());
                prod.setPreco(produto.getPreco());
                prod.setCustoProducao(produto.getCustoProducao());
                prod.setFornecedor(produto.getFornecedor());
                break;
            }
        }
    }
    public void removerProduto(int id) {
        produtos.removeIf(prod -> prod.getId() == id);
    }

    public Produto buscarProduto(int id) {
        for (Produto prod : produtos) {
            if (prod.getId() == id) {
                return prod;
            }
        }
        return null;
    }

    public List<Produto> listarProdutos() {
        return produtos;
    }
}