using System;
using System.Collections.Generic;
using Microsoft.EntityFrameworkCore;
using WebApi.Models.DB;

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

    public virtual DbSet<AswTblScore> AswTblScores { get; set; }

    public virtual DbSet<AswTblUser> AswTblUsers { get; set; }

    public virtual DbSet<BsyTblScore> BsyTblScores { get; set; }

    public virtual DbSet<BsyTblUser> BsyTblUsers { get; set; }

    public virtual DbSet<MjhTblUser> MjhTblUsers { get; set; }

    protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        => optionsBuilder.UseMySql("server=121.190.138.117;port=3306;database=SBS_STUDY;user=PAStudy;password=PAtmxjel22..", Microsoft.EntityFrameworkCore.ServerVersion.Parse("10.3.32-mariadb"));

    protected override void OnModelCreating(ModelBuilder modelBuilder)
    {
        modelBuilder
            .UseCollation("utf8_general_ci")
            .HasCharSet("utf8");

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

        OnModelCreatingPartial(modelBuilder);
    }

    partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
}
