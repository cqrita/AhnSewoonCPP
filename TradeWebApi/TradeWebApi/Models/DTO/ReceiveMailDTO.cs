namespace TradeWebApi.Models.DTO
{
    public class RequestReceiveMailDTO
    {
        public long Id { get; set; }
    }
    public class ResponseReceiveMailDTO
    {
        public long ItemId { get; set; }

        public long ItemCount { get; set; }
    }
}
