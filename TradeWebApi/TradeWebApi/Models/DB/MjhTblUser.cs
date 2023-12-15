using System;
using System.Collections.Generic;

namespace TradeWebApi.Models.DB;

public partial class MjhTblUser
{
    public int Id { get; set; }

    public string Name { get; set; } = null!;

    public int Level { get; set; }
}
