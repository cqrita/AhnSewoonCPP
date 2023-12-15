namespace TradeWebApi.Models.DTO
{
    public class RequestSellMonsterDTO
    {
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
    }
    public class ResponseSellMonsterDTO
    {

    }

}
