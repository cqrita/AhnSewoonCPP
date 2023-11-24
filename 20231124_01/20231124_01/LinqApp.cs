using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231124_01
{
    public class LinqApp
    {
        public void Run()
        {
            List<int> list = new List<int>();
            for (int i = 1; i <= 10000; i++)
            {
                list.Add(i);
            }
            foreach (int i in list)
            {
                Console.WriteLine(i);
            }
            int sum=0;
            foreach (int i in list)
            {
                if (i % 2 == 0)
                {
                    sum += i;
                }
            }

            Console.WriteLine(sum);
            //list.Where(Check1).ToList();
            list = list.Where(
                (i) =>
                {
                    return (i % 2 == 0);
                }
            ).ToList();

            list = list.Where(
               (i) => i % 2 == 0
            ).ToList();

           
        }
        public bool Check1(int i)
        {
            return i % 2 == 0;
        }
        public bool Check2(int index,int value)
        {
            return value % 2 == 0;
        }
    }
}
