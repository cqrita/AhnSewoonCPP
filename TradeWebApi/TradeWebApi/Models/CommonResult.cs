namespace TradeWebApi.Models
{
    public class CommonResult<T>
    {
        public bool IsSuccess { get; set; } = false;
        public string Messsage { get; set; } =string.Empty;
        public T? Data { get; set; }
        public int StatusCode { get; set; }
    }
    public enum CommonStatusCode
    {
        Ok=0,
        NotFoundEntity=1,
        Unprocessable= 2
    }
}
