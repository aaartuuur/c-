using System.Collections.Generic;
using System.Text;
using System.Windows;
using Models = WpfApp1.Models;

namespace WpfApp1
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        private void ShowFiguresButton_Click(object sender, RoutedEventArgs e)
        {
            List<Models.Figure> figures = new List<Models.Figure>
            {
                new Models.Point(2, 3),

                new Models.Line(0, 0, 6, 4),

                new Models.Ellipse(5, 5, 3, 2),

                new Models.Polygon(new List<Models.Point>
                {
                    new Models.Point(1, 1),
                    new Models.Point(5, 1),
                    new Models.Point(4, 4),
                    new Models.Point(2, 5)
                })
            };

            StringBuilder builder = new StringBuilder();

            foreach (Models.Figure figure in figures)
            {
                builder.AppendLine(figure.GetInfo());
                builder.AppendLine(new string('-', 50));
            }

            ResultTextBox.Text = builder.ToString();
        }

        private void ClearButton_Click(object sender, RoutedEventArgs e)
        {
            ResultTextBox.Clear();
        }
    }
}