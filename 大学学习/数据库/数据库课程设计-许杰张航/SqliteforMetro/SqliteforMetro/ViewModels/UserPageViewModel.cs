using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SqliteforMetro.ViewModels
{
    public class UserPageViewModel : ViewModelBase
    {
        public ObservableCollection<Entity.Document> Documents = new ObservableCollection<Entity.Document>();
        public ObservableCollection<Entity.Transfer> Transfers = new ObservableCollection<Entity.Transfer>();


        public UserPageViewModel(bool isBoss)
        {
            DBHelper.UpdateTransferArriveTimeByUserId(isBoss? "-1" : App.currentUser.Id);
        }

        public void ShowHandledTransfer(bool isBoss)
        {

            var transfers = DBHelper.GetTransferByUserId(isBoss ? "-1" : App.currentUser.Id);

            UpdateObservableDataSource<Entity.Transfer>(transfers.Where(a =>
                        a.State.Equals(1)
                       ).ToList(), Transfers);

        }

        public void ShowUnHandledTransfer(bool isBoss)
        {
            var transfers = DBHelper.GetTransferByUserId(isBoss ? "-1" : App.currentUser.Id);

            UpdateObservableDataSource<Entity.Transfer>(transfers.Where(a =>
                        a.State.Equals(0)
                       ).ToList(), Transfers);
        
        }

    }
}
