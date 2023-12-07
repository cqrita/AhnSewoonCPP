using WebApi.Models.DB;

namespace WebApi.Models.DTO
{
    public class RequestInsertUserDTO
    {
        public string Name { get; set; }
    }
    public class ResponseInsertUserDTO
    {
        public AswTblUser UserInfo
        {
            get; set;
        }
    }
}
