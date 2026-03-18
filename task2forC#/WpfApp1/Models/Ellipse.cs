using System;

namespace WpfApp1.Models
{
    public class Ellipse : Figure
    {
        public double RadiusX { get; set; }
        public double RadiusY { get; set; }

        public Ellipse(double x, double y, double radiusX, double radiusY)
            : base(x, y)
        {
            RadiusX = radiusX;
            RadiusY = radiusY;
        }

        public override Box GetBox()
        {
            return new Box
            {
                Left = X - RadiusX,
                Top = Y - RadiusY,
                Right = X + RadiusX,
                Bottom = Y + RadiusY
            };
        }

        public override double GetArea()
        {
            return Math.PI * RadiusX * RadiusY;
        }

        public override string GetInfo()
        {
            return base.GetInfo() +
                   $"Полуось X: {RadiusX:F2}\n" +
                   $"Полуось Y: {RadiusY:F2}\n";
        }
    }
}