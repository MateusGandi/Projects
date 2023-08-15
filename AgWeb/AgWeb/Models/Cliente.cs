using Microsoft.Extensions.Options;
using System.ComponentModel.DataAnnotations;

namespace AgWeb.Models
{
    public class Cliente
    {
        public bool Problemas = false;
        private string _servico = "Mateus";
        public int Id { get; set; }
        public string Nome { get; set; }
        public string Descricao { get; set; }
        public string Data { get; set; }
        public string Horario { get; set; }
        public string Servico { get; set;}
    }
}
