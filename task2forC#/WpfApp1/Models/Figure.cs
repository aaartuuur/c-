using System.Text;

namespace WpfApp1.Models
{
    public abstract class Figure
    {
        public double X { get; protected set; }
        public double Y { get; protected set; }

        protected Figure(double x, double y)
        {
            X = x;
            Y = y;
        }

        public abstract Box GetBox();

        public abstract double GetArea();

        public virtual string GetInfo()
        {
            StringBuilder builder = new StringBuilder();

            builder.AppendLine($"Фигура: {GetType().Name}");
            builder.AppendLine($"Центр: ({X:F2}; {Y:F2})");
            builder.AppendLine($"Площадь: {GetArea():F2}");
            builder.AppendLine($"Ограничивающий прямоугольник: {GetBox()}");

            return builder.ToString();
        }
    }
}