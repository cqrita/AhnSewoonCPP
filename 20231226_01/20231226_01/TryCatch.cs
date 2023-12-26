using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231226_01
{
    public class TryCatch
    {
        public void Run()
        {
            try
            {
                int zero = 0;
                var a = 1 / zero;
                Console.WriteLine(a);
            }
            catch (Exception ex) 
            {
                Console.WriteLine(ex.ToString());
            }
            finally
            {
                
            }
        }
    }
}
