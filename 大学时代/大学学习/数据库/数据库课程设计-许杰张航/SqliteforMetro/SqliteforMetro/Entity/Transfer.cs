using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace SqliteforMetro.Entity
{
    public class Transfer
    {
        [PrimaryKey]
        public string Id { get; set; }

        public string DocumentId { get; set; }
        public string TargetUserId { get; set; }
        public string TargetUserName { get; set; }
        public string CommanderId { get; set; }
        public string CommanderName { get; set; }
        public string Command { get; set; }

        //0 未完成
        //1 完成
        public int State { get; set; }
        //[PrimaryKey, AutoIncrement]

        //任务顺序
        public int Order { get; set; }

        public string parentTransferId { get; set; }

        public string ResultNote { get; set; }

        public string ArriveTime { get; set; }
        public string FinishTime { get; set; }
    }
}
