using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Primitives;
using Newtonsoft.Json;
using TradeWebApi.Models.DB;
using TradeWebApi.Models;
using TradeWebApi.Models.DTO;
using TradeWebApi.Utility;
using WebApi.Data;

namespace TradeWebApi.Services
{
    public class MonsterService : IMonsterService
    {
        private readonly Context _context;
        public MonsterService(Context context)
        {
            _context = context;
        }

        public async Task<AswTblTradeMonster> BuyMonster(long id, long buyUserId)
        {
            var Monster = await(from monster in _context.AswTblTradeMonsters
                                where id == monster.Id
                                select monster).FirstOrDefaultAsync();
            if (Monster == null)
            {
                throw new CommonException(CommonStatusCode.Unprocessable,"");
            }
            if (Monster.DeleteDate != null)
            {
                throw new CommonException(CommonStatusCode.Unprocessable, "");
            }
            if (DateTime.Now > Monster.AvailableDate)
            {
                throw new CommonException(CommonStatusCode.Unprocessable, "");
            }
            if (Monster.OwnerUserId == buyUserId)
            {
                throw new CommonException(CommonStatusCode.Unprocessable, "");
            }

            Monster.DeleteDate = DateTime.Now;

            var newMail = new AswTblMail()
            {
                DeleteDate = null,
                FromUserId = buyUserId,
                ItemId = 1,
                ItemCount = Monster.Price,
                UpdateDate = DateTime.Now
            };
            _context.Add(newMail);
            await _context.SaveChangesAsync();
            return Monster;
        }

        public async Task<List<AswTblTradeMonster>> GetAllTradeMonsters()
        {
            var monsters = await(from tradeMonster in _context.AswTblTradeMonsters
                                 select tradeMonster).ToListAsync();
            return monsters;
        }

        public async Task<List<AswTblTradeMonster>> GetMonstersV2(int pageNo, int pageSize, RootFilter rootFilter)
        {
            var monsters = (from monster in _context.AswTblTradeMonsters
                            select monster).AsQueryable();
            monsters = monsters.Where(m => m.DeleteDate == null);
            var nowTime = DateTime.Now;
            monsters = monsters.Where(m => nowTime < m.AvailableDate);
            if (rootFilter != null)
            {
                monsters = CompositeFilter<AswTblTradeMonster>.ApplyFilter(monsters, rootFilter);
            }
            monsters = monsters.Skip(pageNo * pageSize).Take(pageSize);
            return await monsters.ToListAsync();
        }

        public async Task<int> SellMonster(RequestSellMonsterDTO dTO)
        {
            var nowTime = DateTime.Now;
            int count = await _context.AswTblTradeMonsters.Where(m => m.DeleteDate == null).Where(m => nowTime < m.AvailableDate).Where(m => m.OwnerUserId == dTO.OwnerUserId).CountAsync();
            if (count >= 3)
            {
                throw new CommonException(CommonStatusCode.Unprocessable, "");
            }
            _context.AswTblTradeMonsters.Add(new AswTblTradeMonster()
            {
                OwnerUserId = dTO.OwnerUserId,
                MonsterId = dTO.MonsterId,
                Price = dTO.Price,
                LevelStat = dTO.LevelStat,
                AttackStat = dTO.AttackStat,
                DefenceStat = dTO.DefenceStat,
                SpeedStat = dTO.SpeedStat,
                HealthStat = dTO.HealthStat,
                RareStat = dTO.RareStat,
                PropertyStat = dTO.PropertyStat,
                TypeStat = dTO.TypeStat,
                RebirthStat = dTO.RebirthStat
            });
            return count;
        }
    }
}
