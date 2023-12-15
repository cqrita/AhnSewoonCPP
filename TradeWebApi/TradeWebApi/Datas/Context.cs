using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using TradeWebApi.Models.DB;

namespace WebApi.Data;

public partial class Context : DbContext
{
    public Context()
    {
    }

    public Context(DbContextOptions<Context> options)
        : base(options)
    {
    }

    public virtual DbSet<AswTblMail> AswTblMails { get; set; }

    public virtual DbSet<AswTblScore> AswTblScores { get; set; }

    public virtual DbSet<AswTblTradeMonster> AswTblTradeMonsters { get; set; }

    public virtual DbSet<AswTblUser> AswTblUsers { get; set; }

    public virtual DbSet<BsyTblMail> BsyTblMails { get; set; }

    public virtual DbSet<BsyTblScore> BsyTblScores { get; set; }

    public virtual DbSet<BsyTblTradeMonster> BsyTblTradeMonsters { get; set; }

    public virtual DbSet<BsyTblUser> BsyTblUsers { get; set; }

    public virtual DbSet<MjhTblUser> MjhTblUsers { get; set; }

    public virtual DbSet<PswTblMail> PswTblMails { get; set; }

    public virtual DbSet<PswTblTradeMonster> PswTblTradeMonsters { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
        => optionsBuilder.UseMySql("server=121.190.138.117;port=3306;database=SBS_STUDY;user=PAStudy;password=PAtmxjel22..", Microsoft.EntityFrameworkCore.ServerVersion.Parse("10.3.32-mariadb"));

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder
            .UseCollation("utf8_general_ci")
            .HasCharSet("utf8");

        modelBuilder.Entity<AswTblMail>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("ASW_TblMail");

            entity.Property(e => e.Id)
                .HasColumnType("bigint(20)")
                .HasColumnName("id");
            entity.Property(e => e.CreateDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("createDate");
            entity.Property(e => e.DeleteDate)
                .HasColumnType("datetime")
                .HasColumnName("deleteDate");
            entity.Property(e => e.FromUserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("fromUserId");
            entity.Property(e => e.ItemCount)
                .HasColumnType("bigint(20)")
                .HasColumnName("itemCount");
            entity.Property(e => e.ItemId)
                .HasColumnType("bigint(20)")
                .HasColumnName("itemId");
            entity.Property(e => e.UpdateDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("updateDate");
            entity.Property(e => e.UserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("userId");
        });

        modelBuilder.Entity<AswTblScore>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("ASW_TblScore");

            entity.HasIndex(e => e.UserId, "FK_UserId");

            entity.Property(e => e.Id)
                .HasColumnType("int(11)")
                .HasColumnName("ID");
            entity.Property(e => e.UserId).HasColumnType("int(11)");
            entity.Property(e => e.Value)
                .HasDefaultValueSql("'1'")
                .HasColumnType("int(11)");

            entity.HasOne(d => d.User).WithMany(p => p.AswTblScores)
                .HasForeignKey(d => d.UserId)
                .HasConstraintName("FK_UserId");
        });

        modelBuilder.Entity<AswTblTradeMonster>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("ASW_TblTradeMonster");

            entity.Property(e => e.Id)
                .HasColumnType("bigint(20)")
                .HasColumnName("id");
            entity.Property(e => e.AttackStat)
                .HasColumnType("int(11)")
                .HasColumnName("attackStat");
            entity.Property(e => e.AvailableDate)
                .HasDefaultValueSql("(current_timestamp() + interval 3 day)")
                .HasColumnType("datetime")
                .HasColumnName("availableDate");
            entity.Property(e => e.CreateDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("createDate");
            entity.Property(e => e.DefenceStat)
                .HasColumnType("int(11)")
                .HasColumnName("defenceStat");
            entity.Property(e => e.DeleteDate)
                .HasColumnType("datetime")
                .HasColumnName("deleteDate");
            entity.Property(e => e.HealthStat)
                .HasColumnType("int(11)")
                .HasColumnName("healthStat");
            entity.Property(e => e.LevelStat)
                .HasColumnType("int(11)")
                .HasColumnName("levelStat");
            entity.Property(e => e.MonsterId)
                .HasColumnType("int(11)")
                .HasColumnName("monsterId");
            entity.Property(e => e.OwnerUserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("ownerUserId");
            entity.Property(e => e.Price)
                .HasColumnType("bigint(20)")
                .HasColumnName("price");
            entity.Property(e => e.PropertyStat)
                .HasMaxLength(100)
                .HasColumnName("propertyStat");
            entity.Property(e => e.RareStat)
                .HasMaxLength(100)
                .HasColumnName("rareStat");
            entity.Property(e => e.RebirthStat)
                .HasColumnType("int(11)")
                .HasColumnName("rebirthStat");
            entity.Property(e => e.SpeedStat)
                .HasColumnType("int(11)")
                .HasColumnName("speedStat");
            entity.Property(e => e.TypeStat)
                .HasMaxLength(100)
                .HasColumnName("typeStat");
            entity.Property(e => e.UpdateDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("updateDate");
        });

        modelBuilder.Entity<AswTblUser>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("ASW_TblUser");

            entity.Property(e => e.Id)
                .HasColumnType("int(11)")
                .HasColumnName("ID");
            entity.Property(e => e.Level)
                .HasDefaultValueSql("'1'")
                .HasColumnType("int(11)")
                .HasColumnName("LEVEL");
            entity.Property(e => e.Name).HasMaxLength(30);
        });

        modelBuilder.Entity<BsyTblMail>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("BSY_TblMail");

            entity.Property(e => e.Id).HasColumnType("bigint(20)");
            entity.Property(e => e.CreatedDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("createdDate");
            entity.Property(e => e.DeletedDate)
                .HasColumnType("datetime")
                .HasColumnName("deletedDate");
            entity.Property(e => e.FromUserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("fromUserId");
            entity.Property(e => e.ItemCount)
                .HasColumnType("bigint(20)")
                .HasColumnName("itemCount");
            entity.Property(e => e.ItemId)
                .HasColumnType("bigint(20)")
                .HasColumnName("itemId");
            entity.Property(e => e.UpdateDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("updateDate");
            entity.Property(e => e.UserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("userId");
        });

        modelBuilder.Entity<BsyTblScore>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("BSY_TblScore");

            entity.HasIndex(e => e.UserId, "UserId");

            entity.Property(e => e.Id).HasColumnType("int(11)");
            entity.Property(e => e.UserId).HasColumnType("int(11)");
            entity.Property(e => e.Value)
                .HasDefaultValueSql("'1'")
                .HasColumnType("int(11)");

            entity.HasOne(d => d.User).WithMany(p => p.BsyTblScores)
                .HasForeignKey(d => d.UserId)
                .OnDelete(DeleteBehavior.ClientSetNull)
                .HasConstraintName("BSY_TblScore_ibfk_1");
        });

        modelBuilder.Entity<BsyTblTradeMonster>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("BSY_TblTradeMonster");

            entity.Property(e => e.Id).HasColumnType("bigint(20)");
            entity.Property(e => e.AttackStat)
                .HasColumnType("int(11)")
                .HasColumnName("attackStat");
            entity.Property(e => e.AvailableDate)
                .HasDefaultValueSql("(current_timestamp() + interval 3 day)")
                .HasColumnType("datetime")
                .HasColumnName("availableDate");
            entity.Property(e => e.CreatedDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("createdDate");
            entity.Property(e => e.DefenceStat)
                .HasColumnType("int(11)")
                .HasColumnName("defenceStat");
            entity.Property(e => e.DeletedDate)
                .HasColumnType("datetime")
                .HasColumnName("deletedDate");
            entity.Property(e => e.HealthStat)
                .HasColumnType("int(11)")
                .HasColumnName("healthStat");
            entity.Property(e => e.LevelStat)
                .HasColumnType("int(11)")
                .HasColumnName("levelStat");
            entity.Property(e => e.MonsterId)
                .HasColumnType("int(11)")
                .HasColumnName("monsterId");
            entity.Property(e => e.OwnerUserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("ownerUserId");
            entity.Property(e => e.Price)
                .HasColumnType("bigint(20)")
                .HasColumnName("price");
            entity.Property(e => e.PropertyState)
                .HasColumnType("int(11)")
                .HasColumnName("propertyState");
            entity.Property(e => e.RareStat)
                .HasColumnType("int(11)")
                .HasColumnName("rareStat");
            entity.Property(e => e.RebirthStat)
                .HasColumnType("int(11)")
                .HasColumnName("rebirthStat");
            entity.Property(e => e.SpeedStat)
                .HasColumnType("int(11)")
                .HasColumnName("speedStat");
            entity.Property(e => e.TypeStat)
                .HasColumnType("int(11)")
                .HasColumnName("typeStat");
            entity.Property(e => e.UpdateDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("updateDate");
        });

        modelBuilder.Entity<BsyTblUser>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("BSY_TblUser");

            entity.Property(e => e.Id).HasColumnType("int(11)");
            entity.Property(e => e.Level)
                .HasDefaultValueSql("'1'")
                .HasColumnType("int(11)");
            entity.Property(e => e.Name).HasMaxLength(30);
        });

        modelBuilder.Entity<MjhTblUser>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("MJH_TblUser");

            entity.Property(e => e.Id).HasColumnType("int(11)");
            entity.Property(e => e.Level)
                .HasDefaultValueSql("'1'")
                .HasColumnType("int(11)");
            entity.Property(e => e.Name).HasMaxLength(30);
        });

        modelBuilder.Entity<PswTblMail>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("PSW_TblMail");

            entity.Property(e => e.Id).HasColumnType("bigint(20)");
            entity.Property(e => e.CreatedDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("createdDate");
            entity.Property(e => e.DeletedDate)
                .HasColumnType("datetime")
                .HasColumnName("deletedDate");
            entity.Property(e => e.FromUserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("fromUserId");
            entity.Property(e => e.ItemCount)
                .HasColumnType("bigint(20)")
                .HasColumnName("itemCount");
            entity.Property(e => e.ItemId)
                .HasColumnType("bigint(20)")
                .HasColumnName("itemId");
            entity.Property(e => e.UpdatedDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("updatedDate");
            entity.Property(e => e.UserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("userId");
        });

        modelBuilder.Entity<PswTblTradeMonster>(entity =>
        {
            entity.HasKey(e => e.Id).HasName("PRIMARY");

            entity.ToTable("PSW_TblTradeMonster");

            entity.Property(e => e.Id).HasColumnType("bigint(20)");
            entity.Property(e => e.AttackStat)
                .HasColumnType("int(11)")
                .HasColumnName("attackStat");
            entity.Property(e => e.AvailableDate)
                .HasDefaultValueSql("(current_timestamp() + interval 3 day)")
                .HasColumnType("datetime")
                .HasColumnName("availableDate");
            entity.Property(e => e.CreatedDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("createdDate");
            entity.Property(e => e.DefenseStat)
                .HasColumnType("int(11)")
                .HasColumnName("defenseStat");
            entity.Property(e => e.DeletedDate)
                .HasColumnType("datetime")
                .HasColumnName("deletedDate");
            entity.Property(e => e.HealthStat)
                .HasColumnType("int(11)")
                .HasColumnName("healthStat");
            entity.Property(e => e.LevelStat)
                .HasColumnType("int(11)")
                .HasColumnName("levelStat");
            entity.Property(e => e.MonsterId)
                .HasColumnType("int(11)")
                .HasColumnName("monsterId");
            entity.Property(e => e.OwnerUserId)
                .HasColumnType("bigint(20)")
                .HasColumnName("ownerUserId");
            entity.Property(e => e.Price)
                .HasColumnType("int(11)")
                .HasColumnName("price");
            entity.Property(e => e.PropertyStat)
                .HasColumnType("int(11)")
                .HasColumnName("propertyStat");
            entity.Property(e => e.RareStat)
                .HasColumnType("int(11)")
                .HasColumnName("rareStat");
            entity.Property(e => e.RebirthStat)
                .HasColumnType("int(11)")
                .HasColumnName("rebirthStat");
            entity.Property(e => e.SpeedStat)
                .HasColumnType("int(11)")
                .HasColumnName("speedStat");
            entity.Property(e => e.TypeStat)
                .HasColumnType("int(11)")
                .HasColumnName("typeStat");
            entity.Property(e => e.UpdatedDate)
                .HasDefaultValueSql("current_timestamp()")
                .HasColumnType("datetime")
                .HasColumnName("updatedDate");
        });

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
