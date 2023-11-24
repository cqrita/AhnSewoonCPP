using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231124_01
{
    public class App
    {
        public void Run()
        {
            DateTime dateTime = new DateTime(2023,11,24,17,24,00);
            Console.WriteLine(((DateTimeOffset)dateTime).ToUnixTimeSeconds());
            Console.WriteLine(dateTime.Year);
            Console.WriteLine(dateTime.Month);
            Console.WriteLine(dateTime.Day);
            Console.WriteLine(dateTime.ToString());
            Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-GB");
            Thread.CurrentThread.CurrentCulture= new CultureInfo("en-GB");

            Console.WriteLine(dateTime.ToString());
            Thread.CurrentThread.CurrentUICulture = new CultureInfo("ko-KR");
            Thread.CurrentThread.CurrentCulture = new CultureInfo("ko-KR");

            CultureInfo ci = CultureInfo.InstalledUICulture;
            Console.WriteLine("Default Language Info:");
            Console.WriteLine("* Name: {0}" , ci.Name);
            Console.WriteLine("* Display Name: {0}" , ci.DisplayName);
            
            Console.WriteLine(dateTime.ToString("yyyy/MM/dd HH:mm:ss"));
            DateTime dateTime1 = DateTime.Now;
            DateTime dateTime2 = DateTime.UtcNow;
            DateTime dateTime3 = DateTime.Now;

            Console.WriteLine(dateTime2>dateTime1);
            TimeSpan timeSpan = dateTime3 - dateTime1;
            Console.WriteLine(timeSpan);
            Console.WriteLine(dateTime3+=timeSpan);

            Console.WriteLine(dateTime.IsMonday());
            Console.WriteLine(dateTime2.IsBetween(dateTime1,dateTime3));

        }
    }
}
