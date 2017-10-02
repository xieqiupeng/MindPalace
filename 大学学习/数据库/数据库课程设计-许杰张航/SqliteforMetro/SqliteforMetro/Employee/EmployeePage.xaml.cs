using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

// The Basic Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=234237

namespace SqliteforMetro.Employee
{
    /// <summary>
    /// A basic page that provides characteristics common to most applications.
    /// </summary>
    public sealed partial class EmployeePage : SqliteforMetro.Common.LayoutAwarePage
    {
        public EmployeePage()
        {
            this.InitializeComponent();
        }



        ViewModels.UserPageViewModel viewModel;
        bool isBoss = false;
        protected override void LoadState(Object navigationParameter, Dictionary<String, Object> pageState)
        {
            if ((navigationParameter as string).Equals("BOSS"))
            {
                CreateButton.Visibility = Windows.UI.Xaml.Visibility.Collapsed;
                isBoss = true;
            }

            viewModel = new ViewModels.UserPageViewModel(isBoss);

            pageTitle.Text = App.currentUser.Name;

            DocumentGridView.ItemsSource = viewModel.Transfers;
        }



        protected override void SaveState(Dictionary<String, Object> pageState)
        {
        }


        #region Event
        private void NewDocument_Click(object sender, RoutedEventArgs e)
        {
            Frame.Navigate(typeof(CreateDocument));
        }

        private void UnHandeledButton_Click(object sender, RoutedEventArgs e)
        {
            viewModel.ShowUnHandledTransfer(isBoss);
        }

        private void HandeledButton_Click(object sender, RoutedEventArgs e)
        {
            viewModel.ShowHandledTransfer(isBoss);
        }

        private void DocumentGridView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (DocumentGridView.SelectedItem == null)
                return;


            if (((Entity.Transfer)DocumentGridView.SelectedItem).State.Equals(0))
                Frame.Navigate(typeof(ViewModels.WorkingPage), DocumentGridView.SelectedItem);
            else
                Frame.Navigate(typeof(Timeline.TimelinePage), DocumentGridView.SelectedItem);
        }
        #endregion


    }
}
