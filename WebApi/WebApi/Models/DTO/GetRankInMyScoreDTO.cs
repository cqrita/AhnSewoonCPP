using WebApi.Models.DB;

namespace WebApi.Models.DTO
{
    public class RequestGetRankInMyScoreDTO
    {
        public string Name {  get; set; }
        public int Score {  get; set; }
    }
    public class ResponseGetRankInMyScoreDTO
    {
        public int Rank { get; set; }
        public AswTblScore Score { get; set; }
    }

}
