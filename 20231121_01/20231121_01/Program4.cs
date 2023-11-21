using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231121_01
{
    public class Unit
    {
        public int Hp
        {
            get; private set;
        }
        public int Attack
        {
            get; private set;
        }
        public int Defence
        {
            get; private set;
        }
        public static Unit Factory()
        {
            Unit u= new Unit();
            u.Hp = 10;
            u.Attack = 10;
            u.Defence = 10;
            return u;
        }
        public override string ToString()
        {
            return $"Hp : {this.Hp} Attack : {this.Attack} Defence : {this.Defence}";
        }
    }
    public enum RockStringPaper
    {
        Rock,
        String,
        Paper
    }
    class Program4
    {
        static void Main(string[] args)
        {

            Dictionary<string, Unit> dic = new Dictionary<string, Unit>();
            dic["AAA"] = Unit.Factory();
            Console.WriteLine(dic["AAA"].Attack);

            Random rand = new Random();
            int rcp = rand.Next(0, 3);
            Console.WriteLine(((RockStringPaper)rcp).ToString());
            int a = new int();
            object obj;
            Console.WriteLine(dic["AAA"].ToString());
            Console.ReadKey();
        }
    }
}
