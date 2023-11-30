using Microsoft.AspNetCore.Mvc;
using WebApi.Models;

namespace WebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class WeatherForecastController : ControllerBase
    {
        private static readonly string[] Summaries = new[]
        {
            "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
        };

        private readonly ILogger<WeatherForecastController> _logger;

        public WeatherForecastController(ILogger<WeatherForecastController> logger)
        {
            _logger = logger;
        }

        [HttpGet(Name = "GetWeatherForecast")]
        //[HttpGet("get")]
        //[Route("[controller]/get")]
        public IEnumerable<WeatherForecast> Get()
        {
            /*
            return Enumerable.Range(1 , 5).Select(index => new WeatherForecast
            {
                Date = DateOnly.FromDateTime(DateTime.Now.AddDays(index)) ,
                TemperatureC = Random.Shared.Next(-20 , 55) ,
                Summary = Summaries[Random.Shared.Next(Summaries.Length)]
            })
            .ToArray();
            */
            List<WeatherForecast> weathers = new List<WeatherForecast>();
            Random random = new Random();
            for (int i = 0; i < 10; i++)
            {
                WeatherForecast weather = new WeatherForecast()
                {
                    Date = DateOnly.FromDateTime(DateTime.Now) ,
                    Summary = $"{i}" ,
                    TemperatureC = random.Next(10 , 20)
                };
                weathers.Add(weather);
            }
            return weathers;
        }
    }
}
