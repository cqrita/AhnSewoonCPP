using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231121_01
{
    public enum RockStringPaper
    {
        Rock,
        Scissors,
        Paper
    }
    public struct Player
    {
        public int first;
        public int second;
        public int result;
    }
    class Program5
    {
        static void Main(string[] args)
        {
            Random rand = new Random();
            Player player = new Player();
            Player com = new Player();
            Console.WriteLine("Input player Left Hand");
            player.first = (int)Console.ReadKey().KeyChar-48;
            Console.WriteLine();
            Console.WriteLine("Input player Right Hand");
            player.second = (int)Console.ReadKey().KeyChar - 48;
            Console.WriteLine();
            com.first = rand.Next(0, 3);
            com.second = rand.Next(0, 3);

            Console.WriteLine($"Player Hand:{((RockStringPaper)player.first).ToString()} , {((RockStringPaper)player.second).ToString()}");
            Console.WriteLine($"Com Hand:{((RockStringPaper)com.first).ToString()} , {((RockStringPaper)com.second).ToString()}");
            Console.WriteLine("Input player Final Hand");
            int input = Console.ReadKey().KeyChar;
            Console.WriteLine();
            if (input==0)
            {
                player.result = player.first;
            }
            else
            {
                player.result = player.second;
            }
            input= rand.Next(0, 2);
            if (input == 0)
            {
                com.result = com.first;
            }
            else
            {
                com.result = com.second;
            }
            Console.WriteLine($"Player Hand:{((RockStringPaper)player.result).ToString()}");
            Console.WriteLine($"Com Hand:{((RockStringPaper)com.result).ToString()}");
            if((RockStringPaper)player.result==RockStringPaper.Rock&& (RockStringPaper)com.result == RockStringPaper.Scissors
                || (RockStringPaper)player.result == RockStringPaper.Scissors && (RockStringPaper)com.result == RockStringPaper.Paper
                || (RockStringPaper)player.result == RockStringPaper.Paper && (RockStringPaper)com.result == RockStringPaper.Rock)
            {
                Console.WriteLine("Player Win");
            }
            else if(player.result == com.result)
            {
                Console.WriteLine("Draw");
            }
            else
            {
                Console.WriteLine("Player Lose");
            }
            Console.ReadKey();
        }
    }
}
