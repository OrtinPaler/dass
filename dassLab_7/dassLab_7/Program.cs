using System;

namespace Observer
{
    class Program
    {
        static void Main(string[] args)
        {
            int i = 1;
            Console.WriteLine($"Неделя {i++}:");
            Clock clock = new Clock();
            Deanery deanery = new Deanery(clock);
            Department dep = new Department(deanery);

            Teacher t1 = new Teacher("Альберт Эйнштейн", deanery);
            Teacher t2 = new Teacher("Нильс Бор", deanery);
            Teacher t3 = new Teacher("Алан Тьюринг", deanery);
            
            clock.NotifyObservers();

            Console.WriteLine($"\nНеделя {i++}:");
            t2.WriteReport();
            t1.WriteReport();
            t3.WriteReport();
            clock.NotifyObservers();

            Console.WriteLine($"\nНеделя {i++}:");
            deanery.RemoveTeacher(t3);
            clock.NotifyObservers();

            Console.ReadKey();
        }
    }
}