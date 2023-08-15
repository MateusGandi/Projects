using AgWeb.Models;
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Logging;
using System.Diagnostics;

namespace AgWeb.Controllers
{
    public class HomeController : Controller
    {
        private readonly ILogger<HomeController> _logger;
        private readonly AppDbContext _dbContext;

        public HomeController(ILogger<HomeController> logger, AppDbContext dbContext)
        {
            _logger = logger;
            _dbContext = dbContext;
        }

        public IActionResult Index()
        {
            if (Request.Cookies.TryGetValue("AgendamentoId", out string agendamentoId))
            {
                if (int.TryParse(agendamentoId, out int id))
                {
                    var agendamento = _dbContext.Agendamentos.Find(id);
                    if (agendamento != null)
                    {
                        ViewBag.Agendamento = agendamento;
                    }
                }
            }
            return View();
        }

        //public IActionResult Agendamentos()
        //{
        //    return View();
        //}

        public IActionResult Agendamentos()
        {
            List<Cliente> prov = new List<Cliente>();
            var agendamentos = _dbContext.Agendamentos.ToList();
            if (agendamentos.Count > 0)
            {
                return View(agendamentos);
            }
            else
            {
                prov.Add(new Cliente { Nome = "Olá, bom dia!", Horario = "Nenhum agendamento ainda..." });
                return View(prov);
            }
                
        }//
            


        [ResponseCache(Duration = 0, Location = ResponseCacheLocation.None, NoStore = true)]
        public IActionResult Error()
        {
            return View(new ErrorViewModel { RequestId = Activity.Current?.Id ?? HttpContext.TraceIdentifier });
        }//

    }
}
