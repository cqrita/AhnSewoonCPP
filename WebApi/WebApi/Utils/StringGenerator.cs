namespace WebApi.Utils
{
    public class StringGenerator
    {
        static Random random = new Random();

        public static string Random(int length)
        {
            string str = "";
            for (int i = 0; i < length; i++)
            {
                int index = random.Next(0 , 5);
                switch (index)
                {
                    case 0:
                        str += "바";
                        break;
                    case 1:
                        str += "다";
                        break;
                    case 2:
                        str += "사";
                        break;
                    case 3:
                        str += "자";
                        break;
                    case 4:
                        str += "가";
                        break;
                }
            }

            return str;
        }

    }
}
