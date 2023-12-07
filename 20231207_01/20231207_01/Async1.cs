using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231207_01
{
    public class Async1
    {
        public async Task<int> Run()
        {
            Thread t = new Thread(() =>
            {
                while (true)
                {
                    Console.WriteLine("Thread1");
                    Thread.Sleep(1000);
                }
            });
            //t.Start();
            Task task = new Task(() =>
            {
                for (int i = 0; i < 10; i++)
                {
                    Console.WriteLine("Thread2");
                    Thread.Sleep(1000);
                }
            });
            //task.RunSynchronously();
            task.Start();
            await task;
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("Main");
                Thread.Sleep(500);
            }

            Console.WriteLine("HelloWorld");
            Console.WriteLine("HelloWorld");
            Console.WriteLine("HelloWorld");
            Console.WriteLine("HelloWorld");
            Console.WriteLine("HelloWorld");
            return 0;
        }
    }
}
