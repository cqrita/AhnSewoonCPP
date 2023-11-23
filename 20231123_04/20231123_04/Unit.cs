using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231123_04
{
    public abstract partial class Unit
    {
        public int Id
        {
            get;
            private set;
        } = 0;
        public string Name
        {
            get;
            private set;
        } = "";

    }
}
