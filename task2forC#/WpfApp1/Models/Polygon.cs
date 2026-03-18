using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace WpfApp1.Models
{
    public class Polygon : Figure
    {
        public List<Point> Points { get; set; }

        public Polygon(List<Point> points) : base(0, 0)
        {
            if (points == null || points.Count < 3)
            {
                throw new ArgumentException("Многоугольник должен содержать минимум 3 точки.");
            }

            Points = points;
            X = Points.Average(p => p.X);
            Y = Points.Average(p => p.Y);
        }

        public override Box GetBox()
        {
            return new Box
            {
                Left = Points.Min(p => p.X),
                Top = Points.Min(p => p.Y),
                Right = Points.Max(p => p.X),
                Bottom = Points.Max(p => p.Y)
            };
        }

        public override double GetArea()
        {
            double sum = 0;

            for (int i = 0; i < Points.Count; i++)
            {
                int next = (i + 1) % Points.Count;
                sum += Points[i].X * Points[next].Y - Points[next].X * Points[i].Y;
            }

            return Math.Abs(sum) / 2.0;
        }

        public override string GetInfo()
        {
            StringBuilder builder = new StringBuilder();

            builder.Append(base.GetInfo());
            builder.AppendLine("Точки многоугольника:");

            foreach (Point point in Points)
            {
                builder.AppendLine($"({point.X:F2}; {point.Y:F2})");
            }

            return builder.ToString();
        }
    }
}