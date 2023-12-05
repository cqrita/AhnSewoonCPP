using Microsoft.AspNetCore.Mvc;
using Microsoft.Extensions.Configuration;
using WebApi.Models;
namespace WebApi.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class UserController : ControllerBase
    {

        static List<TblUser> _users = new();
        static List<TblScore> _scores = new();

        IConfiguration _configuration;

        public UserController(IConfiguration configuration)
        {
            _configuration = configuration;

            Console.WriteLine(_configuration["Logging:LogLevel:Default"]);

            Console.WriteLine(_configuration.GetConnectionString("SBS_Study"));
            //_configuration.GetConnectionString
            // Connection String => DB에 연결하기위한 정보

            _users.Clear();

            for (int i = 1; i <= 10; i++)
            {
                _users.Add(TblUser.Factory(i));
            }

            _scores.Clear();
            int scoreIndex = 1;
            for (int i = 1; i <= 10; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    _scores.Add(TblScore.Factory(scoreIndex++, i));
                }
                
            }
        }

        //GET, POST, DELETE, PUT
        [HttpGet("UserInfo")]
        public List<TblScore> UserInfo(int userId)
        {
            return _scores.Where(s => s.UserId == userId).ToList();
        }

        [HttpGet("Ranking")]
        public List<RankUserDto> Ranking()
        {
            var query = from user in _users
                        join score in _scores
                            on user.Id equals score.UserId
                        orderby score.Value descending
                        select new RankUserDto()
                        {
                            User = user,
                            Score = score
                        };


            // 1등유저부터 차례대로 유저정보 리턴
            return query.ToList();
        }

        [HttpGet("Ranking2")]
        public List<RankUserDto> Ranking2()
        {
            var query = from user in _users
                        join score in _scores
                            on user.Id equals score.UserId
                        group new RankUserDto()
                        {
                            User = user ,
                            Score = score
                        } by user.Id into rankUser
                        select new
                        {
                            Key = rankUser.Key ,
                            Value = rankUser
                        };

            List<RankUserDto> rankUsers = new();


            //각 유저별 최고점수 저장
            foreach (var rankUser in query)
            {
                rankUsers.Add(new RankUserDto()
                {
                    User = rankUser.Value.FirstOrDefault().User ,
                    Score = rankUser.Value.OrderByDescending(r => r.Score.Value).FirstOrDefault().Score
                });
            }

            
            return rankUsers.OrderByDescending(r => r.Score.Value).ToList();
        }

        [HttpGet("get")]
        public List<TblUser> get()
        {
            // 모든 User테이블 리턴
            return _users;
        }

    }
}
