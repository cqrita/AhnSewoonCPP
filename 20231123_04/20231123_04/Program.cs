namespace _20231123_04
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Unit unit = new Warrior();
            Warrior? warrior = unit as Warrior;
            warrior?.Run();
            Unit? original= warrior as Unit;
            original?.Run();

            //magic number
            int a = 3;
            int b = 56;

        }
    }
}
