using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231128_01
{
    public class Student
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
    public enum Subject
    {
        Math,English,Korean,End
    }
    public class StudentScore
    {
        public int Id
        {
            get;
            set;
        }
        public Subject Subject
        {
            get;
            set; 
        }
        public int StudentId
        {
            get;
            set; 
        }
        public int Value
        {
            get; 
            set;
        }
    }
    
    public class Linq2App
    {
        public void Run()
        {
            Console.WriteLine(nameof(Linq2App));
            List<Student> students = new List<Student>();
            Random random = new Random();
            int index=1;
            #region Student Add
            students.Add(new Student
            {
                Id = index++ ,
                Name = $"{random.Next()}" ,
            });
            students.Add(new Student
            {
                Id = index++ ,
                Name = $"{random.Next()}" ,
            });
            students.Add(new Student
            {
                Id = index++ ,
                Name = $"{random.Next()}" ,
            });
            students.Add(new Student
            {
                Id = index++ ,
                Name = $"{random.Next()}" ,
            });
            students.Add(new Student
            {
                Id = index++ ,
                Name = $"{random.Next()}" ,
            });
            #endregion
            List<StudentScore> studentScores = new();
            #region StudentScore Add
            int studentScoreIndex = 1;
            for (int i = 1; i <= students.Count; i++)
            {
                for (int j = 0; j < (int)Subject.End; j++)
                {
                    studentScores.Add(new StudentScore
                    {
                        Id = studentScoreIndex++ ,
                        StudentId = i ,
                        Subject = (Subject)j ,
                        Value = random.Next(0 , 3)
                    });

                }
            }
            #endregion
            var query1 = from s in students
                         orderby s.Name
                         select new
                         {
                             Id = s.Id,
                             Name = s.Name,
                         };
            foreach (var student in query1)
            {
                Console.WriteLine($"ID : {student.Id} NAME: {student.Name}");
            }
            Console.WriteLine();
            var query2 = from s in students
                         where s.Id > 3
                         orderby s.Name
                         select s;
            foreach (var student in query2)
            {
                Console.WriteLine($"ID : {student.Id} NAME: {student.Name}");
            }
            Console.WriteLine($"student scores{studentScores.Count()}");
            var query3 = from s in students
                         join ss in studentScores
                            on s.Id equals ss.StudentId
                         select new
                         {
                            Id = s.Id,
                            Name = s.Name,
                            Subject = ss.Subject,
                            Value= ss.Value
                         };
            foreach (var student in query3)
            {
                Console.WriteLine($"ID : {student.Id} NAME: {student.Name}, SUBJECT: {student.Subject} VALUE: {student.Value}");
            }
            var query4 = from sc in query3
                         where sc.Subject==Subject.English
                         group sc by sc.Value into group1
                         select new
                         {
                             Key = group1.Key ,
                             Value = group1
                         };
            foreach (var student in query4)
            {
                Console.WriteLine($"ID : {student.Key}");
                foreach (var groupElement in student.Value)
                {
                    Console.WriteLine($"NAME: {groupElement.Name}, SUBJECT: {groupElement.Subject} VALUE: {groupElement.Value}");
                }
            }



        }
    }
}
