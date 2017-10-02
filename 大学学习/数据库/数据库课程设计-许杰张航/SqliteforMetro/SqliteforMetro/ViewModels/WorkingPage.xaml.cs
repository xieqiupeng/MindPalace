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

namespace SqliteforMetro.ViewModels
{
    /// <summary>
    /// A basic page that provides characteristics common to most applications.
    /// </summary>
    public sealed partial class WorkingPage : SqliteforMetro.Common.LayoutAwarePage
    {
        public WorkingPage()
        {
            this.InitializeComponent();
        }



        Entity.Transfer currentTransfer = null;
        protected override void LoadState(Object navigationParameter, Dictionary<String, Object> pageState)
        {
            currentTransfer = (Entity.Transfer)navigationParameter;
            var document = DBHelper.GetDocument().Single(a => a.Id.Equals(currentTransfer.DocumentId));

            Content.Text = document.Content;
            pageTitle.Text = document.Title;
            ResultNote.DataContext = currentTransfer;
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

        private void Done_Click(object sender, RoutedEventArgs e)
        {
            currentTransfer.State = 1;
            currentTransfer.FinishTime = DateTime.Now.ToString();

            DBHelper.Update(currentTransfer);

            Frame.GoBack();
        }

        private void Assgin_Click(object sender, RoutedEventArgs e)
        {
            Frame.Navigate(typeof(Assign.AssignPage), currentTransfer);
        }
    }
}
