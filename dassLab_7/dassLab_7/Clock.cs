using System.Collections.Generic;

namespace Observer
{
    class Clock : IObservable
    {
        List<IObserver> observers;
        public Clock() => observers = new List<IObserver>();
        public void RegisterObserver(IObserver o) => observers.Add(o);

        public void RemoveObserver(IObserver o) => observers.Remove(o);

        public void NotifyObservers()
        {
            foreach (IObserver o in observers)
            {
                o.Update(null);
            }
        }
    }
}