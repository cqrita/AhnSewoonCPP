namespace _20231123_02
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(String.Join(",",args));
            if (args[0] == "--option_a")
            {
                int value = int.Parse(args[1]);
                Console.WriteLine(value);
            }
        }
    }
}
