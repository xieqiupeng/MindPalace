using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SqliteforMetro.ViewModels
{
    class AssginViewModel : ViewModelBase
    {

        public ObservableCollection<Entity.User> Users = new ObservableCollection<Entity.User>();
        public ObservableCollection<Entity.Transfer> SelectedTransfer = new ObservableCollection<Entity.Transfer>();
        List<Entity.User> userSwapPool = new List<Entity.User>();

        public AssginViewModel()
        {
            UpdateObservableDataSource(DBHelper.GetUsers().Where(a => a.Level < App.currentUser.Level).ToList()
                , Users);
        }


        public void AddNewTransfer(Entity.User user, Entity.Transfer ParentTransfer)
        {
            var newTransfer = new Entity.Transfer();

            newTransfer.parentTransferId = ParentTransfer.Id;
            newTransfer.DocumentId = ParentTransfer.DocumentId;
            newTransfer.State = 0;
            newTransfer.CommanderId = App.currentUser.Id;
            newTransfer.CommanderName = App.currentUser.Name;
            newTransfer.TargetUserId = user.Id;
            newTransfer.TargetUserName = user.Name;
            newTransfer.Id = System.Guid.NewGuid().ToString();


            SelectedTransfer.Add(newTransfer);
            userSwapPool.Add(user);
            Users.Remove(user);
        }

        public void RemoveTransfer(Entity.Transfer transfer)
        {
            var user = userSwapPool.Single(a => a.Id.Equals(transfer.TargetUserId));
            SelectedTransfer.Remove(SelectedTransfer.Single(a => a.TargetUserId.Equals(user.Id)));

            Users.Add(user);
            userSwapPool.Remove(user);
        }

        public void Submit()
        {
            int i = 0;
            foreach (var item in SelectedTransfer)
            {
                item.Order = i++;
                DBHelper.Insert(item);
            }
        }
    }
}
