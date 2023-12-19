namespace TradeWebApi.Utility
{
    public class RootFilter
    {
        public List<Filter> Filters {  get; set; }
        public string Logic { get; set; }
    }
    public class Filter
    {
        public string Field { get; set; }
        public string Operator { get; set; }
        public string Value { get; set; }
        public string Logic { get; set; }
        public List<Filter> Filters { get; set; }
    }
}
