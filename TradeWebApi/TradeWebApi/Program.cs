
using Microsoft.EntityFrameworkCore;
using TradeWebApi.Services;
using WebApi.Data;

namespace TradeWebApi
{
    public class Program
    {
        public static void Main(string[] args)
        {
            var builder = WebApplication.CreateBuilder(args);

            // Add services to the container.

            builder.Services.AddControllers();
            // Learn more about configuring Swagger/OpenAPI at https://aka.ms/aspnetcore/swashbuckle
            builder.Services.AddEndpointsApiExplorer();
            builder.Services.AddSwaggerGen();

            builder.Services.AddScoped<IMailService, MailService>();
            builder.Services.AddScoped<IMonsterService, MonsterService>();

            //var connectionString1 = builder.Configuration["ConnectionStrings:TradeDB"];
            var connectionString = builder.Configuration.GetConnectionString("TradeDB");
            builder.Services.AddDbContext<Context>(options => options.UseMySql(
                connectionString, 
                ServerVersion.AutoDetect(connectionString)));
            

            var app = builder.Build();

            // Configure the HTTP request pipeline.
            if (app.Environment.IsDevelopment())
            {
                app.UseSwagger();
                app.UseSwaggerUI();
            }

            app.UseHttpsRedirection();

            app.UseAuthorization();


            app.MapControllers();

            app.Run();
        }
    }
}
