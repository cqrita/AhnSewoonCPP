﻿
namespace WebApiClient
{
    public class Program
    {
        static async Task Main(string[] args)
        {
            App app = new App();
            await app.Run();
        }
    }
}
