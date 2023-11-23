using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _20231123_01
{
    public enum RockScissorsPaper
    {
        Rock,
        Scissors,
        Paper,
        End
    }
    public class Hand
    {
        public RockScissorsPaper Value
        {
            get; set;
        }= RockScissorsPaper.End;

        public override string ToString()
        {
            switch (Value)
            {
                case RockScissorsPaper.Rock:
                    return "Rock";
                case RockScissorsPaper.Scissors:
                    return "Scissors";
                case RockScissorsPaper.Paper:
                    return "Paper";
                default:
                    break;
            }
            return "";
        }
        public override bool Equals(object? obj)
        {
            Hand? hand = obj as Hand;
            return hand?.Value == this.Value;
        }
        public override int GetHashCode()
        {
            return base.GetHashCode();
        }
    }
}
