using System;
using System.Collections.Generic;

namespace Observer
{
    class Department : IObserver
    {
        IObservable deanery;
        public Department(IObservable o)
        {
            deanery = o;
            deanery.RegisterObserver(this);
        }
        public void Update(Object o)
        {
            if (o is List<string> names)
            {
                if (names.Count > 0)
                {
                    Console.WriteLine($"{names.Count} преподавателя не сдали отчёт:");
                    foreach (string n in names)
                        Console.WriteLine(n);
                }  
                else
                {
                    Console.WriteLine($"Все преподаватели сдали отчет");
                }
            }
            else
            {
                throw new Exception("Всё плохо");
            }
        }
    }
}