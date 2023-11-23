using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231123_04
{
    public class Warrior : Unit
    {
        public override void Attack()
        {
            Console.WriteLine(nameof(Attack));
        }

        public override void Move()
        {
            Console.WriteLine(nameof(Move));
        }

        public override void Run()
        {
            Console.WriteLine(nameof(Run));
        }
    }
}
