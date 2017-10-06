using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace SqliteforMetro
{
    class DBHelper
    {
        public static string dbPath = Path.Combine(Windows.Storage.ApplicationData.Current.LocalFolder.Path, "base.db");


        public static SQLite.SQLiteConnection db = null;
        public static SQLite.SQLiteConnection GetDB()
        {
            if (db == null)
                db = new SQLite.SQLiteConnection(dbPath);

            return db;
        }

        public static async void Initilaze()
        {
            try
            {
                var file = await Windows.Storage.StorageFile.GetFileFromPathAsync(dbPath);
            }
            catch (Exception ex)
            {
                using (var db = new SQLite.SQLiteConnection(dbPath))
                {
                    db.RunInTransaction(() =>
                    {
                        db.CreateTable<Entity.Document>();
                        db.CreateTable<Entity.LoginInfo>();
                        db.CreateTable<Entity.Transfer>();
                        db.CreateTable<Entity.User>();
                    });
                }
                InitilazeLoginAndUserData();
            }
        }


        public static void InitilazeLoginAndUserData()
        {
            using (var db = new SQLite.SQLiteConnection(dbPath))
            {
                db.RunInTransaction(() =>
                {

                    #region  老板
                    db.Insert(new Entity.User()
                    {
                        Name = "张航",
                        Id = "0",
                        Level = 10
                    });

                    db.Insert(new Entity.LoginInfo()
                    {
                        Password = "00",
                        UserId = "0",
                        Level = 10
                    });


                    db.Insert(new Entity.User()
                    {
                        Name = "许杰",
                        Id = "1",
                        Level = 10
                    });

                    db.Insert(new Entity.LoginInfo()
                    {
                        Password = "11",
                        UserId = "1",
                        Level = 10
                    });

                    #endregion

                    #region 科
                    db.Insert(new Entity.User()
                    {
                        Name = "于家辉",
                        Id = "2",
                        Level = 2
                    });

                    db.Insert(new Entity.LoginInfo()
                    {
                        Password = "22",
                        UserId = "2",
                        Level = 2
                    });


                    db.Insert(new Entity.User()
                    {
                        Name = "孙速伟",
                        Id = "3",
                        Level = 2
                    });

                    db.Insert(new Entity.LoginInfo()
                    {
                        Password = "33",
                        UserId = "3",
                        Level = 2
                    });
                    #endregion

                    #region 室
                    db.Insert(new Entity.User()
                    {
                        Name = "董水龙",
                        Id = "4",
                        Level=1
                    });

                    db.Insert(new Entity.LoginInfo()
                    {
                        Password = "44",
                        UserId = "4",
                        Level = 1
                    });

                    db.Insert(new Entity.User()
                    {
                        Name = "苑泽超",
                        Id = "5"
                    });

                    db.Insert(new Entity.LoginInfo()
                    {
                        Password = "55",
                        UserId = "5",
                        Level = 1
                    });

                    db.Insert(new Entity.User()
                    {
                        Name = "赵若思",
                        Id = "6"
                    });

                    db.Insert(new Entity.LoginInfo()
                    {
                        Password = "66",
                        UserId = "6",
                        Level = 1
                    });


                    db.Insert(new Entity.User()
                    {
                        Name = "郑智栋",
                        Id = "7"
                    });

                    db.Insert(new Entity.LoginInfo()
                    {
                        Password = "77",
                        UserId = "7",
                        Level = 1
                    });
                    #endregion

                    #region 员工

                    for (int i = 0; i < 10;i++)
                    {
                           db.Insert(new Entity.User()
                            {
                                Name = (10+i).ToString(),
                                Id = (10+i).ToString(),
                                Level = 0
                            });

                            db.Insert(new Entity.LoginInfo()
                            {
                                Password = "password",
                                UserId = (10+i).ToString(),
                                Level = 0
                            });
                    }
                    #endregion
                });
            }
        }



        #region Get

        public static List<Entity.User> GetUsers()
        {
            return GetDB().Table<Entity.User>().ToList();
        }

        public static List<Entity.Transfer> GetTransfer()
        {
            return GetDB().Table<Entity.Transfer>().ToList();
        }

        public static List<Entity.Document> GetDocument()
        {
            return GetDB().Table<Entity.Document>().ToList();
        }

        public static List<Entity.LoginInfo> GetLoginInfo()
        {
            return GetDB().Table<Entity.LoginInfo>().ToList();
        }
        #endregion


        public static void Insert(object newObject)
        {
            GetDB().Insert(newObject);
        }

        public static void Update(object updatedObject)
        {
            GetDB().Update(updatedObject);
        }


        #region Transfer
        public static List<Entity.Transfer> GetTransferByUserId(string id)
        {
            try
            {
                return GetTransfer().Where(a => a.TargetUserId.Equals(id)).ToList();
            }
            catch (Exception ex)
            {
                return new List<Entity.Transfer>();
            }
        }

        public static void UpdateTransferArriveTimeByUserId(string id)
        {
            var transfers = GetTransferByUserId(id);


            foreach (var item in transfers)
            {
                if (string.IsNullOrEmpty(item.ArriveTime))
                {
                    item.ArriveTime = DateTime.Now.ToString();
                    Update(item);
                }
            }
        }
        #endregion
    }
}
