using Microsoft.AspNetCore.Mvc;

namespace TradeWebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class TradeController : Controller
    {
        private readonly ILogger<TradeController> _logger;
        public TradeController(ILogger<TradeController> logger)
        {
            _logger = logger;
        }
    }
}
