using TradeWebApi.Models.DB;
using TradeWebApi.Models.DTO;
using TradeWebApi.Utility;

namespace TradeWebApi.Services
{
    public interface IMailService
    {
        Task<List<ResponseGetMailDTOElement>> GetMail(int pageSize, int pageNo, RootFilter rootFilter);
        Task<AswTblMail> InsertMail(long fromUserId, long userId, long itemId, long itemCount);
        Task<AswTblMail> ReceieveMail(long id);
    }
}
