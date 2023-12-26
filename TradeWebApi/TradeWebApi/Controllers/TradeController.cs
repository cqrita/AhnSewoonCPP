
using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Diagnostics.HealthChecks;
using Microsoft.Extensions.Primitives;
using Newtonsoft.Json;
using System.Collections.Generic;
using System.Dynamic;
using System.Threading;
using TradeWebApi.Models;
using TradeWebApi.Models.DB;
using TradeWebApi.Models.DTO;
using TradeWebApi.Services;
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
        private readonly IMailService _mailService;
        private readonly IMonsterService _monsterService;

        public TradeController(ILogger<TradeController> logger, Context context, IMailService mailService, IMonsterService monsterService)
        {
            _logger = logger;
            _context = context;
            _mailService = mailService;
            _monsterService = monsterService;
        }


        [HttpGet]
        public async Task<List<AswTblTradeMonster>> GetAllTradeMonsters()
        {
            List<AswTblTradeMonster> monsters;
            monsters = await _monsterService.GetAllTradeMonsters();
            return monsters;
        }

        [HttpPost("BuyMonster")]
        public async Task<CommonResult<ResponseBuyMonsterDTO>> BuyMonster([FromBody] RequestBuyMonsterDTO DTO )
        {
            CommonResult<ResponseBuyMonsterDTO> rv = new CommonResult<ResponseBuyMonsterDTO>();
            AswTblTradeMonster Monster;
            try
            {
                Monster = await _monsterService.BuyMonster(DTO.Id,DTO.BuyUserId);
            }
            catch (CommonException ex)
            {
                rv.IsSuccess = false;
                rv.Messsage = ex.Message;
                rv.StatusCode = (int)ex.StatusCode;
                return rv;
            }

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
            int count;
            try
            {
                count=await _monsterService.SellMonster(DTO);
            }
            catch (CommonException ex)
            {
                rv.IsSuccess = false;
                rv.Messsage = ex.Message;
                rv.StatusCode = (int)ex.StatusCode;
                return rv;
            }


            rv.IsSuccess =Convert.ToBoolean(await _context.SaveChangesAsync());
            rv.StatusCode = (int)CommonStatusCode.Ok;

            return rv;
        }
        [HttpGet("GetMonsters")]
        public async Task<CommonResult<ResponseGetMonsterDTO>> GetMonsters([FromQuery] RequestGetMonsterDTO DTO)
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
        public async Task<CommonResult<ResponseGetMonsterDTO>> GetMonstersV2([FromQuery] RequestGetMonsterV2DTO DTO)
        {
            CommonResult<ResponseGetMonsterDTO> rv = new CommonResult<ResponseGetMonsterDTO>();

            List<AswTblTradeMonster> monsters;
            string? filter = HttpContext.Request.Query["filter"];
            var filterResult = new RootFilter();

            if (!string.IsNullOrEmpty(filter))
            {
                filterResult = JsonConvert.DeserializeObject<RootFilter>(filter);
            }
            else
            {
                filterResult = new RootFilter();
            }

            try
            {
                monsters = await _monsterService.GetMonstersV2(DTO.PageNo, DTO.PageSize, filterResult);
            }
            catch (Exception ex)
            {
                rv.IsSuccess = false;
                rv.Messsage = ex.Message;
                rv.StatusCode = (int)CommonStatusCode.Unprocessable;
                return rv;
            }

            rv.IsSuccess = true;
            rv.StatusCode = (int)CommonStatusCode.Ok;
            rv.Data = new ResponseGetMonsterDTO()
            {
                Monsters = (from monster in monsters
                            select new ResponseGetMonsterDTOElement
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
                            }).ToList()
            };
            return rv;            
        }
        [HttpPost("SendMail")]
        public async Task<CommonResult<ResponseSendMailDTO>> SendMail([FromBody] RequestSendMailDTO DTO)
        {
            //add ASWTblMail to ASWTblMails
            //send response
            CommonResult<ResponseSendMailDTO> rv = new CommonResult<ResponseSendMailDTO>();
            AswTblMail mail;
            try
            {
                mail = await _mailService.InsertMail(DTO.FromUserId, DTO.UserId, DTO.ItemId, DTO.ItemCount);
            }
            catch (Exception ex) 
            {
                rv.IsSuccess = false;
                rv.Messsage = ex.Message;
                rv.StatusCode = (int)CommonStatusCode.Unprocessable;
                return rv;
            }
            rv.IsSuccess =true;
            rv.StatusCode = (int)CommonStatusCode.Ok;
            rv.Data = new ResponseSendMailDTO()
            {
                Id = mail.Id
            };
            return rv;
        }
        [HttpGet("GetMail")]
        public async Task<CommonResult<ResponseGetMailDTO>> GetMail([FromQuery] RequestGetMailDTO DTO)
        {
            //get ASWTblMails
            //validation delete date
            //filter
            //orderby
            //paging
            //send response
            CommonResult<ResponseGetMailDTO> rv = new CommonResult<ResponseGetMailDTO>();
            List<ResponseGetMailDTOElement>? record;
            string? filter = HttpContext.Request.Query["filter"];
            var filterResult = new RootFilter();
            if (!string.IsNullOrEmpty(filter))
            {
                filterResult = JsonConvert.DeserializeObject<RootFilter>(filter);
            }
            else
            {
                filterResult = new RootFilter();
            }

            try
            {
                record = await _mailService.GetMail(DTO.PageSize, DTO.PageNo, filterResult);
            }
            catch (Exception ex)
            {
                rv.IsSuccess = false;
                rv.Messsage = ex.Message;
                rv.StatusCode = (int)CommonStatusCode.Unprocessable;
                return rv;
            }
            rv.IsSuccess = true;
            rv.StatusCode = (int)CommonStatusCode.Ok;
            rv.Data = new ResponseGetMailDTO()
            {
                Mail = record
            };
            return rv;
        }
        [HttpPost("ReceiveMail")]
        public async Task<CommonResult<ResponseReceiveMailDTO>> ReceieveMail([FromQuery] RequestReceiveMailDTO DTO)
        {
            //get ASWTblMails where id=dto id
            //validation delete date
            //update date
            //send response
            
            CommonResult<ResponseReceiveMailDTO> rv = new CommonResult<ResponseReceiveMailDTO>();
            AswTblMail? Mail;
            try
            {
                Mail = await _mailService.ReceieveMail(DTO.Id);
            }
            catch (CommonException ex)
            {
                rv.IsSuccess = false;
                rv.Messsage = ex.Message;
                rv.StatusCode = (int)ex.StatusCode;
                return rv;
            }
            rv.IsSuccess = true;
            rv.StatusCode = (int)CommonStatusCode.Ok;
            rv.Data = new ResponseReceiveMailDTO()
            {
                ItemCount=Mail.ItemCount,
                ItemId=Mail.ItemId
            };
            return rv;
        }

    }
}
