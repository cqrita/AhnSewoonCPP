using System;
using System.Collections.Generic;

namespace TradeWebApi.Models.DB;

public partial class AswTblTradeMonster
{
    public long Id { get; set; }

    public long OwnerUserId { get; set; }

    public int MonsterId { get; set; }

    public long Price { get; set; }

    public int LevelStat { get; set; }

    public int AttackStat { get; set; }

    public int DefenceStat { get; set; }

    public int SpeedStat { get; set; }

    public int HealthStat { get; set; }

    public string RareStat { get; set; } = null!;

    public string PropertyStat { get; set; } = null!;

    public string TypeStat { get; set; } = null!;

    public int? RebirthStat { get; set; }

    public DateTime CreateDate { get; set; }

    public DateTime UpdateDate { get; set; }

    public DateTime? DeleteDate { get; set; }

    public DateTime AvailableDate { get; set; }
}
