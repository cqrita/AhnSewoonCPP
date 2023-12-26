using TradeWebApi.Models.DB;
using TradeWebApi.Models.DTO;
using TradeWebApi.Utility;

namespace TradeWebApi.Services
{
    public interface IMonsterService
    {
        Task<AswTblTradeMonster> BuyMonster(long id, long buyUserId);
        Task<List<AswTblTradeMonster>> GetAllTradeMonsters();
        Task<List<AswTblTradeMonster>> GetMonstersV2(int pageNo, int pageSize, RootFilter rootFilter);
        Task<int> SellMonster(RequestSellMonsterDTO dTO);
    }
}
