namespace TradeWebApi.Models.DTO
{
    public class RequestSendMailDTO
    {
        public long UserId { get; set; }
        public long FromUserId { get; set; }
        public long ItemId { get; set; }
        public long ItemCount { get; set; }
    }
    public class ResponseSendMailDTO
    {
        public long Id { get; set; }
    }
}
