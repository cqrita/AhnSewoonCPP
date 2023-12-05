using Microsoft.EntityFrameworkCore;
using WebApi.Data;

namespace WebApi
{
    public class Program
    {
        public static void Main(string[] args)
        {
            //WebApplication ��������� ���� �������� �Լ�  (CREATE)
            var builder = WebApplication.CreateBuilder(args);

            //����ֵ鿡 �������� ���� �߰�
            //Controller, 
            //EndPoint,
            //Swagger
            // -> API ����� Ȯ���ϱ����� ������� ���̺귯��
            builder.Services.AddControllers();
            builder.Services.AddEndpointsApiExplorer();
            builder.Services.AddSwaggerGen();


            var connectionString = builder.Configuration.GetConnectionString("SBS_Study");
            builder.Services.AddDbContext<Context>(options => options.UseMySql(connectionString, ServerVersion.AutoDetect(connectionString)));


            //�����ϱ����� ���۾�
            var app = builder.Build();

            //���� ���߸���
            if (app.Environment.IsDevelopment())
            {
                //Swagger�� ����ϰڴ�.
                app.UseSwagger();
                app.UseSwaggerUI();
            }

            //https�ɼǿ����� �߰�1
            app.UseHttpsRedirection();
            //https �ɼǿ����� �߰�2
            app.UseAuthorization();

            //���Ʈ ����
            app.MapControllers();


            //����
            app.Run();
        }
    }
}
