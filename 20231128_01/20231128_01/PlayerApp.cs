using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace _20231128_01
{
    public class Character
    {
        public int Id
        {
            get;
            set;
        }
        public int Hp
        {
            get;
            set;
        }
        public int Level
        {
            get;
            set;
        }
        public string Name
        {
            get;
            set; 
        }
    }
    public class PlayerItem
    {
        public int Id
        {
            get;
            set;
        }
        public int PlayerId
        {
            get;
            set;
        }
        public int ItemId
        {
            get;
            set;
        }
    }
    public class Item
    {
        public int Id
        {
            get;
            set;
        }
        public string Name
        {
            get;
            set;
        }
    }
    public class PlayerApp
    {
        public void Run()
        {
            List<Character> characters = new List<Character>();
            List<PlayerItem> playerItems = new List<PlayerItem>();
            List<Item> items = new List<Item>();
            Random random = new Random();
            int charIndex = 1;
            for (int i = 0; i < 100; i++)
            {
                characters.Add(new Character
                {
                    Id = charIndex++ ,
                    Hp = random.Next(0 , 100) + 1 ,
                    Level = random.Next(0 , 5) ,
                    Name = WordGenerator(5)
                });
            }
            for (int i = 1; i <= 8; i++)
            {
                items.Add(new Item
                {
                    Id = i,
                    Name=WordGenerator(5)
                });
            }
            int itemIndex = 1;
            for (int i = 1; i <= characters.Count(); i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    playerItems.Add(new PlayerItem
                    {
                        Id = itemIndex++,
                        PlayerId = i ,
                        ItemId = random.Next(1 , items.Count())
                    });
                }    
            }
            
            var query1 = from c in characters
                         select c;
            foreach (var character in query1)
            {
                Console.WriteLine($"ID : {character.Id}, HP: {character.Hp}, LEVEL: {character.Level} NAME: {character.Name}");
            }
            Console.WriteLine();
            var query2 = from pi in playerItems
                         join c in characters
                            on pi.PlayerId equals c.Id
                         join i in items
                            on pi.ItemId equals i.Id
                         select new
                         {
                             Id = pi.Id,
                             PlayerId=c.Id,
                             PlayerName=c.Name,
                             Name=i.Name,
                         };

            foreach (var item in query2)
            {
                Console.WriteLine($"ID : {item.Id}, PLAYERNAME: {item.PlayerName}, NAME: {item.Name}");
            }
            Console.WriteLine();
            var query3 = from c in characters
                         orderby c.Id
                         group c by c.Level into group1
                         select new
                         {
                             Key = group1.Key ,
                             Value = group1
                         };
            foreach (var character in query3)
            {
                Console.WriteLine($"ID : {character.Key}");
                foreach (var groupElement in character.Value)
                {
                    Console.WriteLine($"ID : {groupElement.Id}, HP: {groupElement.Hp}, LEVEL: {groupElement.Level}");
                }
            }
            Console.WriteLine();
            var query4 = from q in query2
                         group q by q.PlayerName into group2
                         select new
                         {
                             Key= group2.Key ,
                             Value = group2
                         };
            foreach (var character in query4)
            {
                Console.WriteLine($"ID : {character.Key}");
                foreach (var groupElement in character.Value)
                {
                    Console.WriteLine($"ID : {groupElement.Id}, NAME: {groupElement.Name}");
                }
            }
        }
        string WordGenerator(int length)
        {
            Random rand = new Random();
            string rv = "";
            for (int i = 0; i < length; i++)
            {
                rv+=char.Parse($"{rand.Next(0,9)}");
            }
            return rv;
        }
    }
}
