using WebApi.Utils;

namespace WebApi.Models
{
    public class TblUser
    {
        public int Id
        {
            get;
            set; 
        }
        public string Name
        {
            get;
            set; 
        }
        public int Level
        {
            get;
            set; 
        }
        public static TblUser Factory(int id)
        {
            Random random = new Random();
            return new TblUser()
            {
                Id = id ,
                Level = random.Next(10) ,
                Name = StringGenerator.Random(4)
            };
        }
    }
}
