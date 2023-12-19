
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Diagnostics.HealthChecks;
using Newtonsoft.Json;
using System.Dynamic;
using TradeWebApi.Models;
using TradeWebApi.Models.DB;
using TradeWebApi.Models.DTO;
using TradeWebApi.Utility;
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
        [HttpGet("GetMonsters")]
        public async Task<CommonResult<ResponseGetMonsterDTO>> GetMonsters(RequestGetMonsterDTO DTO)
        {
            CommonResult<ResponseGetMonsterDTO> rv = new CommonResult<ResponseGetMonsterDTO>();
            var List = (from monster in _context.AswTblTradeMonsters
                        where DTO.MaxPrice >= monster.Price
                        where DTO.MinLevel<=monster.LevelStat
                        where DTO.MaxLevel>=monster.LevelStat
                        where DTO.RebirthStat == monster.RebirthStat
                        select monster).AsEnumerable();
            var Property = DTO.PropertyStat == "ALL" ? List : List.Where(m => m.PropertyStat == DTO.PropertyStat);
            var Rare = DTO.RareStat == "ALL" ? Property : Property.Where(m => m.RareStat == DTO.RareStat);
            var Type = DTO.TypeStat == "ALL" ? Rare : Rare.Where(m => m.TypeStat == DTO.TypeStat);
            var Monster = DTO.MonsterId == 0 ? Type.ToList() : Type.Where(m => m.MonsterId == DTO.MonsterId).ToList();
            rv.Data = new ResponseGetMonsterDTO();
            rv.Data.Monsters = new List<ResponseGetMonsterDTOElement>();

            foreach (var item in Monster) 
            {
                ResponseGetMonsterDTOElement data = new ResponseGetMonsterDTOElement();
                data.MonsterId = item.MonsterId;
                data.AttackStat = item.AttackStat;
                data.RareStat = item.RareStat;
                data.RebirthStat = item.RebirthStat;
                data.TypeStat = item.TypeStat;
                data.SpeedStat = item.SpeedStat;
                data.PropertyStat = item.PropertyStat;
                data.DefenceStat = item.DefenceStat;
                data.HealthStat = item.HealthStat;
                data.LevelStat = item.LevelStat;
                data.Price = item.Price;
                data.UpdateDate = item.UpdateDate;
                data.CreateDate = item.CreateDate;
                data.DeleteDate = item.DeleteDate;
                data.AvailableDate = item.AvailableDate;
                data.Id = item.Id;
                rv.Data.Monsters.Add(data);
            }
            rv.IsSuccess = true;
            rv.StatusCode = (int)CommonStatusCode.Ok;
            return rv;
        }

        [HttpGet("GetMonstersV2")]
        public async Task<CommonResult<ResponseGetMonsterDTO>> GetMonstersV2()
        {
            CommonResult<ResponseGetMonsterDTO> rv = new CommonResult<ResponseGetMonsterDTO>();

            string? filter = HttpContext.Request.Query["filter"];
            var monsters = (from monster in _context.AswTblTradeMonsters
                            select new ResponseGetMonsterDTOElement()
                            {
                                AttackStat = monster.AttackStat,
                                AvailableDate = monster.AvailableDate,
                                CreateDate = monster.CreateDate,
                                DeleteDate = monster.DeleteDate,
                                DefenceStat = monster.DefenceStat,
                                HealthStat = monster.HealthStat,
                                LevelStat = monster.LevelStat,
                                Id = monster.Id,
                                MonsterId = monster.MonsterId,
                                OwnerUserId = monster.OwnerUserId,
                                Price = monster.Price,
                                PropertyStat = monster.PropertyStat,
                                RareStat = monster.RareStat,
                                RebirthStat = monster.RebirthStat,
                                SpeedStat = monster.SpeedStat,
                                TypeStat = monster.TypeStat,
                                UpdateDate = monster.UpdateDate
                            }).AsQueryable();
           var filterResult = new RootFilter();

            if (!string.IsNullOrEmpty(filter))
            {
                filterResult = JsonConvert.DeserializeObject<RootFilter>(filter);
            }
            else
            {
                filterResult = new RootFilter();
            }
            if(monsters!=null)
            {
                monsters = CompositeFilter<ResponseGetMonsterDTOElement>.ApplyFilter(monsters, filterResult);
            }
            rv.IsSuccess = true;
            rv.StatusCode = (int)CommonStatusCode.Ok;
            rv.Data = new ResponseGetMonsterDTO();
            rv.Data.Monsters = monsters.ToList();
            return rv;            
        }

    }
}
