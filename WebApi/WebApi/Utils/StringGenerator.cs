namespace WebApi.Utils
{
    public class StringGenerator
    {
        static Random random = new Random();
        public static string Random(int length)
        {
            string str="";
            for (int i = 0; i < length; i++)
            {
                int index=random.Next(1,5);
                str += $"{index}";
            }
            return str;
        }
    }
}
