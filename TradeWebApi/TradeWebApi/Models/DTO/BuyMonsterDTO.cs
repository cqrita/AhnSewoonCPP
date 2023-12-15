namespace TradeWebApi.Models.DTO
{
    public class RequestBuyMonsterDTO
    {
        public long Id { get; set; }
        public long BuyUserId { get; set; }
    }
    public class ResponseBuyMonsterDTO
    {
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

}
