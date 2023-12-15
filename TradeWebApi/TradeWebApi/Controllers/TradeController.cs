
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Diagnostics.HealthChecks;
using TradeWebApi.Models;
using TradeWebApi.Models.DB;
using TradeWebApi.Models.DTO;
using WebApi.Data;

namespace TradeWebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class TradeController : ControllerBase
    {
        private readonly ILogger<TradeController> _logger;
        private readonly Context _context;

        public TradeController(ILogger<TradeController> logger, Context context)
        {
            _logger = logger;
            _context = context;
        }


        [HttpGet]
        public async Task<List<AswTblTradeMonster>> GetAllTradeMonsters()
        {
            var monsters = await (from tradeMonster in _context.AswTblTradeMonsters
                                  select tradeMonster).ToListAsync();

            return monsters;
        }

        [HttpPost("BuyMonster")]
        public async Task<CommonResult<ResponseBuyMonsterDTO>> BuyMonster([FromBody] RequestBuyMonsterDTO DTO )
        {
            CommonResult<ResponseBuyMonsterDTO> rv = new CommonResult<ResponseBuyMonsterDTO>();
            var Monster = (from monster in _context.AswTblTradeMonsters
                        where DTO.Id == monster.Id
                        select monster).FirstOrDefaultAsync().Result;

            if(Monster==null)
            {
                rv.Data = null;
                rv.IsSuccess = false;
                rv.Messsage = "NotFoundEntity";
                rv.StatusCode = (int)CommonStatusCode.NotFoundEntity;
                return rv;
            }
            if(Monster.DeleteDate!=null)
            {
                rv.IsSuccess = false;
                rv.Messsage = "AlreadySold";
                rv.StatusCode = (int)CommonStatusCode.Unprocessable;

                rv.Data = new ResponseBuyMonsterDTO();
                rv.Data.MonsterId = Monster.MonsterId;
                rv.Data.Price = Monster.Price;
                rv.Data.LevelStat = Monster.LevelStat;
                rv.Data.AttackStat = Monster.AttackStat;
                rv.Data.DefenceStat = Monster.DefenceStat;
                rv.Data.SpeedStat = Monster.SpeedStat;
                rv.Data.HealthStat = Monster.HealthStat;
                rv.Data.RareStat = Monster.RareStat;
                rv.Data.PropertyStat = Monster.PropertyStat;
                rv.Data.TypeStat = Monster.TypeStat;
                rv.Data.RebirthStat = Monster.RebirthStat;
                return rv;
            }
            if (DateTime.Now>Monster.AvailableDate)
            {
                rv.IsSuccess = false;
                rv.Messsage = "PastAvailableDate";
                rv.StatusCode = (int)CommonStatusCode.Unprocessable;

                rv.Data = new ResponseBuyMonsterDTO();
                rv.Data.MonsterId = Monster.MonsterId;
                rv.Data.Price = Monster.Price;
                rv.Data.LevelStat = Monster.LevelStat;
                rv.Data.AttackStat = Monster.AttackStat;
                rv.Data.DefenceStat = Monster.DefenceStat;
                rv.Data.SpeedStat = Monster.SpeedStat;
                rv.Data.HealthStat = Monster.HealthStat;
                rv.Data.RareStat = Monster.RareStat;
                rv.Data.PropertyStat = Monster.PropertyStat;
                rv.Data.TypeStat = Monster.TypeStat;
                rv.Data.RebirthStat = Monster.RebirthStat;
                return rv;
            }
            if (Monster.OwnerUserId == DTO.BuyUserId)
            {
                rv.IsSuccess = false;
                rv.Messsage = "IdenticalUser";
                rv.StatusCode = (int)CommonStatusCode.Unprocessable;

                rv.Data = new ResponseBuyMonsterDTO();
                rv.Data.MonsterId = Monster.MonsterId;
                rv.Data.Price = Monster.Price;
                rv.Data.LevelStat = Monster.LevelStat;
                rv.Data.AttackStat = Monster.AttackStat;
                rv.Data.DefenceStat = Monster.DefenceStat;
                rv.Data.SpeedStat = Monster.SpeedStat;
                rv.Data.HealthStat = Monster.HealthStat;
                rv.Data.RareStat = Monster.RareStat;
                rv.Data.PropertyStat = Monster.PropertyStat;
                rv.Data.TypeStat = Monster.TypeStat;
                rv.Data.RebirthStat = Monster.RebirthStat;
                return rv;
            }

            Monster.DeleteDate = DateTime.Now;

            var newMail = new AswTblMail()
            {
                DeleteDate = null,
                FromUserId = DTO.BuyUserId,
                ItemId = 1,
                ItemCount = Monster.Price,
                UpdateDate = DateTime.Now
            };
            _context.Add(newMail);
            await _context.SaveChangesAsync();

            rv.Data = new ResponseBuyMonsterDTO();
            rv.Data.MonsterId = Monster.MonsterId;
            rv.Data.Price = Monster.Price;
            rv.Data.LevelStat = Monster.LevelStat;
            rv.Data.AttackStat = Monster.AttackStat;
            rv.Data.DefenceStat = Monster.DefenceStat;
            rv.Data.SpeedStat = Monster.SpeedStat;
            rv.Data.HealthStat = Monster.HealthStat;
            rv.Data.RareStat = Monster.RareStat;
            rv.Data.PropertyStat = Monster.PropertyStat;
            rv.Data.TypeStat = Monster.TypeStat;
            rv.Data.RebirthStat = Monster.RebirthStat;

            rv.IsSuccess = true;
            rv.StatusCode = (int)CommonStatusCode.Ok;

            return rv;
        }
        [HttpPost("SellMonster")]
        public async Task<CommonResult<ResponseSellMonsterDTO>> SellMonster([FromBody] RequestSellMonsterDTO DTO)
        {
            CommonResult<ResponseSellMonsterDTO> rv = new CommonResult<ResponseSellMonsterDTO>();
            _context.AswTblTradeMonsters.Add(new AswTblTradeMonster()
            {
                OwnerUserId=DTO.OwnerUserId,
                MonsterId=DTO.MonsterId,
                Price=DTO.Price,
                LevelStat = DTO.LevelStat,
                AttackStat = DTO.AttackStat,
                DefenceStat = DTO.DefenceStat,
                SpeedStat = DTO.SpeedStat,
                HealthStat= DTO.HealthStat,
                RareStat = DTO.RareStat,
                PropertyStat = DTO.PropertyStat,
                TypeStat = DTO.TypeStat,
                RebirthStat = DTO.RebirthStat
            });

            rv.IsSuccess =Convert.ToBoolean(await _context.SaveChangesAsync());
            rv.StatusCode = (int)CommonStatusCode.Ok;

            return rv;
        }
        

    }
}
