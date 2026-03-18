namespace WpfApp1.Models
{
    public class Point : Figure
    {
        public Point(double x, double y) : base(x, y)
        {
        }

        public override Box GetBox()
        {
            return new Box
            {
                Left = X,
                Top = Y,
                Right = X,
                Bottom = Y
            };
        }

        public override double GetArea()
        {
            return 0;
        }
    }
}