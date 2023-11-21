using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231121_01
{
    class Program1
    {
        static void Main(string[] args)
        {
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine($"i : {i}");
            }
            for(int i=0;i<5;i++)
            {
                for(int j=0;j<=i;j++)
                {
                    Console.Write("*");
                }
                Console.Write("\n");
            }
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < i; j++)
                {
                    Console.Write(" ");
                }
                for (int j = i; j < 5; j++)
                {
                    Console.Write("*");
                }
                Console.Write("\n");
            }
            Console.ReadKey();

        }
    }
}
