using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231121_01
{
    public enum Day
    {
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Saturday,
        Sunday
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World");
            Console.Write("Hello World2\n");

            var a = 3;
            Console.WriteLine($"a :{a}");
            int b = 2;
            float c = 1.1f;
            double d = 2.0;
            bool e = true;
            int num1 = 3;
            int num2 = 5;
            Console.WriteLine($"{num1} + {num2} = {num1 + num2}");

            if(true)
            {
                Console.WriteLine("if");
            }
            else if(true)
            {

            }
            else
            {

            }
            int swir = 3;
            switch (swir)
            {
                case 0:
                    Console.WriteLine(0);
                    break;
                case 1:
                    Console.WriteLine(1);
                    break;
                case 2:
                    Console.WriteLine(2);
                    break;

                case 3:
                    Console.WriteLine(3);
                    break;

                default:
                    Console.WriteLine(33);
                    break;

            }
            string str="str";
            switch (str)
            {
                case "ada":
                    Console.WriteLine(0);
                    break;
                case "str":
                    Console.WriteLine(1);
                    break;
                default:
                    Console.WriteLine(33);
                    break;

            }
            Day day = Day.Monday;
            switch (day)
            {
                case Day.Monday:
                    Console.WriteLine(0);
                    break;
                case Day.Thursday:
                    Console.WriteLine(1);
                    break;
                default:
                    Console.WriteLine(33);
                    break;

            }


            Console.ReadKey();
        }
    }
}
