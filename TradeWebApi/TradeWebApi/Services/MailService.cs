using Microsoft.EntityFrameworkCore;
using Microsoft.Extensions.Primitives;
using Newtonsoft.Json;
using TradeWebApi.Models;
using TradeWebApi.Models.DB;
using TradeWebApi.Models.DTO;
using TradeWebApi.Utility;
using WebApi.Data;

namespace TradeWebApi.Services
{
    public class MailService : IMailService
    {
        private readonly Context _context;
        public MailService(Context context) 
        {
            _context = context;
        }

        public async Task<AswTblMail> InsertMail(long fromUserId, long userId, long itemId, long itemCount)
        {
            var mail = await _context.AswTblMails.AddAsync(new AswTblMail()
            {
                FromUserId = fromUserId,
                UserId = userId,
                ItemCount = itemId,
                ItemId = itemCount
            });
            await _context.SaveChangesAsync();
            return mail.Entity;
        }

        public async Task<List<ResponseGetMailDTOElement>> GetMail(int pageSize, int pageNo, RootFilter rootFilter)
        {
            var record = (from mail in _context.AswTblMails
                          select new ResponseGetMailDTOElement()
                          {
                              CreateDate = mail.CreateDate,
                              DeleteDate = mail.DeleteDate,
                              ItemId = mail.ItemId,
                              ItemCount = mail.ItemCount,
                              FromUserId = mail.FromUserId,
                              Id = mail.Id,
                              UserId = mail.UserId
                          }).AsQueryable();
            record = record.Where(m => m.DeleteDate == null);
            if (rootFilter != null)
            {
                record = CompositeFilter<ResponseGetMailDTOElement>.ApplyFilter(record, rootFilter);
            }
            record = record.OrderByDescending(m => m.CreateDate);
            record = record.Skip(pageSize * pageNo).Take(pageSize);
            return await record.ToListAsync();
        }

        public async Task<AswTblMail> ReceieveMail(long id)
        {
            var Mail = await(from mail in _context.AswTblMails
                             where id == mail.Id
                             select mail).FirstOrDefaultAsync();
            if (Mail == null)
            {
                throw new CommonException(CommonStatusCode.Unprocessable, "");
            }
            if (Mail.DeleteDate != null)
            {
                throw new CommonException(CommonStatusCode.Unprocessable, "");
            }
            Mail.DeleteDate = DateTime.Now;
            _context.Update(Mail);
            await _context.SaveChangesAsync();
            return Mail;
        }
    }
}
