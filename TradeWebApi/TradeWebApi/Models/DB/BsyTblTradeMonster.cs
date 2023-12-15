using System;
using System.Collections.Generic;

namespace TradeWebApi.Models.DB;

public partial class BsyTblTradeMonster
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

    public int RareStat { get; set; }

    public int PropertyState { get; set; }

    public int TypeStat { get; set; }

    public int RebirthStat { get; set; }

    public DateTime CreatedDate { get; set; }

    public DateTime UpdateDate { get; set; }

    public DateTime? DeletedDate { get; set; }

    public DateTime AvailableDate { get; set; }
}
