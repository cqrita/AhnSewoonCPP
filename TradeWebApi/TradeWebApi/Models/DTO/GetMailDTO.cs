namespace TradeWebApi.Models.DTO
{
    public class RequestGetMailDTO
    {
        public int PageSize { get; set; }
        public int PageNo { get; set; }
    }
    public class ResponseGetMailDTOElement
    {
        public long Id { get; set; }

        public long UserId { get; set; }

        public long FromUserId { get; set; }

        public long ItemId { get; set; }

        public long ItemCount { get; set; }

        public DateTime CreateDate { get; set; }

        public DateTime? DeleteDate { get; set; }
    }
    public class ResponseGetMailDTO
    {
        public List<ResponseGetMailDTOElement>? Mail { get; set; }
    }
}
