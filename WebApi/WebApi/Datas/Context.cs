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
#warning To protect potentially sensitive information in your connection string, you should move it out of source code. You can avoid scaffolding the connection string by using the Name= syntax to read it from configuration - see https://go.microsoft.com/fwlink/?linkid=2131148. For more guidance on storing connection strings, see http://go.microsoft.com/fwlink/?LinkId=723263.
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

            entity.Property(e => e.Id)
                .HasColumnType("int(11)")
                .HasColumnName("ID");
            entity.Property(e => e.UserId).HasColumnType("int(11)");
            entity.Property(e => e.Value)
                .HasDefaultValueSql("'1'")
                .HasColumnType("int(11)");
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

            entity.Property(e => e.Id).HasColumnType("int(11)");
            entity.Property(e => e.UserId).HasColumnType("int(11)");
            entity.Property(e => e.Value)
                .HasDefaultValueSql("'1'")
                .HasColumnType("int(11)");
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
