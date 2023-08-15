using AgWeb.Models;
using Microsoft.EntityFrameworkCore;

using Microsoft.EntityFrameworkCore;

namespace AgWeb.Models
{
    public class AppDbContext : DbContext
    {
        public DbSet<Cliente> Agendamentos { get; set; }

        public AppDbContext(DbContextOptions<AppDbContext> options) : base(options)
        {
        }
    }
}
