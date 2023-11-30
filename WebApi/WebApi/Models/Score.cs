using WebApi.Utils;

namespace WebApi.Models
{
    public class TblScore
    {
        public int Id
        {
            get; set; 
        }
        public int UserId
        {
            get; set; 
        }
        public int Value
        {
            get; 
            set;
        }
        public static TblScore Factory(int id,int UserId)
        {
            Random random = new Random();
            return new TblScore()
            {
                Id = id ,
                UserId = UserId ,
                Value =random.Next(0,1000)
            };
        }

    }
}
