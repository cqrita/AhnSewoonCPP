using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;
namespace WebApiClient
{
    public class RequestInserUserScoreDTO
    {
        public string Name
        {
            get; set;
        }
        public int Score { get; set; }
    }
    public class App
    {
        public async Task Run()
        {
            var client = new HttpClient();
            var request = new HttpRequestMessage(HttpMethod.Post, "http://localhost:5070/SBSStudy/InsertUserScore");
            RequestInserUserScoreDTO dTO = new RequestInserUserScoreDTO()
            {
                Name = "User3",
                Score = 25
            };
            string json=JsonConvert.SerializeObject(dTO);
            var content = new StringContent(json, null, "application/json");
            request.Content = content;
            var response = await client.SendAsync(request);
            response.EnsureSuccessStatusCode();
            Console.WriteLine(await response.Content.ReadAsStringAsync());
        }
    }
}
