using Microsoft.AspNetCore.Mvc;
using System.Security.Cryptography.X509Certificates;
using WebApi.Models;
namespace WebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class UserContoller : ControllerBase
    {
        static List<TblUser> _users = new List<TblUser>();
        static List<TblScore> _scores = new List<TblScore>();
        public UserContoller()
        {
            _users.Clear();
            _scores.Clear();
            Random random = new Random();
            for (int i = 1; i <= 10; i++)
            {
                _users.Add(TblUser.Factory(i));
            }
            int scoreIndex=1;
            for (int i = 1; i <= _users.Count(); i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    _scores.Add(TblScore.Factory(scoreIndex++, i));
                }
                
            }

        }

        [HttpGet("UserInfo")]
        public List<RankUserDTO> UserInfo(int UserId)
        {
            List<RankUserDTO> userScores=new List<RankUserDTO>();
            var query = from user in _users
                        join score in _scores
                            on user.Id equals score.UserId
                        where user.Id == UserId
                        select new RankUserDTO { User=user, Score=score };
            userScores=query.ToList();
            return userScores;
        }
        [HttpGet("Ranking")]
        public List<RankUserDTO> Ranking()
        {
            List<RankUserDTO> users = new List<RankUserDTO>();

            var query = (from user in _users
                        join score in _scores
                            on user.Id equals score.UserId
                        orderby score.Value descending
                        select new RankUserDTO { User = user , Score = score }).DistinctBy(rank => rank.User);
            users=query.ToList();
            return users;
        }
        [HttpGet("get")]
        public List<TblUser> Get()
        {
            return _users;
        }
    }
}
