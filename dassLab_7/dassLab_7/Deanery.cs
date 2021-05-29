using System.Collections.Generic;
using System.Linq;

namespace Observer
{
    class Deanery : IObservable, IObserver
    {
        public Dictionary<string, string> Reports { get; set; } // Отчёты за текущую неделю
        List<IObserver> observers;
        List<Teacher> teachers;
        IObservable clock;
        public Deanery(IObservable o)
        {
            observers = new List<IObserver>();
            Reports = new Dictionary<string, string>();
            teachers = new List<Teacher>();
            clock = o;
            clock.RegisterObserver(this);
        }
        public void RegisterTeacher(Teacher t) => teachers.Add(t);
        public void RemoveTeacher(Teacher t)
        {
            System.Console.WriteLine($"{t.ToString()} уволился...");
            teachers.Remove(t);
        }
        public void RegisterObserver(IObserver o) => observers.Add(o);
        public void RemoveObserver(IObserver o) => observers.Remove(o);
        public void NotifyObservers()
        {
            List<string> names = new List<string>();
            foreach (Teacher t in teachers)
                if (!Reports.Keys.Contains(t.ToString()))
                    names.Add(t.ToString());
            foreach (IObserver o in observers)
                o.Update(names);
        }
        public void Update(object o)
        {
            NotifyObservers();
            Reports.Clear();
        }
    }
}