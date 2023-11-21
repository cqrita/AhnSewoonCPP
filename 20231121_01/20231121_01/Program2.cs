using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231121_01
{
    class Program2
    {
        static void Main(string[] args)
        {
            //loop

            while(true)
            {
                Console.WriteLine("asd");
                ConsoleKeyInfo a= Console.ReadKey();
                if(a.KeyChar=='a')
                {
                    break;
                }
            }
            int[] arr = new int[10];

            List<int> list = new List<int>();
            list.Add(3);
            
            foreach(var element in list)
            {
                Console.WriteLine(element);
            }
        }
    }
}