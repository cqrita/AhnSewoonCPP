using WebApi.Models.DB;

namespace WebApi.Models.DTO
{
    public class RequestInserUserScoreDTO
    {
        public string Name
        { 
            get; set; 
        }
        public int Score { get; set; }
    }
    public class ResponseInserUserScoreDTO
    {
        public int ScoreId {  get; set; }      
                           
    }

}
