using Microsoft.AspNetCore.Mvc;
using Microsoft.EntityFrameworkCore;
using WebApi.Data;
using WebApi.Models;
using WebApi.Models.DB;

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
        private Context _context;
        public SBSStudyController(Context context)
        {
            _context = context;
        }

        //GET, POST, DELETE, PUT
        [HttpGet("get")]
        public async Task<List<AswTblUser>> Get()
        {
            var rv = await _context.AswTblUsers.ToListAsync();

            return rv;
        }
        [HttpGet("post")]
        public async Task<int> InsertUser()
        {
            _context.AswTblUsers.Add(new AswTblUser()
            {
                Id = 1,
                Level = 1,
                Name = "asd"
            });
            var rv=await _context.SaveChangesAsync();
            return rv;
        }
    }
}
