using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using System.Linq;
using System.Reflection.Emit;
using System.Xml.Linq;
using WebApi.Data;
using WebApi.Models;
using WebApi.Models.DB;
using WebApi.Models.DTO;

namespace WebApi.Controllers
{
    //https://localhost:44300/SBSStudy

    [ApiController]
    [Route("[controller]")]
    public class SBSStudyController : ControllerBase
    {
        private static readonly string[] Summaries = new[]
        {
            "Freezing", "Bracing", "Chilly", "Cool", "Mild", "Warm", "Balmy", "Hot", "Sweltering", "Scorching"
        };

        private readonly Context _context;

        public SBSStudyController(Context context)
        {
            _context = context;
        }

        //GET, POST, DELETE, PUT
        //GET - READ
        //POST - CREATE, (DELETE, UPDATE)
        //DELETE - DELETE
        //PUT - UPDATE
        [HttpPost("InsertUser")]
        public async Task<ResponseInsertUserDTO> InsertUser([FromBody] RequestInsertUserDTO dTO)
        {
            ResponseInsertUserDTO responseInsertUserDTO = new ResponseInsertUserDTO();
            var entity=_context.AswTblUsers.Add(new AswTblUser()
            {
                Level = 1,
                Name = dTO.Name
            });
            responseInsertUserDTO.UserInfo = entity.Entity;
            await _context.SaveChangesAsync();
            return responseInsertUserDTO;
        }
        [HttpGet("GetUser")]
        public async Task<AswTblUser> GetUser(String Name)
        {
            var users = await _context.AswTblUsers.ToListAsync();
            var rv = (from user in users
                     where user.Name == Name
                     select user).FirstOrDefault();
            return rv ?? new AswTblUser();
        }
        [HttpPost("InsertUserScore")]
        public async Task<ResponseInserUserScoreDTO> InsertUserScore([FromBody] RequestInserUserScoreDTO dTO)
        {
            ResponseInserUserScoreDTO rv= new ResponseInserUserScoreDTO();
            var list= await _context.AswTblUsers.ToListAsync();
            var query = from user in list
                        where user.Name == dTO.Name
                        select user;
            AswTblUser aswTblUser = query.First() ?? list.First();
            var score=_context.AswTblScores.Add(new AswTblScore()
            {
                UserId= aswTblUser.Id,
                Value= dTO.Score
            });
            await _context.SaveChangesAsync();
            rv.ScoreId = score.Entity.Id;
            return rv;
        }
        [HttpGet("GetRankInMyScore")]
        public async Task<ResponseGetRankInMyScoreDTO> GetRankInMyScore([FromQuery] RequestGetRankInMyScoreDTO dTO)
        {
            ResponseGetRankInMyScoreDTO rv = new ResponseGetRankInMyScoreDTO();
            var users = await _context.AswTblUsers.ToListAsync();
            var query = from user in users
                        where user.Name == dTO.Name
                        select user;
            AswTblUser aswTblUser = query.First() ?? users.First();
            var list = await _context.AswTblScores.ToListAsync();
            int rank=list.Where(score=>score.UserId == aswTblUser.Id).OrderByDescending(score => score.Value).ToList().FindIndex(score => score.Value == dTO.Score)+1;

            rv.Rank= rank;
            return rv;
        }
        [HttpGet("GetGameCount")]
        public async Task<ResponseGetGameCountDTO> GetGameCount([FromQuery] RequestGetGameCountDTO dTO)
        {
            ResponseGetGameCountDTO rv = new ResponseGetGameCountDTO();

            var users = await _context.AswTblUsers.ToListAsync();
            var query = from user in users
                        where user.Name == dTO.Name
                        select user;
            AswTblUser aswTblUser = query.First() ?? users.First();
            var list = await _context.AswTblScores.ToListAsync();
            rv.Count = list.Where(score => score.UserId == aswTblUser.Id).Count();
            return rv;
        }
        [HttpGet("GetRankInWorldScore")]
        public async Task<ResponseGetRankInWorldScoreDTO> GetRankInWorldScore([FromQuery] RequestGetRankInWorldScoreDTO dTO)
        {
            ResponseGetRankInWorldScoreDTO rv = new ResponseGetRankInWorldScoreDTO();
            var users = await _context.AswTblUsers.ToListAsync();
            var query = from user in users
                        where user.Name == dTO.Name
                        select user;
            AswTblUser aswTblUser = query.First() ?? users.First();
            var list = await _context.AswTblScores.ToListAsync();
            var scoreQuery = list.GroupBy(score => score.UserId);
            List<AswTblScore> scoreList= new List<AswTblScore>();
            foreach ( var score in scoreQuery ) 
            {
                AswTblScore aswTblScore = score.OrderByDescending(s=>s.Value).FirstOrDefault()??new AswTblScore();
                scoreList.Add(aswTblScore);
            }
            rv.Rank = scoreList.OrderByDescending(score => score.Value).ToList().FindIndex(s=>s.UserId== aswTblUser.Id)+1;
            return rv;
        }
    }
}
