using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class AswTblUser
{
    public int Id { get; set; }

    public string Name { get; set; } = null!;

    public int Level { get; set; }
}
