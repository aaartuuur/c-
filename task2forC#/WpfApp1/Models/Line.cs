using System;

namespace WpfApp1.Models
{
    public class Line : Figure
    {
        public double X1 { get; set; }
        public double Y1 { get; set; }
        public double X2 { get; set; }
        public double Y2 { get; set; }

        public Line(double x1, double y1, double x2, double y2)
            : base((x1 + x2) / 2.0, (y1 + y2) / 2.0)
        {
            X1 = x1;
            Y1 = y1;
            X2 = x2;
            Y2 = y2;
        }

        public override Box GetBox()
        {
            return new Box
            {
                Left = Math.Min(X1, X2),
                Top = Math.Min(Y1, Y2),
                Right = Math.Max(X1, X2),
                Bottom = Math.Max(Y1, Y2)
            };
        }

        public override double GetArea()
        {
            return 0;
        }

        public override string GetInfo()
        {
            return base.GetInfo() +
                   $"Точка 1: ({X1:F2}; {Y1:F2})\n" +
                   $"Точка 2: ({X2:F2}; {Y2:F2})\n";
        }
    }
}