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


namespace SqliteforMetro
{
    public sealed partial class CreateDocument : SqliteforMetro.Common.LayoutAwarePage
    {
        public CreateDocument()
        {
            this.InitializeComponent();
        }

        protected override void LoadState(Object navigationParameter, Dictionary<String, Object> pageState)
        {
            Partners.ItemsSource = DBHelper.GetUsers();
        }

        protected override void SaveState(Dictionary<String, Object> pageState)
        {
        }

        private void Submit_Click(object sender, RoutedEventArgs e)
        {

            
            var newDocument = new Entity.Document()
            {
                Id = System.Guid.NewGuid().ToString(),
                AuthorId = App.currentUser.Id,
                Title = Title.Text,
                Content = Content.Text,
                CreateTime = DateTime.Now.ToString(),
                isUrgen = isUrgenSwitch.IsOn
            };

            int i = 0;
            foreach (var item in Partners.SelectedItems)
            {
                switch (i)
                {
                    case 0:
                        newDocument.PartnerOneId = ((Entity.User)item).Id;
                        break;
                    case 1:
                        newDocument.PartnerTwoId = ((Entity.User)item).Id;
                        break;
                    case 2:
                        newDocument.PartnerThreeId = ((Entity.User)item).Id;
                        break;
                    default:
                        break;
                }
                i++;
            }

            DBHelper.Insert(newDocument);

            DBHelper.Insert(new Entity.Transfer()
            {
                Id = System.Guid.NewGuid().ToString(),
                DocumentId = newDocument.Id,
                CommanderId = App.currentUser.Id,
                Command = "New Document",
                CommanderName = App.currentUser.Name,
                State = 0,
                TargetUserId = "-1",
                parentTransferId = null
            });

            Frame.GoBack();
        }

        async private void Partners_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            if ((sender as ListView).SelectedItems.Count > 3)
            {
                var warn = new Windows.UI.Popups.MessageDialog("Warning");
                warn.Content = "as the rule said, you can only choice 3 partners";
                await warn.ShowAsync();

                (sender as ListView).SelectedItems.RemoveAt(3);
            }
        }
    }
}
