using System;
using System.Collections.Generic;

namespace TradeWebApi.Models.DB;

public partial class BsyTblUser
{
    public int Id { get; set; }

    public string Name { get; set; } = null!;

    public int Level { get; set; }

    public virtual ICollection<BsyTblScore> BsyTblScores { get; set; } = new List<BsyTblScore>();
}
