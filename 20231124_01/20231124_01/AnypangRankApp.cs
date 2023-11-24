using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231124_01
{
    public class TblUser
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
        }=string.Empty;
        public int Level
        {
            get; 
            set; 
        }
        public List<int>? friends
        {
            get; set; 
        }
    }
    public class TblScore
    {
        public int Id
        {
            get; set; 
        }
        public int UserId
        {
            get; 
            set; 
        }
        public int Value
        {
            get;
            set;
        }
        public DateTime RegisterDate
        {
            get;
            set; 
        }
        public override string ToString()
        {
            return $"ID : {Id} , UserId : {UserId} , Value: {Value} , RegisterDate: {RegisterDate}";
        }
    }
    public class User
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
        } = string.Empty;
        public int Level
        {
            get;
            set;
        }
        public int Score
        {
            get;
            set;
        }
        public override string ToString()
        {
            return $"ID : {Id} , Name : {Name} , Level: {Level} , Score: {Score}";
        }
    }
    public class AnypangRankApp
    {
        private List<TblUser> lstUsers = new List<TblUser>();
        private List<TblScore> lstScores = new List<TblScore>();
        
        public void Run()
        {
            Random rnd = new Random();
            lstUsers.Add(
                new TblUser{
                    Id = 1 ,
                    Level = 1 ,
                    Name = "1" ,
                    friends=new List<int> { 2}
                });
            lstUsers.Add(
                new TblUser{
                    Id = 2 ,
                    Level = 2 ,
                    Name = "2" ,
                    friends = new List<int> { 1,3 }
                });
            lstUsers.Add(
                new TblUser{
                    Id = 3 ,
                    Level = 3 ,
                    Name = "3" ,
                    friends = new List<int> { 2 }
                });
            for (int i = 0; i < 1000; i++)
            {
                lstScores.Add(
                new TblScore
                {
                    Id = i ,
                    UserId = rnd.Next(1,4) ,
                    Value = rnd.Next(1,100000) ,
                    RegisterDate = DateTime.Now
                });
            }
            foreach (TblUser users in lstUsers)
            {
                User maxScore = lstScores.Where((scores) => { return scores.UserId == users.Id; }).ToList().OrderByDescending(s =>  s.Value).Select(s => new User() { Id = users.Id , Level = users.Level , Score = s.Value ,Name=users.Name}).First();
                Console.WriteLine(maxScore.Score);
            }
            var list = lstScores.Join(lstUsers,score=>score.UserId,user=>user.Id,(score,user )=>new User {Id=user.Id,Level=user.Level,Score=score.Value,Name=user.Name }).ToList();
            foreach (User users in list)
            {
                Console.WriteLine(users);
            }
            foreach (TblUser user1 in lstUsers)
            {
                foreach (int userInt in user1.friends)
                {
                    TblUser user2= lstUsers.Where((user) => { return user.Id == userInt; }).ToList().First();
                    User maxScore = lstScores.Where((scores) => { return scores.UserId == user2.Id; }).ToList().OrderByDescending(s => s.Value).Select(s => new User() { Id = user2.Id , Level = user2.Level , Score = s.Value , Name = user2.Name }).First();
                }
            }
        }
    }
}
