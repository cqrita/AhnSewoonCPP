using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231123_01
{

    public enum HandType
    {
        Player,
        Computer,
        End
    }


    //public
    //private
    //protected
    //internal
    public class App
    {
        //hand -> player hand
        //variable
        //value (0,1,2 or enum)
        //function
        //setter

        //Nullable
        //int? a;

        Dictionary<HandType , Hand> hands= new Dictionary<HandType , Hand>();
        public void Run()
        {
            Console.WriteLine("Rock Scissors paper");
            //1. my hand
            //2. com hand
            //3. get winner
            Random random = new Random();
            hands[HandType.Player]= new Hand();
            hands[HandType.Computer]= new Hand();
            Console.WriteLine("Player 0 rock 1 scissors 2 paper");
            string? input= Console.ReadLine();
            int value = int.Parse(input ?? "");
            hands[HandType.Player].Value = (RockScissorsPaper)value;
            hands[HandType.Computer].Value=(RockScissorsPaper)random.Next(0,3);
            Console.WriteLine($"player hand: {hands[HandType.Player]}");
            Console.WriteLine($"com hand: {hands[HandType.Computer]}");
            if (hands[HandType.Player] == hands[HandType.Computer])
            {
                Console.WriteLine("Draw");
            }
            else if ((hands[HandType.Player].Value == RockScissorsPaper.Scissors && hands[HandType.Computer].Value == RockScissorsPaper.Paper) ||
                (hands[HandType.Player].Value == RockScissorsPaper.Rock && hands[HandType.Computer].Value == RockScissorsPaper.Scissors) ||
                (hands[HandType.Player].Value == RockScissorsPaper.Paper && hands[HandType.Computer].Value == RockScissorsPaper.Rock))
            {
                Console.WriteLine("Win");

            }
            else
            {
                Console.WriteLine("Lose");

            }
        }
    }
}
