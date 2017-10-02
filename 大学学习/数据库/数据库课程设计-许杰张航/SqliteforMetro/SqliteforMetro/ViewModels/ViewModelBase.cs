using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SqliteforMetro.ViewModels
{
    public class ViewModelBase
    {
        public void UpdateObservableDataSource<T>(List<T> source, ObservableCollection<T> targetObservableCollection)
        {
            if (source == null || targetObservableCollection == null)
                throw new ArgumentException("MOT NULL");

            targetObservableCollection.Clear();

            foreach (var item in source)
            {
                targetObservableCollection.Add(item);
            }
        }
    }
}
