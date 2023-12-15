using System;
using System.Collections.Generic;

namespace TradeWebApi.Models.DB;

public partial class BsyTblMail
{
    public long Id { get; set; }

    public long UserId { get; set; }

    public long FromUserId { get; set; }

    public long ItemId { get; set; }

    public long ItemCount { get; set; }

    public DateTime CreatedDate { get; set; }

    public DateTime UpdateDate { get; set; }

    public DateTime? DeletedDate { get; set; }
}
