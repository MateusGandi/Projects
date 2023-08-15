using AgWeb.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.Data.SqlClient;
using System.Threading.Tasks;

namespace AgWeb.Controllers
{
    public class ClientesController : Controller
    {
        private readonly AppDbContext _dbContext;
        public ClientesController(AppDbContext dbContext)
        {
            _dbContext = dbContext;
        }

        [HttpPost]
        public async Task<IActionResult> AddAgendamento(Cliente cliente)
        {
            try
            {
                    _dbContext.Agendamentos.Add(cliente);
                    await _dbContext.SaveChangesAsync();

                return RedirectToAction("Index", "Home", new { horario = cliente.Horario, data = cliente.Data });
            }
            catch (Exception ex)
            {
                // Redirecionar de volta para a página de agendamento com a mensagem de erro
                return RedirectToAction("Index", "Home", new { aviso = "Error" });
            }

        }

        [HttpPost]
        public async Task<IActionResult> ExcluirAgendamento(int id)
        {
            var agendamento = await _dbContext.Agendamentos.FindAsync(id);

            if (agendamento != null)
            {
        
                _dbContext.Agendamentos.Remove(agendamento);
                await _dbContext.SaveChangesAsync();
                    
            }

            return RedirectToAction("Agendamentos", "Home");
        }
    }
}