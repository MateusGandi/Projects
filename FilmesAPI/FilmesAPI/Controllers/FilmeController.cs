using Microsoft.AspNetCore.Mvc;
using FilmesAPI.Models;

namespace FilmesAPI.Controllers
{
    [ApiController]
    [Route("[Controller]")]
    public class FilmeController : ControllerBase
    {
        private static List<Filme> filmes = new List<Filme>();
        [HttpPost]
        public void adcionarFilme([FromBody] Filme filme)
        {
            filmes.Add(filme);
            Console.WriteLine("APsee");
        }
    }
}
