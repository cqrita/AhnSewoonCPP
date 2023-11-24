using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _20231124_01
{
    public static class Extension
    {
        public static bool IsMonday(this DateTime date)
        {
            return date.DayOfWeek == DayOfWeek.Monday;
        }
        public static bool IsBetween(this DateTime date,DateTime start,DateTime end)
        {
            return start <= date && end >= date;
        }

    }
}
