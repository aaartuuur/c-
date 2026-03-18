namespace WpfApp1.Models
{
    public class Box
    {
        public double Left { get; set; }
        public double Top { get; set; }
        public double Right { get; set; }
        public double Bottom { get; set; }

        public override string ToString()
        {
            return $"Left = {Left:F2}, Top = {Top:F2}, Right = {Right:F2}, Bottom = {Bottom:F2}";
        }
    }
}
