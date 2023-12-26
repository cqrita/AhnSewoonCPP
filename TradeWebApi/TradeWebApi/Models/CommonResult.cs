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
        Unprocessable= 2,
        SellLimitExceeded=3
    }
    public class Exception_NotFoundEntity : Exception { }
    public class Exception_Unprocessable : Exception { }
    public class Exception_SellLimitExceeded : Exception { }

    public class CommonException : Exception
    {
        protected CommonStatusCode _statusCode;
        public CommonStatusCode StatusCode => _statusCode;
        public CommonException(CommonStatusCode statusCode, string? Message):base(Message)
        {
            _statusCode = statusCode; 
        }
    }
}
