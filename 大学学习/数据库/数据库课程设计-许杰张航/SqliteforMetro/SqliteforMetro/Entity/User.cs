using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace SqliteforMetro.Entity
{
    public class User
    {
        [PrimaryKey]
        public string Id { get; set; }//按顺序来

        public string Name { get; set; }
        public int Age { get; set; }

        public int Level { set; get; }
    }
}
