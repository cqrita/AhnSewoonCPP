using WebApi.Models.DB;

namespace WebApi.Models.DTO
{
    public class RequestGetGameCountDTO
    {
        public string Name { get; set; }
    }
    public class ResponseGetGameCountDTO
    {
        public AswTblUser User { get; set; }
        public int Count { get; set; }
}
