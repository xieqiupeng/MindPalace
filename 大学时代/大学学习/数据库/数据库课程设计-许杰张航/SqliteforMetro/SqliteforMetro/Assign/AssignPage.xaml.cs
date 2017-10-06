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

namespace SqliteforMetro.Assign
{
    /// <summary>
    /// A basic page that provides characteristics common to most applications.
    /// </summary>
    public sealed partial class AssignPage : SqliteforMetro.Common.LayoutAwarePage
    {
        public AssignPage()
        {
            this.InitializeComponent();
        }


        Entity.Transfer parentTranfer;
        ViewModels.AssginViewModel viewModel = new ViewModels.AssginViewModel();
        protected override void LoadState(Object navigationParameter, Dictionary<String, Object> pageState)
        {
           parentTranfer =(Entity.Transfer) navigationParameter;

           SelectedEmployees.ItemsSource = viewModel.SelectedTransfer;
           Employees.ItemsSource = viewModel.Users;
        }

        /// <summary>
        /// Preserves state associated with this page in case the application is suspended or the
        /// page is discarded from the navigation cache.  Values must conform to the serialization
        /// requirements of <see cref="SuspensionManager.SessionState"/>.
        /// </summary>
        /// <param name="pageState">An empty dictionary to be populated with serializable state.</param>
        protected override void SaveState(Dictionary<String, Object> pageState)
        {
        }

        private void Employees_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if (Employees.SelectedItem == null)
                return;

            viewModel.AddNewTransfer((Entity.User)Employees.SelectedItem, parentTranfer);
        }


        private void RemoveUser_Click(object sender, RoutedEventArgs e)
        {
            if (SelectedEmployees.SelectedItem == null)
                return;

            viewModel.RemoveTransfer((Entity.Transfer)SelectedEmployees.SelectedItem);
        }

        private void Submit_Click(object sender, RoutedEventArgs e)
        {
            viewModel.Submit();

            Frame.GoBack();
            Frame.GoBack();
        }
    }
}
