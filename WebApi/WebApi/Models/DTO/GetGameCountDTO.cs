using WebApi.Models.DB;

namespace WebApi.Models.DTO
{
    public class RequestGetGameCountDTO
    {
        public string Name { get; set; }
    }
    public class ResponseGetGameCountDTO
    {
        public int Count { get; set; }
    }
}
