using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace SqliteforMetro.Entity
{
    public class LoginInfo
    {
        [PrimaryKey]
        public string UserId { get; set; }

        public string Password { get; set; }


        /// <summary>
        /// Level 代表职位
        /// 0  : 普通员
        /// 10 : 老板
        /// 1  : 科负责人
        /// 2 ： 室负责人
        /// </summary>
        public int Level { get; set; }
    }
}
