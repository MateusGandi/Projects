import java.util.List;
import java.util.Scanner;

public class Application {
    public static void main(String[] args) throws ClassNotFoundException {
        Scanner scanner = new Scanner(System.in);
        ProdutoDAO produtoDAO = new ProdutoDAO();

        while (true) {
            System.out.println("KanCodeSystems - Gerenciamento de Estoque");
            System.out.println("Selecione uma opção:");
            System.out.println("[1]Adicionar produto");
            System.out.println("[2]Atualizar produto");
            System.out.println("[3]Remover produto");
            System.out.println("[4]Buscar produto");
            System.out.println("[5]Listar produtos");
            System.out.println("[6]Sair");
            System.out.println("[7]Sobre a KanCode");

            //System.out.println("[6]Listar produtos com ordem de prioridade");
            //System.out.println("[7]Listar produtos em com maior potencial de venda");
            //System.out.println("[8]Gráfico de vendas");


            int opcao = scanner.nextInt();
            scanner.nextLine(); // clear no buffer do scanner

            switch (opcao) {
                case 1:
                    System.out.println("Digite o nome do produto:");
                    String nome = scanner.nextLine();

                    System.out.println("Digite a quantidade:");
                    int quantidade = scanner.nextInt();

                    System.out.println("Digite o preço:");
                    double preco = scanner.nextDouble();

                    System.out.println("Digite o custo de produção:");
                    double custoProducao = scanner.nextDouble();

                    System.out.println("Digite o fornecedor:");
                    scanner.nextLine();
                    String fornecedor = scanner.nextLine();

                    Produto novoProduto = new Produto(nome, quantidade, preco, custoProducao, fornecedor);
                    produtoDAO.adicionarProduto(novoProduto);
                    System.out.println("Produto adicionado com sucesso!");
                    break;

                case 2:
                    System.out.println("Digite o ID do produto que deseja atualizar:");
                    int idAtualizar = scanner.nextInt();
                    Produto produtoAtualizar = produtoDAO.buscarProduto(idAtualizar);

                    if (produtoAtualizar != null) {
                        System.out.println("Digite o novo nome do produto:");
                        scanner.nextLine();
                        String novoNome = scanner.nextLine();
                        produtoAtualizar.setNome(novoNome);

                        System.out.println("Digite a nova quantidade:");
                        int novaQuantidade = scanner.nextInt();
                        produtoAtualizar.setQuantidade(novaQuantidade);

                        System.out.println("Digite o novo preço:");
                        double novoPreco = scanner.nextDouble();
                        produtoAtualizar.setPreco(novoPreco);

                        System.out.println("Digite o novo custo de produção:");
                        double novoCustoProducao = scanner.nextDouble();
                        produtoAtualizar.setCustoProducao(novoCustoProducao);

                        System.out.println("Digite o novo fornecedor:");
                        scanner.nextLine();
                        String novoFornecedor = scanner.nextLine();
                        produtoAtualizar.setFornecedor(novoFornecedor);

                        produtoDAO.atualizarProduto(produtoAtualizar);
                        System.out.println("Produto atualizado com sucesso!");
                    } else {
                        System.out.println("Produto não encontrado.");
                    }
                    break;

                case 3:
                    System.out.println("Digite o ID do produto que deseja remover:");
                    int idRemover = scanner.nextInt();
                    produtoDAO.removerProduto(idRemover);
                    System.out.println("Produto removido com sucesso!");
                    break;

                case 4:
                    System.out.println("Digite o ID do produto que deseja buscar:");
                    int idBuscar = scanner.nextInt();
                    Produto produtoBusca = produtoDAO.buscarProduto(idBuscar);

                    if (produtoBusca != null) {
                        System.out.println("Resultado:");
                        System.out.println("ID: " + produtoBusca.getId());
                        System.out.println("Nome: " + produtoBusca.getNome());
                        System.out.println("Quantidade: " + produtoBusca.getQuantidade());
                        System.out.println("Preço: " + produtoBusca.getPreco());
                        System.out.println("Custo de Produção: " + produtoBusca.getCustoProducao());
                        System.out.println("Fornecedor: " + produtoBusca.getFornecedor());
                    } else {
                        System.out.println("Produto não encontrado.");
                    }
                    break;

                case 5:
                    List<Produto> produtos = produtoDAO.listarProdutos();
                    if (produtos.isEmpty()) {
                        System.out.println("Nenhum produto cadastrado.");
                    } else {
                        System.out.println("Lista de produtos:");
                        for (Produto p : produtos) {
                            System.out.println("ID: " + p.getId());
                            System.out.println("Nome: " + p.getNome());
                            System.out.println("Quantidade: " + p.getQuantidade());
                            System.out.println("Preço: " + p.getPreco());
                            System.out.println("Custo de Produção: " + p.getCustoProducao());
                            System.out.println("Fornecedor: " + p.getFornecedor());
                            System.out.println("-------------------------+");
                        }
                    }
                    break;

                case 6:
                    System.out.println("Grato por usar nosso sistema");
                    System.exit(0);
                    break;
                case 7:
                    System.out.println("Codenome para substituir Mateus Henrique em projetos voltados ao meio comercial!");
                    System.exit(0);
                    break;

                default:
                    System.out.println("Opção inválida. Digite outra!");
                    break;
            }
        }
    }
}
