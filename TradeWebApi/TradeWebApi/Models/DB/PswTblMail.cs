using System;
using System.Collections.Generic;

namespace TradeWebApi.Models.DB;

public partial class PswTblMail
{
    public long Id { get; set; }

    public long UserId { get; set; }

    public long FromUserId { get; set; }

    public long ItemId { get; set; }

    public long ItemCount { get; set; }

    public DateTime CreatedDate { get; set; }

    public DateTime UpdatedDate { get; set; }

    public DateTime? DeletedDate { get; set; }
}
