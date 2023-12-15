using System;
using System.Collections.Generic;

namespace TradeWebApi.Models.DB;

public partial class AswTblUser
{
    public int Id { get; set; }

    public string Name { get; set; } = null!;

    public int Level { get; set; }

    public virtual ICollection<AswTblScore> AswTblScores { get; set; } = new List<AswTblScore>();
}
