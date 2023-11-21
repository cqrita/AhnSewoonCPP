using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231121_01
{
    public struct MyStruct
    {
        public int A
        {
            get
            {
                return _a;
            }
            set
            {
                _a = value;
            }
        }
        private int _a;
        public int B;
        public MyStruct(int aa)
        {
            _a = 3;
            B = 4;
        }
        public static MyStruct Factory()
        {
            return new MyStruct();
        }
    }
    public class MyClass
    {
        ~MyClass()
        {

        }
    }
    class Program3
    {
        static void Main(string[] args)
        {
            MyStruct aa = new MyStruct();
            MyStruct ab = new MyStruct(3);



        }
    }
}