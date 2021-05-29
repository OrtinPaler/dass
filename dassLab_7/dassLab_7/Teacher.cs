namespace Observer
{
    class Teacher
    {
        readonly string name;
        Deanery deanery;
        public Teacher(string name, Deanery deanery)
        {
            this.name = name;
            this.deanery = deanery;
            this.deanery.RegisterTeacher(this);
        }
        public void WriteReport() => deanery.Reports.Add(name, "Report");
        public override string ToString() => name;
    }
}