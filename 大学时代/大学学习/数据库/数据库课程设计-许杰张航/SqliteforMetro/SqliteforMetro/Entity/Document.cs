using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SQLite;

namespace SqliteforMetro.Entity
{
    public class Document
    {
        [PrimaryKey]
        public string Id { get; set; }

        public string Title { get; set; }
        public string Content { get; set; }
        public string AuthorId { get; set; }
        public string CreateTime { get; set; }
        public string PartnerOneId { get; set; }
        public string PartnerTwoId { get; set; }
        public string PartnerThreeId { get; set; }

        public bool isUrgen { get; set; }
    }
}
