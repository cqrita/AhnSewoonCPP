namespace _20231207_01
{
    internal class Program
    {
        static async Task Main(string[] args)
        {
            Async1 async1 = new Async1();
            var task=async1.Run();
            while (!task.IsCompletedSuccessfully)
            {
                Console.WriteLine(task.IsCompletedSuccessfully);
                Thread.Sleep(1000);
            }
            
        }
    }
}
