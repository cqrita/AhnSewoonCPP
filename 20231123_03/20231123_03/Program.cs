using Newtonsoft.Json;
using System.Text.Json.Nodes;

namespace _20231123_03
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Movie movie = new Movie();
            movie.Name = "Bad Boys";
            movie.ReleaseDate = "1995-4-7T00:00:00";
            movie.Genres = new List<string>
            {
                    "Action",
                    "Comedy"
            };
            string json= JsonConvert.SerializeObject(movie , Formatting.Indented);
            Movie movie2 = JsonConvert.DeserializeObject<Movie>(json) ?? new Movie();

            Console.WriteLine(json);
        }
    }
}


public class Movie
{
    public string Name
    {
        get; set;
    }
    public string ReleaseDate
    {
        get; set;
    }
    public List<string> Genres
    {
        get; set;
    }
}
