using System;
using System.Collections.Generic;

namespace WebApi.Models.DB;

public partial class BsyTblScore
{
    public int Id { get; set; }

    public int UserId { get; set; }

    public int Value { get; set; }
}
